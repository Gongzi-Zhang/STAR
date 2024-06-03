* [source code](https://github.com/star-bnl/star-sw)
  local: $STAR/StRoot/
* [class reference](https://www.star.bnl.gov/webdata/dox/html/annotated.html)
* [coding and naming standards](https://drupal.star.bnl.gov/STAR/comp/sofi/soft-n-libs/standards)

------------------------------------------------------------------------------
# StRoot
  * macro: various example macros
  * RTS: Standalone DAQ file reader examples
  * StLibName: a library package/class
    * St...Db: a Database class
      * Store various const information, such as position, material, etc 

  * LD_LIBRARY_PATH
    .sl73_gcc485/lib
    /afs/rhic.bnl.gov/star/packages/SL23a/.sl73_gcc485/lib
    /afs/rhic.bnl.gov/star/ROOT/5.34.38/.sl73_gcc485/rootdeb/lib
    ROOT
    /afs/rhic.bnl.gov/star/ROOT/Xrootd/prod/.sl73_gcc485/lib
    /opt/star/sl73_gcc485/qt4/lib
    /opt/star/sl73_gcc485/lib
  * header files
    dir. where the source code lies in
    StRoot/
* definition of various constant:
  $STAR/StRoot/StEvent/StEnumerations.h
* tables:
  $STAR/.sl73_gcc485/include/tables/
  * Fcs
    * detector offset
    * ET gain


* GetNextDaqElement


# bfc
StBFChain -> StChain -> StMaker -> TDataSet 
* How the bfc works?
    -- define various options to include corresponding makers (the order matters)
	* which maker does each option correspond to?
	    > see StBFChain/BigFullChain.h
	* setFlags for each option
	* load libraries corresponding to each option
	* create makers for each option
    -- include customized makers (exchangable with the next step)
    -- extract various makers from the chain and customize each maker
    -- evenrloop

* how many makers in a chain? Where are these makers introduced?
    -- StChain::lsMakers/chain->GetMakeList()
    -- makers are introduced either through bfc options or maker instance
* What does each maker do? How do they modify and pass the data?
    -- 'StEvent' contains various containers for various data (hit/cluster/point),
       one can operate on these containers to receive and write data
* data strcture?
    StBFChain (bfc) -> StChain (bfc) -> StMaker (bfc) -> TDataSet (bfc)
							    |
							    |-- .make
							    |-- .data
							    |-- .const
							    |-- .garb
							    |-- .aliases
							    |-- .runco
							    |-- .hist
    .make
      |
      |-- Maker1 DataSet
      |-- Maker2 DataSet
      .
      .
      .

    Maker1 DataSet
	|
	|-- .data
	|-- .const
	|-- .garb
	|-- .aliases
	|-- .runco

    StEventMaker
	|
	|-- .data
	      |
	      |-- StEvent

* how to create a dataset tree?
    * who own the dataset? where is it
	-- the first StMaker (bfc) owns the dataset (through StMaker::fgTopChain)
	-- it is a memory object
* When a maker is instanized, it is caught by the chain automatically, how?
    -- in StMaker::StMaker()
	fgStChain->AddData(this,".make"); 
* StEvent -> StFcsCollection -> Hits, Clusters

* Dataset: a named list of dataset objects
  * base clase: TDataset
  * Dataset can be a set of any of these:
    * Tables, Makers, Files, Objects, Geometry, Histograms
  * Unique names for datasets are important, because they are accessed by their name.
  * Datasets form a basis of STAR software for:
      * Data analysis
      * Simulation
      * Reconstruction
* Maker: owner of a dataset
  * StMaker (base class) is also a TDataset itself
  * Make operations on data
  * Reconstruction requires running a few makers per subsystem (detector): ∼ 100 makers in total
* Chain:
  * A special StMaker ("Top maker") and a TDataSet as well
  * Contains an ordered list of makers
  * Makers are added to the chain automatically in order they are created
  * Allows to combine makers as components of a complex analysis, reconstruction or simulation
* BFC: StBFChain
  * all possible options: [https://www.star.bnl.gov/cgi-bin/protected/viewvc.cgi/cvsroot/StRoot/StBFChain/doc/index.html?view=co]
    * StBFChain/BigFullChain.h
    * Run bfc.C without any options
    ```
      root4star -l -q bfc.C
    ```
    * Options can inherit from previous other options
    * Production options: [https://www.star.bnl.gov/devcgi/dbProdOptionRetrv.pl]
    * Geometry options (up to 2020): [https://drupal.star.bnl.gov/STAR/comp/prod/MCGeometry]
  * SetOptions (parse options) -> SetFlags -> Load (load libraries) -> Instantiate (create makers)



------------------------------------------------------------------------------
# Database: [https://drupal.star.bnl.gov/STAR/comp/db]
  * Contains 'calibrations', 'gains', 'geometry transformations', etc.
  * Access to Database information is done via `StMaker::GetDataBase()` method
    which calls St_db_Maker.
  * St_db_Maker reads DB tables with a timestamp automatically set from the data
    or with SdtYYYYMMDD.HHMMSS command for simulation
  * database file: DB tables are read in the following order:
    1. ./StarDb -- local directory
    2. $STAR/StarDb -- from current STAR Library version through AFS
    3. MySQL database 

------------------------------------------------------------------------------
# MuDST

------------------------------------------------------------------------------
# GEANT
* Giant3: $STAR/asps/rexe/TGeant3/
