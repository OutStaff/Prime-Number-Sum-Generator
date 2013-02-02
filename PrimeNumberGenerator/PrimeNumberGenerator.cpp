// PrimeNumberGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <ctime>
using namespace std;

class PrimeGenerator
{
private:
	vector<unsigned long> primes;
public:
	PrimeGenerator(){}
	~PrimeGenerator(){}
public:
	vector<unsigned long> GeneratePrimes(unsigned long max, unsigned long long &sum ){
		char *sieve;
		sieve = new char[max/8+1];
		memset(sieve, 0xFF, (max/8+1) * sizeof(char));
		for(unsigned long x = 2; x <= max; x++)
			if(sieve[x/8] & (0x01 << (x % 8))){
				primes.push_back(x);
				sum+=x;
				for(unsigned long j = 2*x; j <= max; j += x)
				{
					sieve[j/8] &= ~(0x01 << (j % 8));
					
				}
				
			}
		delete[] sieve;
		return primes;
	}
	void Display()
	{
		vector<unsigned long>::iterator it;
		for(it=primes.begin(); it < primes.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
};
int main(void){
Label:
    vector<unsigned long> primes;
	clock_t start_time = clock();
	int num = 0;
	unsigned long max_number = 2000000;
	cout<<"Enter a number below to see the sum of all the prime numbers that are less than or equal to that number: ";
	//cout<<"Enter a number to sum of all prime numbers less than or equal to that: ";
	cin>> max_number;
	if(max_number<=0)
	{
		cout<<"Enter a valid max number"<<endl;
		return 1;
	}
	/*if(max_number>2000000)
	{
		cout<<"Number is greater than 2,000,000"<<endl;
		return 1;
	}*/

	unsigned long long sum = 0;
	PrimeGenerator generator;
    primes = generator.GeneratePrimes(max_number,sum);
    vector<unsigned long>::iterator it;
    /*for(it=primes.begin(); it < primes.end(); it++)
        cout << *it << " ";
    cout << endl;*/
	clock_t end_time =clock();
	cout<<"\nPrime numbers less than or equal to "<<max_number<<" generated in: "<< end_time-start_time<<" msec"<<endl;
	cout<<"\nThe sum of the generated numbers is: "<< sum<<endl;
	//cin>>num;
	cout<<endl<<endl;
	goto Label;
	return 0;
}
