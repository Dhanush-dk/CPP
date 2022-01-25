GFG

Example 1:
Input:
s = "aabc"
Output: 1c1b2a
Explanation: aabc
Step1: a2b1c1
Step2: 1c1b2a
	

Example 2:
Input:
s = "aaaaa"
Output: 5a
Explanation: aaaaa
Step 1: a5
Step 2: 5a

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string encryptString(string s){
    // code here
        string ans = "";
        int i = 0;
        while(i < s.size()){
            unordered_map<char, int> map;
            char c = s[i];
            map[s[i]] = 1;
            i = i+1;
            while(s[i] == c){
                map[s[i]]++;
                i++;
            }
            for(auto k : map){
                string str = to_string(k.second);
                ans += k.first + str;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
	    string s;
		cin>>s;
		Solution ob;
		string ans = ob.encryptString(s);
		cout<<ans<<endl;
	}
}
  // } Driver Code Ends
