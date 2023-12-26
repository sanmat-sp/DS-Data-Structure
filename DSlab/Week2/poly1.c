#include<stdio.h>
#include<stdlib.h>

struct polynomial{
        int coeff;
        int xpwr;
        int ypwr;
        struct polynomial* link;
        };
typedef struct polynomial poly_t;

struct list{
        poly_t* head;
        };
typedef struct list list_t;

void display(list_t* list)
{
        poly_t* pres = list->head;
        while(pres != NULL)
        {
                printf("%dx^%dy^%d + ", pres->coeff, pres->xpwr, pres->ypwr);
                pres = pres->link;
        }
}

void init(list_t* term)
{
        term->head = NULL;
}

void insert(list_t* term, poly_t* element)
{

        poly_t* pres = term->head;
        poly_t* prev = NULL;
        
        while(pres != NULL)
        {
                prev = pres;
                pres = pres->link;
        }
        if(prev == NULL)
        {
                term->head = element;
        }
        else
        {
                prev->link = element;
        }
}
        

int main()
{
        int n, m, t;
        list_t term_1;
        list_t term_2;
        init(&term_1);
        init(&term_2);
        
        printf("Enter number of terms for 1st polynomial: ");
        scanf("%d", &n);
        for(int i = 0; i<n; i++)
        {
                poly_t* element = (poly_t*)malloc(sizeof(poly_t));
                printf("Enter coeff: ");
                scanf("%d", &(element->coeff));
                printf("Enter power of x: ");
                scanf("%d", &(element->xpwr));
                printf("Enter power of y: ");
                scanf("%d", &(element->ypwr));
                element->link = NULL;
                insert(&term_1, element);
        }
        
        printf("Enter number of terms for 2nd polynomial: ");
        scanf("%d", &m);
        for(int i = 0; i<m; i++)
        {
                poly_t* element = (poly_t*)malloc(sizeof(poly_t));
                printf("Enter coeff: ");
                scanf("%d", &(element->coeff));
                printf("Enter power of x: ");
                scanf("%d", &(element->xpwr));
                printf("Enter power of y: ");
                scanf("%d", &(element->ypwr));
                element->link = NULL;
                insert(&term_2, element);
        }

        printf("\nterm 1:\n");
        display(&term_1);
        printf("\nterm 2:\n");
        display(&term_2);
        if(n<=m)
        {
                poly_t* pres2 = term_2.head;
                while(pres2 != NULL)
                {
                        poly_t* pres1 = term_1.head;
                        while(pres1 != NULL)
                        {
                                if((pres1->xpwr == pres2->xpwr) && (pres1->ypwr == pres2->ypwr))
                                {
                                        pres2->coeff = pres2->coeff + pres1->coeff;
                                }
                                pres1 = pres1->link;
                        }
                        pres2 = pres2->link;
                }
        printf("\nresult:\n");
        display(&term_2);
        }
                        
                        
        else
        {
                poly_t* pres1 = term_1.head;
                while(pres1 != NULL)
                {
                        poly_t* pres2 = term_2.head;
                        while(pres2 != NULL)
                        {
                                if((pres1->xpwr == pres2->xpwr) && (pres1->ypwr == pres2->ypwr))
                                {
                                        pres1->coeff = pres2->coeff + pres1->coeff;
                                }
                                pres2 = pres2->link;
                        }
                }
        printf("\nresult:\n");
        display(&term_1);
        }
        return 0;
}