#pragma once

#include <vector>

// header file with function to produce covariance matrix for particle
// Leave only one of the files uncommented
#include "MakeCovMat/MakeCovMatALICE.h"

// Settings of KFParticle version 
#define TESTSUITE  // uncomment if you are using Testsuite branch of KFParticle
//#define ALIPHYSICS   // uncomment if you are using KFParticle inside AliPhysics

//#define CASCADES // for cascades - will be done later.... (?)

const int NUM_OF_DAUGHTERS = 2;
const int NUM_OF_MOTHERS = 1;
const int NUM_OF_DECAYS = NUM_OF_MOTHERS;
const int NUM_OF_KFPARTICLES = NUM_OF_MOTHERS + NUM_OF_DAUGHTERS;
const int MAX_NUM_OF_TRACKS = 50;

const int D0_PDG = 421;
const int KMINUS_PDG = -321;
const int PIPLUS_PDG = 211;

const int JPSI_PDG = 443;
const int eMINUS_PDG = 11;
const int ePLUS_PDG = -11;

// Setup for PDGs of Mother and Daughter particles
const int MOTHER_PDG = D0_PDG;
const std::vector<int> DAUGTHERS_PDGS = {KMINUS_PDG, PIPLUS_PDG};

//const int MOTHER_PDG = JPSI_PDG;
//const std::vector<int> DAUGTHERS_PDGS = {eMINUS_PDG, ePLUS_PDG};

const bool CHECK_PDG_MOTHER = true;
const bool CHECK_PDG_DAUGHTERS = true;

// Method of reconstruction
const int CONSTRUCT_METHOD_NUMBER = 2; // 0 or 2

// Mass and topological constraints
const bool SET_MASS_CONSTRAINT_MOTHER = false;// 
const bool SET_MASS_CONSTRAINT_DAUGHTERS = true;//

const bool SET_TOPOLOGICAL_CONSTRAINT_MOTHER = false;//must know covmat of primary vertex
const bool SET_TOPOLOGICAL_CONSTRAINT_DAUGHTERS = true;//

// Settings of input and output files
// File with MC data and names of trees
const TString MCInputFile = "../MCData/D0_to_Kminus_Piplus/D0_to_Kminus_Piplus_output.root";
const TString nameOfMCTree = "Events";
const TString nameOfMagFieldTree = "MagField";
// Name of output file with KFParticles trees
const TString KFTreeOutputFile = "outputKFTrees_D0_decay.root";
const TString nameOfKFBRTree = "KFBeforeReco";
const TString nameOfKFARTree = "KFAfterReco";
// Name of output file with QA plots and histograms
const TString KFInputFile = KFTreeOutputFile;
const TString KFHistoOutputFile = "outputKFHistos_D0_decay.root";