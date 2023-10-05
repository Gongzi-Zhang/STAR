* ROOT/TGeo based
* Tracking finding:
  * Kalman Track filter (KF)
  * CA + KF: what is CA?
    * Seeds are formed in the last three layers (disks or wheels)
    * Seed is fit to a helix
    * Propagate inwards along the helix
      * Add best hit found within an uncertainty band around the track prediction
      * Except for outermost layer, hits may be used on multiple tracks
    * Track finding complete once all hits in outermost layer have been visited)
  * Once all track candidates have been found, hits are uniquely assigned to the 
    “best” track, based on length and chi2. Tracks with fewer than 4 hits are eliminated.
  * Resulting global tracks refit with the MC vertex to form primary tracks.
