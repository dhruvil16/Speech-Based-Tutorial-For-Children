#include "StdAfx.h"
#include <stdlib.h>
#include <stdio.h>
static int* read_actual_label(){
	int* actual_result = (int*)malloc(sizeof(int) * 10);
	FILE* fp = fopen("verify.txt","r");
	for(int i = 0; i < 10; i++)
	{
		fscanf(fp,"%d",actual_result+i);
	}
	return actual_result;
}