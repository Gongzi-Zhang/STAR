/* Load STAR Library in a roo4star environment */

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
  {"StarClassLibrary",	"",		kFALSE},
  {"St_Tables",		"",		kFALSE},
  {"libStDb_Tables",	"",		kFALSE},
  {"libgen_Tables",	"",		kFALSE},
  {"libgeometry_Tables","",		kFALSE},
  {"libsim_Tables",	"",		kFALSE},
  {"StarMagField",	"",		kFALSE},
  {"StEpdUtil",		"",		kFALSE},
  // unknown
  {"StBichsel",		"",		kFALSE},
  {"libgsl",		"",		kFALSE},
  {"libgslcblas",	"",		kFALSE},
  {"libVMC",		"",		kFALSE},

  {"StUtilities",	"St_base",	kFALSE},
  {"StChain",		"St_base",	kFALSE},
  {"StBFChain",		"St_base",	kFALSE},
  {"StEvent",		"St_base",	kFALSE},
  {"StDbLib",		"St_base",	kFALSE},
  {"St_g2t",		"St_base",	kFALSE},
  // makers
  {"StTreeMaker",	    "StChain",	kFALSE},
  {"StIOMaker",		    "StChain",	kFALSE},
  {"St_db_Maker",	    "StChain",	kFALSE},
  {"St_geant_Maker",	    "StChain",	kFALSE},
  {"StTriggerDataMaker",    "StChain",	kFALSE},
  {"StMuDSTMaker",	    "StEmcUtil,StStrangeMuDstMaker",	kFALSE},
  {"StEventUtilities",	    "StChain,StEvent",	kFALSE},
  {"StStrangeMuDstMaker",   "StChain,StEvent",	kFALSE},

  // sub-detectors
  {"StTofUtil",		"St_base",	kFALSE},
  {"StPmdUtil",		"St_base",	kFALSE},
  {"StEmcUtil",		"StChain,StEvent,St_Tables",	kFALSE},
  {"StTpcDb",		"StChain",	kFALSE},

  //// FCS
  {"StFcsDbMaker",	    "StChain",	kFALSE},
  {"StFcsClusterMaker",	    "StChain,StEvent",	kFALSE},

  // generators
  {"StarGeneratorEvent","",		kFALSE},
  {"StarGeneratorUtil",	"St_base",	kFALSE},
  {"StarGeneratorBase",	"St_Tables,libVMC,StarGeneratorEvent,St_g2t,St_geant_Maker",	kFALSE},
  {"Pythia8_1_62",	"StarGeneratorBase",	kFALSE},
};
const Int_t kNumLibs = sizeof(LibTable)/sizeof(StLibDependency);
