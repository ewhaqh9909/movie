#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linked_List.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function
	void *arg; //a void pointer for passing argument to repFunc
	int cnt; //integer variable

	printf("Reading the data files...\n\n");//1. reading the movie.dat-----------------------------
	
	fp=fopen("movie.dat","r");//1.1 FILE open movie.dat을 읽는 형식으로 열기  
	if(fp==NULL)//파일일 NULL일떄 에러 처리하기  
	{
		printf("\n열수 없습니다.\n");
		exit(1);
	}
    
	//1.2 list generation (use function list_genList() )
	list = list_genList();//mvInfo의 정보를 연결해주기 위한 초기의 list란 메모리 할당 장소를 열기  

	//1.3 read each movie data from the file and add it to the linked list
	
	while (!feof(fp)/* read name, country, runtime and score*/ )
	{
		fscanf(fp,"%s %s %d %f",name,country,&runTime,&score);//문자열로 읽어준다. 
		mvInfo=mv_genMvInfo(name, score, runTime, country);//mv_genMvInfo를 MvInfo으로 저장... 
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		list_addTail(mvInfo, list);//list에 mvInfo를 연결해준다. 
        printf("%s %s %d %f\n",name,country,runTime,score);
        
	}

	fclose(fp);//1.4 FILE close
	printf("    -totally %d movies are listed!\n",list_len(list));//파일속 영화정보 개수...list_len은 linked_list에 있는 함수로 list안의 노드를 세준다. 
	//2. program start
	
	while(exit_flag == 0)
	{
		printf("\n\n--------------------Menu--------------------\n");
		printf("1. print all the movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific score movies\n");
		printf("5. exit");
		printf("\n--------------------Menu--------------------\n\n");
		printf("-- select an option :");
		scanf("%d", &option);
		//2.1 print menu message and get input option
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n");
				printf("----------------------------------------\n");
				repFunc = mv_printAll;//mv_printALL함수를 repFunc처럼 각 노드마다 반복하기 위해 repFunc로 저장... 
				arg = NULL;//repFunc의 인수로 쓰이는 arg를 NULL로 두어 별 다른 조건없이 영화전부를 전부 출력하기위한 설정이다  
				list_repeatFunc(repFunc,arg,list);//노드의 끝까지인 영화정보전체를 다 돌때까지 반복한다  
				break;
				
			case 2: //print movies of specific country
				printf("select a country :");
	            scanf("%s", country);//영화 국가를 입력한다  
	            arg = &country;//arg를 country로 두어서 repFunc인 mv_printcountry함수에서 활용하게 된다  
				repFunc = mv_printCountry;//repFunc인 mv_printcountry함수
				break;
				
			case 3: //print movies with long runtime
				repFunc = mv_printRunTime;
				printf("lowest runtime :");
				scanf("%d", &runTime);
				arg = runTime;
				break;
				
			case 4: //print movies with high score
				repFunc = mv_printScore;
				printf("lowest score :");
				scanf("%f",&score);
				arg = &score;
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		printf("   - totally %d movies are listed!\n",list_repeatFunc(repFunc,arg,list));
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		//2.3 print number of movies
	}
	
	return 0;
}
