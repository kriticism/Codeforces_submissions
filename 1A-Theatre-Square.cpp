#include <iostream>
#include <math.h>
using namespace std;

int main(){
	long long int n, m, a;
	cin>>n>>m>>a;
	long long int k = (n + a - 1)/a;            // worst case rows estimate
	long long int j = (m + a - 1)/a;            // worst case cols estimate
	cout<< k * j;  
	return 0;
}
