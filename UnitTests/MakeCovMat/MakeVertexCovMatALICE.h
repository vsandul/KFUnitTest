#pragma once
#define MAKE_VERTEX_COV_MAT

#include <vector>
#include <cmath>

#include "../ParticleStructures/MCParticleStructure.h"


// This function is just an example, but not
// a real analysis template. Please, do not
// use it for ALICE data analysis - it is
// just senseless.

// Since covariance matrix is a simmetric matrix, we
// can consider only low triangle of this matrix.
// Also we will decompose it to rows, and write
// this rows one by one into vector.
//
// x, y, z - our global parameters
//
//  Cov. matrix:
//
// σxx
// σxy   σyy
// σxz   σyz    σzz
//
// xx, yy, zz,... - in cm^2


std::vector<float> MakeVertexCovMatrix(const MCParticleStruct& part){
    // 3x3 matrix has 6 indep. elements. Lets define all of them.
    std::vector<float> covmat(6);

    /*float pt = -1.;
    if (part.isMother)
        pt = part.finalPT();
    else
        pt = part.initialPT();*/


    covmat[0] = 4e-5; // σxx
    covmat[1] = 2e-5 * (-1 + (double)rand() / RAND_MAX * 2); // σxy
    covmat[2] = 4e-5; // σyy
    covmat[3] = 1e-6 * (-1 + (double)rand() / RAND_MAX * 2); // σxz
    covmat[4] = 1e-6; // σyz
    covmat[5] = 0.1 * (-1 + (double)rand() / RAND_MAX * 2); // σzz


    

    return covmat;
}