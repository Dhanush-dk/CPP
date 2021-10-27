class MinStack {
    long long minVal;
    stack<long long> s;
public:
    MinStack() {
        while(!s.empty()) s.pop();
        minVal = INT_MAX;
    }
    
    void push(int value) {
        long long val = value;
        if(s.empty()){
            minVal = val;
            s.push(val);
        }
        else{
            if(val < minVal){
                s.push(2 * val * 1LL - minVal);
                minVal = val;
            }
            else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        long long n = s.top();
        s.pop();
        if(n < minVal){
            minVal = 2 * minVal - n;
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        long long n = s.top();
        if(n < minVal) return minVal;
        return n;
    }
    
    int getMin() {
        return minVal;
    }
};