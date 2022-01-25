-- Remove characters from the first string which are present in the second string.

Input:
string1 = "computer"
string2 = "cat"
	
Output: "ompuer"

Explanation: After removing characters(c, a, t) from string1 we get "ompuer".


// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        int n = string1.size();
        int m = string2.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(string1[i] == string2[j]){
                    string1.erase(string1.begin()+i);
                    i--;
                }
            }
        }
        return string1;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
