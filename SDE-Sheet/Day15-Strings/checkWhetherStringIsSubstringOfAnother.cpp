#include <iostream>
using namespace std;
bool check(string s, string ss){
    int i = 0, j = 0;
    int count = 0;
    int len1 = s.size();
    int len2 = ss.size();
    while(i < len1 && j < len2){
        if(s[i] == ss[j]){
            count++;
            j++;
        }
        else{
            count = 0;
            j = 0;
        }
        if(count == len2) return true;
        i++;
    }
    return false;
}
int main() {
	string s;
	string ss;
	cin >> s >> ss;
	(check(s,ss)) ? cout << "Present\n" : cout << "Not present\n";
	return 0;
}
