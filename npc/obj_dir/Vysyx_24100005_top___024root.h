// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24100005_top.h for the primary calling header

#ifndef VERILATED_VYSYX_24100005_TOP___024ROOT_H_
#define VERILATED_VYSYX_24100005_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_24100005_top__Syms;
class Vysyx_24100005_top___024unit;


class Vysyx_24100005_top___024root final : public VerilatedModule {
  public:
    // CELLS
    Vysyx_24100005_top___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ ysyx_24100005_top__DOT__wen;
    CData/*0:0*/ ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__hit;
    CData/*0:0*/ ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__hit;
    CData/*0:0*/ ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__hit;
    CData/*0:0*/ ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit;
    CData/*0:0*/ ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit;
    CData/*0:0*/ ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out;
    CData/*0:0*/ ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit;
    CData/*0:0*/ ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit;
    CData/*0:0*/ ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__hit;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    SData/*11:0*/ ysyx_24100005_top__DOT__imm;
    VL_IN(inst,31,0);
    VL_OUT(PC,31,0);
    IData/*31:0*/ ysyx_24100005_top__DOT__DPC;
    IData/*31:0*/ ysyx_24100005_top__DOT__wdata;
    IData/*31:0*/ ysyx_24100005_top__DOT__rdata;
    IData/*31:0*/ ysyx_24100005_top__DOT__immI;
    IData/*31:0*/ ysyx_24100005_top__DOT__immJ;
    IData/*31:0*/ ysyx_24100005_top__DOT__immU;
    IData/*31:0*/ ysyx_24100005_top__DOT__add_output;
    IData/*31:0*/ ysyx_24100005_top__DOT__add_input1;
    IData/*31:0*/ ysyx_24100005_top__DOT__add_input2;
    IData/*31:0*/ ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__lut_out;
    IData/*31:0*/ ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__lut_out;
    IData/*31:0*/ ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__lut_out;
    IData/*31:0*/ ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out;
    IData/*31:0*/ ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out;
    IData/*31:0*/ ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out;
    IData/*31:0*/ ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__lut_out;
    IData/*20:0*/ __VdfgTmp_h18b30d0f__0;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> ysyx_24100005_top__DOT__RegFile__DOT__rf;
    VlUnpacked<QData/*32:0*/, 2> ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*0:0*/, 2> ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 2> ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*32:0*/, 2> ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*0:0*/, 2> ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 2> ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*32:0*/, 2> ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*0:0*/, 2> ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 2> ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*38:0*/, 5> ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*6:0*/, 5> ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 5> ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*38:0*/, 4> ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*6:0*/, 4> ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 4> ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list;
    VlUnpacked<CData/*7:0*/, 4> ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*6:0*/, 4> ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*0:0*/, 4> ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*38:0*/, 8> ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*6:0*/, 8> ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 8> ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*38:0*/, 2> ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*6:0*/, 2> ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 2> ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_24100005_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_24100005_top___024root(Vysyx_24100005_top__Syms* symsp, const char* v__name);
    ~Vysyx_24100005_top___024root();
    VL_UNCOPYABLE(Vysyx_24100005_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
