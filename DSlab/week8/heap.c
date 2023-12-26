#include<stdio.h>
#include<stdlib.h>
void top_heap(int *h, int n);
int main()
{
        int h[100];
        int n, i;
        printf("Enter the number pf elements : ");
        scanf("%d", &n);
        printf("Enter the elemnents :  ");
        for(i=0;i<n;i++)
                scanf("%d", &h[i]);
        top_heap(h, n-1);
        printf("Elements are : ");
        for(i=0;i<n;i++)
                printf("%d ", h[i]);
}

void top_heap(int *h, int n)
{
        int i, k, key, j;
        for(k=0;k<n;k++)
        {
                i=k;
                key=h[i];
                j=(i-1)/2;
                while(i>0 && key<h[j])
                {
                        h[i]=h[j];
                        i=j;
                        j=(i-1)/2;
                }
                h[i]=key;
        }
}
