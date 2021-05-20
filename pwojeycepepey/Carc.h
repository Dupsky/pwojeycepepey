#pragma once
class Carc
{
private:
	unsigned int destination;
public:
	Carc(unsigned int destination);
	~Carc();
	void ARCModifDest(unsigned int uiArg);
	unsigned int getDest();
};

