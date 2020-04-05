#ifndef ROTOR_H
#define ROTOR_H

// 0 index arrays yo
#define ROTOR_I 0
#define ROTOR_II 1
#define ROTOR_III 2
#define ROTOR_IV 3
#define ROTOR_V 4
#define ROTOR_VI 5
#define ROTOR_VII 6
#define ROTOR_VIII 7

class rotor
{
public:
	rotor(const int rotorNumber, const int position, const int ringstellung);
	~rotor();

	bool step();
	bool isNotched() const;

	char encipher(const char input) const;
	char reflectEncipher(const char input) const;

	void dump() const;
private:
	char** substitutionTable;
	char* notches;
	int position;
	const int ringstellung;
	static const int WIRINGLEN = 27;
	static const int NOTCHESLEN = 3;
};

#endif