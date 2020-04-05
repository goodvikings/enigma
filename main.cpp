#include <iostream>
#include "enigma.h"
#include "plug.h"
#include "reflector.h"
#include "rotor.h"
using namespace std;

int main(int argc, char** argv)
{
	enigma* e;

	rotor* left = NULL;
	rotor* centre = NULL;
	rotor* right = NULL;
	reflector* ref = NULL;
	plug* plugboard = NULL;

	left = new rotor(ROTOR_III, 0, 0);
	centre = new rotor(ROTOR_II, 25, 0);
	right = new rotor(ROTOR_I, 0, 0);
	ref = new reflector(REFLECTOR_B);
	plugboard = NULL; /*new plug[13] {
		{'A', 'B'},
		{'C', 'D'},
		{'E', 'F'},
		{'G', 'H'},
		{'I', 'J'},
		{'K', 'L'},
		{'M', 'N'},
		{'O', 'P'},
		{'Q', 'R'},
		{'S', 'T'},
		{'U', 'V'},
		{'W', 'X'},
		{'Y', 'Z'}
	};*/

	e = new enigma(left, centre, right, ref, plugboard, 0);

	int x = 0;
	for (int n = 0; n < 10; n++) {
		for (int i = 'A'; i < 'Z' + 1; i++) {
			cout << e->encipher(i);
			if (x++ == 4) {
				cout << " ";
				x = 0;
			}
		}
	}

	delete e;
	delete left;
	delete centre;
	delete right;
	delete ref;
	delete [] plugboard;

	return 0;
}
