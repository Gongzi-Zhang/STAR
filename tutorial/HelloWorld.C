#include <iostream>
#include "TSystem.h"

void HelloWorld()
{
    // Load libraries
    // gROOT->Macro("loadMuDst.C");
    gROOT->LoadMacro("$STAR/StRoot/StMuDSTMaker/COMMON/macros/loadSharedLibraries.C");
    loadSharedLibraries();

    gSystem->Load("HelloWorldMaker");

    // List of member links in the chain
    StChain* chain = new StChain;
    HelloWorldMaker* Hello = new HelloWorldMaker();
    Int_t nEvents = 10 ;
    // Loop over the links in the chain
    chain -> Init();
    chain -> EventLoop(1,nEvents);
    chain -> Finish();
    // Cleanup
    delete chain ;
}
