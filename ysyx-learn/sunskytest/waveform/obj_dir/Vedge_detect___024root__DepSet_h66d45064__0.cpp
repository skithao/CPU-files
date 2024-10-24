// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vedge_detect.h for the primary calling header

#include "Vedge_detect__pch.h"
#include "Vedge_detect___024root.h"

void Vedge_detect___024root___eval_act(Vedge_detect___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vedge_detect___024root___nba_sequent__TOP__0(Vedge_detect___024root* vlSelf);

void Vedge_detect___024root___eval_nba(Vedge_detect___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vedge_detect___024root___nba_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*0:0*/, 8> Vedge_detect__ConstPool__TABLE_hede2e6fb_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vedge_detect__ConstPool__TABLE_hede2d5ea_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vedge_detect__ConstPool__TABLE_hc3013af4_0;

VL_INLINE_OPT void Vedge_detect___024root___nba_sequent__TOP__0(Vedge_detect___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.edge_detect__DOT__a_dely) 
                     << 2U) | (((IData)(vlSelfRef.a) 
                                << 1U) | (IData)(vlSelfRef.rst_n)));
    vlSelfRef.edge_detect__DOT__a_dely = Vedge_detect__ConstPool__TABLE_hede2e6fb_0
        [__Vtableidx1];
    vlSelfRef.rise = Vedge_detect__ConstPool__TABLE_hede2d5ea_0
        [__Vtableidx1];
    vlSelfRef.down = Vedge_detect__ConstPool__TABLE_hc3013af4_0
        [__Vtableidx1];
}

void Vedge_detect___024root___eval_triggers__act(Vedge_detect___024root* vlSelf);

bool Vedge_detect___024root___eval_phase__act(Vedge_detect___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vedge_detect___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vedge_detect___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vedge_detect___024root___eval_phase__nba(Vedge_detect___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vedge_detect___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vedge_detect___024root___dump_triggers__nba(Vedge_detect___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vedge_detect___024root___dump_triggers__act(Vedge_detect___024root* vlSelf);
#endif  // VL_DEBUG

void Vedge_detect___024root___eval(Vedge_detect___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vedge_detect___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("edge_detect.v", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vedge_detect___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("edge_detect.v", 2, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vedge_detect___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vedge_detect___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vedge_detect___024root___eval_debug_assertions(Vedge_detect___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vedge_detect__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vedge_detect___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelfRef.a & 0xfeU))) {
        Verilated::overWidthError("a");}
}
#endif  // VL_DEBUG
