class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_map<string, vector<string>> mpp; // ingredient -> recipes
        unordered_map<string, int> indegree; // recipe -> remaining ingredients

        // Build graph
        for (int i = 0; i < recipes.size(); i++) {
            for (auto& ing : ingredients[i]) {
                mpp[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;

        // Start with supplies
        for (auto& sup : supplies) {
            q.push(sup);
        }

        unordered_set<string> st; // stores what we can make

        while (!q.empty()) {
            string node = q.front();
            q.pop();

            st.insert(node);

            for (auto& nei : mpp[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        vector<string> done;
        for (auto& recipe : recipes) {
            if (st.count(recipe)) {
                done.push_back(recipe);
            }
        }

        return done;
    }
};