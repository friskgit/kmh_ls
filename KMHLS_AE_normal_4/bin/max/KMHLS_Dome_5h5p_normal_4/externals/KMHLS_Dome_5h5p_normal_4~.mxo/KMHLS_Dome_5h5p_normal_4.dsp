// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 27-Jun-2019 12:07:03

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
rs = (          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,          4.61,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         4.882,         5.317,         5.317,         5.317,         5.317,         5.576);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1,             1,             1);
gamma(1) = (   1.576136142,   1.469698903,   1.267606062,  0.9902074127,  0.6651373474,  0.3242306084);

// gain matrix
s(00,0) = (-1.614748205e+13,-2.973429419e+13, 8.222008627e+13,-1.530631664e+14, 1.436793757e+13, 3.550838825e+13,-5.07447011e+13, 2.523206824e+14, 6.911450846e+13,-5.991012283e+13, 5.071812137e+13, 5.463051329e+13,-4.37486275e+13,-1.136803508e+14,-1.072743336e+14, 5.960794374e+13, 3.784043077e+13, 1.463597594e+14,-5.087851981e+13,-1.391322587e+14, 7.033953998e+13,-9.328448452e+13, 7.978993968e+13,-9.286490206e+13,-2.137056442e+14, 3.219041323e+12,-1.185805665e+12,-9.946404646e+13,-8.08774768e+12, 8.300855552e+13,-2.211458012e+13, 8.747107466e+13,-7.578009423e+13, 6.366624609e+13, 2.421441779e+14,-5.512559116e+13);
s(01,0) = ( 6.845330644e+13,-7.426830598e+12,-8.204392517e+13, 1.429980017e+14, 8.995797119e+13, 9.4413403e+13, 6.779085031e+12,-1.751001409e+14,-2.99783648e+13, 1.714924963e+14,-9.842517139e+13,-1.854662412e+14, 2.677353676e+13, 1.33418935e+14, 8.420218392e+13,-1.67728734e+13, 3.998368785e+13,-1.737890848e+14, 5.846964336e+13, 1.809535167e+14,-3.851942173e+13,-9.902126891e+13,-5.044970689e+13, 7.601660563e+13, 1.72661604e+14, 4.862029018e+13, 9.466342664e+12, 7.878725108e+13,-2.647301119e+13,-8.204356849e+13, 3.939166723e+13, 3.283245694e+13,-5.478569498e+13,-6.52309878e+13,-1.95456615e+14, 2.504841246e+13);
s(02,0) = (-2.391379013e+13, 9.134182338e+13, 8.346380642e+13, 3.980380095e+13,-1.348428406e+14,-2.003006643e+14,-2.514563448e+13, 8.731959618e+13, 1.307049453e+14,-1.185468891e+14, 1.713905881e+14, 2.210407921e+14,-8.745936606e+13,-2.153476685e+14,-4.194142916e+13, 4.830328906e+13,-3.319902121e+13, 1.155027331e+14,-1.130504646e+14,-1.43447115e+14, 9.591280035e+13, 1.958864598e+14,-5.39485533e+13, 1.306673476e+13,-4.259937069e+13,-4.143331871e+13,-7.5381633e+12,-4.961680436e+13, 4.088723597e+13, 4.906917536e+13,-2.191744452e+13,-8.074650459e+13, 1.163181954e+14,-6.083280013e+12, 1.408996825e+14, 3.658828189e+13);
s(03,0) = ( 7.902926758e+13,-1.717210349e+14,-7.420567476e+13,-1.931324613e+13, 1.092781279e+14, 2.325117201e+14,-5.7455907e+13,-3.228353848e+12,-1.123446376e+14,-5.065914898e+13,-2.300546921e+14,-1.578524829e+14, 1.24620483e+14, 1.434516203e+14, 7.573722245e+13, 3.232414429e+13,-4.294881212e+13,-8.363737949e+12, 1.804780614e+14, 5.632568848e+13,-1.000483305e+14,-2.576328006e+14, 2.66775926e+13,-5.786170017e+13,-1.60868244e+12,-1.521581416e+13,-3.126253782e+12, 2.472641496e+13,-3.194206141e+13,-4.665825909e+12, 4.804868397e+13, 1.368503929e+14,-2.070475729e+14, 2.185101704e+13,-6.19205566e+13,-5.290884163e+13);
s(04,0) = (-1.204362112e+12, 1.256003617e+14, 1.375488158e+13, 5.636721133e+13,-1.89411927e+14,-2.138649542e+14, 6.791586855e+13, 1.117967017e+13, 1.355950098e+14, 1.102828607e+14, 2.049327437e+14, 9.462782838e+13,-1.712997303e+14,-1.207626462e+14,-1.125973034e+14,-1.244302493e+14, 3.65777969e+13,-1.630373022e+14,-1.291685284e+14, 8.979265961e+13, 1.358222163e+14, 1.412174286e+14, 5.588802322e+12, 8.185646038e+13,-4.16628267e+13, 5.523797744e+13, 5.385743467e+12, 8.507994903e+13, 6.031384502e+13,-8.085664786e+13,-2.504493596e+13,-6.807407905e+13, 1.838114136e+14,-3.017442207e+13,-1.381593868e+13, 6.092880303e+12);
s(05,0) = ( 7.103932018e+12,-1.726987414e+14, 7.438459839e+13, 5.166199717e+13, 1.074157345e+14, 1.345076658e+14,-1.604969871e+14,-6.391646296e+13,-1.790712479e+14,-1.380448687e+14,-1.8829499e+14, 4.316532128e+13, 1.424739936e+14, 4.209807043e+13, 1.280225582e+14, 7.042349176e+13, 4.038238484e+13, 2.382275102e+14, 1.423081892e+14,-1.280456485e+14,-7.995509753e+13,-1.276287277e+13,-2.110879754e+13,-1.264931017e+14, 5.443605206e+13,-2.951793899e+13, 2.748727231e+12,-1.429302957e+14,-3.250580216e+13, 7.957267023e+13, 3.741770709e+13, 3.688019402e+12,-7.211794035e+13, 8.75887543e+13,-1.205831787e+13, 4.606814501e+13);
s(06,0) = ( 1.094444651e+14, 4.650786105e+13,-1.859095146e+14,-1.429028904e+14,-6.493776247e+13,-8.157332574e+13, 1.515361146e+14, 1.494099063e+14, 6.162138501e+13, 1.749105302e+14, 1.269170795e+14,-3.247703958e+13,-1.025748158e+14,-3.883878065e+12,-1.470681992e+14,-4.510850046e+13,-3.868517087e+13,-1.528109563e+14,-9.633194223e+13, 1.691451769e+14, 4.740928591e+13,-1.201830522e+14, 1.083681793e+14, 9.86785812e+13,-2.036809262e+13,-3.152554214e+13,-6.668397132e+12, 7.769322989e+13, 1.845431303e+13,-1.063752776e+14, 1.136510591e+12, 7.623768952e+13, 1.696479795e+13,-6.481926697e+13, 1.018739594e+14,-4.654493061e+13);
s(07,0) = (-1.118232438e+14,-8.193151695e+13, 2.770711093e+14, 1.689911376e+14, 8.383398601e+13, 2.815257381e+13,-2.134042293e+14,-2.195217372e+14,-4.480223522e+13,-4.017385082e+13,-5.139718059e+13, 6.994333619e+13, 1.94113321e+13, 2.067610879e+13, 8.223156044e+13, 5.639925643e+13,-3.91534071e+13, 2.613844782e+13, 1.52988291e+13,-8.459410741e+13, 4.824270041e+13, 1.941727397e+14,-7.64085479e+13,-2.87927985e+12, 4.028068904e+13, 5.476790259e+13, 1.248045002e+12,-1.858771872e+13,-2.587679841e+13, 4.129444453e+13, 5.629705785e+11,-1.32460399e+14, 9.594418676e+13,-2.597481196e+13,-1.362746465e+14,-4.504145692e+12);
s(08,0) = ( 1.979563858e+14, 1.435316325e+13,-3.353357207e+14,-2.165782814e+14, 2.484161272e+13,-4.329375218e+13, 1.762877953e+14, 2.078988107e+14,-2.798943679e+13,-1.569518114e+14, 3.249628336e+13, 1.638957094e+13, 1.025425649e+13,-4.425243507e+12, 5.983611076e+12, 7.207076476e+13, 4.373167665e+13, 1.244889406e+14,-3.907737892e+13, 4.441398909e+13,-6.574442877e+13,-1.324404609e+14, 3.404786075e+13,-7.387445577e+13,-9.946333404e+13,-1.526839516e+13, 2.17365283e+12,-5.210281944e+13,-1.006102327e+13,-3.007213662e+13, 3.651243463e+13, 9.049757758e+13,-1.246639687e+14, 5.30054332e+13, 8.543244537e+13, 5.238959952e+13);
s(09,0) = (-1.197023199e+14,-5.100178984e+13, 2.848783083e+14, 5.161079307e+13, 1.782963329e+13, 5.930725657e+13,-1.916272785e+14,-1.30502347e+14, 1.316714727e+14, 1.809769408e+14, 2.179533388e+12,-3.601724813e+13,-2.134991168e+13, 7.522750852e+13,-7.760251434e+13,-1.716864825e+14, 3.684506534e+13,-2.620512725e+14,-7.230847465e+12, 1.664748093e+12, 8.34929785e+13, 5.032954772e+13,-3.148264243e+10, 1.494073889e+14, 5.918894998e+13,-4.235163515e+13, 2.95238253e+12, 1.623853497e+14,-6.418283422e+12,-3.096363396e+11,-1.490182938e+13,-5.215361738e+13, 4.866350702e+13,-7.492134929e+13,-1.567675489e+13,-3.395740322e+13);
s(10,0) = ( 9.722717673e+13, 6.69586989e+13,-1.557248763e+14, 5.947120665e+11,-2.164540113e+13,-6.844644976e+13, 1.050923931e+14,-3.07742465e+13,-6.823311774e+13,-1.647089332e+14,-6.441088931e+11, 1.786812841e+13,-5.787763955e+13,-1.642968248e+13, 1.487492384e+14, 1.349735598e+14,-4.276517808e+13, 2.467085466e+14, 6.786291999e+12, 3.202529182e+13, 1.471507148e+13, 1.101556685e+14,-1.114538595e+14,-2.337381086e+14, 7.166133551e+13, 4.661737028e+13,-1.673584965e+12,-1.553942447e+14, 8.144144796e+12,-1.796614691e+13, 1.744284687e+13,-6.365719765e+13,-2.096585467e+13, 1.377258247e+14,-4.023600438e+13,-2.8785834e+13);
s(11,0) = ( 4.245901233e+13,-3.684186402e+13, 5.11934656e+12,-1.546141426e+14,-3.189713969e+13, 4.367168203e+13,-1.120118982e+14, 1.224582873e+14, 8.591974905e+13, 1.322062227e+14,-2.38764017e+13, 4.562203013e+13, 1.349644492e+14, 2.846265373e+13,-1.176264616e+14,-1.66361484e+14,-3.532820751e+13,-9.44781335e+13, 3.498017235e+13,-1.387239948e+14,-8.237621799e+13,-1.149255689e+14, 8.706745199e+13, 2.340425408e+14,-1.16971391e+14, 6.441193644e+12,-5.835483484e+12, 3.578651394e+13, 1.075623477e+13, 7.897442691e+13, 3.165005588e+13, 6.552137307e+13,-6.377205378e+13,-1.196274543e+14, 1.01758449e+14, 5.487838254e+13);
s(12,0) = (-6.084979696e+13, 5.886104781e+13, 1.140622701e+14, 8.748190266e+13,-4.432519845e+13, 4.980640857e+13, 3.920928615e+13,-1.444787371e+14,-2.868773584e+13, 5.842533522e+13,-3.64796612e+12,-1.971078564e+14,-2.262055807e+14, 6.445947567e+13, 3.857739294e+13, 1.952688375e+14, 3.679802735e+13,-5.281616518e+13, 1.973383543e+13, 2.075607419e+14, 1.907969284e+14, 6.349708111e+13,-3.164946146e+13,-1.79028463e+14, 3.924025151e+13,-5.262938777e+13, 4.463882549e+12, 3.55675648e+13, 1.578724075e+13,-9.583707952e+13,-3.738858484e+13,-5.230445384e+13, 5.459953849e+13, 7.455677276e+13,-1.284713464e+14,-8.565476428e+12);
s(13,0) = ( 1.3601415e+14, 6.747058194e+13,-1.647284273e+14,-1.412179581e+13,-2.396109903e+13,-1.191834704e+14,-5.199550973e+13, 3.654701645e+13,-7.038185632e+13,-1.639832667e+14, 2.851876755e+12, 2.075957018e+14, 2.107897161e+14,-7.70093203e+13, 4.41551656e+13,-8.937325908e+13, 4.081624821e+13, 1.432712114e+14, 5.690728587e+12,-2.520863858e+14,-1.793155131e+14, 8.95665394e+13,-2.123449633e+13, 1.533164415e+14, 2.796387827e+13, 2.715072554e+13, 4.840074194e+12,-7.2678156e+13, 8.238625828e+12, 1.23582987e+14, 6.987867414e+13,-4.676256639e+13, 4.403272222e+13,-1.018246856e+14, 2.330199205e+13,-4.77189299e+13);
s(14,0) = (-6.431295994e+13,-3.896912245e+13, 1.448835708e+14,-1.16209163e+14, 2.874413835e+13, 1.763953831e+14,-1.542782602e+13, 1.126877201e+14, 2.184291776e+13, 6.674301683e+13,-1.615192056e+13,-2.249283174e+14,-1.661738531e+14, 6.049345202e+13,-1.380458288e+14, 6.672267319e+13,-3.342638414e+13,-1.527080356e+14, 5.417759923e+12, 1.269046326e+14, 1.670092766e+14,-1.961001126e+14, 1.384000719e+14,-1.114727972e+14,-5.560186057e+13, 3.630373649e+13,-5.209524118e+12, 9.294195061e+13,-1.021343535e+13,-3.893400192e+13,-4.508817928e+13, 1.198775533e+14,-6.92046976e+13, 8.813846173e+13, 1.598399113e+14, 4.150266317e+13);
s(15,0) = ( 8.833010845e+13, 1.226719763e+14,-1.107260492e+14, 2.164314006e+14, 3.370404648e+13,-1.26465805e+14,-6.04104264e+12,-2.11827854e+14,-7.483185851e+13,-2.681201905e+12, 2.035344981e+13, 6.112782707e+13, 7.64040626e+13,-1.525740441e+13, 1.33718799e+14,-1.218572952e+14,-4.507549592e+13, 1.916031344e+13,-3.317518936e+13,-2.440300475e+13,-8.245119584e+13, 1.820130152e+14,-1.150841087e+14, 7.205624849e+13, 1.277494779e+14,-5.257127455e+13,-7.772664537e+11,-1.662100247e+12,-1.044196118e+13, 2.410806116e+12, 5.437189922e+13,-1.182191401e+14, 1.273514611e+14,-3.817760178e+13,-2.544991543e+14, 1.56872913e+13);
s(16,0) = ( 2.368188793e+13, 9.861866891e+12, 2.53759268e+13, 2.693428586e+13, 9.58267794e+12, 1.543914729e+13, 9.91535147e+12, 4.173865684e+13, 1.868346881e+13, 1.529362606e+13, 3.724423881e+13, 1.028191257e+13,-2.194801983e+13, 3.052262626e+13, 3.716616423e+13, 6.528582641e+12,-4.481869208e+12, 4.316433404e+13, 3.940726136e+13,-6.520115665e+12,-3.603156188e+13,-8.412643447e+12, 3.673396651e+13, 1.803859185e+13,-3.335319821e+11, 1.044170663e+13, 5.316982312e+13, 5.500254821e+13,-1.279867999e+13,-2.122720918e+13,-5.075761885e+12,-4.275989734e+13, 8.035040846e+12, 2.310086244e+13, 1.490948929e+12,-3.911869293e+12);
s(17,0) = ( 2.376282251e+13,-1.018636465e+13, 2.539146524e+13, 2.686426361e+13,-9.784477947e+12,-1.584803407e+13, 9.855783669e+12, 4.16682417e+13, 1.831921192e+13,-1.549870951e+13,-3.802507648e+13,-1.050829193e+13,-2.202855348e+13, 3.045631633e+13, 3.640218475e+13, 6.050529859e+12, 4.353855833e+12,-4.359540111e+13,-4.022093796e+13, 6.673459119e+12,-3.605699958e+13,-8.507882416e+12, 3.595471628e+13, 1.657400925e+13,-4.5884474e+11,-1.016255331e+13,-5.306209993e+13,-5.547625957e+13, 1.310654025e+13, 2.166094045e+13,-5.000293265e+12,-4.289471143e+13, 7.852164027e+12, 2.117427151e+13,-2.441625562e+11,-4.823094672e+12);
s(18,0) = ( 2.387228864e+13,-2.758529833e+13, 2.574437505e+13, 9.50275805e+12,-9.45078462e+12,-4.2845938e+13, 1.013204172e+13, 1.47462916e+13,-1.975126035e+13, 7.602648121e+12,-3.465519445e+13,-3.143246157e+13,-2.230034547e+13, 9.7531355e+12,-3.932259975e+13,-1.484827202e+13,-4.370634628e+12, 2.094666214e+13,-3.624199333e+13, 8.486535067e+12,-3.665276276e+13,-6.22335264e+12,-3.8885154e+13,-4.103236355e+13,-1.684352877e+11, 2.45210121e+12, 5.308530142e+13, 2.676173083e+13, 1.162016599e+13, 4.376316482e+13,-5.025225546e+12,-2.013816456e+13,-8.515784077e+12,-5.184793869e+13, 5.117659472e+12, 1.11732511e+13);
s(19,0) = ( 2.373383205e+13,-2.637735042e+13, 2.527226991e+13,-1.134376361e+13, 1.09881287e+13,-4.07157939e+13, 9.722631184e+12,-1.751245454e+13,-1.684726568e+13, 4.352290852e+12, 3.965579389e+13,-2.960384254e+13,-2.202264081e+13,-1.162128458e+13,-3.336920086e+13, 1.629160873e+13, 5.465009263e+12, 1.310434988e+13, 4.133616778e+13, 8.474675005e+12,-3.590579102e+13, 7.119988211e+12,-3.289265326e+13, 4.470211677e+13,-1.19162264e+12, 7.777238978e+12,-5.558911678e+13, 1.739630476e+13,-1.319281406e+13, 4.196467368e+13,-4.87515882e+12, 2.340740782e+13,-7.149275577e+12, 5.631370422e+13,-7.018319054e+12,-9.346444866e+12);
s(20,0) = ( 2.329341684e+13,-9.053595705e+12, 2.455910709e+13,-2.649679752e+13, 9.263573588e+12,-1.398608216e+13, 9.438833174e+12,-4.086228827e+13, 1.900385566e+13,-1.503864533e+13, 3.436435829e+13,-9.098512938e+12,-2.110183753e+13,-2.983690811e+13, 3.763053201e+13,-7.445407957e+12,-7.023142696e+12,-4.313129027e+13, 3.608004845e+13, 6.271862812e+12,-3.455682169e+13, 8.046993619e+12, 3.708684219e+13,-2.048764994e+13,-6.526855536e+10,-1.162806688e+13, 5.933159558e+13,-5.531365821e+13, -1.139031e+13, 1.960575097e+13,-5.169770065e+12, 4.137130245e+13, 8.057647323e+12,-2.614798107e+13, 4.493555898e+12, 3.205820565e+12);
s(21,0) = ( 2.3447555e+13, 9.088554895e+12, 2.47269914e+13,-2.67110225e+13,-9.272881109e+12, 1.413620327e+13, 9.467414885e+12,-4.11051023e+13, 1.901151968e+13, 1.513296469e+13,-3.467539474e+13, 9.265642856e+12,-2.133981105e+13,-2.992464564e+13, 3.747367632e+13,-7.351819796e+12, 6.652532229e+12, 4.318000496e+13,-3.645746097e+13,-6.282178472e+12,-3.48520567e+13, 8.22853078e+12, 3.682624702e+13,-1.978943783e+13, 3.355957709e+11, 1.180747596e+13,-5.883613999e+13, 5.52651516e+13, 1.156277004e+13,-1.982527344e+13,-5.062938226e+12, 4.173477335e+13, 7.946337549e+12,-2.504284207e+13, 3.750577287e+12, 2.777390442e+12);
s(22,0) = ( 2.354006166e+13, 2.633189548e+13, 2.544575705e+13,-1.078335574e+13,-1.042074629e+13, 4.115671394e+13, 1.006319486e+13,-1.701951479e+13,-1.719426221e+13,-4.961244381e+12,-3.888489688e+13, 3.026750879e+13,-2.200516642e+13,-1.151447349e+13,-3.433438956e+13, 1.565358773e+13,-5.492650986e+12,-1.456540503e+13,-4.087487414e+13,-8.346177725e+12,-3.625696715e+13, 6.851348714e+12,-3.401525114e+13, 4.388976256e+13,-1.267337948e+12,-6.722896603e+12, 5.512936911e+13,-1.913819225e+13, 1.292313805e+13,-4.259548971e+13,-5.068627604e+12, 2.301902322e+13,-7.481583188e+12, 5.577431121e+13,-3.6973882e+12,-9.403737643e+12);
s(23,0) = ( 2.381762493e+13, 2.724133071e+13, 2.563955118e+13, 9.752109089e+12, 9.667871519e+12, 4.239684294e+13, 1.005346911e+13, 1.529049287e+13,-1.921126284e+13,-6.929060496e+12, 3.574193005e+13, 3.113726383e+13,-2.22426017e+13, 1.022300176e+13,-3.834283461e+13,-1.503836864e+13, 4.446349293e+12,-1.942818475e+13, 3.74565254e+13,-8.431500058e+12,-3.65058576e+13,-6.370222369e+12,-3.797470199e+13,-4.192961528e+13,-8.418824822e+10,-3.326965875e+12,-5.33216155e+13,-2.501109658e+13,-1.197705192e+13,-4.344215074e+13,-4.988703718e+12,-2.091162971e+13,-8.346432797e+12,-5.317019055e+13, 2.009596278e+12, 1.067462465e+13);
s(24,0) = ( 3.420662699e+13, 1.647959605e+13, 2.722600776e+13, 1.656072321e+13, 2.755917358e+13, 2.557594879e+13, 2.999077662e+13, 2.560578187e+13,-2.139103458e+10, 8.764816759e+11, 8.998019998e+12, 3.401021668e+13, 4.099026218e+13, 3.397438887e+13,-7.166194043e+10,-9.281532353e+11,    6003311381, 2.147246397e+12, 7.689174141e+12, 4.257133224e+13, 2.891896917e+13, 4.254435558e+13,-8.868392966e+10,-2.067607586e+12, 9.592052076e+11,-7.284171959e+11, 1.064150742e+11, 5.435522445e+12, 7.260793748e+13, 4.731407786e+13,-2.884100636e+13, 4.734760706e+13,-2.858422438e+10,-5.220895691e+12,-3.234143931e+12,-5.365712415e+11);
s(25,0) = ( 3.423420686e+13,-1.651626425e+13, 2.72520661e+13, 1.650249914e+13,-2.75444131e+13,-2.559232468e+13, 2.999030874e+13, 2.558735359e+13,-6.035204471e+10,-8.761761832e+11,-9.046991042e+12,-3.399673787e+13, 4.094575438e+13, 3.400529008e+13,-6.350791936e+10,-7.919436625e+11,-6.637394433e+10,-2.136380953e+12,-7.766433445e+12,-4.255563441e+13, 2.886746243e+13, 4.256755698e+13,-2.808421933e+10,-2.032698869e+12, 1.235346757e+12, 7.785124481e+11,-4.959967617e+10,-5.416637265e+12,-7.258864908e+13,-4.73188594e+13,-2.882435659e+13, 4.732433475e+13, 1.170111297e+10,-5.351544732e+12,-3.965841696e+12,-4.311446369e+11);
s(26,0) = ( 3.41723076e+13,-1.64766633e+13, 2.718953147e+13,-1.63851812e+13, 2.752118366e+13,-2.544922478e+13, 2.997936875e+13,-2.539582383e+13,-1.861817777e+10,-8.261745631e+11, 8.912445783e+12,-3.385407044e+13, 4.102956687e+13,-3.386839703e+13,-9.201450425e+10, 7.449008643e+11, 2.409278552e+10,-1.80777245e+12, 7.609103876e+12,-4.260130717e+13, 2.898057312e+13,-4.26321863e+13,-1.24667025e+11, 1.852919521e+12, 8.741812259e+11, 4.849859808e+10, 2.380476709e+11,-4.905025601e+12, 7.262104955e+13,-4.757357052e+13,-2.882836031e+13,-4.757044108e+13,-4.461806856e+10, 5.100351897e+12,-2.728773372e+12, 4.102340547e+11);
s(27,0) = ( 3.42197013e+13, 1.646305853e+13, 2.722013449e+13,-1.645898813e+13,-2.753352367e+13, 2.545398289e+13, 2.996811377e+13,-2.544079475e+13,-7.604310422e+10, 8.409513973e+11,-8.981856413e+12, 3.387216272e+13, 4.097199398e+13,-3.385718207e+13,-8.397906088e+10, 9.172136436e+11,-3.935178147e+10, 1.875678778e+12,-7.686878611e+12, 4.260311898e+13, 2.892485771e+13,-4.260052613e+13,-4.17281574e+10, 1.942785633e+12, 1.14948264e+12,-1.19059128e+11,-2.290984686e+11, 5.00474632e+12,-7.259398905e+13, 4.754698674e+13,-2.880699511e+13,-4.75593223e+13, 1.210654702e+10, 5.016136695e+12,-3.565204349e+12,  4.868291e+11);
s(28,0) = (-5.303882158e+12,-7.456175232e+10, 4.370342278e+13,   -8932696864, 1.567398035e+10,-1.761144902e+10, 5.994722295e+13,-1.03915048e+11, 1.514393911e+10, 1.846286937e+10, 6.159476243e+10, 5.097175438e+10, 1.846276278e+13,-1.220208791e+11, 7.035538666e+10,    9923295686,-4.281854648e+10,-2.730870323e+10, 5.735056404e+10, 4.04951979e+10, 1.352120691e+13, 2.660192372e+10, 9.42136648e+10, 1.70855461e+11,-3.207016737e+12, 9.03801777e+10,-8.413787104e+10,-7.470992692e+10,-4.826537448e+10,-2.347763071e+10, 1.362820729e+14, 2.057330792e+11, 3.330295823e+10, 2.878006244e+11, 6.37767241e+12, 1.695879998e+10);


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