#ifndef BigInt_h
#define BigInt_h
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class BigInt 
{
	private:
		vector<char> digits;
	public:
		BigInt();
		BigInt(vector<char>);
		BigInt(string);
		BigInt(int);
		BigInt(const BigInt &);
		vector<char> getNum();
		int getSize();
		int getValue();
		BigInt operator+(const BigInt &);
		BigInt operator+(int);
		friend void operator++(BigInt&, int);
		BigInt operator-(const BigInt &);
		friend ostream& operator<<(ostream&, const BigInt&);
		void print();
		friend bool operator<(BigInt c, BigInt d);
		bool operator<=(BigInt);
		BigInt operator=(const BigInt&);
		bool operator==(BigInt);
};

#endif    