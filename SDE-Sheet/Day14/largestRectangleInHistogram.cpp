// Solution using 2 passes.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int leftSmall[n], rightSmall[n];
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) leftSmall[i] = 0;
            else leftSmall[i] = s.top() + 1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) rightSmall[i] = n-1;
            else rightSmall[i] = s.top() - 1;
            s.push(i);
        }
        int maxArea = 0; 
        for(int i = 0; i < n; i++) {
            maxArea = maxArea(maxArea, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
        }
        return maxArea;
    }
};

