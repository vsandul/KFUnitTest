#pragma once

#include <vector>

#define TESTSUITE  // uncomment if you are using Testsuite branch of KFParticle
//#define ALIPHYSICS   // uncomment if you are using KFParticle inside AliPhysics

const int NUM_OF_DAUGHTERS = 2;
const int NUM_OF_MOTHERS = 1;
const int NUM_OF_DECAYS = NUM_OF_MOTHERS;
const int NUM_OF_KFPARTICLES = NUM_OF_MOTHERS + NUM_OF_DAUGHTERS;
const int MAX_NUM_OF_TRACKS = 100;

const int D0_PDG = 421;
const int KMINUS_PDG = -321;
const int PIPLUS_PDG = 211;

const int MOTHER_PDG = D0_PDG;
const std::vector<int> DAUGTHERS_PDGS = {KMINUS_PDG, PIPLUS_PDG};

const bool CHECK_PDG_MOTHER = true;
const bool CHECK_PDG_DAUGHTERS = true;

const int CONSTRUCT_METHOD_NUMBER = 2; // 0 or 2

const bool SET_MASS_CONSTRAINT_MOTHER = false;// 
const bool SET_MASS_CONSTRAINT_DAUGHTERS = false;//

const bool SET_TOPOLOGICAL_CONSTRAINT_MOTHER = false;//must know covmat of primary vertex
const bool SET_TOPOLOGICAL_CONSTRAINT_DAUGHTERS = false;//

const TString MCInputFile = "../MCData/D0_to_Kminus_Piplus/D0_to_Kminus_Piplus_output.root";
const TString nameOfMCTree = "Events";
const TString nameOfMagFieldTree = "MagField";

const TString KFTreeOutputFile = "outputKFTrees_D0_decay.root";
const TString nameOfKFBRTree = "KFBeforeReco";
const TString nameOfKFARTree = "KFAfterReco";

const TString KFInputFile = KFTreeOutputFile;
const TString KFHistoOutputFile = "outputKFHistos_D0_decay.root";