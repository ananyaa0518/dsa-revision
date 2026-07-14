#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{  string s;cin>>s;
   int c=0,c1=0;
   for(auto x: s){
       if(x>='a' && x<='z')c++;
       else c1++;
   }
   if(c1>c){
       for(int i=0;i<s.size();i++){
           if(s[i]>='a' && s[i]<='z')s[i]=char(int(s[i])-32);
       }
   }else{
       for(int i=0;i<s.size();i++){
           if(s[i]>='A' && s[i]<='Z')s[i]=char(int(s[i])+32);
       }
        } cout<<s<<endl;
    return 0;
}