// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24100005_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24100005_top___024root.h"

VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_static(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_initial__TOP(Vysyx_24100005_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_initial(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___eval_initial\n"); );
    // Body
    Vysyx_24100005_top___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_initial__TOP(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[0U] = 0x67U;
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[1U] = 0x6fU;
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[2U] = 0x17U;
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[3U] = 0x13U;
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[0U] = 0x67U;
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[1U] = 0x6fU;
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[2U] = 0x63U;
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[3U] = 0x37U;
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[4U] = 0x23U;
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[5U] = 3U;
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[6U] = 0x13U;
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[7U] = 0x33U;
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list[0U] = 0x67U;
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list[1U] = 0x6fU;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[0U] = 0x67U;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[1U] = 0x6fU;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[2U] = 0x37U;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[3U] = 0x17U;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[4U] = 0x13U;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[0U] = 0x67U;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[1U] = 0x6fU;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[2U] = 0x23U;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[3U] = 0x63U;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[0U] = 1U;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[1U] = 1U;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[2U] = 0U;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[3U] = 0U;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[0U] = 0xcfU;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[1U] = 0xdfU;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[2U] = 0x46U;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[3U] = 0xc6U;
}

VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_final(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_triggers__stl(Vysyx_24100005_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100005_top___024root___dump_triggers__stl(Vysyx_24100005_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_stl(Vysyx_24100005_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_settle(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vysyx_24100005_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vysyx_24100005_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/myuser/ysyx/ysyx-workbench/npc/vsrc/top.v", 2, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vysyx_24100005_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100005_top___024root___dump_triggers__stl(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_24100005_top___024root___stl_sequent__TOP__0(Vysyx_24100005_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24100005_top___024root___eval_stl(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_24100005_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100005_top___024root___dump_triggers__ico(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100005_top___024root___dump_triggers__act(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100005_top___024root___dump_triggers__nba(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_24100005_top___024root___ctor_var_reset(Vysyx_24100005_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->inst = 0;
    vlSelf->rst = 0;
    vlSelf->clk = 0;
    vlSelf->PC = 0;
    vlSelf->ysyx_24100005_top__DOT__DPC = 0;
    vlSelf->ysyx_24100005_top__DOT__wen = 0;
    vlSelf->ysyx_24100005_top__DOT__wdata = 0;
    vlSelf->ysyx_24100005_top__DOT__rdata = 0;
    vlSelf->ysyx_24100005_top__DOT__imm = 0;
    vlSelf->ysyx_24100005_top__DOT__immI = 0;
    vlSelf->ysyx_24100005_top__DOT__immJ = 0;
    vlSelf->ysyx_24100005_top__DOT__immU = 0;
    vlSelf->ysyx_24100005_top__DOT__add_output = 0;
    vlSelf->ysyx_24100005_top__DOT__add_input1 = 0;
    vlSelf->ysyx_24100005_top__DOT__add_input2 = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__pair_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__lut_out = 0;
    vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__hit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__pair_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__lut_out = 0;
    vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__hit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__pair_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__lut_out = 0;
    vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__hit = 0;
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out = 0;
    vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out = 0;
    vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out = 0;
    vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out = 0;
    vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__pair_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__lut_out = 0;
    vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__hit = 0;
    vlSelf->__VdfgTmp_h18b30d0f__0 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
