#ifndef COMPLEX_H
#define COMPLEX_H
//#if 1
#include <stdio.h>
#include <iostream>

class Complex
{
	public:
// CONSTRUCTOR
// -----------
//Uses default parameters.
//Overloads to
//Complex(double, double);
//Complex(double);
//Complex();
		Complex(double = 0.0, double = 0.0);
// Copy Constructor - needed for efficient parameter passing
		Complex(const Complex&);		// Param cannot be changed (const)
// DESTRUCTOR
// ----------
		~Complex();						// No virtual destructor needed
// BASIC ASSIGNEMENT OPERATOR
// --------------------------
		Complex& operator=(const Complex&);
// BINARY ARITHMETIC OPERATORS
// ---------------------------
		Complex operator+(const Complex&);
		Complex operator-(const Complex&);
		Complex operator*(const Complex&);
		Complex operator/(const Complex&);
		Complex operator/(double);
// UNARY ARITHMETIC OPERATORS
// --------------------------
		Complex operator-();				//Operand 'this' implicit
		Complex operator+();
		Complex& operator--();				//Decrement real part by unity
		Complex& operator++();				//Increment real part by unity
		Complex operator--(int);			//Decrement imaginary part by unity
		Complex operator++(int);			//Increment imaginary part by unity
// BINARY RELATIONAL OPERATORS
// ---------------------------
// Comparisons are based on the norms of the Complex numbers
		bool operator==(const Complex&);
		bool operator!=(const Complex&);
		bool operator<(const Complex&);
		bool operator<=(const Complex&);
		bool operator>(const Complex&);
		bool operator>=(const Complex&);
// ADVANCED ASSIGNEMENT OPERATORS
// ------------------------------
		Complex& operator+=(const Complex&);
		Complex& operator-=(const Complex&);
		Complex& operator*=(const Complex&);
		Complex& operator/=(const Complex&);
// ARRAY INDEX OPERATOR
// --------------------
		Complex const& operator[](unsigned int) const;	// Read-only access
		Complex& operator[](unsigned int); 				// Read/Write access:
// CONVERSION OPERATORS
// --------------------
		double operator*() const; 						// Computes the norm
// SPECIAL OPERATORS
// -----------------
		Complex operator!() const; 						// Complex conjugate
// BASIC I/O using FRIEND FUNCTIONS
// --------------------------------
		friend std::ostream& operator<<(std::ostream&, const Complex&);
		friend std::istream& operator>>(std::istream&, Complex&);
// DYNAMIC MEMORY OPERATORS
// ------------------------
		void *operator new(size_t s);
		void operator delete(void *ptr);
// CONSTANTS OF DATATYPE
// ---------------------
		static const Complex sc_cUnityR; 	// Defines 1+j0
		static const Complex sc_cUnityI; 	// Defines 0+j1
		static const Complex sc_cZero; 	 	// Defines 0+j0
// COMPONENT FUNCTIONS
//--------------------
		double GetReal() ;
		double GetImg();
	private:
// DATA MEMBERS
// ------------
		double re_;			// The real part
		double im_;			// The imaginary part
};




//#endif
#endif // COMPLEX_H
