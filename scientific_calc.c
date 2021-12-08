#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void calc_value_interf(int n);
double calc_pol_value(double arr[],int n);
void calc_roots_interf();

int main()
{
    for(;;){
        int n;
        char c;
        printf("Select a calculation:\n0. Exit\n1. Calculate a value of a polynomal function\n2. Find a solution\n");
        c=getchar();
        while(getchar()!='\n');
        switch (c){
            case '0':
                printf("End of program\n");
                exit(1);
                break;
            case '1':
                printf("Which power of ponynomal function do you want to caltulate:\n");
                scanf("%d",&n);
                calc_value_interf(n);
                break;
            case '2':
                calc_roots_interf();
                break;
            default:
                printf("Wrong number\n");
                break;
        }
    }

    return 0;
}

void calc_value_interf(int n){
    double coeff_arr[n]; // this is a local array, be aware of that
    double result;
    for(int i=0;i<n;i++){
        printf("Type %d coefficient of x^n+x^(n-1)+x^(n-2)...\n",i);
        scanf("%lf",&coeff_arr[i]);
    }
    /*for(int i=0;i<n;i++){
        printf("%d element of array: %lf",i,coeff_arr[i]);
    }*/ //debugging
    result=calc_pol_value(coeff_arr, n);
    printf("Result: %lf\n",result);
}

void calc_roots_interf(){
    printf("Calc roots\n");
}

double calc_pol_value(double arr[],int n){
    
    return 2;
}

