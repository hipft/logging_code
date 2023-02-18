#include <stdio.h>
#include <stdlib.h>

#define LOG_ERRORS            1  // 2^0, bit 0
#define LOG_WARNINGS          2  // 2^1, bit 1
#define LOG_DEBUG             4  // 2^2, bit 2

//ignore the following definition for now. Trust that it works.
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int main() {
	unsigned char flags;
	//set the flag bits and print them
	flags = LOG_ERRORS;
	printf("Flag bits:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flags));
	printf("\n");
	flags = LOG_ERRORS|LOG_WARNINGS;
	printf("Flag bits:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flags),"\n");
	printf("\n");

	//now check if the LOG_WARNINGS flag is set. LOG_WARNINGS is set above, so it will be TRUE
	if ((flags & LOG_WARNINGS) == LOG_WARNINGS) {
		printf("WARNINGS Flag is set!\n");
	}
	else {
		printf("WARNINGS Flag is not set \n");
	}

	printf("Flag bits:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flags),"\n");
	printf("\n");
	//now check if the LOG_DEBUG flag is set. We never set it, so it will be FALSE
	if ((flags & LOG_DEBUG) == LOG_DEBUG) {
		printf("DEBUG Flag is set!\n");
	}
	else {
		printf("DEBUG Flag is not set \n");
	}

	//now set it
	flags ^= LOG_DEBUG;
	printf("Flag bits:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flags),"\n");
	printf("\n");
	//now check if the LOG_DEBUG flag is set. We never set it, so it will be FALSE
	if ((flags & LOG_DEBUG) == LOG_DEBUG) {
		printf("DEBUG Flag is set!\n");
	}
	else {
		printf("DEBUG Flag is not set \n");
	}
}
