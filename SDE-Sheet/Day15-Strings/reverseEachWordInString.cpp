#include <iostream>
using namespace std;
int main()
{
    string s = "This is a simple program to reverse each word in a string.";
    int i = 0;
    int n = s.size();
    while(i < n){
        while(i < n && s[i] == ' ') i++;
        if(i >= n) break;
        int j = i+1;
        while(j < n && s[j] != ' ') j++;
        int temp = j;
        j--;
        while(i < j)
            swap(s[i++], s[j--]);
        i = temp;
    }
    cout << s;
    return 0;
}

Output:
sihT si a elpmis margorp ot esrever hcae drow ni a .gnirts
