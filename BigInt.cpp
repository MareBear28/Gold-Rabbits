#include <string>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "BigInt.h"

BigInt::BigInt()
{
	digits.push_back('0');
}


BigInt::BigInt(vector<char> b)
{
	digits = b;
}

BigInt::BigInt(string n)
{
	for (int i = 0; i < n.length(); i++)
	{
		digits.push_back(char(n[i]));
	}
}

BigInt::BigInt(int n) 
{
	if (n == 0) 
	{
		digits.push_back((n % 10) + '0');
	}
	while (n > 0) 
	{
		digits.push_back((n % 10) + '0');
		n = n / 10;
	}
	reverse(digits.begin(), digits.end());
}

BigInt::BigInt(const BigInt & n)
{
	digits = n.digits;
}

vector<char> BigInt::getNum()
{
	return digits;
}

int BigInt::getSize() 
{
	return digits.size();
}

int BigInt::getValue() 
{
	string s;
	for (int i = 0; i < digits.size(); i++)
	{
		s.push_back(digits[i]);
	}

	return stoi(s);
}

BigInt BigInt::operator+(const BigInt& b) 
{
	vector<char> a = digits;
	vector<char> c = b.digits;
	vector<char> n;
	int buff = 0;
	bool check = false;
	if (a.size() > c.size())
	{
		buff = 1;
		check = true;
	}
	for (int it = a.size() - 1; it >= 0 + buff; it--)
	{
		char sum = (a[it] - 48) + (c[it - buff] - 48);
		if (int(sum) >= 10)
		{
			n.push_back(sum + 38);
			if (it == 0)
			{
				n.push_back('1');
			}
			else
			{
				a[it - 1] = a[it - 1] + 1;
			}
		}
		else
		{
			n.push_back(sum + 48);
		}
	}
	if (check)
	{
		if (int(a[0] - 48) >= 10)
		{
			n.push_back(int(a[0] - 48) + 38);
			n.push_back('1');
		}
		else {
			n.push_back(a[0]);
		}
	}
	reverse(n.begin(), n.end());
	return BigInt(n);
}

BigInt BigInt::operator+(int i) 
{
	BigInt a(i);
	return *this + a;
}

void operator++(BigInt& d, int dummy) 
{
	d = d + BigInt(1);
}


BigInt BigInt::operator-(const BigInt& b)
{
	vector<char> a = digits;
	vector<char> c = b.digits;
	vector<char> n;
	bool check = false;
	if (a.size() > c.size())
	{
		reverse(c.begin(), c.end());
		while (a.size() != c.size())
		{
			c.push_back('0');
		}
		reverse(c.begin(), c.end());
	}
	for (int it = a.size() - 1; it >= 0; it--)
	{
		char sum = (a[it] - 48) - (c[it] - 48);
		if (int(sum) < 0)
		{
			n.push_back(sum + 58);
			a[it - 1] = a[it - 1] - 1;
		}
		else
		{
			n.push_back(sum + 48);
		}
	}
	reverse(n.begin(), n.end());
	return BigInt(n);
}

ostream& operator<<(ostream& out, const BigInt& b)
{
	if (b.digits.size() > 12)
	{
		out << b.digits[0] << '.';
		for (int i = 1; i < 13; i++)
		{
			out << b.digits[i];
		}
		out << 'e' << b.digits.size() - 1;
	}
	else
	{
		for (int i = 0; i < b.digits.size(); i++)
		{
			if ((i == 0 && b.digits[i] == '0') || (b.digits[i] == '0' && b.digits[0] == '0' && b.digits[i - 1] == '0'))
			{
				continue;
			}
			out << b.digits[i];
		}

		if (b.digits.size() == 1 && b.digits[0] == '0') 
		{
			out << '0';
		}
	}
	return out;
}

void BigInt::print() 
{
	for (int i = 0; i < digits.size(); i++)
	{
		if ((i == 0 && digits[i] == '0') || (digits[i] == '0' && digits[0] == '0' && digits[i - 1] == '0'))
		{
			continue;
		}
		cout << digits[i];
	}

	if (digits.size() == 1 && digits[0] == '0')
	{
		cout << '0';
	}
}

bool operator<(BigInt a, BigInt b)
{
	if (a.getValue() < b.getValue())
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool BigInt::operator<=(BigInt b)
{
	if (getValue() <= b.getValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

BigInt BigInt::operator=(const BigInt& b) 
{
	digits =  b.digits;
	return *this;
}

bool BigInt::operator==(BigInt b)
{
	if (digits == b.digits) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}