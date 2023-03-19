#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int counter=0;
    char array[]={3,4,5,11,14,17,19,21};
    for(int i=0;i<strlen(array);i++)
    {
        int j=2;
        int flag=0;
            for(j=2;j<array[i];j++){
                if(array[i]%j==0){
                    flag++;
                    break;
                }
                
                printf("j:%d\n",j);
            }
            if(flag==0){
                counter=counter+array[i];
            }
    }

 printf("counter:%d\n",counter);
return 0;
}