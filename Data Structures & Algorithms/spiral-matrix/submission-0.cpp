class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while(top <= bottom && left <= right) {
            
            // Step 1: left → right
            for(int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;
            
            // Step 2: top → bottom
            for(int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            // Step 3: right → left (check valid row)
            if(top <= bottom) {
                for(int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            
            // Step 4: bottom → top (check valid column)
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return ans;
    }
};