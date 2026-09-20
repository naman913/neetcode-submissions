class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto k:stones)
            pq.push(k);
        while(pq.size()>1){
            auto k = pq.top();
            pq.pop();
            auto k2=pq.top();
            pq.pop();
            pq.push(abs(k-k2));
        }
        return pq.size()==0? 0: pq.top();
    }
};
