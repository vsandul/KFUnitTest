#pragma once

#include "OutputObjInterface.h"

class GeantMCHistosOutput: public OutputObjInterface{
    public:
        GeantMCHistosOutput(TFile& outputFile):OutputObjInterface(outputFile){};
        ~GeantMCHistosOutput(){};

        // methods that must be realized by user
        void Create() override ;
        void Fill(const MCParticleStruct& mcPart) override ;
        void Fill(const KFParticle& kfPart) override ;
        void Fill(const MCParticleStruct& mcPart, const KFParticle& kfPart) override ;
        void Write() override ;
        
    private:
        TH1F *fHistX; // user-defined histograms
        TH1F *fHistY;
        TH1F *fHistZ;
};

////---------- method implementations ----------

void GeantMCHistosOutput::Create(){
    fHistX = new TH1F("fHistX", "fHistX", 100, -1, 2);
    fHistY = new TH1F("fHistY", "fHistY", 100, -1, 2);
    fHistZ = new TH1F("fHistZ", "fHistZ", 100, -1, 2);
}

void GeantMCHistosOutput::Fill(const MCParticleStruct& mcPart){
    fHistX -> Fill(mcPart.x);
    fHistY -> Fill(mcPart.y);
    fHistZ -> Fill(mcPart.z);
}

void GeantMCHistosOutput::Fill(const KFParticle& kfPart){
    //....
}

void GeantMCHistosOutput::Fill(const MCParticleStruct& mcPart, const KFParticle& kfPart){
    //....
}

void GeantMCHistosOutput::Write(){
    TDirectory* GeantMCHistosOutput = outputFile->mkdir("GeantMCHistosOutput");
    GeantMCHistosOutput->cd();
    fHistX -> Write();
    fHistY -> Write();
    fHistZ -> Write();
}