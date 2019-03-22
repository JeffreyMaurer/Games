import os
import sys

class Chess:
    """
    This will be the game manager
    """
    def __init__(self,n):
        self.n=n
        self.board = [[None for __ in range(n)] for _ in range(n)]
        self.current_player = "white"
        self.quit = False

    def run(self):
        while self.quit==False:
            self.input()
            self.logic()
            self.view()

    def input(self):
        input("Next move " + self.current_player)

    def logic(self):
        if self.current_player == "white":
            self.current_player = "black"
        else:
            self.current_player = "white"
        
    def view(self):
        for i in range(self.n):
            row = ["|" + (" " if self.board[i][j] is None else self.board[i][j]) for j in range(self.n)]
            print(str(i) + "".join(row) + "|")
        print(" ".join(range(self.n)))

if __name__ == '__main__':
    chess = Chess(5)
    chess.view()

