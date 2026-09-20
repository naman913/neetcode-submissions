class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>seti;
        for(int i:nums){
            if(seti.find(i)==seti.end())
                seti.insert(i);
            else 
                return true;
        }
        return false;
    }
};