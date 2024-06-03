/* Load STAR Library in a roo4star environment */
#ifndef _LOADSTARLIBRARY_
#define _LOADSTARLIBRARY_

using namespace std;

struct StLibDependency {
  Char_t  Name[64];
  Char_t  Dependency[256];
  Bool_t  Flag;
};

void PrintTable() {
  cout << "INFO:\tAvailable libraries" << endl;
  for (Int_t i=0; i<kNumLibs; i++)
    cout << "\t" << LibTable[i].Name << endl;
}

Int_t LibNum(TString lib)
{
  if (lib.IsNull())
    return -1;

  lib.ToLower();
  for (Int_t i=0; i<kNumLibs; i++)
  {
    TString tag = LibTable[i].Name;
    tag.ToLower();
    if (lib == tag)
      return i;
  }
  return -1;
}

void LoadLibrary(TString lib, TString parentLib="")
{
  if (lib.IsNull())
    return;
  // check if library is loaded
  Int_t l = LibNum(lib);
  if (-1 == l)
  {
    cout << "ERROR\tLibrary not found in the table, please check it or add it to the table: " << lib << endl;
    PrintTable();
    return;
  }
  if (LibTable[l].Flag)	// already loaded
    return;

  // Load dependency libraries first
  TString Dependency = LibTable[l].Dependency;
  TObjArray *DepLibs = Dependency.Tokenize(", ");
  for (Int_t i=0; i<DepLibs->GetEntries(); i++)
  {
    TString dlib = ((TObjString*) DepLibs->At(i))->GetName();
    LoadLibrary(dlib, LibTable[l].Name);
  }

  // Load lib
  if (parentLib.IsNull())
    cout << "INFO\tLoading library: " << lib << "." << endl;
  else
    cout << "INFO\tLoading library: " << lib << ".\tRequired by " << parentLib << endl;
  gSystem->Load(LibTable[l].Name);
  LibTable[l].Flag = kTRUE;
  return;
}

StLibDependency LibTable[] = {
// "name"	    "dependency"	"flag"
  // math and physics
  {"libPhysics",	"",		kFALSE},
  {"libMinuit",		"",		kFALSE},
  {"libMathMore",	"",		kFALSE},

  // star customed
  {"St_base",		"",		kFALSE},
  {"StarRoot",		"",		kFALSE},
  {"StarClassLibrary",	"",		kFALSE},
  {"St_Tables",		"",		kFALSE},
  {"StTableUtilities",	"",		kFALSE},
  {"libTable",		"",		kFALSE},
  {"libStDb_Tables",	"",		kFALSE},
  {"libgen_Tables",	"",		kFALSE},
  {"libgeometry_Tables","",		kFALSE},
  {"libsim_Tables",	"",		kFALSE},
  {"StarMagField",	"",		kFALSE},
  // unknown
  {"StBichsel",		"",		kFALSE},
  {"libgsl",		"",		kFALSE},
  {"libgslcblas",	"",		kFALSE},
  {"libVMC",		"",		kFALSE},
  {"g2t",		"",		kFALSE},

  {"StUtilities",	"St_base",	kFALSE},
  {"StChain",		"St_base,StarRoot",	kFALSE},
  {"StBFChain",		"StChain,StUtilities",	kFALSE},
  {"StEvent",		"St_base,StarRoot,StarClassLibrary",	kFALSE},
  {"StMcEvent",		"StEvent",	kFALSE},
  {"St_g2t",		"St_base",	kFALSE},

  // Database
  {"StDbLib",		"St_base",	kFALSE},
  {"StDbBroker",	"StDbLib,StUtilities",	kFALSE},
  {"StTpcDb",		"StChain",  kFALSE},

  // makers
  {"StTreeMaker",	    "StChain",	kFALSE},
  {"StIOMaker",		    "StChain",	kFALSE},
  {"St_db_Maker",	    "StChain,StDbBroker",	kFALSE},
  {"St_geant_Maker",	    "StChain,St_Tables,St_g2t",	kFALSE},
  {"StTriggerDataMaker",    "StChain",	kFALSE},
  {"StPreEclMaker",	    "StChain,StEvent",	kFALSE},
  {"StEventUtilities",	    "StChain,StEvent",	kFALSE},
  {"StStrangeMuDstMaker",   "StChain,StEvent",	kFALSE},
  {"StMuDSTMaker",	    "StUtilities,StEmcUtil,StStrangeMuDstMaker",	kFALSE},
  {"StDetectorDbMaker",	    "StTpcDb,St_Tables",	kFALSE},
  {"StEventMaker",	    "StDetectorDbMaker,StEvent",	kFALSE},

  // sub-detectors
  {"StTofUtil",		"St_base",	kFALSE},
  {"StBTofUtil",	"St_base",	kFALSE},
  {"StEmcUtil",		"StChain,StEvent,St_Tables",	kFALSE},
  {"StPmdUtil",		"St_base",	kFALSE},
  {"StEpdUtil",		"",		kFALSE},
  {"StFmsUtil",		"St_base",		kFALSE},
  // {"StFcsUtil",		"",		kFALSE},  // no such lib
  // {"StFttUtil",		"",		kFALSE},  // no such lib
  {"StFstUtil",		"St_base",	kFALSE},
  {"StTpcDb",		"StChain",	kFALSE},

  //// FMS
  {"StFmsDbMaker",	    "StarClassLibrary,StChain,StFmsUtil",	kFALSE},

  //// FCS
  {"StFcsDbMaker",	    "StarClassLibrary,StChain,StUtilities",	kFALSE},
  {"StFcsClusterMaker",	    "StChain,StEvent",	kFALSE},
  {"StFcsRawHitMaker",	    "StMuDstMaker",	kFALSE},

  // generators
  {"StarGeneratorEvent","",		kFALSE},
  {"StarGeneratorUtil",	"St_base",	kFALSE},
  {"StarGeneratorBase",	"St_Tables,libVMC,StarGeneratorEvent,St_g2t,St_geant_Maker",	kFALSE},
  {"Pythia8_1_62",	"StarGeneratorBase",	kFALSE},
};
const Int_t kNumLibs = sizeof(LibTable)/sizeof(StLibDependency);

#endif
