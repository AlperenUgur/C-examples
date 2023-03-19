#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


int main()
{
    //int counter=0;
    char sentence[] = {"the lazy boy went to the market boy in a car"};
    char word[] = {"boy"};
    for (int i = 0;i<strlen(sentence)-strlen(word);i++)
    {
        //printf("i:%d",i);
        if(word[0]==sentence[i])
        {
            bool flg=true;
            for(int j=0;j<strlen(word);j++)
            {
                if(word[j]!=sentence[i+j])
                {
                    flg=false;
                    break;
                }
            }
            if(flg)
            {   
                for(int j=0;j<strlen(word);j++)
                {
                    sentence[i+j]=toupper(word[j]);
                }
            }
        }
    }
         printf("sentence :%s\n",sentence);
    return 0;
}
   
