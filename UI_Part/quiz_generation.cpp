#include "StdAfx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include<time.h>

void static quiz_file_generate(){
	char path[50];
	char digit[4];
	srand(time(0));
	int num = 0;
	FILE* fp_verify = fopen("verify.txt","w");
	FILE* fp = fopen("quiz.txt","w");
	for(int i = 0; i < 10; i++)
	{
		strcpy(path,"Images/");
		num = rand() % 20;
		sprintf(digit,"%d",num);
		strcat(path,digit);
		strcat(path,".jpg");
		fprintf(fp,"%s\n",path);
		fprintf(fp_verify,"%d\n",num);
	}
	fclose(fp);
	fclose(fp_verify);
}