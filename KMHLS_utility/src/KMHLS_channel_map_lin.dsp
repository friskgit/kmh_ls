declare name	"KMHLS ChannelMap - 16+29+4";
declare version " 0.1 ";
declare author " Henrik Frisk " ;
declare license " BSD ";
declare copyright "(c) dinergy 2018 ";

//---------------`Channel mapping plugin` --------------------------
//
// Channel mapping plugin that takes 52 inputs, although only the 49 first channels are routed.
// These are routed to the Crescendo mixer channel layout.
//
// This version expects the floor ring in the beginning of the input.
// 
// Insert this plugin on the master track or similar to get channels to map correctly to the Crescendo, i.e.:
// 
// * Channel 1-16 of the input maps to Crescendo 33-48 (Layer B)
// * Channel 17-45 of the input maps to Crescendo 1-29 (Layer A)
// * Channel 46-49 maps to Crescendo 49-52 (Layer B)
//---------------------------------------------------

import("stdfaust.lib");

domevol = hslider("Volume dome", 1., 0., 1., 0.001) : si.smoo;
floorvol = hslider("Volume floor", 1., 0., 1., 0.001) : si.smoo;
bassvol = hslider("Volume bass", 1., 0., 1., 0.001) : si.smoo;

process (d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16,
	 a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16,
	 b1, b2, b3, b4, b5, b6, b7, b8,
	 c1, c2, c3, c4, c5, 
	 sub1, sub2, sub3, sub4, x1, x2, x3) = a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16,
				   b1, b2, b3, b4, b5, b6, b7, b8,
				   c1, c2, c3, c4, c5, 0, 0, 0,
				   d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16,
				   sub1, sub2, sub3, sub4
						     : hgroup("lower ring", par(i, 29, _ * domevol)), _, _, _,
				   hgroup("floor ring", par(i, 16, _ * floorvol)),
				   hgroup("subs", par(i, 4, _ * bassvol));
