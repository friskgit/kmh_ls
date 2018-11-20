// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 04-Nov-2018 17:35:10

//------- decoder information -------
// decoder file = ../decoders/KMHLS_FullSetup_3h3v_allrad_5200_rE_max_2_band.dsp
// description = KMHLS_FullSetup_3h3v_allrad_5200_rE_max_2_band
// speaker array name = KMHLS_FullSetup
// horizontal order   = 3
// vertical order     = 3
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HV
// input channel order: W Y Z X V T R S U Q O M K L N P 
// output speaker order: S1 S2 S3 S4 S5 S6 S7 S8 S9 S10 S11 S12 S13 S14 S15 S16 S17 S18 S19 S20 S21 S22 S23 S24 S25 S26 S27 S28 S29 S33 S34 S35 S36 S37 S38 S39 S40 S41 S42 S43 S44 S45 S46 S47 S48 
//-------


// start decoder configuration
declare name "KMHLS_FullSetup_3h3v_full_6";

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
rs = (          5.13,         5.137,         5.137,         5.134,          5.13,         5.137,         5.137,         5.134,          5.13,         5.137,         5.137,         5.134,          5.13,         5.137,         5.137,         5.134,         5.204,         5.204,         5.204,         5.204,         5.204,         5.204,         5.204,         5.204,         5.321,         5.321,         5.321,         5.321,          5.34,          4.68,          4.67,          4.68,          4.67,          4.68,          4.67,          4.68,          4.67,          4.68,          4.67,          4.68,          4.67,          4.68,          4.67,          4.68,          4.67);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1);
gamma(1) = (             1,  0.8611363116,  0.6123336207,   0.304746985);

// gain matrix
s(00,0) = (  0.0202876513,  0.0297266425,  0.0149117441,  0.0489643672,  0.0672787334,  0.0210625147,   -0.03726303,  0.0330791768,  0.0352966554,   0.086992999,  0.0491522798, -0.0236162059, -0.0398402772, -0.0410845347,  0.0231808606, -0.0047892942);
s(01,0) = (  0.0148930529,  0.0059429141,  0.0081434539,  0.0426224151,  0.0160147002,  0.0033428676, -0.0312464331,  0.0219085699,  0.0565179216,  0.0279606001,  0.0095417019, -0.0059679969, -0.0240762742,  -0.045125815,   0.030657757,  0.0638153839);
s(02,0) = (  0.0203129975, -0.0136027847,  0.0149225192,  0.0557175872, -0.0352983147, -0.0084932597, -0.0373202888,  0.0383132267,  0.0673839922, -0.0581351376, -0.0231709431,  0.0123580171, -0.0398743978, -0.0458414347,  0.0491935112,  0.0650293184);
s(03,0) = (  0.0149006869, -0.0259614057,  0.0081500327,  0.0343477698, -0.0565492067,  -0.013144476, -0.0312660584,  0.0178651291,  0.0159787136, -0.0648756795, -0.0306826239,  0.0277223184, -0.0241021401, -0.0361421774,  0.0095264601, -0.0254269453);
s(04,0) = (  0.0203036796, -0.0489911445,   0.014932782,  0.0297635795, -0.0673457792, -0.0331161994, -0.0372782784,  0.0211000418, -0.0352806522, -0.0048662371, -0.0492256193,  0.0410798776, -0.0398819709, -0.0236276347, -0.0231810879, -0.0870443694);
s(05,0) = (  0.0148720972, -0.0425610559,  0.0081455726,   0.005935845, -0.0159944454,  -0.021911849, -0.0311960309,  0.0033472354, -0.0564357786,  0.0637235413, -0.0095516923,  0.0450483902, -0.0240773989, -0.0059519672, -0.0306573971, -0.0279246224);
s(06,0) = (  0.0203344124, -0.0557793555,  0.0149185453, -0.0136150345,  0.0353310083, -0.0383059675, -0.0373734074, -0.0084833896, -0.0674619682,  0.0651064369,  0.0231471467,  0.0459248512, -0.0398615201,  0.0123815399, -0.0491969498,  0.0581870985);
s(07,0) = (  0.0149042737, -0.0343635258,  0.0081851202, -0.0259481273,  0.0565367609, -0.0179465403, -0.0312413917, -0.0131865985, -0.0160292482, -0.0253480985,  0.0307903503,  0.0360911441,  -0.024186316,  0.0276617423, -0.0096018156,  0.0649076338);
s(08,0) = (  0.0203014626, -0.0297484774,  0.0149227358, -0.0489939637,  0.0673240361, -0.0210804279, -0.0372758714, -0.0330963363,  0.0353120556, -0.0870467284,  0.0491853791,  0.0236157169, -0.0398498325,  0.0410878561,  0.0231794435,  0.0048022951);
s(09,0) = (  0.0148902343, -0.0059353064,  0.0081684842, -0.0426095995,  0.0159924474, -0.0033505019, -0.0312125282, -0.0219700142,  0.0564990369, -0.0279212812,  0.0095601818,  0.0059447804, -0.0241286036,  0.0450445976,  0.0307363241, -0.0637975156);
s(10,0) = (  0.0203095769,  0.0136255609,  0.0148981946, -0.0557105013, -0.0353527126,  0.0085057102,  -0.037343439, -0.0382550281,  0.0673673993,  0.0582116396, -0.0232035346, -0.0123769457, -0.0398291375,  0.0459052786,  0.0491209223,  -0.064992923);
s(11,0) = (  0.0149297476,  0.0260005299,  0.0081851138, -0.0344149469, -0.0566367525,  0.0131913361, -0.0312940556, -0.0179393455,  0.0160282884,  0.0649905646,  -0.030790567, -0.0277165373, -0.0241737707,  0.0361467855,  0.0095778079,  0.0254303502);
s(12,0) = (  0.0202986639,  0.0489923479,   0.014920154, -0.0297393029, -0.0673100326,  0.0331008038, -0.0372808327, -0.0210673405, -0.0353218881,  0.0047816266, -0.0491700508, -0.0411001104, -0.0398567382,  0.0236298991, -0.0232096182,  0.0870362475);
s(13,0) = (  0.0148886632,   0.042609771,  0.0081499261,  -0.005934559, -0.0159919728,  0.0219269798, -0.0312380161, -0.0033394118, -0.0565004308, -0.0637939791, -0.0095313327,  -0.045114824, -0.0240994506,  0.0059588126, -0.0306850291,  0.0279206535);
s(14,0) = (  0.0203153676,  0.0557234726,  0.0149231509,  0.0136076102,  0.0353080598,  0.0383137055, -0.0373244241,  0.0084990056, -0.0673896371, -0.0650328672,  0.0231838746, -0.0458484926, -0.0398704076, -0.0123535537, -0.0491949318, -0.0581459867);
s(15,0) = (  0.0148994292,  0.0343460338,  0.0081661475,   0.025954395,  0.0565404715,  0.0179006817,  -0.031246582,  0.0131673502, -0.0159879344,  0.0254110277,  0.0307412214, -0.0361051986, -0.0241376265, -0.0276900378, -0.0095517761, -0.0648815482);
s(16,0) = (  0.0380113964,   0.070419014,  0.0713918737,  0.0407315152,  0.0693638888,  0.1222457219,  0.0240182792,  0.0677860839, -0.0373808763,  0.0052889348,  0.1202940882,  0.0935748742, -0.0549737819,  0.0452741779, -0.0702121629, -0.0629687609);
s(17,0) = (  0.0306211721,  0.0165528978,  0.0533641272,  0.0680427388,  0.0322919601,  0.0281496081,  0.0055090701,  0.1100413943,  0.0644991987,  0.0382097096,  0.0575037652,  0.0195675694, -0.0632949428,  0.0646973498,  0.1082953167,  0.0476979946);
s(18,0) = (  0.0380027528, -0.0407191393,  0.0713844673,  0.0704004065, -0.0693433587, -0.0677757394,  0.0240351947,  0.1222313142,  0.0373720446, -0.0629532425,  -0.120279476, -0.0452842568, -0.0549494325,   0.093594237,  0.0702060563, -0.0052855645);
s(19,0) = (  0.0306312963, -0.0680621922,  0.0533828762,  0.0165509432, -0.0322841511, -0.1100701746,  0.0055179064,  0.0281504572, -0.0645165278,   0.047710903, -0.0574916937, -0.0647155286,  -0.063298276,  0.0195817778, -0.1083150329,  -0.038201093);
s(20,0) = (  0.0379997646, -0.0703880089,  0.0713776112, -0.0407267604,  0.0693578668, -0.1222077831,  0.0240365217, -0.0677757203, -0.0373438941, -0.0053327195,  0.1202824868, -0.0935813031,   -0.05492177, -0.0452666239,  -0.070170792,  0.0629598014);
s(21,0) = (  0.0306194443, -0.0165485808,  0.0533547184, -0.0680444218,  0.0322900754, -0.0281370846,  0.0054927342, -0.1100303216,   0.064507223, -0.0382186252,  0.0574860077, -0.0195536035, -0.0632990924,  -0.064664791,  0.1082990353, -0.0477018332);
s(22,0) = (  0.0380205423,  0.0407218497,  0.0714204721, -0.0704326307, -0.0693497977,  0.0677810795,   0.024061545,  -0.122280171,   0.037406373,  0.0629670619, -0.1202847842,  0.0452942272, -0.0549330057, -0.0936234551,  0.0702544345,  0.0052570658);
s(23,0) = (  0.0306213415,  0.0680327787,  0.0533733621, -0.0165659805, -0.0323141482,  0.1100449557,  0.0055321232, -0.0281700179, -0.0644711985, -0.0476547056, -0.0575361199,  0.0647337729,  -0.063280135, -0.0195808404, -0.1082721746,  0.0382310846);
s(24,0) = (  0.0343548857,  0.0398818491,   0.088532239, -0.0151160013, -0.0138234886,  0.0947999705,  0.1063573938, -0.0365986826,  -0.016917791, -0.0038678002, -0.0346706227,  0.1384719347,  0.0837237586, -0.0552506736, -0.0417347168,  0.0062344826);
s(25,0) = (  0.0343682304,  0.0151120816,  0.0885702172,  0.0398855512,  0.0138143112,  0.0365897044,   0.106411387,  0.0948148679,  0.0169033884,  0.0062242632,  0.0346489343,  0.0552367398,  0.0837755844,  0.1385059836,  0.0417001364,  0.0038560681);
s(26,0) = (  0.0343613365, -0.0398955896,  0.0885481856,  0.0151123496, -0.0138333298, -0.0948298604,   0.106375245,  0.0365866404, -0.0169290993,  0.0038815699, -0.0346910407, -0.1385113125,  0.0837373991,  0.0552231536, -0.0417516503,  -0.006253105);
s(27,0) = (  0.0343735455, -0.0151262899,  0.0885795459, -0.0398976973,  0.0138334818,  -0.036619387,  0.1064117692, -0.0948377101,  0.0169098118, -0.0062378497,  0.0346896853, -0.0552722961,  0.0837617606, -0.1385268253,  0.0417159904, -0.0038529319);
s(28,0) = (  0.0116283448,   1.24741e-05,  0.0343458244,   -6.0311e-06,    1.0774e-06,   3.40799e-05,  0.0554784962,  -1.62779e-05,    5.2644e-06,    2.5671e-06,     3.019e-06,    6.2012e-05,  0.0740768677,  -2.90406e-05,    1.5711e-05,    1.6007e-06);
s(29,0) = (  0.0332831817,  0.0555503148, -0.0381102487,  0.0645700365,  0.1048690719, -0.0532736038, -0.0265088273, -0.0620446584,  0.0158079615,  0.0987097394, -0.0971789744, -0.0074881662,  0.0450774983, -0.0085648378, -0.0148663455, -0.0620865798);
s(30,0) = (  0.0332647088,  0.0268499126, -0.0381096993,    0.08078344,  0.0634545018, -0.0257474565, -0.0264804254, -0.0776333391,   0.084898323,  0.0956609038, -0.0587526628, -0.0036296079,  0.0451147814, -0.0107201437, -0.0788537639,  0.0665692557);
s(31,0) = (  0.0332889547, -0.0063592984, -0.0381259428,   0.084942507, -0.0157546839,  0.0062100437, -0.0264770764, -0.0815456862,  0.1048784839, -0.0257988961,  0.0148861251,  0.0007226657,  0.0450250749,  -0.011327129,   -0.09716551,  0.1137278704);
s(32,0) = (  0.0332731055, -0.0381565154, -0.0380812403,  0.0761405648, -0.0849507963,  0.0366610224, -0.0265425548, -0.0730624673,  0.0634803441, -0.1147884329,  0.0787972311,  0.0050690269,  0.0450985191, -0.0102268551, -0.0587368263,  0.0205600427);
s(33,0) = (  0.0332842348, -0.0645600038, -0.0381483656,  0.0555341243, -0.1048360638,  0.0620924992, -0.0264363737, -0.0532952533,  -0.015813225, -0.0620584984,  0.0972184028,  0.0084727717,  0.0450568161, -0.0074275551,    0.01490477, -0.0986852777);
s(34,0) = (  0.0332721145, -0.0808115465, -0.0380982391,  0.0268356944, -0.0634323723,  0.0776089425, -0.0265039155, -0.0257158291, -0.0849547031,  0.0666567254,   0.058691351,  0.0107694785,  0.0450804278, -0.0036500516,  0.0788433113, -0.0956472913);
s(35,0) = (  0.0332764846, -0.0849192104, -0.0381146708, -0.0063509984,  0.0157369125,  0.0815530256, -0.0264817496,  0.0061961742, -0.1048513973,  0.1137008253, -0.0148529528,  0.0112949237,  0.0450814762,  0.0007273187,  0.0971851072,  0.0257762431);
s(36,0) = (  0.0332780677, -0.0761373181, -0.0381082248, -0.0381584289,  0.0849498294,  0.0730908249, -0.0265027589,  0.0366740092, -0.0634670891,  0.0205387338, -0.0788197657,  0.0101825455,  0.0450816551,  0.0050588908,  0.0587534533,  0.1147795381);
s(37,0) = (  0.0332831754, -0.0555537339, -0.0381257523,  -0.064552008,  0.1048604267,  0.0532821084, -0.0264656966,  0.0620499754,  0.0157690351, -0.0986704181, -0.0971801633,  0.0074615742,  0.0450405908,  0.0085114637, -0.0148640698,  0.0621376747);
s(38,0) = (   0.033262025,   -0.02683331,  -0.038106907, -0.0807815486,  0.0634244609,  0.0257299773, -0.0264737523,  0.0776301677,   0.084913401, -0.0956328312, -0.0587256485,  0.0036356788,  0.0451015225,  0.0107112616, -0.0788586638, -0.0666105993);
s(39,0) = (  0.0332889362,  0.0063723465, -0.0381110189, -0.0849515576, -0.0157880992, -0.0062148454,  -0.026511586,   0.081531368,  0.1048899032,  0.0258542794,  0.0148955627, -0.0007351595,  0.0450495131,  0.0113706473, -0.0971546459,   -0.11373347);
s(40,0) = (  0.0332756908,  0.0381559624, -0.0380960908, -0.0761377787,   -0.08494717, -0.0366713861, -0.0265181269,  0.0730725784,  0.0634754891,   0.114782502,  0.0788160802, -0.0050579153,   0.045085587,  0.0102043279, -0.0587313785, -0.0205581221);
s(41,0) = (  0.0332954171,  0.0645831634,  -0.038125736, -0.0555742417, -0.1049002459, -0.0620576654, -0.0265034338,  0.0532850213, -0.0157893063,  0.0621354631,  0.0971868825, -0.0085588732,  0.0450579213,  0.0074884495,  0.0148783533,  0.0987117205);
s(42,0) = (  0.0332589062,  0.0807724329,  -0.038106425, -0.0268395007, -0.0634306377, -0.0776333222, -0.0264746994,  0.0257443272, -0.0848944414, -0.0665812916,  0.0587464699, -0.0107077933,  0.0451193891,   0.003620543,  0.0788589033,   0.095629328);
s(43,0) = (  0.0332866938,  0.0849326916, -0.0381360892,  0.0063599618,  0.0157526739, -0.0815692766, -0.0264612977, -0.0062161797, -0.1048605755, -0.1136994328, -0.0148935161, -0.0112916672,  0.0450462376, -0.0007140876,  0.0971953317, -0.0257925406);
s(44,0) = (  0.0332847552,  0.0761565383, -0.0381014865,  0.0381720357,  0.0849756721, -0.0730759736,  -0.026528459, -0.0366880602, -0.0634856096, -0.0205540947,  -0.078833773, -0.0102195483,  0.0450876333, -0.0050463616,  0.0587200902, -0.1148136353);


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
