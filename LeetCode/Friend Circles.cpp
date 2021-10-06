class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        
        queue<int> q;
        int count = 0;
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == 0) {
                count++;
                q.push(i);
            }
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (visited[cur] != 0) continue;
                visited[cur] = count;
                
                for (int j = 0; j < isConnected[cur].size(); j++) {
                    if (isConnected[cur][j] && visited[j] == 0) {
                        q.push(j);
                    } 
                }
            }
        }
        
        return count;
    }
};