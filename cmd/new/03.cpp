/*
Write a program that abbreviates the following code:
CSE-3141 as Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Theory.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("input.txt","r",stdin);
   string input;
   getline(cin,input);
   int i=0;
   string code="";
   string dept="";
   while(input[i]!='-'){
    dept+=input[i];
    i++;
   }

   code=input.substr(i+1);

   map<string,string>dpt;
   dpt["CSE"]="Computer Science and Engineering";
   dpt["ICE"]="Information and Communication Engineering";
   dpt["ACCE"]="Applied Chemistry and Chemical Engineering";
   dpt["EEE"]="Electrical and Electronic Engineering";

   map<char,string>year;
   year['1']="1st year";
   year['2']="2nd year";
   year['3']="3rd year";
   year['4']="4th year";

   map<char, string> semester;
  semester['1']="1st semester";
   semester['2']="2nd semester";
   semester['3']="3rd semester";
   semester['4']="4th semester";

   map<char, string>course;
   course['1']="Software Engineering";
   course['2']="Database Management Systems";
   course['3']="Compiler Design";
   course['4']="Web Engineerng";

   map<char, string>part;
   part['1']="Theory";
   part['2']="Lab";



    cout<<input<<" : "<<dpt[dept]<<" "<<year[code[0]]<<" "<<semester[code[1]]<<" "<<course[code[2]]<<" "<<part[code[3]]<<endl;


}
