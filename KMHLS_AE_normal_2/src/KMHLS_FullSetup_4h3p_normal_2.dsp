// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 30-Oct-2018 11:22:03

//------- decoder information -------
// decoder file = ../decoders/KMHLS_FullSetup_4h3p_allrad_5200_rE_max_2_band.dsp
// description = KMHLS_FullSetup_4h3p_allrad_5200_rE_max_2_band
// speaker array name = KMHLS_FullSetup
// horizontal order   = 4
// vertical order     = 3
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 44C 
// output speaker order: S1 S2 S3 S4 S5 S6 S7 S8 S9 S10 S11 S12 S13 S14 S15 S16 S17 S18 S19 S20 S21 S22 S23 S24 S25 S26 S27 S28 S29 S33 S34 S35 S36 S37 S38 S39 S40 S41 S42 S43 S44 S45 S46 S47 S48 
//-------


// start decoder configuration
declare name "KMHLS_FullSetup_4h3p_normal_2";

// bands
nbands = 2;

// decoder type
decoder_type = 2;

// crossover frequency in Hz
xover_freq = hslider("xover [unit:Hz]",400,200,800,20): dezipper;

// lfhf_balance
lfhf_ratio = hslider("lf/hf [unit:dB]", 0, -3, +3, 0.1): mu.db2linear : dezipper;


// decoder order
decoder_order = 4;

// ambisonic order of each input component
co = ( 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4);

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
ns = 45;

// radius for each speaker in meters
rs = (          5.13,         5.137,         5.137,         5.134,          5.13,         5.137,         5.137,         5.134,          5.13,         5.137,         5.137,         5.134,          5.13,         5.137,         5.137,         5.134,         5.204,         5.204,         5.204,         5.204,         5.204,         5.204,         5.204,         5.204,         5.321,         5.321,         5.321,         5.321,          5.34,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13,          5.13);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1,             1);
gamma(1) = (             1,  0.9061798459,  0.7317428698,   0.501031171,  0.2457354591);

// gain matrix
s(00,0) = (  0.0182286559,  0.0265463653,  0.0149255974,  0.0437796184,  0.0597486917,  0.0210906775, -0.0322224131,   0.033119103,  0.0314859271,  0.0769157259,  0.0492563807, -0.0192223079, -0.0398919352, -0.0339340077,  0.0232260693, -0.0039055884,  0.0674460999, -0.0442559315);
s(01,0) = (  0.0127005859,  0.0061911691,  0.0081186579,  0.0360247488,  0.0166453463,  0.0034988371, -0.0258851278,  0.0218267191,   0.046854193,  0.0289200737,  0.0100079589, -0.0062956704, -0.0239970202,  -0.036040596,  0.0304789724,  0.0512008895,   0.040844409,  0.0495459102);
s(02,0) = (  0.0184628568, -0.0121571233,  0.0149795753,  0.0504437694, -0.0314335068, -0.0084913359, -0.0327844116,  0.0384877917,  0.0608459721, -0.0516110993, -0.0231884404,  0.0103696473, -0.0400721614, -0.0385445844,  0.0495065368,  0.0586662559,  -0.067586671,  0.0462144301);
s(03,0) = (  0.0125095029, -0.0206399457,  0.0080887668,  0.0294741934, -0.0459349577, -0.0128849742, -0.0254214187,   0.017857143,  0.0167824642, -0.0558692537, -0.0303245426,  0.0204117446, -0.0238987538, -0.0294244476,  0.0100571786, -0.0146949931, -0.0410209519, -0.0478056935);
s(04,0) = (  0.0188619467,  -0.045256478,  0.0150753861,  0.0276790081, -0.0622310845, -0.0334333449, -0.0337324227,  0.0213626724, -0.0321429477, -0.0051192804, -0.0498644791,  0.0358961697, -0.0403692771, -0.0207154976, -0.0233111809, -0.0797274693,  0.0690066726, -0.0472320169);
s(05,0) = (  0.0126510141, -0.0358916541,  0.0081041202,  0.0061099708, -0.0164291553, -0.0217850771, -0.0257624221,   0.003485294, -0.0467263601,  0.0511595126, -0.0099659479,  0.0358580253, -0.0239414693, -0.0061776791,  -0.030421084, -0.0285612191,  0.0403825199,  0.0496666604);
s(06,0) = (  0.0183811404, -0.0502299454,   0.014969318, -0.0120395087,  0.0311355719, -0.0384652625, -0.0325884748,  -0.008472982, -0.0606560266,  0.0586324366,  0.0231429337,  0.0382565768, -0.0400379455,  0.0102177071, -0.0494975021,  0.0511544007, -0.0670687933,  0.0464375892);
s(07,0) = (  0.0128990336, -0.0303811818,  0.0081826549, -0.0213278856,  0.0474327043, -0.0180521072, -0.0263321064, -0.0130509702, -0.0171956006, -0.0153883227,  0.0306911311,  0.0305849897, -0.0241825145,  0.0212993551, -0.0101106559,  0.0575513517, -0.0419619603, -0.0494987122);
s(08,0) = (  0.0185295877, -0.0270704884,  0.0150027633, -0.0444903568,  0.0609139903, -0.0212244307,  -0.032930496, -0.0332821995,  0.0318434181, -0.0782846577,  0.0495592074,   0.019900885, -0.0401251992,  0.0348611787,  0.0232853445,  0.0043991221,  0.0683078267, -0.0455991653);
s(09,0) = (  0.0126773267, -0.0061445649,  0.0081311877, -0.0359588219,  0.0165198506, -0.0034984941, -0.0258008466,  -0.021853954,  0.0467917937, -0.0287101268,  0.0100031309,  0.0062190272, -0.0240071383,  0.0358851235,  0.0305112362, -0.0511901122,  0.0405731795,    0.04963396);
s(10,0) = (  0.0183800709,  0.0120709802,  0.0149421924, -0.0502289062, -0.0312154289,  0.0084867816, -0.0326168533, -0.0383971125,  0.0606447565,  0.0512822436,  -0.023176434,  -0.010242669, -0.0399823188,  0.0383307232,  0.0494040233, -0.0585946711, -0.0672304105,  0.0463591583);
s(11,0) = (  0.0128655223,  0.0212832673,  0.0081845086, -0.0302918056, -0.0473233477,  0.0130531833, -0.0262426331, -0.0180530148,  0.0171129438,  0.0573953487, -0.0306919089, -0.0212250535, -0.0241758087,  0.0304507524,  0.0101078488,  0.0154209042, -0.0417975536, -0.0494666087);
s(12,0) = (  0.0185641151,   0.044588723,  0.0149997655, -0.0271055074, -0.0610085077,  0.0332849096, -0.0330261343, -0.0212117928, -0.0319542043,  0.0043167589, -0.0495437707, -0.0350096634, -0.0401305808,  0.0199751814, -0.0233109366,  0.0784341617,  0.0684838065, -0.0455675835);
s(13,0) = (  0.0126398801,   0.035860475,  0.0081081384, -0.0061013791, -0.0164078743,  0.0217988514, -0.0257374378, -0.0034816166, -0.0466877009, -0.0511209279, -0.0099579824, -0.0358164522, -0.0239621598,  0.0061753869, -0.0304450015,  0.0285277016,  0.0403408294,  0.0496349256);
s(14,0) = (  0.0183865647,  0.0502435389,   0.014968106,  0.0120469707,  0.0311505833,  0.0384571423, -0.0325985267,  0.0084837563, -0.0606695797, -0.0586436805,  0.0231653739, -0.0382736476, -0.0400274235, -0.0102095648, -0.0494741359, -0.0511722298, -0.0670844219,   0.046448984);
s(15,0) = (  0.0131416325,  0.0309018518,  0.0082215965,  0.0218335782,  0.0484699517,  0.0181226355, -0.0269369599,  0.0131464625, -0.0172301575,  0.0162564776,  0.0308863349, -0.0313312278, -0.0243296332, -0.0220029018,   -0.01006193, -0.0585227764, -0.0420873814, -0.0510171288);
s(16,0) = (  0.0380113964,   0.070419014,  0.0713918737,  0.0407315152,  0.0693638888,  0.1222457219,  0.0240182792,  0.0677860839, -0.0373808763,  0.0052889348,  0.1202940882,  0.0935748742, -0.0549737819,  0.0452741779, -0.0702121629, -0.0629687609, -0.0339781804,  -0.028000909);
s(17,0) = (  0.0306211721,  0.0165528978,  0.0533641272,  0.0680427388,  0.0322919601,  0.0281496081,  0.0055090701,  0.1100413943,  0.0644991987,  0.0382097096,  0.0575037652,  0.0195675694, -0.0632949428,  0.0646973498,  0.1082953167,  0.0476979946,   0.034112063,  0.0288213666);
s(18,0) = (  0.0380027528, -0.0407191393,  0.0713844673,  0.0704004065, -0.0693433587, -0.0677757394,  0.0240351947,  0.1222313142,  0.0373720446, -0.0629532425,  -0.120279476, -0.0452842568, -0.0549494325,   0.093594237,  0.0702060563, -0.0052855645, -0.0339714246, -0.0279964217);
s(19,0) = (  0.0306312963, -0.0680621922,  0.0533828762,  0.0165509432, -0.0322841511, -0.1100701746,  0.0055179064,  0.0281504572, -0.0645165278,   0.047710903, -0.0574916937, -0.0647155286,  -0.063298276,  0.0195817778, -0.1083150329,  -0.038201093,  0.0341125397,  0.0288228626);
s(20,0) = (  0.0379997646, -0.0703880089,  0.0713776112, -0.0407267604,  0.0693578668, -0.1222077831,  0.0240365217, -0.0677757203, -0.0373438941, -0.0053327195,  0.1202824868, -0.0935813031,   -0.05492177, -0.0452666239,  -0.070170792,  0.0629598014, -0.0339556414,  -0.028043554);
s(21,0) = (  0.0306194443, -0.0165485808,  0.0533547184, -0.0680444218,  0.0322900754, -0.0281370846,  0.0054927342, -0.1100303216,   0.064507223, -0.0382186252,  0.0574860077, -0.0195536035, -0.0632990924,  -0.064664791,  0.1082990353, -0.0477018332,  0.0341291725,   0.028806552);
s(22,0) = (  0.0380205423,  0.0407218497,  0.0714204721, -0.0704326307, -0.0693497977,  0.0677810795,   0.024061545,  -0.122280171,   0.037406373,  0.0629670619, -0.1202847842,  0.0452942272, -0.0549330057, -0.0936234551,  0.0702544345,  0.0052570658,  -0.033988067, -0.0279814211);
s(23,0) = (  0.0306213415,  0.0680327787,  0.0533733621, -0.0165659805, -0.0323141482,  0.1100449557,  0.0055321232, -0.0281700179, -0.0644711985, -0.0476547056, -0.0575361199,  0.0647337729,  -0.063280135, -0.0195808404, -0.1082721746,  0.0382310846,  0.0341263426,  0.0287723143);
s(24,0) = (  0.0343548857,  0.0398818491,   0.088532239, -0.0151160013, -0.0138234886,  0.0947999705,  0.1063573938, -0.0365986826,  -0.016917791, -0.0038678002, -0.0346706227,  0.1384719347,  0.0837237586, -0.0552506736, -0.0417347168,  0.0062344826,  0.0003698866, -0.0002833052);
s(25,0) = (  0.0343682304,  0.0151120816,  0.0885702172,  0.0398855512,  0.0138143112,  0.0365897044,   0.106411387,  0.0948148679,  0.0169033884,  0.0062242632,  0.0346489343,  0.0552367398,  0.0837755844,  0.1385059836,  0.0417001364,  0.0038560681,  0.0003674145, -0.0002875658);
s(26,0) = (  0.0343613365, -0.0398955896,  0.0885481856,  0.0151123496, -0.0138333298, -0.0948298604,   0.106375245,  0.0365866404, -0.0169290993,  0.0038815699, -0.0346910407, -0.1385113125,  0.0837373991,  0.0552231536, -0.0417516503,  -0.006253105,  0.0003978409, -0.0002741231);
s(27,0) = (  0.0343735455, -0.0151262899,  0.0885795459, -0.0398976973,  0.0138334818,  -0.036619387,  0.1064117692, -0.0948377101,  0.0169098118, -0.0062378497,  0.0346896853, -0.0552722961,  0.0837617606, -0.1385268253,  0.0417159904, -0.0038529319,  0.0003730574, -0.0002950338);
s(28,0) = (  0.0116283448,   1.24741e-05,  0.0343458244,   -6.0311e-06,    1.0774e-06,   3.40799e-05,  0.0554784962,  -1.62779e-05,    5.2644e-06,    2.5671e-06,     3.019e-06,    6.2012e-05,  0.0740768677,  -2.90406e-05,    1.5711e-05,    1.6007e-06,    3.4549e-05,  -1.79769e-05);
s(29,0) = (  0.0092138825, -0.0005980812,   5.05136e-05,  0.0272552931, -0.0016766276, -0.0001205477, -0.0224528054,  0.0001538445,  0.0380298589, -0.0030701596, -0.0003662437,  0.0008109109, -0.0001396165, -0.0373134017,  0.0003052515,  0.0460450375, -0.0046227922,  0.0513756255);
s(30,0) = (  0.0096275782, -0.0204651498,   -2.9502e-06,  0.0197744876, -0.0395942446,   -7.6672e-05, -0.0234633984,   -6.5001e-05, -0.0013597236, -0.0320014595, -0.0001125407,  0.0280138239,   4.19944e-05, -0.0270851523, -0.0003053932, -0.0354836919,  0.0036495389, -0.0528950625);
s(31,0) = (  0.0089606411, -0.0265216383,   8.53588e-05, -0.0006099497,  0.0017088845, -0.0002499324, -0.0218370861, -0.0001001356, -0.0370705403,   0.045015181,  0.0003059609,  0.0363127343, -0.0002575765,  0.0008240048, -0.0004383776,  0.0031270349, -0.0047048764,  0.0504372967);
s(32,0) = (  0.0097279773, -0.0198650945,  -1.18486e-05, -0.0207814729,  0.0399586584,   9.14162e-05, -0.0237044733,  -6.75094e-05,  0.0018091178, -0.0363280151,   7.46929e-05,  0.0272018871,   7.19604e-05,  0.0284403914,  0.0003431356,  0.0316738992,  0.0049098842, -0.0531803676);
s(33,0) = (   0.009018162,   0.000613324,   7.24881e-05, -0.0266876964,  -0.001718343,  0.0001135038, -0.0219730565, -0.0002146918,  0.0372875802,  0.0031441889, -0.0003459893, -0.0008290309, -0.0002149556,   0.036528777,  0.0003899344, -0.0452494658,  -0.004730098,  0.0506548114);
s(34,0) = (  0.0097117621,  0.0207623117,  -1.62627e-05,  -0.019816363, -0.0398899617,   5.77032e-05,    -0.0236681,   9.83255e-05, -0.0018678336,  0.0315369376,  -5.99662e-05,  -0.028421661,   8.70346e-05,  0.0271400673, -0.0003368333,  0.0363427488,  0.0050703229, -0.0530804962);
s(35,0) = (  0.0089696982,  0.0265470614,   7.23775e-05,  0.0005985227,  0.0016780591,  0.0002138382,  -0.021857376,   0.000115695, -0.0371013595, -0.0450437553,  0.0003523747, -0.0363426603, -0.0002153674, -0.0008118204, -0.0003856484, -0.0030734089, -0.0046292289,  0.0504563215);
s(36,0) = (   0.009642169,   0.019588902,   -7.8528e-06,  0.0207002982,  0.0396116605,  -9.23904e-05, -0.0234938115,   8.27948e-05,  0.0022018619,  0.0365599171,   8.43454e-05, -0.0268175996,   5.83255e-05, -0.0283294005,  0.0003772022, -0.0308641345,    0.00605463, -0.0527422659);
s(37,0) = (  0.0622626726, -0.0588530989,  -0.078647037,  0.1391247404, -0.1192069922,   0.062946896,  -0.038593528, -0.1486094768,  0.1159295372, -0.1398016757,  0.1218238225, -0.0009094123,  0.0918037538,  0.0014241049, -0.1183650703,  0.0548856916, -0.1164694119, -0.0023933277);
s(38,0) = (  0.0618812443, -0.1390537854, -0.0773046715,  0.0580306365, -0.1183647887,  0.1465401178, -0.0397035269, -0.0616583216,  -0.117660427,  0.0584108105,  0.1202647438,   0.001254304,   0.090418951,  -1.05966e-05,  0.1178021261, -0.1403906764,  0.1191697998,  0.0019050258);
s(39,0) = (  0.0619989586, -0.1387718186, -0.0778209483, -0.0588730568,  0.1196539088,  0.1472543523, -0.0392071273,  0.0623633082, -0.1158635007,  0.0548233914, -0.1210743788,  -3.96479e-05,  0.0909703092,  -5.99991e-05,  0.1177912305,  0.1409535143,   -0.11804365, -0.0028768225);
s(40,0) = (  0.0621718338, -0.0584813835,  -0.078158667, -0.1392729809,  0.1185687155,  0.0629110964, -0.0391121836,  0.1476707104,  0.1171125652, -0.1395295711, -0.1219744373, -0.0011052603,  0.0912834233,  -1.84419e-05, -0.1174358507,  -0.057686004,  0.1175033486,  0.0021370034);
s(41,0) = (  0.0621942689,  0.0591771975, -0.0781378786, -0.1390757305, -0.1200821995, -0.0627512082, -0.0392181949,  0.1477190052,  0.1157835641,  0.1410895884,  0.1216150419,  0.0001467763,   0.091320167, -0.0002406975, -0.1177878983, -0.0543611078, -0.1177008563, -0.0033581851);
s(42,0) = (  0.0619775098,  0.1389730764, -0.0778429595, -0.0581949391, -0.1181826585, -0.1472150666, -0.0391180677,  0.0625359092, -0.1171928122, -0.0581415167,  0.1214680241, -0.0002124092,  0.0909602196, -0.0009904704,   0.117454099,  0.1394500292,  0.1178938502,  0.0026236593);
s(43,0) = (  0.0618812129,  0.1387846525, -0.0772894831,  0.0586958826,  0.1197935631, -0.1465857306, -0.0397263916, -0.0614849843, -0.1162431053, -0.0550042732, -0.1198788312, -0.0009170043,  0.0904064075, -0.0009238618,  0.1181701918, -0.1417995234, -0.1191430906, -0.0036341752);
s(44,0) = (  0.0622712898,  0.0581953678, -0.0786559562,  0.1394196401,  0.1177940122, -0.0630992343, -0.0386153515, -0.1485802534,  0.1173430917,  0.1383732218, -0.1221824792,  0.0017965325,  0.0918492092,  0.0010484746, -0.1180522436,  0.0582040272,   0.116339149,  0.0029817527);


// ----- do not change anything below here ----

// mask for full ambisonic set to channels in use
input_mask(0) = bus(nc);
input_mask(1) = (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,!,!,!,!,!,!,!,_);


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
