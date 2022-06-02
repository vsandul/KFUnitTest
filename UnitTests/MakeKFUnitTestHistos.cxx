#include <algorithm>
#include "TDirectory.h"

#include "HeadersList.h"

#include "ConfigConstants.h"
#include "OutputObjInterface/OutputMap.h"
#include "OutputObjInterface/MakeGraphsFromTH2.h"

/////
float pT(float px, float py){return sqrt(px*px+py*py);}
float p(float px, float py, float pz){return sqrt(px*px+py*py+pz*pz);}
float e(float px, float py, float pz, float mass){return sqrt(px*px+py*py+pz*pz+mass*mass);}
float eta(float px, float py, float pz){return 0.5*log((p(px,py,pz)+pz)/(p(px,py,pz)-pz));}
float phi(float px, float py){return atan2(py, px);}
float theta(float px, float py, float pz){return atan2(pT(px,py), pz);}

// ... ADD DESCRIPTION 
//...

void MakeKFUnitTestHistos(){

    cout << "\n Staring MakeKFUnitTestHistos macro \n";

    TFile outputFile( KFHistoOutputFile, "RECREATE" );
    OutputMap output_map(outputFile);
    output_map.CreateAll();
    ///////////////////////////////////////////////////////////
    // Next step is to create a directories structure
    //////////////////////////////////////////////////////////

    TDirectory* QAHistos_Dir = outputFile.mkdir("QAHistos");
        TDirectory* GeantMC_Dir = QAHistos_Dir->mkdir("GeantMC");
            TDirectory* MotherMC_Dir = GeantMC_Dir->mkdir("Mother");
            std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersMC_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersMC_Dir[i] = GeantMC_Dir->mkdir(Form("Daughter%i",i+1));
                
        TDirectory* KFPartBeforeReco_Dir = QAHistos_Dir->mkdir("KFPartBeforeReco");
            TDirectory* MotherKFBR_Dir = KFPartBeforeReco_Dir->mkdir("Mother");
            std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersKFBR_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersKFBR_Dir[i] = KFPartBeforeReco_Dir->mkdir(Form("Daughter%i",i+1));
                
        TDirectory* KFPartAfterReco_Dir = QAHistos_Dir->mkdir("KFPartAfterReco");
            TDirectory* MotherKFAR_Dir = KFPartAfterReco_Dir->mkdir("Mother");
            std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersKFAR_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersKFAR_Dir[i] = KFPartAfterReco_Dir->mkdir(Form("Daughter%i",i+1));
                
   
            
    
    //TDirectory*  = outputFile.mkdir("OtherHistosAndPlots");
    TDirectory* OtherHistos = outputFile.mkdir("OtherHistosAndPlots");
        
        
    ////////////////////////////////////////////////////////
    ////////////// end of structure block
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    ////////////// Beginning of histograms block
    ////////////////////////////////////////////////////////

    TH1F *fHistXMotherMC = new TH1F("fHistXMotherMC", "X MC; x, cm; counts", 1000, -1e1, 1e1);
    TH1F *fHistYMotherMC = new TH1F("fHistYMotherMC", "Y MC; y, cm; counts",1000, -1e1, 1e1);
    TH1F *fHistZMotherMC = new TH1F("fHistZMotherMC", "Z MC; z, cm; counts",1000, -3e1, 3e1);
    TH1F *fHistPxMotherMC = new TH1F("fHistPxMotherMC", "Px MC; Px, GeV; counts", 1000, -10, 10);
    TH1F *fHistPyMotherMC = new TH1F("fHistPyMotherMC", "Py MC; Py, GeV; counts",1000, -10, 10);
    TH1F *fHistPzMotherMC = new TH1F("fHistPzMotherMC", "Pz MC; Pz, GeV; counts",1000, -10, 10);
    TH1I *fHistChargeMotherMC = new TH1I("fHistChargeMotherMC", "Charge MC; Q; counts",50, -25, 25);
    TH1I *fHistPDGMotherMC = new TH1I("fHistPDGMotherMC", "PDG MC; PDG; counts",2000, -1000, 1000);
    TH1F *fHistPtMotherMC = new TH1F("fHistPtMotherMC", "Pt MC; p_{T}, GeV; counts",1000,0.,10.);
    TH1F *fHistOneOverPtMotherMC = new TH1F("fHistOneOverPtMotherMC", "1/Pt MC; 1/Pt, GeV^{-1}",1000,0.,20.);
    TH1F *fHistPMotherMC = new TH1F("fHistPMotherMC", "P MC; P, GeV; counts",1000,0.,30.);    
    TH1F *fHistEMotherMC = new TH1F("fHistEMotherMC", "E MC; E, GeV; counts",1000,0.,30.);
    TH1F *fHistMassMotherMC = new TH1F("fHistMassMotherMC", "Mass MC; M, GeV; counts",1000,0.,10.);
    TH1F *fHistEtaMotherMC = new TH1F("fHistEtaMotherMC", "Eta MC; #eta; counts",1000, -10, 10);
    TH1F *fHistPhiMotherMC = new TH1F("fHistPhiMotherMC", "Phi MC; #varphi; counts",1000, -6.5, 6.5);
    TH1F *fHistChi2MotherMC = new TH1F("fHistChi2MotherMC", "Chi2 MC; #chi^{2}; counts",1000, -10, 10);
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistXDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistYDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistZDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPxDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPyDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPzDaughterMC;
    std::array<TH1I*, NUM_OF_DAUGHTERS> fHistChargeDaughterMC;
    std::array<TH1I*, NUM_OF_DAUGHTERS> fHistPDGDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPtDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistOneOverPtDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistEDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistMassDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistEtaDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPhiDaughterMC;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistChi2DaughterMC;
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++) {
        fHistXDaughterMC[i] = new TH1F(Form("fHistXDaughterMC%i",i+1), "X MC; x, cm; counts", 1000, -1e1, 1e1);
        fHistYDaughterMC[i] = new TH1F(Form("fHistYDaughterMC%i",i+1), "Y MC; y, cm; counts",1000, -1e1, 1e1);
        fHistZDaughterMC[i] = new TH1F(Form("fHistZDaughterMC%i",i+1), "Z MC; z, cm; counts",1000, -3e1, 3e1);
        fHistPxDaughterMC[i] = new TH1F(Form("fHistPxDaughterMC%i",i+1), "Px MC; Px, GeV; counts", 1000, -10, 10);
        fHistPyDaughterMC[i] = new TH1F(Form("fHistPyDaughterMC%i",i+1), "Py MC; Py, GeV; counts",1000, -10, 10);
        fHistPzDaughterMC[i] = new TH1F(Form("fHistPzDaughterMC%i",i+1), "Pz MC; Pz, GeV; counts",1000, -10, 10);
        fHistChargeDaughterMC[i] = new TH1I(Form("fHistChargeDaughterMC%i",i+1), "Charge MC; Q; counts",50, -25, 25);
        fHistPDGDaughterMC[i] = new TH1I(Form("fHistPDGDaughterMC%i",i+1), "PDG MC; PDG; counts",2000, -1000, 1000);
        fHistPtDaughterMC[i] = new TH1F(Form("fHistPtDaughterMC%i",i+1), "Pt MC; p_{T}, GeV; counts",1000,0.,10.);
        fHistOneOverPtDaughterMC[i] = new TH1F(Form("fHistOveOverPtDaughterMC%i",i+1), "1/Pt MC; 1/Pt GeV^{-1}",1000,0.,20.);
        fHistPDaughterMC[i] = new TH1F(Form("fHistPDaughterMC%i",i+1), "P MC; P, GeV; counts",1000,0.,30.); 
        fHistEDaughterMC[i] = new TH1F(Form("fHistEDaughterMC%i",i+1), "E MC; E, GeV; counts",1000,0.,30.);
        fHistMassDaughterMC[i] = new TH1F(Form("fHistMassDaughterMC%i",i+1), "Mass MC; M, GeV; counts",1000,0.,10.);
        fHistEtaDaughterMC[i] = new TH1F(Form("fHistEtaDaughterMC%i",i+1), "Eta MC; #eta; counts",1000,-10,10.);
        fHistPhiDaughterMC[i] = new TH1F(Form("fHistPhiDaughterMC%i",i+1), "Phi MC; #varphi; counts",1000,-6.5,6.5);
        fHistChi2DaughterMC[i] = new TH1F(Form("fHistChi2DaughterMC%i",i+1), "Chi2 MC; #chi^{2}; counts",1000, -10, 10);
    }

    TH1F *fHistXMotherKFBR = new TH1F("fHistXMotherKFBR", "X KFBR; x, cm; counts", 1000, -1e1, 1e1);
    TH1F *fHistYMotherKFBR = new TH1F("fHistYMotherKFBR", "Y KFBR; y, cm; counts",1000, -1e1, 1e1);
    TH1F *fHistZMotherKFBR = new TH1F("fHistZMotherKFBR", "Z KFBR; z, cm; counts",1000, -3e1, 3e1);
    TH1F *fHistPxMotherKFBR = new TH1F("fHistPxMotherKFBR", "Px KFBR; Px, GeV; counts", 1000, -10, 10);
    TH1F *fHistPyMotherKFBR = new TH1F("fHistPyMotherKFBR", "Py KFBR; Py, GeV; counts",1000, -10, 10);
    TH1F *fHistPzMotherKFBR = new TH1F("fHistPzMotherKFBR", "Pz KFBR; Pz, GeV; counts",1000, -10, 10);
    TH1I *fHistChargeMotherKFBR = new TH1I("fHistChargeMotherKFBR", "Charge KFBR; Q; counts",50, -25, 25);
    TH1I *fHistPDGMotherKFBR = new TH1I("fHistPDGMotherKFBR", "PDG KFBR; PDG; counts",2000, -1000, 1000);
    TH1F *fHistPtMotherKFBR = new TH1F("fHistPtMotherKFBR", "Pt KFBR; p_{T}, GeV; counts",1000,0.,10.);
    TH1F *fHistOneOverPtMotherKFBR = new TH1F("fHistOneOverPtMotherKFBR", "1/Pt KFBR; 1/Pt, GeV^{-1}",1000,0.,20.);
    TH1F *fHistPMotherKFBR = new TH1F("fHistPMotherKFBR", "P KFBR; P, GeV; counts",1000,0.,30.);    
    TH1F *fHistEMotherKFBR = new TH1F("fHistEMotherKFBR", "E KFBR; E, GeV; counts",1000,0.,30.);
    TH1F *fHistMassMotherKFBR = new TH1F("fHistMassMotherKFBR", "Mass KFBR; M, GeV; counts",1000,0.,10.);
    TH1F *fHistEtaMotherKFBR = new TH1F("fHistEtaMotherKFBR", "Eta KFBR; #eta; counts",1000,-10,10.);
    TH1F *fHistPhiMotherKFBR = new TH1F("fHistPhiMotherKFBR", "Phi KFBR; #varphi; counts",1000,-6.5,6.5);
    TH1F *fHistChi2MotherKFBR = new TH1F("fHistChi2MotherKFBR", "Chi2 KFBR; #chi^{2}; counts",1000, -10, 10);
    TH1F *fHistNDFMotherKFBR = new TH1F("fHistNDFMotherKFBR", "NDF KFBR; NDF; counts",1000, -10, 10);
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistXDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistYDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistZDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPxDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPyDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPzDaughterKFBR;
    std::array<TH1I*, NUM_OF_DAUGHTERS> fHistChargeDaughterKFBR;
    std::array<TH1I*, NUM_OF_DAUGHTERS> fHistPDGDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPtDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistOneOverPtDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistEDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistMassDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistEtaDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPhiDaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistChi2DaughterKFBR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistNDFDaughterKFBR;
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++) {
        fHistXDaughterKFBR[i] = new TH1F(Form("fHistXDaughterKFBR%i",i+1), "X KFBR; x, cm; counts", 1000, -1e1, 1e1);
        fHistYDaughterKFBR[i] = new TH1F(Form("fHistYDaughterKFBR%i",i+1), "Y KFBR; y, cm; counts",1000, -1e1, 1e1);
        fHistZDaughterKFBR[i] = new TH1F(Form("fHistZDaughterKFBR%i",i+1), "Z KFBR; z, cm; counts",1000, -3e1, 3e1);
        fHistPxDaughterKFBR[i] = new TH1F(Form("fHistPxDaughterKFBR%i",i+1), "Px KFBR; Px, GeV; counts", 1000, -10, 10);
        fHistPyDaughterKFBR[i] = new TH1F(Form("fHistPyDaughterKFBR%i",i+1), "Py KFBR; Py, GeV; counts",1000, -10, 10);
        fHistPzDaughterKFBR[i] = new TH1F(Form("fHistPzDaughterKFBR%i",i+1), "Pz KFBR; Pz, GeV; counts",1000, -10, 10);
        fHistChargeDaughterKFBR[i] = new TH1I(Form("fHistChargeDaughterKFBR%i",i+1), "Charge KFBR; Q; counts",50, -25, 25);
        fHistPDGDaughterKFBR[i] = new TH1I(Form("fHistPDGDaughterKFBR%i",i+1), "PDG KFBR; PDG; counts",2000, -1000, 1000);
        fHistPtDaughterKFBR[i] = new TH1F(Form("fHistPtDaughterKFBR%i",i+1), "Pt KFBR; p_{T}, GeV; counts",1000,0.,10.);
        fHistOneOverPtDaughterKFBR[i] = new TH1F(Form("fHistOveOverPtDaughterKFBR%i",i+1), "1/Pt KFBR; 1/Pt, GeV^{-1}",1000,0.,20.);
        fHistPDaughterKFBR[i] = new TH1F(Form("fHistPDaughterKFBR%i",i+1), "P KFBR; P, GeV; counts",1000,0.,30.); 
        fHistEDaughterKFBR[i] = new TH1F(Form("fHistEDaughterKFBR%i",i+1), "E KFBR; E, GeV; counts",1000,0.,30.);
        fHistMassDaughterKFBR[i] = new TH1F(Form("fHistMassDaughterKFBR%i",i+1), "Mass KFBR; M, GeV; counts",1000,0.,10.);
        fHistEtaDaughterKFBR[i] = new TH1F(Form("fHistEtaDaughterKFBR%i",i+1), "Eta KFBR; #eta; counts",1000,-10.,10.);
        fHistPhiDaughterKFBR[i] = new TH1F(Form("fHistPhiDaughterKFBR%i",i+1), "Phi KFBR; #varphi; counts",1000,-6.5,6.5);
        fHistChi2DaughterKFBR[i] = new TH1F(Form("fHistChi2DaughterKFBR%i",i+1), "Chi2 KFBR; #chi^{2}; counts",1000, -10, 10);
        fHistNDFDaughterKFBR[i] = new TH1F(Form("fHistNDFDaughterKFBR%i",i+1), "NDF KFBR; NDF; counts",1000, -10, 10);
    }

    TH1F *fHistXMotherKFAR = new TH1F("fHistXMotherKFAR", "X KFAR; x, cm; counts", 1000, -1e1, 1e1);
    TH1F *fHistYMotherKFAR = new TH1F("fHistYMotherKFAR", "Y KFAR; y, cm; counts",1000, -1e1, 1e1);
    TH1F *fHistZMotherKFAR = new TH1F("fHistZMotherKFAR", "Z KFAR; z, cm; counts",1000, -3e1, 3e1);
    TH1F *fHistPxMotherKFAR = new TH1F("fHistPxMotherKFAR", "Px KFAR; Px, GeV; counts", 1000, -10, 10);
    TH1F *fHistPyMotherKFAR = new TH1F("fHistPyMotherKFAR", "Py KFAR; Py, GeV; counts",1000, -10, 10);
    TH1F *fHistPzMotherKFAR = new TH1F("fHistPzMotherKFAR", "Pz KFAR; Pz, GeV; counts",1000, -10, 10);
    TH1I *fHistChargeMotherKFAR = new TH1I("fHistChargeMotherKFAR", "Charge KFAR; Q; counts",50, -25, 25);
    TH1I *fHistPDGMotherKFAR = new TH1I("fHistPDGMotherKFAR", "PDG KFAR; PDG; counts",2000, -1000, 1000);
    TH1F *fHistPtMotherKFAR = new TH1F("fHistPtMotherKFAR", "Pt KFAR; p_{T}, GeV; counts",1000,0.,10.);
    TH1F *fHistOneOverPtMotherKFAR = new TH1F("fHistOneOverPtMotherKFAR", "1/Pt KFAR; 1/Pt, GeV^{-1}",1000,0.,20.);
    TH1F *fHistPMotherKFAR = new TH1F("fHistPMotherKFAR", "P KFAR; P, GeV; counts",1000,0.,30.);    
    TH1F *fHistEMotherKFAR = new TH1F("fHistEMotherKFAR", "E KFAR; E, GeV; counts",1000,0.,30.);
    TH1F *fHistMassMotherKFAR = new TH1F("fHistMassMotherKFAR", "Mass KFAR; M, GeV; counts",1000,0.,10.);
    TH1F *fHistEtaMotherKFAR = new TH1F("fHistEtaMotherKFAR", "Eta KFAR; #eta; counts",1000,-10,10.);
    TH1F *fHistPhiMotherKFAR = new TH1F("fHistPhiMotherKFAR", "Phi KFAR; #varphi; counts",1000,-6.5,6.5);
    TH1F *fHistChi2MotherKFAR = new TH1F("fHistChi2MotherKFAR", "Chi2 KFAR; #chi^{2}; counts",1000, -10, 10);
    TH1F *fHistNDFMotherKFAR = new TH1F("fHistNDFMotherKFAR", "NDF KFAR; NDF; counts",1000, -10, 10);
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistXDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistYDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistZDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPxDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPyDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPzDaughterKFAR;
    std::array<TH1I*, NUM_OF_DAUGHTERS> fHistChargeDaughterKFAR;
    std::array<TH1I*, NUM_OF_DAUGHTERS> fHistPDGDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPtDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistOneOverPtDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistEDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistMassDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistEtaDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistPhiDaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistChi2DaughterKFAR;
    std::array<TH1F*, NUM_OF_DAUGHTERS> fHistNDFDaughterKFAR;
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++) {
        fHistXDaughterKFAR[i] = new TH1F(Form("fHistXDaughterKFAR%i",i+1), "X KFAR; x, cm; counts", 1000, -1e1, 1e1);
        fHistYDaughterKFAR[i] = new TH1F(Form("fHistYDaughterKFAR%i",i+1), "Y KFAR; y, cm; counts",1000, -1e1, 1e1);
        fHistZDaughterKFAR[i] = new TH1F(Form("fHistZDaughterKFAR%i",i+1), "Z KFAR; z, cm; counts",1000, -3e1, 3e1);
        fHistPxDaughterKFAR[i] = new TH1F(Form("fHistPxDaughterKFAR%i",i+1), "Px KFAR; Px, GeV; counts", 1000, -10, 10);
        fHistPyDaughterKFAR[i] = new TH1F(Form("fHistPyDaughterKFAR%i",i+1), "Py KFAR; Py, GeV; counts",1000, -10, 10);
        fHistPzDaughterKFAR[i] = new TH1F(Form("fHistPzDaughterKFAR%i",i+1), "Pz KFAR; Pz, GeV; counts",1000, -10, 10);
        fHistChargeDaughterKFAR[i] = new TH1I(Form("fHistChargeDaughterKFAR%i",i+1), "Charge KFAR; Q; counts",50, -25, 25);
        fHistPDGDaughterKFAR[i] = new TH1I(Form("fHistPDGDaughterKFAR%i",i+1), "PDG KFAR; PDG; counts",2000, -1000, 1000);
        fHistPtDaughterKFAR[i] = new TH1F(Form("fHistPtDaughterKFAR%i",i+1), "Pt KFAR; p_{T}, GeV; counts",1000,0.,10.);
        fHistOneOverPtDaughterKFAR[i] = new TH1F(Form("fHistOveOverPtDaughterKFAR%i",i+1), "1/Pt KFAR; 1/p_{T}, GeV^{-1}",1000,0.,20.);
        fHistPDaughterKFAR[i] = new TH1F(Form("fHistPDaughterKFAR%i",i+1), "P KFAR; P, GeV; counts",1000,0.,30.); 
        fHistEDaughterKFAR[i] = new TH1F(Form("fHistEDaughterKFAR%i",i+1), "E KFAR; E, GeV; counts",1000,0.,30.);
        fHistMassDaughterKFAR[i] = new TH1F(Form("fHistMassDaughterKFAR%i",i+1), "Mass KFAR; M, GeV; counts",1000,0.,10.);
        fHistEtaDaughterKFAR[i] = new TH1F(Form("fHistEtaDaughterKFAR%i",i+1), "Eta KFAR; #eta; counts",1000,-10.,10.);
        fHistPhiDaughterKFAR[i] = new TH1F(Form("fHistPhiDaughterKFAR%i",i+1), "Phi KFAR; #varphi; counts",1000,-6.5,6.5);
        fHistChi2DaughterKFAR[i] = new TH1F(Form("fHistChi2DaughterKFAR%i",i+1), "Chi2 KFAR; #chi^{2}; counts",1000, -10, 10);
        fHistNDFDaughterKFAR[i] = new TH1F(Form("fHistNDFDaughterKFAR%i",i+1), "NDF KFAR; NDF; counts",1000, -10, 10);
    }

    // other histos and plots
    TH2F* fHistPtPtErrMother = new TH2F("fHistPtPtErrMother","fHistPtPtErrMother",50,0,10,100,-0.04,0.04);
    ////////////////////////////////////////////////////////////////////////
    ////////////////// end of histogram block
    ////////////////////////////////////////////////////////////////////////

    cout << " Creating input and ouput files \n";
    ////////////////////////////////////////////////////////////////////////
    ////////////////// read trees from file
    ////////////////////////////////////////////////////////////////////////
    TChain chainMC(nameOfMCTree);
    std::cout << "MCInputFile: " << MCInputFile << std::endl;
    chainMC.Add(MCInputFile);

    int nTracks_MC;
    int trackID_MC[MAX_NUM_OF_TRACKS];
    int parentID_MC[MAX_NUM_OF_TRACKS];
    int pdg_MC[MAX_NUM_OF_TRACKS];
    //float pdgLifeTime_MC[MAX_NUM_OF_TRACKS];
    int charge_MC[MAX_NUM_OF_TRACKS];
    float initialX_MC[MAX_NUM_OF_TRACKS];
    float initialY_MC[MAX_NUM_OF_TRACKS];
    float initialZ_MC[MAX_NUM_OF_TRACKS];
    float finalX_MC[MAX_NUM_OF_TRACKS];
    float finalY_MC[MAX_NUM_OF_TRACKS];
    float finalZ_MC[MAX_NUM_OF_TRACKS];
    float trackLength_MC[MAX_NUM_OF_TRACKS];
    float initialPX_MC[MAX_NUM_OF_TRACKS];
    float initialPY_MC[MAX_NUM_OF_TRACKS];
    float initialPZ_MC[MAX_NUM_OF_TRACKS];
    float finalPX_MC[MAX_NUM_OF_TRACKS];
    float finalPY_MC[MAX_NUM_OF_TRACKS];
    float finalPZ_MC[MAX_NUM_OF_TRACKS];
    float mass_MC[MAX_NUM_OF_TRACKS];

    chainMC.SetBranchAddress( "nTracks", &nTracks_MC);
    chainMC.SetBranchAddress( "trackID", trackID_MC);
    chainMC.SetBranchAddress( "parentID", parentID_MC);
    chainMC.SetBranchAddress( "pdg", pdg_MC);
    //chainMC.SetBranchAddress( "pdgLifeTime", pdgLifeTime_MC);
    chainMC.SetBranchAddress( "charge", charge_MC);
    chainMC.SetBranchAddress( "initialX", initialX_MC);
    chainMC.SetBranchAddress( "initialY", initialY_MC);
    chainMC.SetBranchAddress( "initialZ", initialZ_MC);
    chainMC.SetBranchAddress( "finalX", finalX_MC);
    chainMC.SetBranchAddress( "finalY", finalY_MC);
    chainMC.SetBranchAddress( "finalZ", finalZ_MC);
    chainMC.SetBranchAddress( "trackLength", trackLength_MC);
    chainMC.SetBranchAddress( "initialPX", initialPX_MC);
    chainMC.SetBranchAddress( "initialPY", initialPY_MC);
    chainMC.SetBranchAddress( "initialPZ", initialPZ_MC);
    chainMC.SetBranchAddress( "finalPX", finalPX_MC);
    chainMC.SetBranchAddress( "finalPY", finalPY_MC);
    chainMC.SetBranchAddress( "finalPZ", finalPZ_MC);
    chainMC.SetBranchAddress( "mass", mass_MC);

    //--------------------------------------------------------------

    TChain chainKFBR(nameOfKFBRTree);
    std::cout << "KFInputFile: " << KFInputFile << std::endl;
    chainKFBR.Add(KFInputFile);

    int nTracks_KFBR ;
    int numOfMCEvent_KFBR ;
    bool isAllCovMatOK_KFBR ;

    int id_KFBR[NUM_OF_KFPARTICLES];
    int idMC_KFBR[NUM_OF_KFPARTICLES];
    int pdg_KFBR[NUM_OF_KFPARTICLES];
    float params_KFBR[NUM_OF_KFPARTICLES][6];
    float covMat_KFBR[NUM_OF_KFPARTICLES][36];
    bool isCovMatOK_KFBR[NUM_OF_KFPARTICLES];
    float x_KFBR[NUM_OF_KFPARTICLES];
    float y_KFBR[NUM_OF_KFPARTICLES];
    float z_KFBR[NUM_OF_KFPARTICLES];
    float pX_KFBR[NUM_OF_KFPARTICLES];
    float pY_KFBR[NUM_OF_KFPARTICLES];
    float pZ_KFBR[NUM_OF_KFPARTICLES];
    float e_KFBR[NUM_OF_KFPARTICLES];
    float s_KFBR[NUM_OF_KFPARTICLES];
    int charge_KFBR[NUM_OF_KFPARTICLES];
    float chi2_KFBR[NUM_OF_KFPARTICLES];
    float ndf_KFBR[NUM_OF_KFPARTICLES];
    float massHypo_KFBR[NUM_OF_KFPARTICLES];

    bool isMother_KFBR[NUM_OF_KFPARTICLES];
    bool isDaughter_KFBR[NUM_OF_KFPARTICLES];
    
    float p_KFBR[NUM_OF_KFPARTICLES];
    float pT_KFBR[NUM_OF_KFPARTICLES];
    float eta_KFBR[NUM_OF_KFPARTICLES];
    float phi_KFBR[NUM_OF_KFPARTICLES];
    float mass_KFBR[NUM_OF_KFPARTICLES];
    float decayLength_KFBR[NUM_OF_KFPARTICLES];
    float decayLengthXY_KFBR[NUM_OF_KFPARTICLES];
    float lifeTime_KFBR[NUM_OF_KFPARTICLES];
    float r_KFBR[NUM_OF_KFPARTICLES];
    float rapidity_KFBR[NUM_OF_KFPARTICLES];
    float theta_KFBR[NUM_OF_KFPARTICLES];

    float xErr_KFBR[NUM_OF_KFPARTICLES];
    float yErr_KFBR[NUM_OF_KFPARTICLES];
    float zErr_KFBR[NUM_OF_KFPARTICLES];
    float pXErr_KFBR[NUM_OF_KFPARTICLES];
    float pYErr_KFBR[NUM_OF_KFPARTICLES];
    float pZErr_KFBR[NUM_OF_KFPARTICLES];
    float eErr_KFBR[NUM_OF_KFPARTICLES];
    float sErr_KFBR[NUM_OF_KFPARTICLES];
    float pErr_KFBR[NUM_OF_KFPARTICLES];
    float pTErr_KFBR[NUM_OF_KFPARTICLES];
    float etaErr_KFBR[NUM_OF_KFPARTICLES];
    float phiErr_KFBR[NUM_OF_KFPARTICLES];
    float massErr_KFBR[NUM_OF_KFPARTICLES];
    float decayLengthErr_KFBR[NUM_OF_KFPARTICLES];
    float decayLengthXYErr_KFBR[NUM_OF_KFPARTICLES];
    float lifeTimeErr_KFBR[NUM_OF_KFPARTICLES];
    float rErr_KFBR[NUM_OF_KFPARTICLES];    

	chainKFBR.SetBranchAddress("nTracks", &nTracks_KFBR);
	chainKFBR.SetBranchAddress("numOfMCEvent", &numOfMCEvent_KFBR );
	chainKFBR.SetBranchAddress("isAllCovMatOK", &isAllCovMatOK_KFBR );

    chainKFBR.SetBranchAddress("ID", id_KFBR );
    chainKFBR.SetBranchAddress("IDMC", idMC_KFBR );
	chainKFBR.SetBranchAddress("pdgID", pdg_KFBR);
    chainKFBR.SetBranchAddress("params", params_KFBR );
    chainKFBR.SetBranchAddress("covMat", covMat_KFBR );
    chainKFBR.SetBranchAddress("isCovMatOK", isCovMatOK_KFBR );
    chainKFBR.SetBranchAddress("x", x_KFBR );
    chainKFBR.SetBranchAddress("y", y_KFBR );
    chainKFBR.SetBranchAddress("z", z_KFBR );
    chainKFBR.SetBranchAddress("pX", pX_KFBR );
    chainKFBR.SetBranchAddress("pY", pY_KFBR );
    chainKFBR.SetBranchAddress("pZ", pZ_KFBR );
    chainKFBR.SetBranchAddress("e", e_KFBR );
    chainKFBR.SetBranchAddress("s", s_KFBR );
    chainKFBR.SetBranchAddress("charge", charge_KFBR );
    chainKFBR.SetBranchAddress("chi2", chi2_KFBR );
    chainKFBR.SetBranchAddress("ndf", ndf_KFBR );
    chainKFBR.SetBranchAddress("massHypo", massHypo_KFBR );

    chainKFBR.SetBranchAddress("isMother", isMother_KFBR );
    chainKFBR.SetBranchAddress("isDaughter", isDaughter_KFBR );

    chainKFBR.SetBranchAddress("p", p_KFBR );
    chainKFBR.SetBranchAddress("pT", pT_KFBR );
    chainKFBR.SetBranchAddress("eta", eta_KFBR );
    chainKFBR.SetBranchAddress("phi", phi_KFBR );
    chainKFBR.SetBranchAddress("mass", mass_KFBR );
    chainKFBR.SetBranchAddress("decayLength", decayLength_KFBR );
    chainKFBR.SetBranchAddress("decayLengthXY", decayLengthXY_KFBR );
    chainKFBR.SetBranchAddress("lifeTime", lifeTime_KFBR );
    chainKFBR.SetBranchAddress("r", r_KFBR );
    chainKFBR.SetBranchAddress("rapidity", rapidity_KFBR );
    chainKFBR.SetBranchAddress("theta", theta_KFBR );

    chainKFBR.SetBranchAddress("xErr", xErr_KFBR );
    chainKFBR.SetBranchAddress("yErr", yErr_KFBR );
    chainKFBR.SetBranchAddress("zErr", zErr_KFBR );
    chainKFBR.SetBranchAddress("pXErr", pXErr_KFBR );
    chainKFBR.SetBranchAddress("pYErr", pYErr_KFBR );
    chainKFBR.SetBranchAddress("pZErr", pZErr_KFBR );
    chainKFBR.SetBranchAddress("eErr", eErr_KFBR );
    chainKFBR.SetBranchAddress("sErr", sErr_KFBR );
    chainKFBR.SetBranchAddress("pErr", pErr_KFBR );
    chainKFBR.SetBranchAddress("pTErr", pTErr_KFBR );
    chainKFBR.SetBranchAddress("etaErr", etaErr_KFBR);
    chainKFBR.SetBranchAddress("phiErr", phiErr_KFBR );
    chainKFBR.SetBranchAddress("massErr", massErr_KFBR );
    chainKFBR.SetBranchAddress("decayLengthErr", decayLengthErr_KFBR);
    chainKFBR.SetBranchAddress("decayLengthXYErr", decayLengthXYErr_KFBR );
    chainKFBR.SetBranchAddress("lifeTimeErr", lifeTimeErr_KFBR );
    chainKFBR.SetBranchAddress("rErr", rErr_KFBR );

    //----------------------------------------------------------------------

    TChain chainKFAR(nameOfKFARTree);
    std::cout << "KFInputFile: " << KFInputFile << std::endl;
    chainKFAR.Add(KFInputFile);

    int nTracks_KFAR ;
    int numOfMCEvent_KFAR ;
    bool isAllCovMatOK_KFAR ;

    int id_KFAR[NUM_OF_KFPARTICLES];
    int idMC_KFAR[NUM_OF_KFPARTICLES];
    int pdg_KFAR[NUM_OF_KFPARTICLES];
    float params_KFAR[NUM_OF_KFPARTICLES][6];
    float covMat_KFAR[NUM_OF_KFPARTICLES][36];
    bool isCovMatOK_KFAR[NUM_OF_KFPARTICLES];
    float x_KFAR[NUM_OF_KFPARTICLES];
    float y_KFAR[NUM_OF_KFPARTICLES];
    float z_KFAR[NUM_OF_KFPARTICLES];
    float pX_KFAR[NUM_OF_KFPARTICLES];
    float pY_KFAR[NUM_OF_KFPARTICLES];
    float pZ_KFAR[NUM_OF_KFPARTICLES];
    float e_KFAR[NUM_OF_KFPARTICLES];
    float s_KFAR[NUM_OF_KFPARTICLES];
    int charge_KFAR[NUM_OF_KFPARTICLES];
    float chi2_KFAR[NUM_OF_KFPARTICLES];
    float ndf_KFAR[NUM_OF_KFPARTICLES];
    float massHypo_KFAR[NUM_OF_KFPARTICLES];

    bool isMother_KFAR[NUM_OF_KFPARTICLES];
    bool isDaughter_KFAR[NUM_OF_KFPARTICLES];
    
    float p_KFAR[NUM_OF_KFPARTICLES];
    float pT_KFAR[NUM_OF_KFPARTICLES];
    float eta_KFAR[NUM_OF_KFPARTICLES];
    float phi_KFAR[NUM_OF_KFPARTICLES];
    float mass_KFAR[NUM_OF_KFPARTICLES];
    float decayLength_KFAR[NUM_OF_KFPARTICLES];
    float decayLengthXY_KFAR[NUM_OF_KFPARTICLES];
    float lifeTime_KFAR[NUM_OF_KFPARTICLES];
    float r_KFAR[NUM_OF_KFPARTICLES];
    float rapidity_KFAR[NUM_OF_KFPARTICLES];
    float theta_KFAR[NUM_OF_KFPARTICLES];

    float xErr_KFAR[NUM_OF_KFPARTICLES];
    float yErr_KFAR[NUM_OF_KFPARTICLES];
    float zErr_KFAR[NUM_OF_KFPARTICLES];
    float pXErr_KFAR[NUM_OF_KFPARTICLES];
    float pYErr_KFAR[NUM_OF_KFPARTICLES];
    float pZErr_KFAR[NUM_OF_KFPARTICLES];
    float eErr_KFAR[NUM_OF_KFPARTICLES];
    float sErr_KFAR[NUM_OF_KFPARTICLES];
    float pErr_KFAR[NUM_OF_KFPARTICLES];
    float pTErr_KFAR[NUM_OF_KFPARTICLES];
    float etaErr_KFAR[NUM_OF_KFPARTICLES];
    float phiErr_KFAR[NUM_OF_KFPARTICLES];
    float massErr_KFAR[NUM_OF_KFPARTICLES];
    float decayLengthErr_KFAR[NUM_OF_KFPARTICLES];
    float decayLengthXYErr_KFAR[NUM_OF_KFPARTICLES];
    float lifeTimeErr_KFAR[NUM_OF_KFPARTICLES];
    float rErr_KFAR[NUM_OF_KFPARTICLES];    

	chainKFAR.SetBranchAddress("nTracks", &nTracks_KFAR);
	chainKFAR.SetBranchAddress("numOfMCEvent", &numOfMCEvent_KFAR );
	chainKFAR.SetBranchAddress("isAllCovMatOK", &isAllCovMatOK_KFAR );

    chainKFAR.SetBranchAddress("ID", id_KFAR );
    chainKFAR.SetBranchAddress("IDMC", idMC_KFAR );
	chainKFAR.SetBranchAddress("pdgID", pdg_KFAR);
    chainKFAR.SetBranchAddress("params", params_KFAR );
    chainKFAR.SetBranchAddress("covMat", covMat_KFAR );
    chainKFAR.SetBranchAddress("isCovMatOK", isCovMatOK_KFAR );
    chainKFAR.SetBranchAddress("x", x_KFAR );
    chainKFAR.SetBranchAddress("y", y_KFAR );
    chainKFAR.SetBranchAddress("z", z_KFAR );
    chainKFAR.SetBranchAddress("pX", pX_KFAR );
    chainKFAR.SetBranchAddress("pY", pY_KFAR );
    chainKFAR.SetBranchAddress("pZ", pZ_KFAR );
    chainKFAR.SetBranchAddress("e", e_KFAR );
    chainKFAR.SetBranchAddress("s", s_KFAR );
    chainKFAR.SetBranchAddress("charge", charge_KFAR );
    chainKFAR.SetBranchAddress("chi2", chi2_KFAR );
    chainKFAR.SetBranchAddress("ndf", ndf_KFAR );
    chainKFAR.SetBranchAddress("massHypo", massHypo_KFAR );

    chainKFAR.SetBranchAddress("isMother", isMother_KFAR );
    chainKFAR.SetBranchAddress("isDaughter", isDaughter_KFAR );

    chainKFAR.SetBranchAddress("p", p_KFAR );
    chainKFAR.SetBranchAddress("pT", pT_KFAR );
    chainKFAR.SetBranchAddress("eta", eta_KFAR );
    chainKFAR.SetBranchAddress("phi", phi_KFAR );
    chainKFAR.SetBranchAddress("mass", mass_KFAR );
    chainKFAR.SetBranchAddress("decayLength", decayLength_KFAR );
    chainKFAR.SetBranchAddress("decayLengthXY", decayLengthXY_KFAR );
    chainKFAR.SetBranchAddress("lifeTime", lifeTime_KFAR );
    chainKFAR.SetBranchAddress("r", r_KFAR );
    chainKFAR.SetBranchAddress("rapidity", rapidity_KFAR );
    chainKFAR.SetBranchAddress("theta", theta_KFAR );

    chainKFAR.SetBranchAddress("xErr", xErr_KFAR );
    chainKFAR.SetBranchAddress("yErr", yErr_KFAR );
    chainKFAR.SetBranchAddress("zErr", zErr_KFAR );
    chainKFAR.SetBranchAddress("pXErr", pXErr_KFAR );
    chainKFAR.SetBranchAddress("pYErr", pYErr_KFAR );
    chainKFAR.SetBranchAddress("pZErr", pZErr_KFAR );
    chainKFAR.SetBranchAddress("eErr", eErr_KFAR );
    chainKFAR.SetBranchAddress("sErr", sErr_KFAR );
    chainKFAR.SetBranchAddress("pErr", pErr_KFAR );
    chainKFAR.SetBranchAddress("pTErr", pTErr_KFAR );
    chainKFAR.SetBranchAddress("etaErr", etaErr_KFAR);
    chainKFAR.SetBranchAddress("phiErr", phiErr_KFAR );
    chainKFAR.SetBranchAddress("massErr", massErr_KFAR );
    chainKFAR.SetBranchAddress("decayLengthErr", decayLengthErr_KFAR);
    chainKFAR.SetBranchAddress("decayLengthXYErr", decayLengthXYErr_KFAR );
    chainKFAR.SetBranchAddress("lifeTimeErr", lifeTimeErr_KFAR );
    chainKFAR.SetBranchAddress("rErr", rErr_KFAR );
    ////////////////////////////////////////////////////////////////////////
    ////////////////// end of trees block
    ////////////////////////////////////////////////////////////////////////
    
    ////////////////////////////////////////////////////////////////////////
    ////////////////// START of event loop block
    ////////////////////////////////////////////////////////////////////////

    cout << " Starting event loops\n";

    int nEventsMC = chainMC.GetEntries();
    int nEventsKFBR = chainKFBR.GetEntries();
    int nEventsKFAR = chainKFAR.GetEntries();
    if (nEventsKFBR != nEventsKFAR){
        cout << "nEventsKFBR != nEventsKFAR (" << nEventsKFBR << " != " << nEventsKFAR << ")\n. Quit.";
        return;
    }
    int nEvents = nEventsKFBR;

    // Create MC QA plots
    for (int iEvent = 0; iEvent < nEventsMC; iEvent++){
        chainMC.GetEntry(iEvent);
        // if number of tracks in the event less than
        // number of daughters + number of mother particles - do not process the event
        if (nTracks_MC < NUM_OF_KFPARTICLES)
            continue;
        
        if(iEvent % 1000 == 0) {
            std::cout << "processing " << iEvent << " MC event\r";
            std::cout << std::flush;
        }    

        size_t motherCounter = 0;
        size_t daughterCounter = 0;

        // loop over the tracks
        for (int iTrack = 0; iTrack < nTracks_MC; iTrack++){
            // if we found all daughters and mother - do not process other tracks
            if (daughterCounter >= NUM_OF_DAUGHTERS && motherCounter >= NUM_OF_MOTHERS)
                break;
            if (parentID_MC[iTrack]==0){
                //setup mother particle from MC data and fill some histos
                if (pdg_MC[iTrack] != MOTHER_PDG){
                    cout << "Mother particle's PDGID is not in the set of mothers pdgs... error and skip the event # " << iEvent << endl;
                    break;
                }
                fHistXMotherMC -> Fill(finalX_MC[iTrack]);
                fHistYMotherMC -> Fill(finalY_MC[iTrack]);
                fHistZMotherMC -> Fill(finalZ_MC[iTrack]);
                fHistPxMotherMC -> Fill(finalPX_MC[iTrack]);
                fHistPyMotherMC -> Fill(finalPY_MC[iTrack]);
                fHistPzMotherMC -> Fill(finalPZ_MC[iTrack]);
                fHistChargeMotherMC -> Fill(charge_MC[iTrack]);
                fHistPDGMotherMC -> Fill(pdg_MC[iTrack]);
                fHistPtMotherMC -> Fill(pT(finalPX_MC[iTrack],finalPY_MC[iTrack]));
                fHistOneOverPtMotherMC -> Fill(1./pT(finalPX_MC[iTrack],finalPY_MC[iTrack]));
                fHistPMotherMC -> Fill(p(finalPX_MC[iTrack],finalPY_MC[iTrack], finalPZ_MC[iTrack]));
                fHistEMotherMC -> Fill(e(finalPX_MC[iTrack],finalPY_MC[iTrack],finalPZ_MC[iTrack],mass_MC[iTrack]));
                fHistMassMotherMC -> Fill(mass_MC[iTrack]);
                fHistEtaMotherMC -> Fill(eta(finalPX_MC[iTrack],finalPY_MC[iTrack], finalPZ_MC[iTrack]));
                fHistPhiMotherMC -> Fill(phi(finalPX_MC[iTrack],finalPY_MC[iTrack]));
                //fHistChi2MotherMC -> Fill();

                motherCounter++; 
            }
            if (parentID_MC[iTrack] == 1){
                auto iter_pdg = find (DAUGTHERS_PDGS.begin(), DAUGTHERS_PDGS.end(), pdg_MC[iTrack]);
                if ( iter_pdg == DAUGTHERS_PDGS.end()){
                    cout << "Daughter particle's PDGID is not in the set of daughters pdgs... error and skip the event # " << iEvent << endl;
                    break;
                }
                int daughterNum = distance(DAUGTHERS_PDGS.begin(),iter_pdg);
                // setup daughter particles from MC
                fHistXDaughterMC[daughterNum] -> Fill(initialX_MC[iTrack]);
                fHistYDaughterMC[daughterNum] -> Fill(initialY_MC[iTrack]);
                fHistZDaughterMC[daughterNum] -> Fill(initialZ_MC[iTrack]);
                fHistPxDaughterMC[daughterNum] -> Fill(initialPX_MC[iTrack]);
                fHistPyDaughterMC[daughterNum] -> Fill(initialPY_MC[iTrack]);
                fHistPzDaughterMC[daughterNum] -> Fill(initialPZ_MC[iTrack]);
                fHistChargeDaughterMC[daughterNum] -> Fill(charge_MC[iTrack]);
                fHistPDGDaughterMC[daughterNum] -> Fill(pdg_MC[iTrack]);
                fHistPtDaughterMC[daughterNum] -> Fill(pT(initialPX_MC[iTrack],initialPY_MC[iTrack]));
                fHistOneOverPtDaughterMC[daughterNum] -> Fill(1./pT(initialPX_MC[iTrack],initialPY_MC[iTrack]));
                fHistPDaughterMC[daughterNum] -> Fill(p(initialPX_MC[iTrack],initialPY_MC[iTrack], initialPZ_MC[iTrack]));
                fHistEDaughterMC[daughterNum] -> Fill(e(initialPX_MC[iTrack],initialPY_MC[iTrack],initialPZ_MC[iTrack],mass_MC[iTrack]));
                fHistMassDaughterMC[daughterNum] -> Fill(mass_MC[iTrack]);
                fHistEtaDaughterMC[daughterNum] -> Fill(eta(initialPX_MC[iTrack],initialPY_MC[iTrack], initialPZ_MC[iTrack]));
                fHistPhiDaughterMC[daughterNum] -> Fill(phi(initialPX_MC[iTrack],initialPY_MC[iTrack]));

                daughterCounter++;            
            }
        } // end of track loop

    } // end of MC event loop
    cout << endl;

    // Create KFBR QA plots
    for (int iEvent = 0; iEvent < nEventsKFBR; iEvent++){
        chainKFBR.GetEntry(iEvent);
        // if number of tracks in the event less than
        // number of daughters + number of mother particles - do not process the event
        if (!isAllCovMatOK_KFBR)
            continue;
        if (nTracks_KFBR < NUM_OF_KFPARTICLES)
            continue;
        if(iEvent % 1000 == 0) {
            std::cout << "processing " << iEvent << " KFBR event\r";
            std::cout << std::flush;
        } 

        size_t motherCounter = 0;
        size_t daughterCounter = 0;

        // loop over the tracks
        for (int iTrack = 0; iTrack < nTracks_KFBR; iTrack++){
            // if we found all daughters and mother - do not process other tracks
            if (daughterCounter >= NUM_OF_DAUGHTERS && motherCounter >= NUM_OF_MOTHERS)
                break;
            if (isMother_KFBR[iTrack]){
                //setup mother particle from KFBR data and fill some histos
                if (pdg_KFBR[iTrack] != MOTHER_PDG){
                    cout << "Mother particle's PDGID " << pdg_KFBR[iTrack] << " is not in the set of mothers pdgs... error and skip the event # " << iEvent << endl;
                    break;
                }
                fHistXMotherKFBR -> Fill(x_KFBR[iTrack]);
                fHistYMotherKFBR -> Fill(y_KFBR[iTrack]);
                fHistZMotherKFBR -> Fill(z_KFBR[iTrack]);
                fHistPxMotherKFBR -> Fill(pX_KFBR[iTrack]);
                fHistPyMotherKFBR -> Fill(pY_KFBR[iTrack]);
                fHistPzMotherKFBR -> Fill(pZ_KFBR[iTrack]);
                fHistChargeMotherKFBR -> Fill(charge_KFBR[iTrack]);
                fHistPDGMotherKFBR -> Fill(pdg_KFBR[iTrack]);
                fHistPtMotherKFBR -> Fill(pT(pX_KFBR[iTrack],pY_KFBR[iTrack]));
                fHistOneOverPtMotherKFBR -> Fill(1./pT(pX_KFBR[iTrack],pY_KFBR[iTrack]));
                fHistPMotherKFBR -> Fill(p(pX_KFBR[iTrack],pY_KFBR[iTrack], pZ_KFBR[iTrack]));
                fHistEMotherKFBR -> Fill(e(pX_KFBR[iTrack],pY_KFBR[iTrack],pZ_KFBR[iTrack],mass_KFBR[iTrack]));
                fHistMassMotherKFBR -> Fill(mass_KFBR[iTrack]);
                fHistEtaMotherKFBR -> Fill(eta(pX_KFBR[iTrack],pY_KFBR[iTrack], pZ_KFBR[iTrack]));
                fHistPhiMotherKFBR -> Fill(phi(pX_KFBR[iTrack],pY_KFBR[iTrack]));
                fHistChi2MotherKFBR -> Fill(chi2_KFBR[iTrack]);
                fHistNDFMotherKFBR -> Fill(ndf_KFBR[iTrack]);

                motherCounter++; 
            }
            if (isDaughter_KFBR[iTrack]){
                auto iter_pdg = find (DAUGTHERS_PDGS.begin(), DAUGTHERS_PDGS.end(), pdg_KFBR[iTrack]);
                if ( iter_pdg == DAUGTHERS_PDGS.end()){
                    cout << "Daughter particle's PDGID " << pdg_KFBR[iTrack] << " is not in the set of daughters pdgs... error and skip the event # " << iEvent << endl;
                    break;
                }
                int daughterNum = distance(DAUGTHERS_PDGS.begin(),iter_pdg);
                // setup daughter particles from KFBR
                fHistXDaughterKFBR[daughterNum] -> Fill(x_KFBR[iTrack]);
                fHistYDaughterKFBR[daughterNum] -> Fill(y_KFBR[iTrack]);
                fHistZDaughterKFBR[daughterNum] -> Fill(z_KFBR[iTrack]);
                fHistPxDaughterKFBR[daughterNum] -> Fill(pX_KFBR[iTrack]);
                fHistPyDaughterKFBR[daughterNum] -> Fill(pY_KFBR[iTrack]);
                fHistPzDaughterKFBR[daughterNum] -> Fill(pZ_KFBR[iTrack]);
                fHistChargeDaughterKFBR[daughterNum] -> Fill(charge_KFBR[iTrack]);
                fHistPDGDaughterKFBR[daughterNum] -> Fill(pdg_KFBR[iTrack]);
                fHistPtDaughterKFBR[daughterNum] -> Fill(pT(pX_KFBR[iTrack],pY_KFBR[iTrack]));
                fHistOneOverPtDaughterKFBR[daughterNum] -> Fill(1./pT(pX_KFBR[iTrack],pY_KFBR[iTrack]));
                fHistPDaughterKFBR[daughterNum] -> Fill(p(pX_KFBR[iTrack],pY_KFBR[iTrack], pZ_KFBR[iTrack]));
                fHistEDaughterKFBR[daughterNum] -> Fill(e(pX_KFBR[iTrack],pY_KFBR[iTrack],pZ_KFBR[iTrack],mass_KFBR[iTrack]));
                fHistMassDaughterKFBR[daughterNum] -> Fill(mass_KFBR[iTrack]);
                fHistEtaDaughterKFBR[daughterNum] -> Fill(eta(pX_KFBR[iTrack],pY_KFBR[iTrack], pZ_KFBR[iTrack]));
                fHistPhiDaughterKFBR[daughterNum] -> Fill(phi(pX_KFBR[iTrack],pY_KFBR[iTrack]));
                fHistChi2DaughterKFBR[daughterNum] -> Fill(chi2_KFBR[iTrack]);
                fHistNDFDaughterKFBR[daughterNum] -> Fill(ndf_KFBR[iTrack]);
                
                daughterCounter++;            
            }
        } // end of track loop

    } // end of KFBR event loop
    cout << endl;

        // Create KFAR QA plots
    for (int iEvent = 0; iEvent < nEventsKFAR; iEvent++){
        chainKFAR.GetEntry(iEvent);
        // if number of tracks in the event less than
        // number of daughters + number of mother particles - do not process the event
        if (!isAllCovMatOK_KFAR)
            continue;
        if (nTracks_KFAR < NUM_OF_KFPARTICLES)
            continue;

        if(iEvent % 1000 == 0) {
            std::cout << "processing " << iEvent << " KFAR event\r";
            std::cout << std::flush;
        } 

        size_t motherCounter = 0;
        size_t daughterCounter = 0;

        // loop over the tracks
        for (int iTrack = 0; iTrack < nTracks_KFAR; iTrack++){
            // if we found all daughters and mother - do not process other tracks
            if (daughterCounter >= NUM_OF_DAUGHTERS && motherCounter >= NUM_OF_MOTHERS)
                break;
            if (isMother_KFAR[iTrack]){
                //setup mother particle from KFAR data and fill some histos
                if (pdg_KFAR[iTrack] != MOTHER_PDG){
                    cout << "Mother particle's PDGID " << pdg_KFAR[iTrack] << " is not in the set of mothers pdgs... error and skip the event # " << iEvent << endl;
                    break;
                }

                fHistXMotherKFAR -> Fill(x_KFAR[iTrack]);
                fHistYMotherKFAR -> Fill(y_KFAR[iTrack]);
                fHistZMotherKFAR -> Fill(z_KFAR[iTrack]);
                fHistPxMotherKFAR -> Fill(pX_KFAR[iTrack]);
                fHistPyMotherKFAR -> Fill(pY_KFAR[iTrack]);
                fHistPzMotherKFAR -> Fill(pZ_KFAR[iTrack]);
                fHistChargeMotherKFAR -> Fill(charge_KFAR[iTrack]);
                fHistPDGMotherKFAR -> Fill(pdg_KFAR[iTrack]);
                fHistPtMotherKFAR -> Fill(pT(pX_KFAR[iTrack],pY_KFAR[iTrack]));
                fHistOneOverPtMotherKFAR -> Fill(1./pT(pX_KFAR[iTrack],pY_KFAR[iTrack]));
                fHistPMotherKFAR -> Fill(p(pX_KFAR[iTrack],pY_KFAR[iTrack], pZ_KFAR[iTrack]));
                fHistEMotherKFAR -> Fill(e(pX_KFAR[iTrack],pY_KFAR[iTrack],pZ_KFAR[iTrack],mass_KFAR[iTrack]));
                fHistMassMotherKFAR -> Fill(mass_KFAR[iTrack]);
                fHistEtaMotherKFAR -> Fill(eta(pX_KFAR[iTrack],pY_KFAR[iTrack], pZ_KFAR[iTrack]));
                fHistPhiMotherKFAR -> Fill(phi(pX_KFAR[iTrack],pY_KFAR[iTrack]));
                fHistChi2MotherKFAR -> Fill(chi2_KFAR[iTrack]);
                fHistNDFMotherKFAR -> Fill(ndf_KFAR[iTrack]);

                motherCounter++; 
            }
            if (isDaughter_KFAR[iTrack]){
                auto iter_pdg = find (DAUGTHERS_PDGS.begin(), DAUGTHERS_PDGS.end(), pdg_KFAR[iTrack]);
                if ( iter_pdg == DAUGTHERS_PDGS.end()){
                    cout << "Daughter particle's PDGID " << pdg_KFAR[iTrack] << " is not in the set of daughters pdgs... error and skip the event # " << iEvent << endl;
                    break;
                }
                int daughterNum = distance(DAUGTHERS_PDGS.begin(),iter_pdg);
                // setup daughter particles from KFAR
                fHistXDaughterKFAR[daughterNum] -> Fill(x_KFAR[iTrack]);
                fHistYDaughterKFAR[daughterNum] -> Fill(y_KFAR[iTrack]);
                fHistZDaughterKFAR[daughterNum] -> Fill(z_KFAR[iTrack]);
                fHistPxDaughterKFAR[daughterNum] -> Fill(pX_KFAR[iTrack]);
                fHistPyDaughterKFAR[daughterNum] -> Fill(pY_KFAR[iTrack]);
                fHistPzDaughterKFAR[daughterNum] -> Fill(pZ_KFAR[iTrack]);
                fHistChargeDaughterKFAR[daughterNum] -> Fill(charge_KFAR[iTrack]);
                fHistPDGDaughterKFAR[daughterNum] -> Fill(pdg_KFAR[iTrack]);
                fHistPtDaughterKFAR[daughterNum] -> Fill(pT(pX_KFAR[iTrack],pY_KFAR[iTrack]));
                fHistOneOverPtDaughterKFAR[daughterNum] -> Fill(1./pT(pX_KFAR[iTrack],pY_KFAR[iTrack]));
                fHistPDaughterKFAR[daughterNum] -> Fill(p(pX_KFAR[iTrack],pY_KFAR[iTrack], pZ_KFAR[iTrack]));
                fHistEDaughterKFAR[daughterNum] -> Fill(e(pX_KFAR[iTrack],pY_KFAR[iTrack],pZ_KFAR[iTrack],mass_KFAR[iTrack]));
                fHistMassDaughterKFAR[daughterNum] -> Fill(mass_KFAR[iTrack]);
                fHistEtaDaughterKFAR[daughterNum] -> Fill(eta(pX_KFAR[iTrack],pY_KFAR[iTrack], pZ_KFAR[iTrack]));
                fHistPhiDaughterKFAR[daughterNum] -> Fill(phi(pX_KFAR[iTrack],pY_KFAR[iTrack]));
                fHistChi2DaughterKFAR[daughterNum] -> Fill(chi2_KFAR[iTrack]);
                fHistNDFDaughterKFAR[daughterNum] -> Fill(ndf_KFAR[iTrack]);

                daughterCounter++;            
            }
        } // end of track loop

    } // end of KFAR event loop
    cout << endl;

    // Create Pt dep plots of residuals and pulls
    for (int iEvent = 0; iEvent < nEventsKFAR; iEvent++){
        chainKFAR.GetEntry(iEvent);
        chainMC.GetEntry(numOfMCEvent_KFAR);
        // if number of tracks in the event less than
        // number of daughters + number of mother particles - do not process the event
        if (!isAllCovMatOK_KFAR)
            continue;
        if (nTracks_KFAR < NUM_OF_KFPARTICLES)
            continue;

        size_t motherCounter = 0;
        size_t daughterCounter = 0;

        // loop over the tracks
        for (int iTrack = 0; iTrack < nTracks_KFAR; iTrack++){
            // if we found all daughters and mother - do not process other tracks
            if (daughterCounter >= NUM_OF_DAUGHTERS && motherCounter >= NUM_OF_MOTHERS)
                break;
            if (isMother_KFAR[iTrack]){
                //setup mother particle from KFAR data and fill some histos
                if (pdg_KFAR[iTrack] != MOTHER_PDG){
                    cout << "Mother particle's PDGID " << pdg_KFAR[iTrack] << " is not in the set of mothers pdgs... error and skip the event # " << iEvent << endl;
                    break;
                }
                motherCounter++; 
            }
            if (isDaughter_KFAR[iTrack]){
                auto iter_pdg = find (DAUGTHERS_PDGS.begin(), DAUGTHERS_PDGS.end(), pdg_KFAR[iTrack]);
                if ( iter_pdg == DAUGTHERS_PDGS.end()){
                    cout << "Daughter particle's PDGID " << pdg_KFAR[iTrack] << " is not in the set of daughters pdgs... error and skip the event # " << iEvent << endl;
                    break;
                }
                daughterCounter++;            
            }

            MCParticleStruct mcpart_;
            KFParticleStruct kfpart_;
            int iTrack_MC = idMC_KFAR[iTrack];

            mcpart_.trackID = trackID_MC[iTrack_MC];
            mcpart_.parentID = parentID_MC[iTrack_MC];
            mcpart_.pdg = pdg_MC[iTrack_MC];
            mcpart_.charge = charge_MC[iTrack_MC];
            mcpart_.mass = mass_MC[iTrack_MC];
            mcpart_.isMother = isMother_KFAR[iTrack];
            mcpart_.trackLength = trackLength_MC[iTrack_MC];
            mcpart_.initialX = initialX_MC[iTrack_MC];
            mcpart_.initialY = initialY_MC[iTrack_MC];
            mcpart_.initialZ = initialZ_MC[iTrack_MC];
            mcpart_.finalX = finalX_MC[iTrack_MC];
            mcpart_.finalY = finalY_MC[iTrack_MC];
            mcpart_.finalZ = finalZ_MC[iTrack_MC];
            mcpart_.initialPX = initialPX_MC[iTrack_MC];
            mcpart_.initialPY = initialPY_MC[iTrack_MC];
            mcpart_.initialPZ = initialPZ_MC[iTrack_MC]; 
            mcpart_.finalPX = finalPX_MC[iTrack_MC];
            mcpart_.finalPY = finalPY_MC[iTrack_MC];
            mcpart_.finalPZ = finalPZ_MC[iTrack_MC];  
            ///mcpart_.ndf = 0.;
            ///mcpart_.chi2 = 0.;

            kfpart_.id = iTrack;
            kfpart_.idMC = mcpart_.trackID;
            kfpart_.pdg = pdg_KFAR[iTrack];
            memcpy(kfpart_.params, params_KFAR, sizeof(kfpart_.params));
            memcpy(kfpart_.covMat, covMat_KFAR, sizeof(kfpart_.covMat));
            kfpart_.isCovMatOK = isCovMatOK_KFAR[iTrack];
            kfpart_.x = x_KFAR[iTrack];
            kfpart_.y = y_KFAR[iTrack];
            kfpart_.z = z_KFAR[iTrack];
            kfpart_.pX = pX_KFAR[iTrack];
            kfpart_.pY = pY_KFAR[iTrack];
            kfpart_.pZ = pZ_KFAR[iTrack];
            kfpart_.e = e_KFAR[iTrack];
            kfpart_.s = s_KFAR[iTrack];
            kfpart_.charge = charge_KFAR[iTrack];
            kfpart_.chi2 = chi2_KFAR[iTrack];
            kfpart_.ndf - ndf_KFAR[iTrack];
            kfpart_.massHypo = massHypo_KFAR[iTrack];

            kfpart_.isMother = isMother_KFAR[iTrack];
            kfpart_.isDaughter = isDaughter_KFAR[iTrack];
            
            kfpart_.xErr = xErr_KFAR[iTrack];
            kfpart_.yErr = yErr_KFAR[iTrack];
            kfpart_.zErr = zErr_KFAR[iTrack];
            kfpart_.pXErr = pXErr_KFAR[iTrack];
            kfpart_.pYErr = pYErr_KFAR[iTrack];
            kfpart_.pZErr = pZErr_KFAR[iTrack];
            kfpart_.p = pErr_KFAR[iTrack];
            kfpart_.pT = pT_KFAR[iTrack];
            kfpart_.eta = eta_KFAR[iTrack];
            kfpart_.phi = phi_KFAR[iTrack];
            kfpart_.mass = mass_KFAR[iTrack];
            kfpart_.decayLength = decayLength_KFAR[iTrack];
            kfpart_.decayLengthXY = decayLengthXY_KFAR[iTrack];
            kfpart_.lifeTime = lifeTime_KFAR[iTrack];
            kfpart_.r = r_KFAR[iTrack];
            kfpart_.rapidity = rapidity_KFAR[iTrack];
            kfpart_.theta = theta_KFAR[iTrack];

            kfpart_.eErr = eErr_KFAR[iTrack];
            kfpart_.sErr = sErr_KFAR[iTrack];
            kfpart_.pErr = pErr_KFAR[iTrack];
            kfpart_.pTErr = pTErr_KFAR[iTrack];
            kfpart_.etaErr = etaErr_KFAR[iTrack];
            kfpart_.phiErr = phiErr_KFAR[iTrack];
            kfpart_.massErr = massErr_KFAR[iTrack];
            kfpart_.decayLengthErr = decayLengthErr_KFAR[iTrack];
            kfpart_.decayLengthXYErr = decayLengthXYErr_KFAR[iTrack];
            kfpart_.lifeTimeErr = lifeTimeErr_KFAR[iTrack];
            kfpart_.rErr = rErr_KFAR[iTrack];
            
            for (auto& [name,obj]:output_map.map){
                obj->Fill(mcpart_, kfpart_);
                obj->Fill(kfpart_);
                obj->Fill(mcpart_);
            }
                

        } // end of track loop

    } // end of KFAR event loop

    ////////
    // end of event loop section
    ////

    output_map.PreWriteProcessAll();

    /////////
    //  write all the stuff into output file
    ////
    cout << " Writing output file\n";

    MotherMC_Dir -> cd();
        fHistXMotherMC -> Write();
        fHistYMotherMC -> Write();
        fHistZMotherMC -> Write();
        fHistPxMotherMC -> Write();
        fHistPyMotherMC -> Write();
        fHistPzMotherMC -> Write();
        fHistChargeMotherMC -> Write();
        fHistPDGMotherMC -> Write();
        fHistPtMotherMC -> Write();
        fHistOneOverPtMotherMC -> Write();
        fHistPMotherMC -> Write();    
        fHistEMotherMC -> Write();
        fHistMassMotherMC -> Write();
        fHistEtaMotherMC -> Write();
        fHistPhiMotherMC -> Write();
        fHistChi2MotherMC -> Write();
    
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++) {
        DaughtersMC_Dir[i] -> cd();
            fHistXDaughterMC[i] -> Write();
            fHistYDaughterMC[i] -> Write();
            fHistZDaughterMC[i] -> Write();
            fHistPxDaughterMC[i] -> Write();
            fHistPyDaughterMC[i] -> Write();
            fHistPzDaughterMC[i] -> Write();
            fHistChargeDaughterMC[i] -> Write();
            fHistPDGDaughterMC[i] -> Write();
            fHistPtDaughterMC[i] -> Write();
            fHistOneOverPtDaughterMC[i] -> Write();
            fHistPDaughterMC[i] -> Write(); 
            fHistEDaughterMC[i] -> Write();
            fHistMassDaughterMC[i] -> Write();
            fHistEtaDaughterMC[i] -> Write();
            fHistPhiDaughterMC[i] -> Write();
            fHistChi2DaughterMC[i] -> Write();
    }

    MotherKFBR_Dir -> cd();
        fHistXMotherKFBR -> Write();
        fHistYMotherKFBR -> Write();
        fHistZMotherKFBR -> Write();
        fHistPxMotherKFBR -> Write();
        fHistPyMotherKFBR -> Write();
        fHistPzMotherKFBR -> Write();
        fHistChargeMotherKFBR -> Write();
        fHistPDGMotherKFBR -> Write();
        fHistPtMotherKFBR -> Write();
        fHistOneOverPtMotherKFBR -> Write();
        fHistPMotherKFBR -> Write();    
        fHistEMotherKFBR -> Write();
        fHistMassMotherKFBR -> Write();
        fHistEtaMotherKFBR -> Write();
        fHistPhiMotherKFBR -> Write();
        fHistChi2MotherKFBR -> Write();
        fHistNDFMotherKFBR -> Write();

    for (int i = 0; i < NUM_OF_DAUGHTERS; i++) {
        DaughtersKFBR_Dir[i] -> cd();
            fHistXDaughterKFBR[i] -> Write();
            fHistYDaughterKFBR[i] -> Write();
            fHistZDaughterKFBR[i] -> Write();
            fHistPxDaughterKFBR[i] -> Write();
            fHistPyDaughterKFBR[i] -> Write();
            fHistPzDaughterKFBR[i] -> Write();
            fHistChargeDaughterKFBR[i] -> Write();
            fHistPDGDaughterKFBR[i] -> Write();
            fHistPtDaughterKFBR[i] -> Write();
            fHistOneOverPtDaughterKFBR[i] -> Write();
            fHistPDaughterKFBR[i] -> Write(); 
            fHistEDaughterKFBR[i] -> Write();
            fHistMassDaughterKFBR[i] -> Write();
            fHistEtaDaughterKFBR[i] -> Write();
            fHistPhiDaughterKFBR[i] -> Write();
            fHistChi2DaughterKFBR[i] -> Write();
            fHistNDFDaughterKFBR[i] -> Write();
    }

    MotherKFAR_Dir -> cd();
        fHistXMotherKFAR -> Write();
        fHistYMotherKFAR -> Write();
        fHistZMotherKFAR -> Write();
        fHistPxMotherKFAR -> Write();
        fHistPyMotherKFAR -> Write();
        fHistPzMotherKFAR -> Write();
        fHistChargeMotherKFAR -> Write();
        fHistPDGMotherKFAR -> Write();
        fHistPtMotherKFAR -> Write();
        fHistOneOverPtMotherKFAR -> Write();
        fHistPMotherKFAR -> Write();    
        fHistEMotherKFAR -> Write();
        fHistMassMotherKFAR -> Write();
        fHistEtaMotherKFAR -> Write();
        fHistPhiMotherKFAR -> Write();
        fHistChi2MotherKFAR -> Write();
        fHistNDFMotherKFAR -> Write();

    for (int i = 0; i < NUM_OF_DAUGHTERS; i++) {
        DaughtersKFAR_Dir[i] -> cd();
            fHistXDaughterKFAR[i] -> Write(); //Write("",TObject::kOverwrite);
            fHistYDaughterKFAR[i] -> Write();
            fHistZDaughterKFAR[i] -> Write();
            fHistPxDaughterKFAR[i] -> Write();
            fHistPyDaughterKFAR[i] -> Write();
            fHistPzDaughterKFAR[i] -> Write();
            fHistChargeDaughterKFAR[i] -> Write();
            fHistPDGDaughterKFAR[i] -> Write();
            fHistPtDaughterKFAR[i] -> Write();
            fHistOneOverPtDaughterKFAR[i] -> Write();
            fHistPDaughterKFAR[i] -> Write(); 
            fHistEDaughterKFAR[i] -> Write();
            fHistMassDaughterKFAR[i] -> Write();
            fHistEtaDaughterKFAR[i] -> Write();
            fHistPhiDaughterKFAR[i] -> Write();
            fHistChi2DaughterKFAR[i] -> Write();
            fHistNDFDaughterKFAR[i] -> Write();
    }

    output_map.WriteAll();

    OtherHistos -> cd();
        fHistPtPtErrMother -> Write();

    outputFile.Close();

    cout << endl;
    cout << "The macro is done. Results are saved in " << 
    KFHistoOutputFile << endl;
}
