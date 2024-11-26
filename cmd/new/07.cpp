/*
Build a lexical analyzer implementing the following regular expressions:
Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary Number = 0(0|1)(0|1)*
Invalid Input or Undefined = Otherwise
*/

#include<bits/stdc++.h>
using namespace std;

vector<string>keywords{

    "int","float","double","long integer", "if", "else if", "else",
     "switch","case"," default","break","continue","for","while",
     "goto","do","do while","auto","struct","pointer", "stack", "set",
     "namespace", "main", "char", "string","cout", "cin","scanf",
     "printf"

};

vector<string>operators{

    "+","-","*","/","%",          //arithmetic operators
    "==","!=",">",">=","<","<=",  //relational operators
    "&&","||","!",                //logical operators
    "&","|","^","<<",">>","~","^",//bitwise operators
    "=","+=","-=","*=","/=","&=",
    "|=","!=","^=","~=","<<=",">>=",  //assignment operators
    "++","--"                       //increment decrement operators
};


int main()
{
   freopen("input.txt","r",stdin);
   string s;
   bool isvalid=true;
   getline(cin, s);
   if (find(keywords.begin(), keywords.end(), s) != keywords.end()){  //eta vector er khetre shudhu kaj kre tai array na niye vector nibo
                                                                       // ar array nile (find(begin(keywords), end(keywords), str) != end(keywords)) eta use krb
    cout<<"keywords"<<endl;
    return 0;
   }

   else if(find(operators.begin(),operators.end(),s)!=operators.end()){
    cout<<"operators"<<endl;
    return 0;
   }

   else if(s[0]=='_'||isalpha(s[0])){
    for(int i=1;i<s.size();i++){
        if(!isalnum(s[i])){
            isvalid = false;
            break;
        }
    }
    if(isvalid){
        cout<<"Identifire"<<endl;
        return 0;
    }
   }
   else if(s[0]=='"'&&s[s.size()-1]=='"'){
    cout<<"const"<<endl;
    return 0;
   }
   else if(isdigit(s[0])){

    int dot=0, dot_position=-1;
    for(int i=1;i<s.size();i++){
        if(s[i]=='.'){
            dot_position=i;
            dot++;
        }
        else if(isdigit(s[i])){
            continue;
        }
        else{
            isvalid=false;
            break;
        }
    }
    if(isvalid&&dot<2){
        cout<<"const"<<endl;
    }
    else{
        isvalid=false;
    }

   }
   else {
    isvalid = false;
   }

   if(!isvalid){
    cout<<"Invalid Input"<<endl;
   }



}
