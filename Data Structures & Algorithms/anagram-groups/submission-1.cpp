class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {    
        unordered_map<string,vector<string>>str;
        for(string st:strs){
            string k=st;
            sort(k.begin(),k.end());
            str[k].push_back(st);
        }
        vector<vector<string>>ans;
        for(auto i:str){
            ans.push_back(i.second);
        }
        return ans;
    }
};
