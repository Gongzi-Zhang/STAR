// StMuDstMaker
StMuDstMaker *muDstMaker = new StMuDstMaker( int mode,
					     int nameMode,
					     const char *dirName="./",
					     const char *fileName="",
					     const char *filter=".",
					     int maxfiles=10,
					     const char *name="MuDst" );
/* mode: 0--read; 1--write
 * nameMode: 0--read from inFile; 1--ioMaker
 * dirName: 
 * filename: name of .root file or filelist
 * filter:
 * maxfiles: max # of .root files to chain
 * name: 
 */

// reading events
while ( !muDstMaker->Make() )
{
    // Do 'event' analysis based on event pointers
   StMuEvent* muEvent = muDstMaker -> muDst()-> event();
   cout << muEvent -> primaryVertexPosition().z() << endl;
   // Get 'track' data, make cuts on tracks, do physics analysis
   TObjArray* tracks = muDstMaker -> muDst()-> primaryTracks();
   TObjArrayIter GetTracks(tracks);
   StMuTrack* track ;
   while ( ( track = (StMuTrack*)GetTracks.Next() ) ) // Main loop for Iteratin)))) {
     cout << track->pt() << endl;
}

// MuEvent
StMuEvent *muEvent = mMuDstMaker->muDst()->event();
muEvent->refMult();
muEvent->primaryVertexPosition().z();
muEvent->magneticField();
muEvent->ctbMultiplicity();
muEvent->triggerIdCollection();
muEvent->fpdCollection();

// MuTrack
StMuTrack *muTrack = (StMuTrack*) GetTracks.Next();
muTrack->eta(); // pseudorapidity
muTrack->phi(); // az.angle (radians)
muTrack->pt(); // transverse mom.
muTrack->charge(); // +1 or -1
muTrack->nHits(); // TPC hits
muTrack->nHitsFit(); // TPC hits used in fit

muTrack->dcaGlobal(); // StThreeVectorF
muTrack->momentum(); // StThreeVectorF
muTrack->helix(); // StPhysicalHelixD

muTrack->pidProbPion(); // 0. <= pidProb <= 1.0
muTrack->nSigmaKaon();	// nSigma (bethe-bloc)
