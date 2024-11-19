// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24100005_top.h for the primary calling header

#ifndef VERILATED_VYSYX_24100005_TOP___024UNIT_H_
#define VERILATED_VYSYX_24100005_TOP___024UNIT_H_  // guard

#include "verilated.h"

class Vysyx_24100005_top__Syms;

class Vysyx_24100005_top___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vysyx_24100005_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_24100005_top___024unit(Vysyx_24100005_top__Syms* symsp, const char* v__name);
    ~Vysyx_24100005_top___024unit();
    VL_UNCOPYABLE(Vysyx_24100005_top___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
