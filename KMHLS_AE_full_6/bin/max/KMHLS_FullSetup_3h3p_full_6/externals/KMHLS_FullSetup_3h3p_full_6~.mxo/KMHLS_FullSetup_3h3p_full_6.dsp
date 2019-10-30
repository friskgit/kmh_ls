// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.7.0) at 28-Oct-2019 23:12:53

//------- decoder information -------
// decoder file = ../decoders/KMHLS_FullSetup_3h3p_allrad_5200_rE_max_2_band.dsp
// description = KMHLS_FullSetup_3h3p_allrad_5200_rE_max_2_band
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
declare name "KMHLS_FullSetup_3h3p_full_6";

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
s(00,0) = (  0.0173517055,  0.0296654548,  0.0146881238,  0.0385625593,  0.0617547406,  0.0242265677, -0.0304204424,  0.0301655273,   0.016700725,  0.0673834744,  0.0523507333, -0.0211637868, -0.0395116522,  -0.029526496,  0.0118537247, -0.0270355077);
s(01,0) = (  0.0121423434,   0.008166631,  0.0080504287,   0.033948018,  0.0215195561,  0.0053739679, -0.0246715269,  0.0212768029,  0.0422492512,  0.0362625092,   0.015085925,  -0.007798497, -0.0239365806, -0.0338370016,  0.0280507115,  0.0425728351);
s(02,0) = (  0.0174661019,  -0.006535444,   0.014732654,  0.0485469447, -0.0173188131, -0.0043816192, -0.0307154107,   0.038575807,  0.0620233563, -0.0295073609, -0.0123431639,  0.0061069487, -0.0397144989, -0.0362964768,  0.0524349656,  0.0668049169);
s(03,0) = (  0.0121692494, -0.0184110658,     0.0080647,  0.0297580194, -0.0425395078, -0.0113458644, -0.0247318656,  0.0188293614,  0.0211584261, -0.0557727435, -0.0282275621,  0.0186099617, -0.0239814551, -0.0294251209,  0.0148658184, -0.0052783762);
s(04,0) = (  0.0177769474, -0.0399229285,   0.015043623,  0.0297978742, -0.0625922985, -0.0312496123, -0.0311855749,  0.0243329644, -0.0188865548, -0.0245526329, -0.0531047042,  0.0305635897, -0.0404913973, -0.0212846224, -0.0137054213, -0.0697592768);
s(05,0) = (  0.0122919182, -0.0345108213,   0.008136989,  0.0076172284, -0.0201381578, -0.0216047173, -0.0249998318,   0.005027099, -0.0435210991,  0.0450030794, -0.0141670747,   0.034448976, -0.0242176159, -0.0072634917, -0.0288920315, -0.0341287478);
s(06,0) = (  0.0179759708, -0.0496797462,  0.0152102627, -0.0082717252,  0.0216787129, -0.0396130745, -0.0315349869, -0.0057907998, -0.0623923045,  0.0651763201,  0.0161097188,  0.0369253572, -0.0409364886,  0.0073694848, -0.0530006792,  0.0363413541);
s(07,0) = (  0.0124723197, -0.0297759182,  0.0082610322, -0.0199645747,  0.0449877426, -0.0188399483, -0.0253550017, -0.0123225125, -0.0184054127, -0.0116003212,  0.0299154498,  0.0294495407, -0.0245731414,  0.0201492983, -0.0130363411,  0.0559884411);
s(08,0) = (  0.0168837615,  -0.027112731,  0.0141814517, -0.0388887965,  0.0585170324, -0.0220701686, -0.0298001046, -0.0302280145,  0.0218887162, -0.0690746581,  0.0495350401,  0.0195070731,  -0.038324688,  0.0301244596,  0.0161223445,  0.0169625881);
s(09,0) = (  0.0166288795, -0.0065763686,  0.0139324784, -0.0462513406,  0.0174644977, -0.0043610464, -0.0294219552,  -0.036541627,  0.0590953917, -0.0298409646,  0.0123275796,  0.0062190835, -0.0377300667,  0.0349887358,  0.0497830501, -0.0635890604);
s(10,0) = (  0.0122519133,  0.0077890747,  0.0080658692, -0.0343690767, -0.0205832842,  0.0051041465, -0.0249576325, -0.0213943254,  0.0432005364,  0.0348462835, -0.0143775897, -0.0074658054,  -0.024013405,  0.0344122679,  0.0285112084, -0.0443761831);
s(11,0) = (   0.016899001,  0.0280836693,  0.0142656394, -0.0382314023, -0.0595927691,  0.0228417573,  -0.029716101, -0.0299108348,  0.0189450389,   0.067686701, -0.0504664467, -0.0202180887, -0.0384768202,  0.0293273849,   0.014017185,  0.0222228183);
s(12,0) = (  0.0115571903,  0.0278907766,  0.0076511251, -0.0181327538, -0.0414236368,  0.0176248494, -0.0234996259, -0.0111909168, -0.0183374942,  0.0086368018,  -0.027518741, -0.0276104972, -0.0227601348,  0.0183102897, -0.0128853253,  0.0529826969);
s(13,0) = (  0.0171159819,  0.0472527396,  0.0146665511, -0.0080785879, -0.0212455383,  0.0381809964, -0.0297676772, -0.0056105808, -0.0592715296, -0.0617749902,  -0.015679665, -0.0344306597, -0.0393248387,  0.0072763469, -0.0511149104,  0.0357998102);
s(14,0) = (  0.0121517424,  0.0343086964,  0.0080115141,  0.0066573067,  0.0176824781,   0.021377224, -0.0247367827,    0.00447685, -0.0440350552, -0.0470733133,  0.0126653066, -0.0343220192, -0.0238393379, -0.0062313292, -0.0290537462, -0.0302382983);
s(15,0) = (  0.0120597401,  0.0295908519,  0.0080539394,  0.0180607804,  0.0418831286,  0.0188768286,  -0.024445595,  0.0111949218, -0.0214613175,  0.0042459413,  0.0279642858, -0.0291018254, -0.0239206737, -0.0182013398, -0.0152251735, -0.0553320382);
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
s(29,0) = (  0.0339854821,   0.035999882, -0.0359963588,  0.0802532514,  0.0824521556, -0.0316373921, -0.0314096407, -0.0705286381,  0.0734153269,  0.1163306727,  -0.069419295, -0.0087417167,  0.0429094085, -0.0194796025, -0.0618114147,  0.0367406175);
s(30,0) = (  0.0341288712,  0.0021928951, -0.0357965145,  0.0883968747,  0.0055052596, -0.0019055225, -0.0319326832, -0.0768105289,   0.110944865,  0.0091264992, -0.0045699534, -0.0005419473,  0.0425243424,  -0.022290322, -0.0922545824,   0.122487431);
s(31,0) = (  0.0339966103, -0.0318913358, -0.0359743824,  0.0819987258, -0.0746196891,  0.0279819077, -0.0314135265, -0.0719548619,  0.0814200151, -0.1094785314,  0.0627030405,  0.0077611802,  0.0427538122, -0.0199568613, -0.0684331357,  0.0539708241);
s(32,0) = (   0.034376846, -0.0619228317, -0.0360982774,  0.0639806634, -0.1117141593,  0.0539008696, -0.0321240694, -0.0556522259,  0.0036687244, -0.0915021501,  0.0930354105,   0.015513203,  0.0429151797, -0.0160977621,  -0.002993529, -0.0828758926);
s(33,0) = (  0.0344169534, -0.0819450327, -0.0363389296,   0.034927997, -0.0806058354,  0.0717464676, -0.0319378065, -0.0305874358, -0.0773844901,  0.0436926876,  0.0675905582,   0.020160876,  0.0432680588, -0.0085816519,  0.0648753606,  -0.115314396);
s(34,0) = (  0.0347152705, -0.0898382403, -0.0365762853,   1.68337e-05,  -5.12437e-05,  0.0784304454, -0.0322479783,   1.09431e-05, -0.1126450264,  0.1242159033,  -2.72128e-05,  0.0222397576,  0.0433858857,  -2.64533e-05,  0.0941157954, -0.0001025116);
s(35,0) = (  0.0349377949, -0.0831632836, -0.0367748085, -0.0355247348,  0.0818910455,  0.0725768797, -0.0325624004,  0.0309980838, -0.0783597284,  0.0439411936, -0.0684008896,   0.020674531,  0.0437990941,  0.0088331616,  0.0654694828,  0.1168829682);
s(36,0) = (  0.0341170799, -0.0613021601, -0.0359172178, -0.0636048666,  0.1108558581,  0.0535121021, -0.0317292645,  0.0554308921,  0.0041147918, -0.0914314748, -0.0925518664,   0.015193917,  0.0425977844,  0.0158667863, -0.0032696554,  0.0817185159);
s(37,0) = (  0.0325375103, -0.0312354526, -0.0343445682, -0.0783443833,  0.0730925302,  0.0273709521,  -0.030214339,   0.068587093,  0.0771083149, -0.1071969799, -0.0613573967,  0.0076670577,  0.0409235749,  0.0192668228, -0.0646272331, -0.0495528946);
s(38,0) = (  0.0339145867,  0.0011029234, -0.0356718423, -0.0878395366, -0.0027476353, -0.0009809587, -0.0316089789,  0.0765607695,   0.110333793,  0.0044979874,  0.0023437961, -0.0002562781,  0.0423775155,  0.0219239638, -0.0920524384, -0.1220087285);
s(39,0) = (  0.0342118234,  0.0345684767, -0.0361376166, -0.0815256939, -0.0798911279,  -0.030240654, -0.0317157599,  0.0714279527,  0.0772341322,  0.1145522271,  0.0669324505, -0.0085181397,  0.0430093474,  0.0199841155, -0.0648697994, -0.0440146149);
s(40,0) = (  0.0326253698,  0.0602403856, -0.0343579115, -0.0593765981, -0.1065459281, -0.0526132231, -0.0303788546,  0.0518323726,  -0.001534299,  0.0819197645,  0.0890904297, -0.0149274902,   0.040893681,  0.0147467681,  0.0013331096,  0.0855287384);
s(41,0) = (  0.0318444848,  0.0759127503, -0.0335862291, -0.0325001495, -0.0753958231,  -0.066366706, -0.0295739688,  0.0284112945,  -0.071918979, -0.0406321011,  0.0631385874, -0.0187831307,  0.0399058755,  0.0080503083,  0.0602276448,  0.1087938522);
s(42,0) = (  0.0333273946,  0.0863605191, -0.0350535168, -0.0016977392, -0.0042952473, -0.0753044949, -0.0310931068,  0.0014508849, -0.1085804882, -0.1202623352,    0.00350463, -0.0215366704,  0.0417315803,  0.0004438941,   0.090649314,  0.0072027954);
s(43,0) = (  0.0338216882,  0.0818483764,  -0.035705976,   0.031132243,  0.0731207214, -0.0716553948, -0.0313636231, -0.0272042524, -0.0821732263, -0.0561402904, -0.0611936565, -0.0201107959,  0.0424463983, -0.0077010724,  0.0689594017, -0.1079479191);
s(44,0) = (  0.0334724443,  0.0628859015, -0.0351643161,  0.0597497376,  0.1089713154, -0.0547483804, -0.0312497489, -0.0519943656, -0.0055815854,  0.0786904399,   -0.09078485, -0.0157603712,  0.0417637141, -0.0150048179,  0.0046966084,  -0.091834242);


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
