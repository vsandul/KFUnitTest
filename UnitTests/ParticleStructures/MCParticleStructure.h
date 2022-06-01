#pragma once

#include <cmath>

struct MCParticleStruct{
    int trackID;
    int parentID;
    int pdg;
    int charge;
    float mass;

    float x;
    float y;
    float z;

    float trackLength;

    float pX;
    float pY;
    float pZ;

    float ndf;
    float chi2;

    float pT() const {return sqrt(pX*pX+pY*pY);}
    float p() const {return sqrt(pX*pX+pY*pY+pZ*pZ);}
    float e() const {return sqrt(pX*pX+pY*pY+pZ*pZ+mass*mass);}
    float eta() const {return 0.5*log((p()+pZ)/(p()-pZ));}
    float phi() const {return atan2(pY, pX);}
    float theta() const {return atan2(pT(), pZ);}
};