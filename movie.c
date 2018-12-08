#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

//structure definition
typedef struct movInfo {
	char name[100];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;

void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	//allocate memory and set the member variables
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	if (mvPtr != NULL)
	{
		strcpy(mvPtr->name,name);//���ڿ�  ����  
		mvPtr->score=score; //score�� ����ü�� score�� ����   
		mvPtr->runTime=runTime;//runTime�� ����ü�� runTime�� ����  
		strcpy(mvPtr->madeIn,country);//���ڿ� ����  
	}
	
	return (void*)mvPtr;	
}//name,score,runTime,country�� ����ü�� ��������� �Ҵ����ذͿ� �����Ѵ�  

void printMv(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if (mvPtr == NULL) //���� 
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}

int mv_printAll(void* obj, void* arg)
{
	printf("----------------------------------------\n");
	printMv(obj);
	return;
}

int mv_printScore(void* obj, void* arg)
{
movInfo_t* mvPtr = (movInfo_t*)obj;
	if ( mvPtr->score >= *(float*)arg ) 
	{
		printMv(obj);
		return 1;
	}

	return 1;
}

int mv_printRunTime(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if ( (mvPtr->runTime) >=  *(float*)arg) 
	{
		printMv(obj);
		return 1;
	}
	return 0;
}

int mv_printCountry(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;//�Ű��������� obj�� ����ü���� mvPtr�� ���  
	if(strcmp(arg,mvPtr->madeIn)==0)//���ڿ� arg��  mvPtr->madeIn�� ���Ͽ� ������ printMv�� �� ��带 ����Ѵ�. 
	{
		printMv(obj);
		return 1;
	}else 
	return 0;
}


