/* make connection to the db */
void StFcsDbMaker()
{
  LoadLibrary("St_geant_Maker");
  LoadLibrary("St_db_Maker");
  LoadLibrary("StFcsDbMaker");

  // FIXME What's the hell? Why this maker is necessary?
  St_geant_Maker* geant = new St_geant_Maker("geant");

  TString MySQLDb("MySQL:StarDb");                                      
  TString MainCintDb("$STAR/StarDb"); 
  St_db_Maker *dbMk = new St_db_Maker("db", MySQLDb, MainCintDb);
  dbMk->SetDebug();

  TString flavor = "ofl";   // default flavor for offline
  dbMk->SetFlavor(flavor.Data());
  dbMk->SetAttr("blacklist", "tpc"); 
  dbMk->SetAttr("blacklist", "svt");                                            
  dbMk->SetAttr("blacklist", "ssd");                                            
  dbMk->SetAttr("blacklist", "ist");                                            
  dbMk->SetAttr("blacklist", "pxl");                                            
  dbMk->SetAttr("blacklist", "pp2pp");                                          
  dbMk->SetAttr("blacklist", "ftpc");                                           
  dbMk->SetAttr("blacklist", "emc");                                            
  dbMk->SetAttr("blacklist", "eemc");                                           
  dbMk->SetAttr("blacklist", "mtd");                                            
  dbMk->SetAttr("blacklist", "pmd");                                            
  dbMk->SetAttr("blacklist", "tof");                                            
  dbMk->SetAttr("blacklist", "etof");                                           
  dbMk->SetAttr("blacklist", "rhicf");                                          
  dbMk->SetAttr("blacklist", "Calibrations_rich"); 

  TDatime dt;
  dbMk->SetDateTime(dt.GetDate(), dt.GetTime());
  dbMk->Init();
  dbMk->Make();

  StFcsDbMaker *fcsDbMk = new StFcsDbMaker("fcsDbMkr");
  fcsDbMk->Init();
  fcsDbMk->InitRun(-1);
  fcsDbMk->Make();
  StFcsDb* fcsDb = (StFcsDb*) fcsDbMk->GetDataSet("fcsDb");
  cout << fcsDb->getDetectorOffset(0) << endl;
  cout << fcsDb->getDetectorOffset(1) << endl;
  cout << fcsDb->getDetectorOffset(2) << endl;
  cout << fcsDb->getDetectorOffset(3) << endl;
}
