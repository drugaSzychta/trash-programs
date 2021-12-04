#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 5

int main()
{
    int arr[N];
    char user_arr[N+1];
    bool flag =true;
    
    srand(time(NULL));
    
    for(int i=0;i<N;i++){
    arr[i]= i;
    }
    
    printf("Type numbers:\n");
    scanf("%5[^n]",user_arr);
    
    for(int i=0;i<N;i++){
        int user_element = (int)user_arr[i]-48;
        //printf("User number after conversion: %d ",user_element);
        if(user_element!=arr[i]) flag=false;
    }
    if(flag) printf("Bezbłędnie!\n");
    else printf("Popełniono błąd\n");
    
    return 0;
}
