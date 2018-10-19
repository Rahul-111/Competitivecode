#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int main()
{
    string s="453";

    int y=atoi(s.c_str());
    cout<<y%10;
}
