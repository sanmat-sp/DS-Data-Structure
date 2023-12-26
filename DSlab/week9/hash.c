#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
        char name[20];
        int ph_no;
        struct node *next;
};

struct hash
{
        struct node *head;
        int count;
};

void insert(struct hash *ht, int size, int ph_no, char *name);
void delete(struct hash *ht, int size, int ph_no);
void search(struct hash *ht, int sz, int ph);
void display(struct hash *ht, int size);
void main()
{
        int sz, ch, num, i;
        char name[20];
        struct hash *ht;
        printf("Enter the size of table : ");
        scanf("%d", &sz);
        ht=(struct hash *)malloc(sz*(sizeof(struct hash)));
        for(i=0;i<sz;i++)
        {
                ht[i].head=NULL;
                ht[i].count=0;
        }
        while(1)
        {
                printf("\n1:Insert a PHONE NUMBER\n2:Delete a PHONE NUMBER\n3:Search a PHONE NUMBER\n4:Display\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                switch(ch)
                {
                        case 1: printf("Enter the PHONE NUMBER : ");
                                scanf("%d", &num);
                                printf("\nEnter the name : ");
                                scanf("%s", name);
                                insert(ht, sz, num, name);
                                break;
                        case 2: printf("Enter the PHONE NUMBER to be deleted : ");
                                scanf("%d", &num);
                                delete(ht, sz, num);
                                break;
                        case 3: printf("Enter the PHONE NUMBER to be searched : ");
                                scanf("%d", &num);
                                search(ht, sz, num);
                                break;
                        case 4: display(ht, sz);
                                break;  
                }
        }
}

void insert(struct hash *ht, int size, int ph_no, char *name)
{
        int index;
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->next=NULL;
        temp->ph_no=ph_no;
        strcpy(temp->name, name);
        index=ph_no%size;
        temp->next=ht[index].head;
        ht[index].head=temp;
        ht[index].count++;
}

void delete(struct hash *ht, int size, int ph_no)
{
        struct node *prev, *temp;
        int index;
        index=ph_no%size;
        prev=NULL;
        temp=ht[index].head;
        while(temp->ph_no!=ph_no)
        {
                prev=temp;
                temp=temp->next;
        }
        if(temp==NULL)
                printf("Element not found\n");
        else
        {
                if(prev==NULL)
                {
                        ht[index].head=temp->next;
                }
                else
                {
                        prev->next=temp->next;
                }
        }
}

void display(struct hash *ht, int size)
{
        int i;
        struct node *temp;
        printf("\n");
        for(i=0;i<size;i++)
        {
                printf("%d(%d): ", i, ht[i].count);
                if(ht[i].head!=NULL)
                {
                        temp=ht[i].head;
                        while(temp!=NULL)
                        {       
                                printf("PHONE NUMBER - %d, NAME - %s -> ", temp->ph_no, temp->name);
                                temp=temp->next;
                        }
                }
                printf("\n");
        }
}

void search(struct hash *ht, int sz, int ph)
{
        int index;
        struct node *temp;
        index=ph%sz;
        temp=ht[index].head;
        while((temp!=NULL)&&(temp->ph_no!=ph))
                 temp=temp->next;
        if(temp!=NULL)
        {
                printf("\nFound with\n");
                printf("PHONE NUMBER - %d, NAME - %s\n",temp->ph_no, temp->name);   
        }
        else
                printf("Record not found\n");
}


