#include "Carc.h"

Carc::Carc(unsigned int destination) {
	this->destination = destination;
}

Carc::~Carc() {
}

void Carc::ARCModifDest(unsigned int uiArg) {
	this->destination = uiArg;
}
unsigned int Carc::getDest()
{
	return this->destination;
}