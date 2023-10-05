#ifndef HelloWorldMaker_h
#define HelloWorldMaker_h

#include "StMaker.h"

class HelloWorldMaker : public StMaker 
{
  public:
    HelloWorldMaker();
    ~HelloWorldMaker();

    int Init();
    int Make();
    int Finish();

  private:
    ClassDef(HelloWorldMaker, 1)
};

#endif
