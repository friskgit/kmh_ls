// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 10-Dec-2018 19:47:16

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
rs = (         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.085,         5.085,         5.085,         5.085,         5.576);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1);
gamma(1) = (   2.245861807,   1.933993153,   1.375216692,  0.6844196142);

// gain matrix
s(00,0) = (   1.442901721,   1.155317913, -0.2974519042,   1.969639784,   2.122851956, -0.2376408646, -0.9998344173, -0.1640364035,   1.200085003,   2.226393395, -0.0870548639, -0.5416779632,  0.0850019139, -0.9129222285,  0.0657684981, -0.0172442103);
s(01,0) = (   1.426050983,  0.2811240013, -0.2615654901,   2.198680288,  0.6048586366, -0.0888161923,   -0.98855677, -0.0696977739,   2.369018996,   0.785317311, -0.0095735715, -0.1363802854,  0.0507066496,  -1.005033497,  0.0469373229,   2.051613723);
s(02,0) = (   1.407321238, -0.5340810436, -0.2299125362,   2.149929483,  -1.086493298,  0.1186803896, -0.9755582047, -0.0854776807,    2.24833509,  -1.477697368,  0.0466575439,  0.2499119197,  0.0211888822, -0.9803876498, -0.0024201308,   1.793621218);
s(03,0) = (   1.389977125,  -1.350625892, -0.2370995791,   1.771418117,  -2.329137096,  0.2445591603, -0.9654587561, -0.1923670653,  0.6787853968,  -2.062109589,  0.0860960251,  0.6398093196,  0.0349520765, -0.8192339888, -0.0197044216, -0.7404771215);
s(04,0) = (   1.390823872,   -1.82411907, -0.2740853481,   1.216548556,  -2.163988013,   0.197773649, -0.9696023727, -0.2133686534,  -1.017417009, -0.2491770034,  0.0935696687,  0.8637029015,  0.0773171043, -0.5759379776,  0.0195742244,   -2.10824024);
s(05,0) = (   1.409846479,  -2.120207104, -0.3061530032,  0.4675040824, -0.9693471515,  0.1125968686, -0.9865078171, -0.1007361033,  -2.254857156,   1.833330835,  0.0648735787,   1.000293067,  0.1093424098, -0.2333871492,  0.0671034929,  -1.303133433);
s(06,0) = (   1.444192069,  -2.198087729, -0.3031939945, -0.5105525105,   1.009825788,  0.1203293858,  -1.012154625,  0.1184359973,  -2.298987952,   1.835484706, -0.0248038313,    1.03163148,  0.0975898652,  0.2288440011,  0.0648963689,   1.260249891);
s(07,0) = (   1.464376816,  -1.960335328, -0.2741630096,  -1.306754346,   2.331514349,  0.2252245507,  -1.025410209,  0.2347715552,  -1.014265499, -0.4220102215, -0.1218165681,  0.9147650837,  0.0597016706,  0.6094545528,  0.0047367686,   2.246174374);
s(08,0) = (   1.452883617,  -1.201591245, -0.2605648612,  -1.980641478,   2.231254214,   0.254960077,  -1.017161242,   0.185955777,   1.270382836,  -2.316508313, -0.1518762339,  0.5511923495,    0.04789146,  0.9277560512, -0.0564478612,  0.0408240925);
s(09,0) = (   1.424310933, -0.3538100004, -0.2844449577,  -2.185673723,  0.7690691335,  0.0839286543, -0.9995841669,  0.1221437578,   2.348983877, -0.9373382367, -0.0545490772,   0.149266486,  0.0834016363,   1.023183252, -0.0383318882,  -1.960468787);
s(10,0) = (   1.402193405,  0.5436101407,  -0.309019105,  -2.122008512,  -1.114161786, -0.1514833881, -0.9867405278,  0.1547761937,    2.13990211,   1.468908226,  0.0964859093, -0.2689751026,  0.1179254499,  0.9977233398,  0.0065528204,  -1.659262603);
s(11,0) = (   1.401414687,   1.270288073, -0.3040375782,  -1.835194542,  -2.309337538, -0.2628729192,  -0.985758118,  0.2392554951,   0.897911087,   2.163865575,  0.1898480699, -0.5983334473,  0.1122374209,  0.8714999001,  0.0150030173,  0.4113090338);
s(12,0) = (   1.422926852,   1.920904526, -0.2667337443,  -1.183690639,   -2.22147074, -0.1899657161, -0.9951682307,   0.245542866,  -1.131785983,  0.0926775208,  0.1594357655, -0.8824984486,  0.0617876674,  0.5713311395, -0.0398738606,   2.201464631);
s(13,0) = (   1.444597258,    2.21980659, -0.2455702055, -0.4138005855, -0.8444713662, -0.0760051641,  -1.003895472,  0.0897597325,  -2.303093175,  -1.999140516,  0.0337582114,  -1.009777338,  0.0286742742,  0.2040936333, -0.0890125901,   1.162911156);
s(14,0) = (   1.456888507,   2.243459031, -0.2609354578,   0.514040786,   1.122541448, -0.0739274532,  -1.008160497, -0.1403593552,  -2.265674986,  -1.824384464, -0.0997760497,  -1.021490294,  0.0396619299, -0.2427525421, -0.0752106847,  -1.356320817);
s(15,0) = (   1.454471602,   1.861174251, -0.2966314858,   1.416595287,   2.450529416, -0.2019421309,  -1.006393372, -0.2460774159, -0.7114091835,   0.860288394, -0.1417101084, -0.8578436578,   0.079733064, -0.6676962251,  0.0103130272,  -2.120930892);
s(16,0) = (  0.5688732939,  0.1608952165,   1.642648435,  0.2751363554,  0.2122408473,   1.229177791,  0.2725970097,   3.419553539,  -0.041501993,   1.410687906,   2.147177819,  0.0185414398,  -1.871350865,  0.0263540688,    2.82821169,   0.668655219);
s(17,0) = (  0.5708560307, -0.1788011589,   1.585691754,  0.2435348248, -0.2673000489,    -1.7123251,   0.275660319,   3.158728935,  -0.011198283,  -1.565855251,  -2.648365844, -0.0131596514,  -1.816196021,  0.0268853703,   1.971445797,  0.1034693995);
s(18,0) = (  0.5705503365, -0.3407230957,   1.545434978,  0.1579152804,  -0.195583673,  -3.155071533,  0.2719353201,    1.13741355, -0.0383684253,  0.7875925726,  -1.960954019, -0.1041631723,  -1.770966211,  0.0232220144,  -2.746594094,  -1.314472085);
s(19,0) = (  0.5967615116, -0.3809628815,   1.590328163,  -0.156088295,  0.2583639322,  -3.089857051,  0.2539631375,  -1.552529361, -0.0124446438,   0.368408092,   2.435562488, -0.0511347675,  -1.828541453,  0.0334868192,  -2.391487641,   1.525450692);
s(20,0) = (  0.5965088825, -0.1018349483,   1.564111267, -0.3571219934,   0.258204863,  -1.341071826,  0.2578611785,  -3.223937372,  0.0137700866,  -1.412114781,   2.085998765,  0.0386972892,  -1.803481534, -0.0672889132,   2.793156823, -0.7038149131);
s(21,0) = (  0.5814843844,  0.2113603923,   1.493613184, -0.3621794412, -0.2815622255,   1.291515521,  0.2631830466,  -2.970466553,  0.0082447143,   1.449450748,  -2.189964465,  0.0322910016,  -1.718405999, -0.0989571237,   2.357290505, -0.4665019333);
s(22,0) = (  0.5839328421,  0.2462847023,   1.570847458, -0.2271823966, -0.3219902937,   3.127193091,  0.2595411158,  -1.636992164,  0.0579085663, -0.0850968495,  -2.571695472,  0.0173985505,   -1.79960251, -0.0271200131,   -1.98404002,   1.511347303);
s(23,0) = (  0.5702552499,  0.2758953941,   1.679879263,   0.186415454,  0.2920712898,   3.452736901,  0.2697599938,   1.356597153,  0.0211961851, -0.5596478727,   2.290183263, -0.0139864078,  -1.910591606,  0.0094807716,  -2.691696971,  -1.478917756);
s(24,0) = (   1.886622179,   1.464843374,  0.1803383559,   1.476461021, -0.3721713595, -0.1509795527,   2.769647183, -0.1862938179,  0.0077383386, -0.0013952965,   1.326331669,   3.205866346,    1.06646625,   3.208429046, -0.0298036709,   0.002547363);
s(25,0) = (    1.89718812,  -1.473905534,   0.120114616,   1.468558527,  0.3810080623,  0.2156382242,   2.750735209, -0.1825366208, -0.0276667692, -0.0119947764,  -1.345469349,  -3.197365837,   1.139295014,   3.189712769,  0.1122997573,  0.0049129642);
s(26,0) = (   1.887178625,  -1.463187081,  0.1328679132,  -1.458619247, -0.3898250037,  0.1638117718,   2.740666783,  0.1596919652, -0.0055023945, -0.0091291272,   1.382445565,  -3.202757204,   1.143924343,  -3.195732975,  0.0105453827,  0.0118494583);
s(27,0) = (   1.894292439,    1.47290771,  0.1135403142,  -1.484580793,  0.3832840458, -0.1923016982,   2.748636123,   0.257110346,  0.0273157781, -0.0274963054,  -1.300286533,   3.195534725,   1.150659652,  -3.198762451, -0.1187304454,  0.0057958108);
s(28,0) = ( -0.3915099912,  0.0078067383,   5.324638551,  0.0100066946,  0.0084145192, -0.0118887961,  -1.740013299, -0.0145226924, -0.0041143967,  0.0025496151, -0.0114090141,  0.0045701248,   4.268374003,  0.0058199897,  0.0064055269, -0.0014760885);


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
