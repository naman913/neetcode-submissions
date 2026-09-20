class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mapi;
        for(string str:strs){
            string k=str;
            sort(k.begin(),k.end());
            mapi[k].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto k:mapi){
            ans.push_back(k.second);
        }
        return ans;
    }
};
