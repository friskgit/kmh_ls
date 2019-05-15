// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 18-Apr-2019 14:55:18

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
gamma(1) = (             1,  0.8611363116,  0.6123336207,   0.304746985);

// gain matrix
s(00,0) = (  0.0451242667,  0.0707429053, -0.0169584296,  0.0970283879,   0.145695123,  -0.015562004, -0.0546592729, -0.0251614829,   0.046934945,  0.1618062828, -0.0257567013, -0.0298221862, -0.0010001545, -0.0417483188, -0.0143119794, -0.0529030131);
s(01,0) = (  0.0407611646,  0.0240705031,  -0.023531261,  0.1057768072,  0.0601762198, -0.0093175714, -0.0496922946, -0.0448848897,  0.1252532441,  0.0970592387, -0.0195834972, -0.0110642116,  0.0137764659, -0.0488263958, -0.0461333512,  0.1218701485);
s(02,0) = (  0.0474972114, -0.0200812517, -0.0154586829,  0.1246030601, -0.0504569935,  0.0057809943, -0.0571696744, -0.0249199872,  0.1520361871,  -0.082122957,  0.0116110957,   0.008742937,  -0.005187601, -0.0515693698, -0.0211652561,  0.1567158914);
s(03,0) = (  0.0408255198, -0.0587732385, -0.0236447732,   0.091439155, -0.1266799651,  0.0251163801, -0.0498905704, -0.0387578136,  0.0578560888, -0.1546017945,  0.0460785625,  0.0271913112,  0.0141909408, -0.0422598085, -0.0205389633, -0.0221599503);
s(04,0) = (  0.0458837321, -0.0998511781, -0.0186894622,  0.0701382309, -0.1462149878,  0.0279181776, -0.0555825546, -0.0179634999, -0.0527796371, -0.0452091088,  0.0298538483,  0.0433693041,  0.0013038935, -0.0301430849,  0.0144393927, -0.1666315767);
s(05,0) = (  0.0412830359, -0.1075533969, -0.0238195688,  0.0224882187, -0.0563785351,  0.0456690347, -0.0504663215, -0.0086800189,  -0.128821647,  0.1281579959,  0.0182759292,  0.0497520417,  0.0141515627, -0.0103759639,  0.0473881566, -0.0913545494);
s(06,0) = (  0.0475581666, -0.1241415242, -0.0174064037,  -0.023448789,  0.0585899133,  0.0289495957, -0.0574618985,  0.0081857837, -0.1491767864,  0.1494961656, -0.0169030741,  0.0525061933, -0.0019129274,  0.0105500761,  0.0245960741,  0.0944233535);
s(07,0) = (  0.0419006115, -0.0918926062, -0.0242020015, -0.0630525028,  0.1329004471,  0.0383728024, -0.0511114941,  0.0273716501, -0.0512837518, -0.0366932495, -0.0487247945,  0.0424183958,  0.0142330973,   0.029136868,  0.0163560596,  0.1548394413);
s(08,0) = (  0.0449610953, -0.0661982288,  -0.016762492, -0.0996666919,  0.1405012687,  0.0138843228, -0.0544748888,  0.0257576653,  0.0592719003, -0.1666911152, -0.0236990606,  0.0277516743, -0.0011684029,  0.0428594791, -0.0173965362,  0.0310662637);
s(09,0) = (  0.0399788659, -0.0195304394, -0.0230375985, -0.1046513612,  0.0492979729,  0.0072978203, -0.0487645772,  0.0443202124,  0.1273565155, -0.0808236592, -0.0153666062,  0.0089660369,  0.0134882707,  0.0483209126, -0.0467611848, -0.1304839742);
s(10,0) = (  0.0461617648,  0.0234619925, -0.0167084219, -0.1204773699, -0.0587132926, -0.0082194271, -0.0558078502,  0.0276570653,  0.1446174077,  0.0948784147,   0.016993767, -0.0105505143, -0.0021433779,  0.0508948231, -0.0231844722, -0.1445630988);
s(11,0) = (  0.0433828096,  0.0659722005, -0.0183825709, -0.0948528994, -0.1385478592, -0.0175209744, -0.0527041228,  0.0281516445,  0.0514637983,  0.1601077979,   0.029928229, -0.0285950127,  0.0026006186,  0.0416853273, -0.0157651825,  0.0410878435);
s(12,0) = (  0.0387064769,  0.0855996345, -0.0224561947,  -0.057619945, -0.1229567887, -0.0363186694, -0.0472882281,  0.0247273921, -0.0499666684,  0.0306802396,  0.0449147322, -0.0395744649,  0.0134922315,  0.0266354919,  0.0175900174,  0.1466719696);
s(13,0) = (  0.0465317867,  0.1213047735, -0.0139538947, -0.0239531136, -0.0599025434, -0.0213728819, -0.0558293515,  0.0071390068,  -0.145095156, -0.1441337774,  0.0143749068, -0.0493711882, -0.0071147341,  0.0105535747,  0.0161371121,  0.0966904283);
s(14,0) = (  0.0404699282,   0.105980887, -0.0231931119,  0.0192923213,  0.0486768764, -0.0446558827, -0.0493727006, -0.0067672833, -0.1291420471, -0.1326568099, -0.0140899296, -0.0489361989,  0.0133918133, -0.0088437891,  0.0474624971, -0.0797288888);
s(15,0) = (  0.0407522993,   0.091741054, -0.0235523148,   0.057925282,  0.1254849816,  -0.038495403, -0.0497887242, -0.0251407791,  -0.059797928,   0.018327309, -0.0461599717, -0.0423947801,  0.0140152429,   -0.02680014,  0.0199173683, -0.1547987254);
s(16,0) = (  0.0404755738,  0.0232955908,  0.0760286689,  0.0829650673,  0.0437161468,  0.0392098396,  0.0257393827,  0.1425448415,  0.0698333263,  0.0485006568,  0.0764257579,  0.0266525509, -0.0578780974,  0.1061954093,  0.1233410524,  0.0425639888);
s(17,0) = (  0.0321152551, -0.0344836633,  0.0562496943,  0.0643617613, -0.0625568638, -0.0555134136,  0.0068731543,  0.1049508434,  0.0408372344,  -0.062680386, -0.1054370502, -0.0325943646, -0.0644693382,  0.0639232818,  0.0707696058,  0.0038544517);
s(18,0) = (  0.0374055911, -0.0776465268,  0.0701143454,  0.0207807048, -0.0402877618, -0.1329189811,  0.0235922674,  0.0348734847, -0.0681133417,  0.0448451761, -0.0703248626, -0.0983452803, -0.0528684773,  0.0235595049, -0.1199472793, -0.0472322174);
s(19,0) = (  0.0317779492, -0.0641313184,  0.0554719974, -0.0336948328,  0.0615871892, -0.1043094927,  0.0062667457, -0.0539374139, -0.0417371408,  0.0057115325,  0.1033305972, -0.0629192676,  -0.064254195, -0.0310701998, -0.0724368768,  0.0625145192);
s(20,0) = (  0.0384735307, -0.0226347173,  0.0722882503, -0.0791126253,  0.0427290927, -0.0385333295,  0.0246467857, -0.1357616506,  0.0676189722, -0.0482216153,   0.075643023, -0.0270854722, -0.0544291838, -0.1010001279,  0.1189246105, -0.0428499906);
s(21,0) = (  0.0257030829,   0.022357459,  0.0461948226, -0.0539708721, -0.0433690384,  0.0376354134,  0.0086520878, -0.0901034527,  0.0435425858,  0.0508219673, -0.0761288667,  0.0255622804, -0.0495124416, -0.0589957027,   0.075833757, -0.0211109254);
s(22,0) = (   0.031281047,  0.0632923314,  0.0550108526, -0.0322749382, -0.0595767566,  0.1037808208,  0.0073576037, -0.0517575016, -0.0419578008, -0.0063776305, -0.1001371654,  0.0644681295, -0.0621276339, -0.0300374726, -0.0736651603,   0.061405121);
s(23,0) = (  0.0444879484,  0.0902149648,  0.0816028067,  0.0304571824,  0.0558699982,  0.1517973532,  0.0227154878,  0.0486782852, -0.0696303747, -0.0326837478,  0.0932679136,  0.1067271428, -0.0684279359,  0.0279746311, -0.1225543714, -0.0570607794);
s(24,0) = (   0.024950364,  0.0211545176,  0.0656088516,  0.0217611917,  0.0185860124,  0.0512099756,  0.0829071375,  0.0526239699,  0.0005996448,  0.0079158468,  0.0465481788,  0.0773368418,  0.0734436898,  0.0793284565,  0.0014660809, -0.0071390238);
s(25,0) = (  0.0341278765, -0.0223482302,  0.0879436426,  0.0359295839, -0.0191079452, -0.0538099609,  0.1057034124,  0.0851345128,  0.0103683719, -0.0072702693, -0.0475852104, -0.0805311807,  0.0835034546,  0.1236729804,   0.025398557, -0.0006793222);
s(26,0) = (  0.0340686883, -0.0360210073,  0.0877469248, -0.0223415236,  0.0192173694, -0.0852277699,  0.1053520488, -0.0538309155, -0.0107599187,  -0.000135485,  0.0478923619, -0.1235207157,  0.0830633053, -0.0806420311, -0.0261788064,  0.0075846199);
s(27,0) = (  0.0424916651,  0.0361124822,  0.1082624699, -0.0356745864, -0.0186310144,  0.0855052787,  0.1263397231, -0.0842805046,  0.0002870544,  0.0007512416, -0.0462631009,  0.1240391971,  0.0924145907, -0.1218422706,  0.0004444702, -0.0006128184);
s(28,0) = (  0.0102900397,    1.9657e-06,  0.0304481074,   -8.5177e-06,    1.1512e-06,    5.6355e-06,  0.0493629167,  -2.33718e-05,   -1.7518e-06,      6.31e-07,    3.4689e-06,   1.10318e-05,  0.0662800898,  -4.28226e-05,     -5.29e-06,    1.0543e-06);


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
