#ifndef PROYECTO_ESTRUCTURAS_INTEGER_H
#define PROYECTO_ESTRUCTURAS_INTEGER_H

#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Integer {

private:
	string digits;


public:

	Integer(long long);
	Integer(int);
	Integer(long);
	Integer();
	Integer(string);
	string toString();
	string getDigits();
	Integer static parse(string);//ni idea
	// Fibonacci, Combinacion , Factorial
	bool operator==(const Integer&);
	bool operator!=(const Integer&);
	bool operator<(const Integer&);
	bool operator>(const Integer&);
	bool operator<=(const Integer&);
	bool operator>=(const Integer&);
	Integer& operator=(const Integer&);
	Integer& operator*=(const Integer&);
	Integer& operator*(const Integer&);
	Integer& operator-=(const Integer&);
	Integer& operator-(const Integer&);
	Integer& operator+=(const Integer&);
	Integer& operator+(const Integer&);
	Integer& operator/=(const Integer&);//division /
	Integer& operator/(const Integer&);

	friend ostream& operator <<(ostream&, Integer&);

};











#endif //PROYECTO_ESTRUCTURAS_INTEGER_H
