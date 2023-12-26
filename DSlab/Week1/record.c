#include<stdio.h>
#include<string.h>
typedef struct stud
{
char SRN[14];
char name[25];
int sem;
struct marks
{
int PH101;
int MA151;
int CS151;
int ME101;
int EE101;
}m;
}stud;
void swap(stud*,stud*);
void main()
{
int n;
printf("Enter number of students: ");
scanf("%d",&n);
stud s[n+1];
for(int i=0;i<n;i++)
{
printf("\nSRN: ");
scanf(" %[^\n]s",s[i].SRN);
printf("Name: ");
scanf(" %[^\n]s",s[i].name);
printf("Sem: ");
scanf("%d",&s[i].sem);
printf("Marks for PH101, MA151, CS151, ME101, EE101:\n");
scanf("%d%d%d%d%d",&s[i].m.PH101,&s[i].m.MA151,&s[i].m.CS151,&s[i].m.ME101,&s[i].m.EE101);
}
float PHsum=0,MAsum=0,CSsum=0,MEsum=0,EEsum=0;
//a)
for(int i=0;i<n;i++)
{
PHsum+=s[i].m.PH101;
MAsum+=s[i].m.MA151;
CSsum+=s[i].m.CS151;
MEsum+=s[i].m.ME101;
EEsum+=s[i].m.EE101;
}
printf("\n\nClass average marks in:\nPhysics(PH101)=%.2f\nMaths(MA151)=%.2f\nComputer Science(CS151)=%.2f\nMechanics(ME101)=%.2f\nElectrical(EE101)=%.2f\n\n",PHsum/n,MAsum/n,CSsum/n,MEsum/n,EEsum/n);
        //b)
        for(int i=0;i<n-1;i++)
        for(int j=0;i<n-i-1;i++)
        if(strcmp(s[j].SRN,s[j+1].SRN)>=1)
        swap(&s[j],&s[j+1]);
        for(int i=0;i<n;i++)
        {
        printf("\nSRN: %s",s[i].SRN);
printf("\nName: %s",s[i].name);
printf("\nSem: %d",s[i].sem);
printf("\nMarks:\nPH101:%d\nMA151:%d\nCS151:%d\nME101:%d\nEE101:%d\n",s[i].m.PH101,s[i].m.MA151,s[i].m.CS151,s[i].m.ME101,s[i].m.EE101);
}
}
void swap(stud* n1, stud* n2)
{
stud temp=*n1;
*n1=*n2;
*n2=temp;
}

