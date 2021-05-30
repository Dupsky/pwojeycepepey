#pragma once
class Carc
{
private:
	unsigned int uiDest;
public:
	Carc();
	Carc(unsigned int uiDest);
	~Carc();
	void ARCModifDest(unsigned int uiArg);
	unsigned int ARCDest();
};

