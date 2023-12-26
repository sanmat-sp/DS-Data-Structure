#include<stdio.h>
#include<stdlib.h>  
typedef struct node
{
    int data;
    struct node* link;
    
}NODE;

typedef struct queue
{
    NODE* front;
    NODE* rear;
}Queue;


void init(Queue* pq)
{
    pq->front = NULL;   
    pq->rear = NULL;    
}


void enqueue(Queue *pq,int, int, int);
int dequeue_skip(Queue *pq, int);

int main()
{
    Queue pq;
    init(&pq);
    int n,skip,i;
    printf("enter the no. of person\n");
    scanf("%d", &n);
    printf("enter the number of skips\n");
    scanf("%d", &skip);
    
    for(i = 1;i<=n;i++)
        enqueue(&pq,i,n,skip);
    int winner = dequeue_skip(&pq, skip);
    printf("Survivor is %d\n",winner );
    
return 0;
}


void enqueue(Queue *pq, int value, int n, int skip)
{
    
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = value;
    temp->link = NULL;

    if (pq->front == NULL && pq->rear == NULL)  
    {
        pq->front = temp;       
        pq->rear = temp;
        pq->rear->link = pq->front; 
    }

    else            
    {
        pq->rear->link = temp;  
        pq->rear = temp;        
        temp->link = pq->front; 
    }   
    
}

int dequeue_skip(Queue *pq, int skip)
{
   
    int i;
    NODE *p, *befp;
    p = pq->front;
    befp = NULL;
    while(p->link!=p)   
    {
        for(i = 0;i<skip-1;i++)
        {
            befp = p;
            p = p->link;
        }
        befp->link = p->link;
         
      
             p = befp->link;
    }
    pq->front = p;
    return (p->data);
}
