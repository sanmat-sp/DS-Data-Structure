#include <stdio.h>
#include <stdlib.h>
 
void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();

 
int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;
 
int main()
{
    int ch;
    
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeu element from queue");
    printf("\n4 - Exit\n");
    
    while (1)
    {
        display();
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 4:
            exit(0);
        }
    }
}
 
void push1(int data)
{
    st1[++top1] = data;
}

int pop1()
{
    return(st1[top1--]);
}
 
void push2(int data)
{
    st2[++top2] = data;
}

int pop2()
{
    return(st2[top2--]);
}

void enqueue()
{
    int data, i;
 
    printf("Enter data into queue : ");
    scanf("%d", &data);
    push1(data);
    count++;
}

void dequeue()
{
    int i;
 
    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2());
    }
}

void display()
{
    int i;
    if(top1<0)
       {
                printf("Queue is empty\n");
       }
    else
    {
       for (i = 0;i <= top1;i++)
       { 
                 printf(" %d ", st1[i]);
       }
    }
}  
