class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;
        // store {position, speed}
        for(int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        // sort according to position
        sort(cars.begin(), cars.end());

        stack<double> st;

        // process from right to left
        for(int i = n - 1; i >= 0; i--) {

            double time =
                (double)(target - cars[i].first)
                / cars[i].second;

            // new fleet
            if(st.empty() || time > st.top()) {
                st.push(time);
            }

            // else merges with fleet ahead
        }

        return st.size();
    }
};