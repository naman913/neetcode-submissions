class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mapi;
        for(int i:nums)
            mapi[i]++;
        
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;            
        for(auto i:mapi){
                        pq.push({i.second,i.first});

            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(pq.size()!=0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
