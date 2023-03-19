#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char sentence[]={"1355 - 999999999"};
    char delim[]={" "};
    char *token;
    token = strtok(sentence,delim);
    int i=1;
    while(token != NULL)
    {
        printf("%d. %s\n",i++,token);
        token = strtok(NULL , delim);
    }
    return 0;
}