#include <stdio.h>
#include <string.h>
#include "Stack.h"


int IsLeftOp(char ch)
{
    if(ch=='(')
    return 1;
    if(ch=='{')
    return 2;
    if(ch=='[')
    return 3;
    else 
    return 0;
}

int IsRightOp(char ch)
{
    if(ch==')')
    return 1;
    if(ch=='}')
    return 2;
    if(ch==']')
    return 3;
    else 
    return 0;
}

int main()
{
    char * s;
    char ch;
    int n;
    Stack LeftOp=InitStack(100000); 
    printf("Enter the string :\n");
    gets(s);
    n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(IsLeftOp(s[i])==1||IsLeftOp(s[i])==2||IsLeftOp(s[i])==3)
        {
            Push(LeftOp,s[i]);
        }
        else if(IsRightOp(s[i])==1||IsRightOp(s[i])==2||IsRightOp(s[i])==3)
        {
            int Rid=IsRightOp(s[i]);
            if(IsEmpty(LeftOp))
            {
                printf("Wrong Syntax\n");
                return 0;
            }
            char ch=Top(LeftOp);
            int Lid=IsLeftOp(ch);
            if(Lid==Rid)
            {
                Pop(LeftOp);

            }
            else
            {
                printf("Wrong Syntax\n");
                return 0;
            }
        }
    }
    if(IsEmpty(LeftOp)==0)
    {
        printf("Wrong Syntax\n");
        return 0;
    }
    else
    printf("Correct Syntax\n");
}