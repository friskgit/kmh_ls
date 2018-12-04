// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 03-Dec-2018 21:28:46

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_3H3P_Slepian11_2_band.dsp
// description = KMHLS_Dome_3H3P_Slepian11_2_band
// speaker array name = KMHLS_Dome
// horizontal order   = 3
// vertical order     = 3
// coefficient order  = fuma
// coefficient scale  = fuma
// input scale        = fuma
// mixed-order scheme = HP
// input channel order: WXYZRSTUVKLMNOPQ
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
nfc_output = 1;
nfc_input  = 0;

// enable output gain and muting controls
output_gain_muting = 1;

// number of speakers
ns = 29;

// radius for each speaker in meters
rs = (         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.085,         5.085,         5.085,         5.085,         5.576);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1);
gamma(1) = (             1,  0.8611363116,  0.6123336207,   0.304746985);

// gain matrix
s(00,0) = (  0.0773735463,   0.062479288,  0.0341546486, -0.0372002777,  -0.123599668,  -0.007238196, -0.0124183644,  0.0319485846,  0.0488058346,  0.1189259646, -0.0752143041, -0.0524192858,  0.0211465823,  0.0321250279, -0.0048683373,  0.1110872237);
s(01,0) = (  0.0761857422,  0.0707806636,  0.0060725351,  -0.034783365, -0.1203481976, -0.0011054156,   -0.00630228,  0.0628280947,  0.0134683219,  0.1130962527, -0.0757779959, -0.0149242783,  0.0415855504,  0.0088651331,  0.0973119729,  0.0380166651);
s(02,0) = (  0.0746723765,  0.0683064633, -0.0167720161, -0.0325806455, -0.1168486059, -0.0016092225,  0.0042086858,  0.0590734839,  -0.025478314,  0.1075703128, -0.0738578686,  0.0230459359,  0.0391003954, -0.0167703627,  0.0880114581,  -0.073652386);
s(03,0) = (  0.0738862356,   0.054141851, -0.0391291214, -0.0341043807, -0.1169878008, -0.0082000665,  0.0115589033,  0.0177783752, -0.0532414829,  0.1104871971, -0.0677370765,  0.0564594606,  0.0117674031, -0.0350446651, -0.0328414794, -0.1007592737);
s(04,0) = (  0.0748486438,  0.0358005195, -0.0543917146, -0.0378215738, -0.1209125394,  -0.010899832,  0.0097628378, -0.0257128111, -0.0484901063,  0.1190261355, -0.0520743824,  0.0702518056, -0.0170191601, -0.0319172089, -0.1002185365, -0.0107450755);
s(05,0) = (  0.0768544856,  0.0127873686, -0.0664929086, -0.0401454156, -0.1251139934, -0.0066996778,  0.0052895468, -0.0568858974, -0.0205164625,  0.1250581495, -0.0223829182,  0.0770782455, -0.0376524446, -0.0135043676, -0.0631659995,  0.0906244433);
s(06,0) = (   0.078892756, -0.0167660041, -0.0715410213, -0.0379516434, -0.1260418821,  0.0034659423,  0.0047492847, -0.0579130969,  0.0245512719,  0.1213064857,  0.0220606358,  0.0815872573,  -0.038332342,  0.0161601641,   0.060811689,  0.0881579407);
s(07,0) = (  0.0792803989, -0.0416723283, -0.0633706648,  -0.033683749, -0.1233936553,  0.0092702542,  0.0091800063, -0.0259042016,  0.0541080534,  0.1122400167,  0.0559001086,  0.0787623599, -0.0171458403,    0.03561506,  0.1109257325, -0.0236729611);
s(08,0) = (  0.0782298903, -0.0636760618, -0.0369524487, -0.0328876969, -0.1215020791,  0.0072017428,  0.0102406785,  0.0314638542,  0.0515303803,  0.1099941467,   0.076405607,  0.0523072624,  0.0208257421,  0.0339183813,  0.0066428982, -0.1142149674);
s(09,0) = (   0.077569025, -0.0697573545, -0.0106565388, -0.0374162944, -0.1240014518,  0.0044250406,  0.0018923151,  0.0593588545,  0.0185437331,  0.1194911387,  0.0792894188,  0.0135697499,  0.0392892805,  0.0122058756, -0.0914461377, -0.0440628295);
s(10,0) = (  0.0776657675, -0.0659806299,  0.0150132975, -0.0419731735, -0.1274646068,  0.0065822312, -0.0090942585,  0.0548691945,  -0.024110494,  0.1294238146,  0.0782935005, -0.0279826462,  0.0363176007, -0.0158700348, -0.0798952664,   0.074047696);
s(11,0) = (  0.0780358491, -0.0553470957,  0.0363829176, -0.0420107761, -0.1279528514,  0.0112384813, -0.0132856163,   0.023139293, -0.0516104977,  0.1296882407,  0.0732642785, -0.0559673565,  0.0153157634, -0.0339711163,  0.0184303033,  0.1059133257);
s(12,0) = (   0.078056334, -0.0350724392,  0.0591748165, -0.0367193202, -0.1240967612,  0.0116368356, -0.0073524386, -0.0304997934, -0.0503690764,   0.118220028,  0.0523153643, -0.0719364417, -0.0201876358, -0.0331539866,  0.1055484254,  0.0018256376);
s(13,0) = (  0.0776712405, -0.0129711332,  0.0726615657, -0.0324767642, -0.1205052541,  0.0034848913, -0.0001031304, -0.0623087599, -0.0193310625,  0.1088267136,  0.0181439582, -0.0763620144, -0.0412418057, -0.0127241124,   0.056492599, -0.1000619655);
s(14,0) = (   0.077428069,  0.0141540926,  0.0754738784, -0.0324905678, -0.1202126908, -0.0083102903,  0.0001310757,  -0.061675531,  0.0257860739,  0.1087365053, -0.0260311289, -0.0789259055, -0.0408226752,  0.0169729368,  -0.065949541, -0.0883961996);
s(15,0) = (  0.0775923967,  0.0429626393,  0.0604481749, -0.0360866501, -0.1230551729, -0.0129127883,  -0.008218594, -0.0196070297,  0.0565158915,  0.1166183951, -0.0623177905, -0.0742938734, -0.0129777789,  0.0371999497, -0.1055898564,   0.045407164);
s(16,0) = (  -0.065845721,  0.0441867944,  0.0156070776,  0.1241838217,  0.1730578074,  0.0957664199,  0.0343782074,  0.0483642364,  0.0421506004, -0.3019165341,  0.0865276761,  0.0316298087,  0.0320120067,  0.0277444126,  0.0345402176,  0.0640127277);
s(17,0) = ( -0.0674254858,  0.0397834701, -0.0208661696,  0.1235811671,  0.1745821456,   0.087163223, -0.0431184403,   0.035832383, -0.0523370254,  -0.301389807,  0.0792826336, -0.0383101969,  0.0237172459, -0.0344493321,  0.0123256427,  -0.076814327);
s(18,0) = ( -0.0644371612,  0.0159415623, -0.0382431844,    0.11692153,  0.1659771846,  0.0315184637, -0.0893701501, -0.0474113604, -0.0374360348, -0.2854670512,  0.0273036566, -0.0838284293, -0.0313813037, -0.0246411863, -0.0609090369,  0.0430184634);
s(19,0) = ( -0.0605211599, -0.0208446805, -0.0427399539,  0.1186245548,  0.1623519893, -0.0384506685, -0.0869821875, -0.0415046185,   0.049821057, -0.2872263866, -0.0318428112, -0.0759249572, -0.0274716656,  0.0327932687,  0.0721957356,  0.0177765142);
s(20,0) = ( -0.0618908119,  -0.041586824, -0.0173643953,   0.118646196,  0.1640727456, -0.0901014408, -0.0321923044,  0.0478807617,  0.0441568376, -0.2879500778, -0.0813853916, -0.0267940995,  0.0316919977,  0.0290649603, -0.0348635507, -0.0712746374);
s(21,0) = ( -0.0634623797, -0.0365444201,  0.0179012874,  0.1139091549,   0.162554069, -0.0828473397,  0.0355473023,  0.0398820193, -0.0435046868, -0.2784509048, -0.0766272224,  0.0308698729,  0.0263976766, -0.0286357008, -0.0254167407,  0.0673634028);
s(22,0) = ( -0.0642110945, -0.0206434333,  0.0391661621,  0.1202927637,  0.1681687816, -0.0415777967,  0.0855062238, -0.0345661023, -0.0513901793, -0.2926683004, -0.0363876803,   0.077635205,  -0.022879102, -0.0338260981,   0.072019975, -0.0108779605);
s(23,0) = ( -0.0652564472,  0.0193690181,  0.0463888936,  0.1259122727,  0.1735922245,  0.0378715424,  0.0957556828, -0.0483828717,  0.0482164146, -0.3053747643,  0.0325722434,  0.0842239631, -0.0320243414,  0.0317370592, -0.0702907193, -0.0322363913);
s(24,0) = (  0.0431800282, -0.0052334199, -0.0053505369,  0.0587546786,  0.0616114649,  0.1079309291,  0.1091504006,  -0.000619787,  0.0138103972,  0.0678720803,  0.1550779597,  0.1568898975, -0.0004102334,  0.0090902942,  0.0056620165, -0.0059134314);
s(25,0) = (  0.0452297953, -0.0048723793,  0.0054435107,  0.0534942124,  0.0552011509,  0.1053016933, -0.1054316585,  0.0036409603, -0.0154621422,  0.0802959835,  0.1510571906, -0.1518328864,  0.0024099304, -0.0101775075,  0.0053466038,  0.0054676177);
s(26,0) = (   0.048513121,  0.0051511597,   0.005139621,   0.048310601,  0.0473117359, -0.1078516705, -0.1085295745,  0.0001634211,  0.0150203871,  0.0931626747,  -0.154881131, -0.1558138483,  0.0001081675,   0.009886735, -0.0059408939,  0.0047036987);
s(27,0) = (  0.0453843494,  0.0057091734, -0.0048976204,    0.05201257,  0.0539218985, -0.1039151916,  0.1058710753, -0.0033951145,  -0.012648649,  0.0835863579, -0.1500127178,  0.1518687191, -0.0022472065, -0.0083256071, -0.0041795359, -0.0064150598);
s(28,0) = (  0.1194173133, -0.0005796942, -0.0002573545, -0.0118852868, -0.0633096545, -0.0011261161, -0.0008145647,  0.0001617386, -0.0005531571,  0.3112508176, -0.0009536686, -0.0008542379,  0.0001070538, -0.0003640997,   -0.00068238,  0.0016573168);


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
