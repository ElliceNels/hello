#include <stdio.h>

const char *greeting = "Hello World";

static const char *get_greeting(void)
{
	return greeting;
}

int main(void)
{
	printf(get_greeting());
	return 0;
}
