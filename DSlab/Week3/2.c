#include<stdio.h>

#include<stdlib.h>

#include<string.h>

 

typedef struct dept

{

    char name[20];

    int no;

}dept;

 

typedef struct node

{

    char ssn[30];

    char name[30];

    long long int ph_no;

    struct dept d;

    char desig[30];

    float salary;

    int age;

    struct node* left;

    struct node* right;

}node;

 

typedef struct employees

{

    node* head;

}employee;

 

void ini(employee*);

node* create_node(char*,char*,long long int,char*,int,char*,float,int);

void ins(employee*,char*,char*,long long int,char*,int,char*,float,int);

void del(employee*);

void disp_e(employee*,char*);

void destroy(employee*);

void disp(employee*);

 

void main()

{

    employee l;

    ini(&l);

    int n;

    printf("Enter number of employees : ");

    scanf("%d",&n);

    char ssn[20],name[30],d_name[20],desig[20];

    int d_no,age;

    float sal;

    long long int ph_no;

    for(int i=0;i<n;i++)

    {

        printf("Enter socisl security number(SSN) : ");

        scanf(" %[^\n]s",ssn);

        printf("Enter Name : ");

        scanf(" %[^\n]s",name);

        printf("Enter phone number : ");

        scanf("%lld",&ph_no);

        printf("Enter department name : ");

        scanf(" %[^\n]s",d_name);

        printf("Enter department number : ");

        scanf("%d",&d_no);

        printf("Enter designation :");

        scanf(" %[^\n]s",desig);

        printf("Enter salary :");

        scanf("%f",&sal);

        printf("Enter age :");

        scanf("%d",&age);

        ins(&l,ssn,name,ph_no,d_name,d_no,desig,sal,age);

        printf("\n");

    }

    del(&l);

    printf("\nAll employee details with age greater than 58 deleted!\n");

    disp(&l);

    printf("\nEnter the department name you want to search : ");

    scanf(" %[^\n]s",d_name);

    disp_e(&l,d_name);

    destroy(&l);

}

void ini(employee* L)

{

    L->head=NULL;

}

node* create_node(char* ssn,char* name,long long int ph_no,char* dept,int no,char* desig,float salary,int age)

{

    node* temp=(node*)malloc(sizeof(node));

    strcpy(temp->ssn,ssn);

    strcpy(temp->name,name);

    temp->ph_no=ph_no;

    strcpy(temp->d.name,dept);

    temp->d.no=no;

    strcpy(temp->desig,desig);

    temp->salary=salary;

    temp->age=age;

    temp->right=NULL;

    temp->left=NULL;

    return temp;

}

void ins(employee* L,char* ssn,char* name,long long int ph_no,char* d_name,int d_no, char* desig,float salary,int age)

{

    node* temp=create_node(ssn,name,ph_no,d_name,d_no,desig,salary,age);  if(L->head==NULL)

    {

        L->head=temp;

        return;

    }

    temp->right=L->head;

    L->head->left=temp;

    L->head=temp;

}

void del(employee* L)

{

    if(L->head==NULL)

        return;

    node* pres=L->head,* prev=NULL,* next=NULL;  while(pres!=NULL)

    {

        if(pres->age>58)

        {

            if(prev==NULL)

            {

                L->head=pres->right; 

                if(L->head==NULL)

                {

                    free(pres);

                    return;

                }

                L->head->left=NULL;

                node* temp=pres;

                pres=pres->right;

                temp->right=NULL;

                free(temp);

            }

            else

            {

                prev=pres->left;

                next=pres->right;

                if(next==NULL)

                {

                    prev->right=NULL;  pres->left=NULL; 

                }

                else

                {

                    prev->right=next;

                    next->left=prev; 

                }

                node* temp=pres;

                prev=pres;

                pres=pres->right;

                free(temp);

            }

        }

        else

        {

            prev=pres;

            pres=pres->right;

        }

    }

}

void disp_e(employee* L,char* d_name)

{

    if(L->head==NULL)

    {

        printf("\nNothing to display!!!!\n");

        return;

    }

    node* tr=L->head;

    int flag=1;

    while(tr)

    {

        if(strcmp(tr->d.name,d_name)==0)

            printf("\nSSN: %s\nName: %s\nPh no: %lld\nDept: %s\nDept no.:%d\nD esignation: %s\nSalary: %f\nAge: %d\n",tr->ssn,tr->name,tr->ph_no,tr->d.name,tr->d.no,tr->desig,tr->salary,tr->age);

            tr=tr->right;

            flag++;

            printf("\n");

    }

    if(flag!=1)

    {

        printf("Department not found!");

    }

}

void disp(employee* L)

{

    if(L->head==NULL)

        printf("\nNothing to display\n");

    else

    {

        node* tr=L->head;

        printf("\nLinked list:\n");

        while(tr)

        { 

            printf("\nSSN: %s\nName: %s\nPh no: %lld\nDept: %s\nDept no.:%d\nDesignation: %s\nSalary: %f\nAge: %d\n",tr->ssn,tr->name,tr->ph_no,tr->d.name,tr->d.no,tr->desig,tr->salary,tr->age);

            tr=tr->right;

        }

        printf("\n\n");

    }

}

void destroy(employee* L)

{

    if(L->head==NULL)

        return;

    node* pres=L->head,* prev=NULL;

    while(pres)

    {

        prev=pres;

        pres=pres->right;

        free(prev);

    }

}