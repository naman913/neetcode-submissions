class KthLargest {
public:
    int ans=0;

priority_queue<int, std::vector<int>, std::greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        ans=k;
        pq.empty();
        for(int i:nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>ans)
            pq.pop();
        return pq.top();
    }
};
