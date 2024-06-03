* Undefined symbols
  * load related libraries
  * check ./rootlogon.C
  * check ~/.rootrc making sure that ./rootlogon.C is executed
* can not load a library
  * check $LD_LIBRARY_PATH
  * make sure all prerequisite libraries are loaded
* .sl73_gcc485/obj/StRoot/StarGenerator/UTIL/StarRandom.cxx:69: Double_t StarRandom::flat(Double_t, Double_t) const: Assertion mx>mn failed.
  * if you want to do fixed energy/momentum/eta/phi simulation, then you can not
    use the same number fo min and max. Because the random number generator requires
    that max > min; therefore one should use values as:
      value-0.000001, value+0.000001 
* *** StMuException #29710 *** virtual void StMuDstMaker::read() *** end of input ***
  * canot read the last MuDst event, number of MuDst event = MuDst->GetEntries() - 1 
