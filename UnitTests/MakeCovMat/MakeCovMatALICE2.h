#pragma once

#include <vector>
#include <cmath>
#include <random>

#include "../ParticleStructures.h"

int randomSign() {
   return (int)(rand() > (RAND_MAX / 2)) * 2 - 1;
}

// This function is just an example, but not
// a real analysis template. Please, do not
// use it for ALICE data analysis - it is
// just senseless.

// Since covariance matrix is a simmetric matrix, we
// can consider only low triangle of this matrix.
// Also we will decompose it to rows, and write
// this rows one by one into vector.
//
// x, y, z, px, py, pz - our parameters
//
//  Cov. matrix:
//
// σxx
// σxy   σyy
// σxz   σyz    σzz
// σxpx  σypx   σzpx    σpxpx
// σxpy  σypy   σzpy    σpxpy   σpypy
// σxpz  σypz   σzpz    σpxpz   σpypz   σpzpz
//
// xx, yy, zz,... - in microns^2
// pxpx, pypy, ... - in GeV^2
// xpx, ypy, zpz, ... - in microns*GeV

std::vector<float> MakeCovMatALICE(MCParticle part){
    // 6x6 matrix has 21 indep. elements. Lets define all of them.
    std::vector<float> covmat(21);
    float px = part.pX;
    float py = part.pY;
    float pz = part.pZ;
    float pt = part.pT();

    covmat[0] = (-3.22929e-05 + 3.78177e-06*pt + 1.49687e-04/(pt - -2.52631e-01)) ; // σxx
    covmat[1] = (-2.11894e-05  + 2.74783e-06*pt + 9.41565e-05/(pt - -7.87216e-02 ) ) ;//* TMath::Sign(1, -px*py); // σxy
    covmat[2] = (-5.80494e-05  + 8.22236e-06*pt + 1.65514e-04 /(pt - -2.33561e-01)) ; // σyy
    covmat[3] = (-6.59684e-06 + 6.58809e-06*pt +  1.77962e-05/(pt - -7.02902e-02));// * randomSign(); // σxz
    covmat[4] = (-5.73394e-06 + 6.03010e-06*pt +  1.55028e-05/(pt - -5.27143e-02)) ;//* randomSign() ; // σyz
    covmat[5] = (-1.02019e-04 +  2.38563e-05*pt + 7.31716e-04/(pt -  -4.87793e-01)) ; // σzz
    covmat[6] = (1.21612e-05 + 8.62144e-06*pt + 2.02609e-05 /(pt - -2.88841e-02)) ;//* (-1) ; // σxpx
    covmat[7] = ( 1.67691e-05 + 5.61722e-06*pt +  1.26688e-05/(pt - 2.38342e-04));//* TMath::Sign(1, px*py); // σypx
    covmat[8] = (1.66434e-05 + 4.25166e-06*pt + 1.01088e-05/(pt - -1.70572e-03));//* TMath::Sign(1, px*pz) ; // σzpx
    covmat[9] = (6.32709e-05 + 2.53432e-06/(7.61319e-03+exp(-1.99899e+00 *pt))) ; // σpxpx
    covmat[10] = ( 1.36538e-05  +  7.40315e-06*pt + 1.42164e-05/(pt - -3.02018e-03));//* TMath::Sign(1, px*py) ; // σxpy
    covmat[11] = ( 1.22428e-05 + 8.48157e-06*pt +  1.67240e-05/(pt - -1.55001e-02));// * (-1); // σypy
    covmat[12] = (1.33113e-05 + 5.79967e-06*pt + 1.24222e-05/(pt - -1.46662e-02));//* TMath::Sign(1, pz*py) ; // σzpy
    covmat[13] = (3.03710e-05 + 8.26997e-06 /(1.53282e-02+exp(-1.26413e+00*pt)));//* TMath::Sign(1, px*py) ; // σpxpy
    covmat[14] = (6.27766e-05 + 2.42925e-06/(7.08628e-03+exp(-2.00486e+00*pt))) ; // σpypy
    covmat[15] = (9.69497e-06 +  8.05202e-06*pt + 5.70877e-06/(pt - 3.34999e-02));//* randomSign() ; // σxpz
    covmat[16] = (1.39749e-05 +  1.14156e-05*pt + 4.62978e-06/(pt - 1.79092e-02));//* randomSign()  ; // σypz
    covmat[17] = (1.87989e-05 + 1.17782e-05*pt + 3.29052e-05/(pt - -3.50837e-02)) ;//* (-1); // σzpz
    covmat[18] = (9.35819e-06 + 2.81418e-05/(5.04531e-02+exp(-7.92893e-01*pt))) ;//* TMath::Sign(1, pz*px) ; // σpxpz
    covmat[19] = (1.13372e-05 + 2.59335e-05/(4.75620e-02+exp(-8.21524e-01 *pt)));//* TMath::Sign(1, pz*py) ;// σpypz
    covmat[20] = (3.17555e-05 +  2.57168e-05/(5.84967e-02+exp(-7.71575e-01*pt))) ; // σpzpz

    //go from cm to microns
    covmat[0] *= 1e8;
    covmat[1] *= 1e8;
    covmat[2] *= 1e8;
    covmat[3] *= 1e8;
    covmat[4] *= 1e8;
    covmat[5] *= 1e8;

    covmat[6] *= 1e4;
    covmat[7] *= 1e4;
    covmat[8] *= 1e4;
    covmat[10] *= 1e4;
    covmat[11] *= 1e4;
    covmat[12] *= 1e4;
    covmat[15] *= 1e4;
    covmat[16] *= 1e4;
    covmat[17] *= 1e4;


    return covmat;

}