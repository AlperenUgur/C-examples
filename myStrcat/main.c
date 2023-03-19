#include <stdio.h>
#include <string.h>

char* myStrcat(char *dest, const char *src);


int main(){
    char source[50]={"alperen recep uğur "};
    char dest[50]={"pamukkale üniversitesi"};
    printf("destination sentence:%s\n",myStrcat(dest,source));
    return 0;
}
char* myStrcat(char *dest, const char *src){
    int i,j;
    for(i=0;dest[i]!='\0';i++);
    for(j=0;src[j]!='\0';j++)
    {
        dest[i+j]=src[j];
    }
    dest[i+j]='\0';
return dest;
}