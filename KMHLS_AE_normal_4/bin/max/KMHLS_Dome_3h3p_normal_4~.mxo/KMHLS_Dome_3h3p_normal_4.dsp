// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 15-May-2019 19:49:24

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_3h3p_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMHLS_Dome_3h3p_pinv_energy_limit_050_rV_max_rE_2_band
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
declare name "KMHLS_Dome_3h3p_normal_4";

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
s(00,0) = (   1.066508575,  0.8415210563, -0.5669402555,   1.228074221,    1.48683233, -0.1323904512, -0.3359411588, -0.2005495411,  0.5630283996,   1.392565463, -0.0762701907, -0.3634965176, -0.0626158545, -0.4969845495, -0.0369510399, -0.3440189573);
s(01,0) = (   1.065705942,  0.3336288292,  -0.566692891,   1.482728388,  0.7198417963, -0.0479571651, -0.3369109297, -0.2708800042,   1.434814721,  0.9228146063, -0.0382060743, -0.1528506307, -0.0614555647, -0.5585525073, -0.0874954702,   1.100885097);
s(02,0) = (     1.0665035, -0.2697800632, -0.5682187603,    1.50834983, -0.5697014055,  0.0419378073, -0.3356503756, -0.2784267507,   1.505555771, -0.7519404914,  0.0278889368,  0.1227732133, -0.0618719976, -0.5650962767, -0.0926712184,   1.223131311);
s(03,0) = (   1.071319925, -0.7883569236, -0.5727268391,    1.28304173,  -1.448817893,  0.1218270894, -0.3341556225, -0.2155405135,  0.7009000481,  -1.432507922,  0.0788136721,  0.3437761533, -0.0632597288, -0.5131329473,  -0.046700683, -0.1675927446);
s(04,0) = (   1.078655809,  -1.249738283, -0.5782126097,  0.8307933894,  -1.500508842,  0.2066984411, -0.3340832472, -0.1165798232, -0.5952145637, -0.3191530373,  0.0884826953,  0.5020655553, -0.0647667855,  -0.367274171,  0.0319792144,   -1.40832977);
s(05,0) = (   1.082638583,  -1.507644061, -0.5806639723,  0.2932624059, -0.6410858221,  0.2657517724, -0.3352658735, -0.0351667056,  -1.489821043,   1.175953399,  0.0410280057,  0.5702214875, -0.0650833974, -0.1384860663,  0.0914380142, -0.8317180965);
s(06,0) = (   1.080687707,  -1.516745121, -0.5800036348, -0.2905276881,  0.6383341213,  0.2747853724, -0.3361372308,  0.0364638732,  -1.502374355,   1.196384937, -0.0401177824,  0.5727925867, -0.0634259796,  0.1385217698,  0.0978392075,  0.8235426952);
s(07,0) = (   1.074103898,  -1.250921264,  -0.578005755, -0.8373234244,   1.512991834,  0.2205886452, -0.3360264944,  0.1228072142, -0.5794030857, -0.3440634601, -0.0994043809,  0.5031681886, -0.0598898997,   0.373427026,  0.0404374955,   1.408412313);
s(08,0) = (   1.066521157,  -0.784840946, -0.5750823022,  -1.265395761,   1.436451036,  0.1277235706,  -0.336068397,  0.2210441123,  0.6835669446,  -1.412708306,  -0.093863215,  0.3449809762, -0.0561309739,  0.5132336168, -0.0451390629,   0.175415263);
s(09,0) = (   1.060126762, -0.2656231584, -0.5697887863,  -1.485915112,  0.5767712962,  0.0371185394, -0.3370634211,  0.2833073999,   1.484023103, -0.7625465705, -0.0347992393,  0.1257349525, -0.0544490907,  0.5661668714,  -0.102209759,  -1.200356246);
s(10,0) = (   1.053882112,  0.3080719793, -0.5604518396,  -1.475698316, -0.6618380354, -0.0499078466, -0.3382589487,  0.2770185624,   1.462754081,  0.8555541798,  0.0447083977, -0.1402741152,  -0.055972398,  0.5639369417, -0.1031733008,  -1.156120087);
s(11,0) = (   1.049208012,  0.8157231105, -0.5510746899,  -1.222460354,  -1.468073126,  -0.125843034, -0.3376866816,  0.2026634511,   0.590264968,   1.395023803,  0.0881630137, -0.3582489506, -0.0601840415,  0.5010239174, -0.0454017441,  0.3102110256);
s(12,0) = (   1.048010982,   1.219048475, -0.5467580917,   -0.80013884,  -1.441725855, -0.1951421396, -0.3350003574,  0.1086540508, -0.6000545197,  0.2791911118,  0.0770247482, -0.4964434084, -0.0647731864,  0.3590598691,  0.0324728376,   1.386105288);
s(13,0) = (   1.051446173,   1.457892415,  -0.549673373, -0.3041261267,   -0.65526248, -0.2443716708, -0.3320856631,   0.034112184,  -1.439810879,  -1.133623221,   0.026884529, -0.5590296774, -0.0674341344,  0.1450662061,  0.0850253384,  0.8626594435);
s(14,0) = (   1.058525521,   1.487485791, -0.5577206354,   0.257038776,  0.5562561367, -0.2548783484, -0.3311644558, -0.0301461487,  -1.500751454,  -1.237817078, -0.0369051585,  -0.564776606, -0.0673306997, -0.1225271425,  0.0868737543, -0.7361047692);
s(15,0) = (   1.064477328,   1.275311132, -0.5644948296,  0.7741272795,   1.426620021, -0.2139289244,  -0.333078967, -0.1038464523, -0.7008259225,  0.1573595082, -0.0765473295, -0.5085650783, -0.0651563233, -0.3466183809,  0.0374485961,  -1.428152482);
s(16,0) = ( -0.7166358771, -0.1326066722,    3.22719009, -0.2711227479, -0.0292199419,   1.128038694,  -1.391924593,   2.672533983, -0.0959038745,  0.7901120185,   1.545502191, -0.0536939037, -0.5770146595, -0.0777997448,   1.685114348,  0.3468996628);
s(17,0) = ( -0.7269276148,   0.133452269,   3.249789116, -0.2638570571,  0.0318732619,  -1.156052218,  -1.403703923,   2.662164769, -0.0901595456, -0.8025295382,   -1.57986194,  0.0574307006, -0.5775536606, -0.0809634022,   1.655217294,  0.3197342361);
s(18,0) = ( -0.7603334897,  0.2801812056,    3.33381121, -0.1128087232,  0.0282645008,  -2.730346488,  -1.454718334,   1.043478913,  0.1019662019,  0.4043574444,  -1.478218693,  0.0901797458, -0.5782451206, -0.0454785292,   -1.78723678, -0.7712557776);
s(19,0) = ( -0.7163627443,  0.2454374378,   3.228190285,  0.1209532769, -0.0162130578,  -2.586024064,  -1.394322011,  -1.217650589,  0.0890979297,  0.2254408397,   1.678397742,  0.0782969536, -0.5774252008,  0.0464615662,  -1.526258589,  0.8394368368);
s(20,0) = ( -0.6437676101,  0.1077954122,    3.05144471,  0.2224837349, -0.0295388159,   -1.02410819,  -1.291766762,  -2.568730161, -0.0890600875, -0.7538852129,   1.452824625,  0.0386263492, -0.5755123971,   0.046349647,   1.710403951, -0.3834066247);
s(21,0) = ( -0.6571426348, -0.1136948697,   3.078911039,  0.2273960253,  0.0286246692,   1.039615711,  -1.304854307,  -2.580194131, -0.0857117179,  0.7605999237,  -1.466030154, -0.0427753425, -0.5763559392,  0.0482041763,   1.713039514, -0.3917978608);
s(22,0) = (  -0.739376736, -0.2714496753,   3.267683326,  0.1310586505,  0.0431136642,   2.618275133,  -1.408754422,  -1.197188646,  0.1033520748, -0.2570356184,   -1.65178287, -0.0696993539, -0.5790103923,  0.0464936258,  -1.580628156,   0.816164397);
s(23,0) = ( -0.7573455346, -0.2781215504,   3.317290101, -0.1144411456, -0.0384076351,   2.702276991,  -1.440738263,   1.076745858,  0.1031060349, -0.3673370542,   1.526392734, -0.0828596271, -0.5783640447, -0.0449916803,  -1.738361888, -0.7849026676);
s(24,0) = (   6.479036171,   1.567010914,  -11.21353452,   1.572260291, -0.2417585038,  -1.228392541,   10.39068255,  -1.247043537, -0.0035501776,  0.0347787555,  0.8611087068,   2.454045446,  -2.181759882,   2.455185154,  0.0036818449, -0.0356685225);
s(25,0) = (   6.471816274,   -1.56727305,  -11.20046943,   1.574261217,   0.242709833,   1.225575401,   10.38551494,  -1.246849671, -0.0002415133, -0.0346393654, -0.8613751361,  -2.454353352,  -2.182376856,   2.455642254,  0.0025355455, -0.0395477518);
s(26,0) = (   6.477964567,  -1.576718678,  -11.22446465,  -1.572525998, -0.2389910423,   1.250169188,   10.38398783,   1.259315417,  0.0040207549, -0.0295977839,  0.8439190338,  -2.460557561,  -2.164259296,     -2.453125, -0.0165340519,  0.0364909169);
s(27,0) = (   6.474013138,   1.576845731,   -11.2127477,  -1.571539578,  0.2379160263,  -1.247563801,   10.37554509,   1.254072838,  0.0004926972,  0.0303696507, -0.8475591362,   2.461223592,  -2.163727397,  -2.453034904, -0.0126066093,  0.0392968143);
s(28,0) = (  -16.16549124,  0.0002561519,   36.76228323,  0.0033995496, -0.0005610057,   9.47747e-05,  -27.41250451, -0.0036639847, -0.0025633335,  -7.68933e-05,  0.0003610731,  -0.000294152,   11.71975139,  0.0024846058,  0.0025245918,    8.3626e-05);


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
