//InterviewBit

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    int n = A.size();
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        while(!s.empty() && A[i] <= s.top()) s.pop();
        if(s.empty()) ans[i] = -1;
        else{
            ans[i] = s.top();
        }
        s.push(A[i]);
    }
    return ans;
}

// Entire Code
#include<bits/stdc++.h>
using namespace std;
void prevSmallerElement(vector<int> v, vector<int> &ans){
    stack<int> s;
    int n = v.size();
    //vector<int> ans(n);
    for(int i = 0; i < n; i++){
        while(!s.empty() && v[i] <= v[s.top()]) s.pop();
        if(s.empty()) ans[i] = -1;
        else{
            ans[i] = v[s.top()];
        }
        s.push(i);
    }
    for(auto i : ans){
        cout<< i << " ";
    }
}
int main(){
    vector<int> v{10, 20, 30, 50, 10, 70, 30};
    vector<int> ans(v.size());
    prevSmallerElement(v, ans);
    return 0;
}