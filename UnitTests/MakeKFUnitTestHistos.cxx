#include <algorithm>
#include "TDirectory.h"

#include "./ConfigConstants.h"

/////
float pT(float px, float py){return sqrt(px*px+py*py);}
float p(float px, float py, float pz){return sqrt(px*px+py*py+pz*pz);}
float e(float px, float py, float pz, float mass){return sqrt(px*px+py*py+pz*pz+mass*mass);}
float eta(float px, float py, float pz){return 0.5*log((p(px,py,pz)+pz)/(p(px,py,pz)-pz));}
float phi(float px, float py){return atan2(py, px);}
float theta(float px, float py, float pz){return atan2(pT(px,py), pz);}

// ... ADD DESCRIPTION !!!
template<typename T, typename U>
U *MakeIntegatedHistoFromTH2(T fHisto2D);
template<typename T>
TGraphErrors *MakeMeanGraphFromTH2(T fHisto2D);
template<typename T>
TGraphErrors *MakeSigmaGraphFromTH2(T fHisto2D);


void MakeKFUnitTestHistos(){

    cout << "\n Staring MakeKFUnitTestHistos macro \n";

    TFile outputFile( KFHistoOutputFile, "RECREATE" );

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
                
    TDirectory* ResidPtDep_Dir = outputFile.mkdir("ResidPtDependencies");
        TDirectory* MotherResidPtDep_Dir = ResidPtDep_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersResidPtDep_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersResidPtDep_Dir[i] = ResidPtDep_Dir->mkdir(Form("Daughter%i",i+1));
            
    TDirectory* PullPtDep_Dir = outputFile.mkdir("PullPtDependencies");
        TDirectory* MotherPullPtDep_Dir = PullPtDep_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersPullPtDep_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersPullPtDep_Dir[i] = PullPtDep_Dir->mkdir(Form("Daughter%i",i+1));
            
    TDirectory* ResidHistos_Dir = outputFile.mkdir("ResidHistos");
        TDirectory* MotherResidHistos_Dir = ResidHistos_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersResidHistos_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersResidHistos_Dir[i] = ResidHistos_Dir->mkdir(Form("Daughter%i",i+1));

    TDirectory* PullHistos_Dir = outputFile.mkdir("PullHistos");
        TDirectory* MotherPullHistos_Dir = PullHistos_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersPullHistos_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersPullHistos_Dir[i] = PullHistos_Dir->mkdir(Form("Daughter%i",i+1));
             
    TDirectory* MeanResidPtDepPlots_Dir = outputFile.mkdir("MeanResidPtDepPlots");
        TDirectory* MotherMeanResidPtDepPlots_Dir = MeanResidPtDepPlots_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersMeanResidPtDepPlots_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersMeanResidPtDepPlots_Dir[i] = MeanResidPtDepPlots_Dir->mkdir(Form("Daughter%i",i+1));
    
    TDirectory* MeanPullPtDepPlots_Dir = outputFile.mkdir("MeanPullPtDepPlots");
        TDirectory* MotherMeanPullPtDepPlots_Dir = MeanPullPtDepPlots_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersMeanPullPtDepPlots_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersMeanPullPtDepPlots_Dir[i] = MeanPullPtDepPlots_Dir->mkdir(Form("Daughter%i",i+1));
           
    TDirectory* ResolPtDepPlots_Dir = outputFile.mkdir("ResolPtDepPlots");
        TDirectory* MotherResolPtDepPlots_Dir = ResolPtDepPlots_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersResolPtDepPlots_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersResolPtDepPlots_Dir[i] = ResolPtDepPlots_Dir->mkdir(Form("Daughter%i",i+1));
            
    TDirectory* PullWidthPtDepPlots_Dir = outputFile.mkdir("PullWidthPtDepPlots");
        TDirectory* MotherPullWidthPtDepPlots_Dir = PullWidthPtDepPlots_Dir->mkdir("Mother");
        std::array<TDirectory*, NUM_OF_DAUGHTERS> DaughtersPullWidthPtDepPlots_Dir;
            for (int i = 0; i < NUM_OF_DAUGHTERS; i++)
                DaughtersPullWidthPtDepPlots_Dir[i] = PullWidthPtDepPlots_Dir->mkdir(Form("Daughter%i",i+1));
            
    //TDirectory*  = outputFile.mkdir("OtherHistosAndPlots");
    TDirectory* OtherHistos = outputFile.mkdir("OtherHistosAndPlots");
        
        
    ////////////////////////////////////////////////////////
    ////////////// end of structure block
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    ////////////// Beginning of histograms block
    ////////////////////////////////////////////////////////

    TH1F *fHistXMotherMC = new TH1F("fHistXMotherMC", "X MC; x, #mu; counts", 1000, -1e5, 1e5);
    TH1F *fHistYMotherMC = new TH1F("fHistYMotherMC", "Y MC; y, #mu; counts",1000, -1e5, 1e5);
    TH1F *fHistZMotherMC = new TH1F("fHistZMotherMC", "Z MC; z, #mu; counts",1000, -3e5, 3e5);
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
    TH1F *fHistChi2MotherMC = new TH1F("fHistChi2MotherMC", "Chi2 MC; #xi^{2}; counts",1000, -10, 10);
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
        fHistXDaughterMC[i] = new TH1F(Form("fHistXDaughterMC%i",i+1), "X MC; x, #mu; counts", 1000, -1e5, 1e5);
        fHistYDaughterMC[i] = new TH1F(Form("fHistYDaughterMC%i",i+1), "Y MC; y, #mu; counts",1000, -1e5, 1e5);
        fHistZDaughterMC[i] = new TH1F(Form("fHistZDaughterMC%i",i+1), "Z MC; z, #mu; counts",1000, -3e5, 3e5);
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

    TH1F *fHistXMotherKFBR = new TH1F("fHistXMotherKFBR", "X KFBR; x, #mu; counts", 1000, -1e5, 1e5);
    TH1F *fHistYMotherKFBR = new TH1F("fHistYMotherKFBR", "Y KFBR; y, #mu; counts",1000, -1e5, 1e5);
    TH1F *fHistZMotherKFBR = new TH1F("fHistZMotherKFBR", "Z KFBR; z, #mu; counts",1000, -3e5, 3e5);
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
        fHistXDaughterKFBR[i] = new TH1F(Form("fHistXDaughterKFBR%i",i+1), "X KFBR; x, #mu; counts", 1000, -1e5, 1e5);
        fHistYDaughterKFBR[i] = new TH1F(Form("fHistYDaughterKFBR%i",i+1), "Y KFBR; y, #mu; counts",1000, -1e5, 1e5);
        fHistZDaughterKFBR[i] = new TH1F(Form("fHistZDaughterKFBR%i",i+1), "Z KFBR; z, #mu; counts",1000, -3e5, 3e5);
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
        fHistChi2DaughterKFBR[i] = new TH1F(Form("fHistChi2DaughterKFBR%i",i+1), "Chi2 KFBR; #chi2^{2}; counts",1000, -10, 10);
        fHistNDFDaughterKFBR[i] = new TH1F(Form("fHistNDFDaughterKFBR%i",i+1), "NDF KFBR; NDF; counts",1000, -10, 10);
    }

    TH1F *fHistXMotherKFAR = new TH1F("fHistXMotherKFAR", "X KFAR; x, #mu; counts", 1000, -1e5, 1e5);
    TH1F *fHistYMotherKFAR = new TH1F("fHistYMotherKFAR", "Y KFAR; y, #mu; counts",1000, -1e5, 1e5);
    TH1F *fHistZMotherKFAR = new TH1F("fHistZMotherKFAR", "Z KFAR; z, #mu; counts",1000, -3e5, 3e5);
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
        fHistXDaughterKFAR[i] = new TH1F(Form("fHistXDaughterKFAR%i",i+1), "X KFAR; x, #mu; counts", 1000, -1e5, 1e5);
        fHistYDaughterKFAR[i] = new TH1F(Form("fHistYDaughterKFAR%i",i+1), "Y KFAR; y, #mu; counts",1000, -1e5, 1e5);
        fHistZDaughterKFAR[i] = new TH1F(Form("fHistZDaughterKFAR%i",i+1), "Z KFAR; z, #mu; counts",1000, -3e5, 3e5);
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
        fHistChi2DaughterKFAR[i] = new TH1F(Form("fHistChi2DaughterKFAR%i",i+1), "Chi2 KFAR; #xi^{2}; counts",1000, -10, 10);
        fHistNDFDaughterKFAR[i] = new TH1F(Form("fHistNDFDaughterKFAR%i",i+1), "NDF KFAR; NDF; counts",1000, -10, 10);
    }

    /////////

    TH2F *fHistPtXResidMother = new TH2F("fHistPtXResidMother", "Pt-X Resid histo; p_{T}, GeV; X residual, #mu",50,0,15, 100,-1e3,1e3);
    TH2F *fHistPtYResidMother = new TH2F("fHistPtYResidMother", "Pt-Y Resid histo; p_{T}, GeV; Y residual, #mu",50,0,15, 100,-1e3,1e3);
    TH2F *fHistPtZResidMother = new TH2F("fHistPtZResidMother", "Pt-Z Resid histo; p_{T}, GeV; Z residual, #mu",50,0,15, 100,-1e3,1e3);
    TH2F *fHistPtPxResidMother = new TH2F("fHistPtPxResidMother", "Pt-Px Resid histo; p_{T}, GeV; Px residual, GeV",50,0,10, 50,-0.1,0.1);
    TH2F *fHistPtPyResidMother = new TH2F("fHistPtPyResidMother", "Pt-Py Resid histo; p_{T}, GeV; Py residual, GeV",50,0,10, 50,-0.1,0.1);
    TH2F *fHistPtPzResidMother = new TH2F("fHistPtPzResidMother", "Pt-Pz Resid histo; p_{T}, GeV; Pz residual, GeV",50,0,10, 50,-0.1,0.1);
    TH2F *fHistPtPtResidMother = new TH2F("fHistPtPtResidMother", "Pt-Pt Resid histo; p_{T}, GeV; Pt residual, GeV",50,0,10, 50,-0.1,0.1);
    TH2F *fHistPtMassResidMother = new TH2F("fHistPtMassResidMother", "Pt-Mass Resid histo; p_{T}, GeV; Mass residual, GeV",50,0,10, 50,-0.1,0.1);
    TH2F *fHistPtEResidMother = new TH2F("fHistPtEResidMother", "Pt-E Resid histo; p_{T}, GeV; E residual, GeV",50,0,10, 50,-0.1,0.1);
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtXResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtYResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtZResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPxResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPyResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPzResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPtResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtMassResidDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtEResidDaughter;
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistPtXResidDaughter[i] = new TH2F(Form("fHistPtXResidDaughter%i",i), "Pt-X Resid histo; p_{T}, GeV; X residual, #mu",50,0,15, 100,-1e3,1e3);
        fHistPtYResidDaughter[i] = new TH2F(Form("fHistPtYResidDaughter%i",i), "Pt-Y Resid histo; p_{T}, GeV; Y residual, #mu",50,0,15, 100,-1e3,1e3);
        fHistPtZResidDaughter[i] = new TH2F(Form("fHistPtZResidDaughter%i",i), "Pt-Z Resid histo; p_{T}, GeV; Z residual, #mu",50,0,15, 100,-1e3,1e3);
        fHistPtPxResidDaughter[i] = new TH2F(Form("fHistPtPxResidDaughter%i",i), "Pt-Px Resid histo; p_{T}, GeV; Px residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtPyResidDaughter[i] = new TH2F(Form("fHistPtPyResidDaughter%i",i), "Pt-Py Resid histo; p_{T}, GeV; Py residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtPzResidDaughter[i] = new TH2F(Form("fHistPtPzResidDaughter%i",i), "Pt-Pz Resid histo; p_{T}, GeV; Pz residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtPtResidDaughter[i] = new TH2F(Form("fHistPtPtResidDaughter%i",i), "Pt-Pt Resid histo; p_{T}, GeV; Pt residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtMassResidDaughter[i] = new TH2F(Form("fHistPtMassResidDaughter%i",i), "Pt-Mass Resid histo; p_{T}, GeV; Mass residual, GeV",50,0,10, 50,-0.1,0.1);
        fHistPtEResidDaughter[i] = new TH2F("fHistPtEResidMother", "Pt-E Resid histo; p_{T}, GeV; E residual, GeV",50,0,10, 50,-0.1,0.1);
    }

    //////////////////

    TH2F *fHistPtXPullMother = new TH2F("fHistPtXPullMother", "Pt-X Pull histo; p_{T}, GeV; X Pull, #mu",50,0,15, 100,-10,10);
    TH2F *fHistPtYPullMother = new TH2F("fHistPtYPullMother", "Pt-Y Pull histo; p_{T}, GeV; Y Pull, #mu",50,0,15, 100,-10,10);
    TH2F *fHistPtZPullMother = new TH2F("fHistPtZPullMother", "Pt-Z Pull histo; p_{T}, GeV; Z Pull, #mu",50,0,15, 100,-10,10);
    TH2F *fHistPtPxPullMother = new TH2F("fHistPtPxPullMother", "Pt-Px Pull histo; p_{T}, GeV; Px Pull, GeV",50,0,10, 50,-15,15);
    TH2F *fHistPtPyPullMother = new TH2F("fHistPtPyPullMother", "Pt-Py Pull histo; p_{T}, GeV; Py Pull, GeV",50,0,10, 50,-15,15);
    TH2F *fHistPtPzPullMother = new TH2F("fHistPtPzPullMother", "Pt-Pz Pull histo; p_{T}, GeV; Pz Pull, GeV",50,0,10, 50,-15,15);
    TH2F *fHistPtPtPullMother = new TH2F("fHistPtPtPullMother", "Pt-Pt Pull histo; p_{T}, GeV; Pt Pull, GeV",50,0,10, 50,-15,15);
    TH2F *fHistPtMassPullMother = new TH2F("fHistPtMassPullMother", "Pt-Mass Pull histo; p_{T}, GeV; Mass Pull, GeV",50,0,10, 50,-5,5);
    TH2F *fHistPtEPullMother = new TH2F("fHistPtEPullMother", "Pt-E Pull histo; p_{T}, GeV; E Pull, GeV",50,0,10, 50,-15,15);
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtXPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtYPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtZPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPxPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPyPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPzPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtPtPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtMassPullDaughter;
    std::array<TH2F*, NUM_OF_DAUGHTERS> fHistPtEPullDaughter;
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistPtXPullDaughter[i] = new TH2F(Form("fHistPtXPullDaughter%i",i), "Pt-X Pull histo; p_{T}, GeV; X Pull, #mu",50,0,15, 100,-10,10);
        fHistPtYPullDaughter[i] = new TH2F(Form("fHistPtYPullDaughter%i",i), "Pt-Y Pull histo; p_{T}, GeV; Y Pull, #mu",50,0,15, 100,-10,10);
        fHistPtZPullDaughter[i] = new TH2F(Form("fHistPtZPullDaughter%i",i), "Pt-Z Pull histo; p_{T}, GeV; Z Pull, #mu",50,0,15, 100,-10,10);
        fHistPtPxPullDaughter[i] = new TH2F(Form("fHistPtPxPullDaughter%i",i), "Pt-Px Pull histo; p_{T}, GeV; Px Pull, GeV",50,0,10, 50,-15,15);
        fHistPtPyPullDaughter[i] = new TH2F(Form("fHistPtPyPullDaughter%i",i), "Pt-Py Pull histo; p_{T}, GeV; Py Pull, GeV",50,0,10, 50,-15,15);
        fHistPtPzPullDaughter[i] = new TH2F(Form("fHistPtPzPullDaughter%i",i), "Pt-Pz Pull histo; p_{T}, GeV; Pz Pull, GeV",50,0,10, 50,-15,15);
        fHistPtPtPullDaughter[i] = new TH2F(Form("fHistPtPtPullDaughter%i",i), "Pt-Pt Pull histo; p_{T}, GeV; Pt Pull, GeV",50,0,10, 50,-15,15);
        fHistPtMassPullDaughter[i] = new TH2F(Form("fHistPtMassPullDaughter%i",i), "Pt-Mass Pull histo; p_{T}, GeV; Mass Pull, GeV",50,0,10, 50,-0.4,0.4);
        fHistPtEPullDaughter[i] = new TH2F("fHistPtEPullMother", "Pt-E Pull histo; p_{T}, GeV; E Pull, GeV",50,0,10, 50,-15,15);
    }


    /////////////

    TH1D *fHistXResidMother = new TH1D("fHistXResidMother", "X Resid histo; X Resid, #mu; counts",100,-1e3,1e3);
    TH1D *fHistYResidMother = new TH1D("fHistYResidMother", "Y Resid histo; Y Resid, #mu; counts", 100,-1e3,1e3);
    TH1D *fHistZResidMother = new TH1D("fHistZResidMother", "Z Resid histo; Z Resid, #mu; counts", 100,-1e3,1e3);
    TH1D *fHistPxResidMother = new TH1D("fHistPxResidMother", "Px Resid histo; Px Resid, GeV; counts", 50,-0.15,0.15);
    TH1D *fHistPyResidMother = new TH1D("fHistPyResidMother", "Py Resid histo; Py Resid, GeV; counts", 50,-0.15,0.15);
    TH1D *fHistPzResidMother = new TH1D("fHistPzResidMother", "Pz Resid histo; Pz Resid, GeV; counts", 50,-0.15,0.15);
    TH1D *fHistPtResidMother = new TH1D("fHistPtResidMother", "Pt - Resid histo; Pt Resid, GeV; counts", 50,-0.15,0.15);
    TH1D *fHistMassResidMother = new TH1D("fHistMassResidMother", "Mass Resid histo; Mass Resid, GeV; counts", 50,-0.15,0.15);
    TH1D *fHistEResidMother = new TH1D("fHistEResidMother", "E Resid histo; E Resid, GeV; counts", 50,-0.15,0.15);
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistXResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistYResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistZResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPxResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPyResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPzResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPtResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistMassResidDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistEResidDaughter;
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistXResidDaughter[i] = new TH1D(Form("fHistXResidDaughter%i",i), "X Resid histo; X Resid, #mu; counts", 100,-1e3,1e3);
        fHistYResidDaughter[i] = new TH1D(Form("fHistYResidDaughter%i",i), "Y Resid histo; Y Resid, #mu; counts",100,-1e3,1e3);
        fHistZResidDaughter[i] = new TH1D(Form("fHistZResidDaughter%i",i), "Z Resid histo; Z Resid, #mu; counts", 100,-1e3,1e3);
        fHistPxResidDaughter[i] = new TH1D(Form("fHistPxResidDaughter%i",i), "Px Resid histo; Px Resid, GeV; counts",50,-0.15,0.15);
        fHistPyResidDaughter[i] = new TH1D(Form("fHistPyResidDaughter%i",i), "Py Resid histo; Py Resid, GeV; counts", 50,-0.15,0.15);
        fHistPzResidDaughter[i] = new TH1D(Form("fHistPzResidDaughter%i",i), "Pz Resid histo; Pz Resid, GeV; counts",50,-0.15,0.15);
        fHistPtResidDaughter[i] = new TH1D(Form("fHistPtResidDaughter%i",i), "Pt Resid histo;  Resid, GeV; counts",50,-0.15,0.15);
        fHistMassResidDaughter[i] = new TH1D(Form("fHistMassResidDaughter%i",i), "Mass Resid histo; Mass Resid, GeV; counts",50,-0.15,0.15);
        fHistEResidDaughter[i] = new TH1D(Form("fHistEResidDaughter%i",i), "E Resid histo; E Resid, GeV; counts",50,-0.15,0.15);
    }

    /////////////

    TH1D *fHistXPullMother = new TH1D("fHistXPullMother", "X Pull histo; X Pull, #mu; counts",100,-1e3,1e3);
    TH1D *fHistYPullMother = new TH1D("fHistYPullMother", "Y Pull histo; Y Pull, #mu; counts",100,-1e3,1e3);
    TH1D *fHistZPullMother = new TH1D("fHistZPullMother", "Z Pull histo; Z Pull, #mu; counts",100,-1e3,1e3);
    TH1D *fHistPxPullMother = new TH1D("fHistPxPullMother", "Px Pull histo; Px Pull, GeV; counts",50,-0.15,0.15);
    TH1D *fHistPyPullMother = new TH1D("fHistPyPullMother", "Py Pull histo; Py Pull, GeV; counts",50,-0.15,0.15);
    TH1D *fHistPzPullMother = new TH1D("fHistPzPullMother", "Pz Pull histo; Pz Pull, GeV; counts",50,-0.15,0.15);
    TH1D *fHistPtPullMother = new TH1D("fHistPtPullMother", "Pt - Pull histo; Pt Pull, GeV; counts",50,-0.15,0.15);
    TH1D *fHistMassPullMother = new TH1D("fHistMassPullMother", "Mass Pull histo; Mass Pull, GeV; counts",50,-0.15,0.15);
    TH1D *fHistEPullMother = new TH1D("fHistEPullMother", "E Pull histo; E Pull, GeV; counts",50,-0.15,0.15);
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistXPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistYPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistZPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPxPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPyPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPzPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistPtPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistMassPullDaughter;
    std::array<TH1D*, NUM_OF_DAUGHTERS> fHistEPullDaughter;
    for (int i = 0; i < NUM_OF_DAUGHTERS; i++){
        fHistXPullDaughter[i] = new TH1D(Form("fHistXPullDaughter%i",i), "X Pull histo; X Pull, #mu; counts",100,-1e3,1e3);
        fHistYPullDaughter[i] = new TH1D(Form("fHistYPullDaughter%i",i), "Y Pull histo; Y Pull, #mu; counts",100,-1e3,1e3);
        fHistZPullDaughter[i] = new TH1D(Form("fHistZPullDaughter%i",i), "Z Pull histo; Z Pull, #mu; counts",100,-1e3,1e3);
        fHistPxPullDaughter[i] = new TH1D(Form("fHistPxPullDaughter%i",i), "Px Pull histo; Px Pull, GeV; counts",50,-0.15,0.15);
        fHistPyPullDaughter[i] = new TH1D(Form("fHistPyPullDaughter%i",i), "Py Pull histo; Py Pull, GeV; counts",50,-0.15,0.15);
        fHistPzPullDaughter[i] = new TH1D(Form("fHistPzPullDaughter%i",i), "Pz Pull histo; Pz Pull, GeV; counts",50,-0.15,0.15);
        fHistPtPullDaughter[i] = new TH1D(Form("fHistPtPullDaughter%i",i), "Pt Pull histo;  Pull, GeV; counts",50,-0.15,0.15);
        fHistMassPullDaughter[i] = new TH1D(Form("fHistMassPullDaughter%i",i), "Mass Pull histo; Mass Pull, GeV; counts",50,-0.15,0.15);
        fHistEPullDaughter[i] = new TH1D(Form("fHistEPullDaughter%i",i), "E Pull histo; E Pull, GeV; counts",50,-0.15,0.15);
    }

    ///////////////////////////////////////////////////////////////

    TGraphErrors *fGraphPtXMeanResidMother = new TGraphErrors();
    TGraphErrors *fGraphPtYMeanResidMother = new TGraphErrors();
    TGraphErrors *fGraphPtZMeanResidMother = new TGraphErrors();
    TGraphErrors *fGraphPtPxMeanResidMother = new TGraphErrors();
    TGraphErrors *fGraphPtPyMeanResidMother = new TGraphErrors();
    TGraphErrors *fGraphPtPzMeanResidMother = new TGraphErrors();
    TGraphErrors *fGraphPtPtMeanResidMother = new TGraphErrors();
    TGraphErrors *fGraphPtMassMeanResidMother = new TGraphErrors();
    TGraphErrors *fGraphPtEMeanResidMother = new TGraphErrors();
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtXMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtYMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtZMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPxMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPyMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPzMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPtMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtMassMeanResidDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtEMeanResidDaughter;
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

    ///////////////////////////////////////////////////////////////

    TGraphErrors *fGraphPtXMeanPullMother = new TGraphErrors();
    TGraphErrors *fGraphPtYMeanPullMother = new TGraphErrors();
    TGraphErrors *fGraphPtZMeanPullMother = new TGraphErrors();
    TGraphErrors *fGraphPtPxMeanPullMother = new TGraphErrors();
    TGraphErrors *fGraphPtPyMeanPullMother = new TGraphErrors();
    TGraphErrors *fGraphPtPzMeanPullMother = new TGraphErrors();
    TGraphErrors *fGraphPtPtMeanPullMother = new TGraphErrors();
    TGraphErrors *fGraphPtMassMeanPullMother = new TGraphErrors();
    TGraphErrors *fGraphPtEMeanPullMother = new TGraphErrors();
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtXMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtYMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtZMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPxMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPyMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPzMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPtMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtMassMeanPullDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtEMeanPullDaughter;
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

    ///////////////////////////////////////////////////////////////

    TGraphErrors *fGraphPtXResolMother = new TGraphErrors();
    TGraphErrors *fGraphPtYResolMother = new TGraphErrors();
    TGraphErrors *fGraphPtZResolMother = new TGraphErrors();
    TGraphErrors *fGraphPtPxResolMother = new TGraphErrors();
    TGraphErrors *fGraphPtPyResolMother = new TGraphErrors();
    TGraphErrors *fGraphPtPzResolMother = new TGraphErrors();
    TGraphErrors *fGraphPtPtResolMother = new TGraphErrors();
    TGraphErrors *fGraphPtMassResolMother = new TGraphErrors();
    TGraphErrors *fGraphPtEResolMother = new TGraphErrors();
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtXResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtYResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtZResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPxResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPyResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPzResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPtResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtMassResolDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtEResolDaughter;
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

    ///////////////////////////////////////////////////////////////

    TGraphErrors *fGraphPtXPullWidthMother = new TGraphErrors();
    TGraphErrors *fGraphPtYPullWidthMother = new TGraphErrors();
    TGraphErrors *fGraphPtZPullWidthMother = new TGraphErrors();
    TGraphErrors *fGraphPtPxPullWidthMother = new TGraphErrors();
    TGraphErrors *fGraphPtPyPullWidthMother = new TGraphErrors();
    TGraphErrors *fGraphPtPzPullWidthMother = new TGraphErrors();
    TGraphErrors *fGraphPtPtPullWidthMother = new TGraphErrors();
    TGraphErrors *fGraphPtMassPullWidthMother = new TGraphErrors();
    TGraphErrors *fGraphPtEPullWidthMother = new TGraphErrors();
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtXPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtYPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtZPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPxPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPyPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPzPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtPtPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtMassPullWidthDaughter;
    std::array<TGraphErrors*, NUM_OF_DAUGHTERS> fGraphPtEPullWidthDaughter;
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
    float pdgLifeTime_MC[MAX_NUM_OF_TRACKS];
    int charge_MC[MAX_NUM_OF_TRACKS];
    float trackX_MC[MAX_NUM_OF_TRACKS];
    float trackY_MC[MAX_NUM_OF_TRACKS];
    float trackZ_MC[MAX_NUM_OF_TRACKS];
    float vertexX_MC[MAX_NUM_OF_TRACKS];
    float vertexY_MC[MAX_NUM_OF_TRACKS];
    float vertexZ_MC[MAX_NUM_OF_TRACKS];
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
    chainMC.SetBranchAddress( "pdgLifeTime", pdgLifeTime_MC);
    chainMC.SetBranchAddress( "charge", charge_MC);
    chainMC.SetBranchAddress( "trackX", trackX_MC);
    chainMC.SetBranchAddress( "trackY", trackY_MC);
    chainMC.SetBranchAddress( "trackZ", trackZ_MC);
    chainMC.SetBranchAddress( "vertexX", vertexX_MC);
    chainMC.SetBranchAddress( "vertexY", vertexY_MC);
    chainMC.SetBranchAddress( "vertexZ", vertexZ_MC);
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

                fHistXMotherMC -> Fill(trackX_MC[iTrack]);
                fHistYMotherMC -> Fill(trackY_MC[iTrack]);
                fHistZMotherMC -> Fill(trackZ_MC[iTrack]);
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
                fHistXDaughterMC[daughterNum] -> Fill(vertexX_MC[iTrack]);
                fHistYDaughterMC[daughterNum] -> Fill(vertexY_MC[iTrack]);
                fHistZDaughterMC[daughterNum] -> Fill(vertexZ_MC[iTrack]);
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
                int iTrack_MC = idMC_KFAR[iTrack];
                float pt_MC_ = pT(finalPX_MC[iTrack_MC],finalPY_MC[iTrack_MC]);
                float pt_KFAR_ = pT(pX_KFAR[iTrack],pY_KFAR[iTrack]);
                float e_MC_ = e(finalPX_MC[iTrack_MC],finalPY_MC[iTrack_MC],finalPZ_MC[iTrack_MC],mass_MC[iTrack_MC]);

                float x_resid_ = trackX_MC[iTrack_MC] - x_KFAR[iTrack];
                float y_resid_ = trackY_MC[iTrack_MC] - y_KFAR[iTrack];
                float z_resid_ = trackZ_MC[iTrack_MC] - z_KFAR[iTrack];
                float px_resid_ = finalPX_MC[iTrack_MC] - pX_KFAR[iTrack];
                float py_resid_ = finalPY_MC[iTrack_MC] - pY_KFAR[iTrack];
                float pz_resid_ = finalPZ_MC[iTrack_MC] - pZ_KFAR[iTrack];
                float pt_resid_ = pt_MC_ - pT_KFAR[iTrack];
                float mass_resid_ = mass_MC[iTrack_MC] - mass_KFAR[iTrack];
                float e_resid_ = e_MC_ - e_KFAR[iTrack];

                float x_pull_ = x_resid_/xErr_KFAR[iTrack];
                float y_pull_ = y_resid_/yErr_KFAR[iTrack];
                float z_pull_ = z_resid_/zErr_KFAR[iTrack];
                float px_pull_ = px_resid_/pXErr_KFAR[iTrack];
                float py_pull_ = py_resid_/pYErr_KFAR[iTrack];
                float pz_pull_ = pz_resid_/pZErr_KFAR[iTrack];
                float pt_pull_ = pt_resid_/pTErr_KFAR[iTrack];
                float mass_pull_ = mass_resid_/massErr_KFAR[iTrack];
                float e_pull_ = e_resid_/eErr_KFAR[iTrack];

                fHistPtXResidMother -> Fill(pt_MC_,x_resid_);
                fHistPtYResidMother -> Fill(pt_MC_,y_resid_);
                fHistPtZResidMother -> Fill(pt_MC_,z_resid_);
                fHistPtPxResidMother -> Fill(pt_MC_,px_resid_);
                fHistPtPyResidMother -> Fill(pt_MC_,py_resid_);
                fHistPtPzResidMother -> Fill(pt_MC_,pz_resid_);
                fHistPtPtResidMother -> Fill(pt_MC_,pt_resid_);
                fHistPtMassResidMother -> Fill(pt_MC_,mass_resid_);
                fHistPtEResidMother -> Fill(pt_MC_,e_resid_);

                fHistPtXPullMother -> Fill(pt_MC_,x_pull_);
                fHistPtYPullMother -> Fill(pt_MC_,y_pull_);
                fHistPtZPullMother -> Fill(pt_MC_,z_pull_);
                fHistPtPxPullMother -> Fill(pt_MC_,px_pull_);
                fHistPtPyPullMother -> Fill(pt_MC_,py_pull_);
                fHistPtPzPullMother -> Fill(pt_MC_,pz_pull_);
                fHistPtPtPullMother -> Fill(pt_MC_,pt_pull_);
                fHistPtMassPullMother -> Fill(pt_MC_,mass_pull_);
                fHistPtEPullMother -> Fill(pt_MC_,e_pull_);

                fHistPtPtErrMother -> Fill(pt_MC_, pTErr_KFAR[iTrack]);

                motherCounter++; 
            }
            if (isDaughter_KFAR[iTrack]){
                auto iter_pdg = find (DAUGTHERS_PDGS.begin(), DAUGTHERS_PDGS.end(), pdg_KFAR[iTrack]);
                if ( iter_pdg == DAUGTHERS_PDGS.end()){
                    cout << "Daughter particle's PDGID " << pdg_KFAR[iTrack] << " is not in the set of daughters pdgs... error and skip the event # " << iEvent << endl;
                    break;
                }
                //int daughterNum = distance(DAUGTHERS_PDGS.begin(),iter_pdg);
                int daughterNum = daughterCounter;
                // setup daughter particles from KFAR
                int iTrack_MC = idMC_KFAR[iTrack];
                float pt_MC_ = pT(finalPX_MC[iTrack_MC],finalPY_MC[iTrack_MC]);
                //float pt_KFAR_ = pT(pX_KFAR[iTrack],pY_KFAR[iTrack]);
                float e_MC_ = e(initialPX_MC[iTrack_MC],initialPY_MC[iTrack_MC],initialPZ_MC[iTrack_MC],mass_MC[iTrack_MC]);

                float x_resid_ = vertexX_MC[iTrack_MC] - x_KFAR[iTrack];
                float y_resid_ = vertexY_MC[iTrack_MC] - y_KFAR[iTrack];
                float z_resid_ = vertexZ_MC[iTrack_MC] - z_KFAR[iTrack];
                float px_resid_ = initialPX_MC[iTrack_MC] - pX_KFAR[iTrack];
                float py_resid_ = initialPY_MC[iTrack_MC] - pY_KFAR[iTrack];
                float pz_resid_ = initialPZ_MC[iTrack_MC] - pZ_KFAR[iTrack];
                float pt_resid_ = pt_MC_ - pT_KFAR[iTrack];// pt_KFAR_;
                float mass_resid_ = mass_MC[iTrack_MC] - mass_KFAR[iTrack];
                float e_resid_ = e_MC_ - e_KFAR[iTrack];
                

                float x_pull_ = x_resid_/xErr_KFAR[iTrack];
                float y_pull_ = y_resid_/yErr_KFAR[iTrack];
                float z_pull_ = z_resid_/zErr_KFAR[iTrack];
                float px_pull_ = px_resid_/pXErr_KFAR[iTrack];
                float py_pull_ = py_resid_/pYErr_KFAR[iTrack];
                float pz_pull_ = pz_resid_/pZErr_KFAR[iTrack];
                float pt_pull_ = pt_resid_/pTErr_KFAR[iTrack];
                float mass_pull_ = mass_resid_/massErr_KFAR[iTrack];
                float e_pull_ = e_resid_/eErr_KFAR[iTrack];

                fHistPtXResidDaughter[daughterNum] -> Fill(pt_MC_,x_resid_);
                fHistPtYResidDaughter[daughterNum] -> Fill(pt_MC_,y_resid_);
                fHistPtZResidDaughter[daughterNum] -> Fill(pt_MC_,z_resid_);
                fHistPtPxResidDaughter[daughterNum] -> Fill(pt_MC_,px_resid_);
                fHistPtPyResidDaughter[daughterNum] -> Fill(pt_MC_,py_resid_);
                fHistPtPzResidDaughter[daughterNum] -> Fill(pt_MC_,pz_resid_);
                fHistPtPtResidDaughter[daughterNum] -> Fill(pt_MC_,pt_resid_);
                fHistPtMassResidDaughter[daughterNum] -> Fill(pt_MC_,mass_resid_);
                fHistPtEResidDaughter[daughterNum] -> Fill(pt_MC_,e_resid_);

                fHistPtXPullDaughter[daughterNum] -> Fill(pt_MC_,x_pull_);
                fHistPtYPullDaughter[daughterNum] -> Fill(pt_MC_,y_pull_);
                fHistPtZPullDaughter[daughterNum] -> Fill(pt_MC_,z_pull_);
                fHistPtPxPullDaughter[daughterNum] -> Fill(pt_MC_,px_pull_);
                fHistPtPyPullDaughter[daughterNum] -> Fill(pt_MC_,py_pull_);
                fHistPtPzPullDaughter[daughterNum] -> Fill(pt_MC_,pz_pull_);
                fHistPtPtPullDaughter[daughterNum] -> Fill(pt_MC_,pt_pull_);
                fHistPtMassPullDaughter[daughterNum] -> Fill(pt_MC_,mass_pull_);
                fHistPtEPullDaughter[daughterNum] -> Fill(pt_MC_,e_pull_);

                daughterCounter++;            
            }
        } // end of track loop

    } // end of KFAR event loop

    ////////
    // end of event loop section
    ////

    

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

    /////////
    //  end of integrated histos block
    ////

    /////////
    //  create some graphs from TH2F histos
    ////

    fGraphPtXMeanResidMother = MakeMeanGraphFromTH2(fHistPtXResidMother);
    fGraphPtXMeanResidMother -> SetNameTitle("X Mean Resid","XMeanResid; p_{T}, GeV; X, #mu");
    fGraphPtYMeanResidMother = MakeMeanGraphFromTH2(fHistPtYResidMother);
    fGraphPtYMeanResidMother -> SetNameTitle("Y Mean Resid","Y Mean Resid; p_{T}, GeV; Y, #mu");
    fGraphPtZMeanResidMother = MakeMeanGraphFromTH2(fHistPtZResidMother);
    fGraphPtZMeanResidMother -> SetNameTitle("Z Mean Resid","Z Mean Resid; p_{T}, GeV; Z, #mu");
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
        fGraphPtXMeanResidDaughter[i] -> SetNameTitle("X Mean Resid","XMeanResid; p_{T}, GeV; X, #mu");
        fGraphPtYMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtYResidDaughter[i]);
        fGraphPtYMeanResidDaughter[i] -> SetNameTitle("Y Mean Resid","YMeanResid; p_{T}, GeV; Y, #mu");
        fGraphPtZMeanResidDaughter[i] = MakeMeanGraphFromTH2(fHistPtZResidDaughter[i]);
        fGraphPtZMeanResidDaughter[i] -> SetNameTitle("Z Mean Resid","ZMeanResid; p_{T}, GeV; Z, #mu");
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

    //----------------------

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

    //----------------------

    fGraphPtXResolMother = MakeSigmaGraphFromTH2(fHistPtXResidMother);
    fGraphPtXResolMother -> SetNameTitle("X Resol","XResol; p_{T}, GeV; X Resol, #mu");
    fGraphPtYResolMother = MakeSigmaGraphFromTH2(fHistPtYResidMother);
    fGraphPtYResolMother -> SetNameTitle("Y Resol","YResol; p_{T}, GeV; Y Resol, #mu");
    fGraphPtZResolMother = MakeSigmaGraphFromTH2(fHistPtZResidMother);
    fGraphPtZResolMother -> SetNameTitle("Z Resol","ZResol; p_{T}, GeV; Z Resol, #mu");
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
        fGraphPtXResolDaughter[i] -> SetNameTitle("X Resol","XResol; p_{T}, GeV; X Resol, #mu");
        fGraphPtYResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtYResidDaughter[i]);
        fGraphPtYResolDaughter[i] -> SetNameTitle("Y Resol","YResol; p_{T}, GeV; Y Resol, #mu");
        fGraphPtZResolDaughter[i] = MakeSigmaGraphFromTH2(fHistPtZResidDaughter[i]);
        fGraphPtZResolDaughter[i] -> SetNameTitle("Z Resol","ZResol; p_{T}, GeV; Z Resol, #mu");
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

    //----------------------

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

    /////////
    //  end of pt graphs block
    ////



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
            fHistXDaughterKFAR[i] -> Write("",TObject::kOverwrite);
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

    /////////
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

    //////////////////
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


    /////////////
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

    /////////////
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

    ///////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////
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

    OtherHistos -> cd();
        fHistPtPtErrMother -> Write();


    outputFile.Close();

    cout << endl;
    cout << "The macro is done. Results are saved in " << 
    KFHistoOutputFile << endl;


}

////
///////
//////////
//////////////

template<typename T, typename U>
U *MakeIntegatedHistoFromTH2(T fHisto2D){
    U *fHistOut = new U();
    fHistOut = fHisto2D->ProjectionY();;
    return fHistOut;
}

template<typename T>
TGraphErrors *MakeMeanGraphFromTH2(T fHisto2D){
    int num_of_bins = fHisto2D->GetXaxis()->GetLast();
    float x[num_of_bins], y[num_of_bins], xerr[num_of_bins], yerr[num_of_bins];
    for (int ibin = 1; ibin <= num_of_bins; ibin++){
        x[ibin-1] = fHisto2D->GetXaxis()->GetBinCenter(ibin);
        xerr[ibin-1] = fHisto2D->GetXaxis()->GetBinWidth(ibin)/2;
        auto fProjHisto2D = fHisto2D->ProjectionY("", ibin, ibin) ;
        y[ibin-1] = fProjHisto2D->GetMean();
        yerr[ibin-1] = fProjHisto2D->GetMeanError();
    }
    TGraphErrors *fGraphOut = new TGraphErrors(num_of_bins,x,y,xerr,yerr);
    return fGraphOut;
}

template<typename T>
TGraphErrors *MakeSigmaGraphFromTH2(T fHisto2D){
    int num_of_bins = fHisto2D->GetXaxis()->GetLast();
    float x[num_of_bins], y[num_of_bins], xerr[num_of_bins], yerr[num_of_bins];
    for (int ibin = 1; ibin <= num_of_bins; ibin++){
        x[ibin-1] = fHisto2D->GetXaxis()->GetBinCenter(ibin);
        xerr[ibin-1] = fHisto2D->GetXaxis()->GetBinWidth(ibin)/2;
        auto fProjHisto2D = fHisto2D->ProjectionY("", ibin, ibin) ;
        y[ibin-1] = fProjHisto2D->GetStdDev();
        yerr[ibin-1] = fProjHisto2D->GetStdDevError();
    }
    TGraphErrors *fGraphOut = new TGraphErrors(num_of_bins,x,y,xerr,yerr);
    return fGraphOut;
}