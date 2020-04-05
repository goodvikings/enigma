#include <assert.h>
#include <cstring>
#include "reflector.h"

#ifdef DEBUG
#include <iostream>
#endif

static const char wirings[3][27] = {
	"EJMZALYXVBWFCRQUONTSPIKHGD", // A
	"YRUHQSLDPXNGOKMIEBFZCWVJAT", // B
	"FVPJIAOYEDRZXWGCTKUQSBNMHL"  // C
};

reflector::reflector(const int wiring)
{
	assert(wiring >= 0 && wiring <= 2);
	this->wiring = new char[WIRINGLEN];
	memcpy(this->wiring, wirings[wiring], WIRINGLEN);
}

reflector::~reflector()
{
	delete [] wiring;
}

char reflector::encipher(const char input) const
{
	char entryPoint = input - 'A';
	assert(entryPoint >= 0 && entryPoint <= 25);
#ifdef DEBUG
	std::cout << "Entered reflector as " << input << " exited as " << char(wiring[entryPoint]) << std::endl;
#endif
	return (wiring[entryPoint]);
}

void reflector::dump() const
{
#ifdef DEBUG
	std::cout << "Wiring:\n";
	std::cout << "\t" << "00000000001111111111222222" << "\n";
	std::cout << "\t" << "01234567890123456789012345" << "\n";
	std::cout << "\t" << this->wiring << "\n";
#endif
}
