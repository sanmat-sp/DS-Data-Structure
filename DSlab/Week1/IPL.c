#include<stdio.h>
#include<stdlib.h>

struct players
{
    char p_name[20];
    char t_name[20];
    int matches;
    int runs;
};
typedef struct players I_T;

void display_record(I_T* ,int );
void display_max(I_T* ,int );
void swap(I_T*,I_T*); 

int main()
{
    int n;
    I_T records[100];
    printf("Enter number of players records:\n");
    scanf("%d",&n);
    I_T temp;
    for(int i=0;i<n;i++)
    {
        printf("Enter player info as playername , teamname , runs scored , no of matches:\n");
        scanf("%s ",temp.p_name);
        scanf("%s ",temp.t_name);
        scanf("%d",&(temp.runs));
        scanf("%d",&(temp.matches));
        fflush(stdin);

        *(records+i)= temp;
    }

    display_record(records,n);
    display_max(records,n);
    return 0;
}


void display_record(I_T* p,int n)
{
    printf("\nNAME\tTeamname\tRUNS\tMatches\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%s\t%d\t%d\n",(p+i)->p_name,(p+i)->t_name,(p+i)->runs,(p+i)->matches);
    }

}

void display_max(I_T* p,int n)
{
    int pos,i,j;
    for(i = 0;i<n-1;i++)
    {
        pos = i;
        for(j = i+1;j<n;j++)
        {
            if((p+i)->runs > (p+j)->runs)
                pos=j;
        }
        if(pos != i)
            swap(p+pos,p+i);
    }
    printf("Details of player with max runs \n%s\t%s\t%d\t%d\n",(p+n-1)->p_name,(p+n-1)->t_name,(p+n-1)->runs,(p+n-1)->matches);
}


void swap(I_T* lhs,I_T* rhs)
{
        I_T temp = *lhs;
        lhs = rhs;
        *rhs = temp;
}