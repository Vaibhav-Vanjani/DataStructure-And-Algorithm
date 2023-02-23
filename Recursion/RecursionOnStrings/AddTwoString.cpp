//Add 2 string taken as input 
//convert them into integer 
//add them 
//return sum

#include<bits/stdc++.h>
using namespace std;

// int helper(string a, string b)
// {
//   int t1 = stoi(a);
//   int t2 = stoi(b);

//   return t1+t2;
// }


//method 2


int pow(int ans ,int power)
{
  int temp = 1;
  for(int i=0;i<power;i++)
  {
    temp*=10;
  }
  return temp;

}

void helper(string a,int i, string b ,int j,int carry,int &ans,int n)
{
  if(i<0 and j<0 and carry == 0)
  return ;

  int tempA;
  if(i<0)tempA = 0;
  else tempA = (int)(a[i]-'0');
 
  int tempB;
  if(j<0)tempB = 0;
  else tempB = (int)(b[j]-'0');
  
  int sum = tempA + tempB + carry ; 

  carry = sum/10;
  ans += (sum%10)*pow(10,n);

   helper(a,i-1,b,j-1,carry,ans,n+1);
}



int main() {

int ans=0;
helper("34",1,"384",2,0,ans,0); 
cout<<ans;



  return 0;
}