// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vcustom_cpu__Syms.h"


VL_ATTR_COLD void Vcustom_cpu___024root__trace_init_sub__TOP__0(Vcustom_cpu___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_init_sub__TOP__0\n"); );
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+251,0,"PC",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"Instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+253,0,"Address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+254,0,"MemWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"Write_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+256,0,"Write_strb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+257,0,"MemRead",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"Mem_Req_Ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+259,0,"Read_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+260,0,"Read_data_Valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"Read_data_Ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"intr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"cpu_perf_cnt_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+264,0,"cpu_perf_cnt_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+265,0,"cpu_perf_cnt_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"cpu_perf_cnt_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+267,0,"cpu_perf_cnt_4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"cpu_perf_cnt_5",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"cpu_perf_cnt_6",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"cpu_perf_cnt_7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+271,0,"cpu_perf_cnt_8",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+272,0,"cpu_perf_cnt_9",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"cpu_perf_cnt_10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"cpu_perf_cnt_11",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"cpu_perf_cnt_12",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"cpu_perf_cnt_13",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+277,0,"cpu_perf_cnt_14",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+278,0,"cpu_perf_cnt_15",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+279,0,"inst_retire",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 69,0);
    tracep->declBus(c+282,0,"a0_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("custom_cpu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+251,0,"PC",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"Instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+253,0,"Address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+254,0,"MemWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"Write_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+256,0,"Write_strb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+257,0,"MemRead",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"Mem_Req_Ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+259,0,"Read_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+260,0,"Read_data_Valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"Read_data_Ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"intr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"cpu_perf_cnt_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+264,0,"cpu_perf_cnt_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+265,0,"cpu_perf_cnt_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"cpu_perf_cnt_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+267,0,"cpu_perf_cnt_4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"cpu_perf_cnt_5",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"cpu_perf_cnt_6",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"cpu_perf_cnt_7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+271,0,"cpu_perf_cnt_8",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+272,0,"cpu_perf_cnt_9",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"cpu_perf_cnt_10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"cpu_perf_cnt_11",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"cpu_perf_cnt_12",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"cpu_perf_cnt_13",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+277,0,"cpu_perf_cnt_14",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+278,0,"cpu_perf_cnt_15",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+279,0,"inst_retire",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 69,0);
    tracep->declBus(c+282,0,"a0_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+0,0,"prediction_incorrect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+1,0,"predictor_to_IF_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+3,0,"PC_correct",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"IF_to_ID_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"ID_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"ID_to_EX_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"EX_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"EX_to_MEM_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"MEM_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"MEM_to_WB_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+285,0,"WB_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+286,0,"inst_Req_Valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+11,0,"IF_to_ID_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+13,0,"ID_to_EX_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 271,0);
    tracep->declArray(c+22,0,"EX_to_MEM_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 214,0);
    tracep->declQuad(c+29,0,"EX_to_ID_bypath_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declArray(c+31,0,"MEM_to_WB_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 70,0);
    tracep->declQuad(c+34,0,"MEM_to_ID_bypath_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+36,0,"WB_to_ID_bypath_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declBit(c+38,0,"Inst_Req_Valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"Inst_Req_Ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"Inst_Valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"Inst_Ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("EX_EX", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+0,0,"prediction_incorrect",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+13,0,"ID_to_EX_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 271,0);
    tracep->declArray(c+22,0,"EX_to_MEM_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 214,0);
    tracep->declQuad(c+29,0,"EX_to_ID_bypath_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBit(c+7,0,"EX_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"EX_to_MEM_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"ID_to_EX_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"MEM_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"PC_correct",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"U_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"ALUop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+45,0,"ALUop_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"ALUop_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"Shiftop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+48,0,"Shiftop_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"Shiftop_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+50,0,"PC_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"func",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+52,0,"prediction_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"prediction_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+54,0,"AluShi_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"mul",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"Jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"Branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"RF_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"RF_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+62,0,"rdata2_true",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+63,0,"ebreak_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"inst_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"inst_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+66,0,"ID_to_EX_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 271,0);
    tracep->declBus(c+75,0,"ALU_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"Shifter_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+77,0,"Zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"Branch_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"Result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+80,0,"Branch_check",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+81,0,"mul_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+83,0,"block_cancel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"exec_redirect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+85,0,"exec_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"EX_work",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+285,0,"EX_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"Address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+88,0,"Write_strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+89,0,"Write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"reg_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+91,0,"reg_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+58,0,"EX_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"EX_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"EX_bypath_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+94,0,"csr_write_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+45,0,"csr_write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+96,0,"csr_write_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"csr_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"mtvec_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"mepc_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+100,0,"ecall_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("CSR_INST", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"csr_write_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"csr_write_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"csr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+45,0,"csr_write_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+100,0,"ecall_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"exec_PC",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"mtvec_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"mepc_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"csr_read_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"mcycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"mcycleh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"mvendorid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"marchid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+105,0,"mcause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"mstatus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("alu_ex", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+45,0,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"ALUop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+107,0,"Overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+287,0,"CarryOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"Zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"temp_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+109,0,"unsigned_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+111,0,"unsigned_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+113,0,"unsigned_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->popPrefix();
    tracep->pushPrefix("shifter_ex", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+48,0,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+47,0,"Shiftop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+76,0,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"A_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"result_sll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"result_srl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"result_sra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("ID_EX", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+11,0,"IF_to_ID_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+29,0,"EX_to_ID_bypath_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+34,0,"MEM_to_ID_bypath_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+36,0,"WB_to_ID_bypath_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declArray(c+13,0,"ID_to_EX_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 271,0);
    tracep->declQuad(c+1,0,"predictor_to_IF_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+0,0,"prediction_incorrect",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"ID_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"ID_to_EX_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"IF_to_ID_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"EX_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"a0_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+118,0,"IF_to_ID_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+120,0,"PC_ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"Instruction_current",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+123,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+124,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+125,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+125,0,"shamt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+126,0,"func",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+127,0,"func_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+128,0,"func7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+129,0,"U_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"I_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"S_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"B_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"J_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"RF_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+288,0,"RF_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"rdata2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"rdata1_true",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"rdata2_true",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+138,0,"Branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+139,0,"ALUop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+140,0,"Shiftop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+141,0,"Jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"AluShi_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+132,0,"Branch_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"ALUop_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"ALUop_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"Shiftop_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"Shiftop_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+124,0,"raddr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+125,0,"raddr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+147,0,"mul",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"ebreak_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"csr_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+151,0,"csr_write_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"csr_write_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"inst_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"inst_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"ID_work",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"ID_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"block",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"EX_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"EX_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"EX_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+93,0,"EX_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+158,0,"EX_related",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+159,0,"MEM_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,0,"MEM_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+161,0,"MEM_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+162,0,"MEM_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+163,0,"MEM_related",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"WB_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+165,0,"WB_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"WB_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+167,0,"RF_wen_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+168,0,"Jump_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"PC_Branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"PC_Jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"prediction_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+172,0,"prediction_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"predictor_update",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"prediction_yes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prediction_ex", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"is_Branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"predictor_update",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+0,0,"prediction_incorrect",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,0,"prediction_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+175,0,"predictor_current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+283,0,"predictor_next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+289,0,"INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+290,0,"S_TAKE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+291,0,"W_TAKE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+292,0,"W_NTAKE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+293,0,"S_NTAKE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_file_ex", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+166,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+124,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+125,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+164,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+165,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+282,0,"a0_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regfile", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+176+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+208,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("IF_EX", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+251,0,"PC",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"Instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+40,0,"Inst_Valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"Inst_Ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"Inst_Req_Valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"Inst_Req_Ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+11,0,"IF_to_ID_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+0,0,"prediction_incorrect",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+1,0,"predictor_to_IF_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+3,0,"PC_correct",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"IF_to_ID_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"ID_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"MemRead",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+289,0,"INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+290,0,"IF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+291,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+292,0,"INS_GO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+293,0,"INS_DONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+209,0,"IF_current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+210,0,"IF_next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+211,0,"Instruction_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+174,0,"prediction_yes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+171,0,"prediction_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"PC_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+213,0,"IF_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("MEM_EX", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+253,0,"Address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+254,0,"MemWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"Write_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+256,0,"Write_strb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+257,0,"MemRead",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"Mem_Req_Ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+259,0,"Read_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+260,0,"Read_data_Valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"Read_data_Ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+22,0,"EX_to_MEM_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 214,0);
    tracep->declArray(c+31,0,"MEM_to_WB_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 70,0);
    tracep->declQuad(c+34,0,"MEM_to_ID_bypath_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBit(c+9,0,"MEM_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"MEM_to_WB_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"EX_to_MEM_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+285,0,"WB_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+214,0,"EX_to_MEM_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 214,0);
    tracep->declBus(c+221,0,"csr_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+222,0,"Result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+223,0,"U_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+224,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+225,0,"PC_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+226,0,"eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+227,0,"func",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+159,0,"load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+229,0,"RF_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+161,0,"RF_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+230,0,"ebreak_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+289,0,"INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+290,0,"SL_BEFORE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+291,0,"SL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+292,0,"RDW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+293,0,"SL_DONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+231,0,"MEM_current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+284,0,"MEM_next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+232,0,"MEM_work",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+233,0,"MEM_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+234,0,"Read_data_current",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+235,0,"read_byte_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+236,0,"read_byte_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+237,0,"read_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+238,0,"read_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+162,0,"RF_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("WB_EX", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+31,0,"MEM_to_WB_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 70,0);
    tracep->declQuad(c+36,0,"WB_to_ID_bypath_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declBit(c+10,0,"MEM_to_WB_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+285,0,"WB_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+279,0,"inst_retired",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 69,0);
    tracep->declArray(c+239,0,"MEM_to_WB_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 70,0);
    tracep->declBit(c+164,0,"RF_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"PC_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"RF_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"RF_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+243,0,"ebreak_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+244,0,"WB_work",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+285,0,"WB_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+244,0,"inst_retire_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+245,0,"inst_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ifu_mem_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+249,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+251,0,"PC",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+38,0,"Inst_Req_Valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"Inst_Req_Ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+252,0,"Instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+40,0,"Inst_Valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"Inst_Ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+246,0,"ifu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+40,0,"ifu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+247,0,"ar_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+248,0,"r_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vcustom_cpu___024root__trace_init_top(Vcustom_cpu___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_init_top\n"); );
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vcustom_cpu___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vcustom_cpu___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vcustom_cpu___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcustom_cpu___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcustom_cpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vcustom_cpu___024root__trace_register(Vcustom_cpu___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_register\n"); );
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vcustom_cpu___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vcustom_cpu___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vcustom_cpu___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vcustom_cpu___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vcustom_cpu___024root__trace_const_0_sub_0(Vcustom_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcustom_cpu___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_const_0\n"); );
    // Body
    Vcustom_cpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcustom_cpu___024root*>(voidSelf);
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vcustom_cpu___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcustom_cpu___024root__trace_const_0_sub_0(Vcustom_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_const_0_sub_0\n"); );
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+285,(1U));
    bufp->fullBit(oldp+286,(vlSelfRef.custom_cpu__DOT__inst_Req_Valid));
    bufp->fullBit(oldp+287,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__CarryOut));
    bufp->fullIData(oldp+288,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__RF_wdata),32);
    bufp->fullCData(oldp+289,(1U),5);
    bufp->fullCData(oldp+290,(2U),5);
    bufp->fullCData(oldp+291,(4U),5);
    bufp->fullCData(oldp+292,(8U),5);
    bufp->fullCData(oldp+293,(0x10U),5);
}

VL_ATTR_COLD void Vcustom_cpu___024root__trace_full_0_sub_0(Vcustom_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcustom_cpu___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_full_0\n"); );
    // Body
    Vcustom_cpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcustom_cpu___024root*>(voidSelf);
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vcustom_cpu___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcustom_cpu___024root__trace_full_0_sub_0(Vcustom_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_full_0_sub_0\n"); );
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__prediction_incorrect));
    bufp->fullQData(oldp+1,((((QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_yes)) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_addr)))),33);
    bufp->fullIData(oldp+3,(((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__exec_redirect)
                              ? ((0x00004000U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U])
                                  ? vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mepc
                                  : vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mtvec)
                              : ((1U & ((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Branch_real) 
                                        | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                           >> 0x0000000cU)))
                                  ? ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                                      << 8U) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                >> 0x00000018U))
                                  : ((IData)(4U) + 
                                     ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[6U] 
                                       << 7U) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                                                 >> 0x00000019U)))))),32);
    bufp->fullBit(oldp+4,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_valid));
    bufp->fullBit(oldp+5,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__ID_ready));
    bufp->fullBit(oldp+6,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_valid));
    bufp->fullBit(oldp+7,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_ready));
    bufp->fullBit(oldp+8,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_work));
    bufp->fullBit(oldp+9,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__MEM_ready));
    bufp->fullBit(oldp+10,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_to_WB_valid));
    bufp->fullQData(oldp+11,((((QData)((IData)(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__PC_reg)) 
                               << 0x00000020U) | (QData)((IData)(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__Instruction_reg)))),64);
    bufp->fullWData(oldp+13,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data),272);
    bufp->fullWData(oldp+22,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_to_MEM_data),215);
    bufp->fullQData(oldp+29,((((QData)((IData)((1U 
                                                & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                   >> 7U)))) 
                               << 0x00000026U) | (((QData)((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_write)) 
                                                   << 0x00000025U) 
                                                  | (((QData)((IData)(
                                                                      (0x0000001fU 
                                                                       & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U]))) 
                                                      << 0x00000020U) 
                                                     | (QData)((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_bypath_data)))))),39);
    __Vtemp_2[0U] = (IData)((((QData)((IData)((0x0000001fU 
                                               & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U]))) 
                              << 0x00000021U) | (((QData)((IData)(
                                                                  (1U 
                                                                   & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U] 
                                                                      >> 5U)))) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_data)))));
    __Vtemp_2[1U] = ((0xffffffc0U & ((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                      << 0x0000001aU) 
                                     | (0x03ffffc0U 
                                        & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[2U] 
                                           >> 6U)))) 
                     | (IData)(((((QData)((IData)((0x0000001fU 
                                                   & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U]))) 
                                  << 0x00000021U) | 
                                 (((QData)((IData)(
                                                   (1U 
                                                    & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U] 
                                                       >> 5U)))) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_data)))) 
                                >> 0x00000020U)));
    __Vtemp_2[2U] = ((0x00000040U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[5U] 
                                     >> 0x00000010U)) 
                     | (0x0000003fU & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                       >> 6U)));
    bufp->fullWData(oldp+31,(__Vtemp_2),71);
    bufp->fullQData(oldp+34,((((QData)((IData)((1U 
                                                & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[1U] 
                                                   >> 0x0000000bU)))) 
                               << 0x00000026U) | (((QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_write)) 
                                                   << 0x00000025U) 
                                                  | (((QData)((IData)(
                                                                      (0x0000001fU 
                                                                       & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U]))) 
                                                      << 0x00000020U) 
                                                     | (QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_data)))))),39);
    bufp->fullQData(oldp+36,((((QData)((IData)((1U 
                                                & vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U]))) 
                               << 0x00000025U) | (((QData)((IData)(
                                                                   (0x0000001fU 
                                                                    & (vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U] 
                                                                       >> 1U)))) 
                                                   << 0x00000020U) 
                                                  | (QData)((IData)(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[0U]))))),38);
    bufp->fullBit(oldp+38,(vlSelfRef.custom_cpu__DOT__ifu_mem_inst__DOT__Inst_Req_Valid));
    bufp->fullBit(oldp+39,((1U & (~ (IData)(vlSelfRef.custom_cpu__DOT__ifu_mem_inst__DOT__ifu_busy)))));
    bufp->fullBit(oldp+40,(vlSelfRef.custom_cpu__DOT__ifu_mem_inst__DOT__ifu_busy));
    bufp->fullBit(oldp+41,(vlSelfRef.custom_cpu__DOT__ifu_mem_inst__DOT__Inst_Ready));
    bufp->fullCData(oldp+42,((0x0000001fU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[6U] 
                                             >> 0x00000019U))),5);
    bufp->fullIData(oldp+43,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[7U] 
                               << 2U) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[6U] 
                                         >> 0x0000001eU))),32);
    bufp->fullCData(oldp+44,((7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                    >> 0x00000015U))),3);
    bufp->fullIData(oldp+45,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                               << 0x0000000bU) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                  >> 0x00000015U))),32);
    bufp->fullIData(oldp+46,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                               << 0x0000000bU) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                                  >> 0x00000015U))),32);
    bufp->fullCData(oldp+47,((3U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                    >> 0x00000013U))),2);
    bufp->fullIData(oldp+48,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                               << 0x0000000dU) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                  >> 0x00000013U))),32);
    bufp->fullCData(oldp+49,((0x0000001fU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                             >> 0x0000000eU))),5);
    bufp->fullIData(oldp+50,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[6U] 
                               << 7U) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                                         >> 0x00000019U))),32);
    bufp->fullCData(oldp+51,((7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                    >> 8U))),3);
    bufp->fullBit(oldp+52,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                                  >> 0x00000018U))));
    bufp->fullIData(oldp+53,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                               << 8U) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                         >> 0x00000018U))),32);
    bufp->fullBit(oldp+54,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                  >> 0x0000000dU))));
    bufp->fullBit(oldp+55,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[7U] 
                                  >> 0x0000001eU))));
    bufp->fullBit(oldp+56,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                  >> 0x0000000cU))));
    bufp->fullBit(oldp+57,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                  >> 0x0000000bU))));
    bufp->fullBit(oldp+58,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                  >> 7U))));
    bufp->fullBit(oldp+59,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                  >> 6U))));
    bufp->fullBit(oldp+60,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                  >> 5U))));
    bufp->fullCData(oldp+61,((0x0000001fU & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U])),5);
    bufp->fullIData(oldp+62,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U]),32);
    bufp->fullBit(oldp+63,((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[7U] 
                            >> 0x0000001fU)));
    bufp->fullBit(oldp+64,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U] 
                                  >> 0x0000000fU))));
    bufp->fullBit(oldp+65,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U] 
                                  >> 0x0000000eU))));
    bufp->fullWData(oldp+66,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg),272);
    bufp->fullIData(oldp+75,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result),32);
    bufp->fullIData(oldp+76,(((0U == (3U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                            >> 0x00000013U)))
                               ? (((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                    << 0x0000000dU) 
                                   | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                      >> 0x00000013U)) 
                                  << (0x0000001fU & 
                                      (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                       >> 0x0000000eU)))
                               : ((2U == (3U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                                >> 0x00000013U)))
                                   ? (((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                        << 0x0000000dU) 
                                       | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                          >> 0x00000013U)) 
                                      >> (0x0000001fU 
                                          & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                             >> 0x0000000eU)))
                                   : ((3U == (3U & 
                                              (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                               >> 0x00000013U)))
                                       ? VL_SHIFTRS_III(32,32,5, 
                                                        ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                                          << 0x0000000dU) 
                                                         | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                            >> 0x00000013U)), 
                                                        (0x0000001fU 
                                                         & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                            >> 0x0000000eU)))
                                       : ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                           << 0x0000000dU) 
                                          | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                             >> 0x00000013U)))))),32);
    bufp->fullBit(oldp+77,((0U == vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result)));
    bufp->fullBit(oldp+78,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Branch_real));
    bufp->fullIData(oldp+79,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result),32);
    bufp->fullBit(oldp+80,((1U & ((0U == (7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                >> 8U)))
                                   ? (0U == vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result)
                                   : ((1U == (7U & 
                                              (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                               >> 8U)))
                                       ? (~ (0U == vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result))
                                       : (((4U == (7U 
                                                   & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                      >> 8U))) 
                                           | (6U == 
                                              (7U & 
                                               (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                >> 8U))))
                                           ? (~ (0U 
                                                 == vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result))
                                           : (((5U 
                                                == 
                                                (7U 
                                                 & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                    >> 8U))) 
                                               | (7U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                      >> 8U))))
                                               ? (0U 
                                                  == vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result)
                                               : 0U)))))));
    bufp->fullQData(oldp+81,(((- (QData)((IData)((1U 
                                                  & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[7U] 
                                                     >> 0x0000001eU))))) 
                              & ((QData)((IData)(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                   << 0x0000000bU) 
                                                  | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                     >> 0x00000015U)))) 
                                 * (QData)((IData)(
                                                   ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                     << 0x0000000bU) 
                                                    | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                                       >> 0x00000015U))))))),64);
    bufp->fullBit(oldp+83,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__block_cancel));
    bufp->fullBit(oldp+84,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__exec_redirect));
    bufp->fullIData(oldp+85,(((0x00004000U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U])
                               ? vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mepc
                               : vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mtvec)),32);
    bufp->fullIData(oldp+86,((0xfffffffcU & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result)),32);
    bufp->fullCData(oldp+87,((3U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result)),2);
    bufp->fullCData(oldp+88,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Write_strb),4);
    bufp->fullIData(oldp+89,(((0U == (7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                            >> 8U)))
                               ? ((0U == (3U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result))
                                   ? (0x000000ffU & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U])
                                   : ((1U == (3U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result))
                                       ? (0x0000ff00U 
                                          & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U] 
                                             << 8U))
                                       : ((2U == (3U 
                                                  & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result))
                                           ? (0x00ff0000U 
                                              & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U] 
                                                 << 0x00000010U))
                                           : VL_SHIFTL_III(32,32,32, vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U], 0x00000018U))))
                               : ((1U == (7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                >> 8U)))
                                   ? ((0U == (3U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result))
                                       ? (0x0000ffffU 
                                          & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U])
                                       : VL_SHIFTL_III(32,32,32, vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U], 0x00000010U))
                                   : vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U]))),32);
    bufp->fullCData(oldp+90,((0x000000ffU & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U])),8);
    bufp->fullCData(oldp+91,((0x000000ffU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U] 
                                             >> 8U))),8);
    bufp->fullBit(oldp+92,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_write));
    bufp->fullIData(oldp+93,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_bypath_data),32);
    bufp->fullBit(oldp+94,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U] 
                                  >> 0x0000000dU))));
    bufp->fullSData(oldp+95,((0x00000fffU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U] 
                                             >> 1U))),12);
    bufp->fullBit(oldp+96,((1U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U])));
    bufp->fullIData(oldp+97,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__csr_read_data),32);
    bufp->fullIData(oldp+98,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mtvec),32);
    bufp->fullIData(oldp+99,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mepc),32);
    bufp->fullBit(oldp+100,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__ecall_valid));
    bufp->fullIData(oldp+101,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mcycle),32);
    bufp->fullIData(oldp+102,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mcycleh),32);
    bufp->fullIData(oldp+103,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mvendorid),32);
    bufp->fullIData(oldp+104,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__marchid),32);
    bufp->fullIData(oldp+105,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mcause),32);
    bufp->fullIData(oldp+106,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mstatus),32);
    bufp->fullBit(oldp+107,((1U & ((2U == (7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                 >> 0x00000015U)))
                                    ? (1U & (((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                               >> 0x00000014U) 
                                              & ((~ 
                                                  (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result 
                                                   >> 0x0000001fU)) 
                                                 & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                    >> 0x00000014U))) 
                                             | ((~ 
                                                 (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                  >> 0x00000014U)) 
                                                & ((~ 
                                                    (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                     >> 0x00000014U)) 
                                                   & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result 
                                                      >> 0x0000001fU)))))
                                    : ((6U == (7U & 
                                               (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                >> 0x00000015U)))
                                        ? (1U & (((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                   >> 0x00000014U) 
                                                  & ((~ 
                                                      (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                       >> 0x00000014U)) 
                                                     & (~ 
                                                        (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result 
                                                         >> 0x0000001fU)))) 
                                                 | ((~ 
                                                     (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                      >> 0x00000014U)) 
                                                    & ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                        >> 0x00000014U) 
                                                       & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result 
                                                          >> 0x0000001fU)))))
                                        : 0U)))));
    bufp->fullIData(oldp+108,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__temp_sub),32);
    bufp->fullQData(oldp+109,((QData)((IData)(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                << 0x0000000bU) 
                                               | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                  >> 0x00000015U))))),33);
    bufp->fullQData(oldp+111,((QData)((IData)(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                << 0x0000000bU) 
                                               | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                                  >> 0x00000015U))))),33);
    bufp->fullQData(oldp+113,((0x00000001ffffffffULL 
                               & (1ULL + ((~ (QData)((IData)(
                                                             ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                               << 0x0000000bU) 
                                                              | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                                                 >> 0x00000015U))))) 
                                          + (QData)((IData)(
                                                            ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                              << 0x0000000bU) 
                                                             | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                                >> 0x00000015U)))))))),33);
    bufp->fullIData(oldp+115,((((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                 >> 0x00000013U)) << 
                               (0x0000001fU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                               >> 0x0000000eU)))),32);
    bufp->fullIData(oldp+116,((((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                 >> 0x00000013U)) >> 
                               (0x0000001fU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                               >> 0x0000000eU)))),32);
    bufp->fullIData(oldp+117,(VL_SHIFTRS_III(32,32,5, 
                                             ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                               << 0x0000000dU) 
                                              | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                 >> 0x00000013U)), 
                                             (0x0000001fU 
                                              & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                 >> 0x0000000eU)))),32);
    bufp->fullQData(oldp+118,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg),64);
    bufp->fullIData(oldp+120,((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                       >> 0x00000020U))),32);
    bufp->fullIData(oldp+121,((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg)),32);
    bufp->fullCData(oldp+122,((0x0000001fU & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 2U)))),5);
    bufp->fullCData(oldp+123,((0x0000001fU & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 7U)))),5);
    bufp->fullCData(oldp+124,((0x0000001fU & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 0x0000000fU)))),5);
    bufp->fullCData(oldp+125,((0x0000001fU & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 0x00000014U)))),5);
    bufp->fullCData(oldp+126,((7U & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                             >> 0x0000000cU)))),3);
    bufp->fullCData(oldp+127,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__func_r),4);
    bufp->fullCData(oldp+128,((0x0000007fU & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 0x00000019U)))),7);
    bufp->fullIData(oldp+129,(((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                        >> 0x0000000cU)) 
                               << 0x0000000cU)),32);
    bufp->fullIData(oldp+130,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__I_imm),32);
    bufp->fullIData(oldp+131,((((- (IData)((1U & (IData)(
                                                         (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                          >> 0x0000001fU))))) 
                                << 0x0000000cU) | (
                                                   (0x00000fe0U 
                                                    & ((IData)(
                                                               (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                                >> 0x00000019U)) 
                                                       << 5U)) 
                                                   | (0x0000001fU 
                                                      & (IData)(
                                                                (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                                 >> 7U)))))),32);
    bufp->fullIData(oldp+132,((((- (IData)((1U & (IData)(
                                                         (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                          >> 0x0000001fU))))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & ((IData)(
                                                               (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                                >> 7U)) 
                                                       << 0x0000000bU)) 
                                                   | ((0x000007e0U 
                                                       & ((IData)(
                                                                  (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                                   >> 0x00000019U)) 
                                                          << 5U)) 
                                                      | (0x0000001eU 
                                                         & ((IData)(
                                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                                     >> 8U)) 
                                                            << 1U)))))),32);
    bufp->fullIData(oldp+133,((((- (IData)((1U & (IData)(
                                                         (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                          >> 0x0000001fU))))) 
                                << 0x00000014U) | (
                                                   (((0x000001feU 
                                                      & ((IData)(
                                                                 (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                                  >> 0x0000000cU)) 
                                                         << 1U)) 
                                                     | (1U 
                                                        & (IData)(
                                                                  (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                                   >> 0x00000014U)))) 
                                                    << 0x0000000bU) 
                                                   | (0x000007feU 
                                                      & ((IData)(
                                                                 (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                                  >> 0x00000015U)) 
                                                         << 1U))))),32);
    bufp->fullIData(oldp+134,(((0U == (0x0000001fU 
                                       & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                  >> 0x0000000fU))))
                                ? 0U : vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile
                               [(0x0000001fU & (IData)(
                                                       (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                        >> 0x0000000fU)))])),32);
    bufp->fullIData(oldp+135,(((0U == (0x0000001fU 
                                       & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                  >> 0x00000014U))))
                                ? 0U : vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile
                               [(0x0000001fU & (IData)(
                                                       (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                        >> 0x00000014U)))])),32);
    bufp->fullIData(oldp+136,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata1_true),32);
    bufp->fullIData(oldp+137,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata2_true),32);
    bufp->fullBit(oldp+138,((0x18U == (0x0000001fU 
                                       & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                  >> 2U))))));
    bufp->fullCData(oldp+139,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__ALUop),3);
    bufp->fullCData(oldp+140,(((1U == (7U & (IData)(
                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                     >> 0x0000000cU))))
                                ? 0U : ((5U == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__func_r))
                                         ? 2U : ((0x0dU 
                                                  == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__func_r))
                                                  ? 3U
                                                  : 1U)))),2);
    bufp->fullBit(oldp+141,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__Jump));
    bufp->fullBit(oldp+142,(((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_11) 
                             & ((5U == (7U & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 0x0000000cU)))) 
                                | (1U == (7U & (IData)(
                                                       (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                        >> 0x0000000cU))))))));
    bufp->fullBit(oldp+143,((0U == (0x0000001fU & (IData)(
                                                          (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                           >> 2U))))));
    bufp->fullBit(oldp+144,((8U == (0x0000001fU & (IData)(
                                                          (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                           >> 2U))))));
    bufp->fullIData(oldp+145,((((4U == (0x0000001fU 
                                        & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                   >> 2U)))) 
                                | (0U == (0x0000001fU 
                                          & (IData)(
                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                     >> 2U)))))
                                ? vlSelfRef.custom_cpu__DOT__ID_EX__DOT__I_imm
                                : ((8U == (0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 2U))))
                                    ? (((- (IData)(
                                                   (1U 
                                                    & (IData)(
                                                              (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                               >> 0x0000001fU))))) 
                                        << 0x0000000cU) 
                                       | ((0x00000fe0U 
                                           & ((IData)(
                                                      (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                       >> 0x00000019U)) 
                                              << 5U)) 
                                          | (0x0000001fU 
                                             & (IData)(
                                                       (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                        >> 7U)))))
                                    : vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata2_true))),32);
    bufp->fullCData(oldp+146,((0x0000001fU & ((4U == 
                                               (0x0000001fU 
                                                & (IData)(
                                                          (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                           >> 2U))))
                                               ? (IData)(
                                                         (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                          >> 0x00000014U))
                                               : vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata2_true))),5);
    bufp->fullBit(oldp+147,((IData)((0x0000000002000030ULL 
                                     == (0x00000000fe00707cULL 
                                         & vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg)))));
    bufp->fullBit(oldp+148,((0x00100073U == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg))));
    bufp->fullBit(oldp+149,((0x1cU == (0x0000001fU 
                                       & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                  >> 2U))))));
    bufp->fullSData(oldp+150,((0x00000fffU & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 0x00000014U)))),12);
    bufp->fullBit(oldp+151,((IData)(((0x0000000000000070ULL 
                                      == (0x000000000000007cULL 
                                          & vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg)) 
                                     & ((1U == (7U 
                                                & (IData)(
                                                          (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                           >> 0x0000000cU)))) 
                                        | (2U == (7U 
                                                  & (IData)(
                                                            (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                             >> 0x0000000cU)))))))));
    bufp->fullBit(oldp+152,((1U != (7U & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                  >> 0x0000000cU))))));
    bufp->fullBit(oldp+153,((0x00000073U == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg))));
    bufp->fullBit(oldp+154,((0x30200073U == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg))));
    bufp->fullBit(oldp+155,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__ID_work));
    bufp->fullBit(oldp+156,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__ID_done));
    bufp->fullBit(oldp+157,(((((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_write) 
                               & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_5) 
                                  | (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_6))) 
                              & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                 >> 7U)) | ((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[1U] 
                                             >> 0x0000000bU) 
                                            & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_write) 
                                               & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_7) 
                                                  | (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_8)))))));
    bufp->fullBit(oldp+158,(((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_write) 
                             & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_5) 
                                | (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_6)))));
    bufp->fullBit(oldp+159,((1U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[1U] 
                                   >> 0x0000000bU))));
    bufp->fullBit(oldp+160,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_write));
    bufp->fullCData(oldp+161,((0x0000001fU & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U])),5);
    bufp->fullIData(oldp+162,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_data),32);
    bufp->fullBit(oldp+163,(((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_write) 
                             & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_7) 
                                | (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_8)))));
    bufp->fullBit(oldp+164,((1U & vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U])));
    bufp->fullIData(oldp+165,(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[0U]),32);
    bufp->fullCData(oldp+166,((0x0000001fU & (vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U] 
                                              >> 1U))),5);
    bufp->fullBit(oldp+167,(((5U == (0x0000001fU & (IData)(
                                                           (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                            >> 2U)))) 
                             | ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__Jump) 
                                | ((0U == (0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 2U)))) 
                                   | ((0x0dU == (0x0000001fU 
                                                 & (IData)(
                                                           (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                            >> 2U)))) 
                                      | ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_11) 
                                         | (IData)(
                                                   ((0x0000000000000070ULL 
                                                     == 
                                                     (0x000000000000007cULL 
                                                      & vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg)) 
                                                    & (~ 
                                                       ((0x00000073U 
                                                         == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg)) 
                                                        | (0x30200073U 
                                                           == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg)))))))))))));
    bufp->fullIData(oldp+168,((0xfffffffeU & (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata1_true 
                                              + vlSelfRef.custom_cpu__DOT__ID_EX__DOT__I_imm))),32);
    bufp->fullIData(oldp+169,(((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                        >> 0x00000020U)) 
                               + (((- (IData)((1U & (IData)(
                                                            (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                             >> 0x0000001fU))))) 
                                   << 0x0000000cU) 
                                  | ((0x00000800U & 
                                      ((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                >> 7U)) 
                                       << 0x0000000bU)) 
                                     | ((0x000007e0U 
                                         & ((IData)(
                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                     >> 0x00000019U)) 
                                            << 5U)) 
                                        | (0x0000001eU 
                                           & ((IData)(
                                                      (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                       >> 8U)) 
                                              << 1U))))))),32);
    bufp->fullIData(oldp+170,(((0x1bU == (0x0000001fU 
                                          & (IData)(
                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                     >> 2U))))
                                ? ((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                            >> 0x00000020U)) 
                                   + (((- (IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                              >> 0x0000001fU))))) 
                                       << 0x00000014U) 
                                      | ((((0x000001feU 
                                            & ((IData)(
                                                       (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                        >> 0x0000000cU)) 
                                               << 1U)) 
                                           | (1U & (IData)(
                                                           (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                            >> 0x00000014U)))) 
                                          << 0x0000000bU) 
                                         | (0x000007feU 
                                            & ((IData)(
                                                       (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                        >> 0x00000015U)) 
                                               << 1U)))))
                                : (0xfffffffeU & (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata1_true 
                                                  + vlSelfRef.custom_cpu__DOT__ID_EX__DOT__I_imm)))),32);
    bufp->fullIData(oldp+171,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_addr),32);
    bufp->fullBit(oldp+172,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__prediction_out));
    bufp->fullBit(oldp+173,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__predictor_update));
    bufp->fullBit(oldp+174,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_yes));
    bufp->fullCData(oldp+175,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__predictor_current_state),5);
    bufp->fullIData(oldp+176,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[0]),32);
    bufp->fullIData(oldp+177,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[1]),32);
    bufp->fullIData(oldp+178,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[2]),32);
    bufp->fullIData(oldp+179,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[3]),32);
    bufp->fullIData(oldp+180,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[4]),32);
    bufp->fullIData(oldp+181,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[5]),32);
    bufp->fullIData(oldp+182,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[6]),32);
    bufp->fullIData(oldp+183,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[7]),32);
    bufp->fullIData(oldp+184,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[8]),32);
    bufp->fullIData(oldp+185,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[9]),32);
    bufp->fullIData(oldp+186,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[10]),32);
    bufp->fullIData(oldp+187,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[11]),32);
    bufp->fullIData(oldp+188,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[12]),32);
    bufp->fullIData(oldp+189,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[13]),32);
    bufp->fullIData(oldp+190,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[14]),32);
    bufp->fullIData(oldp+191,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[15]),32);
    bufp->fullIData(oldp+192,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[16]),32);
    bufp->fullIData(oldp+193,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[17]),32);
    bufp->fullIData(oldp+194,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[18]),32);
    bufp->fullIData(oldp+195,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[19]),32);
    bufp->fullIData(oldp+196,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[20]),32);
    bufp->fullIData(oldp+197,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[21]),32);
    bufp->fullIData(oldp+198,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[22]),32);
    bufp->fullIData(oldp+199,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[23]),32);
    bufp->fullIData(oldp+200,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[24]),32);
    bufp->fullIData(oldp+201,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[25]),32);
    bufp->fullIData(oldp+202,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[26]),32);
    bufp->fullIData(oldp+203,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[27]),32);
    bufp->fullIData(oldp+204,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[28]),32);
    bufp->fullIData(oldp+205,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[29]),32);
    bufp->fullIData(oldp+206,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[30]),32);
    bufp->fullIData(oldp+207,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[31]),32);
    bufp->fullIData(oldp+208,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+209,(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__IF_current_state),5);
    bufp->fullCData(oldp+210,(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__IF_next_state),5);
    bufp->fullIData(oldp+211,(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__Instruction_reg),32);
    bufp->fullIData(oldp+212,(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__PC_reg),32);
    bufp->fullBit(oldp+213,(((~ (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__prediction_incorrect)) 
                             & (0x10U == (IData)(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__IF_current_state)))));
    bufp->fullWData(oldp+214,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg),215);
    bufp->fullIData(oldp+221,(((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[6U] 
                                << 9U) | (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[5U] 
                                          >> 0x00000017U))),32);
    bufp->fullIData(oldp+222,(((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[5U] 
                                << 0x0000000aU) | (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[4U] 
                                                   >> 0x00000016U))),32);
    bufp->fullIData(oldp+223,(((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[4U] 
                                << 0x0000000dU) | (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                                   >> 0x00000013U))),32);
    bufp->fullCData(oldp+224,((0x0000001fU & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                              >> 0x0000000eU))),5);
    bufp->fullIData(oldp+225,(((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                << 0x00000014U) | (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[2U] 
                                                   >> 0x0000000cU))),32);
    bufp->fullCData(oldp+226,((3U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                     >> 0x0000000cU))),2);
    bufp->fullCData(oldp+227,((7U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[4U] 
                                     >> 0x00000013U))),3);
    bufp->fullBit(oldp+228,((1U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[1U] 
                                   >> 0x0000000aU))));
    bufp->fullBit(oldp+229,((1U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U] 
                                   >> 5U))));
    bufp->fullBit(oldp+230,((1U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[5U] 
                                   >> 0x00000016U))));
    bufp->fullCData(oldp+231,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_current_state),5);
    bufp->fullBit(oldp+232,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_work));
    bufp->fullBit(oldp+233,((0x10U == (IData)(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_current_state))));
    bufp->fullIData(oldp+234,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current),32);
    bufp->fullCData(oldp+235,((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current 
                               >> 0x00000018U)),8);
    bufp->fullCData(oldp+236,((0x000000ffU & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current 
                                              >> 0x00000010U))),8);
    bufp->fullCData(oldp+237,((0x000000ffU & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current 
                                              >> 8U))),8);
    bufp->fullCData(oldp+238,((0x000000ffU & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current)),8);
    bufp->fullWData(oldp+239,(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg),71);
    bufp->fullIData(oldp+242,(((vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[2U] 
                                << 0x0000001aU) | (vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U] 
                                                   >> 6U))),32);
    bufp->fullBit(oldp+243,((1U & (vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[2U] 
                                   >> 6U))));
    bufp->fullBit(oldp+244,(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__WB_work));
    bufp->fullBit(oldp+245,((vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U] 
                             & (IData)(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__WB_work))));
    bufp->fullIData(oldp+246,(vlSelfRef.custom_cpu__DOT__ifu_mem_inst__DOT__ifu_rdata),32);
    bufp->fullBit(oldp+247,(((~ (IData)(vlSelfRef.custom_cpu__DOT__ifu_mem_inst__DOT__ifu_busy)) 
                             & (IData)(vlSelfRef.custom_cpu__DOT__ifu_mem_inst__DOT__Inst_Req_Valid))));
    bufp->fullBit(oldp+248,(((IData)(vlSelfRef.custom_cpu__DOT__ifu_mem_inst__DOT__Inst_Ready) 
                             & (IData)(vlSelfRef.custom_cpu__DOT__ifu_mem_inst__DOT__ifu_busy))));
    bufp->fullBit(oldp+249,(vlSelfRef.clk));
    bufp->fullBit(oldp+250,(vlSelfRef.rst));
    bufp->fullIData(oldp+251,(vlSelfRef.PC),32);
    bufp->fullIData(oldp+252,(vlSelfRef.Instruction),32);
    bufp->fullIData(oldp+253,(vlSelfRef.Address),32);
    bufp->fullBit(oldp+254,(vlSelfRef.MemWrite));
    bufp->fullIData(oldp+255,(vlSelfRef.Write_data),32);
    bufp->fullCData(oldp+256,(vlSelfRef.Write_strb),4);
    bufp->fullBit(oldp+257,(vlSelfRef.MemRead));
    bufp->fullBit(oldp+258,(vlSelfRef.Mem_Req_Ready));
    bufp->fullIData(oldp+259,(vlSelfRef.Read_data),32);
    bufp->fullBit(oldp+260,(vlSelfRef.Read_data_Valid));
    bufp->fullBit(oldp+261,(vlSelfRef.Read_data_Ready));
    bufp->fullBit(oldp+262,(vlSelfRef.intr));
    bufp->fullIData(oldp+263,(vlSelfRef.cpu_perf_cnt_0),32);
    bufp->fullIData(oldp+264,(vlSelfRef.cpu_perf_cnt_1),32);
    bufp->fullIData(oldp+265,(vlSelfRef.cpu_perf_cnt_2),32);
    bufp->fullIData(oldp+266,(vlSelfRef.cpu_perf_cnt_3),32);
    bufp->fullIData(oldp+267,(vlSelfRef.cpu_perf_cnt_4),32);
    bufp->fullIData(oldp+268,(vlSelfRef.cpu_perf_cnt_5),32);
    bufp->fullIData(oldp+269,(vlSelfRef.cpu_perf_cnt_6),32);
    bufp->fullIData(oldp+270,(vlSelfRef.cpu_perf_cnt_7),32);
    bufp->fullIData(oldp+271,(vlSelfRef.cpu_perf_cnt_8),32);
    bufp->fullIData(oldp+272,(vlSelfRef.cpu_perf_cnt_9),32);
    bufp->fullIData(oldp+273,(vlSelfRef.cpu_perf_cnt_10),32);
    bufp->fullIData(oldp+274,(vlSelfRef.cpu_perf_cnt_11),32);
    bufp->fullIData(oldp+275,(vlSelfRef.cpu_perf_cnt_12),32);
    bufp->fullIData(oldp+276,(vlSelfRef.cpu_perf_cnt_13),32);
    bufp->fullIData(oldp+277,(vlSelfRef.cpu_perf_cnt_14),32);
    bufp->fullIData(oldp+278,(vlSelfRef.cpu_perf_cnt_15),32);
    bufp->fullWData(oldp+279,(vlSelfRef.inst_retire),70);
    bufp->fullIData(oldp+282,(vlSelfRef.a0_out),32);
    bufp->fullCData(oldp+283,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__predictor_next_state),5);
    bufp->fullCData(oldp+284,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_next_state),5);
}
