// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 06-Dec-2018 21:20:33

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
rs = (         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         4.576,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.575,         5.085,         5.085,         5.085,         5.085,         5.576);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1);
gamma(1) = (   2.245861807,   1.933993153,   1.375216692,  0.6844196142);

// gain matrix
s(00,0) = (   1.023492499,  0.7126976715, -0.7452505151,    1.17620202,   1.172985192, -0.2970132912,  -0.106889433, -0.3191643877,  0.6603433781,   1.182503353, -0.1369158581,  -0.199802662, -0.0560438942, -0.3633535373, -0.0171552603, -0.0135378854);
s(01,0) = (  0.9720439556,  0.1764462778,  -0.636839308,   1.295548592,  0.3325031662, -0.0940034176, -0.1667254491, -0.2705802326,   1.312929173,  0.4151948527, -0.0294954527, -0.0477519426, -0.0551615126, -0.4097005135, -0.0896712998,   1.086167075);
s(02,0) = (  0.9251533375, -0.3314299954, -0.5424297786,   1.269188606, -0.6009231684,  0.1451742456, -0.2167735377, -0.2780149255,   1.251200573,  -0.786714177,   0.071600243,  0.0911203056, -0.0544303316, -0.3970263313, -0.1173611168,  0.9519324298);
s(03,0) = (  0.9204146838, -0.8235726544, -0.5558417773,   1.063462928,  -1.285454515,  0.3167653579,  -0.203066524, -0.3208338097,  0.3820218326,   -1.09502952,  0.1443863103,  0.2422321402, -0.0503209493, -0.3204813935, -0.0521486488, -0.3910921265);
s(04,0) = (  0.9574268125,  -1.089069338, -0.6523300778,  0.7410718763,  -1.193959732,  0.3214264037, -0.1476301314, -0.2796223744, -0.5625898311, -0.1307651444,  0.1418010818,  0.3433014897, -0.0452399756, -0.2196823301,  0.0570184409,  -1.117473506);
s(05,0) = (  0.9987945757,    -1.2477073, -0.7346674979,  0.2844796543, -0.5344829025,  0.2816127586, -0.1087816902, -0.1170977935,  -1.253614986,  0.9748111078,  0.0762607599,  0.4114418533, -0.0420813534, -0.0908443982,  0.1497711012, -0.6914870029);
s(06,0) = (   1.011760437,  -1.297947697, -0.7211217795, -0.3215072992,  0.5598279824,   0.297860185, -0.1335659213,  0.1474739507,  -1.279056159,  0.9733029864, -0.0575591932,  0.4229968431, -0.0438560788,  0.0791236977,  0.1524649541,  0.6685961658);
s(07,0) = (  0.9910801705,  -1.180839693, -0.6390602132, -0.8030672252,    1.29286403,  0.3626658681, -0.1919244751,  0.3116567905,  -0.562773895, -0.2277608141, -0.1694175497,  0.3592211237, -0.0478428481,  0.2282186617,  0.0521030269,   1.193302518);
s(08,0) = (  0.9694262404, -0.7470555219, -0.5992674189,   -1.18426226,   1.239688014,  0.3205194799, -0.2112217511,  0.3326710811,  0.7080956151,  -1.233395168, -0.1837923876,  0.1986296898, -0.0474125832,  0.3699957715, -0.0981059551,  0.0249889873);
s(09,0) = (  0.9769659664, -0.2255802795, -0.6603622647,  -1.289996157,  0.4291217087,  0.1084982684,  -0.163590457,  0.2981103621,   1.304279859, -0.4986567548, -0.0664622548,   0.047462215,  -0.041171522,  0.4183762694, -0.1381042588,  -1.037167663);
s(10,0) = (  0.9885830963,  0.3369114538, -0.7231049162,  -1.255606962, -0.6168360954, -0.1624515979, -0.1178718971,  0.3141145764,    1.18414798,  0.7811396212,  0.1001957476, -0.1002549302,  -0.035426672,  0.4050353522,  -0.096960938, -0.8786393292);
s(11,0) = (  0.9832860563,  0.7807898408, -0.7103080059,  -1.101578062,  -1.280738108, -0.3232194383, -0.1248259792,   0.351673155,  0.4937129268,   1.150709561,  0.2044292062, -0.2225806993, -0.0362238653,  0.3434724763, -0.0283394345,  0.2191407314);
s(12,0) = (   0.961971399,   1.152190102, -0.6214079978, -0.7248651013,  -1.230743001, -0.3356671646, -0.1831896792,  0.2970094914, -0.6293182769,  0.0506104629,  0.1826520106, -0.3455060892, -0.0459674496,  0.2166987947,  0.0380796724,    1.16888978);
s(13,0) = (  0.9604877327,   1.311416167, -0.5827078132, -0.2537207386, -0.4651203571,  -0.280171841, -0.2101237702,  0.1064019836,  -1.276220199,  -1.059885378,  0.0520822615, -0.4095933102, -0.0557532221,  0.0782039096,   0.064184162,  0.6175155016);
s(14,0) = (  0.9920975721,   1.326658116, -0.6437651913,  0.3221826924,  0.6254380591, -0.2822587125, -0.1737982769, -0.1578510653,  -1.256422951, -0.9662412753, -0.1063440913, -0.4149556379, -0.0608068628, -0.0862256731,  0.0695000861, -0.7209095064);
s(15,0) = (   1.031674681,   1.122506408, -0.7489633965,    0.86548746,   1.357848702, -0.3420376506, -0.1081049634, -0.3266863407, -0.3987783135,  0.4591264128, -0.1836385992, -0.3341623538, -0.0590164177, -0.2535434497,  0.0446675202,  -1.129181162);
s(16,0) = ( -0.7601205607,  -0.090176576,   3.033304378, -0.3629315271,  0.0279631751,  0.8910586723,   -1.48014026,   2.526815685,  -0.164750663,  0.7486657864,   1.233046871, -0.1270960019, -0.4866596207, -0.3841724979,   1.699302755,  0.3604920579);
s(17,0) = ( -0.6823404738,  0.1515458837,   2.842919888,  -0.339326414, -0.0376321893,  -1.248888585,   -1.36099354,   2.331128956, -0.1101228919, -0.8293887426,  -1.522621152,  0.1870909447, -0.4915798321, -0.3525822822,   1.195143927,  0.0613156565);
s(18,0) = ( -0.6419835623,  0.2633423923,   2.735480903, -0.0695842841, -0.0289877355,  -2.283842411,  -1.297533227,  0.8116006938,  0.1078069124,  0.4206598473,  -1.122983292,  0.2907078617, -0.4874869017,  -0.108869789,  -1.627092807, -0.6956160916);
s(19,0) = ( -0.6783199194,  0.2363803242,   2.864086534,  0.1530184115,  0.0372756016,  -2.243727108,  -1.385549647,  -1.153333668,   0.109311603,  0.1979359673,   1.406217062,  0.3152817428, -0.4939612882,  0.2028480613,   -1.42494214,  0.8077544043);
s(20,0) = (  -0.641040519,   0.158336728,   2.771579511,  0.2697955268,  0.0537700981,  -1.010322077,  -1.325392424,  -2.343959627,  -0.128048914, -0.7460526129,   1.203071727,  0.1865207995, -0.4976466705,  0.3223114836,   1.665279648, -0.3764639895);
s(21,0) = ( -0.5771084788, -0.0588665741,   2.583786628,  0.2193585754, -0.0675722329,  0.9145269665,  -1.210011716,  -2.137987619, -0.1067361382,  0.7665836582,  -1.248344811,  -0.117052836, -0.4867291249,  0.2677477941,    1.39734555, -0.2529758987);
s(22,0) = ( -0.6699748813, -0.3377871783,   2.823164825,  0.1043740669, -0.0739367492,   2.314058601,  -1.360047523,   -1.17445759,  0.1395057123, -0.0565306301,  -1.468911758, -0.3561701735, -0.4857829679,  0.1622539947,  -1.210238448,  0.7991759224);
s(23,0) = ( -0.8061418524, -0.3767181893,   3.150908331, -0.0944894613,  0.0663423777,   2.568284838,  -1.553965343,  0.9843770338,  0.1518374829, -0.3051609913,   1.314496623, -0.4170401962, -0.4861496845, -0.1465052674,   -1.62665544, -0.7810740983);
s(24,0) = (   5.167606517,    1.23511663,  -8.741569015,   1.246279886, -0.2610562579, -0.7481689507,   8.456838801,  -0.774692627,   0.004476689,  0.0003595594,  0.7843013593,   2.128297125,  -1.931339318,    2.13401533, -0.0156992973,  0.0017400859);
s(25,0) = (   5.221301374,   -1.23964771,  -8.873318217,   1.229583797,  0.2654746093,  0.7804982864,   8.520778969, -0.7522899755, -0.0144409043, -0.0070545959, -0.7938701993,  -2.124046871,  -1.915095646,    2.11468232,  0.0569473405,  0.0019900777);
s(26,0) = (    5.16788474,  -1.232252507,  -8.765304237,  -1.224614157,   -0.26988308,  0.7517940948,   8.442348601,  0.7408676477, -0.0021436776, -0.0035073559,  0.8123583072,  -2.125641392,  -1.892610272,  -2.117692423,  0.0044752295,  0.0063911335);
s(27,0) = (   5.219853533,   1.237112821,  -8.876605368,  -1.250339772,   0.266612601,  -0.766039058,   8.519729426,  0.8101008911,  0.0130503694, -0.0148053604, -0.7712787913,   2.122030153,  -1.909413327,  -2.129182033, -0.0585677608,   0.002431501);
s(28,0) = (   -13.1601896,  0.0039033692,   30.03523979,  0.0050033473,  0.0042072596, -0.0059443981,  -22.66386402, -0.0072613462, -0.0020571984,  0.0012748075,  -0.005704507,  0.0022850624,   10.01955846,  0.0029099949,  0.0032027634, -0.0007380443);


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
