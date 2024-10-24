// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vedge_detect.h for the primary calling header

#include "Vedge_detect__pch.h"
#include "Vedge_detect__Syms.h"
#include "Vedge_detect___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vedge_detect___024root___dump_triggers__act(Vedge_detect___024root* vlSelf);
#endif  // VL_DEBUG

void Vedge_detect___024root___eval_triggers__act(Vedge_detect___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, (((IData)(vlSelfRef.clk) 
                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))) 
                                       | ((IData)(vlSelfRef.rst_n) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vedge_detect___024root___dump_triggers__act(vlSelf);
    }
#endif
}
