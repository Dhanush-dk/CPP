//This problem is same as N meetings in one room
class Solution
{
    public:
    struct activity{
        int start;
        int end;
        int pos;
    };
    static bool comparator(struct activity m1, activity m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        else return false;
    }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        activity act[n];
        
        for(int i = 0; i < n; i++){
            act[i].start = start[i];
            act[i].end = end[i];
            act[i].pos = i+1;
        }
        sort(act, act+n, comparator);
        vector<int> v;
        int limit = act[0].end;
        v.push_back(act[0].pos);
        int count = 1;
        for(int i = 1; i < n; i++){
            if(act[i].start > limit){
                limit = act[i].end;
                v.push_back(act[i].pos);
                count++;
            }
        }
        return count;
    }
};