from itertools import permutations, combinations, combinations_with_replacement

class piece:
    def __init__(self,x,y,team):
        self.x, self.y = x,y
        self.team = team
        self.reachable = []
        self.possible_moves()
    def move(self,x,y):
        self.x, self.y = x,y
    def possible_moves(self):
        print("Problem")

class King(piece):
    def __init__(self,x,y, team):
        super().__init__(x,y, team)
    def possible_moves(self, board):
        # a king can move in all directions by 1 square
        self.reachable = []
        moves = [(-1,1), (0,1), (1,1),
                 (-1,0),        (1,0),
                 (-1,-1),(0,-1),(1,-1)]
        for move in moves:
            x,y=self.x+move[0],self.y+move[1]
            if x >= 0 and y >= 0 and x < n and y < n and board[x,y] == None:
                self.reachable.append((x,y))

if __name__ == '__main__':
    king = King(1,1, "black")
    board = [[None for i in range(5)] for j in range(5)]    
    print(king.possible_moves())