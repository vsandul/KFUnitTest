#pragma once

#include <unordered_map>
#include <string>
#include "TString.h"
#include "TFile.h"
#include "OutputObjInterface.h"

// User-defined classes of output objects
#include "ResidPtDepHistos.h"
#include "PullPtDepHistos.h"

struct OutputMap{
public:
    OutputMap(){};
    OutputMap(TFile& outFile);
    ~OutputMap(){};
    std::unordered_map<std::string, OutputObjInterface*> map;

    void CreateAll();
    void FillAll();
    void PreWriteProcessAll();
    void WriteAll();

private:
    // instances of user-defined classes of output objects
    ResidPtDepHistos *residPTOutput;
    PullPtDepHistos *pullPTOutput;
};

//---------- add objects into map ------------
// here we add output objects in th map
OutputMap::OutputMap(TFile& outFile){
    residPTOutput = new ResidPtDepHistos(outFile);
    map["residPTOutput"] = residPTOutput;

    pullPTOutput = new PullPtDepHistos(outFile);
    map["pullPTOutput"] = pullPTOutput;
}


//---------- methods realization ------------

void OutputMap::CreateAll(){
    for (auto& [name,obj]:map)
        obj->Create();
}

void OutputMap::FillAll(){
    for (auto& [name,obj]:map)
        obj->Fill();
};

void OutputMap::PreWriteProcessAll(){
    for (auto& [name,obj]:map)
        obj->PreWriteProcess();
}

void OutputMap::WriteAll(){
    for (auto& [name,obj]:map)
        obj->Write();
}