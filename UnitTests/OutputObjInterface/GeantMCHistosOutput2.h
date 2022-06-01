#pragma once

#include "OutputObjInterface.h"

class GeantMCHistosOutput2: public OutputObjInterface{
    public:
        GeantMCHistosOutput2(TFile& outputFile):OutputObjInterface(outputFile){};
        ~GeantMCHistosOutput2(){};

        void Create() override ;
        void Fill(const MCParticleStruct& mcPart) override ;
        void Fill(const KFParticle& kfPart) override ;
        void Fill(const MCParticleStruct& mcPart, const KFParticle& kfPart) override ;
        void Write() override ;
        
    private:
        TH1F *fHistPX;
        TH1F *fHistPY;
        TH1F *fHistPZ;
};

////---------- method implementations ----------

void GeantMCHistosOutput2::Create(){
    fHistPX = new TH1F("fHistPX", "fHistPX", 100, -1, 2);
    fHistPY = new TH1F("fHistPY", "fHistPY", 100, -1, 2);
    fHistPZ = new TH1F("fHistPZ", "fHistPZ", 100, -1, 2);
}

void GeantMCHistosOutput2::Fill(const MCParticleStruct& mcPart){
    fHistPX -> Fill(mcPart.pX);
    fHistPY -> Fill(mcPart.pY);
    fHistPZ -> Fill(mcPart.pZ);
}

void GeantMCHistosOutput2::Fill(const KFParticle& kfPart){
    //....
}

void GeantMCHistosOutput2::Fill(const MCParticleStruct& mcPart, const KFParticle& kfPart){
    //....
}

void GeantMCHistosOutput2::Write(){
    TDirectory* GeantMCHistosOutput2 = outputFile->mkdir("GeantMCHistosOutput2");
    GeantMCHistosOutput2->cd();
    fHistPX -> Write();
    fHistPY -> Write();
    fHistPZ -> Write();
}