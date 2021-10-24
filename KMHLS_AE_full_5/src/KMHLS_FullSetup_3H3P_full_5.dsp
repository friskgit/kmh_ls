// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.7.0) at 28-Oct-2019 23:05:13

//------- decoder information -------
// decoder file = ../decoders/KMHLS_FullSetup_3H3P_Slepian11_2_band.dsp
// description = KMHLS_FullSetup_3H3P_Slepian11_2_band
// speaker array name = KMHLS_FullSetup
// horizontal order   = 3
// vertical order     = 3
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 
// output speaker order: S1 S2 S3 S4 S5 S6 S7 S8 S9 S10 S11 S12 S13 S14 S15 S16 S17 S18 S19 S20 S21 S22 S23 S24 S25 S26 S27 S28 S29 S33 S34 S35 S36 S37 S38 S39 S40 S41 S42 S43 S44 S45 S46 S47 S48 
//-------


// start decoder configuration
declare name "KMHLS_FullSetup_3H3P_full_5";

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
ns = 45;

// radius for each speaker in meters
rs = (          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         5.317,         5.317,         5.317,         5.317,         5.576,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1);
gamma(1) = (             1,  0.8611363116,  0.6123336207,   0.304746985);

// gain matrix
s(00,0) = (  0.0123009246,  0.0241826676,  0.0155895093,  0.0346502547,  0.0508126907,    0.01191864, -0.0154854018,   0.018082902,  0.0192373406,  0.0708951597,  0.0388607204,  -0.012692218, -0.0379042529, -0.0170685949,  0.0147945065, -0.0168841613);
s(01,0) = (  0.0122213098,  0.0096286636,  0.0154505147,  0.0413556221,  0.0248185303,  0.0046827212, -0.0154684497,  0.0219704464,  0.0494921443,  0.0469385955,  0.0189808088, -0.0050737579, -0.0377095102, -0.0201032834,    0.03806201,  0.0566239021);
s(02,0) = (  0.0121222421, -0.0078023527,  0.0155618243,  0.0422560443,  -0.019446056, -0.0036454171, -0.0152157792,  0.0222727662,  0.0519239205, -0.0384561083, -0.0148720278,  0.0043221496, -0.0380283176, -0.0208088985,  0.0399321712,   0.062517839);
s(03,0) = (  0.0122375237, -0.0225942002,  0.0157878027,  0.0365251755, -0.0498304416, -0.0112395436, -0.0152348487,  0.0187510041,  0.0239633734, -0.0731076151, -0.0381095122,  0.0116852819, -0.0383943824, -0.0184681177,  0.0184290693, -0.0086092517);
s(04,0) = (  0.0125496962, -0.0354899658,  0.0160102258,  0.0240786345,  -0.051635306, -0.0185525113, -0.0155942793,  0.0119758035, -0.0209086639, -0.0162029977, -0.0394898432,  0.0174415785, -0.0385938613, -0.0124782291, -0.0160798402, -0.0719372655);
s(05,0) = (  0.0127469806, -0.0425965122,  0.0160946162,  0.0084680805, -0.0219403792, -0.0226185345, -0.0158733722,  0.0042443136, -0.0517132005,  0.0602422066, -0.0167796456,  0.0207294652, -0.0386239186, -0.0042784146, -0.0397701167, -0.0424549767);
s(06,0) = (  0.0126277362, -0.0428106168,  0.0159734241,   -0.00860518,  0.0219779038, -0.0221950308, -0.0157826354,  -0.003868061, -0.0520552079,  0.0615541184,  0.0168083438,  0.0216022725, -0.0385172429,  0.0049848511,  -0.040033138,  0.0421694033);
s(07,0) = (  0.0122789662, -0.0353121129,  0.0156077721, -0.0238745455,  0.0515313311,  -0.017372291,  -0.015491726, -0.0113253486, -0.0203708159, -0.0167639823,  0.0394103249,  0.0188998598,   -0.03809977,  0.0131504926, -0.0156662074,    0.07229583);
s(08,0) = (  0.0119973548, -0.0220390602,  0.0151154377, -0.0350549585,   0.048385682, -0.0103489298, -0.0153989604, -0.0171575667,   0.022849673, -0.0712006643,  0.0370045836,  0.0122734743,  -0.037329246,  0.0189140092,  0.0175725763,  0.0095740394);
s(09,0) = (  0.0119161102, -0.0072266384,  0.0147807318, -0.0406224417,   0.018948921,  -0.003495642, -0.0155025851, -0.0202038085,  0.0502983335, -0.0382190329,   0.014491827,    0.00382386, -0.0366626571,  0.0217269416,  0.0386820111,   -0.06081602);
s(10,0) = (  0.0119104862,  0.0089337933,  0.0148080915,  -0.040544988, -0.0227654707,  0.0038909942, -0.0154319539, -0.0201524142,  0.0498161752,  0.0439214253, -0.0174106621, -0.0053523535, -0.0366280317,  0.0216984659,  0.0383112065, -0.0592484444);
s(11,0) = (  0.0118330851,  0.0229247524,  0.0152574681,  -0.034239624, -0.0495703377,   0.011150581, -0.0149091879, -0.0168172048,    0.02022759,  0.0710562619,  -0.037910589, -0.0122285946,  -0.037519983,  0.0183703897,  0.0155560594,  0.0147831324);
s(12,0) = (  0.0117086175,  0.0339126839,  0.0158617092, -0.0228782987, -0.0484533823,  0.0177666804, -0.0142018333, -0.0111624645, -0.0204882032,  0.0139312606, -0.0370563597, -0.0166170685, -0.0388093316,  0.0121605805, -0.0157564843,  0.0693311453);
s(13,0) = (  0.0116973967,   0.040558033,  0.0162616557, -0.0087046546, -0.0219795078,  0.0220115694, -0.0138698381, -0.0043810596, -0.0494978664, -0.0581483438, -0.0168095705, -0.0190633934, -0.0396393358,  0.0043746441, -0.0380664106,  0.0429454446);
s(14,0) = (  0.0118979573,  0.0417335085,  0.0162726257,  0.0076815751,   0.018842579,  0.0224841401, -0.0142212334,  0.0035633163, -0.0518962775, -0.0633732301,  0.0144104983, -0.0198644874, -0.0395383634, -0.0042919877, -0.0399109124, -0.0378089797);
s(15,0) = (  0.0121714017,  0.0362238166,  0.0159579421,  0.0223802605,  0.0484483808,  0.0187538226, -0.0149566904,  0.0111883271, -0.0244733956,  0.0078665435,  0.0370525346, -0.0180939363, -0.0387206792, -0.0114960134, -0.0188213027, -0.0724194362);
s(16,0) = (  0.0080153468,  0.0184467842,  0.0559589262,  0.0440197244,  0.0389653404,  0.0396744148,  0.0336897637,  0.0972026797,  0.0397738092,  0.0399772163,  0.0298000593,  0.0338109635, -0.0995325518,  0.0838584057,  0.0305881094,  0.0189047442);
s(17,0) = (  0.0077908021, -0.0187465647,  0.0562714876,  0.0444832406, -0.0400322912, -0.0411385672,  0.0342967829,  0.0969837313,  0.0395279548,  -0.040787246,  -0.030616046, -0.0355277169, -0.1004097028,  0.0829836881,  0.0303990347,   0.016039921);
s(18,0) = (  0.0080630732, -0.0456994611,  0.0563432441,  0.0172907011, -0.0375126669, -0.0995640688,  0.0338480932,  0.0378104743, -0.0424333947,  0.0211780843, -0.0286890782, -0.0851336181, -0.1004281613,  0.0325874147, -0.0326334677, -0.0399226706);
s(19,0) = (  0.0078903075, -0.0438648545,  0.0552566737, -0.0200384548,  0.0430699123, -0.0952168032,  0.0332243505, -0.0432962942, -0.0366953183,  0.0122124022,  0.0329391693, -0.0812472717, -0.0985068352, -0.0370105405, -0.0282205912,  0.0432781417);
s(20,0) = (  0.0075867276, -0.0164769513,  0.0538105017, -0.0430939961,  0.0360301216, -0.0372398825,  0.0326025345, -0.0948905646,  0.0399732865, -0.0380977083,  0.0275552517, -0.0327752054, -0.0958115382,  -0.081711676,  0.0307415177, -0.0189584847);
s(21,0) = (  0.0076420531,  0.0172478407,  0.0537510543, -0.0431523138,  -0.037097963,  0.0372927764,  0.0325442563, -0.0950797773,  0.0406499977,  0.0383615122, -0.0283719195,  0.0318975503, -0.0954447443, -0.0819020856,  0.0312619435, -0.0208030583);
s(22,0) = (  0.0076972208,  0.0428692807,  0.0551836783, -0.0190945191,  -0.040501331,   0.095836374,  0.0336526115, -0.0422239159, -0.0370040162, -0.0139949917,   -0.03097476,  0.0833548208, -0.0981417284, -0.0366415653, -0.0284579958,  0.0405348346);
s(23,0) = (     0.0080058,  0.0448051927,  0.0559989639,  0.0176903027,  0.0382739556,  0.0983394875,   0.033765918,  0.0388905387, -0.0414146075, -0.0194336507,  0.0292712995,  0.0845030935, -0.0995538909,  0.0336278085, -0.0318499679, -0.0391252107);
s(24,0) = (  0.0284961034,  0.0184970917,  0.0503051734,  0.0177104854,  0.0138411343,  0.0750454681,  0.0572606762,  0.0736790461,   -9.9114e-06,  0.0017183404,  0.0105854747,   0.083969711,  0.0805927987,  0.0829964091,   -7.6224e-06, -0.0014135325);
s(25,0) = (  0.0281966426, -0.0185244913,  0.0506440621,  0.0179937409, -0.0138409707, -0.0751843341,  0.0579839467,  0.0739379071,  0.0004449163,  -0.001441115, -0.0105853495, -0.0841325011,  0.0795220601,  0.0830194412,  0.0003421636, -0.0027559101);
s(26,0) = (  0.0281270094, -0.0181749205,  0.0489155036, -0.0175483137,   0.013119165, -0.0746927457,  0.0566684033, -0.0730431976, -0.0005262736, -0.0014102365,  0.0100333243, -0.0838650233,  0.0828133996, -0.0822942446, -0.0004047316,  0.0020887236);
s(27,0) = (  0.0283669988,  0.0184374736,  0.0486626862, -0.0176350403, -0.0133586061,  0.0751117167,  0.0561371997, -0.0733253022, -0.0005753554,  0.0011968699,  -0.010216445,  0.0841358817,  0.0837142346, -0.0825887391,  -0.000442478,   0.002127409);
s(28,0) = (  0.0360558481,   9.14677e-05,  0.0403067352,  -4.91545e-05,  -4.29035e-05,  0.0001748244,  0.0554972619,  -0.000105636,    7.2589e-05,   6.50299e-05,  -3.28119e-05,  0.0001359754,  0.1530207145,  -8.94775e-05,   5.58247e-05,  -2.82471e-05);
s(29,0) = (   0.021327397,   0.012115194, -0.0237230849,   0.027938706,  0.0282184353, -0.0102221686, -0.0520902931, -0.0215530201,  0.0257297447,  0.0750264848,  0.0215810009, -0.0292688717,  0.0732392584, -0.0653505331,  0.0197874999,  0.0241451365);
s(30,0) = (    0.02123966,   0.000379419, -0.0237679098,  0.0309950796,  0.0024089918, -0.0003847109, -0.0519801852, -0.0231915418,  0.0384907123,   0.005871232,  0.0018423578, -0.0009955331,  0.0732475969, -0.0716658779,  0.0296013417,  0.0781914244);
s(31,0) = (  0.0212631713, -0.0112145137, -0.0236358261,   0.029155654, -0.0256590654,    0.00957562, -0.0519150784, -0.0219254925,   0.028304101, -0.0710336717, -0.0196236364,   0.027248525,  0.0730006312, -0.0674240805,  0.0217673126,  0.0342091884);
s(32,0) = (  0.0215188023, -0.0213115351, -0.0234476324,  0.0224124582, -0.0384915423,  0.0170818772, -0.0521975656, -0.0176566637,  0.0011767846,  -0.059072363, -0.0294377062,  0.0504752063,  0.0728419623, -0.0526789519,   0.000905008, -0.0528654486);
s(33,0) = (  0.0218233587, -0.0288163397,  -0.023257825,  0.0117636387, -0.0276282836,  0.0213967241, -0.0525622991, -0.0102657414, -0.0270561122,  0.0279835368, -0.0211296625,  0.0662282484,  0.0727204707, -0.0289013174, -0.0208075448, -0.0735578262);
s(34,0) = (  0.0218699203, -0.0318770995, -0.0231040954, -0.0004701099,  0.0003414004,  0.0229214438, -0.0525210601, -0.0007971091, -0.0387258412,  0.0790631681,  0.0002610975,  0.0723759951,  0.0724446558, -0.0005527991, -0.0297821679, -0.0001119608);
s(35,0) = (   0.021594585, -0.0292760512, -0.0230583586,  -0.012424511,  0.0282284953,  0.0219505936, -0.0520217731,  0.0090871477, -0.0267841271,  0.0284455645,  0.0215886946,  0.0675874562,  0.0721074204,  0.0280363769, -0.0205983743,  0.0748034452);
s(36,0) = (  0.0212490983, -0.0213611985,  -0.023185821, -0.0221319824,   0.037795385,  0.0176656126, -0.0515366887,  0.0170414257,  0.0013661591, -0.0582734104,  0.0289052964,  0.0513707686,  0.0720712489,  0.0514557789,  0.0010506467,  0.0528910544);
s(37,0) = (  0.0210887679, -0.0107511278, -0.0233946499, -0.0282803279,  0.0248227533,  0.0099087553, -0.0514192897,  0.0216950334,  0.0274209054, -0.0696570192,  0.0189840385,  0.0271545348,  0.0723841591,  0.0660079864,  0.0210880897, -0.0329198821);
s(38,0) = (  0.0210767542,  0.0001405387, -0.0234908553, -0.0304983727, -0.0004698902,  0.0001463433,  -0.051454073,  0.0231612809,  0.0378238396,  0.0002429072, -0.0003593644,   3.53583e-05,  0.0726197073,  0.0710085331,  0.0290884823,  -0.078298564);
s(39,0) = (  0.0210215588,  0.0115857547,   -0.02330913, -0.0280655551, -0.0270484411, -0.0106208131, -0.0511899348,  0.0213378927,  0.0262045777,    0.07511895, -0.0206862083, -0.0291809753,  0.0722680049,  0.0652098964,   0.020152671,  -0.026493571);
s(40,0) = (   0.020846692,   0.020515623,  -0.022942872, -0.0214247321, -0.0358597647, -0.0177685019, -0.0505891284,  0.0164958233,  0.0004355393,  0.0548159297, -0.0274249655, -0.0504837085,  0.0714098499,  0.0497957389,  0.0003349522,  0.0550493837);
s(41,0) = (   0.020692435,  0.0271662867, -0.0226459564, -0.0116593606, -0.0253211934, -0.0215867848, -0.0500950687,  0.0089846273, -0.0253549388, -0.0282222446, -0.0193652374, -0.0644578741,  0.0706693223,  0.0269573613, -0.0194992548,  0.0710781974);
s(42,0) = (  0.0207369792,  0.0302995658, -0.0226416086, -0.0008463296, -0.0022669554,  -0.022693198, -0.0501829957,    0.00023058, -0.0370829081, -0.0776389576, -0.0017337306, -0.0700935988,  0.0706604308,  0.0013503775, -0.0285186677,  0.0068109228);
s(43,0) = (  0.0210162717,  0.0287366214, -0.0229875004,  0.0112443511,  0.0249786093, -0.0214709392, -0.0509536325, -0.0096106533, -0.0275326322, -0.0333225547,  0.0191032346, -0.0662550486,  0.0715451021, -0.0273325263, -0.0211740133, -0.0717903895);
s(44,0) = (  0.0212689273,   0.022450722, -0.0234180462,  0.0207386701,  0.0369623043, -0.0176505673, -0.0517398431,  -0.016810655, -0.0024726375,  0.0501387798,  0.0282681699, -0.0527277224,  0.0725939141, -0.0493723544, -0.0019015857, -0.0611718176);


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
////route(n_inputs,n_outputs,outs) = m.bus(n_inputs)
////                               <: par(i,n_outputs,(0,gate_bus(i,outs)):>_


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
