starsim (successor of gstar) is a framework for simulating the STAR detector 
based on GEANT, controled through KUIP commands (macros).

# questions

# MC event generator
  * perturbative hard scattering + evolution (parton shower) 
  * nonperturbative processes: hadronization, underlying event and multiparton interactions
## event generator tuning
  * PDF and nuclear PDF
  * α_s(m_Z) ~ 0.130

# (GEANT) physcis process configuration [$STAR/kumacs/sim/set_hadr_phys_on.kumac]
  * Hadr_on    - all Geant Physics On
  * Hadr_off   - hadronic interactions switched off, only electro-magnetic processes are present
  * Decay_Only - only some physics simulated: particle decays, multiple scattering and energy loss
  * Phys_off   - all interactions switched off, except for energy losses

# particles
## id
* 1: final particles
* 4: incoming particles


# geometry
* geometry tag: $STAR/StarVMC/Geometry/StarGeo.xml
