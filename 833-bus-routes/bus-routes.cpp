class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        // base case
        if(source == target) return 0;    
                               
        int n = routes.size();
        int m = routes[0].size();
        // firstly we are going to map , stops -> buses , us stop se kitni buses
        // nikalti h
        map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                int stop = routes[i][j]; 
                mpp[stop].push_back(i); // stop k kon kon si buses a rhi h vo push kr denge
            }
        }
        queue<int> q;
        unordered_set<int> visited;
        // source bus stop pe kon kon se buses a rhi h , vo queue me push kr denge
        vector<int> start = mpp[source];
        for (int i = 0; i < start.size(); i++) {
            q.push(start[i]);
            visited.insert(start[i]);
        }
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            // bar bari har bus ko process krenge
            while (size--) {
                int temp = q.front();
                q.pop();
                // bari bari sari buses ko process krenge
                for (int j = 0; j < routes[temp].size(); j++) {
                    int stop = routes[temp][j]; // vo bus kon kon se stop pr jati h
                    // agr vo bus target stop tak jati h toh return krdo current level
                    if (stop == target) {
                        return level;
                    }
                    // else baki buses nikal lo us stop se , queue me push krdo and visited mark krdo
                    vector<int> next = mpp[stop];
                    for (auto it : next) {
                        if (visited.find(it) == visited.end()) {
                            q.push(it);
                            visited.insert(it);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};