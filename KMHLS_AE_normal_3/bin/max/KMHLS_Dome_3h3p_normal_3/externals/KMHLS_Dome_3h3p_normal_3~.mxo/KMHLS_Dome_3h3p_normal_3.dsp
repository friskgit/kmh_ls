// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 03-Dec-2018 21:29:15

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_3h3p_pinv_match_rV_max_rE_2_band.dsp
// description = KMHLS_Dome_3h3p_pinv_match_rV_max_rE_2_band
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
declare name "KMHLS_Dome_3h3p_normal_3";

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
s(00,0) = (  0.6040832768,    0.27007743,  -1.193049126,  0.3827642565,  0.2231184285, -0.3563857178,  0.7860555514, -0.4742923718,  0.1206017533,  0.1386133106, -0.1867768524,  0.1420726392, -0.1970897023,  0.1862151539, -0.1000790187, -0.0098315606);
s(01,0) = (  0.5180369287,  0.0717685544,  -1.012113126,  0.3924168955,  0.0601476959, -0.0991906429,  0.6551058718, -0.4714626912,  0.2568393502,  0.0450723944, -0.0494173339,  0.0408764002, -0.1610296747,  0.1856324695, -0.2262799224,  0.1207204276);
s(02,0) = (  0.4429854369, -0.1287789472,  -0.854947021,  0.3884477286, -0.1153530386,  0.1716681015,  0.5420111293, -0.4705521703,  0.2540660552, -0.0957309858,  0.0965429422, -0.0676713084, -0.1300495453,  0.1863349872, -0.2323021028,  0.1102436415);
s(03,0) = (  0.4508522425, -0.2965194165, -0.8745839755,  0.3555077398, -0.2417719348,  0.3889715555,  0.5593257081, -0.4493005542,  0.0852582685, -0.1279494509,  0.2026765956, -0.1553450392, -0.1355939752,  0.1782712017,  -0.084592876, -0.0417071315);
s(04,0) = (  0.5240297532, -0.3540196068,  -1.030574808,  0.2655951969, -0.2239314502,  0.4450791585,  0.6743421099, -0.3458760954,  -0.107762653, -0.0123532854,  0.1900324949, -0.1770999222, -0.1677970555,  0.1365733173,  0.0944626574, -0.1267067718);
s(05,0) = (  0.5877426726, -0.3752074961,  -1.163181993,  0.1014552262, -0.0996186535,  0.4506286486,  0.7689444367, -0.1334594838, -0.2523728154,  0.1162913805,   0.087647941, -0.1774093608, -0.1935051166,  0.0516983528,  0.2324387096, -0.0798405732);
s(06,0) = (   0.579328805, -0.3978076659,  -1.139049565,  -0.132462088,   0.109830177,  0.4753909841,  0.7450227825,  0.1765119041, -0.2591243663,  0.1111212667,  -0.090314555, -0.1856377935, -0.1853020229, -0.0705966058,  0.2400335392,  0.0769424409);
s(07,0) = (  0.5177835245, -0.4013440589,  -1.003957417,  -0.299380104,  0.2542137111,  0.5001071855,   0.641561259,  0.3885420259, -0.1112822907, -0.0335114066, -0.2170185312, -0.1963228363, -0.1553873667, -0.1530172293,  0.0994692852,  0.1404306621);
s(08,0) = (  0.4859688636, -0.2925197988, -0.9379699766, -0.3878830425,  0.2481218148,  0.3860788829,  0.5947177394,  0.4793863852,  0.1458083942, -0.1502820245, -0.2157085413, -0.1539329699, -0.1427166265, -0.1877645082,  -0.139764049,  0.0091538821);
s(09,0) = (  0.5296209992, -0.0973505586,  -1.036279572,  -0.394318591,   0.089174284,  0.1330678825,  0.6724032529,  0.4740769665,   0.259575841, -0.0599752729, -0.0783754325, -0.0543420561, -0.1657446803, -0.1864307137, -0.2378766293, -0.1138665399);
s(10,0) = (  0.5749727877,   0.130212767,  -1.137190727, -0.3892054126, -0.1195104045, -0.1734198077,  0.7509967336,  0.4734529592,  0.2283938495,  0.0933710168,  0.1039055859,  0.0684652421, -0.1887787938, -0.1876526354, -0.2004746965,  -0.098016055);
s(11,0) = (  0.5651574256,  0.2912916081,  -1.116578434, -0.3679615823, -0.2521386772, -0.3835659574,  0.7361061596,   0.464090815,  0.0895147665,  0.1375535475,  0.2190103424,  0.1531720488, -0.1846851515, -0.1845549474, -0.0716818863,  0.0269724289);
s(12,0) = (  0.5010159458,  0.3834756783, -0.9760822513, -0.2660395637, -0.2400152625, -0.4813686131,  0.6287888722,  0.3484761169, -0.1268505707,   0.008543405,  0.2058682556,  0.1914862703, -0.1537225667,   -0.13793355,  0.1160332054,  0.1363149288);
s(13,0) = (  0.4763782077,  0.4030257438, -0.9198454209, -0.0936408917, -0.0857693481, -0.4843385179,  0.5836479317,  0.1230442348, -0.2493472228, -0.1206302404,  0.0704063117,  0.1905907177, -0.1401807185, -0.0476858141,  0.2173809141,  0.0721198467);
s(14,0) = (  0.5273066374,  0.4098572019,  -1.026594925,  0.1303245989,  0.1283346705, -0.4905899719,   0.660563943, -0.1753427753,  -0.247170916, -0.1080980866, -0.1129121329,  0.1915790179, -0.1612756556,  0.0703011959,  0.2142108569, -0.0854981955);
s(15,0) = (  0.6088777614,  0.3838385652,  -1.201295307,  0.3143796335,  0.2651679877, -0.4821331704,  0.7901834452, -0.4072952655, -0.0861474435,  0.0579644315, -0.2255670901,  0.1895189503, -0.1977658993,  0.1606093256,  0.0790220132, -0.1374314312);
s(16,0) = (  -2.089114415, -0.3412483685,   4.423960322,   -1.00099941, -0.1563144971,  0.5529395535,   -3.23287753,   1.634077832, -0.2879993331,  0.0866436665,  0.3189159224, -0.2727334436,  0.8980316237, -0.7946990646,  0.5703938203,  0.0523288968);
s(17,0) = (  -1.935536978,  0.4818929263,   4.100148021, -0.9221876527,  0.1920356703, -0.7854520691,    -2.9976474,   1.503528976, -0.2090475007, -0.0929222341,  -0.396876461,  0.3873415407,  0.8330363571, -0.7320499348,  0.4188420561,  0.0191619136);
s(18,0) = (  -1.854517461,  0.8674078802,   3.925526828, -0.2970838486,   0.137608202,  -1.412613289,  -2.867001774,  0.4857878378,  0.2539822502,   0.053727122, -0.2850125645,  0.6855788956,  0.7959924079, -0.2409615924, -0.5075915192, -0.0767600981);
s(19,0) = (   -1.95340135,  0.8537235299,   4.137844905,   0.462125118,  -0.183812729,  -1.397597164,  -3.025062431, -0.7541379753,  0.2310678498,  0.0274638426,  0.3768716352,  0.6816982531,  0.8406188763,  0.3722093035, -0.4583966389,  0.0900581161);
s(20,0) = (  -1.878589921,  0.4185084043,   3.979047755,  0.8967130471, -0.1506646667, -0.6795723291,  -2.908646027,  -1.463981883, -0.2698679145,  -0.079990445,  0.3201446877,  0.3343443098,  0.8081881931,  0.7119118803,  0.5374024727, -0.0491130659);
s(21,0) = (  -1.735701342, -0.3290935404,   3.673960071,   0.800896592,  0.1464177597,  0.5375384123,  -2.683206478,  -1.305508686, -0.2217169907,  0.0837165687, -0.3067251584, -0.2663966737,  0.7449477492,  0.6344527118,  0.4374005936, -0.0394498641);
s(22,0) = (  -1.923882605,  -0.921859059,   4.075482192,  0.4359305305,  0.1741167952,   1.500924111,  -2.979636162, -0.7119230165,  0.2211028583, -0.0279644108, -0.3661280444, -0.7297388974,  0.8280365744,  0.3516280025, -0.4364368763,  0.0870045421);
s(23,0) = (  -2.182538955,  -1.029331773,   4.621937398, -0.3753943765, -0.1593865345,   1.683832775,   -3.37769068,  0.6121569145,  0.2824787808, -0.0506741099,  0.3388099829, -0.8200939846,  0.9382922368, -0.3024913063, -0.5616139083, -0.0832304405);
s(24,0) = (   8.448590854,   1.005389886,  -17.66347639,   1.016098751, -0.1499411563,  -1.345358349,   14.14403042,  -1.363091436,  0.0012150394,  0.0021144154,  0.2422710498,   1.050727905,  -4.929144886,   1.059601614, -0.0015949238,  0.0009328088);
s(25,0) = (   8.545414628,  -1.005389886,  -17.86675105,  0.9906090669,  0.1499411563,   1.345358349,   14.29082273,   -1.32204333, -0.0012150394, -0.0021144154, -0.2422710498,  -1.050727905,  -4.969486306,   1.039651871,  0.0015949238, -0.0009328088);
s(26,0) = (   8.448590854,  -1.001317932,  -17.66347639, -0.9906090669, -0.1499411563,   1.339776418,   14.14403042,    1.32204333,  0.0012150394,  0.0021144154,  0.2422710498,   -1.04852558,  -4.929144886,  -1.039651871, -0.0015949238,  0.0009328088);
s(27,0) = (   8.545414628,   1.001317932,  -17.86675105,  -1.016098751,  0.1499411563,  -1.339776418,   14.29082273,   1.363091436, -0.0012150394, -0.0021144154, -0.2422710498,    1.04852558,  -4.969486306,  -1.059601614,  0.0015949238, -0.0009328088);
s(28,0) = (   -25.9288692,             0,   54.74584103,             0,            -0,             0,  -43.58771474,            -0,             0,             0,            -0,            -0,   15.77074292,             0,             0,            -0);


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
