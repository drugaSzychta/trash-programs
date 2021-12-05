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

#define N 10

int* gen_num_arr;
char user_arr[N];
bool flag = true;
int user_type_len;

void generate_num();
void print_gen_numbers(int *arr);
void user_input();
void check();
void print_result();

int main()
{
    generate_num();
    print_gen_numbers(gen_num_arr);
    /*user_input();
    check();
    print_result();*/
    
    return 0;
}

void generate_num(){
    srand(time(NULL));
    printf("How many numbers do you want to remember?");
    scanf("%d",&user_type_len);
    while(getchar()!='\n');
    gen_num_arr=(int*) malloc(sizeof(int)*user_type_len);
    for(int* p=gen_num_arr;p<gen_num_arr+user_type_len;p++) *p = rand()% 10;
}
void print_gen_numbers(int *arr){
    char x;
    for(int *p=arr;p<arr+N;p++) printf("%d",*p);
    printf("\n");
    printf("Are you ready? Press y to start: \n");
    scanf("%c",&x);
    if(getchar()!='\n');
    if(x!='y') exit(1);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void user_input(){
    printf("Type numbers:\n");
    scanf("%4[^n]",user_arr);
}
void check(){
    for(int i=0;i<N;i++){
        int user_element = (int)user_arr[i]-48;
        if(user_element!=gen_num_arr[i]) flag=false;
    }
}
void print_result(){
    flag==true ? printf("You are a winner") : printf("Sorry...");
}

