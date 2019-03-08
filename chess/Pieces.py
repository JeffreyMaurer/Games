class piece:
    def __init__(self,x,y):
        self.x, self.y = x,y
        self.reachable = []
    def move(self,x,y):
        self.x, self.y = x,y
    def possible_moves(self):
        print("Problem")

class King(piece):
    def __init__(self,x,y):
        super().__init__(x,y)
    def possible_moves(self):
        return(self.x)

if __name__ == '__main__':
    king = King(1,1)    
    print(king.possible_moves())