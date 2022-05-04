void RunKFUnitTestMacro() { 
    gSystem->AddIncludePath(" -I$KFPARTICLE_DIR/install/usr/local/include");
    gSystem->Load("$KFPARTICLE_DIR/install/usr/local/lib/libKFParticle.dylib"); 
    gROOT->ProcessLine("KFParticle start_script_part3324151532");
    gROOT->ProcessLine("cout << \"Starting MakeKFParticleTrees macro\" << endl;");
    gROOT->ProcessLine(".x MakeKFParticleTrees.cxx");
    gROOT->ProcessLine("cout << \"Starting MakeKFUnitTestHistos macro\" << endl;");
    gROOT->ProcessLine(".x MakeKFUnitTestHistos.cxx");
}

//export KFPARTICLE_DIR="/Users/vlad/HEP/kfpart_try/KFParticle"

// make DESTDIR=../install install