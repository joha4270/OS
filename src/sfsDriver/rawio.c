#include "stdio.h"
#include "stdlib.h"
FILE * rio_fpointer;
void rio_init(const char *imgfile)
{
	rio_fpointer = fopen(imgfile,"r+");
	if(!rio_fpointer)
	{
		perror("failed to open");
		exit(1000);
	}
	return;
}
char *rio_read_block(int block, int lenght)
{
	if(!rio_fpointer)
	{
		printf("file pointer missing");
		return NULL;
	} 
	
	char *buff = malloc(lenght * 512);

	if(!buff)
	{
		printf("buffer failed to allocate");
		return NULL;
	}
	
	size_t result = fread(buff, 1, lenght * 512, rio_fpointer);
	if(result != lenght * 512)
	{
		free(buff);
		printf("result don't equals expected size %i, returned size %i", lenght * 512, result);
		return NULL;
	}

	return buff;
}
