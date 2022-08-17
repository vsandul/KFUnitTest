#pragma once

//#include "../ConfigConstants.h"

template<typename T>
bool SmearParameters(size_t num_of_params, T parameters[], T covMatArr[]){
//some strings are borrowed from Annalena's code
// https://github.com/AnnalenaKa/KFUnitTest
    size_t covmat_size = num_of_params*(num_of_params+1)/2;
    TRandom3 *randomGenerator = new TRandom3(0);
    TVectorF randomVec(num_of_params);
    for(size_t i = 0; i < num_of_params; i++){
        randomVec[i] = randomGenerator->Gaus(0,1);
    }
    delete randomGenerator;

    TMatrixF covMat(num_of_params,num_of_params); //lets convert vectorized covmat into TMatrix object
    for (size_t i = 0; i < covmat_size; i++){
        size_t n_row = floor((-1 + sqrt(1+8*i))/2);
        size_t n_col = (n_row+1) - ((n_row+1)*(n_row+2)/2-i);
        //cout << "i = " << i << "; n_row = " << n_row << "; n_col = " << n_col << "\n";
        covMat[n_row][n_col] = covMat[n_col][n_row] = covMatArr[i];
    }
    
    TMatrixF decomposedMatrix;
    gErrorIgnoreLevel=kFatal;
    TDecompChol *choleskyComposition = new TDecompChol(covMat);
    if (choleskyComposition->Decompose() == false){
        //cout<< "Matrix not pos. definite"<<endl;
        return false;
    }
    decomposedMatrix.ResizeTo(choleskyComposition->GetU());
    /// Decomposed matrix has property: U^T * U = Cov
    // sets decomposedMatrix = U
    decomposedMatrix = choleskyComposition->GetU();
    delete choleskyComposition;
    TMatrixD decomposedMatrix_t;
    /// "draws" matrix with the size of decomposedMatrix
    decomposedMatrix_t.ResizeTo(decomposedMatrix);
    /// sets decomposedMatrix_t as the transpose of decomposedMatrix
    decomposedMatrix_t.Transpose(decomposedMatrix);

    TVectorF randomCorrVector = randomVec *= decomposedMatrix_t;
    for (size_t iparam = 0; iparam < num_of_params; iparam++){
        parameters[iparam] += randomCorrVector[iparam];
    }

    return true;
}

bool SmearParticle(KFParticle& part){
    size_t num_of_params = 6;
    size_t covmat_size = num_of_params*(num_of_params+1)/2;

    float params[num_of_params];
    for (int i = 0; i < num_of_params; i++)
        params[i] = part.GetParameter(i);

    float covmat[covmat_size];
    for (int i = 0; i < covmat_size; i++)
        covmat[i] = part.GetCovariance(i);

    bool res = SmearParameters(num_of_params, params, covmat);

    float mass, masserr; part.GetMass(mass, masserr);
    float chi2 = part.GetChi2();
    float charge = (int)part.GetQ();
    int ndf = part.GetNDF();

    #ifdef TESTSUITE
    part.Create(params, covmat, charge, chi2, ndf, mass);
    #else
    part.Create(params, covmat, charge, mass);
    #endif

    return res;
}

bool SmearVertex(KFPVertex& vert){
    size_t num_of_params = 3;
    size_t covmat_size = num_of_params*(num_of_params+1)/2;

    float params[num_of_params];
    vert.GetXYZ(params);

    float covmat[covmat_size];
    vert.GetCovarianceMatrix(covmat);

    bool res = SmearParameters(num_of_params, params, covmat);
    vert.SetXYZ(params);
    return res;
}