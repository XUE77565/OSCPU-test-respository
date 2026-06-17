// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vcustom_cpu__Syms.h"


void Vcustom_cpu___024root__trace_chg_0_sub_0(Vcustom_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcustom_cpu___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_chg_0\n"); );
    // Body
    Vcustom_cpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcustom_cpu___024root*>(voidSelf);
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vcustom_cpu___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vcustom_cpu___024root__trace_chg_0_sub_0(Vcustom_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_chg_0_sub_0\n"); );
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<4>/*127:0*/ __Vtemp_3;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__prediction_incorrect));
        bufp->chgQData(oldp+1,((((QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_yes)) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_addr)))),33);
        bufp->chgIData(oldp+3,(((1U & ((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Branch_real) 
                                       | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                          >> 0x0000000cU)))
                                 ? ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                                     << 8U) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                               >> 0x00000018U))
                                 : ((IData)(4U) + (
                                                   (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[6U] 
                                                    << 7U) 
                                                   | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                                                      >> 0x00000019U))))),32);
        bufp->chgBit(oldp+4,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_valid));
        bufp->chgBit(oldp+5,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__ID_ready));
        bufp->chgBit(oldp+6,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_valid));
        bufp->chgBit(oldp+7,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_ready));
        bufp->chgBit(oldp+8,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_work));
        bufp->chgBit(oldp+9,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__MEM_ready));
        bufp->chgBit(oldp+10,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_to_WB_valid));
        bufp->chgQData(oldp+11,((((QData)((IData)(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__PC_reg)) 
                                  << 0x00000020U) | (QData)((IData)(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__Instruction_reg)))),64);
        bufp->chgWData(oldp+13,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data),270);
        bufp->chgWData(oldp+22,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_to_MEM_data),215);
        bufp->chgQData(oldp+29,((((QData)((IData)((1U 
                                                   & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                      >> 7U)))) 
                                  << 0x00000026U) | 
                                 (((QData)((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_write)) 
                                   << 0x00000025U) 
                                  | (((QData)((IData)(
                                                      (0x0000001fU 
                                                       & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U]))) 
                                      << 0x00000020U) 
                                     | (QData)((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_bypath_data)))))),39);
        __Vtemp_3[0U] = (IData)((((QData)((IData)((0x0000001fU 
                                                   & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U]))) 
                                  << 0x00000021U) | 
                                 (((QData)((IData)(
                                                   (1U 
                                                    & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U] 
                                                       >> 5U)))) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_data)))));
        __Vtemp_3[1U] = ((0xffffffc0U & ((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                          << 0x0000001aU) 
                                         | (0x03ffffc0U 
                                            & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[2U] 
                                               >> 6U)))) 
                         | (IData)(((((QData)((IData)(
                                                      (0x0000001fU 
                                                       & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U]))) 
                                      << 0x00000021U) 
                                     | (((QData)((IData)(
                                                         (1U 
                                                          & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U] 
                                                             >> 5U)))) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_data)))) 
                                    >> 0x00000020U)));
        __Vtemp_3[2U] = ((0x00000040U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[5U] 
                                         >> 0x00000010U)) 
                         | (0x0000003fU & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                           >> 6U)));
        __Vtemp_3[3U] = 0U;
        bufp->chgWData(oldp+31,(__Vtemp_3),103);
        bufp->chgQData(oldp+35,((((QData)((IData)((1U 
                                                   & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[1U] 
                                                      >> 0x0000000bU)))) 
                                  << 0x00000026U) | 
                                 (((QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_write)) 
                                   << 0x00000025U) 
                                  | (((QData)((IData)(
                                                      (0x0000001fU 
                                                       & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U]))) 
                                      << 0x00000020U) 
                                     | (QData)((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_data)))))),39);
        bufp->chgQData(oldp+37,((((QData)((IData)((1U 
                                                   & vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U]))) 
                                  << 0x00000025U) | 
                                 (((QData)((IData)(
                                                   (0x0000001fU 
                                                    & (vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U] 
                                                       >> 1U)))) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[0U]))))),38);
        bufp->chgCData(oldp+39,((0x0000001fU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[6U] 
                                                >> 0x00000019U))),5);
        bufp->chgIData(oldp+40,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[7U] 
                                  << 2U) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[6U] 
                                            >> 0x0000001eU))),32);
        bufp->chgCData(oldp+41,((7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                       >> 0x00000015U))),3);
        bufp->chgIData(oldp+42,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                  << 0x0000000bU) | 
                                 (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                  >> 0x00000015U))),32);
        bufp->chgIData(oldp+43,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                  << 0x0000000bU) | 
                                 (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                  >> 0x00000015U))),32);
        bufp->chgCData(oldp+44,((3U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                       >> 0x00000013U))),2);
        bufp->chgIData(oldp+45,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                  << 0x0000000dU) | 
                                 (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                  >> 0x00000013U))),32);
        bufp->chgCData(oldp+46,((0x0000001fU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                >> 0x0000000eU))),5);
        bufp->chgIData(oldp+47,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[6U] 
                                  << 7U) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                                            >> 0x00000019U))),32);
        bufp->chgCData(oldp+48,((7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                       >> 8U))),3);
        bufp->chgBit(oldp+49,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                                     >> 0x00000018U))));
        bufp->chgIData(oldp+50,(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[5U] 
                                  << 8U) | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                            >> 0x00000018U))),32);
        bufp->chgBit(oldp+51,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                     >> 0x0000000dU))));
        bufp->chgBit(oldp+52,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[7U] 
                                     >> 0x0000001eU))));
        bufp->chgBit(oldp+53,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                     >> 0x0000000cU))));
        bufp->chgBit(oldp+54,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                     >> 0x0000000bU))));
        bufp->chgBit(oldp+55,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                     >> 7U))));
        bufp->chgBit(oldp+56,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                     >> 6U))));
        bufp->chgBit(oldp+57,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                     >> 5U))));
        bufp->chgCData(oldp+58,((0x0000001fU & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U])),5);
        bufp->chgIData(oldp+59,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U]),32);
        bufp->chgBit(oldp+60,((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[7U] 
                               >> 0x0000001fU)));
        bufp->chgWData(oldp+61,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg),270);
        bufp->chgIData(oldp+70,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result),32);
        bufp->chgIData(oldp+71,(((0U == (3U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                               >> 0x00000013U)))
                                  ? (((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                       << 0x0000000dU) 
                                      | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                         >> 0x00000013U)) 
                                     << (0x0000001fU 
                                         & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
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
                                      : ((3U == (3U 
                                                 & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
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
        bufp->chgBit(oldp+72,((0U == vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result)));
        bufp->chgBit(oldp+73,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Branch_real));
        bufp->chgIData(oldp+74,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result),32);
        bufp->chgBit(oldp+75,((1U & ((0U == (7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                   >> 8U)))
                                      ? (0U == vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result)
                                      : ((1U == (7U 
                                                 & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                    >> 8U)))
                                          ? (~ (0U 
                                                == vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result))
                                          : (((4U == 
                                               (7U 
                                                & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                   >> 8U))) 
                                              | (6U 
                                                 == 
                                                 (7U 
                                                  & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                     >> 8U))))
                                              ? (~ 
                                                 (0U 
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
                                                  ? 
                                                 (0U 
                                                  == vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__Result)
                                                  : 0U)))))));
        bufp->chgQData(oldp+76,(((- (QData)((IData)(
                                                    (1U 
                                                     & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[7U] 
                                                        >> 0x0000001eU))))) 
                                 & ((QData)((IData)(
                                                    ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                      << 0x0000000bU) 
                                                     | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                        >> 0x00000015U)))) 
                                    * (QData)((IData)(
                                                      ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                        << 0x0000000bU) 
                                                       | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                                          >> 0x00000015U))))))),64);
        bufp->chgBit(oldp+78,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__block_cancel));
        bufp->chgIData(oldp+79,((0xfffffffcU & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result)),32);
        bufp->chgCData(oldp+80,((3U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result)),2);
        bufp->chgCData(oldp+81,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Write_strb),4);
        bufp->chgIData(oldp+82,(((0U == (7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                               >> 8U)))
                                  ? ((0U == (3U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result))
                                      ? (0x000000ffU 
                                         & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U])
                                      : ((1U == (3U 
                                                 & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result))
                                          ? (0x0000ff00U 
                                             & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U] 
                                                << 8U))
                                          : ((2U == 
                                              (3U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result))
                                              ? (0x00ff0000U 
                                                 & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U] 
                                                    << 0x00000010U))
                                              : VL_SHIFTL_III(32,32,32, vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U], 0x00000018U))))
                                  : ((1U == (7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                   >> 8U)))
                                      ? ((0U == (3U 
                                                 & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__Result))
                                          ? (0x0000ffffU 
                                             & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U])
                                          : VL_SHIFTL_III(32,32,32, vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U], 0x00000010U))
                                      : vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U]))),32);
        bufp->chgCData(oldp+83,((0x000000ffU & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U])),8);
        bufp->chgCData(oldp+84,((0x000000ffU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[0U] 
                                                >> 8U))),8);
        bufp->chgBit(oldp+85,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_write));
        bufp->chgIData(oldp+86,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_bypath_data),32);
        bufp->chgBit(oldp+87,((1U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U] 
                                     >> 0x0000000dU))));
        bufp->chgSData(oldp+88,((0x00000fffU & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U] 
                                                >> 1U))),12);
        bufp->chgBit(oldp+89,((1U & vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[8U])));
        bufp->chgIData(oldp+90,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__csr_read_data),32);
        bufp->chgIData(oldp+91,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mcycle),32);
        bufp->chgIData(oldp+92,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mcycleh),32);
        bufp->chgIData(oldp+93,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__mvendorid),32);
        bufp->chgIData(oldp+94,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__CSR_INST__DOT__marchid),32);
        bufp->chgBit(oldp+95,((1U & ((2U == (7U & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
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
                                      : ((6U == (7U 
                                                 & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                    >> 0x00000015U)))
                                          ? (1U & (
                                                   ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
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
        bufp->chgIData(oldp+96,(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__alu_ex__DOT__temp_sub),32);
        bufp->chgQData(oldp+97,((QData)((IData)(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[4U] 
                                                  << 0x0000000bU) 
                                                 | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                    >> 0x00000015U))))),33);
        bufp->chgQData(oldp+99,((QData)((IData)(((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[3U] 
                                                  << 0x0000000bU) 
                                                 | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                                    >> 0x00000015U))))),33);
        bufp->chgQData(oldp+101,((0x00000001ffffffffULL 
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
        bufp->chgIData(oldp+103,((((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                    << 0x0000000dU) 
                                   | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                      >> 0x00000013U)) 
                                  << (0x0000001fU & 
                                      (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                       >> 0x0000000eU)))),32);
        bufp->chgIData(oldp+104,((((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                    << 0x0000000dU) 
                                   | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                      >> 0x00000013U)) 
                                  >> (0x0000001fU & 
                                      (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                       >> 0x0000000eU)))),32);
        bufp->chgIData(oldp+105,(VL_SHIFTRS_III(32,32,5, 
                                                ((vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[2U] 
                                                  << 0x0000000dU) 
                                                 | (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                    >> 0x00000013U)), 
                                                (0x0000001fU 
                                                 & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                                    >> 0x0000000eU)))),32);
        bufp->chgQData(oldp+106,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg),64);
        bufp->chgIData(oldp+108,((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                          >> 0x00000020U))),32);
        bufp->chgIData(oldp+109,((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg)),32);
        bufp->chgCData(oldp+110,((0x0000001fU & (IData)(
                                                        (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                         >> 2U)))),5);
        bufp->chgCData(oldp+111,((0x0000001fU & (IData)(
                                                        (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                         >> 7U)))),5);
        bufp->chgCData(oldp+112,((0x0000001fU & (IData)(
                                                        (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                         >> 0x0000000fU)))),5);
        bufp->chgCData(oldp+113,((0x0000001fU & (IData)(
                                                        (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                         >> 0x00000014U)))),5);
        bufp->chgCData(oldp+114,((7U & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                >> 0x0000000cU)))),3);
        bufp->chgCData(oldp+115,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__func_r),4);
        bufp->chgCData(oldp+116,((0x0000007fU & (IData)(
                                                        (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                         >> 0x00000019U)))),7);
        bufp->chgIData(oldp+117,(((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                           >> 0x0000000cU)) 
                                  << 0x0000000cU)),32);
        bufp->chgIData(oldp+118,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__I_imm),32);
        bufp->chgIData(oldp+119,((((- (IData)((1U & (IData)(
                                                            (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                             >> 0x0000001fU))))) 
                                   << 0x0000000cU) 
                                  | ((0x00000fe0U & 
                                      ((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                >> 0x00000019U)) 
                                       << 5U)) | (0x0000001fU 
                                                  & (IData)(
                                                            (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                             >> 7U)))))),32);
        bufp->chgIData(oldp+120,((((- (IData)((1U & (IData)(
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
                                              << 1U)))))),32);
        bufp->chgIData(oldp+121,((((- (IData)((1U & (IData)(
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
                                           << 1U))))),32);
        bufp->chgIData(oldp+122,(((0U == (0x0000001fU 
                                          & (IData)(
                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                     >> 0x0000000fU))))
                                   ? 0U : vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile
                                  [(0x0000001fU & (IData)(
                                                          (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                           >> 0x0000000fU)))])),32);
        bufp->chgIData(oldp+123,(((0U == (0x0000001fU 
                                          & (IData)(
                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                     >> 0x00000014U))))
                                   ? 0U : vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile
                                  [(0x0000001fU & (IData)(
                                                          (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                           >> 0x00000014U)))])),32);
        bufp->chgIData(oldp+124,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata1_true),32);
        bufp->chgIData(oldp+125,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata2_true),32);
        bufp->chgBit(oldp+126,((0x18U == (0x0000001fU 
                                          & (IData)(
                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                     >> 2U))))));
        bufp->chgCData(oldp+127,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__ALUop),3);
        bufp->chgCData(oldp+128,(((1U == (7U & (IData)(
                                                       (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                        >> 0x0000000cU))))
                                   ? 0U : ((5U == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__func_r))
                                            ? 2U : 
                                           ((0x0dU 
                                             == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__func_r))
                                             ? 3U : 1U)))),2);
        bufp->chgBit(oldp+129,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__Jump));
        bufp->chgBit(oldp+130,(((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_11) 
                                & ((5U == (7U & (IData)(
                                                        (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                         >> 0x0000000cU)))) 
                                   | (1U == (7U & (IData)(
                                                          (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                           >> 0x0000000cU))))))));
        bufp->chgBit(oldp+131,((0U == (0x0000001fU 
                                       & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                  >> 2U))))));
        bufp->chgBit(oldp+132,((8U == (0x0000001fU 
                                       & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                  >> 2U))))));
        bufp->chgIData(oldp+133,((((4U == (0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
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
        bufp->chgCData(oldp+134,((0x0000001fU & ((4U 
                                                  == 
                                                  (0x0000001fU 
                                                   & (IData)(
                                                             (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                              >> 2U))))
                                                  ? (IData)(
                                                            (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                             >> 0x00000014U))
                                                  : vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata2_true))),5);
        bufp->chgBit(oldp+135,((IData)((0x0000000002000030ULL 
                                        == (0x00000000fe00707cULL 
                                            & vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg)))));
        bufp->chgBit(oldp+136,((0x00100073U == (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg))));
        bufp->chgBit(oldp+137,((0x1cU == (0x0000001fU 
                                          & (IData)(
                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                     >> 2U))))));
        bufp->chgSData(oldp+138,((0x00000fffU & (IData)(
                                                        (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                         >> 0x00000014U)))),12);
        bufp->chgBit(oldp+139,((IData)(((0x0000000000000070ULL 
                                         == (0x000000000000007cULL 
                                             & vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg)) 
                                        & ((1U == (7U 
                                                   & (IData)(
                                                             (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                              >> 0x0000000cU)))) 
                                           | (2U == 
                                              (7U & (IData)(
                                                            (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                             >> 0x0000000cU)))))))));
        bufp->chgBit(oldp+140,((1U != (7U & (IData)(
                                                    (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                     >> 0x0000000cU))))));
        bufp->chgBit(oldp+141,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__ID_work));
        bufp->chgBit(oldp+142,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__ID_done));
        bufp->chgBit(oldp+143,(((((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_write) 
                                  & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_5) 
                                     | (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_6))) 
                                 & (vlSelfRef.custom_cpu__DOT__EX_EX__DOT__ID_to_EX_data_reg[1U] 
                                    >> 7U)) | ((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[1U] 
                                                >> 0x0000000bU) 
                                               & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_write) 
                                                  & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_7) 
                                                     | (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_8)))))));
        bufp->chgBit(oldp+144,(((IData)(vlSelfRef.custom_cpu__DOT__EX_EX__DOT__EX_write) 
                                & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_5) 
                                   | (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_6)))));
        bufp->chgBit(oldp+145,((1U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[1U] 
                                      >> 0x0000000bU))));
        bufp->chgBit(oldp+146,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_write));
        bufp->chgCData(oldp+147,((0x0000001fU & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U])),5);
        bufp->chgIData(oldp+148,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_data),32);
        bufp->chgBit(oldp+149,(((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__MEM_write) 
                                & ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_7) 
                                   | (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_8)))));
        bufp->chgBit(oldp+150,((1U & vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U])));
        bufp->chgIData(oldp+151,(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[0U]),32);
        bufp->chgCData(oldp+152,((0x0000001fU & (vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U] 
                                                 >> 1U))),5);
        bufp->chgBit(oldp+153,(((5U == (0x0000001fU 
                                        & (IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                   >> 2U)))) 
                                | ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__Jump) 
                                   | ((0U == (0x0000001fU 
                                              & (IData)(
                                                        (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                         >> 2U)))) 
                                      | ((0x0dU == 
                                          (0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                      >> 2U)))) 
                                         | ((IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT____VdfgRegularize_h98a0652e_0_11) 
                                            | (0x1cU 
                                               == (0x0000001fU 
                                                   & (IData)(
                                                             (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                              >> 2U)))))))))));
        bufp->chgIData(oldp+154,((0xfffffffeU & (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata1_true 
                                                 + vlSelfRef.custom_cpu__DOT__ID_EX__DOT__I_imm))),32);
        bufp->chgIData(oldp+155,(((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                           >> 0x00000020U)) 
                                  + (((- (IData)((1U 
                                                  & (IData)(
                                                            (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                             >> 0x0000001fU))))) 
                                      << 0x0000000cU) 
                                     | ((0x00000800U 
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
                                                 << 1U))))))),32);
        bufp->chgIData(oldp+156,(((0x1bU == (0x0000001fU 
                                             & (IData)(
                                                       (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                        >> 2U))))
                                   ? ((IData)((vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                               >> 0x00000020U)) 
                                      + (((- (IData)(
                                                     (1U 
                                                      & (IData)(
                                                                (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__IF_to_ID_data_reg 
                                                                 >> 0x0000001fU))))) 
                                          << 0x00000014U) 
                                         | ((((0x000001feU 
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
                                                  << 1U)))))
                                   : (0xfffffffeU & 
                                      (vlSelfRef.custom_cpu__DOT__ID_EX__DOT__rdata1_true 
                                       + vlSelfRef.custom_cpu__DOT__ID_EX__DOT__I_imm)))),32);
        bufp->chgIData(oldp+157,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_addr),32);
        bufp->chgBit(oldp+158,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__prediction_out));
        bufp->chgBit(oldp+159,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__predictor_update));
        bufp->chgBit(oldp+160,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_yes));
        bufp->chgCData(oldp+161,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__predictor_current_state),5);
        bufp->chgIData(oldp+162,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[0]),32);
        bufp->chgIData(oldp+163,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[1]),32);
        bufp->chgIData(oldp+164,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[2]),32);
        bufp->chgIData(oldp+165,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[3]),32);
        bufp->chgIData(oldp+166,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[4]),32);
        bufp->chgIData(oldp+167,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[5]),32);
        bufp->chgIData(oldp+168,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[6]),32);
        bufp->chgIData(oldp+169,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[7]),32);
        bufp->chgIData(oldp+170,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[8]),32);
        bufp->chgIData(oldp+171,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[9]),32);
        bufp->chgIData(oldp+172,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[10]),32);
        bufp->chgIData(oldp+173,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[11]),32);
        bufp->chgIData(oldp+174,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[12]),32);
        bufp->chgIData(oldp+175,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[13]),32);
        bufp->chgIData(oldp+176,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[14]),32);
        bufp->chgIData(oldp+177,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[15]),32);
        bufp->chgIData(oldp+178,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[16]),32);
        bufp->chgIData(oldp+179,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[17]),32);
        bufp->chgIData(oldp+180,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[18]),32);
        bufp->chgIData(oldp+181,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[19]),32);
        bufp->chgIData(oldp+182,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[20]),32);
        bufp->chgIData(oldp+183,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[21]),32);
        bufp->chgIData(oldp+184,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[22]),32);
        bufp->chgIData(oldp+185,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[23]),32);
        bufp->chgIData(oldp+186,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[24]),32);
        bufp->chgIData(oldp+187,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[25]),32);
        bufp->chgIData(oldp+188,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[26]),32);
        bufp->chgIData(oldp+189,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[27]),32);
        bufp->chgIData(oldp+190,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[28]),32);
        bufp->chgIData(oldp+191,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[29]),32);
        bufp->chgIData(oldp+192,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[30]),32);
        bufp->chgIData(oldp+193,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[31]),32);
        bufp->chgIData(oldp+194,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+195,(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__IF_current_state),5);
        bufp->chgIData(oldp+196,(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__Instruction_reg),32);
        bufp->chgIData(oldp+197,(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__PC_reg),32);
        bufp->chgBit(oldp+198,(((~ (IData)(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__prediction_incorrect)) 
                                & (0x10U == (IData)(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__IF_current_state)))));
        bufp->chgWData(oldp+199,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg),215);
        bufp->chgIData(oldp+206,(((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[6U] 
                                   << 9U) | (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[5U] 
                                             >> 0x00000017U))),32);
        bufp->chgIData(oldp+207,(((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[5U] 
                                   << 0x0000000aU) 
                                  | (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[4U] 
                                     >> 0x00000016U))),32);
        bufp->chgIData(oldp+208,(((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[4U] 
                                   << 0x0000000dU) 
                                  | (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                     >> 0x00000013U))),32);
        bufp->chgCData(oldp+209,((0x0000001fU & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                                 >> 0x0000000eU))),5);
        bufp->chgIData(oldp+210,(((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                   << 0x00000014U) 
                                  | (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[2U] 
                                     >> 0x0000000cU))),32);
        bufp->chgCData(oldp+211,((3U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[3U] 
                                        >> 0x0000000cU))),2);
        bufp->chgCData(oldp+212,((7U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[4U] 
                                        >> 0x00000013U))),3);
        bufp->chgBit(oldp+213,((1U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[1U] 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+214,((1U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[0U] 
                                      >> 5U))));
        bufp->chgBit(oldp+215,((1U & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__EX_to_MEM_data_reg[5U] 
                                      >> 0x00000016U))));
        bufp->chgCData(oldp+216,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_current_state),5);
        bufp->chgBit(oldp+217,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_work));
        bufp->chgBit(oldp+218,((0x10U == (IData)(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_current_state))));
        bufp->chgIData(oldp+219,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current),32);
        bufp->chgCData(oldp+220,((vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current 
                                  >> 0x00000018U)),8);
        bufp->chgCData(oldp+221,((0x000000ffU & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current 
                                                 >> 0x00000010U))),8);
        bufp->chgCData(oldp+222,((0x000000ffU & (vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current 
                                                 >> 8U))),8);
        bufp->chgCData(oldp+223,((0x000000ffU & vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__Read_data_current)),8);
        bufp->chgWData(oldp+224,(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg),103);
        bufp->chgIData(oldp+228,(((vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[2U] 
                                   << 0x0000001aU) 
                                  | (vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U] 
                                     >> 6U))),32);
        bufp->chgBit(oldp+229,((1U & (vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[2U] 
                                      >> 6U))));
        bufp->chgBit(oldp+230,(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__WB_work));
        bufp->chgBit(oldp+231,((vlSelfRef.custom_cpu__DOT__WB_EX__DOT__MEM_to_WB_data_reg[1U] 
                                & (IData)(vlSelfRef.custom_cpu__DOT__WB_EX__DOT__WB_work))));
    }
    bufp->chgBit(oldp+232,(vlSelfRef.clk));
    bufp->chgBit(oldp+233,(vlSelfRef.rst));
    bufp->chgIData(oldp+234,(vlSelfRef.PC),32);
    bufp->chgBit(oldp+235,(vlSelfRef.Inst_Req_Valid));
    bufp->chgBit(oldp+236,(vlSelfRef.Inst_Req_Ready));
    bufp->chgIData(oldp+237,(vlSelfRef.Instruction),32);
    bufp->chgBit(oldp+238,(vlSelfRef.Inst_Valid));
    bufp->chgBit(oldp+239,(vlSelfRef.Inst_Ready));
    bufp->chgIData(oldp+240,(vlSelfRef.Address),32);
    bufp->chgBit(oldp+241,(vlSelfRef.MemWrite));
    bufp->chgIData(oldp+242,(vlSelfRef.Write_data),32);
    bufp->chgCData(oldp+243,(vlSelfRef.Write_strb),4);
    bufp->chgBit(oldp+244,(vlSelfRef.MemRead));
    bufp->chgBit(oldp+245,(vlSelfRef.Mem_Req_Ready));
    bufp->chgIData(oldp+246,(vlSelfRef.Read_data),32);
    bufp->chgBit(oldp+247,(vlSelfRef.Read_data_Valid));
    bufp->chgBit(oldp+248,(vlSelfRef.Read_data_Ready));
    bufp->chgBit(oldp+249,(vlSelfRef.intr));
    bufp->chgIData(oldp+250,(vlSelfRef.cpu_perf_cnt_0),32);
    bufp->chgIData(oldp+251,(vlSelfRef.cpu_perf_cnt_1),32);
    bufp->chgIData(oldp+252,(vlSelfRef.cpu_perf_cnt_2),32);
    bufp->chgIData(oldp+253,(vlSelfRef.cpu_perf_cnt_3),32);
    bufp->chgIData(oldp+254,(vlSelfRef.cpu_perf_cnt_4),32);
    bufp->chgIData(oldp+255,(vlSelfRef.cpu_perf_cnt_5),32);
    bufp->chgIData(oldp+256,(vlSelfRef.cpu_perf_cnt_6),32);
    bufp->chgIData(oldp+257,(vlSelfRef.cpu_perf_cnt_7),32);
    bufp->chgIData(oldp+258,(vlSelfRef.cpu_perf_cnt_8),32);
    bufp->chgIData(oldp+259,(vlSelfRef.cpu_perf_cnt_9),32);
    bufp->chgIData(oldp+260,(vlSelfRef.cpu_perf_cnt_10),32);
    bufp->chgIData(oldp+261,(vlSelfRef.cpu_perf_cnt_11),32);
    bufp->chgIData(oldp+262,(vlSelfRef.cpu_perf_cnt_12),32);
    bufp->chgIData(oldp+263,(vlSelfRef.cpu_perf_cnt_13),32);
    bufp->chgIData(oldp+264,(vlSelfRef.cpu_perf_cnt_14),32);
    bufp->chgIData(oldp+265,(vlSelfRef.cpu_perf_cnt_15),32);
    bufp->chgWData(oldp+266,(vlSelfRef.inst_retire),70);
    bufp->chgIData(oldp+269,(vlSelfRef.a0_out),32);
    bufp->chgCData(oldp+270,(vlSelfRef.custom_cpu__DOT__ID_EX__DOT__prediction_ex__DOT__predictor_next_state),5);
    bufp->chgCData(oldp+271,(vlSelfRef.custom_cpu__DOT__IF_EX__DOT__IF_next_state),5);
    bufp->chgCData(oldp+272,(vlSelfRef.custom_cpu__DOT__MEM_EX__DOT__MEM_next_state),5);
}

void Vcustom_cpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcustom_cpu___024root__trace_cleanup\n"); );
    // Body
    Vcustom_cpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcustom_cpu___024root*>(voidSelf);
    Vcustom_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
