#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define DEBUG 1
#define N 10
/******************************************************************
 * This program is my try for the below codewars problem:
 * https://www.codewars.com/kata/550f22f4d758534c1100025a
 * print_step() is only uses for degugging process, like any printf() callings
 * *******************************************************************/
char *arr_rand[N];
char *dir[4] = {"NORTH","EAST","SOUTH","WEST"};
bool comp_flag = true;


void resize_arr(int i);
void print_step();

int main()
{
    //Create a list of steps
    srand(time(NULL));
    int choice;
    for(int i = 0 ; i < N ; i++){
        choice = rand() % 4;
        switch (choice){
            case 0:
                arr_rand[i] = dir[0];
                break;
            case 1:
                arr_rand[i] = dir[1];
                break;                
            case 2:
                arr_rand[i] = dir[2];
                break;
            case 3:
                arr_rand[i] = dir[3];
                break;                
        }
    }
    
    //Print result to console
    for(int i = 0 ; i < N ; i++){
            printf("%s, ",*(arr_rand + i) );
    }
    printf("\n");
    //comparison
	do{
		
		comp_flag = false;
		
		for(int i = 0 ; i + 1 < N ; i++){
			if(strcmp(arr_rand[i],dir[0]) == 0 && strcmp(arr_rand[i+1],dir[2]) == 0){
				resize_arr(i);
				#if DEBUG
				printf("Mamy NORTH, nastepny SOUTH. Iteracja: %d\n",i);
				print_step();
				#endif
				comp_flag = true, i = 0;
			}
			else if(strcmp(arr_rand[i],dir[1]) == 0 && strcmp(arr_rand[i+1],dir[3]) == 0){;
				resize_arr(i);
				#if DEBUG
				printf("Mamy EAST, następny WEST. Iteracja: %d\n",i);
				print_step();
				#endif
				comp_flag = true, i = 0;
			}
			else if( strcmp(arr_rand[i],dir[2]) == 0 && strcmp(arr_rand[i+1],dir[0]) == 0){
				resize_arr(i);
				#if DEBUG
				printf("Mamy SOUTH, następny NORTH. Iteracja: %d\n",i);
				print_step();
				#endif
				comp_flag = true, i = 0;
			}
			else if( strcmp(arr_rand[i],dir[3]) == 0 && strcmp(arr_rand[i+1],dir[1]) == 0){
				resize_arr(i);
				#if DEBUG
				printf("Mamy WEST, następny EAST. Iteracja: %d\n",i);
				print_step();
				#endif
				comp_flag = true, i = 0;
			}
				
		}
	}while(comp_flag);
	
	printf("Result:\n");
	print_step();
    
    return 0;
}

void resize_arr(int i){
	/******************************
	* resize_arr move every string by two indexes. i is current location, j is a "move location"
	* difference between i and j is two because we two strings must be disappeared from the array
	*********************************/
    int j;
    if(i+2>=N)
        printf("Leak memory");// To resolve
    for(j = i +2 ; j < N ; j++)
            arr_rand[j - 2] = arr_rand[j];
    arr_rand[j-1]=" ";
    arr_rand[j-2]=" ";    
}
void print_step(){
	for(int i = 0 ; i < N ; i++)
		if(strcmp(*(arr_rand + i)," ") != 0)
        printf("%s, ",*(arr_rand + i) );
    printf("\n");
    #if DEBUG
        int counter=0;
        for(int i = 0 ; i < N ; i++){
            if(strcmp( *(arr_rand + i)," " ) != 0)
                counter++;
        }
        printf("Orginal size: %d Current size of array: %d\n",N,counter);
    #endif
}
