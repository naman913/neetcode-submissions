class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        return false;
        unordered_map<char,int>mapi;
        for(int i=0;i<s.length();i++)
        {
            mapi[s[i]]++;
            mapi[t[i]]--;
        }
        for(auto k :mapi)
        {
            if(k.second!=0)
            return false;
        }

        return true;
    }
};
