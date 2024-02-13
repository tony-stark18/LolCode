class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // use graph: [ai, bi], bi -> ai
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0); 
        vector<int> result;
        // [ai, bi], bi->ai: means how many other prerequisite course ai need?
        // if inDegree is 0, it don't have any prerequisites
        for (const auto& prerequisite: prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            // means prerequisite[1] -> prerequisite[0]
            inDegree[prerequisite[0]]++;
            // means prerequisite[0] is counted, prerequisite[0] has one more prerequisite is prerequisite[1]
        }

        // create the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            for (int neighbor: graph[curr])
            {
                if (--inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if (result.size() == numCourses)
        {
            return result;
        } else {
            return {};
        }
    }
}; 