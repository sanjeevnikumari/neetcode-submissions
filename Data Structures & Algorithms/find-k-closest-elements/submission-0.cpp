class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int,int>> temp; 
        // {distance, value}
        
        for(int i = 0; i < arr.size(); i++) {
            temp.push_back({abs(arr[i] - x), arr[i]});
        }
        
        // sort by distance, then value
        sort(temp.begin(), temp.end());
        
        vector<int> ans;
        
        for(int i = 0; i < k; i++) {
            ans.push_back(temp[i].second);
        }
        
        // final result must be sorted
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};