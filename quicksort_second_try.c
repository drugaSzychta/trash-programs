// problem with situation, where start and end points to the same element
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DEBUG 1
#define RANDOM 20

#define N 10

int quick_sort(int *st, int *end);
void print_step();
void fill_arr();

int arr[N];
int main()
{
    int *start = arr, *end = arr+N-1;
    
    fill_arr();   
    printf("Before quicksort:\n");
    print_step();
    quick_sort(start,end);
    
    printf("\nAfter quicksort:\n");
    print_step();

    return 0;
}

void fill_arr(){
    srand(time(NULL));
    for(int *p = arr ; p < arr + N ; p++)
        *p = rand() % RANDOM;
}

int quick_sort(int *st, int *end){
    //pointer required to make smaller arrays in the future
    int* start_arr = st;
    int* end_arr = end;
    bool equal_adresses = false;
    
    //break recursion
        if(st+1 == end)
            return 0;
    int *pivot = end--, temp; // I choose pivot as a last element of current array
    #if DEBUG
    printf("Pivot : %d\n\n", *pivot);
    #endif
    for( ; st <= end ; st++){
        if(*st < *pivot){
            #if DEBUG
            printf("left number *st %d is smaller the pivot %d! \n", *st,*pivot);
            #endif
            continue;
        }
        
        #if DEBUG
        printf("left %d is BIGGER than pivot %d!\n",*st,*pivot);
        #endif
        
        for( ; st <= end ; end--)
        {
            if(*end < *pivot ){
                #if DEBUG
                printf("right %d is SMALLER than pivot %d!\n",*end, *pivot);
                printf("Swap numbers! %d and %d \n",*st,*end);
                #endif
                
                temp= *st;
                *st = *end;
                *end = temp;
                end--;
                break;
            }
            else if(end == st){
                #if DEBUG
                printf("right pointer points the same memory as left! %d!\n",*end);
                printf("Swap numbers! %d and %d \n",*st,*end);
                #endif
                temp = *end;
                *end = *pivot;
                *pivot = temp;
                equal_adresses=true;
                break;
                }
            else{
                #if DEBUG
                printf("right number *end %d is bigger than the pivot %d! \n", *end,*pivot);
                #endif
            }
        }
        #if DEBUG
        print_step();
        #endif
    }
    //Replace a pivot into correct place
    if(equal_adresses != true){
    temp = *st;
    *st = *pivot;
    *pivot = temp;
    }
    //equal_adresses = false; //just in case, bu i think it's ok
    #if DEBUG
    printf("Position of a st pointer: %d (adress %p) and an end pointer: %d (adress: %p)",*st,st,*end,end);
    #endif
    //return quick_sort(start_arr,st) + quick_sort();
    return 1;
}

void print_step(){
    for(int *p = arr ; p < arr + N ; p++)
        printf("%d ",*p);
    printf("\n\n");
}



