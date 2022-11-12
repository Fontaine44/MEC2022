from Battleship import GRID_SIZE, HitStatus


class Bot:
    __last_turn_status = HitStatus.NONE
    __my_hit_list = [[False for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]

    def do_turn(self, hit_grid, last_turn_status) -> (str, int):
        self.__last_turn_status = last_turn_status

        print_hit_board(hit_grid)
        print(self.__last_turn_status)

        # TODO Do something clever

        # TODO Must return a tuple (colLetter, rowNumber)
        return 'a', 0


def print_hit_board(hit_grid):
    board_str = '#  ' + ''.join([f"{letter}  " for letter in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[:GRID_SIZE]]) + '#\n'

    for row_index, row in enumerate(hit_grid):
        board_str += f"{row_index}  "
        for col_index, tile in enumerate(row):
            board_str += hit_grid[row_index][col_index].value
            board_str += "  "
        board_str += '#\n'

    board_str += "#  " + '#  ' * GRID_SIZE + '#\n'
    print(board_str)
