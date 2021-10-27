#include<bits/stdc++.h>
using namespace std;
void nextSmallerElement(vector<int> v, vector<int>&ans){
    stack<int> s;
    s.push(0);
    for(int i = 1; i < v.size(); i++){
        while(!s.empty() && v[s.top()] >= v[i]){
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    for(auto i : ans){
        cout<< i << " ";
    }
}
int main(){
    vector<int> v{4,2,3,7,1,5};
    vector<int> ans(v.size(), -1);
    nextSmallerElement(v, ans);
    return 0;
}