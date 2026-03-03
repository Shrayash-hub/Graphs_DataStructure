class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points,
                            vector<vector<int>>& q) {
        int j = 0;
        vector<int> ans(q.size());

        for (auto que : q) {
            int x1 = que[0];
            int y1 = que[1];
            int r1 = que[2];
            int count = 0;
            for(int i=0;i<points.size();i++){
                auto temp = points[i];
                int x2 = temp[0];
                int y2 = temp[1];
                int x = x2-x1;
                int y = y2-y1;

                if(x*x+y*y<=r1*r1){
                    count++;
                }
            }
            ans[j++]=count;
        }
        return ans;
    }
};