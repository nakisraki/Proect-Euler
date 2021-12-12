#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

typedef std::set<int>   Sieve;
long long reverse_int(long long num)
{
    long long rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

string reverseStr(string str)
{
    int n = str.length();
    string s = str;
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
    return s;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int gcd(int a, int b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

vector<long long int> allPr(int P){
    vector<long long int> primes;
    bool sieve[(P-1)/2+1];
    int sievebound = (P-1)/2;
	long long int crossbound = ((long long int)sqrt((double)P)-1)/2;
	for (int i = 1; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	primes.push_back(2);
	for (int i = 1; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(2*i+1);
 return primes;
}

vector<int> isPr(int n){
vector<int> is_prime(n+1, true);
is_prime[0] = false;
is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}

return is_prime;
}

bool isPrime(long long int n)
{
	for (int p = 2; p*p <= n; p++) {
		if (n % p == 0) return false;
	}
	return true;
}


int divisors_numb(int n)
{
	int nf = 1;
	for (int pf = 2; pf <= n; pf++) {
		int comb = 1;
		for (; n % pf == 0; n /= pf, comb++);
		nf *= comb;
	}
	return nf;
}

int sumOfFactors(int number) {
    int sqrtOfNumber = (int)sqrt(number);
    int sum = 1;
    if (number == sqrtOfNumber * sqrtOfNumber) {
        sum += sqrtOfNumber;
        sqrtOfNumber--;
    }

    for (int i = 2; i <= sqrtOfNumber; i++) {
        if (number % i == 0) {
            sum = sum + i + (number / i);
        }
    }

    return sum;
}

int base (int x){
   int b = 1;
   while(x>=10){
    x /= 10;
    b*=10;
   }
   return b;
}

bool setDigits(bool used[], int n)
{
	for (; n > 0; n /= 10) {
		if (used[n % 10])
			return false;
		used[n % 10] = 1;
	}
	return true;
}


string bin(long int n)
{
    int binaryNum[32];


    int i = 0;
    while (n > 0) {


        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    string bin = "";


    for (int j = i - 1; j >= 0; j--)
        bin += to_string(binaryNum[j]);

    return bin;
}

bool pandigital(long int n){
	bool stash[] = {true,true,true,true,true,true,true,true,true};
	int digit,i = 0;
	while (n != 0){
		digit = n % 10;
		if(digit == 0) return false;
		else stash[digit-1] = false;

		n /= 10;
		i++;
	}

	for (i = i-1; i >= 0; i--){	if (stash[i] != false) return false; }
	return true;
}


bool isPent(int p)
{
	double n = sqrt(24*p + 1.) + 1;
	return (n == (int)n && (int)n % 6 == 0);
}

bool isTwiceSquare(long number) {
    double squareTest = sqrt(number/2);
    return squareTest == ((int)squareTest);
}

auto primeList = allPr(10000);
 int NumberOfPrimeFacors(int number) {
    int nod = 0;
    bool pf;
    int remain = number;

    for (int i = 0; i < primeList.size(); i++) {
        if (primeList[i] * primeList[i] > number) {
            return ++nod;
        }

        pf = false;
        while (remain % primeList[i] == 0) {
            pf = true;
            remain = remain / primeList[i];
        }
        if (pf){
            nod++;
        }
        if (remain == 1) {
            return nod;
        }
    }
    return nod;
 }

 string sortuniqString(int st)
{
   bool check[10] = {false};
   while(st>=1){
    int n = st%10;
    check[n] = true;
    st /= 10;
   }
   string str = "";
   for (int i=0;i<10;i++){
     if(check[i]==true){
        str += to_string(i);
     }
   }
   sort(str.begin(), str.end());
   return str;
}

int binomial(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    return binomial(n - 1, k - 1)
           + binomial(n - 1, k);
}



#endif // MATH_H_INCLUDED
