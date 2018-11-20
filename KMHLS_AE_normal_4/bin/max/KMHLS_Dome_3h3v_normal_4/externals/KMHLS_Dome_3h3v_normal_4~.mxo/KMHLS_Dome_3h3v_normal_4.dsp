// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 21:01:32

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_3h3v_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMHLS_Dome_3h3v_pinv_energy_limit_050_rV_max_rE_2_band
// speaker array name = KMHLS_Dome
// horizontal order   = 3
// vertical order     = 3
// coefficient order  = fuma
// coefficient scale  = fuma
// input scale        = fuma
// mixed-order scheme = HV
// input channel order: WXYZRSTUVKLMNOPQ
// output speaker order: S1 S2 S3 S4 S5 S6 S7 S8 S9 S10 S11 S12 S13 S14 S15 S16 S17 S18 S19 S20 S21 S22 S23 S24 S25 S26 S27 S28 S29 
//-------


// start decoder configuration
declare name "KMHLS_Dome_3h3v_normal_4";

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
gamma(1) = (   2.245861807,   1.933993153,   1.375216692,  0.6844196142);

// gain matrix
s(00,0) = (   1.044511327,   1.226109593,  0.7065244935, -0.3515245711, -0.4352866329, -0.0941463592, -0.0549765647,  0.7685207357,   1.322261089, -0.0685300955, -0.5723091948, -0.3283119552,  0.0058059268,  0.0096499817,  0.0065635935,   1.382702749);
s(01,0) = (   1.161756968,   1.436448845,    0.16230315, -0.5261429684, -0.3009818061, -0.1427334126,  0.0059532659,   1.486147059,  0.3899911362, -0.1126316659, -0.6188312942, -0.1109260679,  0.0050175243,   0.004248066,   1.276358934,  0.5275322239);
s(02,0) = (   1.153640933,   1.421127064, -0.3838127382, -0.5140554439, -0.3102788913, -0.1595974879,  0.0437264223,   1.334374169, -0.7753864296, -0.1095786811, -0.5774466471,   0.154673801,  0.0028172394, -0.0014264832,  0.9722776235, -0.9796523008);
s(03,0) = (   1.099332383,   1.160372314, -0.8611990939, -0.4331716435, -0.3724897969,  -0.124245277,  0.0647818569,  0.3983480887,  -1.484646233, -0.0891502245,  -0.479565696,  0.4067482629, -0.0008390176, -0.0075551259, -0.5370867423,  -1.273424995);
s(04,0) = (   1.044511327,  0.7065244935,  -1.226109593, -0.3515245711, -0.4352866329, -0.0549765647,  0.0941463592, -0.7685207357,  -1.322261089, -0.0685300955, -0.3283119552,  0.5723091948, -0.0058059268, -0.0096499817,  -1.382702749,  0.0065635935);
s(05,0) = (   1.161756968,    0.16230315,  -1.436448845, -0.5261429684, -0.3009818061,  0.0059532659,  0.1427334126,  -1.486147059, -0.3899911362, -0.1126316659, -0.1109260679,  0.6188312942, -0.0050175243,  -0.004248066, -0.5275322239,   1.276358934);
s(06,0) = (   1.153640933, -0.3838127382,  -1.421127064, -0.5140554439, -0.3102788913,  0.0437264223,  0.1595974879,  -1.334374169,  0.7753864296, -0.1095786811,   0.154673801,  0.5774466471, -0.0028172394,  0.0014264832,  0.9796523008,  0.9722776235);
s(07,0) = (   1.099332383, -0.8611990939,  -1.160372314, -0.4331716435, -0.3724897969,  0.0647818569,   0.124245277, -0.3983480887,   1.484646233, -0.0891502245,  0.4067482629,   0.479565696,  0.0008390176,  0.0075551259,   1.273424995, -0.5370867423);
s(08,0) = (   1.044511327,  -1.226109593, -0.7065244935, -0.3515245711, -0.4352866329,  0.0941463592,  0.0549765647,  0.7685207357,   1.322261089, -0.0685300955,  0.5723091948,  0.3283119552,  0.0058059268,  0.0096499817, -0.0065635935,  -1.382702749);
s(09,0) = (   1.161756968,  -1.436448845,   -0.16230315, -0.5261429684, -0.3009818061,  0.1427334126, -0.0059532659,   1.486147059,  0.3899911362, -0.1126316659,  0.6188312942,  0.1109260679,  0.0050175243,   0.004248066,  -1.276358934, -0.5275322239);
s(10,0) = (   1.153640933,  -1.421127064,  0.3838127382, -0.5140554439, -0.3102788913,  0.1595974879, -0.0437264223,   1.334374169, -0.7753864296, -0.1095786811,  0.5774466471,  -0.154673801,  0.0028172394, -0.0014264832, -0.9722776235,  0.9796523008);
s(11,0) = (   1.099332383,  -1.160372314,  0.8611990939, -0.4331716435, -0.3724897969,   0.124245277, -0.0647818569,  0.3983480887,  -1.484646233, -0.0891502245,   0.479565696, -0.4067482629, -0.0008390176, -0.0075551259,  0.5370867423,   1.273424995);
s(12,0) = (   1.044511327, -0.7065244935,   1.226109593, -0.3515245711, -0.4352866329,  0.0549765647, -0.0941463592, -0.7685207357,  -1.322261089, -0.0685300955,  0.3283119552, -0.5723091948, -0.0058059268, -0.0096499817,   1.382702749, -0.0065635935);
s(13,0) = (   1.161756968,   -0.16230315,   1.436448845, -0.5261429684, -0.3009818061, -0.0059532659, -0.1427334126,  -1.486147059, -0.3899911362, -0.1126316659,  0.1109260679, -0.6188312942, -0.0050175243,  -0.004248066,  0.5275322239,  -1.276358934);
s(14,0) = (   1.153640933,  0.3838127382,   1.421127064, -0.5140554439, -0.3102788913, -0.0437264223, -0.1595974879,  -1.334374169,  0.7753864296, -0.1095786811,  -0.154673801, -0.5774466471, -0.0028172394,  0.0014264832, -0.9796523008, -0.9722776235);
s(15,0) = (   1.099332383,  0.8611990939,   1.160372314, -0.4331716435, -0.3724897969, -0.0647818569,  -0.124245277, -0.3983480887,   1.484646233, -0.0891502245, -0.4067482629,  -0.479565696,  0.0008390176,  0.0075551259,  -1.273424995,  0.5370867423);
s(16,0) = (  -1.393753854, -0.2261674749, -0.3652054095,   3.339413743,  -1.473472898,   1.373357901,   2.348187372,  0.1414858199, -0.1541923651, -0.5285777594,  -0.026261018,  -0.015550111,  -1.157824187,   1.856638087, -0.8222256985, -0.0059813496);
s(17,0) = (  -1.395468378, -0.4277014254, -0.1267099684,   3.341960572,  -1.475497854,   2.640954971,  0.7131577895, -0.1509592882, -0.0331223792, -0.5279000445, -0.0395457814, -0.0259733146,   1.852483445,  0.9654605826,  0.5837402699,  0.5626261031);
s(18,0) = (  -1.393753854, -0.3652054095,  0.2261674749,   3.339413743,  -1.473472898,   2.348187372,  -1.373357901, -0.1414858199,  0.1541923651, -0.5285777594,  -0.015550111,   0.026261018,   1.157824187,  -1.856638087,  0.0059813496, -0.8222256985);
s(19,0) = (  -1.395468378, -0.1267099684,  0.4277014254,   3.341960572,  -1.475497854,  0.7131577895,  -2.640954971,  0.1509592882,  0.0331223792, -0.5279000445, -0.0259733146,  0.0395457814,  -1.852483445, -0.9654605826, -0.5626261031,  0.5837402699);
s(20,0) = (  -1.393753854,  0.2261674749,  0.3652054095,   3.339413743,  -1.473472898,  -1.373357901,  -2.348187372,  0.1414858199, -0.1541923651, -0.5285777594,   0.026261018,   0.015550111,  -1.157824187,   1.856638087,  0.8222256985,  0.0059813496);
s(21,0) = (  -1.395468378,  0.4277014254,  0.1267099684,   3.341960572,  -1.475497854,  -2.640954971, -0.7131577895, -0.1509592882, -0.0331223792, -0.5279000445,  0.0395457814,  0.0259733146,   1.852483445,  0.9654605826, -0.5837402699, -0.5626261031);
s(22,0) = (  -1.393753854,  0.3652054095, -0.2261674749,   3.339413743,  -1.473472898,  -2.348187372,   1.373357901, -0.1414858199,  0.1541923651, -0.5285777594,   0.015550111,  -0.026261018,   1.157824187,  -1.856638087, -0.0059813496,  0.8222256985);
s(23,0) = (  -1.395468378,  0.1267099684, -0.4277014254,   3.341960572,  -1.475497854, -0.7131577895,   2.640954971,  0.1509592882,  0.0331223792, -0.5279000445,  0.0259733146, -0.0395457814,  -1.852483445, -0.9654605826,  0.5626261031, -0.5837402699);
s(24,0) = (   8.409845463,   -1.13881078,   2.001484782,  -10.58257256,   9.839863995,   0.755439532,  -1.327719012,  0.1433345836,   0.241866016,  -2.074228157,  -1.589393928,   2.793459315, -0.4421949192, -0.7454280348,  0.0588354387,   -0.00087514);
s(25,0) = (   8.409845463,   2.001484782,    1.13881078,  -10.58257256,   9.839863995,  -1.327719012,  -0.755439532, -0.1433345836,  -0.241866016,  -2.074228157,   2.793459315,   1.589393928,  0.4421949192,  0.7454280348,    0.00087514,  0.0588354387);
s(26,0) = (   8.409845463,    1.13881078,  -2.001484782,  -10.58257256,   9.839863995,  -0.755439532,   1.327719012,  0.1433345836,   0.241866016,  -2.074228157,   1.589393928,  -2.793459315, -0.4421949192, -0.7454280348, -0.0588354387,    0.00087514);
s(27,0) = (   8.409845463,  -2.001484782,   -1.13881078,  -10.58257256,   9.839863995,   1.327719012,   0.755439532, -0.1433345836,  -0.241866016,  -2.074228157,  -2.793459315,  -1.589393928,  0.4421949192,  0.7454280348,   -0.00087514, -0.0588354387);
s(28,0) = (  -21.14650918,             0,             0,     33.728341,  -24.94571609,            -0,            -0,             0,            -0,   10.82686641,            -0,             0,            -0,             0,            -0,             0);


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
