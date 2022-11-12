from Battleship import GRID_SIZE, HitStatus


class Bot:
    __last_turn_status = HitStatus.NONE
    __my_hit_list = [[False for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]
    __empty = []
    __will_hit_coord = 0
    __hits = []

    for i in 'abcdefghij':
        for j in range(10):
            __empty.append((i, j))



    def do_turn(self, hit_grid, last_turn_status) -> (str, int):
        self.__last_turn_status = last_turn_status

        print_hit_board(hit_grid)
        print(self.__last_turn_status)

        # TODO Do something clever
        if self.__last_turn_status == HitStatus.HIT:
            self.__hits.append(self.__will_hit_coord)

        probabilities = {}
        for i in 'abcdefghij':
            for j in range(10):
                probabilities[i, j] = 0

        for i in self.__empty:
            # check left
            if i[0] != 'a':
                letter_index = 'abcdefghij'.index(i[0])
                if ('abcdefghij'[letter_index - 1], i[1]) in self.__empty:
                    probabilities[i] += 0.1
                if ('abcdefghij'[letter_index - 1], i[1]) in self.__hits:
                    probabilities[i] += 1
            # check right
            if i[0] != 'j':
                letter_index = 'abcdefghij'.index(i[0])
                if ('abcdefghij'[letter_index + 1], i[1]) in self.__empty:
                    probabilities[i] += 0.1
                if ('abcdefghij'[letter_index + 1], i[1]) in self.__hits:
                    probabilities[i] += 1
            # check down
            if i[1] != 9:
                if (i[0], i[1] + 1) in self.__empty:
                    probabilities[i] += 0.1
                if (i[0], i[1] + 1) in self.__hits:
                    probabilities[i] += 1
            # check up
            if i[1] != 0:
                if (i[0], i[1] - 1) in self.__empty:
                    probabilities[i] += 0.1
                if (i[0], i[1] - 1) in self.__hits:
                    probabilities[i] += 1

        self.__will_hit_coord = max(probabilities, key=probabilities.get)
        if probabilities[max(probabilities,key=probabilities.get)] == 0:
            self.__will_hit_coord = ('e', 4)

        self.__empty.remove(self.__will_hit_coord)
        # TODO Must return a tuple (colLetter, rowNumber)
        return self.__will_hit_coord


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