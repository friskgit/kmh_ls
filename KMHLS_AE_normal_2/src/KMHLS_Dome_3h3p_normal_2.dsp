// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 27-Jun-2019 12:07:13

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_3h3p_pinv_even_energy_rV_max_rE_2_band.dsp
// description = KMHLS_Dome_3h3p_pinv_even_energy_rV_max_rE_2_band
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
declare name "KMHLS_Dome_3h3p_normal_2";

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
rs = (          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         5.317,         5.317,         5.317,         5.317,         5.576);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1);
gamma(1) = (   2.245861807,   1.933993153,   1.375216692,  0.6844196142);

// gain matrix
s(00,0) = (   1.685238945,   1.477695223, -0.2705217981,   2.149013188,   2.750015699, -0.0226856399,   -1.21831067, -0.0376230763,   1.038519415,   2.644961811,  0.0143031536, -0.8106704275,  0.0056161368,  -1.128722691, -0.0048185396, -0.6544140536);
s(01,0) = (   1.684523041,  0.5891231492,  -0.271786271,   2.576977581,   1.331007126, -0.0044823954,  -1.219088223, -0.0764820311,   2.646215186,   1.752951778,  0.0045303207, -0.3350988566,  0.0076445661,  -1.299361144, -0.0002254884,   2.089961246);
s(02,0) = (   1.684773108, -0.4750100803, -0.2718598727,   2.619353704,  -1.053393366,  0.0078486301,  -1.218872676, -0.0811766691,   2.776088739,  -1.427666705, -0.0080014539,  0.2702355739,  0.0074841737,  -1.316868632, -0.0016210545,   2.322946017);
s(03,0) = (   1.690091246,  -1.385630273, -0.2722763271,   2.240824872,  -2.677592532,  0.0186339358,  -1.221632724, -0.0464204081,   1.291841023,  -2.720306436, -0.0065078186,  0.7645232643,  0.0061732743,  -1.169638659, -0.0069581892, -0.3176453447);
s(04,0) = (    1.69951592,  -2.183556918, -0.2733118617,   1.465178833,  -2.772199821,  0.0394856661,  -1.227578797, -0.0056493841,  -1.097775678, -0.6061794192,  0.0047863319,   1.142888713,  0.0045610735, -0.8109927895, -0.0078297176,  -2.674022527);
s(05,0) = (   1.705276161,  -2.621537065, -0.2743826771,  0.5211730192,  -1.184351805,  0.0635603667,   -1.23190996,   0.004443722,  -2.746149363,   2.232850208,  0.0069044588,   1.322585964,  0.0042671556,  -0.299926078,   8.81291e-05,  -1.579665997);
s(06,0) = (   1.702776879,  -2.634736375, -0.2758767939,   -0.51543388,   1.178676901,   0.075154855,  -1.231750133, -0.0013408519,  -2.767997517,     2.2712545, -0.0077048083,   1.330501968,  0.0070917726,  0.2994502726,  0.0091306205,    1.56295649);
s(07,0) = (   1.693168727,  -2.181578598, -0.2783509331,  -1.476247596,   2.794764178,  0.0611630102,  -1.227863578,  0.0155571817,  -1.065738237, -0.6544453438, -0.0240668832,   1.147702681,  0.0134092821,  0.8242831446,  0.0067155095,    2.67317493);
s(08,0) = (   1.682425009,  -1.378919945, -0.2806301614,  -2.210631327,   2.654847281,  0.0303899011,  -1.223241001,  0.0625597777,   1.262381809,   -2.68375012, -0.0218134754,  0.7672651028,  0.0199251222,   1.168212929, -0.0081766809,  0.3318298793);
s(09,0) = (    1.67477072, -0.4712239437, -0.2800250709,  -2.581635184,   1.067524692,  0.0040121649,  -1.218823574,  0.0990004286,   2.737297101,  -1.448573319, -0.0040635418,  0.2737854532,  0.0217288536,   1.316022226, -0.0222998172,  -2.280008002);
s(10,0) = (   1.668864247,  0.5418570042, -0.2745378173,  -2.565619711,  -1.222248949, -0.0122207615,  -1.212328204,  0.0923527129,   2.697047849,   1.624868019,  0.0118833173,  -0.309111051,   0.016399627,   1.308898701, -0.0259775208,  -2.194663892);
s(11,0) = (   1.664686516,   1.435872783, -0.2660736865,  -2.140345995,  -2.715079758, -0.0210169085,  -1.204319941,  0.0456760813,   1.087511496,   2.649560583,  0.0082142428, -0.7959301199,  0.0062323102,   1.135249411,  -0.017875738,  0.5911144731);
s(12,0) = (   1.663252861,   2.136057074, -0.2590938042,    -1.4145936,  -2.668690431, -0.0324739271,  -1.198117855,  0.0023614086,  -1.107885029,  0.5303402997, -0.0078999965,  -1.125933965, -0.0030825089,  0.7901481647, -0.0084891164,   2.634652492);
s(13,0) = (   1.666360303,   2.543472886, -0.2572038932, -0.5417634851,   -1.21479787, -0.0461441012,  -1.197683422, -0.0078057175,  -2.656580614,  -2.152950612, -0.0169401346,   -1.29047407, -0.0069669835,  0.3134437507,  -0.005846593,   1.640002825);
s(14,0) = (   1.674125761,   2.591108625, -0.2607365905,  0.4570313063,   1.027229786, -0.0531197835,  -1.204048514,  0.0041261855,  -2.768653236,  -2.350861602, -0.0082239642,  -1.307892632, -0.0047211968, -0.2643404279, -0.0087069764,  -1.397445398);
s(15,0) = (   1.681756587,   2.227072391, -0.2663167894,    1.36837907,   2.638459094, -0.0440816973,  -1.212625317,  0.0002904572,  -1.292818515,  0.2989202034,  0.0083615075,   -1.16072134,   0.000679935, -0.7623298241, -0.0095644672,  -2.712834569);
s(16,0) = (  0.7040768625,  0.1329904272,   1.924980414,  0.3764221352,  0.1023799097,   1.608066592,  0.5293624749,   3.842088508,  0.0052310142,   1.500015106,   2.757130526,   0.212039463,  -2.075189829,  0.5770225818,   2.976203707,  0.6601105656);
s(17,0) = (  0.7011508503, -0.1411301101,   1.933206333,  0.3863947125, -0.1024582279,  -1.647254034,  0.5324039183,   3.827837058,   0.012404531,  -1.523569495,  -2.816973697, -0.2130784758,  -2.083553267,  0.5679269789,    2.92388371,  0.6081143117);
s(18,0) = (  0.7003168824, -0.3843222844,   1.960947633,  0.1381176743, -0.0981019034,  -3.915167273,  0.5334876659,   1.494630552,  -0.005434099,  0.7685858945,  -2.635107833, -0.5727305396,  -2.113723649,  0.2014062388,  -3.154743297,  -1.463766076);
s(19,0) = (  0.7059381412,  -0.395427906,   1.924419852, -0.1773517808,  0.1387797632,  -3.720658961,  0.5262163509,  -1.751956076, -0.0029177292,  0.4274695169,     3.0003732, -0.5517249417,  -2.076413686, -0.2442241451,  -2.690295035,   1.594636118);
s(20,0) = (  0.7129092308, -0.1397575878,   1.863884154, -0.4199929405,  0.0925183069,  -1.470235563,  0.5169871805,  -3.722090853,  0.0172440747,  -1.432448862,   2.594981247, -0.2077509076,  -2.012984684, -0.5970270897,   3.029624954, -0.7295757104);
s(21,0) = (  0.7067459283,  0.1353487501,   1.874840506, -0.4151407579, -0.0953488986,   1.488277755,  0.5233280388,  -3.736104209,  0.0249473534,   1.444992003,  -2.616771422,  0.2060948935,  -2.023798157, -0.5979210447,   3.033639345, -0.7467092232);
s(22,0) = (  0.6891172717,  0.3586056813,   1.941678999, -0.1539177793, -0.0868419178,   3.762265561,  0.5423372256,   -1.71667896,  0.0193107739, -0.4875150669,  -2.949067693,  0.5793677025,  -2.092049944, -0.2412616102,  -2.786961575,   1.548693813);
s(23,0) = (  0.6926515312,  0.3756801436,   1.956969848,  0.1447927642,  0.0860662587,   3.878057061,  0.5400319604,   1.544593973,  0.0025881125,  -0.698083492,   2.719882941,  0.5787938499,  -2.107968823,  0.2106294077,   -3.06877242,  -1.489759395);
s(24,0) = (     2.2748788,   1.887575807, -0.0231807309,   1.892896318, -0.3619033006, -0.7145288598,   3.164880947, -0.7436732797, -0.0074393133,  0.0690379766,   1.515609312,   3.662642245,   1.532269625,   3.661023358,  0.0077121072, -0.0709454191);
s(25,0) = (   2.270023625,   -1.88810008, -0.0174928781,   1.895873989,   0.363805959,  0.7088945792,   3.169629302, -0.7412863124, -0.0001440685, -0.0687591965,   -1.51614217,  -3.663258057,   1.526809792,   3.660827074,  0.0047226736, -0.0794871295);
s(26,0) = (   2.272735593,  -1.895610666, -0.0450409837,  -1.892403551, -0.3563683776,  0.7397677742,   3.151491491,  0.7662178032,  0.0077025517, -0.0597151021,   1.481229966,  -3.666759385,   1.567270797,  -3.655792567, -0.0327196863,  0.0733734597);
s(27,0) = (   2.274417353,   1.895864772, -0.0420494113,  -1.891454892,  0.3542183456,  -0.734556999,   3.149689608,   0.757731882,  0.0013243526,  0.0612588357,   -1.48851017,   3.668091447,   1.564108711,  -3.656722857, -0.0255616361,  0.0782020028);
s(28,0) = ( -0.5110307958,  0.0005123037,   6.277555699,  0.0067990992, -0.0011220114,  0.0001895495,  -2.075920655, -0.0073279694,  -0.005126667, -0.0001537866,  0.0007221462, -0.0005883041,   5.117473502,  0.0049692116,  0.0050491836,  0.0001672519);


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
declare author 		"AmbisonicDecoderToolkit, Henrik Frisk";
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
////route(n_inputs,n_outputs,outs) = m.bus(n_inputs)
////                               <: par(i,n_outputs,(0,gate_bus(i,outs)):>_


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
