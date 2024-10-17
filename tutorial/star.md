------------------------------------------------------------------------------
# [STAR Subsystems](https://www.star.bnl.gov/public/html/subs.html)
  [NIM papers](https://www.star.bnl.gov/public/tpc/NimPapers/index.htm) 
  * SVT: Silicon Vertex Tracker 
    * 3 cylindrical layers at distances of approximately 7, 11 and 15 cm from the beam axis
    * |η| ≤ 1, ΔΦ = 2π
    * primary interaction vertex and secondary vertex
  * SSD: Silicon Strip Detector 
  * HFT: [Heavy Flavor Tracker](https://doi.org/10.2172/887418)
    * 2012 - 
    * upgraded for run 15 and 16
  * TPC: track, momentum and dE/dx measurement
    * 4.2 m long and 4 m in diameter, track reconstruction precision is sub-millimeter
    * radial distance from 50 to 200 cm
    * uniform electric field of about 135 V/cm
    * readout system: Multi-Wire Proportional Chamber
    * |η| < 1.8, ΔΦ = 2π
    * momentum measurement in the range of 0.1 - 30 GeV, δp/p= 0.02, the lower the momentum 
      or the higher the particle multiplicity, the worse the momentum resolution
    * dE/dx resolution of ~8% can be achieved by requiring the tracks of charged 
      particles to have at least 20 out of a maximum of 45 hits in the TPC
    * PID by measuring the ionization energy loss (dE/dx) in the momentum range of 0.1 - 1 GeV.
    * alignment?
    * TPX: 
    * iTPC: inner TPC (inner sectors of the TPC)
  * GMT: GEM Chambers to Monitor the TPC Tracking (GMT)
    * 8 GEM chambers outside TPC at the TOF radius
    * help to monitor and correct the TPC distortion, allowing a TPC space resolution to be better than ~200 μm
  * CTB: [Central Trigger Barrel](https://web.archive.org/web/20050325121727/http://www.star.bnl.gov/STAR/html/trg_l/CTB/index.html)
      measures the multiplicity of charged particles at the outer radius of the TPC and provides that information to the Level 0 trigger. [sn0326]
  * TOF: Time Of Flight (extend the dynamic range of PID to mid pT region)
    * TOFp: TOF patch (covering only 1/60 in azimuth and -1 ≤ η ≤ 0), before full installation
    * installed in 2003
    * time resolution: ~100 ps
    * -1.5 < η < 0.9
    * Multi-gap Resistive Plate Chamber (MRPC)
  * RICH: Ring Imaging Cherekov
  * Solenoid magnet: Bz = 0.5 T
  * EMC: ElectroMagnetic Calorimeter 
    * Lead and plastic-scintillator sampling calorimeters
    * BEMC: Barrel ElectroMagnetic Calorimeter 
      * BTOW: Barrel Electromagnetic Calorimeter
      * BSMD: Barrel Shower-Maximum Detector 
        * to distinguish high momentum single photons from photon pairs resulting from π and η meson decays.
      * BPSD: Barrel Preshower Detector
      * -1 < η < 2, ΔΦ = 2π
      * (outdated) The barrel is segmented into 4800 towers each with a size of (Dη,DΦ) = (0.05,0.05). 
	However, for triggering purposes, these towers are grouped in sets of 16 
	to give 300 trigger patches each covering (Dη,DΦ) = (0.2,0.2).
    * EEMC: (west) Endcap ElectroMagnetic Calorimeter 
      * 1.07 < η < 2.0
      * 720 individual towers each with a size of either (Dη,DΦ) = (0.05,0.1) 
	or (Dη,DΦ) = (0.1,0.1)
      * Towers are grouped together to form 90 trigger patches each covering (Dη,DΦ) = (0.3,0.2)
  * MTD: Muon Telescope Detector
    * MRPC-based detector
    * |η| < 0.5

  * FTPC: Forward TPC 
    * 2.5 < |η| < 4, ΔΦ = 2π
  * VPD: Vertex Position Detector
    * pVPD: pseudo-VPD
    * 2 VPDs, one on each side
    * 5.4 away from the TPC center along the beam line
    * Each pVPD covers ∼19% of the total solid angle in 4.25 ≤ |η| ≤ 5.1
    * used to record the start time for the TOF
  * PMD: Photon Multiplicity Detector
  * FTS: Forward Tracking System (West side)
    * installed and commissioned in 2021, star taking data in Run22
    * 2.5 < η < 4
    * FST: Forward Silicon Tracker (inside TPC)
      * 3 silicon disks at 152, 165 and 179 cm from IP
      * reuse STAR Intermediate Silicon Tracker (IST) DAQ and cooling system
      * Single-sided double-metal mini-strip sensors
	- Granularity: fine in Φ and coarse in R
	- Si sensors from Hamamatsu
      * Frontend readout: APV25
      * Material budget: ~1% per disk
      * inter-radius region: 5 < R < 16.5 cm
	- 1 Kapton flexible hybrid
	- 1 Si sensor: 128 × 4 (Φ×R) strips
	- 4 APV chips
      * Outer-radius region: 16.5<R<28 cm
	- 1 Kapton flexible hybrid
	- 2 Si sensors: 128 × 4 (Φ×R) strips
	- 4 APV chips
      * Mechanical structure is made of
        - PEEK (main structure, tube holder)
        - Stainless steel (cooling tube)
        - Aluminum (heat sinks)
      * installation completed on 8/13/2021
    * Forward sTGC (Small-strip Thin Gap Chanbers) Tracker (FTT) (outside TPC)
      * 4 sTGC stations: at 307, 325, 343 and 361 cm from IP
      * Following ATLAS design
      * Locate inside STAR magnet pole tip openin: inhomogeneous magnetic field
      * 4 quadrants double sided sTGC 
	- Diagonal strips to suppress ghost hits
      * Position resolution: ~100 μm
      * Frontend readout: VMM-chips
      * Material budget: ~0.5% per layer
  * FPD + FMS: Foward Pion Detector + Forward Meson Spectrometer 
    * FPD evolves into FMS (2008)
    * FPD
      * added in 2003
      * 8 lead-glass calorimeters, 4 on each side: the Up, Down, North and South calorimeters. 
      * The Up and Down calorimeters consist of 5x5 arrays of lead-glass Cherenkov detectors. 
      * The North and South calorimeters consist of 7x7 arrays. 
      * The FPD detects very forward p0 particles which can tell us about the gluon distribution in the nucleus. 
      * It is used as a local polarimeter for the polarized proton running.
    * FPS/FPOST: FMS PreShower Detector / FMS Post Shower Detector
      * scintillators with a SiPM readout
      * Monitor radiation damage by the IV scans
    * 2.5 < η < 4.2
  * FCS: Forward Calorimeter System (West side)
    * installed in 2020, commissioned in Run21
    * 7 m from the IP on the “FMS platform”
    * 2.5 < η < 4
    * ECAL
      * reuse PHENIX Pb-SC calorimeter
      * replaced PMTs with SiPM readout
      * 1496 channels: 5.52 x 5.52 x 33 cm³
      * 66 sampling cells with 1.5 mm Pb/4 mm Sc
      * 36 wavelength shifting fibers per cell
      * 18 X₀; 0.85 λ
    * HCAL
      * new Fe/Sc (20mm/3 mm) sandwich
      * 520 readout channels: 10 x 10 x 84 cm³
      * ~ 4.5 λ
      * Uses same SiPM readout as Ecal
      * In close collaboration with EIC R&D
    * Pre-shower: use STAR EPD
  * BBC: Beam Beam Counter 
    * two rings of scintillator tiles: 18 inner (small) and 18 outer (large) 
      * Internally, each ring is itself divided into two separate sub-rings of 6 and 12 tiles each.
    * mounted on the East and West poletips of the STAR magnet
    * 2.1 < |η| < 5.1
  * EPD: [Event Plane Detector](https://doi.org/10.1016/j.nima.2020.163970)
    * measure the azimuthal patterns of emitted particles, doesnot care about the
      particle species
    * plastic scintillator plane: 1.2 cm thick
    * ±3.75 m from the center of the TPC
    * 12 supersectors, 31 tiles / supersector
    * 2.14 < |η| < 5.09 (0.7 < θ < 13.5 deg)
    * ns response time for usage as a trigger
  * ZDC: Zero Degree Counter
    * Lead-fiber sampling calorimeter, one on each side
    * ~18 m away from the IP, horiztonal acceptance: ±5 cm
    * θ < 2 mrad, |η| > 6.0
    * time resolution: ~100 ps
  * FGT: Forward GEM tracker 
    * 2012 -
    * Triple GEM Foils
  * MTPC: Mini TPC 
  * RPD: Roman Pot Detector
    * 7 < |η| < 9

  * CTL: STAR ConTroLs 
  * DAQ: Data AcQuisition 
  * FEE: Front End Electronics 
  * QT: charge (Q) and time (T) digitizer boards
  * RCC: RHIC Clock Control board
  * STP: STAR Trigger Pusher network
  * TCD: Trigger Control Distribution board
  * TCU: Trigger Control Unit
  * Integration:STAR Integration ... Envelope Drawings, Graphics, Documents, etc.
  * Interfaces: Interface 
  * LEVEL3: Level 3 trigger 
  * TRG: TRiGger 
  * DAQ2K: DAQ and TRG Upgrade 

# [Trigger](https://www.star.bnl.gov/public/trg/.introduction/index.html)
  * trigger detectors
    * L0: CTB, ZDC
      * CTB measures charged multiplicity
      * ZDC measures the number of spectator neutrons, for use as a minimum 
        bias trigger, and act as an intra-RHIC normalizing detector. 
	ZDC coincidence can be used to determined the vertex position and the event time
    * L1: BBC, FPD, TPC anode MWC, BEMC and EEMC
      * BBC: The timing difference between the two BBCs will locate the primary vertex position.
    * a minimum bias trigger was obtained by selecting events with a pulse height larger than
      that of one neutron in each of the forward ZDCs, which corresponds to 95% of the geometrical cross-section. 


------------------------------------------------------------------------------

# Jargons
  * RCF: RHIC Computing Facility
  * BFC: Big Full Chain -- data production (reconstruction)
  * IP: interaction point
  * CTF: Central Time of Flight -- A software module that simulates TOF and CTB
	 based on the fact that these 2 sub-detectors use the same scintillators
  * G2T: Geant to Tables -- transforms the GSTAR output into a file with an appropriate 
	 format to be read by STAF
  * STAF: [STar Analysis Framework](https://web.archive.org/web/20010204094000/http://www.rhic.bnl.gov/STAR/html/ssd_l/staf_l/STAF-current/staf.html)
	 A STAR version of PAW. 
    * It includes various useful routines, libraries, such as:
     * event generators
     * gstar
     * g2t
     * ...
    * table: Basic data structure element in STAF
  * PAW: Physics Analysis Workstation
  * GPAW: GEANT-PAW
  * PAM: Physics Analysis Module
  * nσ: normalized dE/dx:
    * nσ_X^Y = log((dE/dx)_Y/B_X)/σ_X
      where X, Y can be e±, π±, K±, and p(pbar).
      B_X is the expected mean dE/dx of a particle X, and σ_X is the dE/dx resolution of TPC.
    * nσ_π distribution is a normal Gaussian distribution with an ideal calibration
  * DSM: Data Storage and Manipulation boards
  * DST: Data Summary Tape; 
  * AGI: Advanced Geometry Interface for GSTAR 
  * AgML: successor of AGI -- Another geometry Modelling Language
    * based on xml
    * backward compatibility with AGI
  * EDM: (MC) Event Data Model

  * PAC: Physics Analysis Coordinators
  * PWG: Physics Worling Groups
    * Correlations and Fluctuations
    * Flow, Chirality and Vorticity
    * Hard Probes
    * Light Flavor Spectra and UPC
    * Cold QCD (Spin)

------------------------------------------------------------------------------
# STAR softwares:
```
  root4star
  cons    # compilation
    # requires the 'StRoot' dir.
    # local version of any modules under StRoot will take place the standard version
  # cvs co StRoot/<Module>
```
## version
  * SLYYx - where YY is the year, and x is a letter, corresponds to data production PYYix
  * DEV - latest development version, may be buggy or unstable
  * PRO - latest production version, default after login
  * NEW - a few weeks old version for full integration testing, more stable than DEV)
  ```
    starver SL20a   # select 20 production
    stardev
    starpro	# default
    starnew
  ```
## misc 
  ```
    root2agml.py  # convert ROOT geometry to AgML
  ```

------------------------------------------------------------------------------
# Data Files
## file storage
  * tape -- /home/starreco/ (hpss, mss): backup of everything. For whole collaboration/lab
  * cache -- /home/starlib/: restored from the tape. For whole collaboration or group
  * work -- /gpfs/mnt/gpfs01/star/pwg/<username>: save results, histograms, small root files. Per user.
  * scratch -- /gpfs/mnt/gpfs01/star/scratch/<username>: temporary large files. Per user
  * group ($GROUP_DIR) -- /afs/rhic/rhstar/group/: common compiled softwares, environments, utilies
  * temp -- /home/temp/<username>: scheduler temporary files, this is where the submitted job is executed. Per user
  * user_web : Access files from web. Per user. Location:
    * /afs/rhic.bnl.gov/star/users/username/www/ (public, accessible from https://www.star.bnl.gov/~username/) and
    * /afs/rhic.bnl.gov/star/doc_protected/www/spin/username (protected, accessible from https://www.star.bnl.gov/protected/spin/username/)
  * user home : Keep all your source code here. Location: /star/u/<username>
  * file systems (FS)
    * Tape: HPSS -- High Performance Storage System
    ```
      hsi	  # to put files on tape  
      # !!! DO NOT use 'hsi' to retrieve files from HPSS - this access mode locks tape drives for exclusive use !!!
      carousel    # recommended: https://drupal.star.bnl.gov/STAR/comp/sofi/tutorials/carousel
    ```
    * NFS: Network FS
      also a GPFS, Generally recently produced data or re-produced data live here. 
      Use 'xrootd' file server to access the files (recommended).
    * GPFS (/star/dataXX/pwg)
      Genral Parallel FS -- allows concurrent access to the same file by multiple nodes
      primary 'work' dir.: keep user defined DST files here.
    * AFS (/afs/rhic/star/users/<username>): Andrew FS
      for shared files
    * local (/home/starlib/ or /star/u/<username>)
      the cache dir. and your home dir. are refered to as local.
      It has been made mandatory to use xrootd to access file from local disk.
    * xrooted: a file server that maps the filename to the read content stored in distributed disks.
      The disks connected to 'xrooted' file server is commonly referred to as distributed disks.
      ```
      root root://xrdstar.rcf.bnl.gov:1095/<file_path>
      xrdcp root://xrdstar.rcf.bnl.gov:1095/<file_path> <destination>	# cp xrooted file to your local dir.
      ```
      * Even restored files on the cache ( /home/starlib/home/stareco/reco/... ) are not
        accessible directly. You need to use root://xrdstar.rcf.bnl.gov:1095/ prefix in
        MuDstMaker() or in the file-list fed to MuDstMaker() even in direct condor job or xrood
        tag in star-scheduler XML file. This prefix is not necessary for the hpss_user.pl utility.
      * If you mention files under the Inputfiles tag in condor job description, I thing that would
        not need xrood prefix. 

### File Management
  * [Disk space](https://monitoring.sdcc.bnl.gov/Facility/GCE/GPFS/)
  * [Machine monitoring](http://www.star.bnl.gov/cgi-bin/protected/nova/showMachines.pl)

## File Types
* Scaler file: scaler.run*.hist.dat
* Trigger data file: .dat
* EVP file (single event DAQ file): .<event_number>
* DAQ file: .daq
* StEvent file: .event.root
* MuDst
  * has all the collision data
  * trigger info: ZDC, BBC, VPD, EMC etc.
  * track info:
    * fit points in tracker
    * momentum
    * dE/dx
    * charge
    * global or primary type
    * DCA to vertex
    * etc.
* PicoDst
  * developed by the LBNL group (originally for private usage)
  * smaller compared to MuDst
  * contain the essential information for most of the physics analyses
  * store data in vanilla (plain) ROOT
  * allow to work in STAR-independent environment
  * work with ROOT 5/6, Windows, Linux, MacOS

## [File Catalog](https://drupal.star.bnl.gov/STAR/comp/sofi/filecatalog/user-manual)
  * extract file
  ```
  get_file_list.pl [-all] -keys keyword[,keyword,...] 
  [-cond keyword=value[,keyword=value,...]] [-start #] [-limit #] [-delim $St] \
  [-onefile] [-o outputfile]
  ```
  Example
  ```
  get_file_list.pl -keys 'path,filename' -cond 'trgsetupname=AuAu_200_production_low_2014,available=1,filetype=daq_reco_MuDst,sanity=1,filename~st_physics_14,storage=local' -onefile -delim '/'
  get_file_list.pl -keys 'path,filename' -cond 'production=P15ik,filetype=daq_reco_MuDst,trgsetupname=production_pp200trans_2015,filename~st_fms,runnumber[]16068037-16068037,sanity=1,storage!=HPSS']
  ```
  * keywords
  runnumber=XXX	  # for a specific run
  runnumber[]XXX1-XXX2	# for a range of runs
  sanity
------------------------------------------------------------------------------
# Example
* Download daq files from HPSS to RCF using 'Data Carousel'
```
  hpss_user.pl -f file.list
```
* Determine the STAR version you want and switch to it
```
  starver SL17d
```
* Figure out the chain options you would like to use, which controls database, geometry, vertex finder algorithm, reconstruction code, etc
```
  DbV20171001 pp2017a StiCA btof mtd mtdCalib PicoVtxDefault fmsDat fmsPoint fpsDat BEmcChkStat OSpaceZ2 OGridLeak3D
```
* Run the following command
```
  root4star -b -q -l 'bfc.C(10,”CHAIN_OPTIONS",”DAQ_FILE")'
```
* Output MuDst and PicoDst files have the same name as the input daq file
* Analysis

------------------------------------------------------------------------------
# [Scheduler](http://www.star.bnl.gov/public/comp/Grid/scheduler/)

------------------------------------------------------------------------------
# Resource
 * [STAR papers](https://drupal.star.bnl.gov/STAR/publications/)
 * [STAR analysis notes](https://drupal.star.bnl.gov/STAR/starnotes)
 * [STAR theses](https://drupal.star.bnl.gov/STAR/theses)
 * [STAR conference presentations](https://drupal.star.bnl.gov/STAR/presentations/)
 * spin blog: /afs/rich/star/doc_protected/www/spin
  > kinit
  > aklog

* BNL cloud -- [BNL box](https://bnlbox.sdcc.bnl.gov/index.php)
