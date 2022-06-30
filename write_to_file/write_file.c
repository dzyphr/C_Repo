#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	char* text;
	if (argc >= 2)
	{
		text = argv[1];
	}
	else
	{
		printf("please give atleast one argument");
	}
	FILE* fptr;//create a file pointer
	fptr = fopen("newfile.file", "w");//open a new file with fopen, set it = to file pointer
	//check for an error with the new file 
	if(fptr == NULL)
	{
		printf("error");
		exit(1);
	}
	fprintf(fptr, "%s", text);//using fprintf write the string data in the 'text' variable  to the file pointer
	fclose(fptr);//close the file pointer
	return 0;
}

