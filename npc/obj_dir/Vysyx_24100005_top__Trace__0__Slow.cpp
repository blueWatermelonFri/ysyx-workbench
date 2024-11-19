// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_24100005_top__Syms.h"


VL_ATTR_COLD void Vysyx_24100005_top___024root__trace_init_sub__TOP__0(Vysyx_24100005_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+179,"inst", false,-1, 31,0);
    tracep->declBit(c+180,"rst", false,-1);
    tracep->declBit(c+181,"clk", false,-1);
    tracep->declBus(c+182,"PC", false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_24100005_top ");
    tracep->declBus(c+179,"inst", false,-1, 31,0);
    tracep->declBit(c+180,"rst", false,-1);
    tracep->declBit(c+181,"clk", false,-1);
    tracep->declBus(c+182,"PC", false,-1, 31,0);
    tracep->declBus(c+183,"SPC", false,-1, 31,0);
    tracep->declBus(c+94,"DPC", false,-1, 31,0);
    tracep->declBit(c+38,"wen", false,-1);
    tracep->declBus(c+95,"wdata", false,-1, 31,0);
    tracep->declBus(c+96,"rdata", false,-1, 31,0);
    tracep->declBus(c+184,"opcode", false,-1, 6,0);
    tracep->declBus(c+185,"funct3", false,-1, 2,0);
    tracep->declBus(c+186,"rs1", false,-1, 4,0);
    tracep->declBus(c+216,"imm", false,-1, 11,0);
    tracep->declBus(c+187,"rd", false,-1, 4,0);
    tracep->declBus(c+39,"immI", false,-1, 31,0);
    tracep->declBus(c+40,"immJ", false,-1, 31,0);
    tracep->declBus(c+41,"immU", false,-1, 31,0);
    tracep->declBus(c+42,"shiftimmU", false,-1, 31,0);
    tracep->declBus(c+97,"add_output", false,-1, 31,0);
    tracep->declBus(c+98,"add_input1", false,-1, 31,0);
    tracep->declBus(c+43,"add_input2", false,-1, 31,0);
    tracep->pushNamePrefix("Iimm_SEXT ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+39,"out", false,-1, 31,0);
    tracep->declBus(c+188,"key", false,-1, 0,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+189,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+39,"out", false,-1, 31,0);
    tracep->declBus(c+188,"key", false,-1, 0,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+189,"lut", false,-1, 65,0);
    tracep->declBus(c+221,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+44+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+48+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+50,"lut_out", false,-1, 31,0);
    tracep->declBit(c+51,"hit", false,-1);
    tracep->declBus(c+222,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Jimm_SEXT ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+40,"out", false,-1, 31,0);
    tracep->declBus(c+188,"key", false,-1, 0,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+192,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+40,"out", false,-1, 31,0);
    tracep->declBus(c+188,"key", false,-1, 0,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+192,"lut", false,-1, 65,0);
    tracep->declBus(c+221,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+52+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+3+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+56+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+58,"lut_out", false,-1, 31,0);
    tracep->declBit(c+59,"hit", false,-1);
    tracep->declBus(c+222,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Mux_PC ");
    tracep->declBus(c+223,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+94,"out", false,-1, 31,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+195,"lut", false,-1, 311,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+223,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+94,"out", false,-1, 31,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+195,"lut", false,-1, 311,0);
    tracep->declBus(c+225,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 8; ++i) {
        tracep->declQuad(c+99+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+5+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+115+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+123,"lut_out", false,-1, 31,0);
    tracep->declBit(c+124,"hit", false,-1);
    tracep->declBus(c+226,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Mux_input1 ");
    tracep->declBus(c+227,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+98,"out", false,-1, 31,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+205,"lut", false,-1, 155,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+227,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+98,"out", false,-1, 31,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+205,"lut", false,-1, 155,0);
    tracep->declBus(c+225,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+125+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+13+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+133+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+137,"lut_out", false,-1, 31,0);
    tracep->declBit(c+138,"hit", false,-1);
    tracep->declBus(c+228,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Mux_input2 ");
    tracep->declBus(c+229,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+43,"out", false,-1, 31,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+60,"lut", false,-1, 194,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+229,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+43,"out", false,-1, 31,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+60,"lut", false,-1, 194,0);
    tracep->declBus(c+225,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 5; ++i) {
        tracep->declQuad(c+67+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+17+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+77+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+82,"lut_out", false,-1, 31,0);
    tracep->declBit(c+83,"hit", false,-1);
    tracep->declBus(c+230,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Mux_iswrite ");
    tracep->declBus(c+227,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+38,"out", false,-1, 0,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+231,"default_out", false,-1, 0,0);
    tracep->declBus(c+232,"lut", false,-1, 31,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+227,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+38,"out", false,-1, 0,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+231,"default_out", false,-1, 0,0);
    tracep->declBus(c+232,"lut", false,-1, 31,0);
    tracep->declBus(c+223,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+22+i*1,"pair_list", true,(i+0), 7,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+26+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+30+i*1,"data_list", true,(i+0), 0,0);
    }
    tracep->declBus(c+84,"lut_out", false,-1, 0,0);
    tracep->declBit(c+85,"hit", false,-1);
    tracep->declBus(c+228,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Mux_writedata ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+95,"out", false,-1, 31,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+97,"default_out", false,-1, 31,0);
    tracep->declArray(c+210,"lut", false,-1, 77,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+224,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+95,"out", false,-1, 31,0);
    tracep->declBus(c+184,"key", false,-1, 6,0);
    tracep->declBus(c+97,"default_out", false,-1, 31,0);
    tracep->declArray(c+210,"lut", false,-1, 77,0);
    tracep->declBus(c+225,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+141+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+34+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+145+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+139,"lut_out", false,-1, 31,0);
    tracep->declBit(c+140,"hit", false,-1);
    tracep->declBus(c+222,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("RegFile ");
    tracep->declBus(c+229,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+181,"clk", false,-1);
    tracep->declBit(c+38,"wen", false,-1);
    tracep->declBus(c+95,"wdata", false,-1, 31,0);
    tracep->declBus(c+187,"waddr", false,-1, 4,0);
    tracep->declBus(c+186,"raddr", false,-1, 4,0);
    tracep->declBus(c+96,"rdata", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+147+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("Uimm_SEXT ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+41,"out", false,-1, 31,0);
    tracep->declBus(c+188,"key", false,-1, 0,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+213,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+41,"out", false,-1, 31,0);
    tracep->declBus(c+188,"key", false,-1, 0,0);
    tracep->declBus(c+220,"default_out", false,-1, 31,0);
    tracep->declArray(c+213,"lut", false,-1, 65,0);
    tracep->declBus(c+221,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+86+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+36+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+90+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+92,"lut_out", false,-1, 31,0);
    tracep->declBit(c+93,"hit", false,-1);
    tracep->declBus(c+222,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+219,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+233,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+181,"clk", false,-1);
    tracep->declBit(c+180,"rst", false,-1);
    tracep->declBus(c+94,"din", false,-1, 31,0);
    tracep->declBus(c+182,"dout", false,-1, 31,0);
    tracep->declBit(c+231,"wen", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vysyx_24100005_top___024root__trace_init_top(Vysyx_24100005_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root__trace_init_top\n"); );
    // Body
    Vysyx_24100005_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_24100005_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_24100005_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_24100005_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_24100005_top___024root__trace_register(Vysyx_24100005_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_24100005_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_24100005_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_24100005_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_24100005_top___024root__trace_full_sub_0(Vysyx_24100005_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_24100005_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_24100005_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24100005_top___024root*>(voidSelf);
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_24100005_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_24100005_top___024root__trace_full_sub_0(Vysyx_24100005_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100005_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100005_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<7>/*223:0*/ __Vtemp_h7720efe0__0;
    VlWide<3>/*95:0*/ __Vtemp_hb9f4ce29__0;
    VlWide<3>/*95:0*/ __Vtemp_he5cfe13e__0;
    VlWide<10>/*319:0*/ __Vtemp_heaa31b35__0;
    VlWide<5>/*159:0*/ __Vtemp_h523b24e8__0;
    VlWide<3>/*95:0*/ __Vtemp_h0610dcb6__0;
    VlWide<3>/*95:0*/ __Vtemp_h88d4fbec__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+3,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+4,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__key_list[1]));
    bufp->fullCData(oldp+5,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+6,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[1]),7);
    bufp->fullCData(oldp+7,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[2]),7);
    bufp->fullCData(oldp+8,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[3]),7);
    bufp->fullCData(oldp+9,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[4]),7);
    bufp->fullCData(oldp+10,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[5]),7);
    bufp->fullCData(oldp+11,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[6]),7);
    bufp->fullCData(oldp+12,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__key_list[7]),7);
    bufp->fullCData(oldp+13,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+14,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[1]),7);
    bufp->fullCData(oldp+15,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[2]),7);
    bufp->fullCData(oldp+16,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__key_list[3]),7);
    bufp->fullCData(oldp+17,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+18,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[1]),7);
    bufp->fullCData(oldp+19,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[2]),7);
    bufp->fullCData(oldp+20,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[3]),7);
    bufp->fullCData(oldp+21,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__key_list[4]),7);
    bufp->fullCData(oldp+22,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[0]),8);
    bufp->fullCData(oldp+23,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[1]),8);
    bufp->fullCData(oldp+24,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[2]),8);
    bufp->fullCData(oldp+25,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__pair_list[3]),8);
    bufp->fullCData(oldp+26,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+27,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[1]),7);
    bufp->fullCData(oldp+28,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[2]),7);
    bufp->fullCData(oldp+29,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__key_list[3]),7);
    bufp->fullBit(oldp+30,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[0]));
    bufp->fullBit(oldp+31,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[1]));
    bufp->fullBit(oldp+32,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[2]));
    bufp->fullBit(oldp+33,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__data_list[3]));
    bufp->fullCData(oldp+34,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+35,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__key_list[1]),7);
    bufp->fullBit(oldp+36,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+37,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+38,(vlSelf->ysyx_24100005_top__DOT__wen));
    bufp->fullIData(oldp+39,(vlSelf->ysyx_24100005_top__DOT__immI),32);
    bufp->fullIData(oldp+40,(vlSelf->ysyx_24100005_top__DOT__immJ),32);
    bufp->fullIData(oldp+41,(vlSelf->ysyx_24100005_top__DOT__immU),32);
    bufp->fullIData(oldp+42,((vlSelf->ysyx_24100005_top__DOT__immU 
                              << 0xcU)),32);
    bufp->fullIData(oldp+43,(vlSelf->ysyx_24100005_top__DOT__add_input2),32);
    bufp->fullQData(oldp+44,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+46,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+48,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+49,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+50,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+51,(vlSelf->ysyx_24100005_top__DOT__Iimm_SEXT__DOT__i0__DOT__hit));
    bufp->fullQData(oldp+52,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+54,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+56,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+57,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+58,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+59,(vlSelf->ysyx_24100005_top__DOT__Jimm_SEXT__DOT__i0__DOT__hit));
    __Vtemp_h7720efe0__0[0U] = (IData)((0x6700000000ULL 
                                        | (QData)((IData)(vlSelf->ysyx_24100005_top__DOT__immI))));
    __Vtemp_h7720efe0__0[1U] = ((vlSelf->ysyx_24100005_top__DOT__immJ 
                                 << 7U) | (IData)((
                                                   (0x6700000000ULL 
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
    bufp->fullWData(oldp+60,(__Vtemp_h7720efe0__0),195);
    bufp->fullQData(oldp+67,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+69,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullQData(oldp+71,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[2]),39);
    bufp->fullQData(oldp+73,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[3]),39);
    bufp->fullQData(oldp+75,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__pair_list[4]),39);
    bufp->fullIData(oldp+77,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+78,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+79,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+80,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+81,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__data_list[4]),32);
    bufp->fullIData(oldp+82,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+83,(vlSelf->ysyx_24100005_top__DOT__Mux_input2__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+84,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__lut_out));
    bufp->fullBit(oldp+85,(vlSelf->ysyx_24100005_top__DOT__Mux_iswrite__DOT__i0__DOT__hit));
    bufp->fullQData(oldp+86,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+88,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+90,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+91,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+92,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+93,(vlSelf->ysyx_24100005_top__DOT__Uimm_SEXT__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+94,(vlSelf->ysyx_24100005_top__DOT__DPC),32);
    bufp->fullIData(oldp+95,(vlSelf->ysyx_24100005_top__DOT__wdata),32);
    bufp->fullIData(oldp+96,(vlSelf->ysyx_24100005_top__DOT__rdata),32);
    bufp->fullIData(oldp+97,(vlSelf->ysyx_24100005_top__DOT__add_output),32);
    bufp->fullIData(oldp+98,(vlSelf->ysyx_24100005_top__DOT__add_input1),32);
    bufp->fullQData(oldp+99,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+101,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullQData(oldp+103,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[2]),39);
    bufp->fullQData(oldp+105,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[3]),39);
    bufp->fullQData(oldp+107,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[4]),39);
    bufp->fullQData(oldp+109,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[5]),39);
    bufp->fullQData(oldp+111,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[6]),39);
    bufp->fullQData(oldp+113,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__pair_list[7]),39);
    bufp->fullIData(oldp+115,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+116,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+117,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+118,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+119,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[4]),32);
    bufp->fullIData(oldp+120,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[5]),32);
    bufp->fullIData(oldp+121,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[6]),32);
    bufp->fullIData(oldp+122,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__data_list[7]),32);
    bufp->fullIData(oldp+123,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+124,(vlSelf->ysyx_24100005_top__DOT__Mux_PC__DOT__i0__DOT__hit));
    bufp->fullQData(oldp+125,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+127,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullQData(oldp+129,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[2]),39);
    bufp->fullQData(oldp+131,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__pair_list[3]),39);
    bufp->fullIData(oldp+133,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+134,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+135,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+136,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+137,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+138,(vlSelf->ysyx_24100005_top__DOT__Mux_input1__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+139,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+140,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__hit));
    bufp->fullQData(oldp+141,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+143,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullIData(oldp+145,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+146,(vlSelf->ysyx_24100005_top__DOT__Mux_writedata__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+147,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[0]),32);
    bufp->fullIData(oldp+148,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[1]),32);
    bufp->fullIData(oldp+149,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[2]),32);
    bufp->fullIData(oldp+150,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[3]),32);
    bufp->fullIData(oldp+151,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[4]),32);
    bufp->fullIData(oldp+152,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[5]),32);
    bufp->fullIData(oldp+153,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[6]),32);
    bufp->fullIData(oldp+154,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[7]),32);
    bufp->fullIData(oldp+155,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[8]),32);
    bufp->fullIData(oldp+156,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[9]),32);
    bufp->fullIData(oldp+157,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[10]),32);
    bufp->fullIData(oldp+158,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[11]),32);
    bufp->fullIData(oldp+159,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[12]),32);
    bufp->fullIData(oldp+160,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[13]),32);
    bufp->fullIData(oldp+161,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[14]),32);
    bufp->fullIData(oldp+162,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[15]),32);
    bufp->fullIData(oldp+163,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[16]),32);
    bufp->fullIData(oldp+164,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[17]),32);
    bufp->fullIData(oldp+165,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[18]),32);
    bufp->fullIData(oldp+166,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[19]),32);
    bufp->fullIData(oldp+167,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[20]),32);
    bufp->fullIData(oldp+168,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[21]),32);
    bufp->fullIData(oldp+169,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[22]),32);
    bufp->fullIData(oldp+170,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[23]),32);
    bufp->fullIData(oldp+171,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[24]),32);
    bufp->fullIData(oldp+172,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[25]),32);
    bufp->fullIData(oldp+173,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[26]),32);
    bufp->fullIData(oldp+174,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[27]),32);
    bufp->fullIData(oldp+175,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[28]),32);
    bufp->fullIData(oldp+176,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[29]),32);
    bufp->fullIData(oldp+177,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[30]),32);
    bufp->fullIData(oldp+178,(vlSelf->ysyx_24100005_top__DOT__RegFile__DOT__rf[31]),32);
    bufp->fullIData(oldp+179,(vlSelf->inst),32);
    bufp->fullBit(oldp+180,(vlSelf->rst));
    bufp->fullBit(oldp+181,(vlSelf->clk));
    bufp->fullIData(oldp+182,(vlSelf->PC),32);
    bufp->fullIData(oldp+183,(((IData)(4U) + vlSelf->PC)),32);
    bufp->fullCData(oldp+184,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+185,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullCData(oldp+186,((0x1fU & (vlSelf->inst 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+187,((0x1fU & (vlSelf->inst 
                                        >> 7U))),5);
    bufp->fullBit(oldp+188,((vlSelf->inst >> 0x1fU)));
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
    bufp->fullWData(oldp+189,(__Vtemp_hb9f4ce29__0),66);
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
    bufp->fullWData(oldp+192,(__Vtemp_he5cfe13e__0),66);
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
    bufp->fullWData(oldp+195,(__Vtemp_heaa31b35__0),312);
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
    bufp->fullWData(oldp+205,(__Vtemp_h523b24e8__0),156);
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
    bufp->fullWData(oldp+210,(__Vtemp_h0610dcb6__0),78);
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
    bufp->fullWData(oldp+213,(__Vtemp_h88d4fbec__0),66);
    bufp->fullSData(oldp+216,(vlSelf->ysyx_24100005_top__DOT__imm),12);
    bufp->fullIData(oldp+217,(2U),32);
    bufp->fullIData(oldp+218,(1U),32);
    bufp->fullIData(oldp+219,(0x20U),32);
    bufp->fullIData(oldp+220,(0U),32);
    bufp->fullIData(oldp+221,(0x21U),32);
    bufp->fullIData(oldp+222,(2U),32);
    bufp->fullIData(oldp+223,(8U),32);
    bufp->fullIData(oldp+224,(7U),32);
    bufp->fullIData(oldp+225,(0x27U),32);
    bufp->fullIData(oldp+226,(8U),32);
    bufp->fullIData(oldp+227,(4U),32);
    bufp->fullIData(oldp+228,(4U),32);
    bufp->fullIData(oldp+229,(5U),32);
    bufp->fullIData(oldp+230,(5U),32);
    bufp->fullBit(oldp+231,(1U));
    bufp->fullIData(oldp+232,(0xc646dfcfU),32);
    bufp->fullIData(oldp+233,(0x80000000U),32);
}
