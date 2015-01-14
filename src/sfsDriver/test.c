#include "stdio.h"
#include "rawio.h"

int main(int argc, char *argv[])
{
	rio_init(argv[1]);
	char *read = rio_read_block(0,1);
	if(read)
	{
		printf(read);
	}
	else
	{
		printf("returned null");
	}
	
	return 0;
}
