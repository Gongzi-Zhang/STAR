* how to do a simulation
    * generator --> RHIC tuning --> Physical process --> Filter --> Geant --> 
      Reconstruction

* what information get saved and how? -- data structure
    * generator: StarGenEvent 
    * StarPrimaryMaker: ROOT output with StarGenEvent, St_g2t_event for geant_Maker
    * St_geant_Maker: St_g2t_event, St_g2t_vertex, St_g2t_track, St_g2t_xxx_hit
* detector response, cross talk, electronics, etc.
* online conditions: pedestals, gain, status tables, etc.
* interface for offline reconstruction, like cluster finders

* GEANT3 based

# Procedure
* AgML geometry + mis-alignment == GEANT Simulation
* GEANT Simulation + status, gains, peds == Detector Simulation ==> hits ==> Reconstruction


# Components
* AgML [2012]
  * geometry description
* StarGenerator [2013]
  * Provides uniform interface for event generators in STAR, event record
  * Supports pythia6, pythia8, hijing, herwig, starlight, kinematics, etc.
* StarDecayManager [2015]
  * Provides support for external decayers
  * Pythia8 decayer, EvtGen from 2016
    * e.g. Bc+ → J/psi e+ nu, D0 → K-pi+, D0→ K-pi+pi+pi-, ...
* AgML 2.0 [2016] 
  * improved data model, versioning support
* Misalignment Support [2017]
  * AgML extended to support misalignments of both active and passive detector 
    elements usintables stored in STAR DB
  * Enables precision simulation / embedding in silicon tracking detectors (HFT, FTS, …)

# Embedding
  * hits + minbias/zerobias == Event Mixer ==> Reconstruction
  * Account for the systematics associated with hardware noise, detector pileup, 
    and the collision and ambient backgrounds present during experimental operations
  * Technique
    * Simulate an event of interest (hijing, pythia, single particle,...)
    * Merge the output of the slow simulators in each hardware channel with the 
      readout from a real triggered event at STAR (zero bias or minimum bias)
  * Software Requirements
    * Slow simulator is essential to properly account dead channels, low gains, 
      and fully exploit the physics potential of the data
    * Mixer is responsible for merging signals from simulated and triggered events
    * Accurate geometry model accounting for the misalignments of the active 
      material and dead layers in the detector setup
  * Misalignments
    * Ultimate resolution, efficiency of high precision trackers depend on 
      simulation of the small deviations of the actual detector from the ideal desi
    * AgML provides support for application of detector misalignments during 
      the construction of the geometry model, enabling precision simulations
