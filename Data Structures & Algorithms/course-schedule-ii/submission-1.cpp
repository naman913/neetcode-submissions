class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph: b -> a (must take b before a)
        for (const auto& req : prerequisites) {
            int course = req[0];
            int prereq = req[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        // Push all courses with 0 prerequisites into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int processedCourses = 0;
        vector<int>ans;

        // Process courses layer by layer
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            processedCourses++;
            ans.push_back(curr);

            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                // If all prerequisites for neighbor are met, add to queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If we processed all courses, there's no cycle
// If processed courses equal numCourses, return ans; otherwise a cycle exists
return processedCourses == numCourses ? ans : vector<int>();    }
};
