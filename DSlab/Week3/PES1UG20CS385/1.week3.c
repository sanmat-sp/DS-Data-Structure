#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[30];
    long long int ph_no;
    char address[30];
    char area[20];
    struct node *left;
    struct node *right;
} node;
typedef struct mylist
{
    node *head;
} ll;
void ini(ll *);
node *create_node(char *, long long int, char *, char *);
void ins(ll *, char *, long long int, char *, char *);
void destroy(ll *);
void disp(ll *);
void main()
{
    ll l;
    ini(&l);
    int n;
    printf("Enter number of entries: ");
    scanf("%d", &n);
    char name[30], address[100], area[20];
    long long int ph_no;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Name: ");
        scanf(" %[^\n]s", name);
        printf("\nEnter ph no.: ");
        scanf("%lld", &ph_no);
        printf("\nEnter Address: ");
        scanf(" %[^\n]s", address);
        printf("\nEnter Area: ");
        scanf(" %[^\n]s", area);
        ins(&l, name, ph_no, address, area);
    }
    /*ins(&l,"Ajsnd",7856765678,"address","Bangalore");
ins(&l,"Zjsasb",9976779860,"address","Bangalore");*/
    disp(&l);
    destroy(&l);
}
void ini(ll *L)
{
    L->head = NULL;
}
node *create_node(char *name, long long int ph_no, char *address, char *area)
{
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->ph_no = ph_no;
    strcpy(temp->address, address);
    strcpy(temp->area, area);
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
void ins(ll *L, char *name, long long int ph_no, char *address, char *area)
{
    node *temp = create_node(name, ph_no, address, area);
    if (L->head == NULL)
    {
        L->head = temp;
        return;
    }
    node *pres = L->head, *prev = NULL;
    while (pres != NULL && strcmp(pres->name, name) < 0)
    {
        prev = pres;
        pres = pres->right;
    }
    if (pres == NULL)
    {
        prev->right = temp;
        temp->left = prev;
    }
    else if (prev == NULL)
    {
        temp->right = L->head;
        L->head->left = temp;
        L->head = temp;
    }
    else
    {
        //next=pres->right;
        prev->right = temp;
        temp->left = prev;
        temp->right = pres;
        pres->left = temp;
    }
}
void disp(ll *L)
{
    if (L->head == NULL)
        printf("\nNothing to display\n");
    else
    {
        node *tr = L->head;
        printf("\nLinked list:\n");
        while (tr)
        {
            printf("Name: %s\nPh:%lld\nAddress:%s\nArea:%s\n\n", tr->name, tr -> ph_no, tr->address, tr->area);
            tr = tr->right;
        }
        printf("\n\n");
    }
}
void destroy(ll *L)
{
    if (L->head == NULL)
        return;
    node *pres = L->head, *prev = NULL;
    while (pres)
    {
        prev = pres;
        pres = pres->right;
        free(prev);
    }
}


