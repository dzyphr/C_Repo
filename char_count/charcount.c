#include <string.h>
#include <stdio.h>
int charCount(char* string);
int main(int argc, char* argv[])
{
	switch (argc)
	{
		case 1:
			printf("enter characters to count as argument\nEx:\n./charcount charactersthatwillbecounted\n");
			printf("to check a string with spaces use single quotes.\nEx:\n./charcount 'characters that will be counted'\n");
			return -1;
		case 2:
			charCount(argv[1]);
	}
}

int charCount(char* string)
{
	int charcount = strlen(string);
	printf("%d", charcount);
}
