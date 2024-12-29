#pragma once
#include "Base.h"

class SharedData
{
	int *selectedBase;
	std::vector<Base> *bases;

public:
	SharedData() { *selectedBase = 0; bases = new std::vector<Base>; }
	void initBases() { *bases = Base::getExampleBases(); }
	int *getSelectedBaseIndex() { return selectedBase; }
	std::vector<Base>* getBases() { return bases; }
	Base& getSelectedBaseInfo() { return (*this->bases)[*selectedBase]; }
	void setSelectedBaseIndex(int base) { *this->selectedBase = base; }
	void setBases(std::vector<Base> bases) { *this->bases = bases; }
};

