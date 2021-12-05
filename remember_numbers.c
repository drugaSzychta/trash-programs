/******************************************************************************

The aim of a program is to exercise memorizing digits. The user is asked to type how many
digits he/she wants to memorize(user_type_len), then computer generate a array.
Result is stored in (gen_num_arr). The next step is to print random numbers to the screen.
Then, the string from an input is stored in user_ch_arr. check_answer() function converts char to int and compares
two arrays. Information about check is stored in the bool flag.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

//variables initialized in generate_num()
int user_type_len;
int* gen_num_arr;
//array initialized in user_input()
char* user_ch_arr;
size_t buff_size=100;
//variables used in check_answer() and print_result()
bool flag = true;
//timer
time_t start, diff;

void generate_num();
void print_gen_numbers(int *arr);
void user_input();
void check_input();
void check_answer();
void print_result();

int main(){
    generate_num();
    print_gen_numbers(gen_num_arr);
    user_input();
    check_input();
    check_answer();
    print_result();
    
    return 0;
}

void generate_num(){
    srand(time(NULL));
    printf("How many numbers do you want to remember?Must be less than 100: ");
    scanf("%d",&user_type_len);
    while(getchar()!='\n'); // without this line, the next scanf() call will take a '\n' char from a buffer, making a bug
    gen_num_arr=(int*) malloc(sizeof(int)*user_type_len);
    for(int* p=gen_num_arr;p<gen_num_arr+user_type_len;p++) *p = rand()% 10;
}
void print_gen_numbers(int *arr){
    char x;
    bool begin_flag=true;
    int counter=0;
    for(int *p=arr;p<arr+user_type_len;p++,counter++){
        counter%4==0 && begin_flag==false ? printf("-%d",*p) : printf("%d",*p);
        begin_flag=false;
    }
    printf("\nTime start!\n");
    start = time(NULL);
    
    printf("Are you ready? Press y to start: \n");
    scanf("%c",&x);
    if(getchar()!='\n');
    if(x!='y') exit(1);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
    //printf("Number of characters: %zu\n",characters);
    diff = time(NULL) - start;
    for(int i=0;i<user_type_len;i++) printf("%c ",user_ch_arr[i]);
}
void check_input(){
    bool flag_not_digit=false, flag_exit=false;
    for(int i=0;i<user_type_len;i++){
        if(user_ch_arr[i]<'0' || user_ch_arr[i]>'9') flag_not_digit=true;
    }
    if(flag_not_digit){ 
        printf("There is a non-digit character in an answer..\n");
        exit(1);
    }
    if(strlen(user_ch_arr)>user_type_len+1){
     printf("Too many digits!\n");
     flag_exit=true;
    }
    else if(strlen(user_ch_arr)<user_type_len+1){ 
    printf("A lack od digit/digits..\n");
    flag_exit=true;
    }
    if(flag_exit) exit(1);
}
void check_answer(){
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
    flag==true ? printf("Win! Your time is %d s. Congratulation!",(int)diff) : printf("Sorry...");
}


