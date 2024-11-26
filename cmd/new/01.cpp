/*
Write a C program that read the following string:
“Md. Tareq Zaman, Part-3, 2011”
a) Count number of words, letters, digits and other characters.
b) Separates letters, digits and others characters.
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    string input;
    int letter=0, word=1,digit=0,character=0;
    string letters="", words="",digits="",characters="";
    getline(cin,input);
    for(char c:input){
        if(c==' '){
            word++;
            words+=c;
        }
        else if(tolower(c)>='a'&&tolower(c)<='z'){
            letter++;
            letters+=c;
        }

        else if(c>='0'&&c<='9'){
            digit++;
            digits+=c;
        }
        else{
            character++;
            characters+=c;   // here character means other special characters
        }
    }

    cout<<"Ans a: "<<endl;
    cout<<"Number of words : "<<word<<endl;
    cout<<"Number of letters : "<<letter<<endl;
    cout<<"Number of digits : "<<digit<<endl;
    cout<<"Number of characters : "<<character<<endl;

    cout<<"\nThe letters are: "<<letters<<endl;
    cout<<"The digits are: "<<digits<<endl;
    cout<<"The characters are: "<<characters<<endl;
}
