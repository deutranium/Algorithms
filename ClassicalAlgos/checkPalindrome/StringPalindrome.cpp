//to check if a string is palindrome or not

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    char ch;
    string str;
    for (int i = 0; i < s.length(); i++)
    {
        ch = s.at(i);
        if(ch != ' ')
        str = ch+str;       
    }
    if(str == s)
    cout<<"Palindrome"<<endl;
    else
    cout<<"Not Palindrome"<<endl;
    return 0;
}