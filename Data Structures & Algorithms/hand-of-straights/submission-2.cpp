class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupsize) {
        int n=hand.size();
        if(n%groupsize!=0) return false;
        map<int ,int>mp;
        for(int x:hand){
            mp[x]++;
        }
        while(!mp.empty()){
            int curr=mp.begin()->first;
            for(int i=0;i<groupsize;i++){
                if(mp[curr+i]==0){
                    return false;
                }
                mp[curr+i]--;
                if(mp[curr+i]<1){
                    mp.erase(curr+i);
                }
            }
        }
        return true;
    }
};
