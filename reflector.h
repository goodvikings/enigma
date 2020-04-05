#ifndef REFLECTOR_H
#define REFLECTOR_H

#define REFLECTOR_A 0
#define REFLECTOR_B 1
#define REFLECTOR_C 2

class reflector
{
public:
	reflector(int wiring);
	~reflector();

	char encipher(const char input) const;

	void dump() const;
private:
	char* wiring;
	static const int WIRINGLEN = 27;
};

#endif