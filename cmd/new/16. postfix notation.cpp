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

void infix_to_postfix(string infix){

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
    cout<<postfix<<endl;

}
int main()
{
        freopen("16.input.txt","r",stdin);

         string infix;
         getline(cin, infix);
         infix_to_postfix(infix);
}
