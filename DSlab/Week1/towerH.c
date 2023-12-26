#include <stdio.h>
 
void hanoi(int,char,char,char);

int main()
{
    int n;
    printf("Enter the no of discs:");
    scanf("%d",&n); 
    hanoi(n, 'A' , 'C' , 'B');  
    return 0;
}

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from tower %c to tower %c", from,to);
        return;
    }
    hanoi(n-1,from,aux,to);
    printf("\n Move disk %d from tower %c to tower %c", n,from, aux);
    hanoi(n-1, aux,to,from);
}

