/* make connection to the db */
void St_db_Maker()
{
  LoadLibrary("St_geant_Maker");
  LoadLibrary("St_db_Maker");

  // FIXME What's the hell? Why this maker is necessary?
  St_geant_Maker* geant = new St_geant_Maker("geant");

  TString MySQLDb("MySQL:StarDb");                                      
  TString MainCintDb("$STAR/StarDb");                                   
  TString MainCintDbObj("$STAR/.$STAR_HOST_SYS/obj/StarDb");            
  TString MyCintDb("$PWD/StarDb");                                      
  TString MyCintDbObj("$PWD/.$STAR_HOST_SYS/obj/StarDb");
  St_db_Maker *dbMk = new St_db_Maker("db", MySQLDb, MainCintDb, MainCintDbObj, MyCintDb, MyCintDbObj);

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
}
