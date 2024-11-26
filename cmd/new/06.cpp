/*
Build a lexical analyzer implementing the following regular expressions:
Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary Number = 0(0|1)(0|1)*
Invalid Input or Undefined = Otherwise
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("input.txt","r",stdin);
   string s;
   cin>>s;
   bool isvalid = true;
   if(s.size()>=4&&(s.substr(0,3)=="ch_"||s.substr(0,3)=="bn_")&&(isalnum(s[3]))){
    for(int i=4;i<s.size();i++){
        if(!isalnum(s[i])){
            isvalid = false;
            break;
        }
    }
    if(isvalid){
        if(s.substr(0,3)=="ch_")cout<<"Character Variable"<<endl;
        else cout<<"Binary Variable"<<endl;
        return 0;
    }
   }
   else if(s[0]=='0'&&(s[1]=='0'||s[1]=='1')){
    for(int i=2;i<s.size();i++){
        if(s[i]!='0'||s[i]!='1'){
            isvalid=false;
            break;
        }
    }
   }
   else{
    isvalid=false;
   }

if(isvalid){
    cout<<"Binary Number"<<endl;
}
else cout<<"Invalid"<<endl;

}
