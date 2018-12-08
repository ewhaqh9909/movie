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
		strcpy(mvPtr->name,name);//문자열  복사  
		mvPtr->score=score; //score를 구조체형 score로 저장   
		mvPtr->runTime=runTime;//runTime를 구조체형 runTime로 저장  
		strcpy(mvPtr->madeIn,country);//문자열 복사  
	}
	
	return (void*)mvPtr;	
}//name,score,runTime,country를 구조체에 저장공간을 할당해준것에 저장한다  

void printMv(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if (mvPtr == NULL) //구조 
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
	movInfo_t* mvPtr = (movInfo_t*)obj;//매개변수였던 obj를 구조체형의 mvPtr로 사용  
	if(strcmp(arg,mvPtr->madeIn)==0)//문자열 arg와  mvPtr->madeIn를 비교하여 같을때 printMv로 그 노드를 출력한다. 
	{
		printMv(obj);
		return 1;
	}else 
	return 0;
}


