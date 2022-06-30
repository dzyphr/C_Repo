#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
	int exists(const char* fname, bool exists)// this function can easily be abstracted away from the main entrypoint if needed
	{
		if (access(fname, F_OK) == 0)// access will compare fname with F_OK and return 0 if true
		{
			return exists = true;
		}
		else
		{
			return exists = false;
		}
	}
	bool does_exist = false;
	if (argc >= 2)
	{
		does_exist = exists(argv[1], does_exist);// this will check if the argument given is an existing file
	}
	else
	{
		printf("\nplease give one argument that is the file you are checking for\n");
		exit(1);
	}
	// because int exists returns a boolean and we set it = bool does_exist, we can rely on does_exist for the answer
	if (does_exist == true)
	{
		printf("\n the file %s exists!\n\n", argv[1]);
	}
	else
	{
		printf("\n the file %s does not exist!\n\n", argv[1]);
	}
	return 0;
}
