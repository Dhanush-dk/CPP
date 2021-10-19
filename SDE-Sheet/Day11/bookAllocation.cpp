bool isPossible(int totalPages, vector<int>&A, int B){
    int allocatedStudents = 0, pages = 0;
    for(int i = 0; i < A.size(); i++){
        if(pages + A[i] > totalPages){
            allocatedStudents++;
            pages = A[i];
            if(pages > totalPages) return false;
        }
        else{
            pages += A[i];
        }
    }
    if(allocatedStudents < B) return true;
    return false;
}
int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1; 
    int low = A[0]; 
    int high = 0;
    for(int i = 0;i<A.size();i++) {
        high = high + A[i]; 
        low = min(low, A[i]); 
    }
    int res = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(isPossible(mid, A, B)){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}
