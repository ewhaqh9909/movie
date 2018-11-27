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
	void* arg; //a void pointer for passing argument to repFunc
	int cnt; //integer variable
	
	
	printf("Reading the data files...");//1. reading the movie.dat-----------------------------
	fp=fopen("movie.txt","r");//1.1 FILE open
	if(fp==NULL)
	{
		printf("\nv열수 없습니다.\n");
		exit(1);
	}
    
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while ( fgetc(fp)!=EOF/* read name, country, runtime and score*/ )
	{	
		cnt++;
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		list_addTail(mvInfo, list);
	}

	fclose(fp);//1.4 FILE close
	printf("    -totally %d movies are listed!\n",cnt);
	//2. program start
	while(exit_flag == 0)
	{
		printf("\n\n--------------------Menu--------------------\n");
		printf("1. print all the movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific score movies\n");
		printf("5. exit");
		printf("--------------------Menu--------------------\n\n");
		printf("-- select an option :");
		scanf("%d",option);
		//2.1 print menu message and get input option
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				
				repFunc = mv_printAll;
				arg = NULL;
				break;
				
			case 2: //print movies of specific country
				printf("select a country :");
				scanf("%c",country);
				repFunc = mv_printCountry;
				arg = NULL;
				break;
				
			case 3: //print movies with long runtime
				printf("lowest runtime :");
				scanf("%d",runTime);
				repFunc = mv_printRunTime;
				arg = NULL;
				break;
				
			case 4: //print movies with high score
				printf("lowest score :");
				scanf("%d",score);
				repFunc = mv_printScore;
				arg = NULL;
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		//2.3 print number of movies
	}
	
	return 0;
}
