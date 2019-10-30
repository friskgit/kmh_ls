// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 27-Jun-2019 12:06:56

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
s(00,0) = (  0.0509600098,  0.0430930197, -0.0269325421,  0.0619051563,  0.0667050257, -0.0038083951, -0.1094840581, -0.0036400662,  0.0254438939,  0.1407555119,  0.0510149201, -0.0582270141,  0.0939833858, -0.0816581517,  0.0195676659, -0.0350597121);
s(01,0) = (  0.0511412767,  0.0169724214, -0.0274185924,  0.0733747396,  0.0326484587, -0.0019382236, -0.1101601653, -0.0028140319,   0.065194846,  0.0930443598,  0.0249690108, -0.0234177359,  0.0951632721, -0.0952151557,   0.050138197,  0.1107095585);
s(02,0) = (  0.0511195884, -0.0143699438,  -0.027377452,  0.0748642059, -0.0255384424,  0.0017328047, -0.1100917687, -0.0026898249,  0.0684848139,    -0.0762455, -0.0195313859,  0.0199670207,  0.0950589678, -0.0969268033,  0.0526683519,  0.1229498167);
s(03,0) = (  0.0512102775, -0.0407104879, -0.0269287385,  0.0650387654, -0.0653899822,   0.003690401, -0.1099217868, -0.0035096378,  0.0317299023, -0.1451350604, -0.0500091962,  0.0550944979,  0.0941501092, -0.0854158374,  0.0244019304, -0.0173299575);
s(04,0) = (  0.0514703476, -0.0633504227, -0.0262957836,  0.0432441514, -0.0675210387,  0.0030579184, -0.1099146113, -0.0038412231, -0.0273607125, -0.0328602585, -0.0516389936,  0.0826258734,  0.0929604573, -0.0584550555, -0.0210417982, -0.1422995678);
s(05,0) = (  0.0516369653, -0.0757969103, -0.0259246497,  0.0152158913,  -0.028378371,  0.0017881579, -0.1099352674, -0.0022325365, -0.0678679267,  0.1182677057, -0.0217033171,  0.0967798132,  0.0922727788, -0.0216972944, -0.0521939338, -0.0838285047);
s(06,0) = (  0.0515631917,  -0.076446148, -0.0261125803, -0.0158938467,  0.0291075272,  0.0023898577, -0.1099434596,  0.0009031948,  -0.068132598,  0.1209282968,   0.022260964,  0.0984497994,  0.0926284057,   0.020644583, -0.0523974797,  0.0835272565);
s(07,0) = (  0.0513609333, -0.0636677582, -0.0269072727, -0.0435915769,  0.0675511137,  0.0044689685, -0.1101712039,   0.003520412, -0.0262723359, -0.0339291359,  0.0516619944,  0.0850237138,  0.0942089228,  0.0584259054, -0.0202047805,  0.1429181466);
s(08,0) = (  0.0512064416,  -0.040304312, -0.0278322889, -0.0634103877,  0.0633515389,  0.0048264072, -0.1105787597,  0.0043243805,  0.0305052617, -0.1416349599,  0.0484502278,  0.0562223287,   0.096105216,  0.0845554099,  0.0234601186,  0.0187980997);
s(09,0) = (  0.0510297722,  -0.013631201,  -0.028201474, -0.0729876177,  0.0250697109,  0.0020884291, -0.1105389791,  0.0040298868,  0.0663307922, -0.0763847935,  0.0191729076,  0.0195586924,  0.0967816449,  0.0965018909,  0.0510117982, -0.1200496437);
s(10,0) = (  0.0505606973,   0.015777052, -0.0276772107, -0.0727259885, -0.0291586252, -0.0023444231, -0.1093282005,  0.0037993538,  0.0654654108,  0.0863470337, -0.0223000429, -0.0225416871,  0.0953177501,  0.0958352798,  0.0503462753, -0.1161048549);
s(11,0) = (  0.0498073377,  0.0410720095, -0.0264691174, -0.0616899245, -0.0642004895, -0.0047160336, -0.1071146981,  0.0038046601,  0.0266561409,  0.1405515251, -0.0490994914, -0.0570191826,  0.0921734045,  0.0816411027,  0.0204999463,    0.03102771);
s(12,0) = (  0.0491280231,  0.0605752718, -0.0252773165, -0.0415405195,  -0.063106225, -0.0040058295, -0.1050434984,  0.0030540182, -0.0265319221,  0.0281614886, -0.0482626157, -0.0805588155,  0.0891161266,  0.0552386823, -0.0204044157,  0.1388828745);
s(13,0) = (  0.0489670158,  0.0721646988,  -0.024742646, -0.0159598717, -0.0288965653, -0.0022370458, -0.1043673372,  0.0009915295, -0.0643934929, -0.1140139776, -0.0220996238, -0.0929084836,   0.087845055,  0.0208435607, -0.0495219151,  0.0858217995);
s(14,0) = (  0.0494841863,  0.0741661707, -0.0250724888,  0.0138516974,  0.0243810663, -0.0018364091, -0.1055199578, -0.0018926578, -0.0675629578, -0.1242758788,  0.0186462434, -0.0948527971,   0.088921309,  -0.019556964,  -0.051959397, -0.0752609725);
s(15,0) = (  0.0503107429,  0.0644799471, -0.0259700616,  0.0403397308,  0.0633510145,  -0.003151733, -0.1076342014, -0.0036725368, -0.0317763261,  0.0164256813,  0.0484498268, -0.0842180728,  0.0914439998, -0.0546119202, -0.0244376327, -0.1446882405);
s(16,0) = ( -0.0406197723,  0.0148374572,  0.1091624277,  0.0344000671,  0.0510305536,  0.0423708282,  0.1516870724,  0.1054256976,  0.0517934849,  0.0789207872,  0.0390273384,  0.0422608875, -0.2649279074,  0.1074034342,  0.0398318595,  0.0370388046);
s(17,0) = ( -0.0410345292, -0.0145410357,  0.1095248211,  0.0353175173, -0.0525694431,  -0.043508028,  0.1526833348,  0.1051606311,  0.0515500477, -0.0806605267, -0.0402042561, -0.0442533329, -0.2660030927,  0.1059072038,  0.0396446438,  0.0325873846);
s(18,0) = ( -0.0405919609,  -0.035873175,  0.1097554865,  0.0138898339, -0.0491959508, -0.1073055115,  0.1520737644,  0.0407322981,  -0.056154188,   0.042336213,  -0.037624264, -0.1082374528,  -0.266193488,  0.0410977217,  -0.043185465, -0.0781631369);
s(19,0) = ( -0.0397308385, -0.0346313362,  0.1074658899, -0.0160707228,  0.0560655943, -0.1022401133,  0.1488761328, -0.0455854208, -0.0483725704,  0.0248496146,  0.0428780558,  -0.102626639, -0.2606304322, -0.0453346229,     -0.037201,   0.085071777);
s(20,0) = (  -0.039107544, -0.0123038765,  0.1047190164,  -0.033444008,  0.0467789402, -0.0391302902,  0.1457612236, -0.1014869127,  0.0522114236, -0.0751599566,  0.0357757736, -0.0407681521, -0.2542428293, -0.1029725417,   0.040153276, -0.0385982859);
s(21,0) = ( -0.0395483813,  0.0138332282,  0.1053750805, -0.0333703208, -0.0485137603,  0.0397234582,  0.1470191159, -0.1019595671,  0.0527650219,  0.0757098358, -0.0371025358,  0.0397222541, -0.2559725654, -0.1037279717,  0.0405790216, -0.0409574087);
s(22,0) = ( -0.0408109733,  0.0331594957,  0.1085170462, -0.0148532827, -0.0532735653,  0.1035981631,  0.1515495449, -0.0446478556, -0.0489169621, -0.0276030681, -0.0407427573,  0.1063714287,  -0.263663183, -0.0454909014, -0.0376196652,  0.0809383906);
s(23,0) = ( -0.0408050517,  0.0354575287,  0.1096904099,  0.0140396793,   0.049741656,  0.1064787015,  0.1524010445,  0.0420054051, -0.0546463243, -0.0383982733,  0.0380416104,  0.1075891409, -0.2662014559,  0.0427242202, -0.0420258401, -0.0779539311);
s(24,0) = (  0.0375298717, -0.0061989756,  0.0406510356, -0.0069140784,  0.0183101005,  0.0940890641,  0.0354864334,  0.0923767226,   2.66852e-05,    0.00251935,  0.0140032674,  0.1416481124,  0.1107611984,  0.1400942969,   2.05223e-05, -0.0023503945);
s(25,0) = (  0.0368179148,  0.0060643842,  0.0409942103, -0.0064369602, -0.0179434848, -0.0944483766,  0.0369917113,  0.0926797239,  0.0007165547, -0.0024022925, -0.0137228857, -0.1419927308,  0.1095198801,  0.1399429638,  0.0005510675,  -0.004417142);
s(26,0) = (  0.0384849825,  0.0065314502,  0.0373266141,  0.0068350468,  0.0170111612, -0.0937888361,  0.0313632072, -0.0918595417, -0.0005387204, -0.0019282273,  0.0130098598, -0.1416298699,  0.1186321931, -0.1392634087, -0.0004143037,  0.0032393758);
s(27,0) = (  0.0388891934, -0.0062398229,  0.0373480664,  0.0067481515,  -0.017540693,  0.0941806992,  0.0306674712, -0.0922917335,  -0.000789605,  0.0018248444,  -0.013414837,  0.1418265603,  0.1188682988, -0.1397726643,  -0.000607247,  0.0036207986);
s(28,0) = (  0.0818174579, -0.0001177044, -0.0098181598, -0.0001740127,  0.0001221119,   -2.4398e-05, -0.0555881788, -0.0006784607,  0.0004385441,  -1.02496e-05,   9.33892e-05,  0.0001108777,  0.3087551888, -0.0007504287,   0.000337263,  -6.94356e-05);


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
//route(n_inputs,n_outputs,outs) = m.bus(n_inputs)
//                               <: par(i,n_outputs,(0,gate_bus(i,outs)):>_


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
