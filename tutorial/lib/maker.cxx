/* data structure:
 * .make - list of child makers
 * .data - list of owned datasets
 * .hist - list of histograms created in StMaker::Init();
 * .const - collection of constants used by the maker)
 */

virtual Int_t Init(); // Called at the beginning, initialize histograms etc...
virtual Int_t InitRun(); // Called at the start of a new run
virtual Int_t Make(); // Called for every event, do your analysis here, fill histograms
virtual Int_t Clear(); // Used for clearing collections after each Make();
virtual void Finish(); // Finish
virtual Int_t FinishRun(Int_t oldrunumber); // Executed at the end of a run
