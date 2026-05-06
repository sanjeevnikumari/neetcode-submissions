class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int curr=1,maxlen=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
                curr=1;
            }
            else if((arr[i]>arr[i-1]&&arr[i-1]<arr[i-2])||
            (arr[i]<arr[i-1]&&arr[i-1]>arr[i-2])||i==1)  {
                curr++;
            }  
            else{
                curr=2;
            }  
            maxlen=max(maxlen,curr);
        }
        return maxlen;
    }
};