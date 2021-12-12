#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include "add.hpp"
#include "math.h"
#include "pokerscore.h"
#include <cmath>



using namespace std;
auto pr = allPr(10000000);
auto ipr = isPr(10000000);
int limit_m = 1000000;

void one_five(){
   int ans = 0;
   for(int i=1;i<1000;i++){
    if(i%3==0 || i%5==0)
        ans+=i;
   }
   cout << "One:" << ans << endl;
   ans = 0;
   int x = 1,y = 2,temp;
   while(x<4000000){
       temp = x;
       x = y;
       y = temp + x;
       if(x%2==0){
        ans+=x;
       }
   }
   cout << "Two:" << ans << endl;

   long long int num = 600851475143;
	for (int n = 3; n < num; n++)
		while (num % n == 0)
			num /= n;
   cout << "Three:" << num << endl;
   ans = 0;
   for(int i=100;i<1000;i++){
       for(int j=100;j<1000;j++){
          if(i*j==reverse_int(i*j) && i*j>ans){
            ans = i*j;
          }
       }
   }
   cout << "Four:" << ans << endl;

   num = 1;
   for(int i = 10;i<20;i++){
    num = num*(i/gcd(i,num));
   }
   cout << "Five:" << num << endl;

}

void six_ten()
{
    long long int x=0,y=0;

    for(int i=1;i<101;i++){
        x += i;
        y += (i*i);
    }
    cout<<"Six:"<<x*x-y<<endl;
    cout << "Seven:" << pr[10001] << endl;

    string line,fin;
    ifstream myfile ("data/8.txt");
    while ( getline (myfile,line,'\n') )
    {
      fin += line;
    }
    myfile.close();
    long long int ans = 0;
    for(int i=0;i<fin.length()-13;i++){
        long long int check = 1;
        for(int j=i;j<i+13;j++){
            check *= fin[j] - '0';
        }
        if(check>ans){
            ans = check;
        }
    }
    cout << "Eight:" << ans << endl;
    int n = 1000;
    int p = 0;
    for (int a = n / 3 - 1;a>2;a--){
        int b = n * (n - 2 * a) / (2 * (n - a));
        int c = n - a - b;
        if (a < b and a * a + b * b == c * c){
            p = a * b * c;
            break;
        }
    }
    cout << "Nine:" << p << endl;
    long int l_ans = 0;
    int check = 0;
    while(pr[check]<2000000){
        l_ans += pr[check];
        check++;
    }

    cout << "Ten:" << l_ans << endl;


}

void eleven_fifteen(){

  ifstream fin("data/11.txt");
  int grid[20][20];
  for (int r = 0; r < 20; r++){
      for (int c = 0; c < 20; c++){
			fin >> grid[r][c];
      }
  }

    int greatest = 0;
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 20; c++) {
			if (r < 16 && multiply(r,c,1,0,grid) > greatest)
				greatest = multiply(r,c,1,0,grid);
			if (c < 16 && multiply(r,c,0,1,grid) > greatest)
				greatest = multiply(r,c,0,1,grid);
			if (r < 16 && c < 16 && multiply(r,c,1,1,grid) > greatest)
				greatest = multiply(r,c,1,1,grid);
			if (r >= 3 && c < 16 && multiply(r,c,-1,1,grid) > greatest)
				greatest = multiply(r,c,-1,1,grid);
		}
	}

	cout << "Eleven: " << greatest << endl;

    int ans;
	for(int n = 1, tri = 1;; n++, tri += n){
        if(divisors_numb(tri)>500){
            ans = tri;
            break;
        }
	}
    cout<<"Twelve:" << ans << endl;
    ifstream fil("data/13.txt");
	string num[100];
	string an = "0";

	for (int n = 0; n < 100; n++){
		getline(fil, num[n],'\n');
        an = findSum(an,num[n]);
	}
    cout<<"Thirteen:"<<an.substr(0,10)<<endl;

const int number = 1000000;
int sequenceLength = 0;
int startingNumber = 0;
long sequence;

int *cache = new int[number + 1];
for (int i = 0; i < number; i++) {
    cache[i] = -1;
}
cache[1] = 1;

for (int i = 2; i <= number; i++) {
    sequence = i;
    int k = 0;
    while (sequence != 1 && sequence >= i) {
        k++;
        if ((sequence % 2) == 0) {
            sequence = sequence / 2;
        } else {
            sequence = sequence * 3 + 1;
        }
    }
    cache[i] = k + cache[sequence];

    if (cache[i] > sequenceLength) {
        sequenceLength = cache[i];
        startingNumber = i;
    }
}
   cout << "Fourteen:"<< startingNumber << endl;
   const int sizes = 20;
   long int grids[sizes+1][sizes+1];

   for (int i = 0; i < sizes; i++) {
       grids[i][sizes] = 1; grids[sizes][i] = 1;
   }

    for (int i = sizes - 1; i >= 0; i--) {
      for (int j = sizes - 1; j >= 0; j--) {
        grids[i][j]= grids[i+1][j] + grids[i][j+1];
      }
    }
    cout << "Fifteen:" << grids[0][0] << endl;
}

void sixteen_twenty(){

  auto pows = power(2,1000);
  int ans = 0;
  for(int i=0;i<pows.size();i++){
    ans += pows[i];
  }
 cout << "Sixteen:" << ans << endl;
 ans = 0;
 for(int i=1;i<=1000;i++){
    ans += Split(nameForNumber(i),' ').length();
 }
 cout << "Seventeen:" << ans << endl;
 ifstream fin("data/18.txt");
 int N = 15;
 ans = 0;
 int prev[N] = {}, cur[N];
	fin >> cur[0];
	for (int n = 2; n <= N; n++) {
		memmove(prev, cur, sizeof(cur));
		for (int m = 0; m < n; m++) {
			fin >> cur[m];
			if (m == 0)
				cur[m] += prev[m];
			else if (m == n - 1)
				cur[m] += prev[m-1];
			else
				cur[m] += max(prev[m],prev[m-1]);
            if (cur[m] > ans){ans=cur[m];}

		}
	}
  cout << "Eighteen:" << ans << endl;
}

void _21_25(){

   int ans = 0;
   for(int i=10;i<10000;i++){
      int a = sumOfFactors(i);
      int b = sumOfFactors(a);
      if(i==b && i!=a){
        ans += i;
      }
   }
   cout << "Twenty_one:" << ans << endl;

    vector<string> names;
	ifstream fin("data/names.txt");
	string name;
    while(getline(fin, name, ','))
    {
        names.push_back(name);
    }

   sort(names.begin(),names.end());
   long int sum = 0;
   for(int i=0;i<names.size();i++){
      int res=0;
      for(int j=0;j<names[i].length();j++){
         if(names[i][j]!='"'){
           res += int(char(names[i][j])) - 64;
         }
      }

      sum += (i+1)*res;
   }
   cout << "Twenty_two:" << sum << endl;
   const int limit = 28124;
   vector<int>abundent;
    for (int i = 2; i <= limit; i++) {
        if(allPr[i] && sumOfFactors(i)>i){
            abundent.push_back(i);
        }
     }
    bool canbe[limit + 1] = {false};
    for (int i = 0; i < abundent.size(); i++) {
    for (int j = i; j < abundent.size(); j++) {
        if (abundent[i] + abundent[j] <= limit) {
            canbe[abundent[i] + abundent[j]] = true;
        } else {
            break;
        }
    }
    }

    long int ans2= 0;
    for (int i = 1; i <= limit; i++) {
    if (!canbe[i]) {
        ans2 += i;
        }
     }
     cout << "Twenty_three:" << ans2 << endl;
     string s = {"0123456789"};
     perm(s,1000000);
     cout << "Twenty_four:" << s << endl;
     string x = "0" , y = "1";
     ans = 0;
     while(x.length()<1000){
        string z = x;
        x = y;
        y = findSum(x,z);
        ans++;
     }
     cout << "Twenty_five:" << ans << endl;
}

void _26_30()
{
    int sequenceLength = 0;
    for (int i = 1000; i > 1; i--) {
         if (sequenceLength >= i) {
             break;
           }
    int foundRemainders[i] = {0};
    int value = 1;
    int position = 0;

    while (foundRemainders[value] == 0 && value != 0) {
        foundRemainders[value] = position;
        value *= 10;
        value %= i;
        position++;
    }

    if (position - foundRemainders[value] > sequenceLength) {
        sequenceLength = position - foundRemainders[value];
    }
   }
   cout << "Twenty_six:" << sequenceLength+1 << endl;
   int ans = 0 ,counts = 0;
   for(int i = -1000;i <= 1000; i++){
    for(int j = -1000;j <=1000; j++){
        int check = 0;
        while(ipr[abs(check*check+(check*i)+j)]){
            check++;
        }
        if(check>counts){
            counts = check;
            ans = i*j;
        }
    }
   }

   cout << "Twenty_seven:" << ans << endl;
   long int ans_28 = 1;
   for(int i=3;i<=1001;i+=2){
    ans_28 += 4 * i * i - 6 * (i - 1);
   }
   cout << "Twenty_eight:" << ans_28 << endl;
   int F = 100;
   int overlap[6+1] = {0};
   bool used[6*F+1] = {0};
	for (int pow = 1; pow < 6+1; pow++) {
		for (int b = 2*pow; b <= F*pow; b += pow) {
			if (used[b]) overlap[pow]++;
			used[b] = 1;
		}
	}
	int sum = 0;
	for (int a = 2; a <= F; a++)
		sum += F - 1 - overlap[powOf(a)];
	cout << "Twenty_nine:" << sum << endl;
	sum = 0;
	for(int i=100;i<333333;i++){
        int j = i  , f = 0;
        while(j>=1){
            f += int(pow(j%10,5));
            j /= 10;
        }
        if(i==f){sum+=i;}
	}
	cout << "Thirty:" << sum << endl;
}

void _31_35()
{
    int price = 200+1;
    int coins[8] = {1,2,5,10,20,50,100,200};
    int ways[price] = {0};
    ways[0] = 1;
    for (int i=0;i<sizeof(coins)/4;i++){
        for (int j=coins[i];j<price;j++){
            ways[j] += ways[j-coins[i]];
        }
    }
    cout<< "Thirty_one:" << ways[200] << endl;

	set<int> s;
	for (int n = 2; n < 100; n++) {
		bool used[10] = {1};
		if (!setDigits(used, n)) continue;
		int start = 1000;
		if (n > 9) start = 100;
		bool used2[10];
		for (int m = start; m * n < 10000; m++) {
			memcpy(used2, used, 10);
			if (setDigits(used2, m) && setDigits(used2, m*n))
				s.insert(m*n);
		}
	}
	int sum = 0;
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
		sum += *iter;
	cout << "THirty_two:" << sum << "\n";
	int numer = 1;
    int denom = 1;
    for (int d = 10;d<100;d++){
        for (int n = 10;n<d;n++){
            int n0 = n % 10;
            int n1 = n / 10;
            int d0 = d % 10;
            int d1 = d / 10;
            if (n1 == d0 and n0 * d == n * d1 || n0 == d1 && n1 * d == n * d0){
                numer *= n;
                denom *= d;
            }
        }
    }
    cout << "Thirty_three:" << denom / gcd(numer, denom) << endl;

    sum = 0;
    for (int i =10;i<333333;i++){
       int check = 0;
       int j = i;
       while(j>=1){
        check += factorial(j%10);
        j /= 10;
       }
       if(check==i){
        sum += i;
       }

    }
    cout << "Thirty_four:" << sum << endl;
    sum = 4;
    for(int i = 10;i<1000000;i++){
       if(ipr[i]){
        bool ch = true;
        int j = i;
          for(int k=0;k<base(i);k++){
            j = j%10 * base(i) + j/10;
            if(!ipr[j]){
                ch = false;
                break;
            }
          }
          if(ch){
            sum += 1;
          }

       }

    }

    cout << "Thirty_five:" << sum << endl;
}

void _36_40()
{
  long int ans = 0;
  for(long long int i=0;i<1000000;i++){
    if(i==reverse_int(i) && bin(i)==reverseStr(bin(i)))
        ans += i;

  }

  cout << "Thirty_six:" << ans << endl;
  ans = 0;
  int counts=0;
  int num = 10;
  while(counts<11){
    if(ipr[num]){
    long int i = num , j = num;
    bool check = true;
    while(i>=9 ){
        i /= 10;
        j = reverse_int(reverse_int(j)/10);
        if(!ipr[i] || !ipr[j]){
            check = false;
        }
      }

       if(check==true){
        ans += num;
        counts++;
      }

   }
    num++;
  }
  cout << "Thirty_seven:" << ans << endl;

  string solution;
	for (int num = 9999; solution.size() == 0; num--) {
		int used = 1;
		string concat;
		for (int n = 1; concat.size() < 9; n++) {
			concat.append(to_string((long long)num*n));
			for (int tempNum = num*n; tempNum > 0; tempNum /= 10) {
				if (1 << (tempNum % 10) & used)
					goto out;
				else
					used += 1 << (tempNum % 10);
			}
		}
		if (used == (1 << 10) - 1)
			solution = concat;
		out:;
	}
   cout << "Thirty_eight:"<< solution << "\n";
   ans = 0;
   counts = 0;
   for(int i=10;i<1000;i++){

      int result = 0;
	  for (int a=1;a<=i;a++){
		for (int b=a;b<=i-a;b++){
			int c = i - a - b;
			if (a * a + b * b == c * c){
				result++;
			}
		}

		if(result>counts){
            ans = i;
            counts=result;
		}
	  }
   }

   cout << "Thirty_nine:" << ans << endl;
   int len = 1000000;
   string champer = "";
   for(int i=1;i<len;i++){
    champer += to_string(i);
   }

   ans = 1;
   for (int i=0;i<7;i++){

        ans *= champer[(int)pow(10,i) - 1] - '0';
   }
   cout << "Fourty:" << ans << endl;

}

void _41_45()
{
    long int i;
	for (i = 7654321; i >= 0; i--){
		if (pandigital(i) && ipr[i]) {
			cout << "Fourty_one:" << i << endl;
            break;
		}
	}

	vector<string> names;
	ifstream fin("data/words.txt");
	string name;
    while(getline(fin, name, ','))
    {
        names.push_back(name);
    }

    long int sum = 0;
    for(int i=0;i<names.size();i++){
      int res=0;
      for(int j=0;j<names[i].length();j++){
         if(names[i][j]!='"'){
           res += int(char(names[i][j])) - 64;
         }
      }

      if((sqrt(8*res+1) - 1) / 2 == int((sqrt(8*res+1) - 1) / 2)){
        sum ++;
      }
    }
    cout << "Fourty_two:" << sum << endl;
    long long nsum = 0;
    void move(int depth, int cur, int used, long long full,long long &nsum);
    for (int n = 0; n < 100; n++) {
		if (n/10 == n%10) continue;
		move(2, n*10, (1<<n/10) + (1<<n%10), n,nsum);
	}
	cout <<"Fourty_three:" << nsum << endl;
    int N = 5000;
    int pent[N];
	for (int n = 0; n < N; n++) {
		pent[n] = (n+1) * (3*(n+1)-1) / 2;
	}
	int lowestD = (1<<31)-1;
	for (int d = 1; d < N && pent[d]-pent[0] < lowestD; d++) {
		for (int m = 0; m+d < N && pent[m+d]-pent[m] < lowestD; m++) {
			if (isPent(pent[m+d]-pent[m]) && isPent(pent[m+d]+pent[m])) {
				lowestD = pent[m+d]-pent[m];
			}
		}
	}
	cout <<"Fourty_four:" << lowestD << endl;
	for (long long h = 144;; h++) {
		long long hex = h * (2*h - 1);
		double pentID = (sqrt(24*hex + 1.) + 1) / 6;
		if (pentID == (int)pentID) {
			cout << "Thirty_five:" << hex << endl;
			break;
		}
	}

}

void _46_50()
{
  int result = 33;
  bool check = true;

while(check){
    result += 2;

    int j = 0;
    check = false;
    while (result >= pr[j]) {
        if(isTwiceSquare(result-pr[j])){
            check = true;
            break;
        }
        j++;
    }
}

  cout << "Fourty_six:" << result << endl;

  long long last10 = 0;
	for (int i = 1; i <= 1000; i++) {
		long long tempLast10 = 1;
		for (int j = 1; j <= i; j++)
			tempLast10 = (tempLast10 * i) % 10000000000LL;
		last10 = (tempLast10 + last10) % 10000000000LL;
	}

int targetpf = 4;
int targetConsec = 4;
int consec = 1;
int res = 210;

while (consec < targetConsec) {
    res++;
    if (NumberOfPrimeFacors(res) >= targetpf) {
        consec++;
    } else {
        consec = 0;
    }
}

cout << "Fourty_seven:" << res-3 << endl;
cout << "Fourty_eight:" << last10 << endl;
int n =1487 , f = 1;
 while(true){
        n += 3 - f;
        f = -f;
        int b = n + 3330;
        int c = n + 6660;
        if (ipr[n] && ipr[b] && ipr[c] && sortuniqString(n)==sortuniqString(b) && sortuniqString(b)==sortuniqString(c)){
                cout <<  "Fourty_nine:" << to_string(n) + to_string(b) + to_string(c) << endl;
                break;
        }
 }
getPrimes();
vector<long long> runSum(primes.size(), 0);
	int maxRun = 0;
	for (int p = 1; p < primes.size(); p++) {
		runSum[p] = runSum[p-1] + primes[p-1];
		if (maxRun == 0 && runSum[p] > P)
			maxRun = p-1;
	}
	bool stop = false;
	for (int r = maxRun; r > 0; r--) {
		for (int l = 0;; l++) {
			long long next = runSum[l+r]-runSum[l];
			if (next > P) break;
			if (next % 2 && !sieve[(next-1)/2]) {
				cout <<"Fifty_"<<next << "\n";
				stop = true;
				break;
			}
		}
		if(stop==true){break;}
	}

}

void _51_55(){

    primes.reserve(P/6);
	getPrimes();
	for (int n = 4; n < primes.size(); n++) {
		int size = 0;
		for (int tempP = primes[n] / 10; tempP > 0; tempP /= 10) size++;
		for (int combi = 1; combi < (1 << size); combi++) {
			if (getMax(combi, primes[n]) == 8) {
				cout << "Fifty_one:" << primes[n] << "\n";
				n = primes.size()-1;
                break;
			}
		}
	}

  int num = 10;
  while(true){
       if (sortuniqString(2*num) == sortuniqString(3*num) && sortuniqString(3*num) == sortuniqString(4*num)  && sortuniqString(4*num) == sortuniqString(5*num)){
        cout << "Fifty_two:" << num << endl;
        break;
       }

    num++;

  }

  int combs = 0;
	for (int n = 23; n <= 100; n++) {
		for (int r = 2, num = n; r <= n/2; r++) {
			num = num*(n+1-r)/r;
			if (num > limit_m) {
				combs += n+1-2*r;
				break;
			}
		}
	}

  cout << "Fifty_three:" << combs << endl;

  ifstream fin("data/poker.txt");
  int wins = 0;
  string hand1[5], hand2[5];
	for (int h = 0; h < 1000; h++) {
		for (int c = 0; c < 5; c++) {
			fin >> hand1[c];
			hand1[c][0] = cVal(hand1[c][0]);
		}
		for (int c = 0; c < 5; c++) {
			fin >> hand2[c];
			hand2[c][0] = cVal(hand2[c][0]);
		}
		sort(hand1, hand1+5);
		sort(hand2, hand2+5);
		if (hVal(hand1) > hVal(hand2)) wins++;
	}

  int answ = 0;
  for(int i = 10;i<10000;i++){
     bool check = false;
     long long n = i;
     for(int j = 0;j<50;j++){
        n = n + reverse_int(n);
        if(n==reverse_int(n)){
            check = true;
            break;
        }
     }

     if(check==false){answ++;}
  }
  cout << "Fifty_four:" << wins <<  endl;
  cout << "Fifty_five:" << answ << endl;
}

void _56_60(){
  int ans = 0 , m = 0;
  for(int i=2;i<100;i++){
     for(int j=2;j<100;j++){
        string pows = Bigpow(i,j);
        int check = 0;
        for(int k=0;k<pows.length();k++){
            check += pows[k] - '0';
        }
        if(check>m){
            m=check;
            ans=check;
        }
     }

  }
  cout << "Fifty_six: "<< ans << endl;

  int noOfPrimes = 3;
  int line = 2;
  int c = 9;

  while( ((float)noOfPrimes)/(2*line+1) > 0.10){
    line += 2;
    for(int i = 0; i < 3; i++){
        c += line;
        if(isPrime(c)) noOfPrimes++;
    }
    c+= line;
  }

  cout << "Fifty_eight:"<< line + 1 << endl;
}

int main()
{

    one_five();
    six_ten();
    eleven_fifteen();
    sixteen_twenty();
    _21_25();
    _26_30();
    _31_35();
    _36_40();
    _41_45();
    _46_50();
    _51_55();
    _56_60();




}
