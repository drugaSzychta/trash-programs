#include <stdio.h>
#include <time.h>


int main(){
	char c;
	time_t result = time(NULL);
	FILE *fp = fopen("zapiski.txt","a");
	
	printf("Is there a learning day? Type y for yes or n for no\n");
	scanf("%c",&c);
	
	if(fp ==NULL){
		printf("\nSomething went wrong");
		return 1;
	}
	else if(c='y'){
		fprintf(fp,"%d %s", 1 , ctime(&result));
	}
	else{
		fprintf(fp,"%d %s", 0 , ctime(&result));
	}
	fclose(fp);
	return 0;
}
