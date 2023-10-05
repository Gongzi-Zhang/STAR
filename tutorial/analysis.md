# 
daq -> StEvent -> MuDst -> PicoDst
* daq: raw data
* StEvent: First data format that has most of the signals from detectors and physics values (e.g., 3-momenta)
* MuDst: The STAR data format that contains physics variables and a some of those from the detector level
* PicoDst: New format that keeps only the most important information for the physics analyses of most PWGs


* Event:
  RunId, EventId, FillId, MagField
  PrimVtxPosition, PrimVtxPositionErr,RankinListOfTriggerIds,
  RefMult1-4,GRefMult,nTofMatched
  VpdVz, Bbc and Zdc,
  58 parameters in total
* Track:
  Id, χ2, charge,
  Global momentum, Primary momentum (if primary), Origin (3D position of DCA),
  dE/dx, nHits, nHitsFit, nHitsPossible (nHitsMax), nHitsDedx,
  nSigma(e, π, K, p), TopologyMap,
  Indices to BEMC, TOF and MTD
* FMS:
  Channel#, DetectorId, ADC
* BEMC (BTowHit): For now we are storing towers with E>200 MeV
  TowerId, ADC, Energy
* TOF (PidTraits):
  TrackIndex, CellId, MatchFlag,
  TimeOfFlight, Beta, YLocal, ZLocal, HitPosition3D
* TOF (Hit):
  Id, Tray, Module, Cell (all stored in one short)
* MTD (Hit):
  ChannelId, TriggerFlag, Leading- & Trailing-Edge time
* EPD (and BBC):
  Id (id, position, tile), QTdata (ADC, TAC, TDC, status flag)
* BEMC (PidTraits): For tracks that matched BEMC
  TrackId, Energy (HighestTower), ADC (HighestTower), η, Φ, Δz,
  E of two neighbor towers
* EmcTrigger:
  Algorithm is implemented (?), ADC, and 4 BHT and 18 JP trigger flags
* RPs:
* FCS:
