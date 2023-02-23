#include <iostream>
#include<vector>
using namespace std;

//method 1
// void printSubsequence(string str, int index , string ans)
// {

//   if(index==str.size())
//   {
//     cout<<ans<<endl;
//     return;
//   }

//   //take
//     printSubsequence(str,index+1,ans+str[index]);
//   //not take
//     printSubsequence(str,index+1,ans);
    
// }

// method 2
void printSubsequence(string str, int index , vector<char> ans)
{

  if(index==str.size())
  {
   for(int i=0;i<ans.size();i++)
   cout<<ans[i];

   cout<<endl;
    return;
  }

  //take
    ans.push_back(str[index]);
    printSubsequence(str,index+1,ans);
    ans.pop_back();
  //not take
    printSubsequence(str,index+1,ans);
    
}





int main() {
   vector<char> ans;
  printSubsequence("abc",0,ans);

  return 0;
}