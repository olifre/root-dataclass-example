#ifndef TESTOBJ
#define TESTOBJ

#include "TNamed.h"
#include "TLorentzVector.h"

class TestObj : public TNamed {
 protected:
	TLorentzVector lMomentum;

 public:
	TestObj() : lMomentum(0,0,0,0) {};
	virtual ~TestObj() {};

	virtual void Clear(Option_t* opt = "") {
		lMomentum.SetXYZT(0,0,0,0);
	}

	virtual void fSetMomentum(const TLorentzVector& aMomentum) {
		lMomentum = aMomentum;
	}
	virtual const TLorentzVector& fGetMomentum() const {
		return lMomentum;
	}

	ClassDef(TestObj, 1);
};

#endif
