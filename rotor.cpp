#include <assert.h>
#include <cstring>
#include "rotor.h"

#ifdef DEBUG
#include <iostream>
#endif

//                              01234567890123456789012345
static const char st_input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static const char st_wirings[8][27] = {
	"EKMFLGDQVZNTOWYHXUSPAIBRCJ",
	"AJDKSIRUXBLHWTMCQGZNPYFVOE",
	"BDFHJLCPRTXVZNYEIWGAKMUSQO",
	"ESOVPZJAYQUIRHXLNFTGKDCMWB",
	"VZBRGITYUPSDNHLXAWMJQOFECK",
	"JPGVOUMFYQBENHZRDKASXLICTW",
	"NZJHGRCXMYSWBOUFAIVLPEKQDT",
	"FKQHTLXOCBJSPDZRAMEWNIUYGV"
};

static const char st_notches[8][3] = {
	"QQ",
	"EE",
	"VV",
	"JJ",
	"ZZ",
	"MZ",
	"MZ",
	"MZ"
};

rotor::rotor(const int rotorNumber, const int position, const int ringstellung) : ringstellung(ringstellung)
{
	assert(rotorNumber >= 0 && rotorNumber <= 7);
	assert(ringstellung >=0 && ringstellung <= 25);

	this->substitutionTable = new char*[2];
	this->substitutionTable[0] = new char[WIRINGLEN];
	this->substitutionTable[1] = new char[WIRINGLEN];

	memcpy(this->substitutionTable[0], st_input, WIRINGLEN);
	memcpy(this->substitutionTable[1], st_wirings[rotorNumber], WIRINGLEN);

	this->notches = new char[NOTCHESLEN];
	memcpy(this->notches, st_notches[rotorNumber], NOTCHESLEN);
	this->position = 0;

	for (int i = 0; i < position; i++)
	{
		step();
	}
}

rotor::~rotor()
{
	delete [] substitutionTable[0];
	delete [] substitutionTable[1];
	delete [] substitutionTable;
	delete [] notches;
}

bool rotor::step()
{
	bool retVal = isNotched();
	substitutionTable[0][WIRINGLEN - 1] = substitutionTable[0][0];
	substitutionTable[1][WIRINGLEN - 1] = substitutionTable[1][0];
	for (int i = 0; i < WIRINGLEN - 1; i++)
	{
		substitutionTable[0][i] = substitutionTable[0][i + 1];
		substitutionTable[1][i] = substitutionTable[1][i + 1];
	}
	substitutionTable[0][WIRINGLEN - 1] = '\0';
	substitutionTable[1][WIRINGLEN - 1] = '\0';

	position++;
	position %= 26;

	return retVal;
}

bool rotor::isNotched() const
{
	for (int i = 0; i < NOTCHESLEN; i++)
		if (substitutionTable[0][0] == notches[i])
			return true;
	return false;
}

char rotor::encipher(const char input) const
{
	assert(input >= 'A' && input <= 'Z');

	char retVal = substitutionTable[1][input - 'A'] - position;
	if (retVal < 'A') retVal += 26;
//	if (retVal > 'Z') retVal -= 26;

#ifdef DEBUG
	std::cout << "Entered rotor as " << substitutionTable[0][input - 'A'] << ", exited as " << char(retVal + position) << " (actually " << char(retVal) << ")" << std::endl;
#endif

	assert(retVal >= 'A' && retVal <= 'Z');

	return retVal;
}

char rotor::reflectEncipher(const char input) const
{
	assert(input >= 'A' && input <= 'Z');

	char entryPoint = 0;
	bool found = false;
	for (int i = 0; i < WIRINGLEN; i++)
		if (substitutionTable[1][i] == (((input + position - 'A') % 26) + 'A'))
		{
			entryPoint = i;
			found = true;
			break;
		}

	assert(found);
	char retVal = char(substitutionTable[0][entryPoint] - position);
	if (retVal < 'A') retVal += 26;
//	if (retVal > 'Z') retVal -= 26;

#ifdef DEBUG
	std::cout << "Entered (inverse) rotor as " << char(input + position) << " exited as '" << retVal << "'" << std::endl;
#endif
	assert(retVal >= 'A' && retVal <= 'Z');

	return retVal;
}

void rotor::dump() const
{
#ifdef DEBUG
	std::cout << "Wiring:\n";
	std::cout << "\t" << "00000000001111111111222222" << "\n";
	std::cout << "\t" << "01234567890123456789012345" << "\n";
	std::cout << "\t" << this->substitutionTable[0] << "\n";
	std::cout << "\t" << this->substitutionTable[1];
	std::cout << "\nPosition: ";
	std::cout <<  this->position;
	std::cout << "\nRingstellung: ";
	std::cout << this->ringstellung << std::endl;
#endif
}
