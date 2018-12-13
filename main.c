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
	
	while (fscanf(fp,"%s %s %d %f",name,country,&runTime,&score)!=EOF)//문자열로 읽어준다. 그 파일의 끝까지 읽게 된다. /* read name, country, runtime and score*/ )
	{	
		mvInfo=mv_genMvInfo(name, score, runTime, country);//mv_genMvInfo를 MvInfo으로 저장... 
		list_addTail(mvInfo, list);//list에 mvInfo를 연결해준다. 
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
	}

	fclose(fp);//1.4 FILE close
	printf("Read done! %d items are read\n",list_len(list));//파일속 영화정보 개수...list_len은 linked_list에 있는 함수로 list안의 노드를 세준다. 
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
				printf("   - totally %d movies are listed!\n",list_repeatFunc(repFunc,arg,list));
				/*list_repeatFunc()을 이용하여 repFunc는 결국 mv_print~~함수인데
				이 함수를 while문 속에서 각 노드의 끝까지 보내서 조건에 따라 출력하게 되는데 
				이때 각 조건이 맞을때 mv_print~~함수의 반환값들을  더하게 된다 그럼 결국 출력한 영화의 개수를 셀 수 있다.*/ 
				break;
				
			case 2: //print movies of specific country
				printf("select a country :");
	            scanf("%s", country);//영화 국가를 입력한다  
	            arg = &country;//arg를 country로 두어서 repFunc인 mv_printcountry함수에서 활용하게 된다  
				repFunc = mv_printCountry;//repFunc인 mv_printcountry함수
				printf("   - totally %d movies are listed!\n",list_repeatFunc(repFunc,arg,list));
				break;
				
			case 3: //print movies with long runtime
				printf("lowest runtime :");
				scanf("%d", &runTime);//런타임이상을 뽑기위해 원하는 최소 런타임 입력 받음  
				arg = &runTime;//arg를 runTime로 두어서 repFunc인 mv_printrunTime함수에서 활용하게 된다  
				repFunc = mv_printRunTime;//repFunc인  mv_printRunTim함수  
				printf("   - totally %d movies are listed!\n",list_repeatFunc(repFunc,arg,list));
				break;
				
			case 4: //print movies with high score
				printf("lowest score :");
				scanf("%f",&score);//원하는 최소 score입력 받음  
				arg = &score;//arg를 score값으로 두어서 repFunc인  mv_printScore함수에서 활용하게 된다.  
				repFunc = mv_printScore;
				printf("   - totally %d movies are listed!\n",list_repeatFunc(repFunc,arg,list));
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;//5번을 선택했을때 while문을 끝낸다. 
				break;
				
			default://틀린걸 입력했을때 다시 입력받게 된다. 
				printf("wrong command! input again\n"); 
				break;
		}
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		//2.3 print number of movies
	}
	
	return 0;
}
