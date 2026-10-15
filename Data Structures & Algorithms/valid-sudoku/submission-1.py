class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(len(board)):
            vis = [0]*10
            for j in range(len(board)):
                if board[i][j] == '.':
                    continue
                if vis[int(board[i][j])] == 1:
                    return False
                vis[int(board[i][j])] = 1
        
                
        for i in range(9):
            vis = [0]*10
            for j in range(9):
                if board[j][i] == '.':
                    continue
                if vis[int(board[j][i])] == 1:
                    return False
                vis[int(board[j][i])] = 1
        for i in range(0,9,3):
            for j in range(0,9,3):
                vis = [0]*10
                for k in range(i,i+3):
                    for l in range(j,j+3):
                        if board[k][l] == '.' :
                            continue
                        if vis[int(board[k][l])] == 1:
                            return False
                        vis[int(board[k][l])] = 1
        return True
