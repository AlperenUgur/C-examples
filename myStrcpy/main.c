#include <stdio.h>
#include <string.h>

int strcpyChucky(char* dest, const char* src);
int myStrcpy(char* sen1, char* sen2);

int main(){
    char sen1[]={"alperen"};
    char sen2[]={"alp"};
    char dest[]={"mustafa hakan caki"};
    char src[]={"chucky"};
    myStrcpy(sen1,sen2);
    printf("strcpyChucky: %d\n", strcpyChucky(dest, src));
    printf("res: %s\n", dest);
    return 0;
}

int strcpyChucky(char* dest, const char* src)
{
    int i = 0;
    while(src[i])
    {
        dest[i]=src[i];
        i++;
    }
    dest[i] = 0;
    return i;
}

int myStrcpy(char* sen1,char* sen2)
{
    int i;
    for(i=0;i<strlen(sen1);i++){
        sen2[i]=sen1[i];
    }
    sen2[i] = 0;
    printf("sen2:%s\n",sen2);
    return 0;
}
