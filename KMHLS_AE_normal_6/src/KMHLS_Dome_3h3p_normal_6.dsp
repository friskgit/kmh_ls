// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 03-Dec-2018 21:17:19

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
rs = (         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.085,         5.085,         5.085,         5.085,         5.576);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1);
gamma(1) = (             1,  0.8611363116,  0.6123336207,   0.304746985);

// gain matrix
s(00,0) = (  0.0394866116,  0.0519228334, -0.0250128604,  0.0913057222,  0.1156232805, -0.0250308437, -0.0481018677, -0.0429812631,  0.0688310339,  0.1509013957, -0.0483776533,  -0.024264611,  0.0175990646, -0.0427285539,  -0.027189593,  0.0031030061);
s(01,0) = (  0.0373475412,  0.0144140317, -0.0235070757,  0.0984321175,  0.0367181648, -0.0057987614, -0.0455391679, -0.0464480976,  0.1225290872,  0.0611025555, -0.0125146833, -0.0068264971,  0.0164224673, -0.0460293639, -0.0510419851,  0.1307991432);
s(02,0) = (  0.0446755876, -0.0278804413,  -0.018629594,  0.1156078598, -0.0690486854,  0.0105931689, -0.0551132203, -0.0318727005,  0.1346317631, -0.1095552786,  0.0220314779,  0.0129398787,  0.0015555148, -0.0521957383, -0.0272433116,  0.1267827846);
s(03,0) = (  0.0386870822, -0.0602918031, -0.0245311328,  0.0834859848, -0.1254244381,  0.0289366703, -0.0471734135, -0.0393963978,  0.0415360226, -0.1416670478,  0.0521945715,  0.0281510607,   0.017443871, -0.0390667688, -0.0161654095, -0.0447848715);
s(04,0) = (  0.0384801821, -0.0861693548, -0.0181137353,  0.0560387542, -0.1210526667,  0.0290120705, -0.0474389303, -0.0170773559, -0.0537259827, -0.0235969597,  0.0308190633,  0.0396776043,  0.0050476471, -0.0256761691,  0.0179631843, -0.1479492198);
s(05,0) = (  0.0383735139, -0.1001423487, -0.0242494167,  0.0202306158, -0.0509714852,   0.047463243, -0.0468072082, -0.0089290974, -0.1208345966,  0.1218401287,   0.019390164,  0.0468607198,  0.0171004114, -0.0094964516,  0.0504461997, -0.0833154966);
s(06,0) = (   0.044118517, -0.1157432811, -0.0198778455, -0.0202146242,  0.0508526564,  0.0355767445, -0.0544274156,  0.0082006522, -0.1409351839,  0.1444284261, -0.0175593483,  0.0527915458,  0.0042994838,  0.0094045086,   0.033838186,  0.0828805577);
s(07,0) = (  0.0430132006, -0.0937815326, -0.0271752713, -0.0650333201,  0.1358600245,  0.0438573365, -0.0523431537,  0.0312188944, -0.0509730906,  -0.039012975, -0.0563233126,  0.0437894027,  0.0189488003,  0.0303367616,  0.0192389607,  0.1558832344);
s(08,0) = (  0.0470865692, -0.0671072454,  -0.022493232, -0.1055430831,   0.143392194,   0.020290014, -0.0579863058,  0.0366697449,  0.0672792331,   -0.17263161, -0.0367705173,    0.03060252,  0.0069865526,   0.048410405, -0.0244847492,  0.0217216826);
s(09,0) = (  0.0422937805, -0.0139901699, -0.0187740081, -0.1118847164,  0.0355725043,  0.0065747543, -0.0522317969,  0.0338028094,  0.1397436304, -0.0590687886, -0.0146100555,  0.0066033455,  0.0036201546,  0.0510680449, -0.0331382507,  -0.149838998);
s(10,0) = (  0.0364966167,  0.0226049144, -0.0230256566, -0.0946079511, -0.0566894655, -0.0098900817, -0.0444895337,  0.0448139854,  0.1117277515,   0.091916881,  0.0214102085, -0.0106328097,  0.0161419175,  0.0442142391, -0.0469183803,  -0.108020109);
s(11,0) = (  0.0421044077,  0.0655580116, -0.0214389866, -0.0910180336, -0.1361819932, -0.0227246502, -0.0517754443,  0.0335514869,  0.0455235678,  0.1534572732,  0.0398505059, -0.0302551531,  0.0086045682,  0.0420719252,  -0.016565007,  0.0475696688);
s(12,0) = (   0.039981359,  0.0893970612,  -0.025335723, -0.0576062746, -0.1239419023, -0.0423645777, -0.0487773562,  0.0273813885, -0.0562792281,   0.022075649,  0.0512472007, -0.0418128997,  0.0180228524,  0.0269553046,   0.023068706,  0.1508391653);
s(13,0) = (  0.0441579675,  0.1161220323, -0.0175332068, -0.0189153325, -0.0477035418, -0.0303097116, -0.0544875051,  0.0067589408, -0.1422203715, -0.1472723342,  0.0142535485, -0.0521881933, -0.0001037774,   0.008699795,   0.028187834,  0.0780727412);
s(14,0) = (  0.0420281363,  0.1085321421, -0.0265072806,  0.0259450262,  0.0643378044, -0.0513003212, -0.0511549212, -0.0113740217, -0.1267978988, -0.1204005487, -0.0242866839, -0.0506631752,  0.0184310992, -0.0121920274,  0.0529856147,  -0.102344234);
s(15,0) = (  0.0461532421,  0.0974143941, -0.0219601043,  0.0746029145,  0.1503880398, -0.0337197016, -0.0568702806, -0.0231062814, -0.0406090022,  0.0652197621, -0.0397227928, -0.0447578106,  0.0067015549, -0.0340282281,  0.0164775973, -0.1589757588);
s(16,0) = (  0.0441152638,  0.0281900517,   0.078833449,  0.0919584821,  0.0533117442,  0.0437152492,  0.0164682546,  0.1505793563,  0.0751629949,   0.056955401,   0.086359451,  0.0222822257, -0.0735426522,  0.0971565832,  0.1285531615,  0.0401341771);
s(17,0) = (  0.0322291443, -0.0354782568,  0.0543690374,  0.0657063648, -0.0651268373,  -0.055041679,  0.0009321386,  0.1033192787,  0.0419107942, -0.0654214121, -0.1060425436,  -0.027897146, -0.0698982524,  0.0545481004,  0.0703668088,  0.0032706057);
s(18,0) = (  0.0383835826, -0.0809867759,  0.0700558141,  0.0216084235, -0.0424104507, -0.1350041327,   0.018547155,  0.0350864356,   -0.07175167,  0.0472453176, -0.0717229178, -0.0921381408, -0.0600777514,  0.0211430051, -0.1232767149, -0.0499398595);
s(19,0) = (  0.0322389473, -0.0664397298,  0.0540150191, -0.0346993044,  0.0642615192, -0.1037415875,  -4.65217e-05, -0.0534776143,  -0.044203078,  0.0068898536,  0.1040203792, -0.0532561108, -0.0705206195, -0.0264219411, -0.0736585379,  0.0656679365);
s(20,0) = (  0.0373001791, -0.0239514757,    0.06977971, -0.0764773056,  0.0459132551, -0.0393019156,  0.0225051253, -0.1314130889,  0.0631851701,  -0.052238149,  0.0784378186, -0.0244118571, -0.0556038781, -0.0971297609,  0.1128838031, -0.0358427819);
s(21,0) = (  0.0286104684,  0.0236967244,  0.0479587372, -0.0627354134, -0.0467482615,  0.0382949474,   2.31568e-05, -0.0971716735,  0.0543393552,  0.0553642251, -0.0788152456,  0.0226203967, -0.0625278761, -0.0482977288,  0.0866100669, -0.0316725578);
s(22,0) = (  0.0319172532,  0.0662500266,   0.053823552, -0.0329741981, -0.0618595663,  0.1040830202,  0.0009260783, -0.0510567018, -0.0457783326, -0.0094053016, -0.1004721038,  0.0548518835, -0.0690362954, -0.0257547932, -0.0766312158,  0.0647277115);
s(23,0) = (   0.043107296,  0.0891600453,  0.0784006914,  0.0270881439,  0.0506872808,  0.1484434363,  0.0197405766,  0.0436933511, -0.0730962841,    -0.0406016,  0.0850810502,  0.1005337663,  -0.069432149,  0.0256590675, -0.1257143428, -0.0544973932);
s(24,0) = (  0.0282778963,  0.0256932512,  0.0726827727,  0.0264290825,  0.0244019152,  0.0602289362,  0.0873742003,  0.0618834171,  0.0007773925,  0.0111920403,  0.0586731241,  0.0864922968,  0.0706866138,  0.0886860989,  0.0018213451, -0.0101142514);
s(25,0) = (  0.0394667126,  -0.027219782,  0.0989756867,  0.0447614922, -0.0251317251, -0.0633977005,  0.1116717268,  0.1022608322,  0.0142804526,  -0.010304103,  -0.060022493, -0.0900310896,  0.0769882582,  0.1399183775,  0.0334084523, -0.0005439249);
s(26,0) = (  0.0393211851, -0.0447537187,  0.0985756444, -0.0271909304,  0.0252861615, -0.1021079309,   0.111138168, -0.0633864946, -0.0146978784,  0.0001059945,  0.0604525722, -0.1394084336,   0.076532352, -0.0901268013,  -0.034150384,  0.0107665221);
s(27,0) = (  0.0496217482,   0.045034125,  0.1228019665, -0.0443245613, -0.0244928438,  0.1028001122,  0.1335841245, -0.1009329288,  0.0002261756,  0.0005972525,  -0.058301013,  0.1404162883,  0.0824648266, -0.1373521659,  0.0001563322, -0.0011643384);
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
