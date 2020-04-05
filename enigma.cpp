#include <assert.h>
#include "enigma.h"

#ifdef DEBUG
#include <iostream>
#endif

enigma::enigma(rotor* left, rotor* centre, rotor* right, reflector* reflector, const plug* plugboard, int plugboardLen)
{
	assert(left && centre && right && reflector && plugboardLen >= 0 && plugboardLen <= 13);
	
	this->left = left;
	this->centre = centre;
	this->right = right;
	this->reflect = reflector;
	this->plugboard = plugboard;
	this->plugboardLen = plugboardLen;
}

enigma::~enigma()
{
}

void enigma::dump()
{
#ifdef DEBUG
	std::cout << std::endl << "right:" << std::endl;
	this->right->dump();
	std::cout << std::endl << "centre:" << std::endl;
	this->centre->dump();
	std::cout << std::endl << "left:" << std::endl;
	this->left->dump();
	std::cout << std::endl << "reflector: " << std::endl;
	this->reflect->dump();
	std::cout << std::endl;
#endif
}

char enigma::encipher(const char input)
{
	// Increment the rotor(s)
	bool leftNotched = false;

	if (right->step() || centre->isNotched())
		leftNotched = centre->step() || left->isNotched();
	if (leftNotched)
		left->step();

	dump();

	// Pass the input through each wheel, the reflector, and back
	char foo = right->encipher(input);
	foo = centre->encipher(foo);
	foo = left->encipher(foo);
	foo = reflect->encipher(foo);
	foo = left->reflectEncipher(foo);
	foo = centre->reflectEncipher(foo);
	foo = right->reflectEncipher(foo);
	return foo;
}
