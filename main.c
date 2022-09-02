#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define SIZE 10

typedef struct
{
    int items[SIZE];
    int top;
}Stack;

Stack* initialize()
{
    Stack*s=malloc(sizeof(Stack));
    s->top=0;
    return s;
}

void push(Stack*s,int x)
{
    s->items[s->top]=x;
    s->top++;
    //s->items[s->top++] = x;
}

int pop(Stack*s)
{
 s->top--;
 return s->items[s->top];
//return s->items[--s->top];
}

int isEmpty(Stack*s)
{
    if(s->top==0)
        return 1;
        return 0;
    //return s->top==0;
}

int isFull(Stack*s)
{
    if(s->top==SIZE)
        return 1;
    else
        return 0;
//return s->top == SIZE;
}

int peek(Stack*s)
{
    return s->items[s->top-1];
}

void display(Stack*s)
{
    Stack*temp=initialize();
    while(!isEmpty(s))
    {
        int x=pop(s);
      printf("%d ",x);
      push(temp,x);
    }
    while(!isEmpty(temp))
    {
        push(s,pop(temp));
    }

}
int calculate (int x, int y, char op)
{
    if (op == '+')
        return (x+y);
    else if(op == '-')
        return (x-y);
    else if (op == '*')
        return (x*y);
    else if (op == '/')
        return (x/y);
    else if (op == '%')
        return (x%y);
}



int evalpost (char str[])
{
    Stack *s = initialize();
    int i;
    for(i=0; i<strlen(str); i++)
    {
        if(isdigit(str[i]))
            push (s, str[i]-'0');
        else{
            int x = pop(s);
            int y = pop(s);
            int result = calculate (y, x, str[i]);
            push (s, result);
        }
    }
    return (pop (s));
}
int priority (char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else
        return 0;
}
char * infixtopostfix (char* in)
{char*s=malloc(strlen(in)+1);
   // char str1[100];
    char newString[10][10];
    int i,j,ctr;
       printf("\n\n Split string by space into words :\n");
       printf("---------------------------------------\n");

    //printf(" Input  a string : ");
    //fgets(in, sizeof str1, stdin);

    j=0; ctr=0;
    for(i=0;i<=(strlen(in));i++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(in[i]==' '||in[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=in[i];
            j++;
        }
    }
    printf("\n Strings or words after split by space are :\n");
    for(i=0;i < ctr;i++)
       {
           printf(" %s\n",newString[i]);
           strcpy(s,newString);
           if(i>0)
           strcat(s,s);
       }
       return s;
}

int main()
{
   char s[]="( 4 + 3 - ( 4 - 3 / 2 - 1 ) - 2 )";
   char *st=infixtopostfix(s);
   printf(" theee%s",st);

  // printf("result = %d", evalpost(s));

    return 0;
}
