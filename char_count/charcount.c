#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFSIZE 65792
int clean(char* folderpath)
{
	char rm[BUFFSIZE] = "rm -r ";
	strcat(rm, folderpath);
	char* command = rm;
	system(command);
}

char* getHomePath(char homepath[])
{
	char* result;
	char buffer[BUFFSIZE];
	char* goHome = "echo ~/";
	FILE* fp;
	if ((fp = popen(goHome, "r")) == NULL)
	{
		printf("error opening pipe\n");
		exit(1);
	}
	char output[BUFFSIZE];
	while (fgets(buffer, BUFFSIZE, fp) != NULL)
	{
		strcat(output, buffer);
	}
	if (pclose(fp))
	{
		printf("Command not found or exited with error status\n");
		exit(1);
	}
	if (strcmp(output, "")==0)
	{
		printf("NullOutput");
	}
	else
	{
		strcpy(homepath, output);
	}
	homepath[strlen(homepath)-1] = '\0';//get rid of the newline added by popen
	result = homepath;
	return result;
}

char* setDir(char* home)
{
	char* tmpdir = "CCTMP/";
	char* result = strcat(home, tmpdir);
	return result;
}

char* makeTempDir(char dir[])
{
	char* dirpassback = dir;
	char mkdir[BUFFSIZE] = "mkdir ";
        char* maketmpdir = strcat(mkdir, dir);
	system(maketmpdir);
	return dirpassback;
}

char* writeTempFile(char dir[], char* characters)
{
	char* TMP = "CC.TMP";
	char filepath[BUFFSIZE];
	strcpy(filepath, dir);
	strcat(filepath, TMP);
	FILE* fptr = fopen(filepath, "w");
	if (fptr == NULL)
	{
		printf("error opening %s for writing", filepath);
		clean(dir);
		exit(1);
	}
	else
	{
		fprintf(fptr, "%s", characters);
		fclose(fptr);
	}
	char* result = filepath;
	return result;
}

int countCharacters(char filepath[])
{
	char wc[BUFFSIZE] = "wc -c ";
	char* command= strcat(wc, filepath);
	system(command);
}

int main(int argc, char* argv[])
{
	//c->bash program to count small-mid strings using a temp file
	//assumes NO NEWLINES OR ESCAPE SEQUENCES
	//SURROUND WITH '' IF USING SPACES example ./cc 'an example'
	if (argc > 1)
	{
		char* characters = argv[1];
		
		char homepath[BUFFSIZE];
		char* home = getHomePath(homepath);
		
		char dir[BUFFSIZE];
	        strcpy(dir, setDir(home));

		strcpy(dir, makeTempDir(dir));

		char filepath[BUFFSIZE];
	       	strcpy(filepath, writeTempFile(dir, characters));	
	
		countCharacters(filepath);	
		
		clean(dir);
	}
	else
	{
		printf("provide the character string you want to check\n");
		printf("assumes NO NEWLINES OR ESCAPE SEQUENCES\nSURROUND WITH '' IF USING SPACES\nexample:\n./cc 'an example'\n");
	}
}
