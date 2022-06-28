#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc/*argument count*/, char* argv[]/*argument vector*/)
{
	//to store the argument add a char* and set it = to the argv[] index that you choose
        char* argument;
	argument = argv[0];
	//when a c program expects an argument it will fail with segmentation fault if no argument is given on default
	//deal with this by setting logic for how many arguments you expect
	if (argc = 1)//the executable (in this case ./args) is treated as argc = 1
	{
		printf("argument 1:	%s\n", argv[0]);//whereas in the argv it is stored at index 0
		printf("argument:	%s\n", argument);
	}
	if (argc = 2)
	{
		printf("argument 2:	%s\n", argv[1]);
		argument = argv[1];
		printf("argument:       %s\n", argument);
	}
	return 0;
}
