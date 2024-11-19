// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_24100005_top__Syms.h"


void Vysyx_24100005_top___024root__trace_chg_sub_0(Vysyx_24100005_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_24100005_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_24100005_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24100005_top___024root*>(voidSelf);
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_24100005_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_24100005_top___024root__trace_chg_sub_0(Vysyx_24100005_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<7>/*223:0*/ __Vtemp_h7720efe0__0;
    VlWide<3>/*95:0*/ __Vtemp_hb9f4ce29__0;
    VlWide<3>/*95:0*/ __Vtemp_he5cfe13e__0;
    VlWide<10>/*319:0*/ __Vtemp_heaa31b35__0;
    VlWide<5>/*159:0*/ __Vtemp_h523b24e8__0;
    VlWide<3>/*95:0*/ __Vtemp_h0610dcb6__0;
    VlWide<3>/*95:0*/ __Vtemp_h88d4fbec__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+1,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+2,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+3,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list[1]));
        bufp->chgCData(oldp+4,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+5,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+6,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+7,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[3]),7);
        bufp->chgCData(oldp+8,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[4]),7);
        bufp->chgCData(oldp+9,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[5]),7);
        bufp->chgCData(oldp+10,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[6]),7);
        bufp->chgCData(oldp+11,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[7]),7);
        bufp->chgCData(oldp+12,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+13,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+14,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+15,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[3]),7);
        bufp->chgCData(oldp+16,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+17,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+18,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+19,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[3]),7);
        bufp->chgCData(oldp+20,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[4]),7);
        bufp->chgCData(oldp+21,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[0]),8);
        bufp->chgCData(oldp+22,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[1]),8);
        bufp->chgCData(oldp+23,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[2]),8);
        bufp->chgCData(oldp+24,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[3]),8);
        bufp->chgCData(oldp+25,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+26,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+27,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+28,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[3]),7);
        bufp->chgBit(oldp+29,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+30,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[1]));
        bufp->chgBit(oldp+31,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[2]));
        bufp->chgBit(oldp+32,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[3]));
        bufp->chgCData(oldp+33,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+34,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list[1]),7);
        bufp->chgBit(oldp+35,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+36,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list[1]));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+37,(vlSelf->ysyx_24100005_top__DOT__wen));
        bufp->chgIData(oldp+38,(vlSelf->ysyx_24100005_top__DOT__immI),32);
        bufp->chgIData(oldp+39,(vlSelf->ysyx_24100005_top__DOT__immJ),32);
        bufp->chgIData(oldp+40,(vlSelf->ysyx_24100005_top__DOT__immU),32);
        bufp->chgIData(oldp+41,((vlSelf->ysyx_24100005_top__DOT__immU 
                                 << 0xcU)),32);
        bufp->chgIData(oldp+42,(vlSelf->ysyx_24100005_top__DOT__add_input2),32);
        bufp->chgQData(oldp+43,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+45,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+47,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+48,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+49,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+50,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__hit));
        bufp->chgQData(oldp+51,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+53,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+55,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+56,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+57,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+58,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__hit));
        __Vtemp_h7720efe0__0[0U] = (IData)((0x6700000000ULL 
                                            | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__immI))));
        __Vtemp_h7720efe0__0[1U] = ((vlSelf->ysyx_24100005_top__DOT__immJ 
                                     << 7U) | (IData)(
                                                      ((0x6700000000ULL 
                                                        | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__immI))) 
                                                       >> 0x20U)));
        __Vtemp_h7720efe0__0[2U] = (0x3780U | ((0xffffc000U 
                                                & (vlSelf->ysyx_24100005_top__DOT__immU 
                                                   << 0x1aU)) 
                                               | (vlSelf->ysyx_24100005_top__DOT__immJ 
                                                  >> 0x19U)));
        __Vtemp_h7720efe0__0[3U] = (0xdc000U | (0x3fffU 
                                                & (vlSelf->ysyx_24100005_top__DOT__immU 
                                                   >> 6U)));
        __Vtemp_h7720efe0__0[4U] = (0x2e00000U | ((vlSelf->ysyx_24100005_top__DOT__immI 
                                                   << 0x1cU) 
                                                  | (0x1ffffeU 
                                                     & (vlSelf->ysyx_24100005_top__DOT__immU 
                                                        << 1U))));
        __Vtemp_h7720efe0__0[5U] = (0x30000000U | (vlSelf->ysyx_24100005_top__DOT__immI 
                                                   >> 4U));
        __Vtemp_h7720efe0__0[6U] = 1U;
        bufp->chgWData(oldp+59,(__Vtemp_h7720efe0__0),195);
        bufp->chgQData(oldp+66,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[0]),39);
        bufp->chgQData(oldp+68,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[1]),39);
        bufp->chgQData(oldp+70,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[2]),39);
        bufp->chgQData(oldp+72,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[3]),39);
        bufp->chgQData(oldp+74,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[4]),39);
        bufp->chgIData(oldp+76,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+77,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+78,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+79,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+80,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[4]),32);
        bufp->chgIData(oldp+81,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+82,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+83,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out));
        bufp->chgBit(oldp+84,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit));
        bufp->chgQData(oldp+85,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+87,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+89,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+90,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+91,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+92,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+93,(vlSelf->ysyx_24100005_top__DOT__DPC),32);
        bufp->chgIData(oldp+94,(vlSelf->ysyx_24100005_top__DOT__wdata),32);
        bufp->chgIData(oldp+95,(vlSelf->ysyx_24100005_top__DOT__rdata),32);
        bufp->chgIData(oldp+96,(vlSelf->ysyx_24100005_top__DOT__add_output),32);
        bufp->chgIData(oldp+97,(vlSelf->ysyx_24100005_top__DOT__add_input1),32);
        bufp->chgQData(oldp+98,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[0]),39);
        bufp->chgQData(oldp+100,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[1]),39);
        bufp->chgQData(oldp+102,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[2]),39);
        bufp->chgQData(oldp+104,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[3]),39);
        bufp->chgQData(oldp+106,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[4]),39);
        bufp->chgQData(oldp+108,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[5]),39);
        bufp->chgQData(oldp+110,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[6]),39);
        bufp->chgQData(oldp+112,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[7]),39);
        bufp->chgIData(oldp+114,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+115,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+116,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+117,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+118,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[4]),32);
        bufp->chgIData(oldp+119,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[5]),32);
        bufp->chgIData(oldp+120,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[6]),32);
        bufp->chgIData(oldp+121,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[7]),32);
        bufp->chgIData(oldp+122,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+123,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit));
        bufp->chgQData(oldp+124,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[0]),39);
        bufp->chgQData(oldp+126,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[1]),39);
        bufp->chgQData(oldp+128,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[2]),39);
        bufp->chgQData(oldp+130,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[3]),39);
        bufp->chgIData(oldp+132,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+133,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+134,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+135,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+136,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+137,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+138,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+139,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgQData(oldp+140,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__pair_list[0]),39);
        bufp->chgQData(oldp+142,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__pair_list[1]),39);
        bufp->chgIData(oldp+144,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+145,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+146,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[0]),32);
        bufp->chgIData(oldp+147,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[1]),32);
        bufp->chgIData(oldp+148,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[2]),32);
        bufp->chgIData(oldp+149,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[3]),32);
        bufp->chgIData(oldp+150,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[4]),32);
        bufp->chgIData(oldp+151,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[5]),32);
        bufp->chgIData(oldp+152,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[6]),32);
        bufp->chgIData(oldp+153,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[7]),32);
        bufp->chgIData(oldp+154,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[8]),32);
        bufp->chgIData(oldp+155,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[9]),32);
        bufp->chgIData(oldp+156,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[10]),32);
        bufp->chgIData(oldp+157,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[11]),32);
        bufp->chgIData(oldp+158,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[12]),32);
        bufp->chgIData(oldp+159,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[13]),32);
        bufp->chgIData(oldp+160,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[14]),32);
        bufp->chgIData(oldp+161,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[15]),32);
        bufp->chgIData(oldp+162,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[16]),32);
        bufp->chgIData(oldp+163,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[17]),32);
        bufp->chgIData(oldp+164,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[18]),32);
        bufp->chgIData(oldp+165,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[19]),32);
        bufp->chgIData(oldp+166,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[20]),32);
        bufp->chgIData(oldp+167,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[21]),32);
        bufp->chgIData(oldp+168,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[22]),32);
        bufp->chgIData(oldp+169,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[23]),32);
        bufp->chgIData(oldp+170,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[24]),32);
        bufp->chgIData(oldp+171,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[25]),32);
        bufp->chgIData(oldp+172,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[26]),32);
        bufp->chgIData(oldp+173,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[27]),32);
        bufp->chgIData(oldp+174,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[28]),32);
        bufp->chgIData(oldp+175,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[29]),32);
        bufp->chgIData(oldp+176,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[30]),32);
        bufp->chgIData(oldp+177,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[31]),32);
    }
    bufp->chgIData(oldp+178,(vlSelf->inst),32);
    bufp->chgBit(oldp+179,(vlSelf->rst));
    bufp->chgBit(oldp+180,(vlSelf->clk));
    bufp->chgIData(oldp+181,(vlSelf->PC),32);
    bufp->chgIData(oldp+182,(((IData)(4U) + vlSelf->PC)),32);
    bufp->chgCData(oldp+183,((0x7fU & vlSelf->inst)),7);
    bufp->chgCData(oldp+184,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->chgCData(oldp+185,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->chgCData(oldp+186,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->chgBit(oldp+187,((vlSelf->inst >> 0x1fU)));
    __Vtemp_hb9f4ce29__0[0U] = (IData)((0x1fffff000ULL 
                                        | (((QData)((IData)(
                                                            (vlSelf->inst 
                                                             >> 0x14U))) 
                                            << 0x21U) 
                                           | (QData)((IData)(
                                                             (vlSelf->inst 
                                                              >> 0x14U))))));
    __Vtemp_hb9f4ce29__0[1U] = (IData)(((0x1fffff000ULL 
                                         | (((QData)((IData)(
                                                             (vlSelf->inst 
                                                              >> 0x14U))) 
                                             << 0x21U) 
                                            | (QData)((IData)(
                                                              (vlSelf->inst 
                                                               >> 0x14U))))) 
                                        >> 0x20U));
    __Vtemp_hb9f4ce29__0[2U] = 0U;
    bufp->chgWData(oldp+188,(__Vtemp_hb9f4ce29__0),66);
    __Vtemp_he5cfe13e__0[0U] = (IData)((((QData)((IData)(
                                                         (vlSelf->inst 
                                                          >> 0x1fU))) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            (0xfffU 
                                                             | ((0xff000000U 
                                                                 & (vlSelf->inst 
                                                                    << 0xcU)) 
                                                                | ((0x800000U 
                                                                    & (vlSelf->inst 
                                                                       << 3U)) 
                                                                   | (0x7fe000U 
                                                                      & (vlSelf->inst 
                                                                         >> 8U))))))) 
                                            << 0x15U) 
                                           | (QData)((IData)(vlSelf->__VdfgTmp_h18b30d0f__0)))));
    __Vtemp_he5cfe13e__0[1U] = (IData)(((((QData)((IData)(
                                                          (vlSelf->inst 
                                                           >> 0x1fU))) 
                                          << 0x35U) 
                                         | (((QData)((IData)(
                                                             (0xfffU 
                                                              | ((0xff000000U 
                                                                  & (vlSelf->inst 
                                                                     << 0xcU)) 
                                                                 | ((0x800000U 
                                                                     & (vlSelf->inst 
                                                                        << 3U)) 
                                                                    | (0x7fe000U 
                                                                       & (vlSelf->inst 
                                                                          >> 8U))))))) 
                                             << 0x15U) 
                                            | (QData)((IData)(vlSelf->__VdfgTmp_h18b30d0f__0)))) 
                                        >> 0x20U));
    __Vtemp_he5cfe13e__0[2U] = 0U;
    bufp->chgWData(oldp+191,(__Vtemp_he5cfe13e__0),66);
    __Vtemp_heaa31b35__0[0U] = (IData)((0x6700000000ULL 
                                        | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__add_output))));
    __Vtemp_heaa31b35__0[1U] = ((vlSelf->ysyx_24100005_top__DOT__add_output 
                                 << 7U) | (IData)((
                                                   (0x6700000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__add_output))) 
                                                   >> 0x20U)));
    __Vtemp_heaa31b35__0[2U] = (0x3780U | ((vlSelf->ysyx_24100005_top__DOT__add_output 
                                            << 0xeU) 
                                           | (vlSelf->ysyx_24100005_top__DOT__add_output 
                                              >> 0x19U)));
    __Vtemp_heaa31b35__0[3U] = (0x18c000U | ((((IData)(4U) 
                                               + vlSelf->PC) 
                                              << 0x15U) 
                                             | (vlSelf->ysyx_24100005_top__DOT__add_output 
                                                >> 0x12U)));
    __Vtemp_heaa31b35__0[4U] = (0x6e00000U | ((((IData)(4U) 
                                                + vlSelf->PC) 
                                               << 0x1cU) 
                                              | (((IData)(4U) 
                                                  + vlSelf->PC) 
                                                 >> 0xbU)));
    __Vtemp_heaa31b35__0[5U] = (0x30000000U | (((IData)(4U) 
                                                + vlSelf->PC) 
                                               >> 4U));
    __Vtemp_heaa31b35__0[6U] = (2U | (((IData)(4U) 
                                       + vlSelf->PC) 
                                      << 3U));
    __Vtemp_heaa31b35__0[7U] = (0x18U | ((((IData)(4U) 
                                           + vlSelf->PC) 
                                          << 0xaU) 
                                         | (((IData)(4U) 
                                             + vlSelf->PC) 
                                            >> 0x1dU)));
    __Vtemp_heaa31b35__0[8U] = (0x4c00U | ((((IData)(4U) 
                                             + vlSelf->PC) 
                                            << 0x11U) 
                                           | (((IData)(4U) 
                                               + vlSelf->PC) 
                                              >> 0x16U)));
    __Vtemp_heaa31b35__0[9U] = (0x660000U | (((IData)(4U) 
                                              + vlSelf->PC) 
                                             >> 0xfU));
    bufp->chgWData(oldp+194,(__Vtemp_heaa31b35__0),312);
    __Vtemp_h523b24e8__0[0U] = (IData)((0x6700000000ULL 
                                        | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__rdata))));
    __Vtemp_h523b24e8__0[1U] = ((vlSelf->PC << 7U) 
                                | (IData)(((0x6700000000ULL 
                                            | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__rdata))) 
                                           >> 0x20U)));
    __Vtemp_h523b24e8__0[2U] = (0x3780U | ((vlSelf->PC 
                                            << 0xeU) 
                                           | (vlSelf->PC 
                                              >> 0x19U)));
    __Vtemp_h523b24e8__0[3U] = (0x5c000U | ((vlSelf->ysyx_24100005_top__DOT__rdata 
                                             << 0x15U) 
                                            | (vlSelf->PC 
                                               >> 0x12U)));
    __Vtemp_h523b24e8__0[4U] = (0x2600000U | (vlSelf->ysyx_24100005_top__DOT__rdata 
                                              >> 0xbU));
    bufp->chgWData(oldp+204,(__Vtemp_h523b24e8__0),156);
    __Vtemp_h0610dcb6__0[0U] = (IData)((0x6700000000ULL 
                                        | (QData)((IData)(
                                                          ((IData)(4U) 
                                                           + vlSelf->PC)))));
    __Vtemp_h0610dcb6__0[1U] = ((((IData)(4U) + vlSelf->PC) 
                                 << 7U) | (IData)((
                                                   (0x6700000000ULL 
                                                    | (QData)((IData)(
                                                                      ((IData)(4U) 
                                                                       + vlSelf->PC)))) 
                                                   >> 0x20U)));
    __Vtemp_h0610dcb6__0[2U] = (0x3780U | (((IData)(4U) 
                                            + vlSelf->PC) 
                                           >> 0x19U));
    bufp->chgWData(oldp+209,(__Vtemp_h0610dcb6__0),78);
    __Vtemp_h88d4fbec__0[0U] = (IData)((0x1fff00000ULL 
                                        | (((QData)((IData)(
                                                            (vlSelf->inst 
                                                             >> 0xcU))) 
                                            << 0x21U) 
                                           | (QData)((IData)(
                                                             (vlSelf->inst 
                                                              >> 0xcU))))));
    __Vtemp_h88d4fbec__0[1U] = (IData)(((0x1fff00000ULL 
                                         | (((QData)((IData)(
                                                             (vlSelf->inst 
                                                              >> 0xcU))) 
                                             << 0x21U) 
                                            | (QData)((IData)(
                                                              (vlSelf->inst 
                                                               >> 0xcU))))) 
                                        >> 0x20U));
    __Vtemp_h88d4fbec__0[2U] = 0U;
    bufp->chgWData(oldp+212,(__Vtemp_h88d4fbec__0),66);
}

void Vysyx_24100005_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root__trace_cleanup\n"); );
    // Init
    Vysyx_24100005_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24100005_top___024root*>(voidSelf);
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
