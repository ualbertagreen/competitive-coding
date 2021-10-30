class Solution {
public:
    bool findLoop(vector<vector<int>> & adjList, int cur, vector<int> & visited) {
        if (visited[cur] == 1) return true;
        if (visited[cur] == 2) return false;
        visited[cur] = 1;
        
        for (int a : adjList[cur]) {
            if (findLoop(adjList, a, visited)) return true;
        }
        
        visited[cur] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        
        for (vector<int> e : prerequisites) {
            adjList[e[1]].push_back(e[0]);
        }
        
        vector<int> visited(numCourses);
        for (int i = 0; i < adjList.size(); i++) {
            if (findLoop(adjList, i, visited)) {
                return false;
            }
        }
        
        return true;
    }
};