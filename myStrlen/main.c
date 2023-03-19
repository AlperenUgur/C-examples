#include <stdio.h>
int strlenChucky(const char *s);
int myStrlen(const char *s);

int main()
{
    char str[]="you don't know who i am.";
    printf("sentence:%s\n",str);
    printf("this sentence has = %d \n",myStrlen(str));
    printf("this sentence has = %d \n",strlenChucky(str));
    return 0;
}

int strlenChucky(const char *s){
    int i=0;
    while(s[i]) i++;
    return i;
}

int myStrlen(const char *s)
{
    int count = 0;
    while(*s!='\0')
    {
        count++;
        s++;
    }
    return count;
}