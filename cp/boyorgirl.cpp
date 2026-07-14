#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;
int main()
{
   string s;cin>>s;
   int count=0;
   unordered_map<char,int>m;
   for(auto x:s)m[x]++;
   for(auto x:m)count++;
   (count%2==0)?cout<<"CHAT WITH HER!"<<endl:cout<<"IGNORE HIM!"<<endl;
}