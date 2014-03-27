#include <stdlib.h> //included for malloc (might be used in mystrdup

int mystrlen(const char* s) 
{
	const char *sc;

	for (sc = s; *sc; s++); // will increase s everytime it goes around the loop
	return(sc - s); // return sc - s has it starts from sc, so it started in an advanced position.
}

int mystrncmp(const char *s1, const char *s2, int n) 
{
    unsigned char uc1, uc2;
	int count = 0;
	
	while (*s1 != '\0' && *s1 == *s2 && count < n)  
	// will stop when s1 reaches null and when s1 and s2 are not the same and if it hasnt gone above the counter.
	{
		s1++; // goes to the next character.
		s2++;
		count++;
	}
	uc1 = (*(unsigned char *) s1); // gets the character at s1 and s2.
	uc2 = (*(unsigned char *) s2);
	return ((uc1 < uc2) ? -1 : (uc1 > uc2)); // if s1 < s2 it will return -1, if s1 > s2 it will return 1 and 0 otherwise.
}

int mystrcmp(const char *s1, const char *s2) 
{
	unsigned char uc1, uc2;
	
	while (*s1 != '\0' && *s1 == *s2)  // will stop when s1 reaches null and when s1 and s2 are not the same.
	{
		s1++; // goes to the next character.
		s2++;
	}
	uc1 = (*(unsigned char *) s1); // gets the character at s1 and s2.
	uc2 = (*(unsigned char *) s2);
	return ((uc1 < uc2) ? -1 : (uc1 > uc2)); // if s1 < s2 it will return -1, if s1 > s2 it will return 1 and 0 otherwise.
}

char *mystrncpy(char *dst, const char *src, int n)
{
	int count  = 0; // used to keep track of the index and to make sure it doesnt go above the limit
	
	while (*s1 != '\0' && count < n) // will stop when s1 reaches null and not gone past the limit
	{
		*dst = *src; // getting the character from the source string.
		
		dst++; // incrementing the to the next character.
		src++;
		count++; // incrementing the index.
	}
	
	*dst = '\0'; // ending the null character on the end.
	
	return dst;
}

char *mystrcpy(char *dst, const char *src)
{
	int count  = 0; // used to keep track of the index
	
	while (*s1 != '\0') // will stop when s1 reaches null
	{
		*dst = *src;  // getting the character from the source string.
		
		dst++;  // incrementing the to the next character.
		src++;
		count++;  // incrementing the index.
	}
	
	*dst = '\0'; // ending the null character on the end.
	
	return dst;
}


char *mystrdup(const char *src) 
{
    char *p = malloc(strlen(s) + 1);// need the added one to be have the null character at the end
	
	if(p)  // if p is valid.
	{ 
		strcpy(p, s); // calling the copy function.
	}
	
	return p;
}
