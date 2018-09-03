
class NumIsLands {
    private void dfs(int m, int n, char[][] grid){
        if( m<0 || n<0 || m>=grid.length || n>=grid[0].length || grid[m][n] == '0'){
            return;
        }
        grid[m][n] = '0';
        dfs(m-1, n, grid);
        dfs(m+1, n, grid);
        dfs(m, n-1, grid);
        dfs(m, n+1, grid);
        return;
    }

    public int numIslands(char[][] grid) {
        if(grid.length == 0 || grid[0].length == 0)
            return 0;
        int m = grid.length;
        int n = grid[0].length;
        int counter = 0;        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    counter++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return counter;
    }
}