#include "OutputMap.h"
#include "../ConfigConstants.h"

#include "../MCParticleStructure.h"

void testscript(){

  TFile outputFile("asd.root", "RECREATE");
  
  cout << "outputFile is open? = " << outputFile.IsOpen() << endl;;

  OutputMap output_map(outputFile);

  for (auto &[name,obj]:output_map.map){
      obj->Create();
  }

  for (int i = 0; i < 1000; i++){
    MCParticle mc_part;
    mc_part.x = rand()/(double)RAND_MAX;
    mc_part.y = rand()/(double)RAND_MAX;
    mc_part.z = rand()/(double)RAND_MAX;
    mc_part.pX = rand()/(double)RAND_MAX;
    mc_part.pY = rand()/(double)RAND_MAX;
    mc_part.pZ = rand()/(double)RAND_MAX;

    for (auto &[name,obj]:output_map.map){
      obj->Fill(mc_part);
    }
  }

  for (auto &[name,obj]:output_map.map){
      obj->Write();
  }      

  outputFile.Close();

}