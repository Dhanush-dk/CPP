// InterviewBit solution

int countSmallerThanMid(vector<int> &row, int mid){
    int l = 0, h = row.size()-1;
    while(l <= h){
        int m = (l + h)/2;
        if(row[m] <= mid) l = m+1;
        else h = m-1;
    }
    return l;
}
int Solution::findMedian(vector<vector<int> > &A) {
    
    int low = 1;
    int high = 1e9;
    int r = A.size();
    int c = A[0].size();

    while(low <= high){
        int mid = (low + high)/2;
        int count = 0;
        for(int i = 0; i < r; i++){
            count += countSmallerThanMid(A[i],mid);
        }
        if(count <= (r*c)/2 ) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
