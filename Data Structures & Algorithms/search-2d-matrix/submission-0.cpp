class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int end=matrix.size()-1;
        int t=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(matrix[mid][0]==target)
                return true;
            else if (matrix[mid][0]>target){
                end=mid-1;
            }else{
                t=mid;
                start=mid+1;
            }
        }
        start=0;
        end=matrix[0].size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(matrix[t][mid]==target)
                return true;
            else if(matrix[t][mid]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return false;
    }
};
