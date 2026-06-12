// 1-------------------------
#include <bits/stdc++.h>
using namespace std;

int main() {
   int x;
   cin>>x;
   if(x%5==0){
       cout<<"no";
   }else{
       cout<<"Yes";
   }
return 0;
}
// -------------------2
#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    string s;
    string k;
    cin>>s>>k;
    int t=min(n,m);
    string g="";
    for(int i=0;i<t;i++){
        if(s[i]==k[i]){
            g+=s[i];
        }else{
            break;
        }
    }
    cout<<g<<endl;
}
  return 0;
}
// ------------------------c
#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--){
       int n,m;
       cin>>n>>m;
       vector<int>v(n,0);
       while(m>0){
           for(int i=0;i<n;i++){
               if(m>0)v[i]+=m;
               m--;
           }
          for(int i=n-1;i>=0;i--){
              if(m>0)v[i]+=m;
              m--;
          }
       }
       int td=*max_element(v.begin(), v.end());
       cout<<td<<endl;
   }
return 0;
}
