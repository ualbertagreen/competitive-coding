class Solution {
public:
    bool findTopSort(vector<vector<int>> & adjList, int cur, vector<int> & visited, vector<int> & output) {
        if (visited[cur] == 1) return true;
        if (visited[cur] == 2) return false;
        visited[cur] = 1;
        
        for (int a : adjList[cur]) {
            if (findTopSort(adjList, a, visited, output)) return true;
        }
        
        output.push_back(cur);
        visited[cur] = 2;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        
        for (vector<int> e : prerequisites) {
            adjList[e[1]].push_back(e[0]);
        }
        
        vector<int> output;
        vector<int> visited(numCourses);
        for (int i = 0; i < adjList.size(); i++) {
            if (findTopSort(adjList, i, visited, output)) {
               return vector<int>(0);
            }
        }
        
        reverse(output.begin(), output.end());
        return output;
        
    }
};