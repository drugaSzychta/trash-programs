/******************************************************************************

The aim of a program is to exercise memorizing digits. The user is asked to type how many
digits he/she wants to memorize(user_type_len), then computer generate a array.
Result is stored in (gen_num_arr). The next step is to print random numbers to the screen.
Then, the string from an input is stored in user_ch_arr. Check() function converts char to int and compares
two arrays. Information about check is stored in the bool flag.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//variables initialized in generate_num()
int user_type_len;
int* gen_num_arr;
//array initialized in user_input()
char* user_ch_arr;
size_t buff_size=100;
//variables used in check() and print_result()
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
    printf("How many numbers do you want to remember?Must be less than 100: ");
    scanf("%d",&user_type_len);
    while(getchar()!='\n');
    gen_num_arr=(int*) malloc(sizeof(int)*user_type_len);
    for(int* p=gen_num_arr;p<gen_num_arr+user_type_len;p++) *p = rand()% 10;
}
void print_gen_numbers(int *arr){
    char x;
    for(int *p=arr;p<arr+user_type_len;p++) printf("%d",*p);
    printf("\n");
    printf("Are you ready? Press y to start: \n");
    scanf("%c",&x);
    if(getchar()!='\n');
    if(x!='y') exit(1);
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void user_input(){
    /********************************************************
     * We use dynamic allocation because a length of a user input isn't constant.
     * Instead getline()(which is is a standard library from 2010) we could use a fgets
     * size_t is required to getline
     * for loop is my personal debugger stdbool
     * ******************************************************/
    user_ch_arr =(char*) malloc(sizeof(char)*(user_type_len+1));
    printf("Type numbers:\n");
    size_t characters = getline(&user_ch_arr, &buff_size,stdin);
    printf("Number of characters: %zu \n",characters);
    for(int i=0;i<user_type_len;i++) printf("%c ",user_ch_arr[i]);
}
void check(){
    /*******************************
     * Algorithm is very simple. We convert char ASCII numbers to int numbers, that's why
     * every char is substracted by 48.
     * *****************************/
    for(int i=0;i<user_type_len;i++){
        int user_element = (int)user_ch_arr[i]-48;
        if(user_element!=gen_num_arr[i]) flag=false;
    }
}
void print_result(){
    flag==true ? printf("You are a winner") : printf("Sorry...");
}

