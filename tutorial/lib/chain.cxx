StChain *chain = new StChain;
StMuDstMaker *muDstMk = new StMuDstMaker(0, 0, "", file_list.data(), ".MuDst.root", 200, "MuDst"); // reads MuDST
St_db_Maker *dbMk = new St_db_Maker("StarDb", "MySQL:StarDb"); // DB maker
StEEmcDbMaker *eemcDb = new StEEmcDbMaker("EEmcDbMaker"); // Additional EEMC DB maker

Bool_t status = chain->Init(); // Call Init() for all makers
if (status != kStOK) {
    cout << "ERROR: Chain initialisation failed (error " << status << "), not running!" << endl;
    return 0;
}

status = chain->EventLoop(); //Process all events in the chain
if ((status != kStOK) && (status != kStEOF)) 
    cout << "WARNING: EventLoop returned error " << status << endl;

status = chain->Finish(); // Call Finish() for all makers, write output data
if (status != kStOK) 
    cout << "WARNING: Chain finished with error " << status << endl;
delete chain;
