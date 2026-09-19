class Solution {
public:
    void dfs(vector<vector<int>>&ans,vector<int>& nums,int target,vector<int>&d ,int index){
        if(target==0){
            ans.push_back(d);
            return;
        }
        if(index<0||target<0) return;
        if(target>=nums[index]){
            d.push_back(nums[index]);
            dfs(ans,nums,target-nums[index],d,index);
            d.pop_back();
        }
        dfs(ans,nums,target,d,index-1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp; 
        dfs(ans,nums,target,temp,nums.size()-1);
        return ans;
    }
};
