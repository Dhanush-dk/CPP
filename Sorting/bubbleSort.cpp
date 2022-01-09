class Solution{
    public:
    void swap(int *n, int *m){
        int temp = *n;
        *n = *m;
        *m = temp;
    }
    int shouldPunish (int roll[], int marks[], int n, double avg)
    {
        int swaps = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-i-1; j++){
                if(roll[j] < roll[j+1]){
                    swap(&roll[j], &roll[j+1]);
                    swaps++;
                }
            }
        }
        double total = 0;
        for(int i = 0; i < n; i++){
            total += marks[i];
        }
        total -= double(swaps);
        total /= double(n);
        if(total > avg) return 1;
        else return 0;
    }
};


First Pass: 
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1. 
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4 
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2 
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
Second Pass: 
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ) 
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 ) 
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
Third Pass: 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
