class Solution {
public:
    int result = INT_MAX;
    void solve(vector<int>& cookies,vector<int> &child,int k,int index){
        if(index==cookies.size()){
            int maxi = *max_element(child.begin(),child.end());
            result = min(result,maxi);
            return;
        }
        for(int i=0;i<k;i++){
            child[i]+=cookies[index];
            solve(cookies,child,k,index+1);
            child[i]-=cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();

        vector<int> child(k);
        solve(cookies,child,k,0);
        return result;
    }
};