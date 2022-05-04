#include <cmath>

struct MCParticle{
    int trackID;
    int parentID;
    int pdg;
    float pdgLifeTime;
    int charge;
    float x;
    float y;
    float z;
    float trackLength;
    float pX;
    float pY;
    float pZ;
    float mass;
    float ndf;
    float chi2;

    float pT(){return sqrt(pX*pX+pY*pY);}
    float p(){return sqrt(pX*pX+pY*pY+pZ*pZ);}
    float e(){return sqrt(pX*pX+pY*pY+pZ*pZ+mass*mass);}
    float eta(){return 0.5*log((p()+pZ)/(p()-pZ));}
    float phi(){return atan2(pY, pX);}
    float theta(){return atan2(pT(), pZ);}
};

struct KFBRParticle{
    int numOfMCEvent;
    int idMC;
    int id;
    int pdg;
    float params[6];
    float covMat[21];
    float x;
    float y;
    float z;
    float pX;
    float pY;
    float pZ;
    float e;
    float s;
    int charge;
    float chi2;
    float ndf;
    float massHypo;

    bool isDaughter;
    bool isMother;
    
    float p;
    float pT;
    float eta;
    float phi;
    float mass;
    float decayLength;
    float decayLengthXY;
    float lifeTime;
    float r;
    float rapidity;
    float theta;

    float pErr;
    float pTErr;
    float etaErr;
    float phiErr;
    float massErr;
    float decayLengthErr;
    float decayLengthXYErr;
    float lifeTimeErr;
    float rErr;
};

struct KFARParticle{
    int numOfMCEvent;
    int idMC;
    int id;
    int pdg;
    float params[6];
    float covMat[21];
    float x;
    float y;
    float z;
    float pX;
    float pY;
    float pZ;
    float e;
    float s;
    int charge;
    float chi2;
    float ndf;
    float massHypo;

    bool isDaughter;
    bool isMother;
    
    float p;
    float pT;
    float eta;
    float phi;
    float mass;
    float decayLength;
    float decayLengthXY;
    float lifeTime;
    float r;
    float rapidity;
    float theta;

    float pErr;
    float pTErr;
    float etaErr;
    float phiErr;
    float massErr;
    float decayLengthErr;
    float decayLengthXYErr;
    float lifeTimeErr;
    float rErr;
};
