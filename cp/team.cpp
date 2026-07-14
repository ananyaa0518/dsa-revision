#include <iostream>
#include<vector>
using namespace std;
int main()
{
   int t;cin>>t;
   vector<int>b;
   int sum=0,n=t;
   while(t--){
   int a[3];
   for(int i=0;i<3;i++)cin>>a[i];
   int count=0,s=0;
   for(int i=0;i<3;i++)s+=a[i];
   if(s>1)b.push_back(1);
   else b.push_back(0);
   }
   for(int i=0;i<n;i++)sum+=b[i];
   cout<<sum<<endl;
    return 0;
}