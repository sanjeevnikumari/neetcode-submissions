class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while(mid <= high) {
            
            // case 0
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            
            // case 1
            else if(nums[mid] == 1) {
                mid++;
            }
            
            // case 2
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};