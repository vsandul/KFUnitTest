#pragma once

#include "OutputObjInterface.h"
#include "../ConfigConstants.h"

#include "MakeGraphsFromTH2.h"

#include <array>

class ResidPtDepHistos: public OutputObjInterface{
public:
    ResidPtDepHistos(TFile& outputFile):OutputObjInterface(outputFile){};
    ~ResidPtDepHistos(){};

    void Create() override ;
    void Fill() override {};
    void Fill(const MCParticleStruct& mcPart) override ;
    void Fill(const KFParticleStruct& kfPart) override ;
    void Fill(const MCParticleStruct& mcPart, const KFParticleStruct& kfPart) override ;
    void PreWriteProcess() override ;
    void Write() override ;
    
private:
    TH2F *fHistPtXResidMother;
    TH2F *fHistPtYResidMother;
    TH2F *fHistPtZResidMother;
    TH2F *fHistPtPxResidMother;
    TH2F *fHistPtPyResidMother;
    TH2F *fHistPtPzResidMother;
    TH2F *fHistPtPtResidMother;
    TH2F *fHistPtMassResidMother;
    TH2F *fHistPtEResidMother;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtXResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtYResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtZResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPxResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPyResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPzResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPtResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtMassResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtEResidDaughter;
    //
    TH1D *fHistXResidMother;
    TH1D *fHistYResidMother;
    TH1D *fHistZResidMother;
    TH1D *fHistPxResidMother;
    TH1D *fHistPyResidMother;
    TH1D *fHistPzResidMother;
    TH1D *fHistPtResidMother;
    TH1D *fHistMassResidMother;
    TH1D *fHistEResidMother;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistXResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistYResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistZResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPxResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPyResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPzResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPtResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistMassResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistEResidDaughter;
    //
    TGraphErrors *fGraphPtXMeanResidMother;
    TGraphErrors *fGraphPtYMeanResidMother;
    TGraphErrors *fGraphPtZMeanResidMother;
    TGraphErrors *fGraphPtPxMeanResidMother;
    TGraphErrors *fGraphPtPyMeanResidMother;
    TGraphErrors *fGraphPtPzMeanResidMother;
    TGraphErrors *fGraphPtPtMeanResidMother;
    TGraphErrors *fGraphPtMassMeanResidMother;
    TGraphErrors *fGraphPtEMeanResidMother;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtXMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtYMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtZMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPxMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPyMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPzMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPtMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtMassMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtEMeanResidDaughter;
    //
    TGraphErrors *fGraphPtXResolMother;
    TGraphErrors *fGraphPtYResolMother;
    TGraphErrors *fGraphPtZResolMother;
    TGraphErrors *fGraphPtPxResolMother;
    TGraphErrors *fGraphPtPyResolMother;
    TGraphErrors *fGraphPtPzResolMother;
    TGraphErrors *fGraphPtPtResolMother;
    TGraphErrors *fGraphPtMassResolMother;
    TGraphErrors *fGraphPtEResolMother;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtXResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtYResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtZResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPxResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPyResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPzResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPtResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtMassResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtEResolDaughter;
        
};

////////////////////////////////////////////////
////---------- method implementations ----------
////////////////////////////////////////////////
void ResidPtDepHistos::Create(){
    fHistPtXResidMother = new TH2F("fHistPtXResidMother", "Pt-X Resid histo; p_{T}, GeV; X residual, cm",50,0,10, 100,-1e-1,1e-1);
    fHistPtYResidMother = new TH2F("fHistPtYResidMother", "Pt-Y Resid histo; p_{T}, GeV; Y residual, cm",50,0,10, 100,-1e-1,1e-1);
    fHistPtZResidMother = new TH2F("fHistPtZResidMother", "Pt-Z Resid histo; p_{T}, GeV; Z residual, cm",50,0,10, 100,-1e-1,1e-1);
    fHistPtPxResidMother = new TH2F("fHistPtPxResidMother", "Pt-Px Resid histo; p_{T}, GeV; Px residual, GeV",50,0,10, 50,-0.1,0.1);
    fHistPtPyResidMother = new TH2F("fHistPtPyResidMother", "Pt-Py Resid histo; p_{T}, GeV; Py residual, GeV",50,0,10, 50,-0.1,0.1);
    fHistPtPzResidMother = new TH2F("fHistPtPzResidMother", "Pt-Pz Resid histo; p_{T}, GeV; Pz residual, GeV",50,0,10, 50,-0.1,0.1);
    fHistPtPtResidMother = new TH2F("fHistPtPtResidMother", "Pt-Pt Resid histo; p_{T}, GeV; Pt residual, GeV",50,0,10, 50,-0.1,0.1);
    fHistPtMassResidMother = new TH2F("fHistPtMassResidMother", "Pt-Mass Resid histo; p_{T}, GeV; Mass residual, GeV",50,0,10, 50,-0.1,0.1);
    fHistPtEResidMother = new TH2F("fHistPtEResidMother", "Pt-E Resid histo; p_{T}, GeV; E residual, GeV",50,0,10, 50,-0.1,0.1);
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistPtXResidDaughter[i] = new TH2F(Form("fHistPtXResidDaughter%i",i), "Pt-X Resid histo; p_{T}, GeV; X residual, cm",50,0,10, 100,-1e-1,1e-1);
        fHistPtYResidDaughter[i] = new TH2F(Form("fHistPtYResidDaughter%i",i), "Pt-Y Resid histo; p_{T}, GeV; Y residual, cm",50,0,10, 100,-1e-1,1e-1);
        fHistPtZResidDaughter[i] = new TH2F(Form("fHistPtZResidDaughter%i",i), "Pt-Z Resid histo; p_{T}, GeV; Z residual, cm",50,0,10, 100,-1e-1,1e-1);
        fHistPtPxResidDaughter[i] = new TH2F(Form("fHistPtPxResidDaughter%i",i), "Pt-Px Resid histo; p_{T}, GeV; Px residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtPyResidDaughter[i] = new TH2F(Form("fHistPtPyResidDaughter%i",i), "Pt-Py Resid histo; p_{T}, GeV; Py residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtPzResidDaughter[i] = new TH2F(Form("fHistPtPzResidDaughter%i",i), "Pt-Pz Resid histo; p_{T}, GeV; Pz residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtPtResidDaughter[i] = new TH2F(Form("fHistPtPtResidDaughter%i",i), "Pt-Pt Resid histo; p_{T}, GeV; Pt residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtMassResidDaughter[i] = new TH2F(Form("fHistPtMassResidDaughter%i",i), "Pt-Mass Resid histo; p_{T}, GeV; Mass residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtEResidDaughter[i] = new TH2F("fHistPtEResidMother", "Pt-E Resid histo; p_{T}, GeV; E residual, GeV",50,0,10, 50,-0.1,0.1);
    }
    //////////////////////////////////////////
    //////////////////////////////////////////
    fHistXResidMother = new TH1D("fHistXResidMother", "X Resid histo; X Resid, cm; counts",100,-1e-1,1e-1);
    fHistYResidMother = new TH1D("fHistYResidMother", "Y Resid histo; Y Resid, cm; counts", 100,-1e-1,1e-1);
    fHistZResidMother = new TH1D("fHistZResidMother", "Z Resid histo; Z Resid, cm; counts", 100,-1e-1,1e-1);
    fHistPxResidMother = new TH1D("fHistPxResidMother", "Px Resid histo; Px Resid, GeV; counts", 50,-0.15,0.15);
    fHistPyResidMother = new TH1D("fHistPyResidMother", "Py Resid histo; Py Resid, GeV; counts", 50,-0.15,0.15);
    fHistPzResidMother = new TH1D("fHistPzResidMother", "Pz Resid histo; Pz Resid, GeV; counts", 50,-0.15,0.15);
    fHistPtResidMother = new TH1D("fHistPtResidMother", "Pt - Resid histo; Pt Resid, GeV; counts", 50,-0.15,0.15);
    fHistMassResidMother = new TH1D("fHistMassResidMother", "Mass Resid histo; Mass Resid, GeV; counts", 50,-0.15,0.15);
    fHistEResidMother = new TH1D("fHistEResidMother", "E Resid histo; E Resid, GeV; counts", 50,-0.15,0.15);
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistXResidDaughter[i] = new TH1D(Form("fHistXResidDaughter%i",i), "X Resid histo; X Resid, cm; counts", 100,-1e-1,1e-1);
        fHistYResidDaughter[i] = new TH1D(Form("fHistYResidDaughter%i",i), "Y Resid histo; Y Resid, cm; counts",100,-1e-1,1e-1);
        fHistZResidDaughter[i] = new TH1D(Form("fHistZResidDaughter%i",i), "Z Resid histo; Z Resid, cm; counts", 100,-1e-1,1e-1);
        fHistPxResidDaughter[i] = new TH1D(Form("fHistPxResidDaughter%i",i), "Px Resid histo; Px Resid, GeV; counts",50,-0.15,0.15);
        fHistPyResidDaughter[i] = new TH1D(Form("fHistPyResidDaughter%i",i), "Py Resid histo; Py Resid, GeV; counts", 50,-0.15,0.15);
        fHistPzResidDaughter[i] = new TH1D(Form("fHistPzResidDaughter%i",i), "Pz Resid histo; Pz Resid, GeV; counts",50,-0.15,0.15);
        fHistPtResidDaughter[i] = new TH1D(Form("fHistPtResidDaughter%i",i), "Pt Resid histo;  Resid, GeV; counts",50,-0.15,0.15);
        fHistMassResidDaughter[i] = new TH1D(Form("fHistMassResidDaughter%i",i), "Mass Resid histo; Mass Resid, GeV; counts",50,-0.15,0.15);
        fHistEResidDaughter[i] = new TH1D(Form("fHistEResidDaughter%i",i), "E Resid histo; E Resid, GeV; counts",50,-0.15,0.15);
    }
    //////////////////////////////////////////
    //////////////////////////////////////////
    fGraphPtXMeanResidMother = new TGraphErrors();
    fGraphPtYMeanResidMother = new TGraphErrors();
    fGraphPtZMeanResidMother = new TGraphErrors();
    fGraphPtPxMeanResidMother = new TGraphErrors();
    fGraphPtPyMeanResidMother = new TGraphErrors();
    fGraphPtPzMeanResidMother = new TGraphErrors();
    fGraphPtPtMeanResidMother = new TGraphErrors();
    fGraphPtMassMeanResidMother = new TGraphErrors();
    fGraphPtEMeanResidMother = new TGraphErrors();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fGraphPtXMeanResidDaughter[i] = new TGraphErrors();
        fGraphPtYMeanResidDaughter[i] = new TGraphErrors();
        fGraphPtZMeanResidDaughter[i] = new TGraphErrors();
        fGraphPtPxMeanResidDaughter[i] = new TGraphErrors();
        fGraphPtPyMeanResidDaughter[i] = new TGraphErrors();
        fGraphPtPzMeanResidDaughter[i] = new TGraphErrors();
        fGraphPtPtMeanResidDaughter[i] = new TGraphErrors();
        fGraphPtMassMeanResidDaughter[i] = new TGraphErrors();
        fGraphPtEMeanResidDaughter[i] = new TGraphErrors();
    }
    //////////////////////////////////////////
    //////////////////////////////////////////
    fGraphPtXResolMother = new TGraphErrors();
    fGraphPtYResolMother = new TGraphErrors();
    fGraphPtZResolMother = new TGraphErrors();
    fGraphPtPxResolMother = new TGraphErrors();
    fGraphPtPyResolMother = new TGraphErrors();
    fGraphPtPzResolMother = new TGraphErrors();
    fGraphPtPtResolMother = new TGraphErrors();
    fGraphPtMassResolMother = new TGraphErrors();
    fGraphPtEResolMother = new TGraphErrors();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fGraphPtXResolDaughter[i] = new TGraphErrors();
        fGraphPtYResolDaughter[i] = new TGraphErrors();
        fGraphPtZResolDaughter[i] = new TGraphErrors();
        fGraphPtPxResolDaughter[i] = new TGraphErrors();
        fGraphPtPyResolDaughter[i] = new TGraphErrors();
        fGraphPtPzResolDaughter[i] = new TGraphErrors();
        fGraphPtPtResolDaughter[i] = new TGraphErrors();
        fGraphPtMassResolDaughter[i] = new TGraphErrors();
        fGraphPtEResolDaughter[i] = new TGraphErrors();
    }
}

void ResidPtDepHistos::Fill(const MCParticleStruct& mcPart){
    //....
}
void ResidPtDepHistos::Fill(const KFParticleStruct& kfPart){
    //....
}

void ResidPtDepHistos::Fill(const MCParticleStruct& mcPart, const KFParticleStruct& kfPart){
    float x_resid_ = mcPart.x - kfPart.x;
    float y_resid_ = mcPart.y - kfPart.y;
    float z_resid_ = mcPart.z - kfPart.z;
    float px_resid_ = mcPart.pX - kfPart.pX;
    float py_resid_ = mcPart.pY - kfPart.pY;
    float pz_resid_ = mcPart.pZ - kfPart.pZ;
    float pt_resid_ = mcPart.pT() - kfPart.pT;
    float mass_resid_ = mcPart.mass - kfPart.mass;
    float e_resid_ = mcPart.e() - kfPart.e;

    if (kfPart.isMother){
        //setup mother particle from KFAR data and fill some histos    
        fHistPtXResidMother -> Fill(mcPart.pT(),x_resid_);
        fHistPtYResidMother -> Fill(mcPart.pT(),y_resid_);
        fHistPtZResidMother -> Fill(mcPart.pT(),z_resid_);
        fHistPtPxResidMother -> Fill(mcPart.pT(),px_resid_);
        fHistPtPyResidMother -> Fill(mcPart.pT(),py_resid_);
        fHistPtPzResidMother -> Fill(mcPart.pT(),pz_resid_);
        fHistPtPtResidMother -> Fill(mcPart.pT(),pt_resid_);
        fHistPtMassResidMother -> Fill(mcPart.pT(),mass_resid_);
        fHistPtEResidMother -> Fill(mcPart.pT(),e_resid_);
    }
    if (kfPart.isDaughter){
        int daughterNum = kfPart.id-1;

        fHistPtXResidDaughter[daughterNum] -> Fill(mcPart.pT(),x_resid_);
        fHistPtYResidDaughter[daughterNum] -> Fill(mcPart.pT(),y_resid_);
        fHistPtZResidDaughter[daughterNum] -> Fill(mcPart.pT(),z_resid_);
        fHistPtPxResidDaughter[daughterNum] -> Fill(mcPart.pT(),px_resid_);
        fHistPtPyResidDaughter[daughterNum] -> Fill(mcPart.pT(),py_resid_);
        fHistPtPzResidDaughter[daughterNum] -> Fill(mcPart.pT(),pz_resid_);
        fHistPtPtResidDaughter[daughterNum] -> Fill(mcPart.pT(),pt_resid_);
        fHistPtMassResidDaughter[daughterNum] -> Fill(mcPart.pT(),mass_resid_);
        fHistPtEResidDaughter[daughterNum] -> Fill(mcPart.pT(),e_resid_);
    }
}

void ResidPtDepHistos::PreWriteProcess(){
    //...
    fHistXResidMother = fHistPtXResidMother -> ProjectionY();
    fHistYResidMother = fHistPtYResidMother -> ProjectionY();
    fHistZResidMother = fHistPtZResidMother -> ProjectionY();
    fHistPxResidMother = fHistPtPxResidMother -> ProjectionY();
    fHistPyResidMother = fHistPtPyResidMother -> ProjectionY();
    fHistPzResidMother = fHistPtPzResidMother -> ProjectionY();
    fHistPtResidMother = fHistPtPtResidMother -> ProjectionY();
    fHistMassResidMother = fHistPtMassResidMother -> ProjectionY();
    fHistEResidMother = fHistPtEResidMother -> ProjectionY();
    for(int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistXResidDaughter[i] = fHistPtXResidDaughter[i] -> ProjectionY();
        fHistYResidDaughter[i] = fHistPtYResidDaughter[i] -> ProjectionY();
        fHistZResidDaughter[i] = fHistPtZResidDaughter[i] -> ProjectionY();
        fHistPxResidDaughter[i] = fHistPtPxResidDaughter[i] -> ProjectionY();
        fHistPyResidDaughter[i] = fHistPtPyResidDaughter[i] -> ProjectionY();
        fHistPzResidDaughter[i] = fHistPtPzResidDaughter[i] -> ProjectionY();
        fHistPtResidDaughter[i] = fHistPtPtResidDaughter[i] -> ProjectionY();
        fHistMassResidDaughter[i] = fHistPtMassResidDaughter[i] -> ProjectionY();
        fHistEResidDaughter[i] = fHistPtEResidDaughter[i] -> ProjectionY();
    }
    ///
    fGraphPtXMeanResidMother = MakeMeanGraphFromTH2(fHistPtXResidMother);
    fGraphPtXMeanResidMother -> SetNameTitle("X Mean Resid","XMeanResid; p_{T}, GeV; X, cm");
    fGraphPtYMeanResidMother = MakeMeanGraphFromTH2(fHistPtYResidMother);
    fGraphPtYMeanResidMother -> SetNameTitle("Y Mean Resid","Y Mean Resid; p_{T}, GeV; Y, cm");
    fGraphPtZMeanResidMother = MakeMeanGraphFromTH2(fHistPtZResidMother);
    fGraphPtZMeanResidMother -> SetNameTitle("Z Mean Resid","Z Mean Resid; p_{T}, GeV; Z, cm");
    fGraphPtPxMeanResidMother = MakeMeanGraphFromTH2(fHistPtPxResidMother);
    fGraphPtPxMeanResidMother -> SetNameTitle("Px Mean Resid","Px Mean Resid; p_{T}, GeV; Px, GeV");
    fGraphPtPyMeanResidMother = MakeMeanGraphFromTH2(fHistPtPyResidMother);
    fGraphPtPyMeanResidMother -> SetNameTitle("Py Mean Resid","Py Mean Resid; p_{T}, GeV; Py, GeV");
    fGraphPtPzMeanResidMother = MakeMeanGraphFromTH2(fHistPtPzResidMother);
    fGraphPtPzMeanResidMother -> SetNameTitle("Pz Mean Resid","Pz Mean Resid; p_{T}, GeV; Pz, GeV");
    fGraphPtPtMeanResidMother = MakeMeanGraphFromTH2(fHistPtPtResidMother);
    fGraphPtPtMeanResidMother -> SetNameTitle("Pt Mean Resid","Pt Mean Resid; p_{T}, GeV; Pt, GeV");
    fGraphPtMassMeanResidMother = MakeMeanGraphFromTH2(fHistPtMassResidMother);
    fGraphPtMassMeanResidMother -> SetNameTitle("Mass Mean Resid","Mass Mean Resid; p_{T}, GeV; Mass, GeV");
    fGraphPtEMeanResidMother = MakeMeanGraphFromTH2(fHistPtEResidMother);
    fGraphPtEMeanResidMother -> SetNameTitle("E Mean Resid","E Mean Resid; p_{T}, GeV; E, GeV");
    for(int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fGraphPtXMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtXResidDaughter[i]);
        fGraphPtXMeanResidDaughter[i] -> SetNameTitle("X Mean Resid","XMeanResid; p_{T}, GeV; X, cm");
        fGraphPtYMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtYResidDaughter[i]);
        fGraphPtYMeanResidDaughter[i] -> SetNameTitle("Y Mean Resid","YMeanResid; p_{T}, GeV; Y, cm");
        fGraphPtZMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtZResidDaughter[i]);
        fGraphPtZMeanResidDaughter[i] -> SetNameTitle("Z Mean Resid","ZMeanResid; p_{T}, GeV; Z, cm");
        fGraphPtPxMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtPxResidDaughter[i]);
        fGraphPtPxMeanResidDaughter[i] -> SetNameTitle("Px Mean Resid","Px Mean Resid; p_{T}, GeV; Px, GeV");
        fGraphPtPyMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtPyResidDaughter[i]);
        fGraphPtPyMeanResidDaughter[i] -> SetNameTitle("Py Mean Resid","Py Mean Resid; p_{T}, GeV; Py, GeV");
        fGraphPtPzMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtPzResidDaughter[i]);
        fGraphPtPzMeanResidDaughter[i] -> SetNameTitle("Pz Mean Resid","Pz Mean Resid; p_{T}, GeV; Pz, GeV");
        fGraphPtPtMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtPtResidDaughter[i]);
        fGraphPtPtMeanResidDaughter[i] -> SetNameTitle("Pt Mean Resid","Pt Mean Resid; p_{T}, GeV; Pt, GeV");
        fGraphPtMassMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtMassResidDaughter[i]);
        fGraphPtMassMeanResidDaughter[i] -> SetNameTitle("Mass Mean Resid","Mass Mean Resid; p_{T}, GeV; Mass, GeV");
        fGraphPtEMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtEResidDaughter[i]);
        fGraphPtEMeanResidDaughter[i] -> SetNameTitle("E Mean Resid","E Mean Resid; p_{T}, GeV; E, GeV");
    }
    /////
    fGraphPtXResolMother = MakeSigmaGraphFromTH2(fHistPtXResidMother);
    fGraphPtXResolMother -> SetNameTitle("X Resol","XResol; p_{T}, GeV; X Resol, cm");
    fGraphPtYResolMother = MakeSigmaGraphFromTH2(fHistPtYResidMother);
    fGraphPtYResolMother -> SetNameTitle("Y Resol","YResol; p_{T}, GeV; Y Resol, cm");
    fGraphPtZResolMother = MakeSigmaGraphFromTH2(fHistPtZResidMother);
    fGraphPtZResolMother -> SetNameTitle("Z Resol","ZResol; p_{T}, GeV; Z Resol, cm");
    fGraphPtPxResolMother = MakeSigmaGraphFromTH2(fHistPtPxResidMother);
    fGraphPtPxResolMother -> SetNameTitle("Px Resol","PxResol; p_{T}, GeV; Px Resol, GeV");
    fGraphPtPyResolMother = MakeSigmaGraphFromTH2(fHistPtPyResidMother);
    fGraphPtPyResolMother -> SetNameTitle("Py Resol","PyResol; p_{T}, GeV; Py Resol, GeV");
    fGraphPtPzResolMother = MakeSigmaGraphFromTH2(fHistPtPzResidMother);
    fGraphPtPzResolMother -> SetNameTitle("Pz Resol","PzResol; p_{T}, GeV; Pz Resol, GeV");
    fGraphPtPtResolMother = MakeSigmaGraphFromTH2(fHistPtPtResidMother);
    fGraphPtPtResolMother -> SetNameTitle("Pt Resol","PtResol; p_{T}, GeV; Pt Resol, GeV");
    fGraphPtMassResolMother = MakeSigmaGraphFromTH2(fHistPtMassResidMother);
    fGraphPtMassResolMother -> SetNameTitle("Mass Resol","MassResol; p_{T}, GeV; Mass Resol, GeV");
    fGraphPtEResolMother = MakeSigmaGraphFromTH2(fHistPtEResidMother);
    fGraphPtEResolMother -> SetNameTitle("E Resol","EResol; p_{T}, GeV; E Resol, GeV");
    for(int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fGraphPtXResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtXResidDaughter[i]);
        fGraphPtXResolDaughter[i] -> SetNameTitle("X Resol","XResol; p_{T}, GeV; X Resol, cm");
        fGraphPtYResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtYResidDaughter[i]);
        fGraphPtYResolDaughter[i] -> SetNameTitle("Y Resol","YResol; p_{T}, GeV; Y Resol, cm");
        fGraphPtZResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtZResidDaughter[i]);
        fGraphPtZResolDaughter[i] -> SetNameTitle("Z Resol","ZResol; p_{T}, GeV; Z Resol, cm");
        fGraphPtPxResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtPxResidDaughter[i]);
        fGraphPtPxResolDaughter[i] -> SetNameTitle("Px Resol","PxResol; p_{T}, GeV; Px Resol, GeV");
        fGraphPtPyResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtPyResidDaughter[i]);
        fGraphPtPyResolDaughter[i] -> SetNameTitle("Py Resol","PyResol; p_{T}, GeV; Py Resol, GeV");
        fGraphPtPzResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtPzResidDaughter[i]);
        fGraphPtPzResolDaughter[i] -> SetNameTitle("Pz Resol","PzResol; p_{T}, GeV; Pz Resol, GeV");
        fGraphPtPtResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtPtResidDaughter[i]);
        fGraphPtPtResolDaughter[i] -> SetNameTitle("Pt Resol","PtResol; p_{T}, GeV; Pt Resol, GeV");
        fGraphPtMassResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtMassResidDaughter[i]);
        fGraphPtMassResolDaughter[i] -> SetNameTitle("Mass Resol","MassResol; p_{T}, GeV; Mass Resol, GeV");
        fGraphPtEResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtEResidDaughter[i]);
        fGraphPtEResolDaughter[i] -> SetNameTitle("E Resol","EResol; p_{T}, GeV; E Resol, GeV");
    }


}

void ResidPtDepHistos::Write(){
    TDirectory* ResidPtDep_Dir = outputFile->mkdir("ResidPtDependencies");
        TDirectory* MotherResidPtDep_Dir = ResidPtDep_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersResidPtDep_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersResidPtDep_Dir[i] = ResidPtDep_Dir->mkdir(Form("Daughter%i",i+1));

        MotherResidPtDep_Dir -> cd();
            fHistPtXResidMother -> Write();
            fHistPtYResidMother -> Write();
            fHistPtZResidMother -> Write();
            fHistPtPxResidMother -> Write();
            fHistPtPyResidMother -> Write();
            fHistPtPzResidMother -> Write();
            fHistPtPtResidMother -> Write();
            fHistPtMassResidMother -> Write();
            fHistPtEResidMother -> Write();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        DaughtersResidPtDep_Dir[i] -> cd();
            fHistPtXResidDaughter[i] -> Write();
            fHistPtYResidDaughter[i] -> Write();
            fHistPtZResidDaughter[i] -> Write();
            fHistPtPxResidDaughter[i] -> Write();
            fHistPtPyResidDaughter[i] -> Write();
            fHistPtPzResidDaughter[i] -> Write();
            fHistPtPtResidDaughter[i] -> Write();
            fHistPtMassResidDaughter[i] -> Write();
            fHistPtEResidDaughter[i] -> Write();
    }
    /////////////////////////////////
    /////////////////////////////////
    TDirectory* ResidHistos_Dir = outputFile->mkdir("ResidHistos");
        TDirectory* MotherResidHistos_Dir = ResidHistos_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersResidHistos_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersResidHistos_Dir[i] = ResidHistos_Dir->mkdir(Form("Daughter%i",i+1));

        MotherResidHistos_Dir -> cd();
            fHistXResidMother -> Write();
            fHistYResidMother -> Write();
            fHistZResidMother -> Write();
            fHistPxResidMother -> Write();
            fHistPyResidMother -> Write();
            fHistPzResidMother -> Write();
            fHistPtResidMother -> Write();
            fHistMassResidMother -> Write();
            fHistEResidMother -> Write();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        DaughtersResidHistos_Dir[i] -> cd();
            fHistXResidDaughter[i] -> Write();
            fHistYResidDaughter[i] -> Write();
            fHistZResidDaughter[i] -> Write();
            fHistPxResidDaughter[i] -> Write();
            fHistPyResidDaughter[i] -> Write();
            fHistPzResidDaughter[i] -> Write();
            fHistPtResidDaughter[i] -> Write();
            fHistMassResidDaughter[i] -> Write();
            fHistEResidDaughter[i] -> Write();
    }
    /////////////////////////////////
    /////////////////////////////////
    TDirectory* MeanResidPtDepPlots_Dir = outputFile->mkdir("MeanResidPtDepPlots");
        TDirectory* MotherMeanResidPtDepPlots_Dir = MeanResidPtDepPlots_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersMeanResidPtDepPlots_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersMeanResidPtDepPlots_Dir[i] = MeanResidPtDepPlots_Dir->mkdir(Form("Daughter%i",i+1));

        MotherMeanResidPtDepPlots_Dir -> cd();
            fGraphPtXMeanResidMother -> Write();
            fGraphPtYMeanResidMother -> Write();
            fGraphPtZMeanResidMother -> Write();
            fGraphPtPxMeanResidMother -> Write();
            fGraphPtPyMeanResidMother -> Write();
            fGraphPtPzMeanResidMother -> Write();
            fGraphPtPtMeanResidMother -> Write();
            fGraphPtMassMeanResidMother -> Write();
            fGraphPtEMeanResidMother -> Write();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        DaughtersMeanResidPtDepPlots_Dir[i] -> cd();
            fGraphPtXMeanResidDaughter[i] -> Write();
            fGraphPtYMeanResidDaughter[i] -> Write();
            fGraphPtZMeanResidDaughter[i] -> Write();
            fGraphPtPxMeanResidDaughter[i] -> Write();
            fGraphPtPyMeanResidDaughter[i] -> Write();
            fGraphPtPzMeanResidDaughter[i] -> Write();
            fGraphPtPtMeanResidDaughter[i] -> Write();
            fGraphPtMassMeanResidDaughter[i] -> Write();
            fGraphPtEMeanResidDaughter[i] -> Write();
    }
    /////////////////////////////////
    /////////////////////////////////
    TDirectory* ResolPtDepPlots_Dir = outputFile->mkdir("ResolPtDepPlots");
        TDirectory* MotherResolPtDepPlots_Dir = ResolPtDepPlots_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersResolPtDepPlots_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersResolPtDepPlots_Dir[i] = ResolPtDepPlots_Dir->mkdir(Form("Daughter%i",i+1));

        MotherResolPtDepPlots_Dir -> cd();
            fGraphPtXResolMother -> Write();
            fGraphPtYResolMother -> Write();
            fGraphPtZResolMother -> Write();
            fGraphPtPxResolMother -> Write();
            fGraphPtPyResolMother -> Write();
            fGraphPtPzResolMother -> Write();
            fGraphPtPtResolMother -> Write();
            fGraphPtMassResolMother -> Write();
            fGraphPtEResolMother -> Write();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        DaughtersResolPtDepPlots_Dir[i] -> cd();
            fGraphPtXResolDaughter[i] -> Write();
            fGraphPtYResolDaughter[i] -> Write();
            fGraphPtZResolDaughter[i] -> Write();
            fGraphPtPxResolDaughter[i] -> Write();
            fGraphPtPyResolDaughter[i] -> Write();
            fGraphPtPzResolDaughter[i] -> Write();
            fGraphPtPtResolDaughter[i] -> Write();
            fGraphPtMassResolDaughter[i] -> Write();
            fGraphPtEResolDaughter[i] -> Write();
    }
}



