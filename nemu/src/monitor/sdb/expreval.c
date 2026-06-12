#include "expreval.h"
#include "sdb.h"
#include <isa.h>
#include <regex.h>
#include <stdlib.h>
#include <memory/vaddr.h>

enum {
  TK_NOTYPE = 256, 
  TK_EQ, 
  TK_HEX, 
  TK_DEC, 
  TK_REG,
  TK_NEQ,
  TK_DEREF,
  TK_AND,
};

int expreval(int p, int q, Token *tokens, bool *success) {
    //printf("TK_DEC = %d, TK_HEX = %d, TK_REG = %d\n", TK_DEC, TK_HEX, TK_REG);
    if(p > q) {
        *success = false;
        printf("Bad expression\n");
        return 0;
    }
    else if (p == q){
        //No need to check NOTYPE here, because we do not push the NOTYPE token into tokens array 
        //in make_token function      
        if (tokens[p].type == TK_HEX) {
            *success = true;
            return strtoul(tokens[p].str, NULL, 16);
        }
        else if (tokens[p].type == TK_DEC) {
            *success = true;
            return strtoul(tokens[p].str, NULL, 10);
        }
        //考虑解引用
        else if (tokens[p].type == TK_REG) {
            *success = true;
            //remove the '$' in the register name
            char reg_name[32];
            memset(reg_name, 0, sizeof(reg_name));
            strncpy(reg_name, tokens[p].str + 1, sizeof(reg_name) - 1);
            int reg_index = isa_reg_str2val(reg_name, success);
            if(reg_index == -1) {
                *success = false;
                printf("Unknown register: %s\n", reg_name);
                assert(0);
                return 0;
            }
            return reg_index;
        }
        else {
            *success = false;
            printf("p == q but encountered a non-numeric token: %d\n", tokens[p].type);
            assert(0);
            return 0;
        }
    }
    //如果p和q是一对括号，那么我们就只需要计算括号内的表达式即可
    else if (check_parentheses(p, q, tokens) == true) {
        return expreval(p + 1, q - 1, tokens, success);
    }
    //根据主运算符，递归运算
    else {
        int val1 = 0, val2 = 0;
        int op = -1;
        op = find_main_operator(p, q, tokens);
        if(op == -1) {
            *success = false;
            printf("No operator found in expression\n");
            assert(0);
            return 0;
        }

        //在找到解引用单目运算符之后，只用计算右侧的值
        if(tokens[op].type == TK_DEREF) {
            val2 = expreval(op + 1, q, tokens, success);
            if(*success == false) {
                return 0;
            }
        }
        else {
            val1 = expreval(p, op - 1, tokens, success);
            // printf("Strings of tokens from %d to %d: ", p, op - 1);
            // for(int i = p; i < op; i++) {
            //     printf("%s ", tokens[i].str);
            // }
            // printf("\n[%d, %d]val1 = %u\n", p, op - 1, val1);
            if(*success == false) {
                return 0;
            }
            val2 = expreval(op + 1, q, tokens, success);
            // printf("Strings of tokens from %d to %d: ", op + 1, q);
            // for(int i = op + 1; i <= q; i++) {
            //     printf("%s ", tokens[i].str);
            // }
            // printf("\n[%d, %d]val2 = %u\n", op + 1, q, val2);
        }

        switch (tokens[op].type) {
            case TK_EQ: return val1 == val2;
            case TK_NEQ: return val1 != val2;
            case TK_AND: return val1 && val2;
            case '+': return val1 + val2;
            case '-': return val1 - val2;
            case '*': return val1 * val2;
            case '/': 
                if(val2 == 0) {
                    *success = false;
                    printf("Division by zero\n");
                    assert(0);
                    return 0;
                }
                return val1 / val2;
            case TK_DEREF: return vaddr_read(val2, 4);
            default: 
                *success = false;
                printf("Unknown operator: %d\n", tokens[op].type);
                assert(0);
                return 0;
        }
    }
}

bool check_parentheses(int p, int q, Token *tokens) {
    if(tokens[p].type != '(' || tokens[q].type != ')') {
        return false;
    }
    int depth = 0;
    for(int i = p + 1; i < q; i++) {
        //如果在p和q之间遇到一个左括号，就把depth加1，如果遇到一个右括号，就把depth减
        if(tokens[i].type == '(') {
            depth++;
        }
        else if(tokens[i].type == ')') {
            if(depth == 0) {
                //为了避免()()中最左和最后匹配的情况，如果遇到匹配的，就直接return false
                return false;
            }
            depth--;
        }
    }
    //即使depth为0，也不代表这对括号是匹配的，
    //因为中间可能存在其他括号，
    //例如(A+B)*(C+D)，A+B和C+D外面的括号并不是一对
    return true;
}

int find_main_operator(int p, int q, Token *tokens) {
    int main_op = -1;
    int min_priority = 100;
    int depth = 0;

    for(int i = p; i <= q; i++) {
        if(tokens[i].type == TK_HEX || tokens[i].type == TK_DEC) {
            continue; // skip numbers
        }
        else if(tokens[i].type == '(') {
            depth++;
        }
        else if(tokens[i].type == ')') {
            depth--;
        }
        //只用考虑最外层，因为我们剥开了括号
        else if(depth == 0) { 
            int priority;
            switch (tokens[i].type) {
                //按照优先级排列
                case TK_AND: priority = 0; break; 
                case TK_EQ:
                case TK_NEQ: priority = 1; break;
                case '+':
                case '-': priority = 2; break;
                case '*':
                case '/': priority = 3; break;
                case TK_DEREF: priority = 4; break; //解引用优先级最高
                default: priority = 100; // a large number for unknown operators
            }
            //考虑解引用运算符右结合，如果优先级相同，选右边的，其他的选左边的
            if(priority < min_priority || (priority == min_priority && tokens[i].type != TK_DEREF)) { 
                min_priority = priority;
                main_op = i;
            }
        }
    }
    //printf("____p = %d, q = %d, main operator: %c at position %d___\n", p, q, tokens[main_op].type, main_op);
    return main_op;
}

bool valid_parentheses(Token *tokens, int nr_token) {
    int depth = 0;
    for(int i = 0; i < nr_token; i++) {
        if(tokens[i].type == '(') {
            depth++;
        }
        else if(tokens[i].type == ')') {
            depth--;
            if(depth < 0) {
                printf("Invalid parentheses at token %d\n", i);
                return false;
            }
        }
    }
    return depth == 0;
}




