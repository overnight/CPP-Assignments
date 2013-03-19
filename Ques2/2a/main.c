#include <stdio.h>
#include <math.h>
#include <setjmp.h>

jmp_buf env;
void solve(double a, double b, double c)
{
	if(a==0&&b==0) longjmp(env,1);
	if(a==0) longjmp(env,2);
	double d = b*b - 4*a*c;
	if(d>0)
	{
		d= sqrt(d);
		printf("Roots are distinct and real: %lf\t%lf\n",(-b-d)/(2*a),(-b+d)/(2*a));
		return;
	}
	if(d==0)
	{
		printf("Single repeted root is: %lf\n",-b/(2*a));
		return;
	}
	double rel = -b/(2*a);
	double img =fabs(sqrt(-d)/(2*a));
	printf("imagenary roots are:");
	printf("%lf+%lfi\t",rel,img);
	printf("%lf%lfi\n",rel,-img);
}
int main(int argc, char **argv)
{
	char ch;
	double a,b,c,jmp;
	
	do
	{
		jmp = setjmp(env);
		if(jmp==0)
		{
			printf("Enter a: ");
			scanf("%lf",&a);
			printf("Enter b: ");
			scanf("%lf",&b);
			printf("Enter c: ");
			scanf("%lf",&c);
			solve(a,b,c);
		}
		else
		{
			if(jmp==1)
			{
				printf("Exeption!NO root exists\n");
			}
			if(jmp==2)
			{
				printf("Exeption!not a quad eq. Root is: %lf\n",-c/b);
			}
		}
		printf("Do u wish to contiue(y/n):");
		scanf(" %c",&ch);
	}
	while(ch=='y'||ch=='Y');
	return 0;
}
