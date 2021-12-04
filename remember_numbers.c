/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 5

int gen_num_arr[N];
char user_arr[N];
bool flag = true;

void generate_num();
void print_gen_numbers(int *arr);
void user_input();
void check();
void print_result();

int main()
{
    generate_num();
    print_gen_numbers(gen_num_arr);
    user_input();
    check();
    print_result();
    
    return 0;
}

void generate_num(){
    srand(time(NULL));
    for(int i=0;i<N;i++) gen_num_arr[i]= rand()% 10;
}
void print_gen_numbers(int *arr){
    for(int *p=arr;p<arr+N;p++) printf("%d",*p);
    printf("\n");
}
void user_input(){
    printf("Type numbers:\n");
    scanf("%5[^n]",user_arr);
}
void check(){
    for(int i=0;i<N;i++){
        int user_element = (int)user_arr[i]-48;
        //printf("User number after conversion: %d ",user_element);
        if(user_element!=gen_num_arr[i]) flag=false;
    }
}
void print_result(){
    flag==true ? printf("Bezbłędnie") : printf("Błąd");
}
