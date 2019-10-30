// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.7.0) at 29-Oct-2019 12:52:46

//------- decoder information -------
// decoder file = ../decoders/KMHLS_FullSetup_3h3p_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMHLS_FullSetup_3h3p_pinv_energy_limit_050_rV_max_rE_2_band
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
declare name "KMHLS_FullSetup_3h3p_full_4";

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
gamma(1) = (   2.797630071,   2.409140841,   1.713082951,  0.8525693292);

// gain matrix
s(00,0) = ( -0.1589139694,  0.0030770762,  0.5364545794,  0.0043273626,  0.1191254813,  0.1391315631, -0.5145681765,  0.2015127315,  0.0447017947,  0.1502179401,  0.0980835833, -0.1320517502,   0.145619828, -0.1894516395,  0.0385795735,  -0.036931233);
s(01,0) = ( -0.1612090092,   0.000629278,  0.5410796173,  0.0071527876,  0.0583554674,  0.0566642123, -0.5188891805,  0.2368612595,  0.1140187471,   0.099558837,   0.046324946, -0.0537781632,  0.1476883519,  -0.221880365,  0.0981910507,  0.1186121592);
s(02,0) = (  -0.162584744, -0.0005415467,  0.5440388004,  0.0081335819, -0.0451357112, -0.0456056332, -0.5210484411,  0.2391997975,  0.1193985271, -0.0809970606, -0.0383432956,  0.0437992459,   0.148251598, -0.2246220424,  0.1029378699,  0.1316650951);
s(03,0) = ( -0.1620954087, -0.0017355052,  0.5438907218,   0.006033222, -0.1164063437, -0.1327148182, -0.5205533424,  0.2072659837,  0.0552477373, -0.1544023841, -0.0943210567,  0.1255676583,  0.1473523275, -0.1958542893,  0.0477928007, -0.0181956292);
s(04,0) = ( -0.1604339333, -0.0046243034,  0.5418850631,  0.0022768578, -0.1210275588, -0.2051752428, -0.5188025453,  0.1392484418, -0.0475077088, -0.0344753001, -0.0963652827,  0.1921193867,  0.1458721734, -0.1325438086, -0.0409183811, -0.1518832495);
s(05,0) = ( -0.1595721891, -0.0076453604,  0.5408919151, -0.0001762016, -0.0516100793, -0.2415983961, -0.5181266793,  0.0510658769, -0.1180126887,  0.1266291839, -0.0413142691,  0.2257207379,  0.1452843611, -0.0487814948, -0.1020140386, -0.0897749908);
s(06,0) = ( -0.1607382962, -0.0081592096,  0.5427157215, -0.0009825022,  0.0517803117,  -0.240908766,   -0.51991512, -0.0492548857, -0.1187129768,  0.1289046632,  0.0395274874,  0.2267164322,  0.1464222615,  0.0472303464, -0.1026769656,  0.0886498133);
s(07,0) = ( -0.1633030672, -0.0050440077,  0.5462600386, -0.0018301364,  0.1218414699, -0.2018581593, -0.5233911167, -0.1402982309, -0.0458520777, -0.0369079047,  0.0954369608,  0.1923479032,  0.1489936891,  0.1340909215, -0.0395361396,  0.1519265708);
s(08,0) = (  -0.164989018,  -0.000823045,  0.5478908022, -0.0041126345,  0.1147299126, -0.1315913672, -0.5255155489, -0.2051102882,  0.0536742114, -0.1518366785,  0.0922770817,  0.1264262133,  0.1512869965,  0.1954342197,  0.0463965767,  0.0193524449);
s(09,0) = ( -0.1643125907,  0.0013971733,  0.5453740239, -0.0065461757,   0.045124288, -0.0479032839, -0.5238449884, -0.2351778312,  0.1169695639,  -0.081651543,  0.0387924852,  0.0455331234,  0.1515273545,  0.2237695925,  0.1003658599, -0.1288716086);
s(10,0) = ( -0.1613644889,  0.0016347487,   0.538768359, -0.0072686823, -0.0537721219,  0.0496484856, -0.5177287827, -0.2331578277,  0.1158109356,  0.0926547864, -0.0411720664, -0.0486383956,  0.1490291725,  0.2219371602,  0.0980903426,  -0.124471169);
s(11,0) = ( -0.1579047491,  0.0018944504,  0.5315185604, -0.0052958637, -0.1172804112,  0.1359998337,  -0.509904714, -0.1980229813,  0.0473680294,  0.1505755499, -0.0955057035, -0.1297291782,  0.1448345138,  0.1885876953,  0.0381134373,  0.0330215104);
s(12,0) = ( -0.1554249873,  0.0039175322,  0.5265679485, -0.0022913964, -0.1145373253,  0.2006715956, -0.5037432095,  -0.134846015, -0.0467584668,  0.0301209813, -0.0957592386, -0.1882567849,   0.140951098,  0.1280354763, -0.0429701148,  0.1486801941);
s(13,0) = ( -0.1544741641,  0.0067634852,    0.52514139, -0.0002700516, -0.0519268923,  0.2355273812, -0.5015098702, -0.0534632661, -0.1137045537, -0.1222092162, -0.0444297143, -0.2191190307,  0.1390852444,  0.0498912897, -0.0997166445,  0.0924032841);
s(14,0) = ( -0.1549078188,  0.0081871529,  0.5269836937,   0.000602109,  0.0442009986,  0.2379844443, -0.5035819328,  0.0436796888, -0.1190938228, -0.1333813716,  0.0365918184, -0.2217574217,  0.1397848979, -0.0426270352, -0.1031536867,  -0.079478101);
s(15,0) = (  -0.156453958,  0.0065566802,  0.5310313011,  0.0016726278,  0.1136367391,  0.2057773885, -0.5085452068,  0.1312166188, -0.0558036837,  0.0170657713,  0.0948601942, -0.1934575149,  0.1423948951, -0.1246694882, -0.0480135238, -0.1537614863);
s(16,0) = (  0.3499648119,  0.0414057947, -0.5172457985,  0.1062209904,  0.0272547946,  0.0834310509,  0.6201095906,  0.1931660171,  0.0258422908,  0.0849887824,  0.2063768798,  0.0474371299, -0.4095631776,  0.1230344324,  0.2177473897,  0.0374729958);
s(17,0) = (  0.3505944728, -0.0446815968, -0.5184603464,  0.1059750177, -0.0270787382, -0.0819328125,  0.6222299703,  0.1936443833,  0.0252974118, -0.0864849417, -0.2126176353, -0.0509614838,  -0.411242918,   0.121108968,  0.2148310109,  0.0346229018);
s(18,0) = (  0.3553217495, -0.1062435469, -0.5261471735,  0.0400109255, -0.0262939145, -0.2001042745,  0.6303439497,  0.0762932432, -0.0271750962,  0.0438687583, -0.1978247788, -0.1217577386, -0.4168319903,  0.0456842845, -0.2320774893, -0.0828533747);
s(19,0) = (  0.3471885858, -0.1033127807, -0.5109562985, -0.0470639437,  0.0308974138,  -0.189313428,  0.6144353072, -0.0899212479, -0.0226607036,  0.0244791909,   0.225795481, -0.1168955191,  -0.407577756, -0.0527625332, -0.1994046151,  0.0903535196);
s(20,0) = (  0.3377080941, -0.0407508685, -0.4948378158, -0.1044066867,  0.0248900322, -0.0727427623,  0.5960063569, -0.1894354405,  0.0263619697, -0.0812706057,  0.1950523615, -0.0470186708, -0.3949935418, -0.1197302454,   0.221818245,  -0.041473885);
s(21,0) = (  0.3431186938,  0.0400022848, -0.5064994759, -0.1059302919, -0.0255542275,  0.0755914041,  0.6067040309, -0.1875604104,  0.0267274603,  0.0818223169,   -0.19690946,  0.0457343766, -0.3995134034, -0.1216922701,  0.2232014236,  -0.042483233);
s(22,0) = (  0.3549808645,  0.1047824227, -0.5290450976, -0.0464244619, -0.0273393134,  0.1863084973,  0.6318297687, -0.0853402887,  -0.023024124, -0.0278150699, -0.2209730982,   0.122866087, -0.4148065083, -0.0537453769, -0.2039840491,  0.0877753996);
s(23,0) = (  0.3564087733,  0.1078870066, -0.5301136119,  0.0421818928,  0.0251681804,   0.193337141,  0.6337701999,  0.0775489583,  -0.026238874, -0.0396388718,  0.2054055414,  0.1244676555, -0.4172715529,  0.0481899747, -0.2252481003,  -0.084350808);
s(24,0) = (  0.0681516552,  0.1984585316,  0.1963009295,  0.1983370414, -0.0033808385, -0.1190878428,  0.0894538034, -0.1216821789, -0.0001782585,  0.0037629569,  0.0996614998,  0.3716592089,  0.1785272811,  0.3711699282,  0.0001242183, -0.0038566824);
s(25,0) = (   0.073586826, -0.1987414656,  0.1838369797,  0.1978941176,  0.0034501101,  0.1188884257,  0.1009906414, -0.1200803651,  -6.18809e-05, -0.0036294811, -0.0993002884, -0.3718921762,  0.1738046199,  0.3702242073,   0.001180831, -0.0044105913);
s(26,0) = (  0.0622184916, -0.1990147245,  0.2062514696, -0.1972322149, -0.0033358419,  0.1214244661,  0.0776813924,  0.1217897787,  0.0002124775, -0.0031840163,  0.0963917251, -0.3722157945,  0.1866651465, -0.3695237972, -0.0025320459,  0.0038503811);
s(27,0) = (   0.059587806,  0.1985384672,  0.2128116864, -0.1975501552,  0.0032461759, -0.1198607861,  0.0718967012,  0.1215796476, -0.0001885714,  0.0032560414, -0.0975675536,  0.3716541178,  0.1886358952, -0.3700112243, -0.0022796424,  0.0044360874);
s(28,0) = ( -0.2440398725,    0.00010937,  0.9011545206,  -9.11525e-05,  -1.71832e-05, -0.0002066204, -0.5500753058, -0.0001950699, -0.0001556777,   3.28503e-05,  0.0001165249,  0.0002668131,  0.5943475818, -0.0003326878,  0.0007375672,  -2.92715e-05);
s(29,0) = (  0.2195771064,   0.096348109, -0.3371515927,  0.2194453869,  0.1464233059, -0.0984692126,    0.17711899, -0.2218777514,  0.1326587167,  0.1581958926, -0.1119444455,  0.0162898963, -0.0317356749,  0.0428528947, -0.1053162827,  0.0525754537);
s(30,0) = (  0.2203780155,  0.0059084007, -0.3391450698,  0.2421132192,  0.0105640659, -0.0065127474,  0.1791954654, -0.2445161836,  0.1985726927,  0.0126232928,  -0.007587872,  0.0015840843, -0.0326858567,  0.0482298773, -0.1568956313,  0.1662746163);
s(31,0) = (  0.2200439718, -0.0863559309, -0.3385379124,  0.2258458396, -0.1339788725,  0.0880952525,  0.1784335569, -0.2274428261,  0.1463930953, -0.1494861979,   0.102637586, -0.0142718708, -0.0321305795,  0.0436144647, -0.1155611084,  0.0725145843);
s(32,0) = (  0.2197025394, -0.1669667299, -0.3372754137,  0.1732143469, -0.1989694764,  0.1698871929,  0.1762791091, -0.1739647085,  0.0069162911, -0.1240622068,  0.1522947656, -0.0308006191, -0.0307277014,  0.0313023619, -0.0056785166, -0.1121922467);
s(33,0) = (  0.2198093739, -0.2245387542, -0.3367150126,  0.0928307976,  -0.143214647,  0.2267904925,   0.174678119, -0.0931916941, -0.1390637907,  0.0597572088,  0.1102988271, -0.0444019663, -0.0296470233,  0.0158402981,  0.1095429926, -0.1561200848);
s(34,0) = (  0.2199789396, -0.2457383831,   -0.33685037,  0.0002889192,   3.95102e-05,  0.2467847774,  0.1746882819, -0.0005223161, -0.2004575892,  0.1673068792,  0.0011401138, -0.0492178748, -0.0296977906,  0.0005452697,   0.158530645, -0.0006221674);
s(35,0) = (  0.2198394763, -0.2247828285,  -0.337144147, -0.0929932717,  0.1448567455,  0.2256691987,  0.1760201516,  0.0931760968,  -0.139595855,  0.0598700599, -0.1104540476, -0.0431853723, -0.0307732108, -0.0152263062,  0.1110546904,  0.1580336463);
s(36,0) = (  0.2195837655,  -0.165723725, -0.3374423137, -0.1717962001,  0.1973169697,  0.1673559111,  0.1776834752,  0.1727756688,  0.0065688385, -0.1236820665, -0.1520729196, -0.0297531032, -0.0321177307,  -0.031147871, -0.0045169034,  0.1116787282);
s(37,0) = (  0.2194271565, -0.0856082389, -0.3375725856, -0.2225813309,   0.131919478,  0.0873123761,  0.1786483898,  0.2242079604,   0.142791476, -0.1477451783, -0.1024788937, -0.0149267224,  -0.032947341, -0.0433936248, -0.1129283592, -0.0700524654);
s(38,0) = (  0.2189696798,  -1.06075e-05, -0.3367611164, -0.2401223901, -0.0011729124,  0.0004728275,  0.1782654627,  0.2418611512,  0.1972056002,  0.0001169702,  0.0005377933, -0.0009340375, -0.0329410788, -0.0479857249, -0.1565851208, -0.1662888789);
s(39,0) = (  0.2173166694,  0.0933172754, -0.3335915375, -0.2190425518, -0.1442826057, -0.0947407099,  0.1757882809,   0.220413661,  0.1356171246,  0.1584213324,  0.1120340306,  0.0151844646, -0.0318855002, -0.0424462952, -0.1077624327, -0.0567626865);
s(40,0) = (  0.2148018597,  0.1657154847, -0.3288616151, -0.1656966731, -0.1929053935, -0.1677543124,  0.1720267856,  0.1667120389, -0.0001744491,  0.1153254305,  0.1497808802,  0.0300947153, -0.0301990311, -0.0300057628,  0.0003467681,  0.1160338639);
s(41,0) = (  0.2125662234,  0.2163713781,   -0.32456678, -0.0898311593, -0.1362009546, -0.2176878556,  0.1683726425,  0.0906518264, -0.1351854228, -0.0605282927,  0.1050984167,  0.0419633484,  -0.028466523, -0.0150985634,  0.1076117392,  0.1505582826);
s(42,0) = (  0.2120863944,  0.2370251291,  -0.323341877, -0.0066337486, -0.0115648833, -0.2375136108,  0.1667921809,  0.0071519318, -0.1955452269, -0.1652688315,  0.0078743814,  0.0465675333,  -0.027540157, -0.0009018742,  0.1551042128,   0.015320293);
s(43,0) = (  0.2140524765,  0.2219048566, -0.3265588483,  0.0874348754,  0.1338669798, -0.2226526425,  0.1685439034,  -0.087792521, -0.1443994452, -0.0716563238, -0.1043322057,  0.0418413165, -0.0280260094,  0.0151107671,  0.1138692929,  -0.150305395);
s(44,0) = (  0.2170616545,  0.1739129675, -0.3320714148,   0.162573189,  0.1953073064, -0.1757237962,    0.17266447, -0.1640967255, -0.0134853999,  0.1050356548, -0.1506064397,  0.0307273835,  -0.029720498,  0.0298537401,  0.0099439877, -0.1276353982);


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
