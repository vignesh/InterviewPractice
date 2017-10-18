class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        sudokuMap = set()
        for i in xrange(0,9):
            for j in xrange(0,9):
                if board[i][j]!='.':
                    #make sure cur is a string so does not get mixed up with indexes
                    cur = str(board[i][j])
                    if (i,cur) in sudokuMap or (cur,j) in sudokuMap or (i/3,j/3,cur) in sudokuMap:
                        return False
                    sudokuMap.add((i,cur))
                    sudokuMap.add((cur,j))
                    sudokuMap.add((i/3,j/3,cur))
        return True
        