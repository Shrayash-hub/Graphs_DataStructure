class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool> &visited){
        // mark current room as visited
        visited[room] = true;

        // jitni keys is room me hain
        for(int key : rooms[room]) {

            // agar wo room abhi tak visit nahi hua
            if(!visited[key]) {
                dfs(key, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);

        dfs(0,rooms,visited);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};