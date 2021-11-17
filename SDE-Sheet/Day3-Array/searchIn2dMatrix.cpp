class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j = matrix[0].size()-1;
        int i = 0;
        if(matrix.size() == 0){
            return false;
        }
        while(i < matrix.size() && j >=0){
            if(matrix[i][j] == target)
                return true;
            else(matrix[i][j] > target) ? j-- : i++;
        }
        return false;
    }
};