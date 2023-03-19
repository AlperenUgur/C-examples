#include <stdio.h>
#include <string.h>
int charCounter(char *str,char c);

int main(){
    char str[100];
    char c;
    printf("enter a string:\n");
    gets(str);
   
    printf("enter a letter:\n");
    scanf("%c",&c);
    int count = charCounter(str,c);
    printf("count:%d",count);


    return 0;
}

int charCounter(char *str,char c)
{
   if(*str=='\0')
   {
    return 0;
   }
   if(c==*str)
   {
    return 1+ charCounter(str+1,c);
   }
   else 
    return charCounter(str+1,c);

}

