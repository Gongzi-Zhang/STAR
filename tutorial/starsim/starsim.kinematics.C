/* A simple event generator for generating particles for simulation
 * 
 * $STAR/StRoot/StarGenerator/Kinematics
 */

#include <unistd.h>

class St_geant_Maker;
St_geant_Maker *geant_maker = 0;

class StarGenEvent;
StarGenEvent   *event       = 0;

class StarPrimaryMaker;
StarPrimaryMaker *_primary = 0;

class StarKinematics;
StarKinematics *kinematics = 0;

TF1 *ptDist  = 0;
TF1 *etaDist = 0;

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
void trig( Int_t n=1, const char* part = "e-")
{
  for ( Int_t i=0; i<n; i++ ) {
    // Clear the chain from the previous event
    chain->Clear();

    kinematics->SetAttr("energy", 1); // uniform dist. in energy; default flat in pt
    // line 94-174 in StRoot/StarGenerator/Kinematics
    kinematics->Kine( 1, part, 50.0, 100.0, 2.5, 4.0 );
    // if flat dist. in energy, then only falt in eta, not rapidity
    // kinematics->Kine( nTrack, "particle", Elow, Ehigh, etalow, etahigh, philow, phihigh);

    // kinematics->Kine( nTrack, "particle", ptlow, pthigh, ylow, yhigh, philow, phihigh);

    // Generate the event
    chain->Make();

    // Print the event
    _primary->event()->Print();
  }
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
void starsim(const char* part = "e-", Int_t nevents=1000)
{ 
  gSystem->Load("StarRoot");
  gROOT->ProcessLine(".L bfc.C");
  TString simple = "y2023 geant gstar usexgeom agml";  // bfc options
  bfc(0, simple);

  gSystem->Load( "libVMC.so");

  gSystem->Load( "StarGeneratorUtil.so" );
  gSystem->Load( "StarGeneratorEvent.so" );
  gSystem->Load( "StarGeneratorBase.so" );

  gSystem->Load( "libMathMore.so"   );  
  gSystem->Load( "xgeometry.so"     );

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
    _primary -> SetFileName( "starsim.kinematics.root" );
    _primary -> SetVertex( 0, 0, 0.0 );
    _primary -> SetSigma(0.1, 0.1, 30);	// unit in cm
    chain -> AddBefore( "geant", _primary );
  }

  // set up and add the kinematics generator
  gSystem->Load( "libKinematics.so");
  kinematics = new StarKinematics();
    
  _primary->AddGenerator(kinematics);

  //
  // Initialize primary event generator and all sub makers
  //
  _primary -> Init();

  //
  // Setup geometry and set starsim to use agusread for input
  //
  //geometry("y2012");
  command("gkine -4 0");  // what does this mean?
  command("gfile o starsim.kinematics.fzd");  // output fzd file
  
  //
  // Trigger on nevents
  //
  trig( nevents, part );

  command("call agexit");  // Make sure that STARSIM exits properly
}
// ----------------------------------------------------------------------------

