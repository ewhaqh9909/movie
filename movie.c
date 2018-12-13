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

void* mv_genMvInfo(char* name, float score, int runTime, char* country) //����ü�� ũ�⸦ �������ְ� �� �ڷ���� ������ �������ش�   
{
	movInfo_t* mvPtr;//movInfo�� ����ü�� mvPtr�̶� ������  
	//allocate memory and set the member variables
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));//����ü ������ ũ�⸦ �����Ҵ����� �������ش�   
	if (mvPtr != NULL)//����ü�� NULL�� �ƴҶ�  
	{
		strcpy(mvPtr->name,name);//���ڿ�  ����  
		mvPtr->score=score; //score�� ����ü�� score�� ����   
		mvPtr->runTime=runTime;//runTime�� ����ü�� runTime�� ����  
		strcpy(mvPtr->madeIn,country);//���ڿ� ����  
	}
	
	return (void*)mvPtr;	
}//name,score,runTime,country�� ����ü�� ��������� �Ҵ����ذͿ� �����Ѵ�  

void printMv(void* obj)//�ش� ����� ��ȭ������ ������ִ� �Լ�  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;//���� obj�� ����ü�� ���� mvPtr�� �����Ͽ� ����ü ���� mvPtr�� ���   
	if (mvPtr == NULL) //����ü �� NULL�̸�  
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}

int mv_printAll(void* obj, void* arg)//��ȭ������ ��ü ����ϱ� ���� �Լ� obj��  arg�� repFunc�� �Ű������� ������ ���� ���� �̱⵵ �ϴ�   
{
	printf("----------------------------------------\n");
	printMv(obj);//obj�� printMv�� ���� �Ű������� �ش� ����� ��ȭ�� ����Ѵ�  
	return 1;//���ǿ� ������� 1��ȯ�Ͽ� list_repeaFunc���� ��带 ������ �������� �����ְ� �ȴ�  
}

int mv_printScore(void* obj, void* arg)//���ǿ� �´� score�� ��ȭ�� ����ϰ� �ϴ� �Լ���  arg�� repFunc�� �Ű������� ������ ���� ���� �̱⵵ �ϴ�   
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if ((mvPtr->score) >= *(float*)arg ) //arg�� void���̹Ƿ� �ڷ����� �����ϱ� ���ؼ� *(float*)arg������ Ÿ���� ��ȯ���ش� �׸��� ������ �Ҵ�Ǿ��� ����ü�� score�� ���Ѵ�  
	{
		printMv(obj);//obj�� printMv�� ���� �Ű������� �ش� ����� ��ȭ�� ����Ѵ�  
		return 1;//���ǿ� ������� 1��ȯ�Ͽ� list_repeaFunc���� ��带 ������ �������� �����ְ� �ȴ�
	}else
	return 0;//���ǿ� ������� 0��ȯ�Ͽ� list_repeaFunc���� ��带 ������ �������� �����ְ� �ȴ�
}

int mv_printRunTime(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if ( (mvPtr->runTime) >= *(int*)arg)  //arg�� void���̹Ƿ� �ڷ����� �����ϱ� ���ؼ� *(int*)arg������ Ÿ���� ��ȯ���ش� �׸��� ������ �Ҵ�Ǿ��� ����ü�� runTime�� ���Ѵ� 
	{
		printMv(obj);//obj�� printMv�� ���� �Ű������� �ش� ����� ��ȭ�� ����Ѵ�  
		return 1;//���ǿ� ������� 1��ȯ�Ͽ� list_repeaFunc���� ��带 ������ �������� �����ְ� �ȴ�
	}else
	return 0;//���ǿ� ������� 0��ȯ�Ͽ� list_repeaFunc���� ��带 ������ �������� �����ְ� �ȴ�
}

int mv_printCountry(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;//�Ű��������� obj�� ����ü���� mvPtr�� ���  
	if(strcmp(arg,mvPtr->madeIn)==0)//���ڿ� arg��  mvPtr->madeIn�� ���Ͽ� ������ printMv�� �� ��带 ����Ѵ�. 
	{
		printMv(obj);//obj�� printMv�� ���� �Ű������� �ش� ����� ��ȭ�� ����Ѵ�  
		return 1;//���ǿ� ������� 1��ȯ�Ͽ� list_repeaFunc���� ��带 ������ �������� �����ְ� �ȴ�
	}else
	return 0;//���ǿ� ������� 0��ȯ�Ͽ� list_repeaFunc���� ��带 ������ �������� �����ְ� �ȴ�
}


