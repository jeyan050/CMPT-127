#include <stdio.h>
#include <limits.h>
 
int main( void ) 
{
	int charBits = sizeof(char)  * CHAR_BIT;
	int unSignCharBits = sizeof(unsigned char)  * CHAR_BIT;
	int intBits = sizeof(int)  * CHAR_BIT;
	int unSignIntBits = sizeof(unsigned int)  * CHAR_BIT;
	int longBits = sizeof(long)  * CHAR_BIT;
	int unSignLongBits = sizeof(unsigned long)  * CHAR_BIT;
	int floatBits = sizeof(float)  * CHAR_BIT;
	int doubleBits = sizeof(double)  * CHAR_BIT;
	int longDoubleBits = sizeof(long double)  * CHAR_BIT;

	printf("%u %u %u %u %u %u %u %u %u\n", charBits, unSignCharBits, intBits, unSignIntBits, longBits, unSignLongBits, floatBits, doubleBits, longDoubleBits);
}
