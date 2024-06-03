void genevents(const char* fName = "starsim.kinematics.root")
{
  gROOT->SetBatch(1);
  gStyle->SetOptStat(111110);

  LoadLibrary("StarGeneratorEvent");

  TFile *fin = new TFile(fName, "read");
  TTree *tin = (TTree*) fin->Get("genevents");

  StarGenEvent *event;
  tin->SetBranchAddress("primaryEvent", &event);

  StarGenParticle *prt = 0;
  int id;
  float px, py, pz, pt, p, energy, mass;
  float eta, theta, phi;
  float vx, vy, vz;
  TH1F *hpx = new TH1F("px", "px;GeV", 100, -5, 5);
  TH1F *hpy = new TH1F("py", "py;GeV", 100, -5, 5);
  TH1F *hpz = new TH1F("pz", "pz;GeV", 100, 5, 25);
  TH1F *hpt = new TH1F("pt", "pt;GeV", 100, 0, 5);
  TH1F *henergy = new TH1F("energy;GeV", "energy", 100, 5, 25);
  TH1F *hmass = new TH1F("mass", "mass;GeV", 100, 0, 0.5);
  TH1F *heta = new TH1F("eta", "eta", 50, 2, 5);
  TH1F *hphi = new TH1F("phi", "phi", 50, -3.2, 3.2);
  TH1F *hvx = new TH1F("vx", "vx;cm", 100, -0.5, 0.5);
  TH1F *hvy = new TH1F("vy", "vy;cm", 100, -0.5, 0.5);
  TH1F *hvz = new TH1F("vz", "vz;cm", 200, -100, 100);
  for (int ei=0; ei<tin->GetEntries(); ei++)
  {
    tin->GetEntry(ei);

    for (int pi=0; pi<event->GetNumberOfParticles(); pi++)
    {
      prt = (*event)[pi];
      if (prt->GetStatus() != 1)
	continue;

      px = prt->GetPx();
      py = prt->GetPy();
      pz = prt->GetPz();
      pt = prt->pt();
      p  = sqrt(pt*pt + pz*pz);
      energy = prt->GetEnergy();
      mass = prt->GetMass();
      eta = 0.5*log((energy+pz)/(energy-pz));
      phi = prt->momentum().Phi();

      vx = prt->GetVx();
      vy = prt->GetVy();
      vz = prt->GetVz();
      // cout << "DEBUG\t" << px << "\t" << py << "\t" << pz << "\t" << energy << "\t" << mass << endl;

      hpx->Fill(px);
      hpy->Fill(py);
      hpz->Fill(pz);
      hpt->Fill(pt);
      henergy->Fill(energy);
      hmass->Fill(mass);
      heta->Fill(eta);
      hphi->Fill(phi);
      hvx->Fill(vx);
      hvy->Fill(vy);
      hvz->Fill(vz);

    }
  }

  TCanvas* c = new TCanvas("c", "c", 800, 600);
  hpx->Draw();
  c->SaveAs("px.png");
  hpy->Draw();
  c->SaveAs("py.png");
  hpz->Draw();
  c->SaveAs("pz.png");
  hpt->Draw();
  c->SaveAs("pt.png");
  henergy->Draw();
  c->SaveAs("energy.png");
  hmass->Draw();
  c->SaveAs("mass.png");
  heta->Draw();
  c->SaveAs("eta.png");
  hphi->Draw();
  c->SaveAs("phi.png");
  hvx->Draw();
  c->SaveAs("vx.png");
  hvy->Draw();
  c->SaveAs("vy.png");
  hvz->Draw();
  c->SaveAs("vz.png");
}
