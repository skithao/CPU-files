// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vedge_detect__Syms.h"


void Vedge_detect___024root__trace_chg_0_sub_0(Vedge_detect___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vedge_detect___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root__trace_chg_0\n"); );
    // Init
    Vedge_detect___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vedge_detect___024root*>(voidSelf);
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vedge_detect___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vedge_detect___024root__trace_chg_0_sub_0(Vedge_detect___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.a));
    bufp->chgBit(oldp+3,(vlSelfRef.rise));
    bufp->chgBit(oldp+4,(vlSelfRef.down));
    bufp->chgBit(oldp+5,(vlSelfRef.edge_detect__DOT__a_dely));
}

void Vedge_detect___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root__trace_cleanup\n"); );
    // Init
    Vedge_detect___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vedge_detect___024root*>(voidSelf);
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}