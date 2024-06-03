* Contains calibrations, gains, geometry transformation, etc
* Access to Database information is done via StMaker::GetDataBase() method
which calls St db Maker.
* St db Maker reads DB tables with a timestamp automatically set from the data
or with SdtYYYYMMDD.HHMMSS command for simulation)

# DB tables are read in order:
1. ./StarDb - local directory
2. $STAR/StarDb - from current STAR Library version through AFS
3. MySQL database
  This allows to substitute official Db entries by a private version in order to check/modify calibration.
