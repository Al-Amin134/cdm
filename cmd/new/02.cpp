/*
Write a program that read the following string:
“Munmun is the student of Computer Science & Engineering”.
a) Count how many vowels and Consonants are there?
b) Find out which vowels and consonants are existed in the above string?
c) Divide the given string into two separate strings, where one string only contains
 the words started with vowel, and another contains the words started with consonant.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    string input;
    getline(cin, input);
    int v=0, c=0;
    set<char>vowel,consonant;

    for(char ch:input){
        char a = tolower(ch);
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
            v++;
            vowel.insert(a);
        }
        else if(a>='a'&&a<='z'){
            c++;
        consonant.insert(a);
    }
    }

        cout<<"Number of Vowels: "<<v<<endl;
        cout<<"Vowels are: ";
        for(char vw: vowel)cout<<vw<<" ";
            cout<<endl;
        cout<<"Number of Consonants: "<<c<<endl;

        cout<<"Consonants are :";
        for(char co:consonant)cout<<co<<" ";

}
