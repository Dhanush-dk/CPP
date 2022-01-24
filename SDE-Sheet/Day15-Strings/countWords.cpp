Write a C++ program to count all the words in a given string.
Example:
Sample Input: Python
Sample Output: number of words -> 1

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = " Here is a program to find out the number of words in a sentence. ";
    int count = 0;
    string temp;
    int i = 0, j = 0;
    while(i < s.size()){
        while(i < s.size() && s[i] == ' ') i++;
        j = i;
        while(j < s.size() && s[j] != ' ') j++;
        temp = s.substr(i, j-i);
        if(temp.size() != 0) count++;
        i = j+1;
    }
    cout << count;
    return 0;
}
