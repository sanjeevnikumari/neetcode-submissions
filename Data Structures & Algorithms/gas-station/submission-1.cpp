class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0;
        int totalcost=0;
        for(int i=0;i<gas.size();i++){
            totalgas+=gas[i];
        }
        for(int i=0;i<cost.size();i++){
            totalcost+=cost[i];
        }
        if(totalgas<totalcost) return -1;
        int result=0;
        int diff=0;
        for(int i=0;i<gas.size();i++){
            diff+=gas[i]-cost[i];
            if(diff<0){
                diff=0;
                result=i+1;
            }
        }
        return result;
    }
};
