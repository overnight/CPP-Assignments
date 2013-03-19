#include "complex.h"
#include <stdlib.h>
#include <math.h>
#if 1
 const Complex Complex::sc_cUnityR(0,1); 	// Defines 1+j0
const Complex sc_cUnityI(0,1); 	// Defines 0+j1
	 const Complex sc_cZero(0,0); 	 
Complex::Complex(double real,double imaginary)
{
	re_=real;
	im_=imaginary;
}
Complex::Complex(const Complex& number)
{
	re_=number.re_;
	im_=number.im_;
}
Complex::~Complex()
{
}
Complex& Complex:: operator=(const Complex& number)
{
	re_=number.re_;;
	im_=number.im_;
	return *this;
}
Complex Complex:: operator+(const Complex& number)
{
	return *(new Complex(re_+number.re_,im_+number.im_));
}
Complex Complex ::operator-(const Complex& number)
{
	return *(new Complex(re_-number.re_,im_-number.im_));
}
Complex Complex:: operator*(const Complex& number)
{
	return *(new Complex(re_*number.re_-im_*number.im_,re_*number.im_+im_*number.re_));
}
Complex Complex ::operator/(const Complex& number)
{
	return (((*this)*(!number))/(number.re_*number.re_+number.im_*number.im_));
}
Complex Complex:: operator/(double d)
{
	return *(new Complex(re_/d,im_/d));
}
Complex Complex ::operator-()
{
	return *(new Complex(-re_,-im_));
}
Complex  Complex:: operator+()
{
	return *(new Complex(+re_,+im_));
}
Complex&  Complex:: operator--()
{
	--re_;
	return *this;
}
Complex& Complex:: operator++()
{
	++re_;
	return *this;
}
Complex Complex:: operator--(int a)
{
	--im_;
	return *this;
}
Complex Complex::operator++(int a)
{
	++im_;
	return *this;
}
bool Complex:: operator==(const Complex& number)
{
	double a =(*(*this));
	double b = (*number);
	return (a==b);
}
bool Complex:: operator!=(const Complex& number)
{
	double a =(*(*this));
	double b = (*number);
	return (a!=b);
}
bool Complex:: operator<(const Complex& number)
{
	double a =(*(*this));
	double b = (*number);
	return (a<b);
}
bool Complex:: operator<=(const Complex& number)
{
	double a =(*(*this));
	double b = (*number);
	return (a<=b);
}
bool Complex:: operator>(const Complex& number)
{
	double a =(*(*this));
	double b = (*number);
	return (a>b);
}
bool Complex:: operator>=(const Complex& number)
{
	double a =(*(*this));
	double b = (*number);
	return (a>=b);
}
Complex& Complex::operator+=(const Complex& number)
{
	re_+=number.re_;
	im_+=number.im_;
	return *this;
}
Complex& Complex::operator-=(const Complex& number)
{
	re_-=number.re_;
	im_-=number.im_;
	return *this;
}
Complex& Complex::operator*=(const Complex& number)
{
	double temp=re_*number.im_+im_*number.re_;
	re_=re_*number.re_-im_*number.im_;
	im_=temp;
	return *this;
}
Complex& Complex::operator/=(const Complex& number)
{
	*this = (((*this)*(!number))/(number.re_*number.re_+number.im_*number.im_));
	return *this;
}
double Complex::operator*() const
{
	return sqrt((re_*re_)+(im_*im_));
}
Complex Complex::operator!() const
{

	return *(new Complex(re_,-im_));
}
double Complex::GetReal()
{
	return re_;
}
double Complex::GetImg()
{
	return im_;
}
void* Complex::operator new(size_t s)
{
	return malloc(s);
}
void Complex::operator delete(void *ptr)
{
	free(ptr);
}
std::ostream& operator<<(std::ostream& out, const Complex& num)
{
	if(num.im_<0)
		return out<<num.re_<<num.im_<<"i";
	return out<<num.re_<<"+"<<num.im_<<"i";
}

std::istream& operator>>(std::istream& in, Complex& num)
{
	char t;
	return in>>num.re_>>num.im_>>t;
}
Complex const& Complex::operator[](unsigned int a) const
{
	return *(this+a);
}
Complex& Complex::operator[](unsigned int a)
{
	return *(this+a);
}
#endif
