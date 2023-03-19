#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char numbers[]={"10 20 30 40"};
    char delim[]={" "};
    char *token;
    token = strtok(numbers,delim);
    int a = atoi(token);
    while(token!=NULL){
        printf("%d\n",a-1);
        token = strtok(NULL,delim);
        if(token!=NULL)
        {
            a = atoi(token);
        }
        
    }
return 0;
}