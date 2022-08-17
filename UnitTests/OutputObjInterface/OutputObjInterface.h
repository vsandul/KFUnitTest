#pragma once

#include "../ParticleStructures/MCParticleStructure.h"
#include "../ParticleStructures/KFParticleStructure.h"
#include "TFile.h"

class OutputObjInterface{
public:
    OutputObjInterface(TFile& outputFile) {this->outputFile = &outputFile;};
    virtual ~OutputObjInterface(){};

    void virtual Create() = 0;
    void virtual Fill() = 0;
    void virtual Fill(const MCParticleStruct& mcPart) = 0;
    void virtual Fill(const KFParticleStruct& kfPart) = 0;
    void virtual Fill(const MCParticleStruct& mcPart, const KFParticleStruct& kfPart) = 0;
    void virtual PreWriteProcess() = 0;
    void virtual Write() = 0;

protected:
    TFile *outputFile;

};