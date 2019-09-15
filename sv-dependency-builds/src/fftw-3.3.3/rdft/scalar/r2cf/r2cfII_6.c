/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Nov 25 07:40:13 EST 2012 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cf.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -n 6 -name r2cfII_6 -dft-II -include r2cfII.h */

/*
 * This function contains 13 FP additions, 6 FP multiplications,
 * (or, 7 additions, 0 multiplications, 6 fused multiply/add),
 * 15 stack variables, 2 constants, and 12 memory accesses
 */
#include "r2cfII.h"

static void r2cfII_6(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(24, rs), MAKE_VOLATILE_STRIDE(24, csr), MAKE_VOLATILE_STRIDE(24, csi)) {
	       E T1, T9, T2, T3, T6, T7;
	       T1 = R0[0];
	       T9 = R1[WS(rs, 1)];
	       T2 = R0[WS(rs, 2)];
	       T3 = R0[WS(rs, 1)];
	       T6 = R1[WS(rs, 2)];
	       T7 = R1[0];
	       {
		    E Tc, T4, Ta, T8, T5, Tb;
		    Cr[WS(csr, 1)] = T1 + T2 - T3;
		    Tc = T2 + T3;
		    T4 = T3 - T2;
		    Ta = T6 + T7;
		    T8 = T6 - T7;
		    T5 = FMA(KP500000000, T4, T1);
		    Tb = FMA(KP500000000, Ta, T9);
		    Ci[WS(csi, 1)] = T9 - Ta;
		    Cr[WS(csr, 2)] = FMA(KP866025403, T8, T5);
		    Cr[0] = FNMS(KP866025403, T8, T5);
		    Ci[WS(csi, 2)] = FMS(KP866025403, Tc, Tb);
		    Ci[0] = -(FMA(KP866025403, Tc, Tb));
	       }
	  }
     }
}

static const kr2c_desc desc = { 6, "r2cfII_6", {7, 0, 6, 0}, &GENUS };

void X(codelet_r2cfII_6) (planner *p) {
     X(kr2c_register) (p, r2cfII_6, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 6 -name r2cfII_6 -dft-II -include r2cfII.h */

/*
 * This function contains 13 FP additions, 4 FP multiplications,
 * (or, 11 additions, 2 multiplications, 2 fused multiply/add),
 * 14 stack variables, 2 constants, and 12 memory accesses
 */
#include "r2cfII.h"

static void r2cfII_6(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(24, rs), MAKE_VOLATILE_STRIDE(24, csr), MAKE_VOLATILE_STRIDE(24, csi)) {
	       E Ta, T7, T9, T1, T3, T2, T8, T4, T5, T6, Tb;
	       Ta = R1[WS(rs, 1)];
	       T5 = R1[WS(rs, 2)];
	       T6 = R1[0];
	       T7 = KP866025403 * (T5 - T6);
	       T9 = T5 + T6;
	       T1 = R0[0];
	       T3 = R0[WS(rs, 1)];
	       T2 = R0[WS(rs, 2)];
	       T8 = KP866025403 * (T2 + T3);
	       T4 = FMA(KP500000000, T3 - T2, T1);
	       Cr[0] = T4 - T7;
	       Cr[WS(csr, 2)] = T4 + T7;
	       Ci[WS(csi, 1)] = Ta - T9;
	       Cr[WS(csr, 1)] = T1 + T2 - T3;
	       Tb = FMA(KP500000000, T9, Ta);
	       Ci[0] = -(T8 + Tb);
	       Ci[WS(csi, 2)] = T8 - Tb;
	  }
     }
}

static const kr2c_desc desc = { 6, "r2cfII_6", {11, 2, 2, 0}, &GENUS };

void X(codelet_r2cfII_6) (planner *p) {
     X(kr2c_register) (p, r2cfII_6, &desc);
}

#endif				/* HAVE_FMA */
