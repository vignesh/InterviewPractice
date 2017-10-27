class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    islands+=1
                    #Ru
                    self.DFS(grid, i, j) 
        return islands
    
    def DFS(self, grid, x, y):
        #check if coordinate is valid and is land
        if ((x < 0) or (x >= len(grid)) or (y < 0) or (y >= len(grid[0])) or (grid[x][y] != '1')):
            return
        #mark as visited
        grid[x][y] = "X"
        #perform DFS on neighbors
        self.DFS(grid, x+1, y)
        self.DFS(grid, x-1, y)
        self.DFS(grid, x, y+1)
        self.DFS(grid, x, y-1)
        