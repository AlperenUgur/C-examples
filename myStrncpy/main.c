#include <stdio.h>
#include <string.h>

char* strncpyChucky(char* dest, const char* src, int n);
int myStrncpy(char* sen1,char* sen2,int n);

int main(){
    char sen1[]="alperen recep uğur";
    char sen2[10];
    char dest[]={"mustafa hakan caki"};
    char src[]={"chucky"};
    myStrncpy(sen1,sen2,5);
    printf("strncpyChucky: %s\n", strncpyChucky(dest, src, 3));
    return 0;
}
char* strncpyChucky(char* dest, const char* src, int n)
{
    int i = 0;
    while(src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    while(i < n) {
        dest[i] = 0;
        i++;
    }
    return dest;
}
int myStrncpy(char* sen1,char* sen2,int n){
    for(int i=0;i<strlen(sen1);i++){
        if(i==n)
            {
                break;
            }
        if(sen1[i]!=sen2[i])
        {
            sen2[i]=sen1[i];
               
        }
}
printf("here is your new sentence:%s\n",sen2);
return 0;
}