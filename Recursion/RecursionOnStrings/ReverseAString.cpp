
#include <bits/stdc++.h>
using namespace std;

//Reverse a string using recursion(using start index)
// void revStr(string str,int start)
// {
//     if(start==str.size())
//     {
//         return ;
//     }
    
   
//     revStr(str,start+1);
//     cout<<str[start];
// }





//Reverse a string using recursion(using last index)
// void revStr(string str,int last)
// {
//     if(last<0)return ;
    
//     if(last==0)
//     {
//         cout<<str[0];
//         return ;
//     }
    
//     cout<<str[last];
//     revStr(str,last-1);
// }

//Reverse a string using recursion(using swap)
// void revStr(string &str,int start,int end)
// {
//     if(start>=end)
//     {
//      return ;   
//     }
    
//     swap(str[start],str[end]);
//     revStr(str,start+1,end-1);
// }




int main() {
    // Write C++ code here
    string str = "vaibhav";
   int n = str.size();
   
   revStr(str,0,n-1);
   cout<<str;

    return 0;
}
    
    
    
    
    
    
    
    
   
