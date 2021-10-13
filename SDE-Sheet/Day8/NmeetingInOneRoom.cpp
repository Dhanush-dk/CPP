class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting{
        int start;
        int end;
        int pos;
    };
    static bool comparator(struct meeting m1, meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        else return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        meeting meet[n];
        
        for(int i = 0; i < n; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i+1;
        }
        sort(meet, meet+n, comparator);
        vector<int> v;
        int limit = meet[0].end;
        v.push_back(meet[0].pos);
        int count = 1;
        for(int i = 1; i < n; i++){
            if(meet[i].start > limit){
                limit = meet[i].end;
                v.push_back(meet[i].pos);
                count++;
            }
        }
        return count;
    }
};