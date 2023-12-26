#include<stdio.h>
#include<stdlib.h>

struct node
{
    int lic_plate;
    struct node *next;
};
struct node *first = NULL;
int store[100];
 int i = 0;

void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("The parking lot is full\n");
        
    }
    else
    {
        printf("\nCar has entered the garage successfully");
        temp->lic_plate = x;
        temp->next = first;
        first = temp;
    }
}

void pop(int x)
{
    struct node *temp;
    struct node *ptr;
    int a[10];
   
    
    if(first == NULL)
        printf("Stack is empty\n");
    else
    {
        temp = first;
        ptr = NULL;
        while(temp->lic_plate!=x)
        {
            ptr=temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        int ele=temp->lic_plate;
        free(temp);

        struct node *t;
        t = first;
        ptr = ptr->next;
        
        while(t->lic_plate!=ptr->lic_plate)
        {
            
           
            printf("Car that was removed from the parking lot had the license plate: %d\n",t->lic_plate);
            store[i]=t->lic_plate;
            t=t->next;
            i++;
            
            
        }
        int j;
        int count=0;
        for(j=0;j<i;j++)
        {
            
            if(ele==store[j])

            {
                count++;
            }
            
        }
        
        printf("\ncar with license plate %d",x);
        printf(" moved %d times",count);
     
        printf("\n");
        
       
    }
}

void display()
{
    struct node *p;
    p = first;
    while(p)
    {
        printf("%d\n",p->lic_plate);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int x,n;
    do
    {
        printf("\n1.Arrival of car\n");
        printf("\n2.Departure of car\n");
        printf("\n3.Display parking lot\n");
        printf("\n4.EXIT \n");
        printf("\nEnter the option: ");
        scanf("%d",&x);
        printf("\n");
        switch(x)
        {
            case 1: printf("Enter the license plate of the car that has entered the parking lot: ");
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2: printf("Enter the license plate of the license plate of the car that has left the parking lot: ");
                    scanf("%d",&n);
                    pop(n);
                    break;
            case 3: display();
                    break;
            case 4:exit(0);
            default: printf("Kindly enter a valid choice\n");
        }
    } while(x!=9);
    
}