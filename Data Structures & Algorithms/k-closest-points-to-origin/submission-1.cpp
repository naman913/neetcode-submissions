class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int t) {
        // Use default max-heap to pop the largest distances when size > t
        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto& k : points) {
            int dist = k[0] * k[0] + k[1] * k[1];
            pq.push({dist, {k[0], k[1]}});
            
            if (pq.size() > t)
                pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto pt = pq.top().second;
            ans.push_back({pt.first, pt.second});
            pq.pop();
        }

        return ans;
    }
};