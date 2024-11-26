
#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    switch(ch)
    {
    case '^':
          return 3;


    case '*':
    case '/':
         return 2;


    case '+':
    case '-':
            return 1;


    default: return 0;


    }
}
string infix_to_postfix(string infix){

    string postfix="";
    stack<char>stk;

    for(char ch:infix){
        if(tolower(ch)>='a'&&tolower(ch)<='z'){
            postfix+=ch;
        }
        else if(ch=='(')
            stk.push(ch);
        else if(ch==')'){
            while(stk.top()!='('){
                postfix+=stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while(!stk.empty()&&precedence(ch)<=precedence(stk.top())){
            postfix+=stk.top();
            stk.pop();

        }
        stk.push(ch);
    }

    }
    while(!stk.empty()){
        postfix+=stk.top();
        stk.pop();
    }
    return postfix;

}

void solve(string infix){
    stack<string>stk;
    string temp;
    string postfix="";
    for(char ch:infix){
        if(ch!=' ')temp+=ch;
        else{
            if(temp=="then"){
                temp="";
                continue;
            }
            if(temp=="if"){
                stk.push(temp);
            }
            else if(temp=="else"){
                stk.push(temp);
            }
            else{
                postfix+=infix_to_postfix(temp);
                while(!stk.empty()&&stk.top()=="else"){
                    postfix+='?';
                    stk.pop();
                    stk.pop();
                }
            }
            temp="";
        }
    }
    cout<<postfix;
}
int main()
{

        freopen("17.input.txt","r",stdin);
         string infix;
         getline(cin, infix);
         solve(infix);
}
