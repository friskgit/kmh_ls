// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.7.0) at 29-Oct-2019 12:53:02

//------- decoder information -------
// decoder file = ../decoders/KMHLS_FullSetup_3h3p_pinv_even_energy_rV_max_rE_2_band.dsp
// description = KMHLS_FullSetup_3h3p_pinv_even_energy_rV_max_rE_2_band
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
declare name "KMHLS_FullSetup_3h3p_full_2";

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
s(00,0) = (  0.0811890014,  0.0729958705,  0.1516685616,  0.1058265383,  0.1955286809,  0.1221385517, -0.1788418934,  0.1764793736,  0.0736751831,  0.2291840359,  0.1383984707, -0.1203420178, -0.0544278616, -0.1716548452,  0.0530737041, -0.0563216227);
s(01,0) = (  0.0805836114,  0.0288413616,  0.1524526009,  0.1268925079,  0.0952446181,  0.0498984671, -0.1797177471,  0.2081687015,  0.1874399505,  0.1520175239,  0.0657557725, -0.0490719588,  -0.053845539, -0.2016209035,  0.1362378926,  0.1813120978);
s(02,0) = (  0.0801607601, -0.0236173179,  0.1532739683,  0.1293708723, -0.0743314979, -0.0390272234, -0.1799257449,  0.2103362696,  0.1962040677, -0.1234506747, -0.0538078459,  0.0393178139, -0.0540995826, -0.2043788947,   0.142928416,  0.2014562536);
s(03,0) = (  0.0806309054, -0.0682918844,  0.1535026628,  0.1109564535, -0.1904163551, -0.1150148703, -0.1798467697,  0.1817247253,  0.0908379105, -0.2354026517,  -0.133389934,  0.1132837678, -0.0548158408, -0.1779311603,  0.0662244419, -0.0272637568);
s(04,0) = (  0.0817889189, -0.1076010491,  0.1532289175,  0.0724589691, -0.1975696225, -0.1789349676, -0.1798416579,  0.1214738799, -0.0779697991, -0.0522835467, -0.1367432243,  0.1737964053, -0.0555725222, -0.1198794723, -0.0571330729, -0.2314797128);
s(05,0) = (  0.0824428267, -0.1294229389,  0.1530296103,  0.0254880943, -0.0844233315, -0.2114229151, -0.1799977276,  0.0443824422, -0.1938648998,    0.19357662, -0.0586837806,  0.2047543092, -0.0558398526, -0.0436627904, -0.1420363384,  -0.136924293);
s(06,0) = (  0.0818421614, -0.1301288369,   0.153297744, -0.0255391093,   0.084005378, -0.2106735266, -0.1803222582, -0.0427234207, -0.1950186712,  0.1968496656,  0.0563823516,  0.2059742831, -0.0553543873,  0.0432724978, -0.1428774471,  0.1351053014);
s(07,0) = (  0.0803265974, -0.1073289649,  0.1536989419, -0.0721342662,  0.1987017674, -0.1756042968, -0.1807869629, -0.1220424349, -0.0751220046, -0.0564924887,  0.1358477772,  0.1745162227, -0.0540709704,  0.1220855441, -0.0549573809,  0.2313365027);
s(08,0) = (  0.0791144371, -0.0671517584,  0.1534772721, -0.1075988331,  0.1880034194, -0.1134975793, -0.1811143174, -0.1792415649,  0.0886488133, -0.2320205843,  0.1308750082,  0.1140812427, -0.0525106074,  0.1783202503,   0.064724501,  0.0287231601);
s(09,0) = (  0.0789035045, -0.0223175638,  0.1525079032, -0.1259089437,  0.0747592604, -0.0405323777, -0.1808067572, -0.2062737734,  0.1926634175, -0.1247905637,  0.0543499014,  0.0403231827, -0.0516160106,  0.2047396906,  0.1399437335, -0.1974947353);
s(10,0) = (  0.0794107431,  0.0269974664,  0.1511790027,  -0.125871879, -0.0875342172,  0.0440985285, -0.1794016712,  -0.204770499,  0.1904146257,   0.141466813, -0.0592958532, -0.0450252954, -0.0519870385,  0.2033233585,  0.1367771569, -0.1903901721);
s(11,0) = (  0.0799569677,  0.0702822479,  0.1503866362, -0.1056200694, -0.1926887551,  0.1195069478, -0.1772478178, -0.1736270017,  0.0774740693,  0.2299566193, -0.1359349064, -0.1183287009, -0.0536476605,  0.1725430081,  0.0530477105,  0.0505424985);
s(12,0) = (  0.0802570041,  0.1045532969,  0.1503374511, -0.0699313074, -0.1888980592,  0.1768047635, -0.1753069389, -0.1179193726, -0.0774369351,  0.0459832675, -0.1358214464, -0.1714250743, -0.0556686788,  0.1168306119, -0.0602593207,  0.2274459052);
s(13,0) = (  0.0805214968,  0.1250548933,  0.1506579441,  -0.026521799, -0.0859115464,  0.2081377786, -0.1745604425, -0.0467830293, -0.1872988694, -0.1867307438, -0.0630886165, -0.1997146767, -0.0569221568,  0.0455419654,  -0.139657842,  0.1415570838);
s(14,0) = (  0.0809824507,  0.1280436534,  0.1509565305,  0.0230083187,  0.0727000823,  0.2103718355, -0.1753546833,  0.0377832653, -0.1957596541, -0.2039144961,  0.0512290542, -0.2023552683, -0.0568680037, -0.0382907058, -0.1446207332, -0.1210612019);
s(15,0) = (  0.0813522072,  0.1102827005,   0.151175089,  0.0677397865,  0.1870244981,  0.1813628144, -0.1770935355,  0.1143097355, -0.0914811875,   0.025772203,  0.1334749646, -0.1765161668, -0.0557496546, -0.1125799184, -0.0677374664, -0.2346722368);
s(16,0) = (  0.1833958677,  0.0708236872,  0.0301519745,  0.1747077648,  0.0658472524,  0.1158611636,  0.1745441431,  0.2773834437,  0.0652571703,  0.1299288411,  0.2663438928,  0.0691473106, -0.2464654862,  0.1711233311,  0.2779461226,  0.0569466245);
s(17,0) = (  0.1833390289, -0.0735848114,  0.0304611082,  0.1747987102,  -0.066603703, -0.1178282028,  0.1753423722,  0.2771593493,   0.064178467, -0.1320052124, -0.2730722298, -0.0709334768, -0.2475452729,  0.1692599751,  0.2738943114,   0.052464374);
s(18,0) = (  0.1852345375, -0.1768765145,  0.0296976501,  0.0668916172, -0.0631847421, -0.2846142514,  0.1768353036,  0.1083093723, -0.0689972137,  0.0664764957,  -0.254508579, -0.1714383096, -0.2500916279,  0.0646144157, -0.2939996247, -0.1266238389);
s(19,0) = (  0.1827934512, -0.1710462499,  0.0315316023, -0.0796997376,   0.073803822, -0.2714880645,  0.1730708143, -0.1278633727, -0.0584145463,   0.036465166,  0.2919144293,  -0.164095457,  -0.246290554, -0.0763883673, -0.2515087345,  0.1382195254);
s(20,0) = (  0.1796194436, -0.0668478673,  0.0323959545, -0.1733295466,  0.0613467974, -0.1063677621,  0.1686466123, -0.2736577668,  0.0667670125, -0.1244663741,  0.2521628654, -0.0651137143, -0.2399805509, -0.1688732142,  0.2843461019, -0.0631815058);
s(21,0) = (  0.1808324376,  0.0671670775,   0.029874353,  -0.174363358, -0.0623452894,  0.1070481646,  0.1710277355, -0.2726115786,  0.0676470556,  0.1254413276, -0.2535568441,  0.0656047893, -0.2406150743, -0.1701646758,   0.285587244, -0.0648951535);
s(22,0) = (   0.183686822,  0.1713443549,  0.0278569856, -0.0772481383, -0.0681558118,  0.2695036029,  0.1775935399, -0.1228826888, -0.0592721767, -0.0417343233, -0.2850059847,  0.1705213957, -0.2474016273, -0.0760966155, -0.2582811979,   0.134050823);
s(23,0) = (  0.1847348019,  0.1768511561,  0.0284732202,  0.0697356843,  0.0631834547,  0.2777946774,  0.1779686611,  0.1112048209, -0.0667784406,   -0.06018883,  0.2640522405,  0.1734528887, -0.2493253818,  0.0673785843, -0.2853750357, -0.1288286198);
s(24,0) = (  0.1613775832,  0.1705459505,  0.2243405019,  0.1702216898,  0.0062339813,  0.0164986055,  0.2299979114,  0.0140721732, -0.0004174994,  0.0066230093,  0.1261968303,  0.3592544142,  0.2271645686,  0.3585589624,  0.0003729404, -0.0066514001);
s(25,0) = (  0.1620646519, -0.1710761775,  0.2223557351,  0.1702606163, -0.0061636294, -0.0164758374,  0.2323646956,  0.0150450832,  0.0001439853,  -0.006328705, -0.1262300658, -0.3595926178,  0.2261130495,  0.3581485436,  0.0005438795, -0.0074980821);
s(26,0) = (  0.1593039949, -0.1708182221,  0.2250248297, -0.1689842922,  0.0062240387, -0.0145585252,  0.2267429049, -0.0131325293,   9.66254e-05, -0.0058744685,  0.1227403874, -0.3593052056,  0.2312244846,  -0.356891909, -0.0032854435,  0.0068109976);
s(27,0) = (  0.1592189462,  0.1705310761,  0.2259417319, -0.1693409104, -0.0063419051,  0.0157277709,  0.2257324913, -0.0132789236, -0.0005117493,  0.0059548168, -0.1237684729,  0.3592640971,  0.2315638333, -0.3574706012, -0.0023016597,  0.0073259129);
s(28,0) = (  0.1072191756, -0.0002923399,  0.3717416866,  0.0003575473,  -2.94628e-05,  0.0007069731,   0.125658298,  -1.98042e-05, -0.0001245903,   9.22014e-05, -0.0001809946, -0.0003485223,  0.4472179811,  0.0003357967, -0.0002330558,  -2.13891e-05);
s(29,0) = (  0.1870692774,  0.1149834755, -0.1431816098,  0.2605785583,  0.2131121709, -0.0821826091, -0.0619590314, -0.1832614971,  0.1923549527,  0.2416546071, -0.1257389921, -0.0314656529,  0.0790398083, -0.0658324833, -0.1166706181,  0.0794952503);
s(30,0) = (   0.187045013,  0.0068227745, -0.1434275957,  0.2869855512,  0.0153381807, -0.0054984624,  -0.061436288, -0.2015192854,   0.287879205,  0.0193030703, -0.0086572599, -0.0012651626,  0.0787591832, -0.0713848756, -0.1739751848,  0.2534883483);
s(31,0) = (  0.1869899272, -0.1031154745, -0.1433035421,  0.2680108644,  -0.194686262,  0.0731661847, -0.0616754825, -0.1876546867,  0.2122049334, -0.2282988028,  0.1149276652,  0.0288584062,  0.0789415083, -0.0678292263, -0.1281683704,  0.1108154936);
s(32,0) = (  0.1874697988, -0.1983469075, -0.1433669861,  0.2062617928, -0.2889212921,  0.1402918071, -0.0626269493, -0.1441051621,  0.0100446094, -0.1895547743,  0.1705478646,  0.0521675143,  0.0795823943, -0.0542694083, -0.0063390363, -0.1709548562);
s(33,0) = (  0.1881918597, -0.2657861932, -0.1436307473,   0.110931211, -0.2079825141,  0.1862554691, -0.0635434713, -0.0775863291, -0.2014597388,   0.091024012,  0.1235140879,  0.0665320444,   0.080166234, -0.0302412817,  0.1213391537, -0.2381468975);
s(34,0) = (  0.1883624835, -0.2906224749, -0.1436895057,  0.0002284323, -0.0001860661,  0.2023221082, -0.0636234071,  -0.000484483,  -0.290245452,  0.2551139774,  0.0012852824,  0.0717878053,  0.0801370979,  0.0001397343,  0.1754519612, -0.0011235274);
s(35,0) = (  0.1877147972, -0.2664137647, -0.1433788723, -0.1114299274,  0.2101516454,  0.1856096631, -0.0628017712,  0.0776571335, -0.2017232323,  0.0909219487, -0.1237832123,  0.0676939867,  0.0794848893,  0.0306297705,  0.1225140433,   0.240691754);
s(36,0) = (  0.1868202645, -0.1972430228, -0.1430146896, -0.2049824936,  0.2869078106,  0.1385380015, -0.0617375661,  0.1435732417,    0.01037835, -0.1894505422, -0.1706348637,  0.0526175206,  0.0787265096,   0.053813658, -0.0058523086,  0.1697745568);
s(37,0) = (  0.1863019285,   -0.10229318, -0.1428624415, -0.2645942114,  0.1924994939,  0.0726164969, -0.0610978383,  0.1857033562,  0.2077655676, -0.2262015199, -0.1152232759,  0.0282102568,  0.0783253993,  0.0666486061, -0.1260171127, -0.1073875388);
s(38,0) = (  0.1860237843,   6.07568e-05, -0.1426723073, -0.2850455511, -0.0009216893,    5.6172e-05, -0.0609477653,  0.2000686045,  0.2862022873, -0.0003358311,  0.0003999952, -0.0003903804,  0.0782553954,  0.0706105746, -0.1740842618, -0.2536614995);
s(39,0) = (   0.185388775,    0.11195974, -0.1418912706, -0.2605260992, -0.2098367355, -0.0797216635, -0.0610940584,  0.1826886566,  0.1961805996,  0.2415736644,  0.1259843089, -0.0310833603,  0.0782987679,  0.0656943474, -0.1193430188, -0.0855972272);
s(40,0) = (  0.1843846417,  0.1983722365, -0.1406441568, -0.1979498382, -0.2815148044, -0.1402538291, -0.0613777345,  0.1388028541, -0.0012101456,  0.1759689073,  0.1688881754, -0.0522370093,  0.0783503391,  0.0518754726,  0.0010455298,  0.1786583443);
s(41,0) = (  0.1835897293,  0.2583615917, -0.1395754908, -0.1079515656, -0.1993842615, -0.1809462316, -0.0618313151,  0.0759382643, -0.1970657135, -0.0923781682,  0.1189786766, -0.0651272495,  0.0785232105,  0.0293763466,  0.1202510933,  0.2312095468);
s(42,0) = (  0.1837081923,  0.2826108508, -0.1394586446, -0.0083902395, -0.0176514436, -0.1967945897, -0.0623787149,  0.0063149785,  -0.284319351, -0.2522063344,  0.0096643835,  -0.070303395,   0.078867829,  0.0023765221,  0.1728840773,  0.0240825887);
s(43,0) = (  0.1849484046,  0.2645877153, -0.1405840706,  0.1043346399,  0.1946955338, -0.1845620265, -0.0627894713, -0.0729265084, -0.2097134029, -0.1092279036, -0.1167494411, -0.0674500641,  0.0792677236, -0.0283376051,  0.1268977794, -0.2296969634);
s(44,0) = (   0.186314512,  0.2075533738, -0.1420864447,  0.1937063577,  0.2843900923, -0.1461270603, -0.0626240598,  -0.136070596, -0.0196162902,  0.1605443236, -0.1690163617, -0.0551356348,  0.0793352023, -0.0508549139,   0.011367938, -0.1956223341);


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