Write a C++ program to find the largest word in a given string.
  
Example:
Sample Input: C++ is a general-purpose programming language.
Sample Output: programming

#include <iostream>
using namespace std;
int main()
{
    string s = "C++ is a general-purpose programming language";
    string ans = "";
    
    int i = 0, j = 0;
    
    while(i < s.size()){
        j = i;
        while(s[j] != ' ' && j < s.size() && ((int(s[j]) >= 65 && int(s[j]) <= 90) || (int(s[j]) >= 97 && int(s[j]) <= 122))){
            j++;
        }
        string temp = s.substr(i, j-i);
        if(temp.size() > ans.size()){
            ans = temp;
        }
        i = j + 1;
        while(s[i] == ' ' && i < s.size()) i++;
    }
    
    cout << ans;
    return 0;
}
