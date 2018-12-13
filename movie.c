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

void* mv_genMvInfo(char* name, float score, int runTime, char* country) //구조체의 크기를 지정해주고 그 자료들을 공간에 저장해준다   
{
	movInfo_t* mvPtr;//movInfo란 구조체의 mvPtr이란 변수명  
	//allocate memory and set the member variables
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));//구조체 변수의 크기를 동적할당으로 지정해준다   
	if (mvPtr != NULL)//구조체속 NULL이 아닐때  
	{
		strcpy(mvPtr->name,name);//문자열  복사  
		mvPtr->score=score; //score를 구조체형 score로 저장   
		mvPtr->runTime=runTime;//runTime를 구조체형 runTime로 저장  
		strcpy(mvPtr->madeIn,country);//문자열 복사  
	}
	
	return (void*)mvPtr;	
}//name,score,runTime,country를 구조체에 저장공간을 할당해준것에 저장한다  

void printMv(void* obj)//해당 노드의 영화정보를 출력해주는 함수  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;//변수 obj를 구조체형 변수 mvPtr로 저장하여 구조체 변수 mvPtr로 사용   
	if (mvPtr == NULL) //구조체 속 NULL이면  
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}

int mv_printAll(void* obj, void* arg)//영화정보를 전체 출력하기 위한 함수 obj는  arg는 repFunc속 매개변수로 조건을 위한 변수 이기도 하다   
{
	printf("----------------------------------------\n");
	printMv(obj);//obj는 printMv를 위한 매개변수로 해당 노드의 영화를 출력한다  
	return 1;//조건에 맞을경우 1반환하여 list_repeaFunc에서 노드를 끝까지 돌때동안 더해주게 된다  
}

int mv_printScore(void* obj, void* arg)//조건에 맞는 score의 영화를 출력하게 하는 함수로  arg는 repFunc속 매개변수로 조건을 위한 변수 이기도 하다   
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if ((mvPtr->score) >= *(float*)arg ) //arg가 void형이므로 자료형을 지정하기 위해서 *(float*)arg형으로 타입을 전환해준다 그리고 위에서 할당되었던 구조체의 score와 비교한다  
	{
		printMv(obj);//obj는 printMv를 위한 매개변수로 해당 노드의 영화를 출력한다  
		return 1;//조건에 맞을경우 1반환하여 list_repeaFunc에서 노드를 끝까지 돌때동안 더해주게 된다
	}else
	return 0;//조건에 맞을경우 0반환하여 list_repeaFunc에서 노드를 끝까지 돌때동안 더해주게 된다
}

int mv_printRunTime(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if ( (mvPtr->runTime) >= *(int*)arg)  //arg가 void형이므로 자료형을 지정하기 위해서 *(int*)arg형으로 타입을 전환해준다 그리고 위에서 할당되었던 구조체의 runTime와 비교한다 
	{
		printMv(obj);//obj는 printMv를 위한 매개변수로 해당 노드의 영화를 출력한다  
		return 1;//조건에 맞을경우 1반환하여 list_repeaFunc에서 노드를 끝까지 돌때동안 더해주게 된다
	}else
	return 0;//조건에 맞을경우 0반환하여 list_repeaFunc에서 노드를 끝까지 돌때동안 더해주게 된다
}

int mv_printCountry(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;//매개변수였던 obj를 구조체형의 mvPtr로 사용  
	if(strcmp(arg,mvPtr->madeIn)==0)//문자열 arg와  mvPtr->madeIn를 비교하여 같을때 printMv로 그 노드를 출력한다. 
	{
		printMv(obj);//obj는 printMv를 위한 매개변수로 해당 노드의 영화를 출력한다  
		return 1;//조건에 맞을경우 1반환하여 list_repeaFunc에서 노드를 끝까지 돌때동안 더해주게 된다
	}else
	return 0;//조건에 맞을경우 0반환하여 list_repeaFunc에서 노드를 끝까지 돌때동안 더해주게 된다
}


