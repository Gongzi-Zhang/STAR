// macro to instantiate the Geant3 from within
// STAR  C++  framework and get the starsim prompt
// To use it do
//  root4star starsim.C

class St_geant_Maker;
St_geant_Maker *geant_maker = 0;

class StarGenEvent;
StarGenEvent   *event       = 0;

class StarPrimaryMaker;
StarPrimaryMaker *_primary = 0;

// ----------------------------------------------------------------------------
void geometry( TString tag, Bool_t agml=true )
{
  TString cmd = "DETP GEOM "; cmd += tag;
  if ( !geant_maker ) geant_maker = (St_geant_Maker *)chain->GetMaker("geant");
  geant_maker -> LoadGeometry(cmd);
  //  if ( agml ) command("gexec $STAR_LIB/libxgeometry.so");
}
// ----------------------------------------------------------------------------
void command( TString cmd )
{
  if ( !geant_maker ) geant_maker = (St_geant_Maker *)chain->GetMaker("geant");
  geant_maker -> Do( cmd );
}
// ----------------------------------------------------------------------------
// trig()  -- generates one event
// trig(n) -- generates n+1 events.
//
// NOTE:  last event generated will be corrupt in the FZD file
//
void trig( Int_t n=1 )
{
  chain->EventLoop(n);
  _primary->event()->Print();
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
void Pythia8( TString config="pp:W" )
{
  //
  // Create the pythia 8 event generator and add it to 
  // the primary generator
  //
  StarPythia8 *pythia8 = new StarPythia8();    
  if ( config=="pp:DY" )
  {
    pythia8->SetFrame("CMS", 200.0);
    pythia8->SetBlue("proton");
    pythia8->SetYell("proton");
    
    pythia8->Set("WeakSingleBoson:all=off");
    pythia8->Set("WeakSingleBoson:ffbar2gmZ=on");
    pythia8->Set("23:onMode=0");        // switch off all Z decay
    pythia8->Set("23:onIfAny 11 -11");	// switch on for decays to e+/-
    pythia8->Set("4900022:onMode=0");	    // switch off all gamma* decay
    pythia8->Set("4900022:onIfAny 11 -11"); // switch on for decays to e+/-
  }

  _primary -> AddGenerator( pythia8 );
  
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
void starsim( Int_t nevents=10, const char *prefix = "pythia8.starsim")
{ 

  gROOT->ProcessLine(".L bfc.C");
  {
    TString simple = "y2023 geant gstar usexgeom agml ";
    bfc(0, simple );
  }

  gSystem->Load( "libVMC.so");

  gSystem->Load( "StarGeneratorUtil.so");
  gSystem->Load( "StarGeneratorEvent.so");
  gSystem->Load( "StarGeneratorBase.so" );

  gSystem->Load( "Pythia8_1_62.so");

  gSystem->Load( "libMathMore.so"   );  

  // Force loading of xgeometry
  gSystem->Load( "xgeometry.so"     );

//   // And unloading of geometry
//   TString geo = gSystem->DynamicPathName("geometry.so");
//   if ( !geo.Contains("Error" ) ) {
//     std::cout << "Unloading geometry.so" << endl;
//     gSystem->Unload( gSystem->DynamicPathName("geometry.so") );
//   }

  // Setup RNG seed and map all ROOT TRandom here
  time_t seconds = time(NULL);
  pid_t pid = getpid();
  StarRandom::seed( seconds + pid );
  StarRandom::capture();
  
  //
  // Create the primary event generator and insert it
  // before the geant maker
  //
  //  StarPrimaryMaker *
  _primary = new StarPrimaryMaker();
  {
    _primary -> SetFileName( Form("%s.root", prefix));
    _primary -> SetVertex( 0.1, -0.1, 0.0 );
    _primary -> SetSigma ( 0.1,  0.1, 30.0 );
    chain -> AddBefore( "geant", _primary );
  }

  //
  // Setup an event generator
  //
  Pythia8("pp:DY");

  //
  // Setup cuts on which particles get passed to geant for
  //   simulation.  (To run generator in standalone mode,
  //   set ptmin=1.0E9.)
  //                    ptmin  ptmax
  // _primary->SetPtRange  (0.0,  -1.0);         // GeV
  _primary->SetPtRange  (1.0E9,  -1.0);         // GeV
  //                    etamin etamax
  _primary->SetEtaRange ( -3.0, +3.0 );
  //                    phimin phimax
  _primary->SetPhiRange ( 0., TMath::TwoPi() );
  
  // 
  // Setup a realistic z-vertex distribution:
  //   x = 0 gauss width = 1mm
  //   y = 0 gauss width = 1mm
  //   z = 0 gauss width = 30cm
  // 
  _primary->SetVertex( 0., 0., 0. );
  _primary->SetSigma( 0.1, 0.1, 30.0 );

  
  //
  // Initialize primary event generator and all sub makers
  //
  _primary -> Init();

  //
  // Setup geometry and set starsim to use agusread for input
  //
  //geometry("y2012");
  //* AGUSER/GKINE NTRACK ID [ PTLOW PTHIGH YLOW YHIGH PHILOW PHIHIGH ZLOW ZHIGH option ]

  command("gkine -4 0");
  command("gfile o pythia8.starsim.fzd");
  

  //
  // Trigger on nevents
  //
  trig( nevents );

  //
  // Finish the chain
  //
  chain->Finish();

  //
  // EXIT starsim
  //
  command("call agexit");  // Make sure that STARSIM exits properly
}
// ----------------------------------------------------------------------------

