

from Battleship import BattleshipBoard, HitStatus
from Bot import Bot


class Game:
    __bot: Bot
    __board: BattleshipBoard
    __last_turn_status = HitStatus.NONE

    def __init__(self):
        self.__bot = Bot()
        self.__board = BattleshipBoard()

    def start_game(self):
        turns = 0
        while not self.__board.has_won() and turns < 90:
            self.__run_next_turn()
            turns += 1

        if self.__board.has_won():
            print(f"Victory in {turns} turns!")
        else:
            print(f"Welp... That took a while... (Killed after {turns} turns)")

        return turns

    def __run_next_turn(self):
        move_tile = self.__bot.do_turn(
            self.__board.hit_grid, self.__last_turn_status)
        self.__last_turn_status = self.__board.do_move(move_tile)
