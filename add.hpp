#ifndef ADD_HPP_INCLUDED
#define ADD_HPP_INCLUDED
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "math.h"
using namespace std;

#define P 1000000
bool sieve[(P-1)/2+1];
vector<int> primes;



int multiply(int r, int c, int dR, int dC, int (&grid)[20][20])
{

	int product = 1;
	for (int n = 0; n < 4; n++, r += dR, c += dC) {
		product *= grid[r][c];
	}
	return product;
}



////BIGMATH
string findSum(string str1, string str2)
{

    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";

    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {

        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        str.push_back(carry+'0');

    reverse(str.begin(), str.end());

    return str;
}


int multiply(int x, int res[], int res_size) {

int carry = 0;

for (int i = 0; i < res_size; i++) {
    int prod = res[i] * x + carry;
    res[i] = prod % 10;
    carry = prod / 10;
}

while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
}
return res_size;
}

#define MAX 100000
string Bigpow(int x, int n)
{

string resul = "";

if(n == 0 ){
    return "0";
}


int res[MAX];
int res_size = 0;
int temp = x;
while (temp != 0) {
    res[res_size++] = temp % 10;
    temp = temp / 10;
}

for (int i = 2; i <= n; i++)
    res_size = multiply(x, res, res_size);

for (int i = res_size - 1; i >= 0; i--)
    resul +=to_string(res[i]);

  return resul;
}




int multiply(int x, vector<int> &res, int res_size) {
int carry = 0;
for (int i = 0; i < res_size; i++) {
    int prod = res[i] * x + carry;

    res[i] = prod % 10;

    carry = prod / 10;
}

while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
}
return res_size;
}



vector<int> power(int x, int n)
{
#define MAX 200000
vector<int> res(MAX);
int res_size = 0;
int temp = x;
while (temp != 0) {
    res[res_size++] = temp % 10;
    temp = temp / 10;
}

for (int i = 2; i <= n; i++)
    res_size = multiply(x, res, res_size);

res.resize(res_size);
    return res;
}

string digitName(int digit);
    string teenName(int number);
    string tensName(int number);
    string intName(int number);

    vector<string> ones {"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> teens {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
    vector<string> tens {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    string nameForNumber (long number) {
        if (number < 10) {
            return ones[number];
        } else if (number < 20) {
            return teens [number - 10];
        } else if (number < 100) {
            return tens[number / 10] + ((number % 10 != 0) ? " " + nameForNumber(number % 10) : "");
        } else if (number < 1000) {
            return nameForNumber(number / 100) + " hundred" + ((number % 100 != 0) ? " and " + nameForNumber(number % 100) : "");
        } else if (number < 1000000) {
            return nameForNumber(number / 1000) + " thousand" + ((number % 1000 != 0) ? " and " + nameForNumber(number % 1000) : "");
        } else if (number < 1000000000) {
            return nameForNumber(number / 1000000) + " million" + ((number % 1000000 != 0) ? " and " + nameForNumber(number % 1000000) : "");
        } else if (number < 1000000000000) {
            return nameForNumber(number / 1000000000) + " billion" + ((number % 1000000000 != 0) ? " and " + nameForNumber(number % 1000000000) : "");
        }
        return "error";
    }



string Split(string str,char sp)
{
    string word = "";
    for (auto x : str)
    {
        if (x != sp)
        {
            word = word + x;
        }
    }
    return word;
}

void perm(string &s,int amount)
{
    for(int i=1;i<amount;i++){

        bool val = next_permutation(s.begin(),s.end());
    }
}

int powOf(int a)
{
	for (int i = 2; i*i <= a; i++) {
		if (a % i == 0) {
			int pow = 0, temp = a;
			for (; temp % i == 0; temp /= i, pow++);
			if (temp == 1)
				return pow;
		}
	}
	return 1;
}

void move(int depth, int cur, int used, long long full ,long long &nsum)
{
    const int primes[] = {2,3,5,7,11,13,17};
	if (depth == 9) {
		for (int n = 0; n < 10; n++) {
			if (used & (1 << n)) continue;
			nsum += full + n * 1000000000LL;
			return;
		}
	}
	for (int n = 0; n < 10; n++) {
		if (used & (1 << n)) continue;
		if ((cur + n) % primes[depth-2] == 0) {
			move(depth + 1, (cur % 100 + n)*10, used + (1 << n), full * 10 + n,nsum);
		}
	}
}

///51 BAD SOLUTION
int getMax(int combi, int num)
{
	int offset = 0, origDigit = -1;
	for (int multiplier = 10, shift = 0; combi >= (1 << shift); multiplier *= 10, shift++) {
		if ((1 << shift) & combi) {
			int digit = num / multiplier % 10;
			if (origDigit == -1) origDigit = digit;
			if (origDigit != digit) return 0;
			num -= digit * multiplier;
			offset += multiplier;
		}
	}
	int numPrimes = 1;
	for (int digit = origDigit+1; digit < 10; digit++) {
		if (sieve[(num+offset*digit)/2]) continue;
		numPrimes++;
	}
	return numPrimes;
}

void getPrimes()
{
	int sievebound = (P-1)/2;
	int crossbound = ((int)sqrt((double)P)-1)/2;
	for (int i = 1; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	primes.push_back(2);
	for (int i = 1; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(2*i+1);
}




#endif
