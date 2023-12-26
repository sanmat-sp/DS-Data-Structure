#include<stdio.h>
#include<stdlib.h>
void push2(int *s, int *t2, int size2, int end, int ele);
void push1(int *s, int *t1, int size1, int end, int ele);
void display(int *s, int t1, int t2, int end, int size1, int size2);
void pop(int *s, int *t1, int *t2, int end);
void display_arr(int *s, int n);
int main(){
        int size1, size2;
        printf("Enter the size of stack1: ");
        scanf("%d", &size1);
        printf("Enter the size of stack 2: ");
        scanf("%d", &size2);
        int top1 = -1;
        int top2 = -1;
        int *s = (int *)malloc(sizeof((size1+size2)*sizeof(int)));
        while (1){
                printf("Enter your choice [1.push 2.pop]: ");
                int opt, stackno;
                scanf("%d", &opt);
                switch(opt){
                        case 1 : printf("Enter stack number[1 or 2]: ");
                                 scanf("%d", &stackno);
                                 int ele;
                                 printf("Enter element: ");
                                 scanf("%d", &ele);
                                 if (stackno==1)
                                        push1(s,&top1, size1, size1+size2, ele);
                                 if (stackno==2)
                                        push2(s,&top2, size2, size1+size2, ele);
                                 display(s, top1, top2, size1+size2, size1, size2);
                                 break;
                        case 2 : pop(s, &top1, &top2, size1+size2);
                                 display(s, top1, top2, size1+size2, size1, size2);
                                 break;
                        default: printf("Thanks\n"); exit(0);
                }
        }
}
void display_arr(int *s, int n){
        for (int i=0; i<n; i++)
                printf("%d\t", s[i] );
}
void display(int *s, int t1, int t2, int end, int size1, int size2){
        printf("Printing stack1:\n");
        if (t1==-1)
                printf("Stack underflow for stack1\n");
        else{
                for (int i=0; i<=t1; i++)
                        printf("%d->", s[i]);
        }
        printf("\nPrinting stack2:\n");
        if (t2 == -1)
                printf("Stack underflow for stack2\n");
        else{
                for (int i=end; i>=end-t2; i--)
                        printf("%d ", s[i]);
             
        }
        printf("\n");
}
void push1(int *s, int *t1, int size1, int end, int ele){
        if ( (*t1)+1 ==size1){
                printf("Stack overflow for stack1.\n");
                return;
        }
        else{
                (*t1)++;
                s[*t1]=ele;
        }
}
void push2(int *s, int *t2, int size2, int end, int ele){
        if ( (*t2)+1 ==size2){
                printf("Stack overflow for stack2.\n");
                return;
        }
        else{
                (*t2)++;
                s[end - (*t2)] = ele;
        }
}
void pop(int *s, int *t1, int *t2, int end){
        int top_arr = 0;
        while (top_arr <end ){
                if ( (*t1)!= -1 ){
                        (*t1)--;
                        top_arr++;
                }
                else{
                        (*t2)--;
                        top_arr++;
                       
                }
        }
}