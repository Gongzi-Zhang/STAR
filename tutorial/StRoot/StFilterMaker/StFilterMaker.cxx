#include "StFilterMaker.h"
ClassImp(StFilterMaker)

using namespace std;


StFilterMaker::StFilterMaker()
{

}
StFilterMaker::~StFilterMaker()
{

}

int StFilterMaker::Init()
{ 
    // Do once at the start of the analysis, create histograms, etc. 
}

int StFilterMaker::Make()
{ 
    // Do for every event
    if (fail_filter) 
      return kStSkip;
    return kStOK; 
}

/*
void StFilterMaker::Clear()
{

}
*/

int StFilterMaker::Finish()
{ 
    // Do once at the end of the analysis, close files, etc. 
}

