#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int a[10];
    int top;
};

void push(struct stack *s,int e)
{
    (s->top)++;
    s->a[s->top] = e;
}

int pop(struct stack *s)
{
    int temp = s->a[s->top];
    (s->top)--;
    return temp;
}

void display(struct stack s)
{
    if((s.top) == -1)
        return;
    for(int i=0 ; i<=(s.top) ; i++)
        printf("%d " , s.a[i]);
    printf("\n\n");
}

int main()
{
    struct stack s;
    s.top = -1;
    int c , e;
    while(1)
    {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Choice : ");
        scanf("%d" , &c);
        printf("\n");
        switch(c)
        {
            case 1: printf("Enter element : ");
                    scanf("%d" , &e);
                    push(&s , e);
                    break;
            case 2: e = pop(&s);
                    printf("%d is popped\n" , e);
                    break;
            case 3: printf("Stack contains:\n");
                    display(s);
                    break;
            case 4: exit(0);
            default : printf("\nWrong choice !!!");
        }
    }
    return 0;
}
