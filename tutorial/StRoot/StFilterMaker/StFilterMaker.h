#ifndef StFilterMaker_h
#define StFilterMaker_h

#include "StMaker.h"

class StFilterMaker : public StMaker 
{
  public:
    StFilterMaker();
    ~StFilterMaker();

    int Init();
    int Make();
    int Finish();

  private:
    ClassDef(StFilterMaker, 1)
};

#endif
