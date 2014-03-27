#include <stdlib.h> //included for malloc (might be used in mystrdup

int mystrlen(const char* s) 
{
	const char *sc;

	for (sc = s; *sc; s++); // will increase s everytime it goes around the loop
	return(sc - s); // return sc - s has it starts from sc, so it started in an advanced position.
}

int mystrncmp(const char *s1, const char *s2, int n) 
{
    //here goes your code
}

int mystrcmp(const char *s1, const char *s2) 
{
	//here goes your code
}

char *mystrncpy(char *dst, const char *src, int n)
{
	//here goes your code
}

char *mystrcpy(char *dst, const char *src)
{
	//here goes your code
}


char *mystrdup(const char *src) 
{
    //here goes your code
}
