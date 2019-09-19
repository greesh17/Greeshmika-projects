#include <iostream>
#include <stdexcept>
#include <string>
#include<iomanip>
#include "rational.h"

using namespace std;

class calculator
{
    public:

	void enter()
	{
		int num, den;
		cout << "enter first rational number numerator:";
		cin >> num;
		cout << "enter first rational number denominator:";
		cin >> den;
		r1 = rational(num, den);
		r1.display();
		
		cout << "enter second rational number numerator:";
		cin >> num;
		cout << "enter second rational number denominator:";
		cin >> den;
		r2 = rational(num, den);
		r2.display();
	}

	void add()
	{
		rational temp = r1.add(r2);
		r1 = temp;
	}
	void sub()
	{
		rational temp = r1.sub(r2);
		r1 = temp;
	}
	void mul()
	{
		rational temp = r1.mul(r2);
		r1 = temp;
	}
	void  div()
	{
		 rational temp = r1.div(r2);
		 r1 = temp;
	}
	void swap()
	{
		rational temp;
		temp = r1;
		r1 = r2;
		r2 = temp;
		r1.display();
		r2.display();
	}

    private:
	rational r1, r2;
};

int main()
{
	calculator c;
	char command;
	
	do
	{
		cin >> command;
		if (command == 'e')
		{
			c.enter();
		}
		else if (command == '+')
		{
			c.add();
		}
		else if (command == '-')
		{
			c.sub();
		}
		else if (command == '*')
		{
			c.mul();
		}
		else if (command == '/')
		{
			c.div();
		}
		else if (command == 's')
		{
			c.swap();
		}
	} while (command != 'q');
}