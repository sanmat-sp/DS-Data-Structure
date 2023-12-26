#include<stdio.h>
#include<stdlib.h>
union name
{
	char ch;
	int a;
	float b;
};

int main()
{
	union name;
	name.ch="a";
	printf("%c", name.ch);
}