#ifndef ENIGMA_H
#define ENIGMA_H

#include "plug.h"
#include "reflector.h"
#include "rotor.h"

class enigma
{
public:
	enigma(rotor* left, rotor* centre, rotor* right, reflector* reflector, const plug* plugboard, const int plugboardLen);
	~enigma();

	char encipher(const char input);

	void dump();
private:
	rotor* left;
	rotor* centre;
	rotor* right;	
	reflector* reflect;
	const plug* plugboard;
	int plugboardLen;
};

#endif