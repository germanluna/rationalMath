#include<iostream>
using namespace std;

class Rational{
	friend ostream &operator<<(ostream &, Rational &);
private:
	int numerator, denominator;
public:
	Rational():numerator(0), denominator(1){}
	Rational(int x):numerator(x), denominator(1){}
	Rational(int x, int y):numerator(x), denominator(y){}

	Rational operator+(const Rational &);
	Rational operator-(const Rational &);
	Rational operator*(const Rational &);
	Rational operator/(const Rational &);
};

//finding the Greatest Common Divisor
int gcd(int num, int denum){	
	return (denum==0)? num: gcd(denum, num % denum);
}

void normalize(int &x, int &y){
	int commonDiv = gcd(x,y);
	x = x/commonDiv;
	y = y/commonDiv;
}

//Overloading the "<<" operator, the "cout" 
ostream &operator<<(ostream &out, Rational &frac){
	normalize(frac.numerator,frac.denominator);
	if(frac.denominator == 1 && frac.numerator != 0){
		out << frac.numerator;
		return out;
	}
	out << frac.numerator<<"/" << frac.denominator;
	return out;

}

//Overloading the "+" operator, so it nows how to add two rational numbers
Rational Rational:: operator+(const Rational &x){
	return Rational((numerator * x.denominator) + (denominator * x.numerator),
			denominator * x.denominator);
}

//Overloading the "-" operator
Rational Rational:: operator-(const Rational &x){
	return Rational((numerator * x.denominator) - (denominator * x.numerator),
			denominator * x.denominator);
}	

//Overloading the "*" operator
Rational Rational:: operator*(const Rational &x){
	return Rational(numerator * x.numerator, denominator * x.denominator);
}

//Overloading the "/" operator
Rational Rational:: operator/(const Rational &x){
	return Rational(numerator * x.denominator, denominator * x.numerator);
}

//TEST DRIVER
int main(){
Rational num(4,6);
Rational num1(5,2);
Rational num2(3,4);
Rational num3 = num1 + num2;
Rational num4 = num1 - num2;
Rational num5 = num1 * num2;
Rational num6 = num1 / num2;

cout<<num1<<" + " <<num2<<" = "<<num3<<endl;
cout<<num1<<" - " <<num2<<" = "<<num4<<endl;
cout<<num1<<" * " <<num2<<" = "<<num5<<endl;
cout<<num1<<" / " <<num2<<" = "<<num6<<endl;

return 0;

}
