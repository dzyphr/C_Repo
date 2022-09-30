#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define SIZE 65792
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("\nplease give the filepath to check as an argument\n");
		return -1;
	}
	FILE* fp;
	char* filename;
	char cmd[SIZE];
	//using grep to compare the output of the file to a whitespace character
	char part1[] = "grep -q '[^[:space:]]' < \"";
	//if theres anything in the file 'file_is_NOT_blank'  will be printed
	char part2[] = "\" && printf \'%s\n\' \"file_is_NOT_blank\"";
	strcat(cmd, part1);
	filename = argv[1];
	strcat(cmd, filename);
	strcat(cmd, part2);
	if ((fp = popen(cmd, "r")) == NULL)
	{
		printf("Error opening pipe!\n");
                return -1;
	}
	//printf("%s", cmd);//if the file is blank nothing will be printed
	system(cmd);
	return 0;
}
