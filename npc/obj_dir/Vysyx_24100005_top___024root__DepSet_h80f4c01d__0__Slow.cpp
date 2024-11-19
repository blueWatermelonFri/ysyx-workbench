// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24100005_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24100005_top__Syms.h"
#include "Vysyx_24100005_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100005_top___024root___dump_triggers__stl(Vysyx_24100005_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_triggers__stl(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_24100005_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vysyx_24100005_top___024unit____Vdpiimwrap_ebreak_TOP____024unit();

VL_ATTR_COLD void Vysyx_24100005_top___024root___stl_sequent__TOP__0(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    if ((0x73U == (0x7fU & vlSelf->inst))) {
        Vysyx_24100005_top___024unit____Vdpiimwrap_ebreak_TOP____024unit();
    }
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__pair_list[0U] 
        = (0x1fffff000ULL | (QData)((IData)((vlSelf->inst 
                                             >> 0x14U))));
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)((vlSelf->inst >> 0x14U)));
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__pair_list[0U] 
        = (0x1fff00000ULL | (QData)((IData)((vlSelf->inst 
                                             >> 0xcU))));
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)((vlSelf->inst >> 0xcU)));
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__pair_list[0U] 
        = (0x6700000000ULL | (QData)((IData)(((IData)(4U) 
                                              + vlSelf->PC))));
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__pair_list[1U] 
        = (0x6f00000000ULL | (QData)((IData)(((IData)(4U) 
                                              + vlSelf->PC))));
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[1U] 
        = (0x6f00000000ULL | (QData)((IData)(vlSelf->PC)));
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[2U] 
        = (0x1700000000ULL | (QData)((IData)(vlSelf->PC)));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[3U] 
        = (0x3700000000ULL | (QData)((IData)(((IData)(4U) 
                                              + vlSelf->PC))));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[4U] 
        = (0x2300000000ULL | (QData)((IData)(((IData)(4U) 
                                              + vlSelf->PC))));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[5U] 
        = (0x300000000ULL | (QData)((IData)(((IData)(4U) 
                                             + vlSelf->PC))));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[6U] 
        = (0x1300000000ULL | (QData)((IData)(((IData)(4U) 
                                              + vlSelf->PC))));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[7U] 
        = (0x3300000000ULL | (QData)((IData)(((IData)(4U) 
                                              + vlSelf->PC))));
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list[0U] 
        = ((IData)(4U) + vlSelf->PC);
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list[1U] 
        = ((IData)(4U) + vlSelf->PC);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[3U] 
        = ((IData)(4U) + vlSelf->PC);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[4U] 
        = ((IData)(4U) + vlSelf->PC);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[5U] 
        = ((IData)(4U) + vlSelf->PC);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[6U] 
        = ((IData)(4U) + vlSelf->PC);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[7U] 
        = ((IData)(4U) + vlSelf->PC);
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[1U] 
        = vlSelf->PC;
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[2U] 
        = vlSelf->PC;
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list[0U] 
        = (0xfffff000U | (vlSelf->inst >> 0x14U));
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list[1U] 
        = (vlSelf->inst >> 0x14U);
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list[0U] 
        = (0xfff00000U | (vlSelf->inst >> 0xcU));
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list[1U] 
        = (vlSelf->inst >> 0xcU);
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out 
        = (((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list
            [0U]) & vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit 
        = ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out) 
           | (((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list
               [1U]) & vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out) 
           | (((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list
               [2U]) & vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out) 
           | (((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list
               [3U]) & vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_24100005_top__DOT__wen = (1U & ((~ (IData)(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit)) 
                                                 | (IData)(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out)));
    vlSelf->__VdfgTmp_h18b30d0f__0 = ((0x100000U & 
                                       (vlSelf->inst 
                                        >> 0xbU)) | 
                                      ((0xff000U & vlSelf->inst) 
                                       | ((0x800U & 
                                           (vlSelf->inst 
                                            >> 9U)) 
                                          | (0x7feU 
                                             & (vlSelf->inst 
                                                >> 0x14U)))));
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__lut_out 
        = ((- (IData)(((vlSelf->inst >> 0x1fU) == vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__hit 
        = ((vlSelf->inst >> 0x1fU) == vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__lut_out 
           | ((- (IData)(((vlSelf->inst >> 0x1fU) == 
                          vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__hit) 
           | ((vlSelf->inst >> 0x1fU) == vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__immI = ((IData)(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__hit)
                                             ? vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__lut_out
                                             : 0U);
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__lut_out 
        = ((- (IData)(((vlSelf->inst >> 0x1fU) == vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__hit 
        = ((vlSelf->inst >> 0x1fU) == vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__lut_out 
           | ((- (IData)(((vlSelf->inst >> 0x1fU) == 
                          vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__hit) 
           | ((vlSelf->inst >> 0x1fU) == vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__immU = ((IData)(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__hit)
                                             ? vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__lut_out
                                             : 0U);
    if (vlSelf->ysyx_24100005_top__DOT__wen) {
        if ((0U == (0x1fU & (vlSelf->inst >> 0xfU)))) {
            vlSelf->ysyx_24100005_top__DOT__rdata = 0U;
            vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[0U] = 0U;
            vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[3U] = 0U;
        } else {
            vlSelf->ysyx_24100005_top__DOT__rdata = 
                vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf
                [(0x1fU & (vlSelf->inst >> 0xfU))];
            vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[0U] 
                = vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf
                [(0x1fU & (vlSelf->inst >> 0xfU))];
            vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[3U] 
                = vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf
                [(0x1fU & (vlSelf->inst >> 0xfU))];
        }
    } else {
        vlSelf->ysyx_24100005_top__DOT__rdata = 0U;
        vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[0U] = 0U;
        vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[3U] = 0U;
    }
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__pair_list[0U] 
        = (0x1ffe00000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h18b30d0f__0)));
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->__VdfgTmp_h18b30d0f__0));
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list[0U] 
        = (0xffe00000U | vlSelf->__VdfgTmp_h18b30d0f__0);
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list[1U] 
        = vlSelf->__VdfgTmp_h18b30d0f__0;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[0U] 
        = (0x6700000000ULL | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__immI)));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[4U] 
        = (0x1300000000ULL | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__immI)));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[0U] 
        = vlSelf->ysyx_24100005_top__DOT__immI;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[4U] 
        = vlSelf->ysyx_24100005_top__DOT__immI;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[2U] 
        = (0x3700000000ULL | (QData)((IData)((vlSelf->ysyx_24100005_top__DOT__immU 
                                              << 0xcU))));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[3U] 
        = (0x1700000000ULL | (QData)((IData)((vlSelf->ysyx_24100005_top__DOT__immU 
                                              << 0xcU))));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[2U] 
        = (vlSelf->ysyx_24100005_top__DOT__immU << 0xcU);
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[3U] 
        = (vlSelf->ysyx_24100005_top__DOT__immU << 0xcU);
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[0U] 
        = (0x6700000000ULL | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__rdata)));
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[3U] 
        = (0x1300000000ULL | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__rdata)));
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out 
        = ((- (IData)(((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit 
        = ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_24100005_top__DOT__add_input1 = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit)
                                                   ? vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out
                                                   : 0U);
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__lut_out 
        = ((- (IData)(((vlSelf->inst >> 0x1fU) == vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__hit 
        = ((vlSelf->inst >> 0x1fU) == vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__lut_out 
           | ((- (IData)(((vlSelf->inst >> 0x1fU) == 
                          vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__hit) 
           | ((vlSelf->inst >> 0x1fU) == vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__immJ = ((IData)(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__hit)
                                             ? vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__lut_out
                                             : 0U);
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[1U] 
        = (0x6f00000000ULL | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__immJ)));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[1U] 
        = vlSelf->ysyx_24100005_top__DOT__immJ;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out 
        = ((- (IData)(((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit 
        = ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
                          [4U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->ysyx_24100005_top__DOT__add_input2 = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit)
                                                   ? vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out
                                                   : 0U);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[0U] 
        = (vlSelf->ysyx_24100005_top__DOT__add_input1 
           + vlSelf->ysyx_24100005_top__DOT__add_input2);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[1U] 
        = (vlSelf->ysyx_24100005_top__DOT__add_input1 
           + vlSelf->ysyx_24100005_top__DOT__add_input2);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[2U] 
        = (vlSelf->ysyx_24100005_top__DOT__add_input1 
           + vlSelf->ysyx_24100005_top__DOT__add_input2);
    vlSelf->ysyx_24100005_top__DOT__add_output = (vlSelf->ysyx_24100005_top__DOT__add_input1 
                                                  + vlSelf->ysyx_24100005_top__DOT__add_input2);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
        = ((- (IData)(((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit 
        = ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
                          [4U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
                          [5U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list
              [5U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
              [5U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
                          [6U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list
              [6U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
              [6U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
                          [7U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list
              [7U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list
              [7U]));
    vlSelf->ysyx_24100005_top__DOT__DPC = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit)
                                            ? vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out
                                            : ((IData)(4U) 
                                               + vlSelf->PC));
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__lut_out 
        = ((- (IData)(((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__hit 
        = ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_24100005_top__DOT__wdata = ((IData)(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__hit)
                                              ? vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__lut_out
                                              : vlSelf->ysyx_24100005_top__DOT__add_output);
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[0U] 
        = (0x6700000000ULL | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__add_output)));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[1U] 
        = (0x6f00000000ULL | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__add_output)));
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[2U] 
        = (0x6300000000ULL | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__add_output)));
}
