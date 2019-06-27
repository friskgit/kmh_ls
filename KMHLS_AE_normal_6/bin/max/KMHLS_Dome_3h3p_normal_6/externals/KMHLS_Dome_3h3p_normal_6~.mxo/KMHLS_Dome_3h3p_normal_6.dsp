// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 15-May-2019 19:52:22

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
s(00,0) = (  0.0455161113,  0.0715868303, -0.0164399572,  0.0976407501,  0.1469509473, -0.0144956852, -0.0550471546, -0.0243907403,  0.0465245793,  0.1622545282, -0.0240578981, -0.0298325246, -0.0021655191,  -0.041760736, -0.0148752695, -0.0543012154);
s(01,0) = (  0.0407611646,  0.0240705031,  -0.023531261,  0.1057768072,  0.0601762198, -0.0093175714, -0.0496922946, -0.0448848897,  0.1252532441,  0.0970592387, -0.0195834972, -0.0110642116,  0.0137764659, -0.0488263958, -0.0461333512,  0.1218701485);
s(02,0) = (  0.0462990151, -0.0189752204, -0.0170522078,  0.1216281125, -0.0478241102,  0.0071355785, -0.0560066837, -0.0287048301,  0.1490434893, -0.0782206052,  0.0150852179,  0.0086371095, -0.0016405849, -0.0516047129, -0.0253070988,  0.1547252186);
s(03,0) = (  0.0408824486, -0.0584413262, -0.0235779504,  0.0918168125, -0.1262571526,  0.0254689889, -0.0499651922, -0.0383478814,  0.0590526573, -0.1549101306,  0.0465673824,  0.0270487643,  0.0140234162, -0.0424045922, -0.0191535624, -0.0200175356);
s(04,0) = (  0.0470040108, -0.1016666058, -0.0172169406,  0.0725094891, -0.1498746608,  0.0256431096, -0.0567130206, -0.0149906965, -0.0517856769, -0.0491250789,  0.0249305792,  0.0434277429,  -0.002027816, -0.0302226866,   0.015782055, -0.1682188075);
s(05,0) = (  0.0412830359, -0.1075533969, -0.0238195688,  0.0224882187, -0.0563785351,  0.0456690347, -0.0504663215, -0.0086800189,  -0.128821647,  0.1281579959,  0.0182759292,  0.0497520417,  0.0141515627, -0.0103759639,  0.0473881566, -0.0913545494);
s(06,0) = (  0.0475581666, -0.1241415242, -0.0174064037,  -0.023448789,  0.0585899133,  0.0289495957, -0.0574618985,  0.0081857837, -0.1491767864,  0.1494961656, -0.0169030741,  0.0525061933, -0.0019129274,  0.0105500761,  0.0245960741,  0.0944233535);
s(07,0) = (  0.0419006115, -0.0918926062, -0.0242020015, -0.0630525028,  0.1329004471,  0.0383728024, -0.0511114941,  0.0273716501, -0.0512837518, -0.0366932495, -0.0487247945,  0.0424183958,  0.0142330973,   0.029136868,  0.0163560596,  0.1548394413);
s(08,0) = (  0.0449610953, -0.0661982288,  -0.016762492, -0.0996666919,  0.1405012687,  0.0138843228, -0.0544748888,  0.0257576653,  0.0592719003, -0.1666911152, -0.0236990606,  0.0277516743, -0.0011684029,  0.0428594791, -0.0173965362,  0.0310662637);
s(09,0) = (  0.0447719067, -0.0193611237, -0.0169987597, -0.1175406724,  0.0488413132,  0.0074527608, -0.0541884036,  0.0288162275,  0.1438050173, -0.0800130132, -0.0158186322,  0.0088467096, -0.0007987109,   0.050191122, -0.0254942354, -0.1488228528);
s(10,0) = (  0.0407654735,  0.0229159583, -0.0235416473, -0.1060778049, -0.0574211548, -0.0089122189, -0.0497783854,  0.0450662899,   0.126614818,  0.0929810854,  0.0187740721, -0.0105425424,  0.0139374384,  0.0490003924, -0.0465905729, -0.1251236507);
s(11,0) = (   0.044828624,  0.0685041688,  -0.016504912, -0.0976515573,  -0.142982515, -0.0143614454, -0.0542152319,  0.0246980875,  0.0518872893,  0.1635297483,  0.0239965056, -0.0287144733, -0.0017052578,  0.0418979283, -0.0152647048,  0.0437482892);
s(12,0) = (  0.0387779604,  0.0859665353, -0.0223731351, -0.0573987566, -0.1227381554, -0.0359196983, -0.0473836766,  0.0249614099, -0.0509763725,   0.028986763,  0.0451650123, -0.0397136847,   0.013282145,  0.0265388415,  0.0164186846,  0.1471202429);
s(13,0) = (   0.045030867,  0.1175510806, -0.0159688055,  -0.023082134, -0.0578733237, -0.0261906104, -0.0544154456,  0.0081904115,  -0.141181589, -0.1412064688,  0.0170153869, -0.0495108258, -0.0026763784,  0.0104375838,  0.0215876807,   0.093814131);
s(14,0) = (  0.0403909169,  0.1058182068, -0.0232903552,  0.0190739843,  0.0481578273, -0.0448497898, -0.0492784367,  -0.007009892, -0.1291243562, -0.1329708703, -0.0147101833, -0.0489089409,  0.0136266857, -0.0087713231,  0.0474988346, -0.0789764535);
s(15,0) = (  0.0408056832,   0.091948842, -0.0234860259,   0.057847785,  0.1254092492, -0.0382574317, -0.0498504408, -0.0252195795, -0.0602701717,  0.0175610554, -0.0462382443, -0.0424476356,  0.0138585873, -0.0267587623,  0.0193530026, -0.1549701511);
s(16,0) = (  0.0389359004,  0.0258369542,  0.0730907593,  0.0790967813,  0.0480246049,  0.0438587823,  0.0247242058,  0.1356615161,    0.06470592,   0.052728592,  0.0847168637,  0.0305806987, -0.0553800916,  0.1007985804,  0.1137285452,  0.0372378095);
s(17,0) = (   0.032144031, -0.0324570478,    0.05629634,  0.0654787095, -0.0597469082, -0.0522084646,  0.0068646756,   0.106752281,  0.0449066054, -0.0618418835,  -0.100558322, -0.0306441549, -0.0645447536,   0.064936305,  0.0777263902,  0.0104764496);
s(18,0) = (  0.0395166583, -0.0808136808,   0.074133704,  0.0243202724, -0.0453998507, -0.1385429382,   0.024915885,  0.0412290404, -0.0675695113,  0.0408923765, -0.0799873327, -0.1027107279, -0.0565076882,   0.028616354, -0.1187872858, -0.0501467267);
s(19,0) = (  0.0317779492, -0.0641313184,  0.0554719974, -0.0336948328,  0.0615871892, -0.1043094927,  0.0062667457, -0.0539374139, -0.0417371408,  0.0057115325,  0.1033305972, -0.0629192676,  -0.064254195, -0.0310701998, -0.0724368768,  0.0625145192);
s(20,0) = (  0.0341328459, -0.0233769556,  0.0661523781, -0.0679899269,  0.0443138782, -0.0398394551,  0.0276602482, -0.1211456865,  0.0540602426, -0.0504647112,  0.0785611273, -0.0280880536, -0.0430821714,  -0.099162839,  0.1002470553, -0.0283471511);
s(21,0) = (   0.030686754,  0.0244521496,  0.0535257039, -0.0656843844, -0.0462794247,  0.0414300622,  0.0059497676, -0.1056797826,   0.055674328,   0.052324425, -0.0816331087,  0.0286972616, -0.0620787771, -0.0613967273,  0.0915842353, -0.0328271898);
s(22,0) = (  0.0315846399,  0.0639034872,  0.0554443176, -0.0327476721, -0.0600769105,  0.1044964968,  0.0070786338, -0.0527373106,   -0.04253874, -0.0075418295, -0.1012831045,   0.064181008, -0.0632335591, -0.0310452771, -0.0740576406,  0.0617000074);
s(23,0) = (   0.042479525,   0.086306478,  0.0777221091,  0.0305791533,  0.0565207609,  0.1447242077,  0.0212296047,   0.049048283, -0.0669515903, -0.0318921803,  0.0947564582,   0.100904202, -0.0653947564,   0.028565992, -0.1173150315,   -0.05881435);
s(24,0) = (  0.0254848385,  0.0220263973,  0.0669407106,  0.0219154887,  0.0188895248,  0.0532528341,  0.0843550147,  0.0529947699, -0.0001143287,  0.0074215374,  0.0473105299,  0.0802267994,  0.0742492643,  0.0798672787, -0.0002846297, -0.0075645291);
s(25,0) = (  0.0342672386, -0.0221166977,  0.0882500942,   0.036347146, -0.0188521144, -0.0533630464,  0.1059216186,  0.0859909754,  0.0110994197, -0.0072807379, -0.0470621702, -0.0801182577,  0.0834174503,  0.1245961587,  0.0269801361,  0.0001976359);
s(26,0) = (  0.0340686883, -0.0360210073,  0.0877469248, -0.0223415236,  0.0192173694, -0.0852277699,  0.1053520488, -0.0538309155, -0.0107599187,  -0.000135485,  0.0478923619, -0.1235207157,  0.0830633053, -0.0806420311, -0.0261788064,  0.0075846199);
s(27,0) = (  0.0424027981,  0.0360226875,  0.1079464385, -0.0360071718, -0.0188934804,  0.0851469788,  0.1257305059, -0.0850421345,  0.0001325816,    4.6512e-06, -0.0469808387,  0.1231784569,  0.0915987015, -0.1228703683,  0.0002487492, -0.0003324332);
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
