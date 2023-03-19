#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char plusStr[]= {"13 + 20"};
    char s[]=" ";


    char *p1 = strtok(plusStr, s);
    printf("%s\n",p1);
    int a = atoi(p1);


    char *p2 = strtok(NULL, s);
    printf("%s\n",p2);

    char *p3 = strtok(NULL, s);
    printf("%s\n",p3);
    int b= atoi(p3);

    if(p2[0]=='+'){
        int result = a + b;
        printf("result:%d\n",result);
    }

    

   
    return 0;
}
        
