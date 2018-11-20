// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 21:02:13

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_3H3P_Slepian11_2_band.dsp
// description = KMHLS_Dome_3H3P_Slepian11_2_band
// speaker array name = KMHLS_Dome
// horizontal order   = 3
// vertical order     = 3
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 
// output speaker order: S1 S2 S3 S4 S5 S6 S7 S8 S9 S10 S11 S12 S13 S14 S15 S16 S17 S18 S19 S20 S21 S22 S23 S24 S25 S26 S27 S28 S29 
//-------


// start decoder configuration
declare name "KMHLS_Dome_3H3P_normal_5";

// bands
nbands = 2;

// decoder type
decoder_type = 2;

// crossover frequency in Hz
xover_freq = hslider("xover [unit:Hz]",400,200,800,20): dezipper;

// lfhf_balance
lfhf_ratio = hslider("lf/hf [unit:dB]", 0, -3, +3, 0.1): mu.db2linear : dezipper;


// decoder order
decoder_order = 3;

// ambisonic order of each input component
co = ( 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3);

// use full or reduced input set
input_full_set = 1;

// delay compensation
delay_comp = 1;

// level compensation
level_comp = 1;

// nfc on input or output
nfc_output = 0;
nfc_input  = 1;

// enable output gain and muting controls
output_gain_muting = 1;

// number of speakers
ns = 29;

// radius for each speaker in meters
rs = (          5.13,         5.137,         5.137,         5.134,          5.13,         5.137,         5.137,         5.134,          5.13,         5.137,         5.137,         5.134,          5.13,         5.137,         5.137,         5.134,         5.204,         5.204,         5.204,         5.204,         5.204,         5.204,         5.204,         5.204,         5.321,         5.321,         5.321,         5.321,          5.34);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1);
gamma(1) = (             1,  0.8611363116,  0.6123336207,   0.304746985);

// gain matrix
s(00,0) = (  0.0511576586,  0.0383407974, -0.0258429439,  0.0663378586,  0.0613351196,   -0.00215435, -0.1087703239, -0.0035345974,  0.0355187959,  0.1464117273,  0.0469081031, -0.0499702799,  0.0923896839, -0.0871255867,  0.0273157848,  0.0006578761);
s(01,0) = (  0.0512834783,  0.0100605405, -0.0260095026,   0.075668543,  0.0176045055, -0.0019395366,  -0.109091302, -0.0022671321,  0.0693767917,  0.0561364526,  0.0134636398, -0.0150031525,  0.0928935352, -0.0973628048,  0.0533543288,  0.1344262178);
s(02,0) = (  0.0512747786, -0.0200049027, -0.0259979864,  0.0736895707, -0.0365714596,  0.0003498058, -0.1090691091, -0.0009038845,  0.0627086085, -0.1030052072, -0.0279692582,  0.0248717577,  0.0928586959, -0.0928533998,  0.0482261522,   0.102178661);
s(03,0) = (  0.0512165268, -0.0468861882, -0.0259208742,  0.0606442828, -0.0692834415,   0.002912569, -0.1089205057, -0.0011119062,  0.0191919721, -0.1341806509, -0.0529868505,  0.0616697514,  0.0926254211, -0.0764162711,  0.0147596158, -0.0571694497);
s(04,0) = (  0.0511576586, -0.0663378586, -0.0258429439,  0.0383407974, -0.0613351196,  0.0035345974, -0.1087703239,   -0.00215435, -0.0355187959,  0.0006578761, -0.0469081031,  0.0871255867,  0.0923896839, -0.0499702799, -0.0273157848, -0.1464117273);
s(05,0) = (  0.0512834783,  -0.075668543, -0.0260095026,  0.0100605405, -0.0176045055,  0.0022671321,  -0.109091302, -0.0019395366, -0.0693767917,  0.1344262178, -0.0134636398,  0.0973628048,  0.0928935352, -0.0150031525, -0.0533543288, -0.0561364526);
s(06,0) = (  0.0512747786, -0.0736895707, -0.0259979864, -0.0200049027,  0.0365714596,  0.0009038845, -0.1090691091,  0.0003498058, -0.0627086085,   0.102178661,  0.0279692582,  0.0928533998,  0.0928586959,  0.0248717577, -0.0482261522,  0.1030052072);
s(07,0) = (  0.0512165268, -0.0606442828, -0.0259208742, -0.0468861882,  0.0692834415,  0.0011119062, -0.1089205057,   0.002912569, -0.0191919721, -0.0571694497,  0.0529868505,  0.0764162711,  0.0926254211,  0.0616697514, -0.0147596158,  0.1341806509);
s(08,0) = (  0.0511576586, -0.0383407974, -0.0258429439, -0.0663378586,  0.0613351196,    0.00215435, -0.1087703239,  0.0035345974,  0.0355187959, -0.1464117273,  0.0469081031,  0.0499702799,  0.0923896839,  0.0871255867,  0.0273157848, -0.0006578761);
s(09,0) = (  0.0512834783, -0.0100605405, -0.0260095026,  -0.075668543,  0.0176045055,  0.0019395366,  -0.109091302,  0.0022671321,  0.0693767917, -0.0561364526,  0.0134636398,  0.0150031525,  0.0928935352,  0.0973628048,  0.0533543288, -0.1344262178);
s(10,0) = (  0.0512747786,  0.0200049027, -0.0259979864, -0.0736895707, -0.0365714596, -0.0003498058, -0.1090691091,  0.0009038845,  0.0627086085,  0.1030052072, -0.0279692582, -0.0248717577,  0.0928586959,  0.0928533998,  0.0482261522,  -0.102178661);
s(11,0) = (  0.0512165268,  0.0468861882, -0.0259208742, -0.0606442828, -0.0692834415,  -0.002912569, -0.1089205057,  0.0011119062,  0.0191919721,  0.1341806509, -0.0529868505, -0.0616697514,  0.0926254211,  0.0764162711,  0.0147596158,  0.0571694497);
s(12,0) = (  0.0511576586,  0.0663378586, -0.0258429439, -0.0383407974, -0.0613351196, -0.0035345974, -0.1087703239,    0.00215435, -0.0355187959, -0.0006578761, -0.0469081031, -0.0871255867,  0.0923896839,  0.0499702799, -0.0273157848,  0.1464117273);
s(13,0) = (  0.0512834783,   0.075668543, -0.0260095026, -0.0100605405, -0.0176045055, -0.0022671321,  -0.109091302,  0.0019395366, -0.0693767917, -0.1344262178, -0.0134636398, -0.0973628048,  0.0928935352,  0.0150031525, -0.0533543288,  0.0561364526);
s(14,0) = (  0.0512747786,  0.0736895707, -0.0259979864,  0.0200049027,  0.0365714596, -0.0009038845, -0.1090691091, -0.0003498058, -0.0627086085,  -0.102178661,  0.0279692582, -0.0928533998,  0.0928586959, -0.0248717577, -0.0482261522, -0.1030052072);
s(15,0) = (  0.0512165268,  0.0606442828, -0.0259208742,  0.0468861882,  0.0692834415, -0.0011119062, -0.1089205057,  -0.002912569, -0.0191919721,  0.0571694497,  0.0529868505, -0.0764162711,  0.0926254211, -0.0616697514, -0.0147596158, -0.1341806509);
s(16,0) = ( -0.0425086076,  0.0309313728,  0.1069133147,  0.0180475558,  0.0627523314,  0.0947403667,  0.1516948685,  0.0538343908, -0.0368713955,  -0.001965242,  0.0479919637,  0.0966115286, -0.2653836249,  0.0546429031, -0.0283560037, -0.0875867569);
s(17,0) = ( -0.0425077909,  0.0092725832,  0.1069116604,  0.0345019461,  0.0349000817,  0.0268787812,  0.1516914398,  0.1047167374,  0.0626220301,  0.0578239949,  0.0266910156,  0.0270108448, -0.2653813376,  0.1061756713,  0.0481595689,  0.0619401532);
s(18,0) = ( -0.0425086076, -0.0180475558,  0.1069133147,  0.0309313728, -0.0627523314, -0.0538343908,  0.1516948685,  0.0947403667,  0.0368713955, -0.0875867569, -0.0479919637, -0.0546429031, -0.2653836249,  0.0966115286,  0.0283560037,   0.001965242);
s(19,0) = ( -0.0425077909, -0.0345019461,  0.1069116604,  0.0092725832, -0.0349000817, -0.1047167374,  0.1516914398,  0.0268787812, -0.0626220301,  0.0619401532, -0.0266910156, -0.1061756713, -0.2653813376,  0.0270108448, -0.0481595689, -0.0578239949);
s(20,0) = ( -0.0425086076, -0.0309313728,  0.1069133147, -0.0180475558,  0.0627523314, -0.0947403667,  0.1516948685, -0.0538343908, -0.0368713955,   0.001965242,  0.0479919637, -0.0966115286, -0.2653836249, -0.0546429031, -0.0283560037,  0.0875867569);
s(21,0) = ( -0.0425077909, -0.0092725832,  0.1069116604, -0.0345019461,  0.0349000817, -0.0268787812,  0.1516914398, -0.1047167374,  0.0626220301, -0.0578239949,  0.0266910156, -0.0270108448, -0.2653813376, -0.1061756713,  0.0481595689, -0.0619401532);
s(22,0) = ( -0.0425086076,  0.0180475558,  0.1069133147, -0.0309313728, -0.0627523314,  0.0538343908,  0.1516948685, -0.0947403667,  0.0368713955,  0.0875867569, -0.0479919637,  0.0546429031, -0.2653836249, -0.0966115286,  0.0283560037,  -0.001965242);
s(23,0) = ( -0.0425077909,  0.0345019461,  0.1069116604, -0.0092725832, -0.0349000817,  0.1047167374,  0.1516914398, -0.0268787812, -0.0626220301, -0.0619401532, -0.0266910156,  0.1061756713, -0.2653813376, -0.0270108448, -0.0481595689,  0.0578239949);
s(24,0) = (  0.0380335228,  -0.008963034,  0.0401303157,  0.0050932845, -0.0169339717,  0.1125569245,  0.0349249883, -0.0640364625, -0.0100392705,  -4.23848e-05, -0.0129508265,  0.1713543169,  0.1139453362, -0.0974982768, -0.0077207165,   0.004818287);
s(25,0) = (  0.0380335228, -0.0050932845,  0.0401303157,  -0.008963034,  0.0169339717,  0.0640364625,  0.0349249883,  0.1125569245,  0.0100392705,   0.004818287,  0.0129508265,  0.0974982768,  0.1139453362,  0.1713543169,  0.0077207165,   4.23848e-05);
s(26,0) = (  0.0380335228,   0.008963034,  0.0401303157, -0.0050932845, -0.0169339717, -0.1125569245,  0.0349249883,  0.0640364625, -0.0100392705,   4.23848e-05, -0.0129508265, -0.1713543169,  0.1139453362,  0.0974982768, -0.0077207165,  -0.004818287);
s(27,0) = (  0.0380335228,  0.0050932845,  0.0401303157,   0.008963034,  0.0169339717, -0.0640364625,  0.0349249883, -0.1125569245,  0.0100392705,  -0.004818287,  0.0129508265, -0.0974982768,  0.1139453362, -0.1713543169,  0.0077207165,  -4.23848e-05);
s(28,0) = (  0.0900274516,             0,   -0.01450042,             0,            -0,            -0, -0.0672099323,            -0,            -0,            -0,             0,            -0,  0.3397348308,            -0,             0,             0);


// ----- do not change anything below here ----

// mask for full ambisonic set to channels in use
input_mask(0) = bus(nc);
input_mask(1) = (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_);


// Start of decoder implementation.  No user serviceable parts below here!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//declare name		"Fill in name in configuration section below";
declare version 	"1.2";
declare author 		"AmbisonicDecoderToolkit";
declare license 	"BSD 3-Clause License";
declare copyright	"(c) Aaron J. Heller 2013";

/*
Copyright (c) 2013, Aaron J. Heller
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
  Author: Aaron J. Heller <heller@ai.sri.com>
  $Id: 21810b615fa65b96af41a7c8783d7435b41084b8 $
*/

// v 1.2, 28-Oct-2017 ajh
//  . add 6th-order NFC filters
//  . fixed error in speaker_chain and speaker_chain2, where speaker 
//    distance was being indexed by order, not speaker number

// v 1.1 remove dependancies on Faust Libraries, 23-Nov-2016 ajh
//   m = library("math.lib");
//   mu = library("music.lib");

m = environment {
  // from the old math.lib
  take (1, (xs, xxs)) = xs;
  take (1, xs) = xs;
  take (nn, (xs, xxs)) = take (nn-1, xxs);

  bus(2) = _,_; // avoids a lot of "bus(1)" labels in block diagrams
  bus(n) = par(i, n, _);

  SR = min(192000, max(1, fconstant(int fSamplingFreq, <math.h>)));
  //PI = 3.1415926535897932385;
  // quad precision value
  PI = 3.14159265358979323846264338327950288;
};

mu = environment {
   // from the old music.lib
   db2linear(x)	= pow(10, x/20.0);
};



// m.SR from math.lib is an integer, we need a float
SR = float(m.SR);

// descriptive statistics
total(c) = c:>_;

average(c) = total(c)/count(c);

count(c) = R(c) :>_ with {
 R((c,cl)) = R(c),(R(cl));
 R(c)      = 1;
};

rms(c) = R(c) :> /(count(c)) : sqrt with {
 R((c,cl)) = R(c),R(cl);
 R(c)      = (c*c);
};

sup(c) = R(c) with {
 R((c,cl)) = max(R(c),R(cl));
 R(c)      = c;
};

inf(c) = R(c) with {
 R((c,cl)) = min(R(c),R(cl));
 R(c)      = c;
};

// bus
bus(n)   = par(i,n,_);

// bus with gains
gain(c) = R(c) with {
  R((c,cl)) = R(c),R(cl);
  R(1)      = _;
  R(0)      = !:0;  // need to preserve number of outputs, faust will optimize away
  R(float(0)) = R(0);
  R(float(1)) = R(1);
  R(c)      = *(c);
};

// fir filter  (new improved, better behaved)
fir(c) = R(c) :>_ with {
  R((c,lc)) = _<: R(c), (mem:R(lc));
  R(c)      = gain(c);
};

// --- phase-matched bandsplitter from BLaH3
xover(freq,n) = par(i,n,xover1) with {

	sub(x,y) = y-x;

	k = tan(m.PI*float(freq)/m.SR);
	k2 = k^2;
	d =  (k2 + 2*k + 1);
	//d = (k2,2*k,1):>_;
	// hf numerator
	b_hf = (1/d,-2/d,1/d);
	// lf numerator
	b_lf = (k2/d, 2*k2/d, k2/d);
	// denominator
	a = (2 * (k2-1) / d, (k2 - 2*k + 1) / d);
	// 
	xover1 = _:sub ~ fir(a) <: fir(b_lf),fir(b_hf):_,*(-1);
};

shelf(freq,g_lf,g_hf) = xover(freq,1) : gain(g_lf),gain(g_hf):>_;

// from http://old.nabble.com/Re%3A--Faudiostream-devel---ANN--Faust-0.9.24-p28597267.html
//   (not used currently, do we need to worry about denormals?)
anti_denormal = pow(10,-20);
anti_denormal_ac = 1 - 1' : *(anti_denormal) : + ~ *(-1); 

// UI "dezipper"
smooth(c) = *(1-c) : +~*(c);
dezipper = smooth(0.999);

// physical constants     

temp_celcius = 20;                        
c = 331.3 * sqrt(1.0 + (temp_celcius/273.15)); // speed of sound m/s


// ---- NFC filters ----
//  see BesselPoly.m for coefficient calculations
//
// [1] J. Daniel, “Spatial Sound Encoding Including Near Field Effect:
//     Introducing Distance Coding Filters and a Viable, New Ambisonic 
//     Format ,” Preprints 23rd AES International Conference, Copenhagen,
//     2003.
// [2] Weisstein, Eric W. "Bessel Polynomial." From MathWorld--A Wolfram 
//     Web Resource. http://mathworld.wolfram.com/BesselPolynomial.html
// [3] F. Adriaensen, “Near Field filters for Higher Order
//     Ambisonics,” Jul. 2006.
// [4] J. O. Smith, “Digital State-Variable Filters,” CCRMA, May 2013.
//
// [5] "A Filter Primer", https://www.maximintegrated.com/en/app-notes/index.mvp/id/733

// first and second order state variable filters see [4]
//   FIXME FIXME this code needs to be refactored, so that the roots are 
//               passed in rather then hardwired in the code, or another 
//               API layer, or ...
svf1(g,d1)    = _ : *(g) :       (+      <: +~_, _ ) ~ *(d1)                   : !,_ ;
svf2(g,d1,d2) = _ : *(g) : (((_,_,_):> _ <: +~_, _ ) ~ *(d1) : +~_, _) ~ *(d2) : !,_ ;

//  these are Bessel filters, see [1,2]
nfc1(r,gain) = svf1(g,d1)  // r in meters
 with {
   omega = c/(float(r)*SR);
   //  1  1
   b1 = omega/2.0;
   g1 = 1.0 + b1;
   d1 = 0.0 - (2.0 * b1) / g1;
   g = gain/g1;
};

nfc2(r,gain) = svf2(g,d1,d2)
 with {
   omega = c/(float(r)*SR);
   r1 = omega/2.0;
   r2 = r1 * r1;

   // 1.000000000000000   3.00000000000000   3.00000000000000
   b1 = 3.0 * r1;
   b2 = 3.0 * r2;
   g2 = 1.0 + b1 + b2;

   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;
   g = gain/g2;
};

nfc3(r,gain) = svf2(g,d1,d2):svf1(1.0,d3)
 with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;

   // 1.000000000000000   3.677814645373914   6.459432693483369
   b1 = 3.677814645373914 * r1;
   b2 = 6.459432693483369 * r2;         
   g2 = 1.0 + b1 + b2;
   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;

   // 1.000000000000000   2.322185354626086
   b3 = 2.322185354626086 * r1;
   g3 = 1.0 + b3;
   d3 = 0.0 - (2.0 * b3) / g3;

   g = gain/(g3*g2);
};

nfc4(r,gain) = svf2(g,d1,d2):svf2(1.0,d3,d4)
 with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;
   
   // 1.000000000000000   4.207578794359250  11.487800476871168
   b1 =  4.207578794359250 * r1;
   b2 = 11.487800476871168 * r2;         
   g2 = 1.0 + b1 + b2;
   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;

   // 1.000000000000000   5.792421205640748   9.140130890277934
   b3 = 5.792421205640748 * r1;
   b4 = 9.140130890277934 * r2;         
   g3 = 1.0 + b3 + b4;
   d3 = 0.0 - (2.0 * b3 + 4.0 * b4) / g3;  // fixed
   d4 = 0.0 - (4.0 * b4) / g3;
   
   g = gain/(g3*g2);
};

nfc5(r,gain) = svf2(g,d1,d2):svf2(1.0,d3,d4):svf1(1.0,d5)
 with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;
   
   // 1.000000000000000   4.649348606363304  18.156315313452325
   b1 =  4.649348606363304 * r1;
   b2 = 18.156315313452325 * r2;         
   g2 = 1.0 + b1 + b2;
   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;

   // 1.000000000000000   6.703912798306966  14.272480513279568
   b3 =  6.703912798306966 * r1;
   b4 = 14.272480513279568 * r2;         
   g3 = 1.0 + b3 + b4;
   d3 = 0.0 - (2.0 * b3 + 4 * b4) / g3;  // fixed
   d4 = 0.0 - (4.0 * b4) / g3;

   // 1.000000000000000   3.646738595329718
   b5 = 3.646738595329718 * r1;
   g4 = 1.0 + b5;
   d5 = 0.0 - (2.0 * b5) / g4;

   g = gain/(g4*g3*g2);
 };

nfc6(r,gain) = svf2(g,d11,d12):svf2(1.0,d21,d22):svf2(1.0,d31,d32)
with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;

   // reverse Bessel Poly 6:
   //   1          21         210        1260        4725       10395       10395
   // factors:
   //   1.000000000000000   5.031864495621642  26.514025344067996
   //   1.000000000000000   7.471416712651683  20.852823177396761
   //   1.000000000000000   8.496718791726696  18.801130589570320


   // 1.000000000000000   5.031864495621642  26.514025344067996
   b11 =  5.031864495621642 * r1;
   b12 = 26.514025344067996 * r2;         
   g1 = 1.0 + b11 + b12;
   d11 = 0.0 - (2.0 * b11 + 4.0 * b12) / g1;
   d12 = 0.0 - (4.0 * b12) / g1;

   // 1.000000000000000   7.471416712651683  20.852823177396761
   b21 =  7.471416712651683 * r1;
   b22 = 20.852823177396761 * r2;         
   g2 = 1.0 + b21 + b22;
   d21 = 0.0 - (2.0 * b21 + 4.0 * b22) / g2;
   d22 = 0.0 - (4.0 * b22) / g2;

   // 1.000000000000000   8.496718791726696  18.801130589570320
   b31 =  8.496718791726696 * r1;
   b32 = 18.801130589570320 * r2;         
   g3 = 1.0 + b31 + b32;
   d31 = 0.0 - (2.0 * b31 + 4.0 * b32) / g3;
   d32 = 0.0 - (4.0 * b32) / g3;

   g = gain/(g3*g2*g1);
};


// ---- End NFC filters ----

nfc(0,r,g) = gain(g);
nfc(1,r,g) = nfc1(r,g);
nfc(2,r,g) = nfc2(r,g);
nfc(3,r,g) = nfc3(r,g);
nfc(4,r,g) = nfc4(r,g);
nfc(5,r,g) = nfc5(r,g);
nfc(6,r,g) = nfc6(r,g);

// null NFC filters to allow very high order decoders. FIXME!
nfc(o,r,g) = gain(g);

//declare name "nfctest";
//process = bus(6):(nfc(0,2,1),nfc(1,2,1),nfc(2,2,1),nfc(3,2,1),nfc(4,2,1),nfc(5,2,1)):bus(6);


// top level api to NFC filters
nfc_out(1,order,r,g) = nfc(order,r,g);
nfc_out(0,order,r,g) = _;

nfc_inp(1,order,r,g) = nfc(order,r,g);
nfc_inp(0,order,r,g) = _;



// ---- delay and level
delay(dc,r)  = R(dc,r) with {
 R(0,r) = _;  // delay_comp off
 R(1,0) = _;  // delay_comp on, but no delay
 R(1,float(0)) = R(1,0);
 R(1,r) = @(meters2samples(r));
 meters2samples(r) = int(m.SR * (float(r)/float(c)) + 0.5);
};

level(lc,r,rmax) = R(lc,r,rmax) with{
 R(0,r,rmax) = _;  // level_comp off
 R(1,r,rmax) = gain(float(r)/float(rmax));
};


delay_level(r) = R(r) with {  // delay_comp and level_comp are free variables (fix?)
 R((r,rl)) =   R(r), R(rl);
 R(r)      =   delay(delay_comp,(r_max-r)) : level(level_comp,r,r_max);
};

// ---- gates
gate(0) = !;
gate(1) = _;
dirac(i,j) = i==j;
gate_bus(order,(o,oss)) = (gate(order==o),gate_bus(order,oss));
gate_bus(order,o)       =  gate(order==o);


// route (not used)
route(n_inputs,n_outputs,outs) = m.bus(n_inputs)
                               <: par(i,n_outputs,(0,gate_bus(i,outs)):>_)
                               : m.bus(n_outputs);

//process = route(4,4,(3,1,1,2)); // test


// deinterleave 
deinterleave(n,span) = par(i,n,_) <: par(i,span, par(j,n,gate(%(j,span)==i)));


// 1 band speaker chain
speaker_chain(ispkr) = gain(s(ispkr,0))  // decoder matrix gains
		     // iterate over orders, select each order from matrix
		     <: par(jord,no,gate_bus(jord,co)
		            // sum and apply NFC filter for that order
			    // at the speaker distance
		            :> nfc_out(nfc_output,jord,m.take(ispkr+1,rs),1.0))
		     // sum the orders
	             :>_;

// 1 band speaker chain -- bad definition
// speaker_chain(i) = gain(s(i,0)) <: par(i,no,gate_bus(i,co):>nfc_out(nfc_output,i,m.take(i+1,rs),1.0)):>_;

// near field correction at input, nfc_input = 1
nfc_input_bus(nc) = par(i,nc, nfc_inp(nfc_input, m.take(i+1,co), r_bar, 1.0));

// per order gains
gamma_bus(n) = par(i,nc, gain( m.take(m.take(i+1,co)+1, gamma(n))));

// output gain and muting
output_gain = hslider("gain [unit:dB]", -10, -30, +10, 1): mu.db2linear :*(checkbox("mute")<0.5): dezipper;

gain_muting_bus(0,n) = bus(n);
gain_muting_bus(1,n) = par(i,n,*(output_gain));


// one band decoder
decoder(1,nc,ns) = nfc_input_bus(nc) 
                :  gamma_bus(0) 
                <: par(is,ns, speaker_chain(is)) 
                : delay_level(rs); 


// two band decoder
//   there are two variants of the two-band decoder
//     1. classic, with shelf-filters and one matrix
//     2. vienna,  bandsplitting filters and separate LF and HF matricies.

// classic shelf filter decoder
decoder(2,nc,ns) = nfc_input_bus(nc) 
                :  par(i,nc, shelf(xover_freq,m.take(m.take(i+1,co)+1, gamma(0))/lfhf_ratio,
                                              m.take(m.take(i+1,co)+1, gamma(1))*lfhf_ratio))
                <: par(is,ns, speaker_chain(is)) 
                :  delay_level(rs);

// vienna decoder
//   FIXME FIXME  need to incorporate lfhf_ratio
decoder(3,nc,ns) = bus(nc)
                   : nfc_input_bus(nc) 
                   : xover(xover_freq,nc) : deinterleave(2*nc,2) 
                   : (gamma_bus(0),gamma_bus(1)) : bus(2*nc)
                   <: par(j, ns, speaker_chain2(j,nc))
                   : delay_level(rs)
; 
// 2 band speaker chain for vienna decoder
// i is speaker, j is order
speaker_chain2(i,nc) = gain(s(i,0)), gain(s(i,1))
                       :> bus(nc)
                       <: par(j,no,gate_bus(j,co):>nfc_out(nfc_output,j,m.take(i+1,rs),1.0))
                       :>_ ;

//process = speaker_chain2(1,16); // test



// --------------------------------------
//  things calculated from decoder config 

// maximum and average speaker distance
r_max = sup(rs);
r_bar = (rs :> float) / float(count(rs));

// number of ambisonic orders, including 0
no = decoder_order+1;

// number of input component signals
nc = count(co);



// the top-level process
process = input_mask(input_full_set):decoder(decoder_type,nc,ns):gain_muting_bus(output_gain_muting,ns);


// End of decoder implementation.  No user serviceable parts above here!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//EOF!
