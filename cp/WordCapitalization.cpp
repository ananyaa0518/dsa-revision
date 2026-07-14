#include <iostream>
using namespace std;
#include <string>
int main()
{
  string s;cin>>s;
  if(int(s[0])>=65 && int(s[0])<=90)cout<<s;
  else{
      s[0]=char(int(s[0])-32);cout<<s<<endl;
  } return 0;
}