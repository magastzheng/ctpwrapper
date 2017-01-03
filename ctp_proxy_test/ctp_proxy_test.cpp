// ctp_proxy_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ctp_proxy/util.h"
#include "../ctp_proxy/CTPQuote.h"

const char fmt[] = "Address: %x, value: %s ";
//int copyarray(char *dest[], const char *src[]);
int copyarray(char *dest[], char *src[], int total, int num)
{
	if(NULL == src)
	{
		return -1;
	}

	//int each = sizeof(src[0]);
	//int total = sizeof(src);
	//int num = total / each;
	/*dest = new char*[total];*/

	for(int i = 0; i < num; i++)
	{
		//strcpy_s(dest[i], sizeof(src[i]), src[i]);
		//dest[i] = src[i];
		dest[i]=src[i];
	}

	

	return 0;
}

int skip_atoi(const char **s)
{
	int i, c;

	for (i = 0; '0' <= (c = **s) && c <= '9'; ++*s)
		i = i*10 + c - '0';
	return i;
}

char** char2array(int num)
{
	char **strings = (char **)malloc(num*sizeof(char *));
	strings[0] = "UWC";
	strings[1] = "Bellvine";
	strings[2] = "Cape Town";

	for(int i = 0; i < num; i++)
	{
		printf(fmt, strings[i], strings[i]);
	}
	printf("\n");
	return strings;
}

char** char2arrayv2(int num)
{
	char **strings = (char **)malloc(num*sizeof(char *));
	int length = (strlen("Magast") + 1) * sizeof(char);
	strings[0] = (char *)malloc(length);
	strcpy_s(strings[0], length, "Magast");

	length = (strlen("Had") + 1) * sizeof(char);
	strings[1] = (char *)malloc(length);
	strcpy_s(strings[1], length, "Had");

	length = (strlen("Finished") + 1) * sizeof(char);
	strings[2] = (char *)malloc(length);
	strcpy_s(strings[2], length, "Finished");

	for(int i = 0; i < num; i++)
	{
		printf(fmt, strings[i], strings[i]);
	}
	printf("\n");
	return strings;
}

void printdata(char **data, int num)
{
	for(int i = 0; i < num; i++)
	{
		printf(fmt, data[i], data[i]);
	}
	printf("\n");
}

void testcopyarray()
{
	char *p1="hello world";
	char *p2="hello world";

	char *str[] = {"This", "is", "Haitong", "Asset", "Management", "Company", "in", "Shanghai", "China"};
	char **p = str;
	int each = sizeof(str[0]);
	int total = sizeof(str);
	int num = total / each;
	for(int i = 0; i < num; i++)
	{
		printf("%x, %s\n", p, *(p));
		p++;
	}

	char **dest = (char**)malloc(sizeof(*dest) * num);
	for(int i = 0; i < num; i++)
	{
		dest[i] = (char*)malloc(each);
	}
	//dest = new char*[total];

	//char **dest = (char**)malloc(sizeof(*dest) * num);;
	copyarray(dest, str, total, num);

	int dataLen = 3;
	char** data = char2array(dataLen);
	//int skip_atoi((const char **)p);
	total = sizeof(data);
	each = sizeof(char *);
	//num = total/each;
	printdata(data, dataLen);

	data = char2arrayv2(dataLen);
	printdata(data, dataLen);

	while(true)
	{
		data = copypointerarray(str, num);
		printdata(data, num);
		freepointerarray(data, num);
	}

	printf("dest: %x\n", dest);
	printf("p1: %x\t p2: %x\n", p1, p2);
}

int cb_ctp_connected()
{
	printf("cb_ctp_connected\n");

	return 0;
}

void test_ctp_proxy()
{
	CTPManager *mgr = CreateAPI();
	RegOnFrontConnected(mgr, cb_ctp_connected);
	int ret = Init(mgr, "tcp://test.com");

	ReqUserLogin(mgr, "1234", "1234", "1234");
}

int _tmain(int argc, _TCHAR* argv[])
{
	test_ctp_proxy();

	return 0;
}



