// C++ program to check for even or odd
// using Bitwise AND operator
#include <iostream>
using namespace std;


void swap_without_thirdVar(int &a,int &b)
{
	a =a^b;
	b =a^b;
	a= a^b;
  return;
}

// Driver code
int main()
{
	int a = 101;
	int b = 102;	

	swap_without_thirdVar(a,b);	

	cout<<a;
	cout<<b;

	return 0;
}
