#include <stdexcept>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class rational

{
    private:
    
	int numerator;
	int denominator;
    
    public:

	rational()
	{
		numerator = 0;
		denominator = 0;
	}

	rational(int n, int d)
	{
		setnumerator(n);
		setdenominator(d);
	}

	void setnumerator(int n)
	{
		numerator = n;
	}
    
	void setdenominator(int d)
	{
		if (d == 0) 
			throw runtime_error("Denominator should not be less than or equal to zero");
		else
		denominator = d;
	}

	int getnumerator()
	{
		return numerator;
	}

	int getdenominator()
	{
		return denominator;
	}

	void  simplestForm() 
    {
		int largest = numerator > denominator ? numerator : denominator;
		int gcd = 0; // greatest common divisor

		for (int loop = 2; loop <= largest; ++loop)
			if (numerator % loop == 0 && denominator % loop == 0)
			gcd = loop;

		    if (gcd != 0) 
            {
			numerator /= gcd;
			denominator /= gcd;
		    }
	}
	
	void display()
    {
		cout << "The rational number is :" << numerator  << "/" << denominator  << endl;
	}
    
	rational  add(rational r2)
	{
			rational result =  rational();
			result.denominator = denominator * r2.denominator;
			result.numerator = (numerator*r2.denominator) + (denominator*r2.numerator);
			result.simplestForm();
			result.display();
			return result;
	}

	rational sub(rational r2)
	{
			rational result;
			result.denominator = denominator * r2.denominator;
			result.numerator = (numerator*r2.denominator) - (denominator*r2.numerator);
			result.simplestForm();
			result.display();
			return result;
	}

	rational mul(rational r2)
	{
			rational result=rational();
			result.denominator = denominator * r2.denominator;
			result.numerator = numerator*r2.numerator;
			result.simplestForm();
			result.display();
			return result;
	}

	rational div(rational r2)
	{
			rational result=rational();
			result.denominator = denominator * r2.numerator;
			result.numerator = numerator * r2.denominator;
			result.simplestForm();
			result.display();
			return result;
	}
	
};
