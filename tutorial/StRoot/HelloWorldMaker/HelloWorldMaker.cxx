#include "HelloWorldMaker.h"
ClassImp(HelloWorldMaker)

using namespace std;


HelloWorldMaker::HelloWorldMaker()
{

}
HelloWorldMaker::~HelloWorldMaker()
{

}

int HelloWorldMaker::Init()
{ 
    // Do once at the start of the analysis, create histograms, etc. 
}

int HelloWorldMaker::Make()
{ 
    // Do for every event
    cout << "Hello World" << endl;
    return kStOK; 
}

/*
void HelloWorldMaker::Clear()
{

}
 */

int HelloWorldMaker::Finish()
{ 
    // Do once at the end of the analysis, close files, etc. 
}

