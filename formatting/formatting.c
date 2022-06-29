#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <float.h>
int main()
{
	//shorts
	printf("signed short min:            	%hi\n", (signed short) SHRT_MIN);
	printf("unsigned short max:		%hu\n", (unsigned short) USHRT_MAX);
	printf("signed short max:         	%hi\n", (signed short) SHRT_MAX);
	//ints
	printf("signed int max:               	%d\n", (int) INT_MAX);
	printf("unsigned int max:             	%u\n", (unsigned int) UINT_MAX);
	//longs
	printf("long max:               	%ld\n", (long) LONG_MAX);
	printf("unsigned long max:              %lu\n", (unsigned long) ULONG_MAX);
	//chars
	printf("character bit:              	%d\n", (char) CHAR_BIT);
	printf("character bit max:              %d\n", (char) CHAR_MAX);
	printf("character bit min:              %d\n", (char) CHAR_MIN);
	printf("short character bit max:        %d\n", (char) SCHAR_MAX);
	printf("short character bit min:        %d\n", (char) SCHAR_MIN);
	printf("unsigned character bit max:     %d\n", (unsigned char) UCHAR_MAX);
	//strings
	char string[] =  "this is a string";
	printf("string:				%s\n", string);
	//null formatter
	int c;
	printf("Null formatter:			%n\n", &c);
	printf("Amount of chars before null: 	%d\n", c);
	//floating points 
	//%f can print floating point %e prints scientific notation and %g prints shorter of the two notations
	printf("float min:			%g\n", (float) FLT_MIN);
	printf("negative float min:             %g\n", (float) -FLT_MIN);
	printf("double min:             	%g\n", (double) DBL_MIN);
	printf("float max:                      %g\n", (float) FLT_MAX);
        printf("negative float max:             %g\n", (float) -FLT_MAX);
        printf("double max:                     %g\n", (double) DBL_MAX);
	printf("negative double max:            %g\n", (double) -DBL_MAX);
	printf("long double max:                %Lg\n",(long double) LDBL_MAX); 
	printf("negative long double max:       %Lg\n",(long double) -LDBL_MAX); 
	printf("long double min:                %Lf\n",(long double) LDBL_MIN);
	printf("negative long double min:       %Lf\n",(long double) -LDBL_MIN);
	//octals
	printf("octal				%o\n", 8);
	printf("octal                           %o\n", 16);
	printf("octal                           %o\n", 32);
	printf("octal                           %o\n", 64);
	//hexadecimals
	printf("hexadecimal:			%x\n", 15);
	printf("hexadecimal:                    %x\n", 14);
	printf("hexadecimal:                    %x\n", 13);
	printf("hexadecimal:                    %x\n", 12);
	printf("hexadecimal:                    %x\n", 11);
	printf("hexadecimal:                    %x\n", 10);
	//pointers
	int value = 256;
	int* pointer;
	printf("original value:			%d\n", value);
	printf("value of empty pointer          %p\n", pointer);
	pointer = &value;
	printf("value as pointer(as hex):	%p\n", value); 	//compiler warns us this is a decimal value not a void* 
								//but it will compile since int* is a possibility
	printf("value inside the pointer	%p\n", pointer);
}
