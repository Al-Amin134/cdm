/*
Build a lexical analyzer implementing the following regular expressions:
Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("input.txt","r",stdin);
   string s;
   cin>>s;
   int dotcount=0, dot_pos = -1;
   bool isvalid = true;
   if((tolower(s[0])>='a'&&tolower(s[0])<='h')||tolower(s[0])>='o'&&tolower(s[0])<='z'){
    for(int i=1;i<=s.size();i++){
        if(!isalnum(s[i])){
            isvalid=false;
            break;
        }
    }
    if(isvalid)cout<<"Float Variable"<<endl;
   }
   else if(isdigit(s[0])){
    for(int i=1;i<s.size();i++){
        if(s[i]=='.'){
            dot_pos=i;
            dotcount++;
        }
        else if(!isdigit(s[i])){
            isvalid=false;
            break;
        }
    }
    if(dotcount!=1)isvalid=false;


   }
   else isvalid = false;



  if(isvalid){
    int n = s.size()- dot_pos-1;
    if(n==2)cout<<"The number is Float"<<endl;
    else if(n>2)cout<<"The number is double"<<endl;
    else isvalid=false;
  }

  if(!isvalid)cout<<"The number is Invalid"<<endl;

}
