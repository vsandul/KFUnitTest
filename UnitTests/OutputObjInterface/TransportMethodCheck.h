/*
An example of user-defined class of output object.
The short instruction:
1) Name your class
2) Add output objects (histograms, plots, etc.) into private filed of the class
3) Realize methods Create(), Fill(..), PreWriteProcess() and Write().
If some of the methods are not need - leave them empty;
4) Add your class into "OutputMap.h" file in the way it is done for this class
*/

#pragma once

#include "OutputObjInterface.h"

class TransportMethodCheck: public OutputObjInterface{
    public:
        TransportMethodCheck(TFile& outputFile):OutputObjInterface(outputFile){};
        ~TransportMethodCheck(){};

        // methods that must be realized by user
        void Create() override ;
        void Fill() override {};
        void Fill(const MCParticleStruct& mcPart) override ;
        void Fill(const KFParticleStruct& kfPart) override ;
        void Fill(const MCParticleStruct& mcPart, const KFParticleStruct& kfPart) override ;
        void PreWriteProcess() override ;
        void Write() override ;
        
    private:
        TH1F *fHistDeltaXAbs; // user-defined histograms
        TH1F *fHistDeltaYAbs;
        TH1F *fHistDeltaZAbs;
        TH1F *fHistDeltaRAbs;
        TH1F *fHistDeltaPXAbs;
        TH1F *fHistDeltaPYAbs;
        TH1F *fHistDeltaPZAbs;
        TH1F *fHistDeltaPTAbs;
        TH1F *fHistDeltaPAbs;
        TH1F *fHistDeltaEAbs;
        TH1F *fHistDeltaMassAbs;

        TH1F *fHistDeltaXOverTrackLength; // user-defined histograms
        TH1F *fHistDeltaYOverTrackLength;
        TH1F *fHistDeltaZOverTrackLength;
        TH1F *fHistDeltaROverTrackLength;
        TH1F *fHistDeltaPXOverTrackLength;
        TH1F *fHistDeltaPYOverTrackLength;
        TH1F *fHistDeltaPZOverTrackLength;
        TH1F *fHistDeltaPTOverTrackLength;
        TH1F *fHistDeltaPOverTrackLength;
        TH1F *fHistDeltaEOverTrackLength;
        TH1F *fHistDeltaMassOverTrackLength;
};

////---------- method implementations ----------

void TransportMethodCheck::Create(){
    fHistDeltaXAbs = new TH1F("fHistDeltaXAbs","#Delta X;#Delta X, cm; counts", 50, -5,5);
    fHistDeltaYAbs = new TH1F("fHistDeltaYAbs","#Delta Y;#Delta Y, cm; counts", 50, -5,5);
    fHistDeltaZAbs = new TH1F("fHistDeltaZAbs","#Delta Z;#Delta Z, cm; counts", 50, -5,5);
    fHistDeltaRAbs = new TH1F("fHistDeltaRAbs","#Delta R;#Delta R, cm; counts", 50, -5,5);
    fHistDeltaPXAbs = new TH1F("fHistDeltaPXAbs","#Delta Px;#Delta Px, GeV; counts", 50, -1,1);
    fHistDeltaPYAbs = new TH1F("fHistDeltaPYAbs","#Delta Py;#Delta Py, GeV; counts", 50, -1,1);
    fHistDeltaPZAbs = new TH1F("fHistDeltaPZAbs","#Delta Pz;#Delta Pz, GeV; counts", 50, -0.1,0.1);
    fHistDeltaPTAbs = new TH1F("fHistDeltaPTAbs","#Delta Pt;#Delta Pt, GeV; counts", 50, -0.1,0.1);
    fHistDeltaPAbs = new TH1F("fHistDeltaPAbs","#Delta P;#Delta P, GeV; counts", 50, -0.1,0.1);
    fHistDeltaEAbs = new TH1F("fHistDeltaEAbs","#Delta E;#Delta E, GeV; counts", 50, -0.1,0.1);
    fHistDeltaMassAbs = new TH1F("fHistDeltaMassAbs","#Delta Mass;#Delta Mass, GeV; counts", 50, -0.1,0.1);

    fHistDeltaXOverTrackLength = new TH1F("fHistDeltaXOverTrackLength","#Delta X/Lmc; #Delta X/Lmc; counts", 50, -1,1);
    fHistDeltaYOverTrackLength = new TH1F("fHistDeltaYOverTrackLength","#Delta Y/Lmc; #Delta Y/Lmc; counts", 50, -1,1);
    fHistDeltaZOverTrackLength = new TH1F("fHistDeltaZOverTrackLength","#Delta Z/Lmc; #Delta Z/Lmc; counts", 50, -1,1);
    fHistDeltaROverTrackLength = new TH1F("fHistDeltaROverTrackLength","#Delta R/Lmc; #Delta R/Lmc; counts", 50, -1,1);
    fHistDeltaPXOverTrackLength = new TH1F("fHistDeltaPXOverTrackLength","#Delta Px/Lmc; #Delta Px/Lmc, GeV/cm; counts", 50, -1e-3,1e-3);
    fHistDeltaPYOverTrackLength = new TH1F("fHistDeltaPYOverTrackLength","#Delta Py/Lmc; #Delta Py/Lmc, GeV/cm; counts", 50, -1e-3,1e-3);
    fHistDeltaPZOverTrackLength = new TH1F("fHistDeltaPZOverTrackLength","#Delta Pz/Lmc; #Delta Pz/Lmc, GeV/cm; counts", 50, -1e-3,1e-3);
    fHistDeltaPTOverTrackLength = new TH1F("fHistDeltaPTOverTrackLength","#Delta Pt/Lmc; #Delta Pt/Lmc, GeV/cm; counts", 50, -1e-3,1e-3);
    fHistDeltaPOverTrackLength = new TH1F("fHistDeltaPOverTrackLength","#Delta P/Lmc; #Delta P/Lmc, GeV/cm; counts", 50, -1e-3,1e-3);
    fHistDeltaEOverTrackLength = new TH1F("fHistDeltaEOverTrackLength","#Delta E/Lmc; #Delta E/Lmc, GeV/cm; counts", 50, -1e-2,1e-2);
    fHistDeltaMassOverTrackLength = new TH1F("fHistDeltaMassOverTrackLength","#Delta Mass/Lmc, GeV/cm; #Delta Mass/Lmc; counts", 50, -1e-2,1e-2);

}

void TransportMethodCheck::Fill(const MCParticleStruct& mcPart){
    //MCParticleStruct part(mcPart);
    KFParticle kfPart;
    //kfPart.SetConstructMethod(2);
    float params[6];
    params[0] = mcPart.initialX;
    params[1] = mcPart.initialY;
    params[2] = mcPart.initialZ;
    params[3] = mcPart.initialPX;
    params[4] = mcPart.initialPY;
    params[5] = mcPart.initialPZ;
    //auto covmat_vec_ = MakeCovMatALICE(mcPart);
    float covmat[21];
    //std::copy(covmat_vec_.begin(), covmat_vec_.end(), covmat);
    auto charge_ = mcPart.charge;
    auto chi2_ = 0;//mcPart.chi2;
    auto ndf_ = 0;//mcPart.ndf;
    auto mass_ = mcPart.mass;
    #ifdef TESTSUITE
    kfPart.Create(params,covmat,charge_,chi2_,ndf_,mass_);
    #else
    kfPart.Create(params,covmat,charge_,mass_);
    #endif
    kfPart.SetId(mcPart.trackID);
    kfPart.SetPDG(mcPart.pdg);
    kfPart.SetAtProductionVertex(true);
    
    float xyz[3] = {mcPart.finalX, mcPart.finalY, mcPart.finalZ};
    kfPart.TransportToPoint(xyz);/**/

    float _mass_, _mass_err_;
    float _pt_, _pt_err_;
    float _p_, _p_err_;
    kfPart.GetMass(_mass_, _mass_err_);
    kfPart.GetPt(_pt_, _pt_err_);
    kfPart.GetMomentum(_p_, _p_err_);

    float deltaR = sqrt(pow(mcPart.finalX - kfPart.GetX(),2) + pow(mcPart.finalY - kfPart.GetY(),2) + pow(mcPart.finalZ - kfPart.GetZ(),2));
    
    fHistDeltaXAbs -> Fill(mcPart.finalX - kfPart.GetX());
    fHistDeltaYAbs -> Fill(mcPart.finalY - kfPart.GetY());
    fHistDeltaZAbs -> Fill(mcPart.finalZ - kfPart.GetZ());
    fHistDeltaRAbs -> Fill(deltaR);
    fHistDeltaPXAbs -> Fill(mcPart.finalPX - kfPart.GetPx());
    fHistDeltaPYAbs -> Fill(mcPart.finalPY - kfPart.GetPy());
    fHistDeltaPZAbs -> Fill(mcPart.finalPZ - kfPart.GetPz());
    fHistDeltaPTAbs -> Fill(mcPart.finalPT() - _pt_);
    fHistDeltaPAbs -> Fill(mcPart.finalP() - _p_);
    fHistDeltaEAbs -> Fill(mcPart.finalE() - kfPart.GetE());
    fHistDeltaMassAbs -> Fill(mcPart.mass - _mass_);

    fHistDeltaXOverTrackLength -> Fill((mcPart.finalX - kfPart.GetX())/mcPart.trackLength);
    fHistDeltaYOverTrackLength -> Fill((mcPart.finalY - kfPart.GetY())/mcPart.trackLength);
    fHistDeltaZOverTrackLength -> Fill((mcPart.finalZ - kfPart.GetZ())/mcPart.trackLength);
    fHistDeltaROverTrackLength -> Fill(deltaR/mcPart.trackLength);
    fHistDeltaPXOverTrackLength -> Fill((mcPart.finalPX - kfPart.GetPx())/mcPart.trackLength);
    fHistDeltaPYOverTrackLength -> Fill((mcPart.finalPY - kfPart.GetPy())/mcPart.trackLength);
    fHistDeltaPZOverTrackLength -> Fill((mcPart.finalPZ - kfPart.GetPz())/mcPart.trackLength);
    fHistDeltaPTOverTrackLength -> Fill((mcPart.finalPT() - _pt_)/mcPart.trackLength);
    fHistDeltaPOverTrackLength -> Fill((mcPart.finalP() - _p_)/mcPart.trackLength);
    fHistDeltaEOverTrackLength -> Fill((mcPart.finalE() - kfPart.GetE())/mcPart.trackLength);
    fHistDeltaMassOverTrackLength -> Fill((mcPart.mass - _mass_)/mcPart.trackLength);

    //cout << mcPart.trackID << " " << kfPart.GetMass() << "\n";

}

void TransportMethodCheck::Fill(const KFParticleStruct& kfPart){
    //....
}

void TransportMethodCheck::Fill(const MCParticleStruct& mcPart, const KFParticleStruct& kfPart){
    //....
}

void TransportMethodCheck::PreWriteProcess(){

}

void TransportMethodCheck::Write(){
    TDirectory* TransportMethodCheck_Dir = outputFile->mkdir("TransportMethodCheck");
        TDirectory* TransportDeltasAbs_Dir = TransportMethodCheck_Dir->mkdir("Deltas");
    
        TransportDeltasAbs_Dir->cd();
            fHistDeltaXAbs -> Write();
            fHistDeltaYAbs -> Write();
            fHistDeltaZAbs -> Write();
            fHistDeltaRAbs -> Write();
            fHistDeltaPXAbs -> Write();
            fHistDeltaPYAbs -> Write();
            fHistDeltaPZAbs -> Write();
            fHistDeltaPTAbs -> Write();
            fHistDeltaPAbs -> Write();
            fHistDeltaEAbs -> Write();
            fHistDeltaMassAbs -> Write();

        TDirectory* TransportDeltasOverTrackLength_Dir = TransportMethodCheck_Dir->mkdir("DeltasOverTrackLength");

        TransportDeltasOverTrackLength_Dir->cd();
            fHistDeltaXOverTrackLength -> Write();
            fHistDeltaYOverTrackLength -> Write();
            fHistDeltaZOverTrackLength -> Write();
            fHistDeltaROverTrackLength -> Write();
            fHistDeltaPXOverTrackLength -> Write();
            fHistDeltaPYOverTrackLength -> Write();
            fHistDeltaPZOverTrackLength -> Write();
            fHistDeltaPTOverTrackLength -> Write();
            fHistDeltaPOverTrackLength -> Write();
            fHistDeltaEOverTrackLength -> Write();
            fHistDeltaMassOverTrackLength -> Write();
}