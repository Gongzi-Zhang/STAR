/* introduction: https://drupal.star.bnl.gov/STAR/comp/db
 *
 * DB tables are read in order:
 * 1. ./StarDb - local directory
 * 2. $STAR/StarDb - from current STAR Library version through AFS
 * 3. MySQL database
 */
void db()
{
    St_db_Maker *dbMk = new St_db_Maker("db", "MySQL:StarDb", "$STAR/StarDb");
    dbMk->SetDebug();
    dbMk->SetDateTime(20090301, 0);	// event or run start time
    dbMk->SetFlavor("ofl");	// pick up offline calibrations
    // dbMk->SetFlavor("simu"); // use simulations calibration set

    dbMk->Init();
    dbMk->Make();

    // this is done inside ::Make method
    TDataSet *DB = 0;
    // "dbMk->" will NOT be needed, if done inside your [subsys]DbMaker.
    // Simply use DB = GetInputDb("Calibrations/[subsystem_name]")
    DB = dbMk->GetInputDB("Calibrations/eemc");
    if (!DB) { std::cout << "ERROR: no db maker?" << std::endl; }

    St_eemctable_name *table_name = 0;
    table_name = (St_eemctable_name*) DB->Find("eemctable_name");

    // fetch data and place it to appropriate structure
    if (table_name) {
	eemctable_name_st *table = table_name->GetTable();
	std::cout << table->param1 << std::endl;
	std::cout << table->paramN << std::endl;
    }
}
