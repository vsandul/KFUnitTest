#include "ConfigConstants.h"

void RunKFUnitTestMacro() {
    #ifndef ALIPHYSICS
    gSystem->AddIncludePath(" -I$KFPARTICLE_DIR/install/usr/local/include");
    gSystem->Load("$KFPARTICLE_DIR/install/usr/local/lib/libKFParticle.dylib"); 
    gROOT->ProcessLine("KFParticle start_script_part3324151532");
    #endif

    gROOT->ProcessLine(".x MakeKFParticleTrees.cxx");
    gROOT->ProcessLine(".x MakeKFUnitTestHistos.cxx");
}