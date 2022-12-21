#include<stdio.h>
#include<stdio.h>
#include<string.h> 
#include<limits.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100
int top=-1, arr[MAX];

//function to push element
void push(char x)     
{
    arr[++top]=x;
}

//function to remove element from stack
char pop()            
{ 
	if(top==-1)
    	return -1;
    else
    	return arr[top--];
}

//function to check precedence of the element in stack
int prcd(char c)      
{   
	if(c==')')
    	return 0;
    else if(c=='+'||c=='-')
    	return 1;
    else if(c=='*'||c=='/')
    	return 2;
}


//main function to change the expression
void infixtoprefix(char expression[MAX],char prefix[MAX])
{
    char temp,x;
    int i=0,j=0;
    strrev(expression);
    while(expression[i]!='\0')
    {
        temp=expression[i];
       if(isalnum(temp))
        {
            prefix[j++]=temp;
        }
        else if(temp==')')
         push(temp);
        else if(temp=='(')
            {
         while((x=pop())!=')')
         {
          prefix[j++]=x;
           }
          }
        else
        {  while(prcd(arr[top])>=prcd(temp))
            {prefix[j++]=pop();}
                push(temp);
        }
        i++;
    }
    while(top!= -1)            // Once all inital expression characters are traversed
                               // adding all left elements from stack to exp
    prefix[j++]=pop();
    prefix[j]='\0';
    strrev(prefix);
}
int main()
{
    char expression[MAX],prefix[MAX];
    printf("Enter the expression expression\n");
    gets(expression);
    printf("The expression expression is %s\n",expression);
    infixtoprefix(expression, prefix);
    printf("The prefix expression is %s\n",prefix);
	return 0;
}
