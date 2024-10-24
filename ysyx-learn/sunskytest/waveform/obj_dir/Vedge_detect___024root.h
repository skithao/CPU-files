// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vedge_detect.h for the primary calling header

#ifndef VERILATED_VEDGE_DETECT___024ROOT_H_
#define VERILATED_VEDGE_DETECT___024ROOT_H_  // guard

#include "verilated.h"


class Vedge_detect__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vedge_detect___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(a,0,0);
    VL_OUT8(rise,0,0);
    VL_OUT8(down,0,0);
    CData/*0:0*/ edge_detect__DOT__a_dely;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vedge_detect__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vedge_detect___024root(Vedge_detect__Syms* symsp, const char* v__name);
    ~Vedge_detect___024root();
    VL_UNCOPYABLE(Vedge_detect___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
