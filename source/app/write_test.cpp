#include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "TClonesArray.h"
#include "TProcessID.h"

#include "testobject.h"

int main(int argc, char** argv) {
	TFile testFile("test.root", "RECREATE");
	TTree dataTree("Output", "Output");

	TClonesArray particles(TestObj::Class(), 100);

	dataTree.Branch("particles", &particles, 32768);

	for (Int_t e=0; e<100000; e++) {
		// For each "event".
		UInt_t objCount = TProcessID::GetObjectCount();

		TestObj* party = static_cast<TestObj*>(particles.ConstructedAt(0));
		party->fSetMomentum(TLorentzVector(1, 1, gRandom->Gaus(0.5, 1), 1));

		dataTree.Fill();

		particles.Clear("C");

		TProcessID::SetObjectCount(objCount);
	}

	dataTree.Write();

	TestObj* globalParty = new TestObj();
	globalParty->SetName("testparticle");
	globalParty->fSetMomentum(TLorentzVector(1, 1, gRandom->Gaus(0.5, 1), 1));
	globalParty->Write();

	testFile.Close();

	return 0;
}
