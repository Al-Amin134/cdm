/*
Build a lexical analyzer implementing the following regular expressions:
Integer variable = (i-nI-N)(a-zA-Z0-9)*
ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9)
LongInt Number = (1-9)(0-9)(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("input.txt","r",stdin);
   string s;
   cin>>s;

   int cnt=1;
   bool isvalid = true;
   if(tolower(s[0])>='i'&&tolower(s[0])<='n'){
    for(int i=1;i<s.size();i++){
        if(!isalnum(s[i])){
            isvalid = false;
            break;
        }
    }
    if(isvalid)
    cout<<"Integer Variable"<<endl;
   }
   else if(s[0]>='1'&&s[0]<='9'){
    for(int i=1;i<s.size();i++){
        if(!isdigit(s[i])){
            isvalid=false;
            break;
        }
        else cnt++;
    }
      if(isvalid){
    if(cnt<=4)cout<<"Short Integer Number"<<endl;
    else cout<<"Long Integer Number"<<endl;
    }
   }
   else{
    isvalid = false;
   }

if(!isvalid){
    cout<<"Invalid Input"<<endl;
}
}
