#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
class Complex
{
	public:
	
		Complex(double real,double imaginary)
		{
		
			re_=real;
			im_=imaginary;
			
		}
		
		
		Complex operator/(double d)
		{
			return *(new Complex(re_/d,im_/d));
		}
		
		Complex operator!() const
		
		{
		
			return *(new Complex(re_,-im_));
		}
		// Complex conjugate
// BASIC I/O using FRIEND FUNCTIONS
// --------------------------------
		friend std::ostream& operator<<(std::ostream& out , const Complex& num)
		{
			if(num.im_<0)
				return out<<num.re_<<num.im_<<"i";
			return out<<num.re_<<"+"<<num.im_<<"i";
		}
		
		double GetReal()
		{
			return re_;
		};
		double GetImg()
		{
			return im_;
		};
	private:
// DATA MEMBERS
// ------------
		double re_;			// The real part
		double im_;			// The imaginary part
};
void solve(double a, double b, double c)
{
	if(a==0&&b==0) throw 1;
	if(a==0) throw 2;
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
	Complex root(-b,sqrt(-d));
	root = root/(2*a);
	printf("imagenary roots are:");
	cout<<root<<"\t";
	cout<<(!root)<<endl;
}
int main(int argc, char **argv)
{
	char ch;
	double a,b,c;
	
	do
	{
		printf("Enter a: ");
		scanf("%lf",&a);
		printf("Enter b: ");
		scanf("%lf",&b);
		printf("Enter c: ");
		scanf("%lf",&c);
		try
		{
			solve(a,b,c);
		}
		catch(int e)
		{
			if(e==1)
			{
				printf("Exeption!NO root exists\n");
			}
			if(e==2)
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
