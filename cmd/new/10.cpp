/*
Write a program to implement a shift reducing parsing.
*/

#include<bits/stdc++.h>
using namespace std;
void shift(string stk, string input){
    cout<<stk<<"\t\t\t"<<input<<"\t\t\t"<<"Shift"<<endl;
}

void reduce_to(string stk, string input, string left, string right){
    cout<<stk<<"\t\t\t"<<input<<"\t\t\t"<<left<<"->"<<right<<endl;
}
int main()
{

    freopen("input.txt","r",stdin);
    int n;
    string temp;
    cin>>n;
    string left[n],right[n];
    cin.ignore();

    for(int i=0;i<n;i++){
        getline(cin,temp);
        left[i].push_back(temp[0]);
        for(int j=3;j<temp.size();j++){
            right[i].push_back(temp[j]);
        }
    }

    cout<<"The grammar is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<left[i]<<" ->";
        cout<<right[i]<<endl;
    }

    string input="";
    string stk="";
    cin>>input;
    input+="$";
    stk.push_back('$');
cout<<"Stack"<<" \t\t\t"<<"Input"<<" \t\t\t"<<"Actions"<<endl;
    while(input!="$"){

        stk.push_back(input[0]);
        input.erase(input.begin());
        shift(stk,input);

        for(int i=0;i<n;i++){
            bool flag=false;
            if(stk.find(right[i])<stk.length()){
                stk.erase(stk.find(right[i]), stk.length());
                stk+=(left[i]);
                reduce_to(stk,input,left[i],right[i]);
                flag=true;
            }
            if(flag)i=-1;
        }
    }

    input+=left[0];
    if(input==stk)cout<<"Accepted"<<endl;
    else cout<<"Rejected"<<endl;

}
