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

/*
    covmat[0] = ....; // σxx
    covmat[1] = ....; // σxy
    covmat[2] = ....; // σyy
    covmat[3] = ....; // σxz
    covmat[4] = ....; // σyz
    covmat[5] = ....; // σzz


    */

    return covmat;
}