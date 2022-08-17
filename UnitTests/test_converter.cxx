#include <random>
#include <chrono> 

#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

#include "ALICETrackParamConverter.h"


void CreateCovMat(double cv[21]){

    std::uniform_real_distribution<double> unif(0,20);
    std::default_random_engine re;
    re.seed(std::chrono::system_clock::now().time_since_epoch().count());

    cv[0] = unif(re);
    cv[2] = unif(re);
    cv[5] = unif(re);
    cv[9] = unif(re);
    cv[14] = unif(re);
    cv[20] = unif(re);

    cv[1] = sqrt(cv[0]*cv[2])*unif(re)/200;
    cv[3] = sqrt(cv[0]*cv[5])*unif(re)/200;
    cv[4] = sqrt(cv[2]*cv[5])*unif(re)/200;
    cv[6] = sqrt(cv[0]*cv[9])*unif(re)/200;
    cv[7] = sqrt(cv[2]*cv[9])*unif(re)/200;
    cv[8] = sqrt(cv[5]*cv[9])*unif(re)/200;
    cv[10] = sqrt(cv[0]*cv[14])*unif(re)/200;
    cv[11] = sqrt(cv[2]*cv[14])*unif(re)/200;
    cv[12] = sqrt(cv[5]*cv[14])*unif(re)/200;
    cv[13] = sqrt(cv[9]*cv[14])*unif(re)/200;
    cv[15] = sqrt(cv[0]*cv[20])*unif(re)/200;
    cv[16] = sqrt(cv[2]*cv[20])*unif(re)/200;
    cv[17] = sqrt(cv[5]*cv[20])*unif(re)/200;
    cv[18] = sqrt(cv[9]*cv[20])*unif(re)/200;
    cv[19] = sqrt(cv[14]*cv[20])*unif(re)/200;
    
}

void PrintGlobalParams(double xyz[3], double pxpypz[3], double cv[21], short sign){
    std::cout << "parameters:\t" << xyz[0] << "\t" << xyz[1] << "\t" << xyz[2] << "\t" << pxpypz[0] << "\t" << pxpypz[1] << "\t" << pxpypz[2] << std::endl;
    std::cout << "sign:\t" << sign << std::endl;
    std::cout << "covmat:\t" << "\n" << 
    cv[0]<<"\n"<<
    cv[1]<<"\t"<<cv[2]<<"\n"<<
    cv[3]<<"\t"<<cv[4]<<"\t"<<cv[5]<<"\n"<<
    cv[6]<< "\t"<<cv[7]<<"\t"<< cv[8]<<"\t"<<cv[9]<<"\n"<<
    cv[10]<< "\t"<<cv[11]<<"\t"<<cv[12]<< "\t"<<cv[13]<<"\t"<<cv[14]<<"\n"<<
    cv[15]<< "\t"<<cv[16]<<"\t"<<cv[17]<<"\t"<<cv[18]<<"\t"<<cv[19]<<"\t"<<cv[20]<<"\n";
    cout << endl;
}

void PrintLocalParams(double x, double alpha, double params[5], double cv[15], short sign){
    std::cout << "x: " << x << "\t" << "alpha: " << alpha << std::endl;
    std::cout << "parameters:\t" << params[0] << "\t" << params[1] << "\t" << params[2] << "\t" << params[3] << "\t" << params[4] << std::endl;
    std::cout << "sign:\t" << sign << std::endl;
    std::cout << "covmat:\t" << "\n" << 
    cv[0]<<"\n"<<
    cv[1]<<"\t"<<cv[2]<<"\n"<<
    cv[3]<<"\t"<<cv[4]<<"\t"<<cv[5]<<"\n"<<
    cv[6]<< "\t"<<cv[7]<<"\t"<< cv[8]<<"\t"<<cv[9]<<"\n"<<
    cv[10]<< "\t"<<cv[11]<<"\t"<<cv[12]<< "\t"<<cv[13]<<"\t"<<cv[14]<<"\n";
    cout << endl;
}

void PrintLocalParams(double x, double alpha, const double params[5], const double cv[15], short sign){
    std::cout << "x: " << x << "\t" << "alpha: " << alpha << std::endl;
    std::cout << "parameters:\t" << params[0] << "\t" << params[1] << "\t" << params[2] << "\t" << params[3] << "\t" << params[4] << std::endl;
    std::cout << "sign:\t" << sign << std::endl;
    std::cout << "covmat:\t" << "\n" << 
    cv[0]<<"\n"<<
    cv[1]<<"\t"<<cv[2]<<"\n"<<
    cv[3]<<"\t"<<cv[4]<<"\t"<<cv[5]<<"\n"<<
    cv[6]<< "\t"<<cv[7]<<"\t"<< cv[8]<<"\t"<<cv[9]<<"\n"<<
    cv[10]<< "\t"<<cv[11]<<"\t"<<cv[12]<< "\t"<<cv[13]<<"\t"<<cv[14]<<"\n";
    cout << endl;
}

void test_converter(){
{
    /*double xyz[3] = {0.1, 0.2, 0.3};
    double pxpypz[3] = {1,4,3};

    short sign = 1;

    double cv[21];
    CreateCovMat(cv);

    cout << "//------generated global and Ali... local---------------\n";

    PrintGlobalParams(xyz,pxpypz, cv, sign);
    cout << endl;

    AliExternalTrackParam p;
    p.Set(xyz, pxpypz, cv, sign);

    p.Print();

    // --------------------------------

    cout << "//------global and global converted to local---------------\n";

    ALICETrackParamsConverter conv(xyz, pxpypz, cv, sign);

    cout << endl;
    conv.PrintGlobalParams();
    conv.PrintLocalParams();

    //-----------------

    cout << "//------global and local converted to global---------------\n";

    double locParams[5]; conv.GetLocalParams(locParams);
    double locCV[15]; conv.GetLocalCovMat(locCV);
    double alpha; conv.GetAlpha(alpha);
    double x; conv.GetX(x);
    short trackSign; conv.GetTrackSign(trackSign);


    ALICETrackParamsConverter conv2(locParams, locCV, x, alpha, sign);

    cout << endl;
    conv2.PrintGlobalParams();
    conv2.PrintLocalParams();
    cout << endl;
    
}
    //--------------------------------------
{    cout << "\n\n from local to global Ali... \n";

    double x = 0.218282, alpha = 1.32582;
    double parameters[5] = {-0.0485071 ,0.3 , -8.07806e-17 ,0.727607 ,0.242536};
    double covmat15[15] = { 19.5329,
                  -8.28721   ,    3.7938,
                  0.569385 ,   -0.714441   ,  0.399747,
                  0.448221  ,   0.329101  ,    0.13583   ,  0.695114,
                  0.336735  ,  -0.177225  ,  0.0355615 ,   0.0922413 ,   0.0575128,

    };
    AliExternalTrackParam p(x, alpha, parameters, covmat15);

    double glob_xyz[3], glob_pxpypz[3];
    double glob_covmat[21];

    p.GetXYZ(glob_xyz);
    p.GetPxPyPz(glob_pxpypz);
    p.GetCovarianceXYZPxPyPz(glob_covmat);

    PrintGlobalParams(glob_xyz, glob_pxpypz, glob_covmat, 0);
  */  
}


/*
{

    double xyz[3] = {0.1, 0.2, 0.3};
    double pxpypz[3] = {1,4,3};

    short sign = 1;

    double cv[21];
    CreateCovMat(cv);

    cout << "\n -=-=-=-  Generated Global Params -=-=-=-=-\n";
    PrintGlobalParams(xyz,pxpypz, cv, sign);
    cout << endl;

    AliExternalTrackParam p(xyz, pxpypz, cv, sign);
   // p.CheckCovariance();
    cout << "\n -=-=-=-  AliExt.. local Params -=-=-=-=-\n";
    p.Print();

    //---

    const Double_t *loc_params__ = p.GetParameter();
    const Double_t *loc_covmat__ = p.GetCovariance();
    short loc_sign = p.GetSign();
    double x = p.GetX();
    double alpha = p.GetAlpha();
    
    double loc_params[5], loc_covmat[15];
    for (int i = 0; i < 5; i++)
        loc_params[i] = loc_params__[i];
    for (int i = 0; i < 15; i++)
        loc_covmat[i] = loc_covmat__[i];

    cout << "\n -=-=-=-  AliExt.. local Params - extracted -=-=-=-=-\n";
    PrintLocalParams(x, alpha, loc_params, loc_covmat, loc_sign);

    //------

    AliExternalTrackParam p2(x, alpha, loc_params, loc_covmat);
   // p2.CheckCovariance();
    cout << "\n -=-=-=-  AliExt.. local Params - printed -=-=-=-=-\n";
    p2.Print();

    double glob_xyz[3], glob_pxpypz[3];
    double glob_covmat[21];

    p.GetXYZ(glob_xyz);
    p.GetPxPyPz(glob_pxpypz);
    p.GetCovarianceXYZPxPyPz(glob_covmat);

    cout << "\n -=-=-=-  AliExt.. global Params - extracted -=-=-=-=-\n";
    PrintGlobalParams(glob_xyz, glob_pxpypz, glob_covmat, 1);
    


}
*/

// To compare AliExternalTrackParam performance and this class performance
{

    double xyz[3] = {0.001, 0.001, 3};
    double pxpypz[3] = {1.1,4,3.2};
    short sign = 1;
    double cv[21];
    CreateCovMat(cv);
    cout << "\n -=-=-=-  Generated Global Params -=-=-=-=-\n";
    PrintGlobalParams(xyz,pxpypz, cv, sign);
    cout << "\n";

    
    AliExternalTrackParam track(xyz, pxpypz, cv, sign);
    double out_alitrack_xyz[3]; track.GetXYZ(out_alitrack_xyz);
    double out_alitrack_pxpypz[3]; track.GetPxPyPz(out_alitrack_pxpypz);
    const double *out_alitrack_local_params = track.GetParameter();
    double out_alitrack_x; out_alitrack_x = track.GetX();
    double out_alitrack_alpha; out_alitrack_alpha = track.GetAlpha();
    double out_alitrack_global_covmat[21]; track.GetCovarianceXYZPxPyPz(out_alitrack_global_covmat);
    const double *out_alitrack_local_covmat = track.GetCovariance();
    short out_alitrack_sign = track.GetSign();

    ALICETrackParamsConverter conv(xyz, pxpypz, cv, sign);
    double out_converter_xyz[3]; conv.GetXYZ(out_converter_xyz);
    double out_converter_pxpypz[3]; conv.GetPxPyPz(out_converter_pxpypz);
    double out_converter_local_params[5]; conv.GetLocalParams(out_converter_local_params);
    double out_converter_x; conv.GetX(out_converter_x);
    double out_converter_alpha; conv.GetAlpha(out_converter_alpha);
    short out_converter_sign; conv.GetTrackSign(out_converter_sign);
    double out_converter_global_covmat[21]; conv.GetGlobalCovMat(out_converter_global_covmat);
    double out_converter_local_covmat[15]; conv.GetLocalCovMat(out_converter_local_covmat);

    cout << "\n -=-=-=-  Global: AliTrack vs Converter -=-=-=-=-\n";
    //double xyz[3], double pxpypz[3], double cv[21], short sign
    PrintGlobalParams(out_alitrack_xyz, out_alitrack_pxpypz,  out_alitrack_global_covmat,out_alitrack_sign); //
    PrintGlobalParams(out_converter_xyz, out_converter_pxpypz, out_converter_global_covmat, out_converter_sign);

    cout << "\n -=-=-=-  Local: AliTrack vs Converter -=-=-=-=-\n";
    //double x, double alpha, double params[5], double cv[15], short sign
    PrintLocalParams(out_alitrack_x, out_alitrack_alpha, out_alitrack_local_params, out_alitrack_local_covmat, out_alitrack_sign);
    PrintLocalParams(out_converter_x, out_converter_alpha, out_converter_local_params, out_converter_local_covmat, out_converter_sign);



}



}