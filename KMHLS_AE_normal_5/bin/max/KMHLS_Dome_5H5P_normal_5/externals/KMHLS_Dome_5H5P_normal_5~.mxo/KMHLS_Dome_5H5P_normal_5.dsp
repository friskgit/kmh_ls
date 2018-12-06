// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 03-Dec-2018 21:28:46

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_5H5P_Slepian24_2_band.dsp
// description = KMHLS_Dome_5H5P_Slepian24_2_band
// speaker array name = KMHLS_Dome
// horizontal order   = 5
// vertical order     = 5
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 
// output speaker order: S1 S2 S3 S4 S5 S6 S7 S8 S9 S10 S11 S12 S13 S14 S15 S16 S17 S18 S19 S20 S21 S22 S23 S24 S25 S26 S27 S28 S29 
//-------


// start decoder configuration
declare name "KMHLS_Dome_5H5P_normal_5";

// bands
nbands = 2;

// decoder type
decoder_type = 2;

// crossover frequency in Hz
xover_freq = hslider("xover [unit:Hz]",400,200,800,20): dezipper;

// lfhf_balance
lfhf_ratio = hslider("lf/hf [unit:dB]", 0, -3, +3, 0.1): mu.db2linear : dezipper;


// decoder order
decoder_order = 5;

// ambisonic order of each input component
co = ( 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5);

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
gamma(0) = (             1,             1,             1,             1,             1,             1);
gamma(1) = (             1,  0.9324695142,  0.8042490924,  0.6282499246,  0.4220050093,  0.2057123111);

// gain matrix
s(00,0) = (  0.0353448226,  0.0385225746, -0.0147816856,  0.0507180156,  0.1461738485,  0.0142057465,  -0.089787826, -0.0302872638,  0.0258366382,  0.1338983734, -0.0389405015, -0.0298985216,   0.032062332,  -0.112352295, -0.0445174997,  0.0067552934,  0.0794597984, -0.0314328899, -0.1341315197, -0.0040761924,  0.0958878309, -0.0123790769, -0.1055920448, -0.0564287518, -0.0584274793,  0.1181218953,  0.0560696674, -0.1600631163,  0.0843660665,  0.0334813617,  -0.059127149,  0.0898759188,  -0.057461502, -0.0763439407, -0.0458776438, -0.1711563025);
s(01,0) = (  0.0322555413,  0.0126651392,   0.003365854,  0.0602869285,   0.062030413,   0.019236601, -0.0632243646, -0.0049089579,  0.0497119307,  0.0512412311, -0.0361212019,  0.0128525972,  0.0034305937, -0.0891554299, -0.0350572376,  0.1106430657,  0.0400125097, -0.0726009035, -0.0707699612,   0.003191768,  0.0551549651, -0.0159288693, -0.1317523392,  0.0373256462,  0.0977444432,  0.1370982332,  0.0282342537, -0.1371925074,  0.0551424917, -0.0004988792,  -0.031292381,  0.0715391352, -0.0897938408, -0.0526964029,  0.0664199876,  0.1415823862);
s(02,0) = (  0.0375745616, -0.0222197028, -0.0067929428,  0.0645604693, -0.0877178354, -0.0205220936,  -0.084591116,  0.0044220124,  0.0515596618,  -0.089209953,  0.0242981764,  -0.001458059,  0.0225511818, -0.0838469069,  0.0060764728,  0.0888530757, -0.0783525113,  0.0587872248,  0.0811487978, -0.0001073468,  0.0851497687, -0.0225852108, -0.0767529491,  0.0203968105,  0.0734387101, -0.2046261913, -0.0552883261,   0.153930169, -0.0515455886, -0.0081573458, -0.0535297706,   0.061686555, -0.0757140437, -0.0542297488,  0.0478238439,  0.0665106297);
s(03,0) = (  0.0363154613, -0.0418588401, -0.0214417801,  0.0475186874, -0.1705308292,  -0.003150309, -0.0991187862, -0.0243307189,  0.0185948967, -0.1264146753,  0.0633179796,  0.0478743453,  0.0427835689, -0.0998035742, -0.0127643462, -0.0343811111, -0.0373306015,  0.0496919545,  0.1691248847, -0.0014905598,  0.1108487982, -0.0123087241, -0.0487898835, -0.0613546343, -0.0959092382,  -0.002052049, -0.0263418037,  0.1765851297, -0.1160795551, -0.0551167764, -0.0689786838,  0.0795080454, -0.0334444486, -0.0454736671, -0.0730370912, -0.1947561116);
s(04,0) = (  0.0331129051,  -0.045986413, -0.0139738402,  0.0317233572, -0.1296715793,  0.0214527285, -0.0847543408, -0.0080406551, -0.0227426823, -0.0149127197,  0.0407854513,  0.0938697001,   0.029166373, -0.0506573063, -0.0062441848, -0.1094430634,  0.0637003748, -0.0520157311,  0.1233997142,  0.0126742495,  0.0900765714,  0.0024693612,  0.0288251292,  0.0129561558, -0.0754453024,  0.1874197733,  0.0449492561, -0.0513009084, -0.0810013243, -0.0739834673, -0.0539314784,  0.0538569256,  0.0319343202,  0.1149728259, -0.0576073374,  0.0581898721);
s(05,0) = (  0.0343441707, -0.0572257857,  -0.001920563,  0.0187728059, -0.0606858682,  0.0078958996, -0.0726064711,  0.0187244874, -0.0521249918,  0.1121475053,  0.0105715934,  0.0920428966,  0.0138469845,  0.0038962651,  0.0341765049, -0.0812132759,  0.0435069469, -0.0153475322,  0.0517320318,  0.0222503151,  0.0692727635,  0.0018894003,  0.1345027802,  0.0629070057,  0.0864654681, -0.1017409017,  0.0307000532, -0.1202309557,  -0.029503531, -0.0648709169, -0.0434428542,  0.0071414706,   0.093092601,  0.1519919099,  0.0577456665,  0.1580308001);
s(06,0) = (  0.0361000712, -0.0648231716, -0.0032201961, -0.0128382119,  0.0591153575,  0.0085740183, -0.0775472634, -0.0033474074, -0.0516257593,  0.1087208249, -0.0245925618,  0.1002517576,  0.0167118306,  0.0096383536,  0.0273848233,  0.0662812981, -0.0587073461,  0.0339611412, -0.0604959818,  0.0162162723,  0.0754542299, -0.0043883856,  0.1240905896, -0.0331404026,  0.1018643805, -0.1335436571, -0.0414259969, -0.0551424016,  0.0428481593, -0.0813213955, -0.0471691397, -0.0175442951,  0.0895478311, -0.1011191181,  0.0683696695,  -0.165800117);
s(07,0) = (  0.0397998327, -0.0569615412, -0.0186038177, -0.0473892591,  0.1738797718,  0.0183030915, -0.1040206877, -0.0094055488, -0.0214945575, -0.0332091975, -0.0459920247,  0.1035100195,  0.0376070724,  0.0480744006,  0.0039135082,  0.1422345805, -0.0378409589,   -0.03395738, -0.1593221986,  0.0133496335,  0.1120589238,  0.0041020127,  0.0410963905, -0.0345500767, -0.0956430738,  0.2021546177,   -0.02670193, -0.0120323121,  0.1000318861, -0.0850143363, -0.0663461715, -0.0509078984,  0.0342101328, -0.1717756992, -0.0728809641, -0.0095806928);
s(08,0) = (  0.0434992893, -0.0408158115, -0.0217482568, -0.0599897566,  0.1547842208, -0.0131299441, -0.1141128484,  0.0223051202,  0.0293816672, -0.1428694803, -0.0310951044,  0.0350057454,  0.0456397716,  0.1133120985,  0.0010565851,  0.0091134374,  0.0607921499,  0.0203357039, -0.1348666215,  0.0056848217,  0.1248542228,  0.0140483768, -0.0471343499,  0.0343220562, -0.0893729007, -0.0668379734,  0.0428971089,  0.1543048269,   0.079328673, -0.0364382162, -0.0786353614, -0.0926091065, -0.0441337786,  0.0341831281,  -0.069138911,  0.1942336281);
s(09,0) = (  0.0339991563, -0.0129195155, -0.0008912257, -0.0568347184,  0.0482052841,  0.0018859601, -0.0704292858,  0.0078525696,  0.0504205647, -0.0531666837, -0.0231414692,   0.016530292,  0.0128803165,  0.0897380425, -0.0373571335, -0.1173055258,   0.031500924,  0.0375787135, -0.0515132843, -0.0062785732,  0.0667168921,  0.0178783717, -0.1361712445, -0.0126477807,  0.1117415056, -0.1193037938,  0.0222281753,   0.095002773,   0.037987632, -0.0250197817, -0.0426092346, -0.0680782113, -0.0918126756,   0.089796405,  0.0757278338, -0.1674638319);
s(10,0) = (  0.0293216727,  0.0218969506,  0.0018747519, -0.0566153708, -0.0599915331,  0.0205955548, -0.0589916514,  0.0034180762,   0.045179037,   0.085775791,  0.0007597701,  0.0013492463,  0.0045747296,   0.084355159, -0.0369226581, -0.0939389504, -0.0499674145, -0.0507080509,  0.0442910763, -0.0014173004,   0.052685398,   0.020865781, -0.1268834656,  0.0023399907,  0.0845593951,  0.1625603778, -0.0352587895, -0.1407556094, -0.0196014629,  0.0063697682, -0.0290050557, -0.0607068598, -0.0836837689,  0.0874439815,  0.0572650897, -0.0802359088);
s(11,0) = (  0.0383682297,  0.0382648619, -0.0208042998, -0.0529592342, -0.1603957399, -0.0155424724, -0.1030164612,  0.0204677107,  0.0217332714,  0.1227437424,  0.0595451141, -0.0686834178,  0.0416084338,  0.1008391391,   0.017483366,  0.0334168755, -0.0480091346,  -0.018750791,  0.1590664891,  0.0051174854,   0.113517255,  0.0114856857, -0.0112912802,  0.0351059823, -0.1010898803,  0.0103472473, -0.0338769574, -0.1344052944, -0.1091710591,  0.0732527238, -0.0693144014,  -0.083609737, -0.0257903006,  0.0132827171, -0.0768184711,  0.2108773591);
s(12,0) = (  0.0409795843,  0.0494942994, -0.0234587302,  -0.038744016, -0.1793794702, -0.0276500303, -0.1101940675, -0.0008440982, -0.0229014471,   0.012906743,  0.0715728827, -0.1072056325,  0.0488583003,  0.0464920451,  0.0170279136,  0.1352168609,  0.0546608446,  0.0612528793,  0.1814127252, -0.0127572694,  0.1233628015, -0.0033123039,  0.0619347994, -0.0449884281, -0.0846327221, -0.1893799316,  0.0385706412,  0.0646791391, -0.1270073947,  0.0852004744,  -0.080007258, -0.0548222426,  0.0417267147, -0.1784688026, -0.0657315533, -0.0646137704);
s(13,0) = (  0.0323841797,  0.0651765215,  0.0023288317, -0.0150005618, -0.0435646543,  0.0129130921, -0.0644018943, -0.0151287646, -0.0546429923, -0.1038974258, -0.0045669414, -0.0736068503,   0.005574323,  -0.002339283,  -0.009779832,  0.0637759466,  0.0532281075, -0.0279252334,  0.0285456517,  -0.025697864,  0.0574063581,  0.0011664898,  0.0766287254, -0.0334400907,   0.099088557,  0.1360460923,  0.0375596508,  0.0584868521, -0.0091822649,  0.0504487849, -0.0335980556, -0.0029871615,  0.0788710074, -0.0992217558,  0.0672562396, -0.1538184815);
s(14,0) = (  0.0364337677,  0.0665002448, -0.0004677899,   0.020987492,  0.1011615842, -0.0076927586, -0.0762638797,  0.0159712047, -0.0533828832, -0.1071182335, -0.0439833117,  -0.101572055,  0.0102640298,  -0.001773328,  0.0392112907, -0.0935880531, -0.0653948795, -0.0326919245, -0.1048663935, -0.0173147502,   0.070789341,   0.004609971,   0.143690791,  0.0721345679,   0.083332805,  0.0873815287,  -0.046144959,    0.05519861,  0.0751985717,  0.0818095409, -0.0403284881,   0.015474782,  0.0970670556,  0.1747082079,  0.0555309209,  0.1894396191);
s(15,0) = (  0.0441035333,  0.0500378704, -0.0274574724,  0.0455917103,  0.1445586002, -0.0386596059, -0.1213114795,  0.0024725882, -0.0134041945,  0.0431537304, -0.0194343865, -0.1222926541,  0.0554848968,  -0.057148209,  0.0370714289, -0.1260923895, -0.0506117808,  0.0760742566, -0.1191674224, -0.0091130874,  0.1372971085, -0.0077526062,  0.0745071776, -0.0038259916, -0.1061973346, -0.2237530428, -0.0357134774,  0.0559526201,  0.0646067298,  0.1010835832, -0.0878262705,  0.0524625156,  0.0355473201,  0.1090234144, -0.0815909844, -0.0113682449);
s(16,0) = ( -0.0283242205, -0.0058454527,  0.0722179173,   0.022113007, -0.1129626589,  0.0138659312,  0.1250964664,  0.1547098033,  0.0262316969, -0.0170585568,  0.1661686853,  0.0144109566, -0.1481537065,  0.1726673923,  0.2088628356, -0.0092318607,  0.0464326057,  0.1807318144,  0.1998284328, -0.0331470071, -0.1934124258, -0.0539753036,  0.2513825589,   0.094703821, -0.0001133779, -0.0077342418,  0.0327645024,   0.242782448, -0.1994990497, -0.0529489659,  0.1731074839, -0.1826933907,  0.0459342077,  0.1268631948,    0.00953361,  0.0050831739);
s(17,0) = (  -0.029346369,  0.0054443576,  0.0782218204,  0.0206753057,  0.1412453273, -0.0299397784,  0.1330002085,  0.1361612346,  0.0172257483,  0.0206496445, -0.2077674383, -0.0319802746,  -0.159655937,   0.149559414,  0.1412513941, -0.0091767279, -0.0554029386, -0.2185153299, -0.2498561652,  0.0459042048, -0.2073870292,  -0.049737135,  0.1708583281,  0.0711569141, -0.0097919897,   0.009228423, -0.0390942892, -0.2936106609,  0.2494428552,  0.0810582748,  0.1845331079, -0.1611550287,  0.0318450549,  0.0972908189,  0.0033259454, -0.0060651942);
s(18,0) = ( -0.0233242208, -0.0231196605,  0.0586405833, -0.0073720567,  0.0945607467, -0.1389801255,  0.1021866742,  0.0128594677, -0.0220475107, -0.0122004279, -0.1388986726, -0.1541960226, -0.1204988012,  0.0145952518, -0.1804359365,  0.0220330901,  0.0634880319,  0.1424730643, -0.1671340136,  0.0402369067, -0.1575634155, -0.0339697512, -0.2181846863, -0.1899352261,  0.0022667823, -0.0105751505,  0.0447994193,  0.1896888594,  0.1668020506,  0.1521543831,  0.1412859284, -0.0547706913, -0.0406137103,  -0.258873377,  0.0094489879,  0.0069503036);
s(19,0) = ( -0.0273376464, -0.0176918358,  0.0732217999,  0.0052117275, -0.1298140157, -0.1309955197,  0.1242497984, -0.0322474772, -0.0188137345, -0.0078788047,  0.1907301427, -0.1452635271, -0.1493693341, -0.0359581137, -0.1484117119,  -0.022628213, -0.0624002282,  0.0416469964,  0.2294776893,  0.0514586049, -0.1939207566,  0.0434408384, -0.1783365476,  0.1958858476, -0.0101301698,  0.0103939559, -0.0440318262,    0.05901809, -0.2290355689,  0.1613165559,  0.1724418424,  0.0809765802, -0.0323751371,  0.2669689808,  0.0024153672, -0.0068312171);
s(20,0) = ( -0.0291554684,  0.0042809985,  0.0737825733, -0.0218671776, -0.1051720831, -0.0224606224,  0.1282143545,  -0.139957397,    0.02125551,  0.0221904068,  0.1547507957, -0.0235009329, -0.1514965834, -0.1536117842,  0.1679503218,  0.0108730507,  0.0646960776, -0.1746936486,  0.1860768245,  0.0363949316, -0.1979465331,  0.0494140817,  0.2018728586, -0.0847302173,  0.0014629019, -0.0107763737,  0.0456518595, -0.2398775794, -0.1857819515,  0.0629449082,  0.1773422342,  0.1632404004,  0.0366905787, -0.1158839581,  0.0108831287,  0.0070825534);
s(21,0) = ( -0.0189564158, -0.0076338078,  0.0518057986, -0.0189823988,  0.0999529626,  0.0076423785,  0.0871869744, -0.1254740816,  0.0215671502, -0.0267934535, -0.1470973098,  0.0068564862, -0.1054459524,  -0.141188199,  0.1771064434,  0.0110503821, -0.0747237817,  0.2123847021, -0.1768611857, -0.0355404668, -0.1365936913,  0.0373859879,  0.2142803224, -0.1182921143, -0.0099642758,  0.0124466803, -0.0527277651,  0.2913903647,   0.176588219, -0.0510916775,  0.1211479222,  0.1408967098,   0.039975818,  -0.158279665, -0.0003160338, -0.0081803286);
s(22,0) = ( -0.0306357768,  0.0215581492,  0.0776807355,  0.0040392598,  0.1284603572,  0.1426511089,  0.1348758011, -0.0278713271, -0.0202794153,  0.0143141223, -0.1887381322,  0.1585066816,  -0.159463898, -0.0279972933, -0.1662021301, -0.0209292012,  0.0633500989, -0.1007431836, -0.2270825522, -0.0477264824, -0.2083097865,  0.0439634068, -0.2010208127,  0.2087551691,   0.001104368, -0.0105521751,  0.0447020889, -0.1391201936,  0.2266441627,  -0.164933965,  0.1865780944,    0.07520123, -0.0374536522,  0.2815739844,  0.0111425927,  0.0069352034);
s(23,0) = (  -0.029644018,  0.0232805581,  0.0786927177, -0.0035883986,  -0.114073487,  0.1596079923,  0.1340275005,  0.0225342903, -0.0252457693,  0.0070049995,  0.1676203074,  0.1767162161, -0.1606910302,  0.0227249492, -0.2009433499,  0.0176541278, -0.0461407124, -0.0857231212,  0.2016645425, -0.0578315577, -0.2088266023, -0.0363707762, -0.2418364414, -0.1744160415, -0.0089731057,  0.0076856214, -0.0325585321, -0.1135392908, -0.2012808075, -0.1898265379,  0.1859132588, -0.0619989215, -0.0441793105,  -0.235406833,  0.0039814962, -0.0050512191);
s(24,0) = (   0.158069192,  0.0589004687,  0.0712929504,  0.0589127965,  0.2955947972,   0.078436705,  -0.105325575,   0.078626178,   2.97637e-05, -0.0001391391, -0.0585693832,  0.0940934271,  0.2442907619,  0.0943056066,  0.0002301421,  0.0001748087,    0.00019619,  0.0007749323, -0.0690497417,  0.1423945171,  0.1753279208,   0.142281924,  0.0002755714,  -0.000967931,  0.0095565876,  -3.26792e-05,  0.0001384387,  0.0008581405,  0.5222647828,  0.1233131295, -0.5436530042,  0.1230265028,   4.93104e-05, -0.0011339256, -0.0141128371,   2.14777e-05);
s(25,0) = (   0.158069192, -0.0590534836,  0.0712929504,  0.0589127965, -0.2968249053, -0.0792156822,  -0.105325575,   0.078626178,   2.97637e-05,   1.15288e-05,  0.0603786568, -0.0949609854,  0.2442907619,  0.0943056066,  0.0002301421,  0.0001748087,    0.00019619,  0.0005904152,  0.0712256186,  -0.142254066,  0.1753279208,   0.142281924,  0.0002755714,  -0.000967931,  0.0095565876,  -3.26792e-05,  0.0001384387,  0.0009714791, -0.5244370107, -0.1225701743, -0.5436530042,  0.1230265028,   4.93104e-05, -0.0011339256, -0.0141128371,   2.14777e-05);
s(26,0) = (   0.158069192, -0.0590534836,  0.0712929504, -0.0590411559,  0.2955947972, -0.0792156822,  -0.105325575, -0.0790262092,   2.97637e-05,   1.15288e-05, -0.0585693832, -0.0949609854,  0.2442907619, -0.0947488059,  0.0002301421,   2.41407e-05,    0.00019619,  0.0005904152, -0.0690497417,  -0.142254066,  0.1753279208,  -0.142366659,  0.0002755714, -0.0007834139,  0.0095565876,  -3.26792e-05,  0.0001384387,  0.0009714791,  0.5222647828, -0.1225701743, -0.5436530042, -0.1228568009,   4.93104e-05, -0.0012472642, -0.0141128371,   2.14777e-05);
s(27,0) = (   0.158069192,  0.0589004687,  0.0712929504, -0.0590411559, -0.2968249053,   0.078436705,  -0.105325575, -0.0790262092,   2.97637e-05, -0.0001391391,  0.0603786568,  0.0940934271,  0.2442907619, -0.0947488059,  0.0002301421,   2.41407e-05,    0.00019619,  0.0007749323,  0.0712256186,  0.1423945171,  0.1753279208,  -0.142366659,  0.0002755714, -0.0007834139,  0.0095565876,  -3.26792e-05,  0.0001384387,  0.0008581405, -0.5244370107,  0.1233131295, -0.5436530042, -0.1228568009,   4.93104e-05, -0.0012472642, -0.0141128371,   2.14777e-05);
s(28,0) = ( -0.3683504077,  0.0002160241,  -0.002921535,  0.0001812159,  0.0017366483,  0.0010997485,  0.5461724041,  0.0005647581,  -8.40399e-05,  0.0001801583, -0.0025543056,  0.0012248059, -0.4532675385,  0.0006257021, -0.0006498224, -0.0002808738, -0.0005539562, -0.0019275773, -0.0030718706, -0.0001982868, -0.3270869009,  0.0001196277, -0.0007780952,  0.0024725227, -0.0269836959,    9.2272e-05, -0.0003908913, -0.0025830298,   0.003066719,  -0.001048893,   1.605447637, -0.0002395826, -0.0001392313,  0.0033617282,  0.0398485864,  -6.06439e-05);


// ----- do not change anything below here ----

// mask for full ambisonic set to channels in use
input_mask(0) = bus(nc);
input_mask(1) = (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_);


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