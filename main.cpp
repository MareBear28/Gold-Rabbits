#include <climits>
#include <iostream>
#include <string>
#include "BigInt.h"    
using namespace std;
#include "GoldRabbits.tools"


void pause() { cout << "Press Enter to continue..."; getchar(); } // utility function
int main()
{
	BigInt B1("123456789123456789123456789123456789");
	BigInt B2(B1);
	BigInt MAX(INT_MAX);
	cout << "B1:" << B1 << "\nB2:" << B2 << "\nMAX:" << MAX << endl;
	pause();
	cout << "\nB1:";
	B1.print();
	cout << endl;
	pause();
	BigInt display;
	for (BigInt i = 0; i <= BigInt(50); i++)
	{
		cout << "\ngoldRabbits(" << i << ") = " << goldRabbits(i);
	}
	cout << "\n\nThis is the long value of goldRabbits(3000)\n\n";
	BigInt gR3000 = goldRabbits(BigInt(3000));
	gR3000.print();
	cout << "\n\nThis is the short value of goldRabbits(3000):" << gR3000 << endl;
	pause();
	int n = 500;
	try {
		cout << "\nThe value of goldRabbits(" << n << ") is: ";
		cout << goldRabbits(n) << endl;
	}
	catch (const string& error)
	{
		cout << error << endl;
		cout << "Transitioning to BigInt\n";
		cout << goldRabbits(BigInt(n)) << endl;
	}
	pause();
}
