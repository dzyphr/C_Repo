#include <stdio.h>
#include <string.h>
#define BUFSIZE 65792

int main(int argc, char** argv) 
{
   	char cmd[] = "uname -rs ";   //this will execute in a sub-shell from the current working directory
	char buf[BUFSIZE]; //certain char arrays need a large buffer size to handle arbitrary lengths and prevent cat & cpy failures
    	FILE *fp; //create a file pointer to handle our system command process
    	//note: this technically doesnt make any file, but it acts as a file as does everything on linux
	if ((fp = popen(cmd, "r")) == NULL) //if we cannot open our filepointer throw ->
    	{
    		printf("Error opening pipe!\n");
        	return -1;
    	}
	else //command has been succesfully piped into popen through the file pointer:
	{
		char output[BUFSIZE];
		while (fgets(buf, BUFSIZE, fp) != NULL) //while fgets recieves non-empty data from our filepointer do:
		{
			strcat(output, buf);
		}
		if (pclose(fp)) //check if the current pipe has been closed if so throw ->
		{
			printf("Command not found or exited with error status\n");
			return -1;
		}
		else
		{
			if (strcmp(output, "")==0)//check if the output was null or empty:
			{
				printf("NullOutput");
				//sometimes you may return -1 here but other times you may expect null
				//in those cases you dont want to throw a proccess breaking error so we will not by default
			}
			else //output is not null so we can utilize it effectively:
			{
				printf("%s", output);//utilize the captured output from popen 
			}
		}
	}
}
