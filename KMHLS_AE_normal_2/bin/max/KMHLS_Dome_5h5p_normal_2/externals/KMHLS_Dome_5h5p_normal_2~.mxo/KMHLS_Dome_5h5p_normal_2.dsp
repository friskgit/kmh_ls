// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 27-Jun-2019 12:07:13

//------- decoder information -------
// decoder file = ../decoders/KMHLS_Dome_5h5p_pinv_even_energy_rV_max_rE_2_band.dsp
// description = KMHLS_Dome_5h5p_pinv_even_energy_rV_max_rE_2_band
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
declare name "KMHLS_Dome_5h5p_normal_2";

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
rs = (          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         5.317,         5.317,         5.317,         5.317,         5.576);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1,             1,             1);
gamma(1) = (   1.576136142,   1.469698903,   1.267606062,  0.9902074127,  0.6651373474,  0.3242306084);

// gain matrix
s(00,0) = ( 3.138113087e+13, 2.578014773e+13, 3.847869461e+13, 1.502073048e+13, 7.525112389e+13, 2.409978941e+13,-6.028560028e+13, 8.176340168e+13, 4.36501303e+13, 5.330275736e+13, 3.304794435e+13,-9.826261767e+12,-2.995851539e+13,-7.172697857e+13,-2.409584674e+13,-3.920457047e+11, 6.971275137e+13, 7.599786251e+13,-5.789962804e+13,-6.225019014e+13, 4.984190375e+13,-4.994487452e+13, 6.315155008e+12,-4.935033417e+13,-1.237344647e+14, 6.438082646e+12, 6.532268131e+12,-7.536083762e+13,-2.697532728e+13, 4.515069033e+13, 1.015085741e+13, 4.627981765e+13,-3.600767059e+13, 2.029738536e+13, 3.123005784e+13,-1.102511823e+14);
s(01,0) = ( 7.447569592e+13, 1.952209866e+13,-4.290185812e+13, 1.058569262e+14, 5.688856677e+13, 2.467743688e+13,-2.605500557e+13,-3.383095899e+13, 5.071247427e+13, 9.583574987e+13,-1.603999071e+13,-5.995397349e+13,-2.479528444e+12,-8.108791781e+12, 4.451225269e+13, 5.003426956e+13, 8.476110666e+13,-3.760112116e+13,-7.852354499e+12, 4.797292272e+13, 7.315945436e+12,-6.094625374e+13,-5.697681693e+13, 5.819562165e+13, 1.014026115e+14, 9.724058037e+13, 1.178087321e+13,-1.787725764e+13,-1.787099915e+13,-1.7564816e+13, 3.131324788e+13, 3.965435455e+13,-5.559990334e+13,-5.329495755e+13,-2.700580728e+13, 5.009682491e+13);
s(02,0) = ( 3.427105352e+13, 8.613325021e+12, 3.074699022e+13, 7.873546309e+13,-6.246500555e+13,-5.379827107e+13,-4.75968279e+13, 3.901769994e+13, 9.893726701e+13,-7.196500839e+13, 3.826811882e+13, 6.614911761e+13,-4.145166436e+13,-1.062778271e+14, 8.425946946e+12, 8.646788572e+13,-6.900710442e+13, 2.380582891e+13,-1.153595203e+13,-3.583812797e+13, 5.627589201e+13, 2.171858255e+13,-5.7940503e+13, 3.27604715e+13, 4.755880499e+13,-8.286663741e+13,-1.118384256e+13, 1.783994017e+13, 1.945861728e+13, 8.44069215e+12, 9.635299669e+12, 9.042753698e+12,-1.176029092e+13,-2.924531838e+13, 8.373713794e+13, 7.317656377e+13);
s(03,0) = ( 6.933340348e+13,-8.313468755e+13,-2.601955597e+13, 5.323736604e+13,-3.90175737e+13, 5.224148068e+13,-5.251370737e+13, 1.189532988e+13,-9.027277638e+11,-8.676310595e+13,-8.161613506e+13,-1.655237387e+13, 2.191454036e+13,-1.408376767e+12, 2.890090144e+13,-7.077180246e+12,-8.494660394e+13,-3.5176916e+13, 9.241955885e+13, 3.047555789e+13,-5.663844108e+12,-9.836619375e+13,-1.32580752e+13,-2.331479196e+13,-5.160836549e+13,-3.043162831e+13,-7.671343651e+12, 5.947048789e+13, 1.493174141e+13,-1.851278718e+13, 3.292620825e+13, 6.175234598e+13,-7.504534781e+13,-3.240485358e+12,-5.164612612e+13,-1.058176833e+14);
s(04,0) = ( 4.908542269e+13,-2.15524409e+13,-6.068340803e+12, 5.509365719e+13,-1.224066707e+14,-7.073182484e+13,-1.444751269e+13, 1.127090794e+13, 1.036676074e+13, 9.37809713e+12, 3.307603671e+13, 6.397503002e+13,-6.15466761e+13,-5.763066486e+13,-3.570171549e+13,-1.081656511e+14, 7.287440451e+13,-6.051180954e+13, 9.526138599e+12, 5.605305281e+13, 5.979689429e+13, 1.944667896e+13, 1.882211389e+13,-1.383717621e+13,-6.901782963e+13, 1.104759549e+14, 1.119099586e+13, 2.135574343e+13, 4.177150191e+13,-4.954187923e+13, 1.306808878e+13, 7.458290726e+10, 6.622752761e+13, 3.776314796e+13,-4.897785366e+13, 1.218576061e+13);
s(05,0) = ( 4.240123632e+13,-1.182630517e+14, 2.981173577e+13, 2.788749409e+13,-1.17752568e+12, 2.440601416e+13,-8.67930842e+13,-1.19263046e+13,-1.0801847e+14, 2.51688926e+13,-5.917428644e+13, 5.975932944e+13, 2.278704431e+13, 1.246848959e+11, 1.158398497e+13,-2.079522547e+13, 8.158066991e+13, 9.75650401e+13, 5.942839075e+13,-7.174278741e+12, 7.573762453e+12,-7.649697161e+12, 3.910484572e+13,-4.784549295e+13, 6.735645073e+13,-5.903587799e+13, 4.280205254e+12,-7.369780119e+13, 1.074831462e+12,-5.337241167e+12, 2.607559834e+13, 9.236702076e+12, 2.276244006e+13, 6.433414885e+13, 3.782095642e+13, 9.213629001e+13);
s(06,0) = ( 8.480933589e+13,-5.19441201e+13,-6.848171131e+13,-5.177831709e+13, 1.25279861e+13,-4.169870299e+13, 1.169221785e+13, 3.446156135e+13,-4.911680139e+13, 1.150618718e+14, 4.45700092e+13, 3.661109433e+13,-3.880323142e+13, 1.052562723e+13,-5.904387308e+13, 2.670740133e+13,-7.926369842e+13,-1.016963122e+13,-4.529363897e+13, 8.427017705e+13, 3.222800729e+13,-2.800040835e+13, 6.903904206e+13, 4.591116419e+13, 5.560395028e+13,-6.305108429e+13,-1.05120777e+13,-9.622497999e+12,-5.855801847e+12,-6.25292824e+13, 2.063947342e+13, 1.284941531e+13, 4.65926076e+13,-5.442022997e+13, 6.001716825e+13,-9.308986122e+13);
s(07,0) = ( 8.697123676e+12,-8.402854952e+13, 8.602013368e+13, 3.842838438e+12, 9.48320711e+13, 3.670698632e+11,-1.031162684e+14,-6.541310778e+13,-3.39805822e+13,-3.447383611e+13, 4.249871929e+12, 6.102224747e+13,-1.114061392e+13, 3.023687492e+13, 1.17533386e+13, 9.273842914e+13,-7.561684793e+13,-5.822149623e+12,-4.340120698e+13,-1.63320147e+12, 4.243385491e+13, 7.099206128e+13,-1.264653577e+12, 2.577203704e+13,-5.631283968e+13, 1.095358052e+14,-1.51709586e+12,-5.524068513e+12,-3.090042144e+13,-1.080511421e+13, 1.722704847e+13,-5.534086172e+13, 4.184832647e+13,-5.585142376e+13,-6.834536546e+13,-9.008291384e+12);
s(08,0) = ( 1.050281946e+14,-2.795702043e+13,-1.064814883e+14,-1.140254434e+14, 7.313916971e+13,-2.437881153e+13, 2.01655725e+13, 4.074451297e+13, 1.995501645e+13,-1.15542314e+14, 3.051006811e+13, 2.577483522e+13,-1.356474625e+13, 3.994730291e+13, 1.601560986e+13, 3.043750222e+13, 8.497037174e+13,-2.209478215e+10,-5.562580394e+13, 3.681810642e+13, 4.748180547e+12,-7.681282048e+12,-1.095432999e+13,-1.064069095e+13,-7.207567151e+13,-3.053679031e+13, 8.066608203e+12, 3.626541768e+13,-2.587397202e+13,-3.080358355e+13, 2.996573217e+13,-1.047591568e+12,-5.152322899e+13, 1.636594438e+13,-1.838529926e+13, 1.04779199e+14);
s(09,0) = ( 1.029694513e+13,-3.177603732e+13, 8.287429349e+13,-5.490324086e+13, 3.362592751e+13, 1.584141452e+13,-9.733527597e+13,-4.725585879e+13, 9.880868817e+13, 1.113565515e+13, 7.35263578e+12, 2.353351954e+12,-1.255937261e+13, 6.628053103e+13,-5.388067767e+12,-1.166658949e+14, 7.460479585e+13,-8.317554071e+13,-1.585577093e+13,-4.702210178e+12, 4.428750487e+13, 4.451715214e+13,-4.253340626e+13, 1.592972339e+13, 7.18367659e+13,-8.47032703e+13, 4.540167516e+12, 7.722890072e+13,-1.275174061e+13,-8.11311117e+11, 1.401579977e+13,-4.328528981e+13,-3.053774547e+13, 1.345539469e+13, 3.80816441e+13,-6.791480644e+13);
s(10,0) = ( 7.399543135e+13, 3.763182223e+13,-5.029756526e+13,-6.544801967e+13,-3.934427163e+13,-1.712804016e+13, 1.78801136e+12,-2.381286884e+13, 4.016936352e+13,-3.770033945e+12,-7.079021586e+12,-9.729822641e+12,-4.033132825e+13, 4.187582689e+13, 6.172098501e+13,-1.551550024e+13,-8.419300652e+13, 8.378135914e+13, 1.876873957e+13, 1.399554668e+13, 3.56819027e+13, 6.447870359e+13,-7.696356825e+13,-1.054374539e+14, 7.527397909e+13, 9.323474055e+13,-5.342374381e+12,-8.156583864e+13, 1.427985669e+13,-3.144902377e+12, 2.091349262e+13,-4.889391675e+13,-4.628401285e+13, 7.9306436e+13, 2.105047214e+13,-5.7571668e+13);
s(11,0) = ( 5.74539948e+13, 2.44983681e+13, 4.827214446e+11,-9.928709316e+13,-7.533058362e+13, 2.283473342e+13,-7.626085698e+13, 2.137532476e+13, 5.054468675e+13, 1.140367612e+14,-3.081859014e+13,-7.175878612e+12, 3.539813503e+13, 4.779868204e+13,-2.521932556e+13,-3.973391245e+13,-7.347408589e+13, 5.492225949e+11, 5.564457635e+13,-6.572328896e+13,-7.40407592e+12,-7.07774416e+12, 1.083548306e+13, 9.311125406e+13,-9.057053865e+13, 1.288238729e+13,-7.467257392e+12,-3.371391453e+13, 2.673680179e+13, 4.504912745e+13, 2.993957725e+13,-5.292372242e+12,-3.462691209e+13,-4.343887508e+13,-1.038149476e+13, 1.097567651e+14);
s(12,0) = ( 2.66418735e+13, 7.468142919e+13, 2.877345145e+13,-1.310641504e+13,-8.196112519e+13, 2.404176696e+13,-1.798450943e+13,-4.792226625e+13,-3.453363538e+13, 2.681846249e+13,-1.711011686e+13,-9.688066113e+13,-8.811453144e+13, 4.005517891e+13, 5.459562395e+12, 1.381040422e+14, 7.603639746e+13, 7.177691515e+12, 4.841389561e+13, 3.699091384e+13, 8.405420273e+13, 3.768835785e+13, 7.450805615e+12,-3.49570461e+13,-4.569206006e+13,-1.052587755e+14, 5.286994886e+12, 7.043751661e+12, 2.806742296e+13,-5.338847101e+12, 5.878557445e+12,-3.36266823e+13, 3.323349045e+13,-1.954939907e+13,-7.168848288e+13,-1.713095286e+13);
s(13,0) = ( 8.676782145e+13, 8.394036793e+13,-5.261441848e+13,-1.974397777e+13,-3.692601544e+13,-1.754265977e+13,-5.195133848e+13, 6.046134839e+12,-7.920373596e+13,-1.003892662e+14,-1.045498311e+13, 1.307642266e+13, 5.224416051e+13,-8.758266479e+12,-1.123744936e+13, 9.987630441e+12, 8.153796777e+13, 4.326777279e+11, 2.280250674e+13,-1.028874776e+14,-3.212932004e+13, 2.641329622e+13, 3.531386823e+13, 6.912256356e+13, 6.073768135e+13, 5.430145109e+13, 9.821176572e+12, 1.509765711e+13, 1.314443837e+13, 6.38806309e+13, 3.89692754e+13,-1.932217566e+13, 5.098294995e+13,-7.096170498e+13, 3.942801223e+13,-9.543785979e+13);
s(14,0) = ( 2.31768229e+13, 5.535770661e+13, 4.735602213e+13,-1.832594195e+13, 3.367551598e+13, 6.511793094e+13,-4.42120861e+13, 3.409022274e+13,-5.625486316e+13,-5.308370696e+13, 2.668345674e+12,-1.06364978e+14,-6.390622072e+13, 6.183187148e+12,-5.832045376e+13,-1.117769475e+13,-6.990223272e+13,-7.036861685e+13,-1.650093058e+13,-3.76134212e+11, 7.629994547e+13,-5.410485327e+13, 8.019437142e+13,-4.82693484e+13, 4.396293083e+13, 7.260747298e+13,-5.869523684e+12, 5.514130285e+13,-1.128187031e+13, 2.070828749e+13, 3.065574227e+12, 3.794656444e+13, 2.427865691e+13, 6.271746895e+13, 8.818524102e+13, 8.300532635e+13);
s(15,0) = ( 7.831221294e+13, 9.551128198e+13,-4.935152535e+13, 9.522051607e+13, 7.659204988e+13,-2.605720741e+13,-3.01546712e+13,-4.95601106e+13,-5.083457678e+13, 1.400364245e+13, 2.724458246e+13,-2.591375122e+13, 9.517158952e+12,-2.613372994e+13, 2.907747387e+13,-1.139464226e+14,-8.48876035e+13, 1.314374654e+13,-5.253723936e+13,-2.928350745e+13,-4.679571361e+12, 2.949219161e+13,-1.004256315e+13,-6.694114006e+12,-1.231933298e+13,-1.051425491e+14,-9.407031266e+12, 8.983091317e+12,-2.683204704e+13, 2.286582499e+13, 3.613196114e+13,-1.283128783e+13, 5.415500366e+13, 3.515976797e+13,-1.09437695e+14, 3.137458259e+13);
s(16,0) = ( 4.736377586e+13, 1.972373378e+13, 5.07518536e+13, 5.386857172e+13, 1.916535588e+13, 3.087829459e+13, 1.983070294e+13, 8.347731368e+13, 3.736693762e+13, 3.058725213e+13, 7.448847761e+13, 2.056382515e+13,-4.389603966e+13, 6.104525252e+13, 7.433232846e+13, 1.305716528e+13,-8.963738417e+12, 8.632866808e+13, 7.881452272e+13,-1.304023133e+13,-7.206312376e+13,-1.682528689e+13, 7.346793302e+13, 3.60771837e+13,-6.670639642e+11, 2.088341327e+13, 1.063396462e+14, 1.100050964e+14,-2.559735998e+13,-4.245441836e+13,-1.015152377e+13,-8.551979468e+13, 1.607008169e+13, 4.620172488e+13, 2.981897858e+12,-7.823738586e+12);
s(17,0) = ( 4.752564502e+13,-2.03727293e+13, 5.078293049e+13, 5.372852722e+13,-1.956895589e+13,-3.169606815e+13, 1.971156734e+13, 8.33364834e+13, 3.663842384e+13,-3.099741902e+13,-7.605015296e+13,-2.101658386e+13,-4.405710696e+13, 6.091263265e+13, 7.28043695e+13, 1.210105972e+13, 8.707711666e+12,-8.719080222e+13,-8.044187592e+13, 1.334691824e+13,-7.211399917e+13,-1.701576483e+13, 7.190943255e+13, 3.31480185e+13,-9.176894801e+11,-2.032510662e+13,-1.061241999e+14,-1.109525191e+14, 2.621308049e+13, 4.33218809e+13,-1.000058653e+13,-8.578942286e+13, 1.570432805e+13, 4.234854302e+13,-4.883251124e+11,-9.646189344e+12);
s(18,0) = ( 4.774457727e+13,-5.517059666e+13, 5.148875011e+13, 1.90055161e+13,-1.890156924e+13,-8.5691876e+13, 2.026408343e+13, 2.949258319e+13,-3.950252069e+13, 1.520529624e+13,-6.931038889e+13,-6.286492313e+13,-4.460069094e+13, 1.9506271e+13,-7.86451995e+13,-2.969654405e+13,-8.741269256e+12, 4.189332428e+13,-7.248398665e+13, 1.697307013e+13,-7.330552553e+13,-1.244670528e+13,-7.7770308e+13,-8.206472711e+13,-3.368705753e+11, 4.90420242e+12, 1.061706028e+14, 5.352346165e+13, 2.324033198e+13, 8.752632963e+13,-1.005045109e+13,-4.027632913e+13,-1.703156815e+13,-1.036958774e+14, 1.023531894e+13, 2.23465022e+13);
s(19,0) = ( 4.74676641e+13,-5.275470084e+13, 5.054453983e+13,-2.268752721e+13, 2.19762574e+13,-8.14315878e+13, 1.944526237e+13,-3.502490908e+13,-3.369453135e+13, 8.704581705e+12, 7.931158779e+13,-5.920768509e+13,-4.404528162e+13,-2.324256915e+13,-6.673840172e+13, 3.258321745e+13, 1.093001853e+13, 2.620869975e+13, 8.267233556e+13, 1.694935001e+13,-7.181158204e+13, 1.423997642e+13,-6.578530651e+13, 8.940423355e+13,-2.38324528e+12, 1.555447796e+13,-1.111782336e+14, 3.479260953e+13,-2.638562812e+13, 8.392934736e+13,-9.750317641e+12, 4.681481563e+13,-1.429855115e+13, 1.126274084e+14,-1.403663811e+13,-1.869288973e+13);
s(20,0) = ( 4.658683367e+13,-1.810719141e+13, 4.911821419e+13,-5.299359504e+13, 1.852714718e+13,-2.797216431e+13, 1.887766635e+13,-8.172457654e+13, 3.800771132e+13,-3.007729067e+13, 6.872871658e+13,-1.819702588e+13,-4.220367506e+13,-5.967381623e+13, 7.526106402e+13,-1.489081591e+13,-1.404628539e+13,-8.626258053e+13, 7.216009689e+13, 1.254372562e+13,-6.911364339e+13, 1.609398724e+13, 7.417368438e+13,-4.097529987e+13,-1.305371107e+11,-2.325613376e+13, 1.186631912e+14,-1.106273164e+14, -2.278062e+13, 3.921150194e+13,-1.033954013e+13, 8.27426049e+13, 1.611529465e+13,-5.229596213e+13, 8.987111795e+12, 6.411641129e+12);
s(21,0) = (  4.689511e+13, 1.817710979e+13, 4.945398279e+13,-5.3422045e+13,-1.854576222e+13, 2.827240653e+13, 1.893482977e+13,-8.22102046e+13, 3.802303935e+13, 3.026592938e+13,-6.935078948e+13, 1.853128571e+13,-4.26796221e+13,-5.984929128e+13, 7.494735264e+13,-1.470363959e+13, 1.330506446e+13, 8.636000992e+13,-7.291492193e+13,-1.256435694e+13,-6.97041134e+13, 1.645706156e+13, 7.365249403e+13,-3.957887566e+13, 6.711915417e+11, 2.361495191e+13,-1.1767228e+14, 1.105303032e+14, 2.312554007e+13,-3.965054688e+13,-1.012587645e+13, 8.34695467e+13, 1.58926751e+13,-5.008568414e+13, 7.501154575e+12, 5.554780884e+12);
s(22,0) = ( 4.708012333e+13, 5.266379095e+13, 5.08915141e+13,-2.156671148e+13,-2.084149258e+13, 8.231342788e+13, 2.012638971e+13,-3.403902958e+13,-3.438852442e+13,-9.922488762e+12,-7.776979376e+13, 6.053501757e+13,-4.401033284e+13,-2.302894698e+13,-6.866877913e+13, 3.130717545e+13,-1.098530197e+13,-2.913081005e+13,-8.174974829e+13,-1.669235545e+13,-7.251393429e+13, 1.370269743e+13,-6.803050227e+13, 8.777952513e+13,-2.534675896e+12,-1.344579321e+13, 1.102587382e+14,-3.82763845e+13, 2.58462761e+13,-8.519097942e+13,-1.013725521e+13, 4.603804645e+13,-1.496316638e+13, 1.115486224e+14,-7.3947764e+12,-1.880747529e+13);
s(23,0) = ( 4.763524985e+13, 5.448266141e+13, 5.127910235e+13, 1.950421818e+13, 1.933574304e+13, 8.479368587e+13, 2.010693822e+13, 3.058098574e+13,-3.842252568e+13,-1.385812099e+13, 7.148386011e+13, 6.227452767e+13,-4.44852034e+13, 2.044600353e+13,-7.668566921e+13,-3.007673728e+13, 8.892698585e+12,-3.88563695e+13, 7.49130508e+13,-1.686300012e+13,-7.30117152e+13,-1.274044474e+13,-7.594940398e+13,-8.385923055e+13,-1.683764964e+11,-6.653931749e+12,-1.06643231e+14,-5.002219317e+13,-2.395410384e+13,-8.688430148e+13,-9.977407436e+12,-4.182325942e+13,-1.669286559e+13,-1.063403811e+14, 4.019192556e+12, 2.13492493e+13);
s(24,0) = ( 6.841325397e+13, 3.29591921e+13, 5.445201552e+13, 3.312144642e+13, 5.511834716e+13, 5.115189759e+13, 5.998155323e+13, 5.121156375e+13,-4.278206915e+10, 1.752963352e+12,  1.799604e+13, 6.802043335e+13, 8.198052436e+13, 6.794877775e+13,-1.433238809e+11,-1.856306471e+12, 1.200662276e+10, 4.294492794e+12, 1.537834828e+13, 8.514266448e+13, 5.783793834e+13, 8.508871116e+13,-1.773678593e+11,-4.135215172e+12, 1.918410415e+12,-1.456834392e+12, 2.128301484e+11, 1.087104489e+13, 1.45215875e+14, 9.462815571e+13,-5.768201272e+13, 9.469521413e+13,-5.716844876e+10,-1.044179138e+13,-6.468287863e+12,-1.073142483e+12);
s(25,0) = ( 6.846841373e+13,-3.303252849e+13, 5.450413219e+13, 3.300499827e+13,-5.508882619e+13,-5.118464935e+13, 5.998061748e+13, 5.117470719e+13,-1.207040894e+11,-1.752352366e+12,-1.809398208e+13,-6.799347575e+13, 8.189150876e+13, 6.801058016e+13,-1.270158387e+11,-1.583887325e+12,-1.327478887e+11,-4.272761906e+12,-1.553286689e+13,-8.511126882e+13, 5.773492485e+13, 8.513511396e+13,-5.616843866e+10,-4.065397738e+12, 2.470693513e+12, 1.557024896e+12,-9.919935234e+10,-1.083327453e+13,-1.451772982e+14,-9.46377188e+13,-5.764871319e+13, 9.46486695e+13, 2.340222594e+10,-1.070308946e+13,-7.931683393e+12,-8.622892738e+11);
s(26,0) = ( 6.83446152e+13,-3.295332661e+13, 5.437906293e+13,-3.27703624e+13, 5.504236732e+13,-5.089844956e+13, 5.99587375e+13,-5.079164765e+13,-3.723635554e+10,-1.652349126e+12, 1.782489157e+13,-6.770814088e+13, 8.205913374e+13,-6.773679406e+13,-1.840290085e+11, 1.489801729e+12, 4.818557105e+10,-3.6155449e+12, 1.521820775e+13,-8.520261433e+13, 5.796114625e+13,-8.526437259e+13,-2.493340499e+11, 3.705839042e+12, 1.748362452e+12, 9.699719615e+10, 4.760953419e+11,-9.810051202e+12, 1.452420991e+14,-9.514714105e+13,-5.765672062e+13,-9.514088217e+13,-8.923613712e+10, 1.020070379e+13,-5.457546744e+12, 8.204681094e+11);
s(27,0) = ( 6.84394026e+13, 3.292611707e+13, 5.444026897e+13,-3.291797627e+13,-5.506704733e+13, 5.090796577e+13, 5.993622754e+13,-5.088158951e+13,-1.520862084e+11, 1.681902795e+12,-1.796371283e+13, 6.774432543e+13, 8.194398796e+13,-6.771436415e+13,-1.679581218e+11, 1.834427287e+12,-7.870356295e+10, 3.751357557e+12,-1.537375722e+13, 8.520623797e+13, 5.784971542e+13,-8.520105226e+13,-8.34563148e+10, 3.885571265e+12, 2.29896528e+12,-2.381182559e+11,-4.581969372e+11, 1.000949264e+13,-1.451879781e+14, 9.509397348e+13,-5.761399021e+13,-9.51186446e+13, 2.421309404e+10, 1.003227339e+13,-7.130408699e+12, 9.736582001e+11);
s(28,0) = (-1.060776432e+13,-1.491235046e+11, 8.740684557e+13,-1.786539373e+10, 3.13479607e+10,-3.522289803e+10, 1.198944459e+14,-2.078300959e+11, 3.028787822e+10, 3.692573874e+10, 1.231895249e+11, 1.019435088e+11, 3.692552556e+13,-2.440417582e+11, 1.407107733e+11, 1.984659137e+10,-8.563709296e+10,-5.461740647e+10, 1.147011281e+11, 8.09903958e+10, 2.704241383e+13, 5.320384745e+10, 1.884273296e+11, 3.417109221e+11,-6.414033474e+12, 1.807603554e+11,-1.682757421e+11,-1.494198538e+11,-9.653074896e+10,-4.695526143e+10, 2.725641458e+14, 4.114661583e+11, 6.660591646e+10, 5.756012489e+11, 1.275534482e+13, 3.391759996e+10);


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