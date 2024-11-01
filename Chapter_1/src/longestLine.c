#include <stdio.h>

//Max input line size
#define MAXLINE 1000

int getLine(char line[],int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;                //current line length
    int max;                //int max length seen 
    char line[MAXLINE];     //current input line
    char longest[MAXLINE];  //longest line saved

    max = 0; 
    while((len = getLine(line, MAXLINE)) > 0)
    {
        if(len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0)
    {
        printf("%s",longest);
    }
    return 0;
}

//read a line into s, return length
int getLine(char s[],int lim)
{
    int c,i;

    for(i = 0; i<lim-1 && (c=getchar()) != EOF && c!='\n';++i)
    {
        s[i] = c;
    }
    if(c =='\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    printf("length %d",i);
    return i;
}

//copy from into to
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') 
    {
        ++i;
    }
}