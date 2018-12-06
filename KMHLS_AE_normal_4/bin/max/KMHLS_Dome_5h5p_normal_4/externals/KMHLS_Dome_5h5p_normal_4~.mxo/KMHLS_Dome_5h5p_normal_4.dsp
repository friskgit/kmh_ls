// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 06-Dec-2018 21:20:34

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_5h5p_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMHLS_Dome_5h5p_pinv_energy_limit_050_rV_max_rE_2_band
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
declare name "KMHLS_Dome_5h5p_normal_4";

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
gamma(1) = (   1.576136142,   1.469698903,   1.267606062,  0.9902074127,  0.6651373474,  0.3242306084);

// gain matrix
s(00,0) = (-8.663913062e+13,-5.198962834e+13, 1.9717676e+14,-1.264453432e+14, 1.390365604e+14, 4.723388128e+13,-5.60744258e+13, 2.131002301e+14, 1.423517692e+14, 1.095292356e+14,-1.335962073e+14, 7.45504745e+13,-1.484970118e+14,-9.896716476e+13,-1.242364851e+14, 1.390256307e+14, 6.035809873e+13,-6.542679447e+13, 5.823366562e+13,-1.828857115e+14, 1.501402675e+14,-9.352324044e+13, 5.266317093e+13,-1.691446582e+14,-1.22822196e+14, 3.027240917e+13,-6.798765026e+12, 2.275454502e+12,-3.007057958e+13, 1.060174666e+14,-3.39915238e+13, 9.53478657e+13, 3.478452699e+13, 1.084898986e+14, 1.312611948e+14,-4.94667788e+13);
s(01,0) = ( 1.132913638e+14, 8.64699137e+13,-1.562734797e+14, 2.022515693e+14,-9.298468208e+13,-3.931667269e+13, 4.916389589e+13,-2.135546144e+14,-1.785111595e+14,-1.105950096e+13, 1.551094416e+14,-9.321010605e+13, 3.575403062e+13, 8.242275844e+13, 1.05189072e+14,-1.229300984e+14, 3.014231534e+13, 3.199447053e+13,-1.242122743e+14, 1.857043778e+14,-5.482926105e+13, 1.195621923e+13,-3.226832983e+13, 2.278397102e+14, 4.66097844e+13, 3.498531778e+13,-6.826647085e+11,-4.187431572e+13, 3.291534924e+13,-1.063385809e+14, 3.414688677e+13,-3.386807951e+13,-3.244971191e+14,-1.46058534e+14, 1.901657569e+13, 4.564769872e+13);
s(02,0) = ( 1.9007185e+13,-6.107801917e+13, 2.902209371e+13,-5.018799616e+13, 6.196110137e+13, 1.431750673e+13,-8.868762365e+13, 1.532704195e+14, 3.254295687e+14,-4.121545361e+13,-1.294484711e+14, 6.930204748e+13, 5.949138284e+13,-1.304784712e+14,-1.064536822e+14, 1.457330286e+14,-5.505389076e+13, 1.151696008e+13, 1.210997335e+14,-1.23558447e+14,-1.19524525e+13, 6.132407425e+12,-2.59976648e+13,-1.205956499e+14, 1.081730329e+14,-5.634518579e+13, 2.223052794e+12, 2.673193303e+13,-3.290392893e+13, 7.276044888e+13, 1.507146482e+13, 2.776708969e+13, 3.817308597e+14, 5.548312268e+13,-9.421057594e+13, 2.365290706e+13);
s(03,0) = (-3.455903795e+13,-4.684701619e+13, 9.152928635e+13, 4.851179517e+13,-8.625795608e+13, 4.990574032e+13, 1.909290063e+13,-3.930148067e+13,-3.362183618e+14, 6.736776485e+11, 5.226628876e+13,-3.578147248e+13,-1.606951818e+14, 4.484977314e+13, 2.321816569e+14,-7.622050974e+11,-2.29544856e+13,-7.559090158e+13,-3.37870437e+13, 5.272021341e+13, 1.321178963e+14,-7.689202574e+13,-9.985003263e+13,-2.324829228e+13,-1.685147181e+14, 5.490301245e+12,-1.319534029e+13, 5.601693425e+13, 4.143819879e+13,-3.742363315e+13,-2.52932249e+13, 4.610831978e+13,-3.532823395e+14, 3.11137825e+13, 1.651328842e+14,-5.669603229e+13);
s(04,0) = ( 1.094917724e+14, 7.528938575e+13,-1.335000578e+14, 2.011807117e+13,-5.376323155e+13,-1.609630817e+14,-5.220676477e+13, 1.864408364e+13, 3.258096895e+14,-6.835428305e+13, 1.247510081e+13, 1.081409966e+14, 1.643063111e+14,-6.470292098e+13,-3.502105968e+14,-1.861947661e+14, 3.24794025e+13, 7.258271431e+13, 3.18140961e+13, 2.938229889e+13,-1.181596415e+14, 3.974232934e+13, 2.196447595e+14, 1.49760388e+14, 7.381275747e+13, 5.502810452e+13, 2.112968179e+13,-3.900218389e+13, 1.710525747e+12,-4.215285034e+13, 5.188733209e+13,-1.397424731e+13, 1.562537964e+14,-9.238519787e+13,-1.746650115e+14, 1.615984297e+13);
s(05,0) = (-8.783633452e+12,-1.954844594e+14, 5.061253945e+13, 6.360908054e+13, 4.767111076e+13, 2.040613346e+14, 6.146658413e+12,-6.636538619e+13,-2.276189148e+14, 9.174070459e+13,-1.028303628e+14,-8.055158648e+13,-1.04845911e+14, 3.941049142e+13, 3.006294701e+14, 1.630446247e+14, 4.7964898e+13,-4.986216978e+13, 7.872227803e+13,-1.297847347e+13, 9.380218337e+13, 7.906413788e+12,-2.035534537e+14,-2.341556379e+14, 5.880221602e+12,-3.119988065e+13,-6.747799022e+12, 1.069769008e+13,-1.222079011e+13, 2.623261096e+13,-1.516423252e+13,-8.19816561e+12, 1.372416474e+14, 1.742860695e+14, 6.264217013e+13, 4.718088335e+13);
s(06,0) = ( 9.690836822e+12, 1.12577521e+14, 4.631349677e+13,-1.597848188e+14,-7.827753001e+13,-2.214311867e+14,-6.572566991e+13, 1.874861689e+14,-1.47131153e+13,-5.372862587e+10, 1.434006962e+14, 1.519705379e+14, 1.711598172e+13,-6.972977761e+13,-1.891085819e+14,-1.310507012e+14,-3.858238878e+13, 6.890239978e+13,-1.201774468e+14, 3.717748212e+13, 2.323114964e+12,-6.835253924e+13, 2.044581225e+14, 1.995164593e+14, 1.099017403e+13,-3.777292822e+13,-8.678000357e+12,-5.310301612e+13, 3.059303423e+13,-6.194339144e+13, 1.227933118e+13, 5.71999604e+13,-2.22261683e+14,-1.347420184e+14, 6.390597896e+13,-4.85621216e+13);
s(07,0) = ( 6.910088688e+13,-1.505458841e+14,-8.653282132e+13, 1.893875158e+14, 1.380070542e+14, 1.554050936e+14, 2.57812584e+13,-2.789490159e+14, 5.53807221e+13, 2.10960069e+13,-1.23923277e+14,-6.753790146e+13,-8.751151832e+12, 1.261787748e+14, 3.565053313e+13, 1.306412969e+14,-4.626911321e+13,-4.645381439e+13, 7.105853515e+13, 9.088104372e+12, 8.29946648e+12, 1.023348796e+14,-6.17994279e+13,-8.737283077e+13,-1.017487639e+13, 5.813904808e+13, 6.879609059e+12, 2.735262939e+13,-4.589737642e+13, 6.61216182e+12, 1.480440891e+13,-9.959114822e+13, 2.28415155e+14, 2.144760897e+13,-6.134079753e+13,-6.603977463e+12);
s(08,0) = ( 1.236104425e+13, 3.350399895e+13, 3.450026422e+13,-3.118731227e+14,-3.236024189e+13,-7.841514285e+13,-6.769637059e+13, 3.539963959e+14,-1.085388475e+14,-7.729895421e+13, 1.223616419e+14, 4.389141347e+13, 2.137757448e+13,-1.302470937e+14, 1.031595651e+14, 3.822431544e+12, 5.092671049e+13, 1.757321295e+13,-1.083592693e+14, 3.199127104e+13, 1.172015368e+13,-7.606542688e+13,-5.541480949e+13, 2.660192658e+12,-1.793812197e+13,-2.318665333e+13, 3.039185614e+12, 1.510413035e+13, 1.119381285e+13,-3.170531441e+13, 1.078559215e+13, 8.033351917e+13,-1.270182471e+14, 4.078364255e+12,-3.642657366e+13, 5.489401348e+13);
s(09,0) = (-1.915745706e+13,-5.61565438e+12, 7.919084795e+13, 2.704193366e+14, 6.615089792e+13,-2.843273566e+13,-1.787414566e+13,-4.244564497e+14, 1.816935267e+14, 5.796384598e+12,-7.66740974e+13, 7.116549328e+13,-9.009970138e+13, 2.323346375e+14,-1.632778549e+14,-1.030619427e+14, 3.683397619e+13,-3.577156892e+13, 3.579896452e+13,-7.219560912e+13, 8.164428473e+13, 9.936306664e+13, 7.925447588e+13, 5.850020015e+13,-1.739533712e+13,-3.556198729e+13,-9.518390427e+12, 3.094618743e+13,-1.205811846e+13, 2.841124957e+13,-1.209080705e+13,-1.251167116e+14,-7.145286632e+12,-1.1541092e+13, 1.171169645e+14,-4.843618211e+13);
s(10,0) = ( 1.674170122e+14,-5.361334016e+13,-2.54254238e+14,-2.817005915e+14,-2.483072645e+13, 1.497394915e+14, 5.658748358e+13, 3.233890258e+14,-5.05054216e+13, 2.877863929e+13,-9.46526855e+11,-1.887814337e+14, 1.155296009e+14,-1.497117616e+14, 1.385734661e+14, 4.551911616e+13,-5.465536955e+13, 1.265356285e+13, 2.472548596e+13, 1.388829775e+14,-1.186063795e+14,-2.277495232e+13,-1.239609124e+14,-1.222543836e+14, 1.190360816e+14, 4.987291399e+13, 1.038075008e+13,-1.898102998e+13,-3.347233304e+12,-5.04080194e+13, 5.458714582e+13, 5.47986959e+13, 1.102216666e+13, 7.002023795e+13,-1.111970234e+14,-2.493166789e+13);
s(11,0) = (-1.43394477e+14, 1.112587615e+14, 3.154684872e+14, 8.271274878e+13,-8.222897145e+13,-1.869567907e+14,-1.637119894e+14,-1.677751337e+14, 2.158201158e+13, 1.294830366e+13, 5.040367606e+13, 2.038402001e+14,-1.011105641e+14, 1.199307723e+14, 1.269933535e+13,-3.914093281e+13,-3.475742573e+13, 5.151384379e+13,-1.956727005e+13,-1.723927976e+14, 1.541316266e+14, 2.762592845e+13,-1.970989483e+13, 7.384067861e+13,-9.345725415e+13, 6.380398205e+12,-1.00209622e+13,-6.231984725e+13, 3.060742498e+13, 7.781662503e+13,-3.862894293e+13,-5.226665015e+13, 1.499174128e+13,-3.358220567e+13, 6.005364937e+13, 5.927609343e+13);
s(12,0) = ( 1.703991776e+14,-4.928467152e+13,-2.814155397e+14,-4.706112953e+13, 2.757944887e+13, 1.809074535e+14, 1.46867549e+14, 2.677494396e+13, 3.593097696e+13, 7.516808021e+13,-1.110319909e+14,-2.206133329e+14, 1.762125697e+12, 1.017183688e+13,-1.776245382e+14, 5.46130629e+13, 5.049805555e+13,-8.030558444e+13, 1.044307311e+14, 1.190188202e+14,-5.43549033e+13,-8.530330236e+12, 1.678938534e+14, 8.34114456e+12,-6.546047336e+13,-5.364220612e+13,-2.843621582e+12, 5.27314452e+13,-9.749360452e+12,-3.255767577e+13, 3.951299343e+13,-4.221703897e+11,-1.588748807e+14,-2.679599516e+13, 3.502682627e+13,-1.867682931e+13);
s(13,0) = (-4.461202976e+13, 1.164128333e+14, 1.58479538e+14, 6.404390771e+12,-1.025243324e+14,-1.27298394e+14,-1.827922111e+14,-8.928104244e+12,-1.126510503e+14,-1.371285735e+14, 1.203808367e+14, 9.91339519e+13, 7.938131751e+13,-2.740751081e+13, 2.528094313e+14, 2.641261635e+13, 2.730667177e+13, 1.019857654e+14,-6.271580174e+13,-9.166979316e+13, 5.418068261e+12, 5.032453505e+13,-2.14325284e+14,-6.77761695e+12, 1.544241753e+14, 4.004176072e+13, 2.062217888e+13,-4.263789818e+13, 1.913444025e+13, 4.37589209e+13, 5.256496369e+12,-2.795100944e+13, 3.097623572e+14,-3.246585496e+13,-1.442843049e+14,-4.532139432e+13);
s(14,0) = ( 1.213914341e+13,-1.224500394e+13, 1.080873029e+13,-4.128707492e+13, 1.033336309e+14, 8.658124949e+13, 7.247044931e+13, 5.324722256e+13, 2.41364556e+13, 5.299237356e+13,-1.168687671e+14,-5.57616892e+13,-1.59697289e+14, 1.738235246e+13,-2.553350969e+14,-7.892908826e+12,-3.33485232e+13,-1.447499644e+14, 4.02907899e+13,-4.204825362e+13, 9.95788009e+13,-7.628742869e+13, 2.511129168e+14,-1.676846367e+13,-1.210652599e+14, 2.892240439e+13,-2.236917969e+13, 7.339842626e+13,-9.610797719e+12, 3.38962632e+13,-1.351107763e+13, 5.140165986e+13,-2.447238993e+14, 6.784622117e+13, 2.489698844e+14, 5.161995095e+13);
s(15,0) = ( 1.158132453e+14, 9.088094941e+13,-1.482014865e+14, 1.387696617e+14,-3.816637019e+13,-4.313578605e+13,-5.175063784e+13,-1.274560838e+14,-8.121475184e+13,-6.219462251e+13, 1.36644076e+14,-7.651090187e+13, 1.667711438e+14,-1.028494283e+12, 1.849467124e+14,-1.208973128e+14,-4.57814006e+13, 1.246481787e+14,-9.190662389e+13, 9.418202292e+13,-1.089332892e+14, 7.540867552e+13,-1.414437984e+14, 6.156219473e+13, 1.040447999e+14,-6.155109472e+13, 1.782511877e+13,-4.699373119e+13, -7.062616e+12,-3.607979738e+13, 4.967680995e+13,-5.307824779e+13, 1.617869626e+14,-4.829214808e+13,-2.456128221e+14,-6.884294706e+12);
s(16,0) = ( 2.475984613e+13, 1.004990128e+13, 2.731653054e+13, 3.07385209e+13, 1.109700586e+13, 1.380802494e+13, 8.892814126e+12, 4.766228279e+13, 2.108847028e+13, 1.843016448e+13, 3.773166006e+13, 6.840698741e+12,-2.78586874e+13, 3.162490631e+13, 4.650961895e+13, 8.262976993e+12, 8.353495612e+11, 4.663270686e+13, 3.49563917e+13,-8.91431222e+12,-3.928432876e+13,-1.630188289e+13, 4.36988424e+13, 2.255488469e+13,-1.368024203e+12, 1.626976127e+13, 5.463350544e+13, 5.118282258e+13,-2.048854987e+13,-1.898042662e+13, 3.507579854e+12,-5.037369086e+13,-7.940431706e+11, 2.572670821e+13, 3.663953607e+12,-6.82966691e+12);
s(17,0) = ( 2.447239466e+13,-1.366306731e+13, 2.704760288e+13, 2.82713078e+13,-1.350784336e+13,-1.953455817e+13, 8.647634404e+12, 4.303902782e+13, 1.534482906e+13,-2.069501608e+13,-4.626878646e+13,-1.047846048e+13,-2.80152223e+13, 2.783284446e+13, 3.42896643e+13, 8.349701008e+11, 1.962326277e+12,-5.28113677e+13,-4.301126078e+13, 1.155151801e+13,-3.916844583e+13,-1.564911442e+13, 3.245116984e+13, 6.439380113e+12,-1.841544405e+12,-8.760109632e+12,-5.36472873e+13,-5.818573596e+13, 2.495301327e+13, 2.611963814e+13, 4.094771655e+12,-4.608887899e+13,-4.392761812e+11, 9.410893436e+12,-2.646865714e+13,-1.652115279e+13);
s(18,0) = ( 2.40342362e+13,-2.985056331e+13, 2.518797283e+13, 8.571056269e+12,-9.961828934e+12,-4.521398944e+13, 7.625836684e+12, 1.187034809e+13,-2.159492332e+13, 1.067763236e+13,-3.399837147e+13,-2.959318592e+13,-2.544272959e+13, 5.724731689e+12,-4.684529796e+13,-1.733693792e+13,-3.491921481e+12, 2.937280977e+13,-3.173401888e+13, 1.501571228e+13,-3.545187274e+13,-8.296562371e+12,-4.360597256e+13,-4.737516767e+13, 7.752039178e+11, 3.196579904e+12, 6.263785491e+13, 3.356772835e+13, 1.780452645e+13, 4.61613185e+13, 2.481075413e+12,-1.732245859e+13, 1.054988316e+12,-5.383492573e+13, 7.350683931e+12, 1.748743446e+13);
s(19,0) = ( 2.490272774e+13,-2.975975439e+13, 2.672845269e+13,-1.19127915e+13, 1.243222796e+13,-4.479065328e+13, 8.146667637e+12,-1.670131396e+13,-1.768491485e+13, 4.088530119e+12, 4.312889897e+13,-2.869102616e+13,-2.766246785e+13,-8.577694658e+12,-3.701353894e+13, 1.993666553e+13, 3.40542946e+12, 1.271207622e+13, 4.009929592e+13, 1.62927982e+13,-3.828386216e+13, 1.045906313e+13,-3.373692097e+13, 5.167712618e+13,-1.630994323e+12, 1.090614845e+13,-6.158207828e+13, 1.528992429e+13,-2.371939485e+13, 4.749469487e+13, 3.872915796e+12, 2.283895877e+13, 1.28187928e+12, 5.735701609e+13,-9.649028824e+12,-1.244646459e+13);
s(20,0) = ( 2.488351148e+13,-9.696369612e+12, 2.723753512e+13,-3.087446943e+13, 1.104208364e+13,-1.297788217e+13, 8.692713639e+12,-4.649596244e+13, 2.058146507e+13,-1.842537728e+13, 3.607686387e+13,-6.061239903e+12,-2.791790317e+13,-3.002945149e+13, 4.302588292e+13,-8.648651572e+12,-3.629562515e+12,-4.793566767e+13, 3.304985078e+13, 8.876360199e+12,-3.909773898e+13, 1.62198434e+13, 3.918950518e+13,-2.348401991e+13,-1.231241836e+12,-1.564757527e+13, 6.33966352e+13,-5.329964154e+13,-1.949676556e+13, 1.819770112e+13, 3.784763596e+12, 4.833457041e+13,-1.507305161e+12,-2.67215448e+13, 6.545383428e+12, 5.157483746e+12);
s(21,0) = ( 2.373920987e+13, 1.02334327e+13, 2.369834394e+13,-2.833132802e+13,-1.203861548e+13, 1.276394502e+13, 6.47379999e+12,-4.248921331e+13, 1.886475678e+13, 1.916929534e+13,-3.740125475e+13, 5.128920298e+12,-2.409905783e+13,-2.744915676e+13, 4.285645181e+13,-6.199462785e+12, 6.115863845e+12, 5.285965293e+13,-3.399375995e+13,-9.541327983e+12,-3.287028761e+13, 1.4516023e+13, 4.092023633e+13,-2.113495521e+13,-6.571011075e+11, 1.483964732e+13,-6.807872192e+13, 6.029883673e+13, 1.929673699e+13,-1.807194768e+13, 2.142658234e+12, 4.356359733e+13,-3.229781026e+11,-2.613102414e+13,-7.220946427e+12, 9.801504772e+12);
s(22,0) = ( 2.427800586e+13, 2.807840023e+13, 2.671278248e+13,-1.378695018e+13,-1.38642671e+13, 4.315974667e+13, 8.474035741e+12,-1.872937959e+13,-1.505354294e+13,-1.260319029e+11,-4.417857463e+13, 2.831177399e+13,-2.766857066e+13,-9.364659596e+12,-3.581434396e+13, 2.042627955e+13,-5.566757532e+12,-9.094045884e+12,-4.029644046e+13,-1.514913617e+13,-3.857509114e+13, 1.145939881e+13,-3.501613694e+13, 5.218678647e+13,-4.385318122e+12,-1.817894007e+13, 5.798575694e+13,-1.464797381e+13, 2.340745664e+13,-4.58245144e+13, 4.165680634e+12, 2.46183841e+13,-2.42601873e+11, 5.75328543e+13,-2.41612236e+13,-6.324540193e+12);
s(23,0) = ( 2.534671848e+13, 3.104957366e+13, 2.777230689e+13, 1.147161963e+13, 1.231816495e+13, 4.747649085e+13, 8.743961364e+12, 1.555473037e+13,-2.018244362e+13,-6.621162502e+12, 3.996778699e+13, 3.097132859e+13,-2.878702926e+13, 7.671257121e+12,-4.386662038e+13,-1.966237697e+13,-1.251579249e+12,-1.751751199e+13, 3.656535177e+13,-1.678684976e+13,-4.008357556e+13,-9.782857698e+12,-4.087862739e+13,-4.845472877e+13,-1.115338584e+12,-9.980151104e+12,-5.412224419e+13,-1.973136394e+13,-2.150059494e+13,-5.035234718e+13, 4.258277301e+12,-2.079622548e+13, 9.595517591e+11,-5.250239413e+13,-5.809275755e+12, 1.457800205e+13);
s(24,0) = ( 3.874705407e+13, 1.936501971e+13, 3.346851106e+13, 1.931604381e+13, 2.932787417e+13, 3.082916074e+13, 3.568193832e+13, 3.079238492e+13, 3.987632837e+10, 1.029935997e+12, 1.613949269e+13, 3.959360433e+13, 4.14541163e+13, 3.959761562e+13,-3.068111707e+10,-7.609491703e+11,-1.150022842e+11, 2.390857515e+12, 1.810532162e+13, 4.55653973e+13, 2.341156158e+13, 4.560211562e+13,-9.081593164e+10,-2.152147287e+12, 8.497499659e+11,-1.033731251e+12, 3.847234614e+10, 6.146905992e+12, 7.605900642e+13, 4.71645075e+13,-3.281300583e+13, 4.720213941e+13,-3.822695166e+10,-6.11668417e+12,-2.854521256e+12,-8.107875986e+11);
s(25,0) = ( 3.890440835e+13,-1.91617021e+13, 3.356157659e+13, 1.940912969e+13,-2.912050114e+13,-3.039231362e+13, 3.56614246e+13, 3.110693386e+13,-1.325514532e+11,-1.201851199e+12,-1.592556933e+13,-3.921198877e+13, 4.134544503e+13, 3.993163361e+13,-2.234127295e+11,-9.005851897e+11, 2.730138635e+11,-3.083127755e+12,-1.80129684e+13,-4.562922856e+13, 2.334550954e+13, 4.56049129e+13,-1.738946831e+11,-1.596437818e+12,-2.354825088e+12, 1.491683218e+12,-2.049867922e+11,-7.042057112e+12,-7.60817207e+13,-4.761478168e+13,-3.269180856e+13, 4.687216868e+13, 2.63288427e+10,-5.030363832e+12, 4.448528359e+12,-1.487602159e+11);
s(26,0) = ( 3.883722716e+13,-1.916170048e+13, 3.361752686e+13,-1.924838962e+13, 2.933887526e+13,-3.072664162e+13, 3.576356043e+13,-3.079924761e+13,-1.338376938e+10,-9.03729685e+11, 1.605486093e+13,-3.965863846e+13, 4.131774098e+13,-3.966543003e+13,-1.191659282e+11, 1.135008854e+12,-9.140442802e+10,-2.365550967e+12, 1.799438263e+13,-4.566780955e+13, 2.317083414e+13,-4.561524298e+13,-1.588106909e+11, 2.537004312e+12, 6.709883783e+11,-1.502876578e+11, 1.26918557e+11,-6.27383142e+12, 7.610786866e+13,-4.717466161e+13,-3.283700984e+13,-4.711474392e+13,-2.72503324e+10, 6.244883668e+12,-1.986193014e+12, 3.541002828e+11);
s(27,0) = ( 3.887757177e+13, 1.935154375e+13, 3.352874968e+13,-1.911122341e+13,-2.90755813e+13, 3.110328078e+13, 3.56493027e+13,-3.041721146e+13,-1.179358309e+11, 5.108990796e+11,-1.582603093e+13, 3.999297619e+13, 4.138073455e+13,-3.930408009e+13,-1.723311562e+11, 7.90944333e+11, 2.10935759e+11, 1.04544259e+12,-1.792896332e+13, 4.566385881e+13, 2.340066999e+13,-4.568647732e+13,-1.160513026e+11, 2.478142975e+12,-2.369372582e+12, 5.387552428e+11,-4.424645429e+11, 4.653496759e+12,-7.611506407e+13, 4.688037243e+13,-3.268311381e+13,-4.758833092e+13, 3.161351065e+10, 6.60570285e+12, 4.799583788e+12, 4.25811584e+11);
s(28,0) = (-8.610776617e+12,-1.090290339e+11, 3.96151292e+13,-1.667725893e+11, 1.281409905e+11,-4.082786346e+11, 5.857917282e+13,-2.928413092e+11,   -5726165210,    9247730876, 5.297587624e+10,-4.484505013e+11, 2.621131671e+13,-2.377915291e+11, 2.501884804e+11, 8.035702223e+10,-3.652791999e+11, 8.8108379e+11,-1.104017148e+11,-1.97996976e+10, 3.092167832e+13, 2.31853264e+10, 3.724053319e+11,-5.688413714e+11, 1.95927629e+12,-6.666562725e+11, 2.672898236e+11, 1.416215917e+12,-2.067760973e+11, 4.218497203e+11, 1.490319199e+14, 2.304500204e+11, 8.158103396e+10,-1.02851227e+12,-4.606261493e+12, 2.903619684e+11);


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