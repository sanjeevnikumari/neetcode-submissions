class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        int perimeter = 0;

        for(int i = 0; i < row; i++) {

            for(int j = 0; j < col; j++) {

                // land mila
                if(grid[i][j] == 1) {

                    perimeter += 4;

                    // upper land
                    if(i > 0 && grid[i-1][j] == 1)
                        perimeter--;

                    // lower land
                    if(i < row-1 && grid[i+1][j] == 1)
                        perimeter--;

                    // left land
                    if(j > 0 && grid[i][j-1] == 1)
                        perimeter--;

                    // right land
                    if(j < col-1 && grid[i][j+1] == 1)
                        perimeter--;
                }
            }
        }

        return perimeter;
    }
};