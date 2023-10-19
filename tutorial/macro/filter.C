const char options = "fzin,MakeEvent";
void filter( int nevents, const Char_t *infile )
{
  gROOT->LoadMacro("bfc.C");
  bfc(0, options, infile );
  StFilterMaker *mfm = new StFilterMaker(“myfilter”);
  chain -> AddBefore( “verySlowMaker”, mfm );
  // or chain -> AddAfter( “importantMaker”, mfm );
  
  // set privilege here, then do the event loop
  mfm -> SetAttr( “.Priviledge”, 1 );

  chain -> EventLoop( nevents );
}
