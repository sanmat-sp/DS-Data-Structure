#include<stdio.h>
#include<stdlib.h>
int insert_rear(int *q, int *f, int *r, int size, int x);
int delete_front(int *q, int *f, int *r, int size);
void display(int *q, int f, int r, int size);
int main()
{
        int *q;
        int f, r, size, ch, k, x;
        f=-1;
        r=-1;
        printf("Enter the size of Q\n");
        scanf("%d", &size);
        q=(int *)malloc(size*(sizeof(int)));
        while(1)
        {
                display(q, f, r, size);
                printf("\n1:Insert rear\n");
                printf("2:Delete front\n");
                printf("Enter your choice");
                scanf("%d", &ch);
                switch(ch)
                {
                        case 1:printf("Enter the value of x\n");
                               scanf("%d", &x);
                               insert_rear(q, &f, &r, size, x);
                               break;
                        case 2:delete_front(q, &f, &r, size);
                               break;
                        case 3:exit(0);
                }
        }
}

int insert_rear(int *q, int *f, int *r, int size, int x)
{
    if(*r==size-1)
    {
        printf("Q is full\n");
        return -1;
    }
    (*r)++;
    q[*r]=x;
         if(*f==-1)
            *f=0;
    return 1;
}

int delete_front(int *q, int *f, int *r, int size)
{
        int x;
        if(*f==-1)
        {
                printf("Q is empty\n");
                return -1;
        }
        x=q[*f];
        if(*f==*r)
            *f=*r=-1;
        else
           (*f)++;
        return x;
}

void display(int *q, int f, int r, int size)
{
    int i;
    if(f==-1)
        printf("Q is empty\n");
    else
    {
        for(i=f; i<=r; i++)
        {
                printf("%d - ", q[i]);
        }
    }
}
