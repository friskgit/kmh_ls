// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 21:05:37

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_3h3p_allrad_5200_rE_max_2_band.dsp
// description = KMHLS_Dome_3h3p_allrad_5200_rE_max_2_band
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
declare name "KMHLS_Dome_3h3p_normal_6";

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
s(00,0) = (  0.0459563249,    0.06219309,  -0.016333785,  0.1052099765,  0.1362624689, -0.0123695002,   -0.05542497, -0.0250191186,  0.0751097172,  0.1726379014, -0.0208168335, -0.0257282954, -0.0026487788, -0.0445264654, -0.0174828059, -0.0048525383);
s(01,0) = (  0.0407215932,  0.0144763767, -0.0231432847,  0.1074539708,  0.0368024791, -0.0053357303, -0.0497177373,  -0.044635641,  0.1340064779,  0.0610562883, -0.0112400987, -0.0066556484,   0.013127613, -0.0495685949, -0.0476307881,  0.1434975149);
s(02,0) = (  0.0460748692,  -0.030494917, -0.0164176573,  0.1186753133, -0.0752845231,  0.0090050256,  -0.055592276, -0.0266199991,  0.1365851732, -0.1188697352,  0.0176207005,  0.0133383747, -0.0025157714, -0.0498326181, -0.0209962986,  0.1257620019);
s(03,0) = (  0.0407642043, -0.0658612532, -0.0231502139,  0.0862913081, -0.1341858253,  0.0278374147, -0.0498332699, -0.0353624755,  0.0367168957, -0.1446797337,  0.0477104527,  0.0304538412,  0.0132065412, -0.0398224301,  -0.011186136, -0.0585482161);
s(04,0) = (  0.0459866893, -0.1052528902, -0.0163569837,  0.0622286799, -0.1363198873,   0.025018373, -0.0553912833, -0.0123649615, -0.0751247114, -0.0048721196,  0.0207885148,  0.0445058209,   -0.00271694, -0.0256900992,  0.0174974695, -0.1726866122);
s(05,0) = (  0.0407129561, -0.1074496676, -0.0231269026,  0.0144697749, -0.0367814593,  0.0446548622, -0.0497562501, -0.0053307212, -0.1340007173,  0.1434855217,  0.0112212747,  0.0495788011,  0.0132180823, -0.0066359421,  0.0476705908, -0.0610175647);
s(06,0) = (  0.0460751174, -0.1186703607, -0.0164329252, -0.0304779314,  0.0752465203,  0.0266297539, -0.0555594971,  0.0090017427, -0.1365936625,  0.1257974221, -0.0176106969,  0.0498060759, -0.0025460911,  0.0133296551,   0.020998267,  0.1188204588);
s(07,0) = (  0.0408087998,  -0.086374975, -0.0231602629, -0.0659043807,  0.1342776852,    0.03531943, -0.0498164181,   0.027816703, -0.0367921925, -0.0585142625, -0.0476372829,   0.039830036,  0.0130812912,  0.0304188818,  0.0111589611,  0.1448104745);
s(08,0) = (  0.0459625191, -0.0622023486, -0.0163209514, -0.1052328951,  0.1362831189,  0.0123543835, -0.0554386282,  0.0250319789,  0.0751287253, -0.1726669745, -0.0207943054,  0.0257081325, -0.0026032866,   0.044479412, -0.0175203754,  0.0048451373);
s(09,0) = (  0.0407296946, -0.0144742459, -0.0231015466, -0.1074817423,  0.0367945058,  0.0053186859, -0.0497505427,  0.0445534641,  0.1340445321,  -0.061042003, -0.0111916567,  0.0066446985,  0.0131036552,   0.049600517, -0.0475474056, -0.1435366495);
s(10,0) = (  0.0460418309,  0.0304706139, -0.0164273204, -0.1186111118, -0.0752415173, -0.0089681128, -0.0555887971,  0.0266893431,  0.1365347964,  0.1188273346,     0.0175574, -0.0133487941, -0.0024197083,  0.0498164288, -0.0210932989, -0.1257503336);
s(11,0) = (  0.0408427644,  0.0659466632, -0.0232298428, -0.0863969639, -0.1343242726, -0.0278496037, -0.0497167154,  0.0353599356,  0.0367501693,  0.1448001119,  0.0476593836,   -0.03037219,  0.0129561583,  0.0397364523, -0.0111611299,  0.0586030622);
s(12,0) = (  0.0459318927,  0.1051992492, -0.0162734851,  -0.062160868, -0.1362228195, -0.0249916812, -0.0554979967,  0.0123406664, -0.0751437355,  0.0047786171,  0.0207915806, -0.0445422546, -0.0025229245,  0.0257520112,  0.0174808034,  0.1726314549);
s(13,0) = (  0.0407238797,  0.1074623049, -0.0231458448, -0.0144839717,  -0.036814385, -0.0446518802, -0.0497367568,  0.0053446837, -0.1340098509, -0.1434879446,  0.0112451892, -0.0495934898,  0.0131653961,  0.0066472068,  0.0476502598,    0.06106787);
s(14,0) = (   0.046076518,   0.118668385, -0.0164343712,  0.0304883564,  0.0752726329, -0.0266352822, -0.0555538555, -0.0089809397, -0.1365777442, -0.1257585468, -0.0175738266, -0.0497911804, -0.0025442788, -0.0133415554,  0.0210197553, -0.1188545692);
s(15,0) = (  0.0407867195,  0.0863221348, -0.0231753898,  0.0658866476,  0.1342300712, -0.0353719676, -0.0497923495,  -0.027842427, -0.0367279138,  0.0585701646, -0.0476932083, -0.0397773963,  0.0131488713,  -0.030409231,  0.0111996747, -0.1447283945);
s(16,0) = (  0.0380113964,   0.070419014,  0.0713918737,  0.0407315152,  0.0693638888,  0.1222457219,  0.0240182792,  0.0677860839, -0.0373808763,  0.0052889348,  0.1202940882,  0.0935748742, -0.0549737819,  0.0452741779, -0.0702121629, -0.0629687609);
s(17,0) = (  0.0306211721,  0.0165528978,  0.0533641272,  0.0680427388,  0.0322919601,  0.0281496081,  0.0055090701,  0.1100413943,  0.0644991987,  0.0382097096,  0.0575037652,  0.0195675694, -0.0632949428,  0.0646973498,  0.1082953167,  0.0476979946);
s(18,0) = (  0.0380027528, -0.0407191393,  0.0713844673,  0.0704004065, -0.0693433587, -0.0677757394,  0.0240351947,  0.1222313142,  0.0373720446, -0.0629532425,  -0.120279476, -0.0452842568, -0.0549494325,   0.093594237,  0.0702060563, -0.0052855645);
s(19,0) = (  0.0306312963, -0.0680621922,  0.0533828762,  0.0165509432, -0.0322841511, -0.1100701746,  0.0055179064,  0.0281504572, -0.0645165278,   0.047710903, -0.0574916937, -0.0647155286,  -0.063298276,  0.0195817778, -0.1083150329,  -0.038201093);
s(20,0) = (  0.0379997646, -0.0703880089,  0.0713776112, -0.0407267604,  0.0693578668, -0.1222077831,  0.0240365217, -0.0677757203, -0.0373438941, -0.0053327195,  0.1202824868, -0.0935813031,   -0.05492177, -0.0452666239,  -0.070170792,  0.0629598014);
s(21,0) = (  0.0306194443, -0.0165485808,  0.0533547184, -0.0680444218,  0.0322900754, -0.0281370846,  0.0054927342, -0.1100303216,   0.064507223, -0.0382186252,  0.0574860077, -0.0195536035, -0.0632990924,  -0.064664791,  0.1082990353, -0.0477018332);
s(22,0) = (  0.0380205423,  0.0407218497,  0.0714204721, -0.0704326307, -0.0693497977,  0.0677810795,   0.024061545,  -0.122280171,   0.037406373,  0.0629670619, -0.1202847842,  0.0452942272, -0.0549330057, -0.0936234551,  0.0702544345,  0.0052570658);
s(23,0) = (  0.0306213415,  0.0680327787,  0.0533733621, -0.0165659805, -0.0323141482,  0.1100449557,  0.0055321232, -0.0281700179, -0.0644711985, -0.0476547056, -0.0575361199,  0.0647337729,  -0.063280135, -0.0195808404, -0.1082721746,  0.0382310846);
s(24,0) = (  0.0343548857,  0.0398818491,   0.088532239, -0.0151160013, -0.0138234886,  0.0947999705,  0.1063573938, -0.0365986826,  -0.016917791, -0.0038678002, -0.0346706227,  0.1384719347,  0.0837237586, -0.0552506736, -0.0417347168,  0.0062344826);
s(25,0) = (  0.0343682304,  0.0151120816,  0.0885702172,  0.0398855512,  0.0138143112,  0.0365897044,   0.106411387,  0.0948148679,  0.0169033884,  0.0062242632,  0.0346489343,  0.0552367398,  0.0837755844,  0.1385059836,  0.0417001364,  0.0038560681);
s(26,0) = (  0.0343613365, -0.0398955896,  0.0885481856,  0.0151123496, -0.0138333298, -0.0948298604,   0.106375245,  0.0365866404, -0.0169290993,  0.0038815699, -0.0346910407, -0.1385113125,  0.0837373991,  0.0552231536, -0.0417516503,  -0.006253105);
s(27,0) = (  0.0343735455, -0.0151262899,  0.0885795459, -0.0398976973,  0.0138334818,  -0.036619387,  0.1064117692, -0.0948377101,  0.0169098118, -0.0062378497,  0.0346896853, -0.0552722961,  0.0837617606, -0.1385268253,  0.0417159904, -0.0038529319);
s(28,0) = (  0.0116283448,   1.24741e-05,  0.0343458244,   -6.0311e-06,    1.0774e-06,   3.40799e-05,  0.0554784962,  -1.62779e-05,    5.2644e-06,    2.5671e-06,     3.019e-06,    6.2012e-05,  0.0740768677,  -2.90406e-05,    1.5711e-05,    1.6007e-06);


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
