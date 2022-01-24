Write a C++ program to sort characters (numbers and punctuation symbols are not included) in a string.
Example:
Sample Input: python
Sample Output: hnopty

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "programming";
    sort(s.begin(), s.end());
    cout << s;
    return 0;
}
