class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mapi;
        for(int i=0;i<nums.size();i++)
        {
            if(mapi[nums[i]]!=0)
            return true;
            mapi[nums[i]]++;
        }
        return false;

    }
};
