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
	return (void*)mvPtr;
}

void printMv(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}

int mv_printAll(void* obj, void* arg)
{
	printMv(obj);
}

int mv_printScore(void* obj, void* arg)
{
	float score;
	int i=0;
	printf("lowest score :");
	scanf("%d",score);
	
	movInfo_t* mvPtr;
	
	if(score<= mvPtr->score)
	{
		i++;
		printMv(obj);
	}
	printf("   - totally %d movies are listed!",i);
}

int mv_printRunTime(void* obj, void* arg)
{
	int runTime,i=0;
	printf("lowest runtime :");
	scanf("%d",runTime);
	movInfo_t* mvPtr;
	if(runTime<=mvPtr->runTime)
	{
		i++;
		printMv;
	}
	printf("   - totally %d movies are listed!",i);
}

int mv_printCountry(void* obj, void* arg)
{	
	char country;
	int i=0;
	printf("select a country :");
	scanf("%c",country);
	movInfo_t* mvPtr;
	
	if(country == (*mvPtr->madeIn))
	{
		i++;
		printMv;
		
	}
	printf("   - totally %d movies are listed!",i);
}


