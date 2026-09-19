class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n+1,0);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        ans[1]=nums[0];
        ans[2]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            ans[i+1]=max(ans[i],nums[i]+ans[i-1]);
        }
        return ans[n];
    }
};
