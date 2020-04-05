#ifndef PLUG_H
#define PLUG_H

class plug
{
private:
	char foo;
	char bar;
public:
	plug(char foo, char bar);
	const char translate(const char input);
};

#endif