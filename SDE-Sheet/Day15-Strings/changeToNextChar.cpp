#include <iostream>
using namespace std;
int main()
{
    string s = "I love programming";
    
    for(int i = 0; i < s.size(); i++){
        int charVal = int(s[i]);
        if(charVal == 122) 
            s[i] = char(97);
        else if(charVal == 90)
            s[i] = char(65);
        else if(charVal >= 65 && charVal <= 90 || charVal >= 97 && charVal <= 122)
            s[i] = char(s[i] + 1);
    }
    cout<< s;
    return 0;
}

Output:
J mpwf qsphsbnnjoh

