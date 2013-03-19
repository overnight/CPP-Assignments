#include <stdio.h>
#include <iostream>
#include "complex.h"
using namespace std;

void add()
{
	Complex a,b;
	cout<<"Enter 1st complex in form a+bi:";
	cin>>a;
	cout<<"Enter 2st complex in form a+bi:";
	cin>>b;
	cout<< "addition is: "<<(a+b);
}
void sub()
{
	Complex a,b;
	cout<<"Enter 1st complex in form a+bi:";
	cin>>a;
	cout<<"Enter 2st complex in form a+bi:";
	cin>>b;
	cout<< "subtraction is: "<<(a-b);
}
void mult()
{
	Complex a,b;
	cout<<"Enter 1st complex in form a+bi:";
	cin>>a;
	cout<<"Enter 2st complex in form a+bi:";
	cin>>b;
	cout<< "multiplication is: "<<(a*b);
}
void div()
{
	Complex a,b;
	cout<<"Enter 1st complex in form a+bi:";
	cin>>a;
	cout<<"Enter 2st complex in form a+bi:";
	cin>>b;
	if(*b==0)
	{
		cout<<"b cannot be 0";
		return;
	}
	cout<< "divition is: "<<(a/b);
}
void conj()
{
	Complex a;
	cout<<"Enter complex in form a+bi:";
	cin>>a;
	
	cout<< "congujate is: "<<(!a);
}
void norm()
{
	Complex a;
	cout<<"Enter complex in form a+bi:";
	cin>>a;	
	cout<< "divition is: "<<(*a);
}
void inv()
{
	Complex a;
	Complex b(1,0);
	cout<<"Enter complex in form a+bi:";
	cin>>a;	
	cout<< "inverse is: "<<(b/a);
}
void pow()
{
	Complex a;
	Complex b;
	int p;
	cout<<"Enter complex in form a+bi:";
	cin>>a;	
	cout<<"Enter power";
	cin>>p;
	b=a;
	for(int i=1;i<p;i++)
	{
		b=b*a;
	}
	cout<< "power is: "<<b;
}
int main(int argc, char **argv)
{
	char ch;
	int i;
	do
	{
		printf("To ADD enter 1\n");
		printf("To SUBTRACT enter 2\n");
		printf("To MULTIPLY enter 3\n");
		printf("To DIVIDE enter 4\n");
		printf("To TAKE CONJUGATE enter 5\n");
		printf("To TAKE NORM enter 6\n");
		printf("To TAKE INVERSE enter 7\n");
		printf("To RASE TO POSITIVE POWER enter 8\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: add();
					break;
			case 2: sub();
					break;
			case 3: mult();
					break;
			case 4: div();
					break;
			case 5: conj();
					break;
			case 6: norm();
					break;
			case 7: inv();
					break;
			case 8: pow();
					break;
			default: cout<<"invalid number"<<endl;
		}
		printf("\nDo u wish to contiue(y/n):");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
}
