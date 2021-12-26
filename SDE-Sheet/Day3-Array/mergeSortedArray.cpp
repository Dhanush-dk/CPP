class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.empty()) {
            int i = 0;
            while(i < m+n){
                nums1[i] = nums2[i];
                i++;
            }
            return;
        }
        if(nums2.empty()) {
            int i = 0;
            while(i < m+n){
                nums1[i] = nums1[i];
                i++;
            }
            return;
        }
        int i = 0, j = 0;
        while(i < m){
            if(nums1[i] <= nums2[j]){
                nums1[i] = nums1[i];
            }
            else{
                swap(nums1[i],nums2[j]);
                sort(nums2.begin(),nums2.end());
            }
            i++;
        }
        for(int k = m, l = 0; k < m+n; k++, l++){
            nums1[k] = nums2[l];
        }
    }
};
