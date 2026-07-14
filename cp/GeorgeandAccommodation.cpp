#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{  int n;cin>>n;int c=0;
   while(n--){
       int a,b;cin>>a>>b;
       if(b>a)c++;
   }cout<<c<<endl;
    return 0;
}