#pragma once

#include "OutputObjInterface.h"
#include "../ConfigConstants.h"

#include "MakeGraphsFromTH2.h"

#include <array>

class PullPtDepHistos: public OutputObjInterface{
public:
    PullPtDepHistos(TFile& outputFile):OutputObjInterface(outputFile){};
    ~PullPtDepHistos(){};

    void Create() override ;
    void Fill() override {};
    void Fill(const MCParticleStruct& mcPart) override ;
    void Fill(const KFParticleStruct& kfPart) override ;
    void Fill(const MCParticleStruct& mcPart, const KFParticleStruct& kfPart) override ;
    void PreWriteProcess() override ;
    void Write() override ;
    
private:
    TH2F *fHistPtXPullMother;
    TH2F *fHistPtYPullMother;
    TH2F *fHistPtZPullMother;
    TH2F *fHistPtPxPullMother;
    TH2F *fHistPtPyPullMother;
    TH2F *fHistPtPzPullMother;
    TH2F *fHistPtPtPullMother;
    TH2F *fHistPtMassPullMother;
    TH2F *fHistPtEPullMother;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtXPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtYPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtZPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPxPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPyPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPzPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPtPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtMassPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtEPullDaughter;
    //
    TH1D *fHistXPullMother;
    TH1D *fHistYPullMother;
    TH1D *fHistZPullMother;
    TH1D *fHistPxPullMother;
    TH1D *fHistPyPullMother;
    TH1D *fHistPzPullMother;
    TH1D *fHistPtPullMother;
    TH1D *fHistMassPullMother;
    TH1D *fHistEPullMother;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistXPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistYPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistZPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPxPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPyPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPzPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPtPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistMassPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistEPullDaughter;
    //
    TGraphErrors *fGraphPtXMeanPullMother;
    TGraphErrors *fGraphPtYMeanPullMother;
    TGraphErrors *fGraphPtZMeanPullMother;
    TGraphErrors *fGraphPtPxMeanPullMother;
    TGraphErrors *fGraphPtPyMeanPullMother;
    TGraphErrors *fGraphPtPzMeanPullMother;
    TGraphErrors *fGraphPtPtMeanPullMother;
    TGraphErrors *fGraphPtMassMeanPullMother;
    TGraphErrors *fGraphPtEMeanPullMother;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtXMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtYMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtZMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPxMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPyMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPzMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPtMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtMassMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtEMeanPullDaughter;
    //
    TGraphErrors *fGraphPtXPullWidthMother;
    TGraphErrors *fGraphPtYPullWidthMother;
    TGraphErrors *fGraphPtZPullWidthMother;
    TGraphErrors *fGraphPtPxPullWidthMother;
    TGraphErrors *fGraphPtPyPullWidthMother;
    TGraphErrors *fGraphPtPzPullWidthMother;
    TGraphErrors *fGraphPtPtPullWidthMother;
    TGraphErrors *fGraphPtMassPullWidthMother;
    TGraphErrors *fGraphPtEPullWidthMother;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtXPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtYPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtZPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPxPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPyPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPzPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPtPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtMassPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtEPullWidthDaughter;
};

////////////////////////////////////////////////
////---------- method implementations ----------
////////////////////////////////////////////////
void PullPtDepHistos::Create(){
    fHistPtXPullMother = new TH2F("fHistPtXPullMother", "Pt-X Pull histo; p_{T}, GeV; X Pull",50,0,10, 100,-10,10);
    fHistPtYPullMother = new TH2F("fHistPtYPullMother", "Pt-Y Pull histo; p_{T}, GeV; Y Pull",50,0,10, 100,-10,10);
    fHistPtZPullMother = new TH2F("fHistPtZPullMother", "Pt-Z Pull histo; p_{T}, GeV; Z Pull",50,0,10, 100,-10,10);
    fHistPtPxPullMother = new TH2F("fHistPtPxPullMother", "Pt-Px Pull histo; p_{T}, GeV; Px Pull",50,0,10, 50,-15,15);
    fHistPtPyPullMother = new TH2F("fHistPtPyPullMother", "Pt-Py Pull histo; p_{T}, GeV; Py Pull",50,0,10, 50,-15,15);
    fHistPtPzPullMother = new TH2F("fHistPtPzPullMother", "Pt-Pz Pull histo; p_{T}, GeV; Pz Pull",50,0,10, 50,-15,15);
    fHistPtPtPullMother = new TH2F("fHistPtPtPullMother", "Pt-Pt Pull histo; p_{T}, GeV; Pt Pull",50,0,10, 50,-15,15);
    fHistPtMassPullMother = new TH2F("fHistPtMassPullMother", "Pt-Mass Pull histo; p_{T}, GeV; Mass Pull",50,0,10, 50,-5,5);
    fHistPtEPullMother = new TH2F("fHistPtEPullMother", "Pt-E Pull histo; p_{T}, GeV; E Pull",50,0,10, 50,-15,15);
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistPtXPullDaughter[i] = new TH2F(Form("fHistPtXPullDaughter%i",i), "Pt-X Pull histo; p_{T}, GeV; X Pull",50,0,10, 100,-10,10);
        fHistPtYPullDaughter[i] = new TH2F(Form("fHistPtYPullDaughter%i",i), "Pt-Y Pull histo; p_{T}, GeV; Y Pull",50,0,10, 100,-10,10);
        fHistPtZPullDaughter[i] = new TH2F(Form("fHistPtZPullDaughter%i",i), "Pt-Z Pull histo; p_{T}, GeV; Z Pull",50,0,10, 100,-10,10);
        fHistPtPxPullDaughter[i] = new TH2F(Form("fHistPtPxPullDaughter%i",i), "Pt-Px Pull histo; p_{T}, GeV; Px Pull",50,0,10, 50,-15,15);
        fHistPtPyPullDaughter[i] = new TH2F(Form("fHistPtPyPullDaughter%i",i), "Pt-Py Pull histo; p_{T}, GeV; Py Pull",50,0,10, 50,-15,15);
        fHistPtPzPullDaughter[i] = new TH2F(Form("fHistPtPzPullDaughter%i",i), "Pt-Pz Pull histo; p_{T}, GeV; Pz Pull",50,0,10, 50,-15,15);
        fHistPtPtPullDaughter[i] = new TH2F(Form("fHistPtPtPullDaughter%i",i), "Pt-Pt Pull histo; p_{T}, GeV; Pt Pull",50,0,10, 50,-15,15);
        fHistPtMassPullDaughter[i] = new TH2F(Form("fHistPtMassPullDaughter%i",i), "Pt-Mass Pull histo; p_{T}, GeV; Mass Pull",50,0,10, 50,-0.4,0.4);
        fHistPtEPullDaughter[i] = new TH2F("fHistPtEPullMother", "Pt-E Pull histo; p_{T}, GeV; E Pull",50,0,10, 50,-15,15);
    }
    //
    fHistXPullMother = new TH1D("fHistXPullMother", "X Pull histo; X Pull; counts",100,-1e-1,1e-1);
    fHistYPullMother = new TH1D("fHistYPullMother", "Y Pull histo; Y Pull; counts",100,-1e-1,1e-1);
    fHistZPullMother = new TH1D("fHistZPullMother", "Z Pull histo; Z Pull; counts",100,-1e-1,1e-1);
    fHistPxPullMother = new TH1D("fHistPxPullMother", "Px Pull histo; Px Pull; counts",50,-0.15,0.15);
    fHistPyPullMother = new TH1D("fHistPyPullMother", "Py Pull histo; Py Pull; counts",50,-0.15,0.15);
    fHistPzPullMother = new TH1D("fHistPzPullMother", "Pz Pull histo; Pz Pull; counts",50,-0.15,0.15);
    fHistPtPullMother = new TH1D("fHistPtPullMother", "Pt - Pull histo; Pt Pull; counts",50,-0.15,0.15);
    fHistMassPullMother = new TH1D("fHistMassPullMother", "Mass Pull histo; Mass Pull; counts",50,-0.15,0.15);
    fHistEPullMother = new TH1D("fHistEPullMother", "E Pull histo; E Pull; counts",50,-0.15,0.15);
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistXPullDaughter[i] = new TH1D(Form("fHistXPullDaughter%i",i), "X Pull histo; X Pull; counts",100,-1e-1,1e-1);
        fHistYPullDaughter[i] = new TH1D(Form("fHistYPullDaughter%i",i), "Y Pull histo; Y Pull; counts",100,-1e-1,1e-1);
        fHistZPullDaughter[i] = new TH1D(Form("fHistZPullDaughter%i",i), "Z Pull histo; Z Pull; counts",100,-1e-1,1e-1);
        fHistPxPullDaughter[i] = new TH1D(Form("fHistPxPullDaughter%i",i), "Px Pull histo; Px Pull; counts",50,-0.15,0.15);
        fHistPyPullDaughter[i] = new TH1D(Form("fHistPyPullDaughter%i",i), "Py Pull histo; Py Pull; counts",50,-0.15,0.15);
        fHistPzPullDaughter[i] = new TH1D(Form("fHistPzPullDaughter%i",i), "Pz Pull histo; Pz Pull; counts",50,-0.15,0.15);
        fHistPtPullDaughter[i] = new TH1D(Form("fHistPtPullDaughter%i",i), "Pt Pull histo;  Pull; counts",50,-0.15,0.15);
        fHistMassPullDaughter[i] = new TH1D(Form("fHistMassPullDaughter%i",i), "Mass Pull histo; Mass Pull; counts",50,-0.15,0.15);
        fHistEPullDaughter[i] = new TH1D(Form("fHistEPullDaughter%i",i), "E Pull histo; E Pull; counts",50,-0.15,0.15);
    }
    //
    fGraphPtXMeanPullMother = new TGraphErrors();
    fGraphPtYMeanPullMother = new TGraphErrors();
    fGraphPtZMeanPullMother = new TGraphErrors();
    fGraphPtPxMeanPullMother = new TGraphErrors();
    fGraphPtPyMeanPullMother = new TGraphErrors();
    fGraphPtPzMeanPullMother = new TGraphErrors();
    fGraphPtPtMeanPullMother = new TGraphErrors();
    fGraphPtMassMeanPullMother = new TGraphErrors();
    fGraphPtEMeanPullMother = new TGraphErrors();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fGraphPtXMeanPullDaughter[i] = new TGraphErrors();
        fGraphPtYMeanPullDaughter[i] = new TGraphErrors();
        fGraphPtZMeanPullDaughter[i] = new TGraphErrors();
        fGraphPtPxMeanPullDaughter[i] = new TGraphErrors();
        fGraphPtPyMeanPullDaughter[i] = new TGraphErrors();
        fGraphPtPzMeanPullDaughter[i] = new TGraphErrors();
        fGraphPtPtMeanPullDaughter[i] = new TGraphErrors();
        fGraphPtMassMeanPullDaughter[i] = new TGraphErrors();
        fGraphPtEMeanPullDaughter[i] = new TGraphErrors();
    }
    //
    fGraphPtXPullWidthMother = new TGraphErrors();
    fGraphPtYPullWidthMother = new TGraphErrors();
    fGraphPtZPullWidthMother = new TGraphErrors();
    fGraphPtPxPullWidthMother = new TGraphErrors();
    fGraphPtPyPullWidthMother = new TGraphErrors();
    fGraphPtPzPullWidthMother = new TGraphErrors();
    fGraphPtPtPullWidthMother = new TGraphErrors();
    fGraphPtMassPullWidthMother = new TGraphErrors();
    fGraphPtEPullWidthMother = new TGraphErrors();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fGraphPtXPullWidthDaughter[i] = new TGraphErrors();
        fGraphPtYPullWidthDaughter[i] = new TGraphErrors();
        fGraphPtZPullWidthDaughter[i] = new TGraphErrors();
        fGraphPtPxPullWidthDaughter[i] = new TGraphErrors();
        fGraphPtPyPullWidthDaughter[i] = new TGraphErrors();
        fGraphPtPzPullWidthDaughter[i] = new TGraphErrors();
        fGraphPtPtPullWidthDaughter[i] = new TGraphErrors();
        fGraphPtMassPullWidthDaughter[i] = new TGraphErrors();
        fGraphPtEPullWidthDaughter[i] = new TGraphErrors();
    }   
}

void PullPtDepHistos::Fill(const MCParticleStruct& mcPart){
    //....
}
void PullPtDepHistos::Fill(const KFParticleStruct& kfPart){
    //....
}

void PullPtDepHistos::Fill(const MCParticleStruct& mcPart, const KFParticleStruct& kfPart){
    float x_resid_ = mcPart.x - kfPart.x;
    float y_resid_ = mcPart.y - kfPart.y;
    float z_resid_ = mcPart.z - kfPart.z;
    float px_resid_ = mcPart.pX - kfPart.pX;
    float py_resid_ = mcPart.pY - kfPart.pY;
    float pz_resid_ = mcPart.pZ - kfPart.pZ;
    float pt_resid_ = mcPart.pT() - kfPart.pT;
    float mass_resid_ = mcPart.mass - kfPart.mass;
    float e_resid_ = mcPart.e() - kfPart.e;

    float x_pull_ = x_resid_/kfPart.xErr;
    float y_pull_ = y_resid_/kfPart.yErr;
    float z_pull_ = z_resid_/kfPart.zErr;
    float px_pull_ = px_resid_/kfPart.pXErr;
    float py_pull_ = py_resid_/kfPart.pYErr;
    float pz_pull_ = pz_resid_/kfPart.pZErr;
    float pt_pull_ = pt_resid_/kfPart.pTErr;
    float mass_pull_ = mass_resid_/kfPart.massErr;
    float e_pull_ = e_resid_/kfPart.eErr;

    if (kfPart.isMother){
        fHistPtXPullMother -> Fill(mcPart.pT(),x_pull_);
        fHistPtYPullMother -> Fill(mcPart.pT(),y_pull_);
        fHistPtZPullMother -> Fill(mcPart.pT(),z_pull_);
        fHistPtPxPullMother -> Fill(mcPart.pT(),px_pull_);
        fHistPtPyPullMother -> Fill(mcPart.pT(),py_pull_);
        fHistPtPzPullMother -> Fill(mcPart.pT(),pz_pull_);
        fHistPtPtPullMother -> Fill(mcPart.pT(),pt_pull_);
        fHistPtMassPullMother -> Fill(mcPart.pT(),mass_pull_);
        fHistPtEPullMother -> Fill(mcPart.pT(),e_pull_);
    }
    if (kfPart.isDaughter){
        int daughterNum = kfPart.id-1;

        fHistPtXPullDaughter[daughterNum] -> Fill(mcPart.pT(),x_pull_);
        fHistPtYPullDaughter[daughterNum] -> Fill(mcPart.pT(),y_pull_);
        fHistPtZPullDaughter[daughterNum] -> Fill(mcPart.pT(),z_pull_);
        fHistPtPxPullDaughter[daughterNum] -> Fill(mcPart.pT(),px_pull_);
        fHistPtPyPullDaughter[daughterNum] -> Fill(mcPart.pT(),py_pull_);
        fHistPtPzPullDaughter[daughterNum] -> Fill(mcPart.pT(),pz_pull_);
        fHistPtPtPullDaughter[daughterNum] -> Fill(mcPart.pT(),pt_pull_);
        fHistPtMassPullDaughter[daughterNum] -> Fill(mcPart.pT(),mass_pull_);
        fHistPtEPullDaughter[daughterNum] -> Fill(mcPart.pT(),e_pull_);
    }
}

void PullPtDepHistos::PreWriteProcess(){
    fHistXPullMother = fHistPtXPullMother -> ProjectionY();
    fHistYPullMother = fHistPtYPullMother -> ProjectionY();
    fHistZPullMother = fHistPtZPullMother -> ProjectionY();
    fHistPxPullMother = fHistPtPxPullMother -> ProjectionY();
    fHistPyPullMother = fHistPtPyPullMother -> ProjectionY();
    fHistPzPullMother = fHistPtPzPullMother -> ProjectionY();
    fHistPtPullMother = fHistPtPtPullMother -> ProjectionY();
    fHistMassPullMother = fHistPtMassPullMother -> ProjectionY();
    fHistEPullMother = fHistPtEPullMother -> ProjectionY();
    for(int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistXPullDaughter[i] = fHistPtXPullDaughter[i] -> ProjectionY();
        fHistYPullDaughter[i] = fHistPtYPullDaughter[i] -> ProjectionY();
        fHistZPullDaughter[i] = fHistPtZPullDaughter[i] -> ProjectionY();
        fHistPxPullDaughter[i] = fHistPtPxPullDaughter[i] -> ProjectionY();
        fHistPyPullDaughter[i] = fHistPtPyPullDaughter[i] -> ProjectionY();
        fHistPzPullDaughter[i] = fHistPtPzPullDaughter[i] -> ProjectionY();
        fHistPtPullDaughter[i] = fHistPtPtPullDaughter[i] -> ProjectionY();
        fHistMassPullDaughter[i] = fHistPtMassPullDaughter[i] -> ProjectionY();
        fHistEPullDaughter[i] = fHistPtEPullDaughter[i] -> ProjectionY();
    }
    ///////
    fGraphPtXMeanPullMother = MakeMeanGraphFromTH2(fHistPtXPullMother);
    fGraphPtXMeanPullMother -> SetNameTitle("X Mean Pull","XMeanPull; p_{T}, GeV; X Pull");
    fGraphPtYMeanPullMother = MakeMeanGraphFromTH2(fHistPtYPullMother);
    fGraphPtYMeanPullMother -> SetNameTitle("Y Mean Pull","YMeanPull; p_{T}, GeV; Y Pull");
    fGraphPtZMeanPullMother = MakeMeanGraphFromTH2(fHistPtZPullMother);
    fGraphPtZMeanPullMother -> SetNameTitle("Z Mean Pull","ZMeanPull; p_{T}, GeV; Z Pull");
    fGraphPtPxMeanPullMother = MakeMeanGraphFromTH2(fHistPtPxPullMother);
    fGraphPtPxMeanPullMother -> SetNameTitle("Px Mean Pull","PxMeanPull; p_{T}, GeV; Px Pull");
    fGraphPtPyMeanPullMother = MakeMeanGraphFromTH2(fHistPtPyPullMother);
    fGraphPtPyMeanPullMother -> SetNameTitle("Py Mean Pull","PyMeanPull; p_{T}, GeV; Py Pull");
    fGraphPtPzMeanPullMother = MakeMeanGraphFromTH2(fHistPtPzPullMother);
    fGraphPtPzMeanPullMother -> SetNameTitle("Pz Mean Pull","PzMeanPull; p_{T}, GeV; Pz Pull");
    fGraphPtPtMeanPullMother = MakeMeanGraphFromTH2(fHistPtPtPullMother);
    fGraphPtPtMeanPullMother -> SetNameTitle("Pt Mean Pull","PtMeanPull; p_{T}, GeV; Pt Pull");
    fGraphPtMassMeanPullMother = MakeMeanGraphFromTH2(fHistPtMassPullMother);
    fGraphPtMassMeanPullMother -> SetNameTitle("Mass Mean Pull","MassMeanPull; p_{T}, GeV; Mass Pull");
    fGraphPtEMeanPullMother = MakeMeanGraphFromTH2(fHistPtEPullMother);
    fGraphPtEMeanPullMother -> SetNameTitle("E Mean Pull","EMeanPull; p_{T}, GeV; E Pull");
    for(int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fGraphPtXMeanPullDaughter[i] = MakeMeanGraphFromTH2(fHistPtXPullDaughter[i]);
        fGraphPtXMeanPullDaughter[i] -> SetNameTitle("X Mean Pull","XMeanPull; p_{T}, GeV; X Pull");
        fGraphPtYMeanPullDaughter[i] = MakeMeanGraphFromTH2(fHistPtYPullDaughter[i]);
        fGraphPtYMeanPullDaughter[i] -> SetNameTitle("Y Mean Pull","YMeanPull; p_{T}, GeV; Y Pull");
        fGraphPtZMeanPullDaughter[i] = MakeMeanGraphFromTH2(fHistPtZPullDaughter[i]);
        fGraphPtZMeanPullDaughter[i] -> SetNameTitle("Z Mean Pull","ZMeanPull; p_{T}, GeV; Z Pull");
        fGraphPtPxMeanPullDaughter[i] = MakeMeanGraphFromTH2(fHistPtPxPullDaughter[i]);
        fGraphPtPxMeanPullDaughter[i] -> SetNameTitle("Px Mean Pull","PxMeanPull; p_{T}, GeV; Px Pull");
        fGraphPtPyMeanPullDaughter[i] = MakeMeanGraphFromTH2(fHistPtPyPullDaughter[i]);
        fGraphPtPyMeanPullDaughter[i] -> SetNameTitle("Py Mean Pull","PyMeanPull; p_{T}, GeV; Py Pull");
        fGraphPtPzMeanPullDaughter[i] = MakeMeanGraphFromTH2(fHistPtPzPullDaughter[i]);
        fGraphPtPzMeanPullDaughter[i] -> SetNameTitle("Pz Mean Pull","PzMeanPull; p_{T}, GeV; Pz Pull");
        fGraphPtPtMeanPullDaughter[i] = MakeMeanGraphFromTH2(fHistPtPtPullDaughter[i]);
        fGraphPtPtMeanPullDaughter[i] -> SetNameTitle("Pt Mean Pull","PtMeanPull; p_{T}, GeV; Pt Pull");
        fGraphPtMassMeanPullDaughter[i] = MakeMeanGraphFromTH2(fHistPtMassPullDaughter[i]);
        fGraphPtMassMeanPullDaughter[i] -> SetNameTitle("Mass Mean Pull","MassMeanPull; p_{T}, GeV; Mass Pull");
        fGraphPtEMeanPullDaughter[i] = MakeMeanGraphFromTH2(fHistPtEPullDaughter[i]);
        fGraphPtEMeanPullDaughter[i] -> SetNameTitle("E Mean Pull","EMeanPull; p_{T}, GeV; E Pull");
    }
    ///////
    fGraphPtXPullWidthMother = MakeSigmaGraphFromTH2(fHistPtXPullMother);
    fGraphPtXPullWidthMother -> SetNameTitle("X PullWidth","XPullWidth; p_{T}, GeV; X PullWidth");
    fGraphPtYPullWidthMother = MakeSigmaGraphFromTH2(fHistPtYPullMother);
    fGraphPtYPullWidthMother -> SetNameTitle("Y PullWidth","YPullWidth; p_{T}, GeV; Y PullWidth");
    fGraphPtZPullWidthMother = MakeSigmaGraphFromTH2(fHistPtZPullMother);
    fGraphPtZPullWidthMother -> SetNameTitle("Z PullWidth","ZPullWidth; p_{T}, GeV; Z PullWidth");
    fGraphPtPxPullWidthMother = MakeSigmaGraphFromTH2(fHistPtPxPullMother);
    fGraphPtPxPullWidthMother -> SetNameTitle("Px PullWidth","PxPullWidth; p_{T}, GeV; Px PullWidth");
    fGraphPtPyPullWidthMother = MakeSigmaGraphFromTH2(fHistPtPyPullMother);
    fGraphPtPyPullWidthMother -> SetNameTitle("Py PullWidth","PyPullWidth; p_{T}, GeV; Py PullWidth");
    fGraphPtPzPullWidthMother = MakeSigmaGraphFromTH2(fHistPtPzPullMother);
    fGraphPtPzPullWidthMother -> SetNameTitle("Pz PullWidth","PzPullWidth; p_{T}, GeV; Pz PullWidth");
    fGraphPtPtPullWidthMother = MakeSigmaGraphFromTH2(fHistPtPtPullMother);
    fGraphPtPtPullWidthMother -> SetNameTitle("Pt PullWidth","PtPullWidth; p_{T}, GeV; Pt PullWidth");
    fGraphPtMassPullWidthMother = MakeSigmaGraphFromTH2(fHistPtMassPullMother);
    fGraphPtMassPullWidthMother -> SetNameTitle("Mass PullWidth","MassPullWidth; p_{T}, GeV; Mass PullWidth");
    fGraphPtEPullWidthMother = MakeSigmaGraphFromTH2(fHistPtEPullMother);
    fGraphPtEPullWidthMother -> SetNameTitle("E PullWidth","EPullWidth; p_{T}, GeV; E PullWidth");
    for(int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fGraphPtXPullWidthDaughter[i] = MakeSigmaGraphFromTH2(fHistPtXPullDaughter[i]);
        fGraphPtXPullWidthDaughter[i] -> SetNameTitle("X PullWidth","XPullWidth; p_{T}, GeV; X PullWidth");
        fGraphPtYPullWidthDaughter[i] = MakeSigmaGraphFromTH2(fHistPtYPullDaughter[i]);
        fGraphPtYPullWidthDaughter[i] -> SetNameTitle("Y PullWidth","YPullWidth; p_{T}, GeV; Y PullWidth");
        fGraphPtZPullWidthDaughter[i] = MakeSigmaGraphFromTH2(fHistPtZPullDaughter[i]);
        fGraphPtZPullWidthDaughter[i] -> SetNameTitle("Z PullWidth","ZPullWidth; p_{T}, GeV; Z PullWidth");
        fGraphPtPxPullWidthDaughter[i] = MakeSigmaGraphFromTH2(fHistPtPxPullDaughter[i]);
        fGraphPtPxPullWidthDaughter[i] -> SetNameTitle("Px PullWidth","PxPullWidth; p_{T}, GeV; Px PullWidth");
        fGraphPtPyPullWidthDaughter[i] = MakeSigmaGraphFromTH2(fHistPtPyPullDaughter[i]);
        fGraphPtPyPullWidthDaughter[i] -> SetNameTitle("Py PullWidth","PyPullWidth; p_{T}, GeV; Py PullWidth");
        fGraphPtPzPullWidthDaughter[i] = MakeSigmaGraphFromTH2(fHistPtPzPullDaughter[i]);
        fGraphPtPzPullWidthDaughter[i] -> SetNameTitle("Pz PullWidth","PzPullWidth; p_{T}, GeV; Pz PullWidth");
        fGraphPtPtPullWidthDaughter[i] = MakeSigmaGraphFromTH2(fHistPtPtPullDaughter[i]);
        fGraphPtPtPullWidthDaughter[i] -> SetNameTitle("Pt PullWidth","PtPullWidth; p_{T}, GeV; Pt PullWidth");
        fGraphPtMassPullWidthDaughter[i] = MakeSigmaGraphFromTH2(fHistPtMassPullDaughter[i]);
        fGraphPtMassPullWidthDaughter[i] -> SetNameTitle("Mass PullWidth","MassPullWidth; p_{T}, GeV; Mass PullWidth");
        fGraphPtEPullWidthDaughter[i] = MakeSigmaGraphFromTH2(fHistPtEPullDaughter[i]);
        fGraphPtEPullWidthDaughter[i] -> SetNameTitle("E PullWidth","EPullWidth; p_{T}, GeV; E PullWidth");
    }
}

void PullPtDepHistos::Write(){
   TDirectory* PullPtDep_Dir = outputFile->mkdir("PullPtDependencies");
        TDirectory* MotherPullPtDep_Dir = PullPtDep_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersPullPtDep_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersPullPtDep_Dir[i] = PullPtDep_Dir->mkdir(Form("Daughter%i",i+1));
            
        MotherPullPtDep_Dir -> cd();
            fHistPtXPullMother -> Write();
            fHistPtYPullMother -> Write();
            fHistPtZPullMother -> Write();
            fHistPtPxPullMother -> Write();
            fHistPtPyPullMother -> Write();
            fHistPtPzPullMother -> Write();
            fHistPtPtPullMother -> Write();
            fHistPtMassPullMother -> Write();
            fHistPtEPullMother -> Write();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        DaughtersPullPtDep_Dir[i] -> cd();
            fHistPtXPullDaughter[i] -> Write();
            fHistPtYPullDaughter[i] -> Write();
            fHistPtZPullDaughter[i] -> Write();
            fHistPtPxPullDaughter[i] -> Write();
            fHistPtPyPullDaughter[i] -> Write();
            fHistPtPzPullDaughter[i] -> Write();
            fHistPtPtPullDaughter[i] -> Write();
            fHistPtMassPullDaughter[i] -> Write();
            fHistPtEPullDaughter[i] -> Write();
    }
    /////////////////////////////////
    ///////////////////////////////// 
    TDirectory* PullHistos_Dir = outputFile->mkdir("PullHistos");
        TDirectory* MotherPullHistos_Dir = PullHistos_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersPullHistos_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersPullHistos_Dir[i] = PullHistos_Dir->mkdir(Form("Daughter%i",i+1));
             
        MotherPullHistos_Dir -> cd();
            fHistXPullMother -> Write();
            fHistYPullMother -> Write();
            fHistZPullMother -> Write();
            fHistPxPullMother -> Write();
            fHistPyPullMother -> Write();
            fHistPzPullMother -> Write();
            fHistPtPullMother -> Write();
            fHistMassPullMother -> Write();
            fHistEPullMother -> Write();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        DaughtersPullHistos_Dir[i] -> cd();
            fHistXPullDaughter[i] -> Write();
            fHistYPullDaughter[i] -> Write();
            fHistZPullDaughter[i] -> Write();
            fHistPxPullDaughter[i] -> Write();
            fHistPyPullDaughter[i] -> Write();
            fHistPzPullDaughter[i] -> Write();
            fHistPtPullDaughter[i] -> Write();
            fHistMassPullDaughter[i] -> Write();
            fHistEPullDaughter[i] -> Write();
    }
    /////////////////////////////////
    ///////////////////////////////// 
    TDirectory* MeanPullPtDepPlots_Dir = outputFile->mkdir("MeanPullPtDepPlots");
        TDirectory* MotherMeanPullPtDepPlots_Dir = MeanPullPtDepPlots_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersMeanPullPtDepPlots_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersMeanPullPtDepPlots_Dir[i] = MeanPullPtDepPlots_Dir->mkdir(Form("Daughter%i",i+1));
           
        MotherMeanPullPtDepPlots_Dir -> cd();
            fGraphPtXMeanPullMother -> Write();
            fGraphPtYMeanPullMother -> Write();
            fGraphPtZMeanPullMother -> Write();
            fGraphPtPxMeanPullMother -> Write();
            fGraphPtPyMeanPullMother -> Write();
            fGraphPtPzMeanPullMother -> Write();
            fGraphPtPtMeanPullMother -> Write();
            fGraphPtMassMeanPullMother -> Write();
            fGraphPtEMeanPullMother -> Write();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        DaughtersMeanPullPtDepPlots_Dir[i] -> cd();
            fGraphPtXMeanPullDaughter[i] -> Write();
            fGraphPtYMeanPullDaughter[i] -> Write();
            fGraphPtZMeanPullDaughter[i] -> Write();
            fGraphPtPxMeanPullDaughter[i] -> Write();
            fGraphPtPyMeanPullDaughter[i] -> Write();
            fGraphPtPzMeanPullDaughter[i] -> Write();
            fGraphPtPtMeanPullDaughter[i] -> Write();
            fGraphPtMassMeanPullDaughter[i] -> Write();
            fGraphPtEMeanPullDaughter[i] -> Write();
    }
    /////////////////////////////////
    /////////////////////////////////         
    TDirectory* PullWidthPtDepPlots_Dir = outputFile->mkdir("PullWidthPtDepPlots");
        TDirectory* MotherPullWidthPtDepPlots_Dir = PullWidthPtDepPlots_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersPullWidthPtDepPlots_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersPullWidthPtDepPlots_Dir[i] = PullWidthPtDepPlots_Dir->mkdir(Form("Daughter%i",i+1));
            
        MotherPullWidthPtDepPlots_Dir -> cd();
            fGraphPtXPullWidthMother -> Write();
            fGraphPtYPullWidthMother -> Write();
            fGraphPtZPullWidthMother -> Write();
            fGraphPtPxPullWidthMother -> Write();
            fGraphPtPyPullWidthMother -> Write();
            fGraphPtPzPullWidthMother -> Write();
            fGraphPtPtPullWidthMother -> Write();
            fGraphPtMassPullWidthMother -> Write();
            fGraphPtEPullWidthMother -> Write();
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        DaughtersPullWidthPtDepPlots_Dir[i] -> cd();
            fGraphPtXPullWidthDaughter[i] -> Write();
            fGraphPtYPullWidthDaughter[i] -> Write();
            fGraphPtZPullWidthDaughter[i] -> Write();
            fGraphPtPxPullWidthDaughter[i] -> Write();
            fGraphPtPyPullWidthDaughter[i] -> Write();
            fGraphPtPzPullWidthDaughter[i] -> Write();
            fGraphPtPtPullWidthDaughter[i] -> Write();
            fGraphPtMassPullWidthDaughter[i] -> Write();
            fGraphPtEPullWidthDaughter[i] -> Write();
    }
}



