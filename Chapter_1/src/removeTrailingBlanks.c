#include <stdio.h>

#define MAXLINE 1000

//Gets a line from the input up till limit returns the length
int getLine(char s[]);

int main()
{
    int length = 0;
    char currentLine[MAXLINE];

    int curr,prev;
    int left_length;
    while((length = getLine(currentLine)) > 0)
    {
        left_length = length;
        curr = currentLine[left_length-1];
        //prev = '\0';

        while((curr == ' ' || curr == '\t' || curr == '\n') && left_length > 1)
        {
            //prev = curr;
            --left_length;
            curr = currentLine[left_length - 1];
            currentLine[left_length] = '\0';//prev
            //printf("length left: %d",left_length);
        }
        if(curr != ' ')
        {
            currentLine[left_length] = '\n';//prev
            printf("%s with length %d\n",currentLine,left_length);
        }
        
    }
}

int getLine(char s[])
{
    int index,currChar,charCount;
    index = currChar = charCount = 0;

    //while within length, not endoffile and not the end of the line we are a line
    while(charCount < MAXLINE-1 && ((currChar = getchar()) != EOF) && currChar != '\n')
    {
        s[charCount] = currChar;
        ++charCount;

    }
    if(currChar == '\n')
    {
        s[charCount] = '\n';
        ++charCount;
    }
    s[charCount] = '\0';

    return charCount;
}
