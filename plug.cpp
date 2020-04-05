#include <assert.h>
#include "plug.h"

plug::plug(char foo, char bar)
{
	assert(foo >= 'A' && foo <= 'Z' && bar >= 'A' && bar <= 'Z');
	this->foo = foo;
	this->bar = bar;
}

const char plug::translate(const char input)
{
	assert(input >= 'A' && input <= 'Z');
	return input == foo ? bar : input == bar ? foo : input; 
}
