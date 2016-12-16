#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
* copy the data from the 2d array. It will allocate the memory in heap then return the memory address after copying the data.
**/
char** copypointerarray(char **src, int size)
{
	int length = 0;
	char **dest = (char **)malloc(size * sizeof(char *));

	for(int i = 0; i < size; i++)
	{
		length = strlen(src[i]) + 1;
		dest[i] = (char *)malloc(length);

		strcpy_s(dest[i], length, src[i]);
	}

	return dest;
}

void freepointerarray(char **src, int size)
{
	if(NULL == src)
	{
		return;
	}

	for(int i = 0; i < size; i++)
	{
		if(NULL != src[i])
		{
			free(src[i]);
		}
	}

	free(src);
}