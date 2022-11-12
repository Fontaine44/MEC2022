import random
from enum import Enum, unique

GRID_SIZE = 10


def is_valid_grid_position(pos):
    return 0 <= pos[0] < GRID_SIZE and 0 <= pos[1] < GRID_SIZE


class PlacementOrientation(Enum):
    UP = (0, 1)
    RIGHT = (1, 0)
    DOWN = (0, -1)
    LEFT = (-1, 0)


@unique
class HitStatus(Enum):
    NONE = ' '
    MISS = 'm'
    HIT = 'h'
    SUNK = 's'
    TRIED_ALREADY = '?'


class Ship:
    length: int
    identifier: str
    _hit_count = 0

    def __init__(self, length, identifier):
        self.length = length
        self.identifier = identifier

    def positions(self, pos, ori):
        positions = [pos]
        delta_xy = ori.value

        for i in range(1, self.length):
            new_pos = (pos[0] + delta_xy[0] * i, pos[1] + delta_xy[1] * i)
            positions.append(new_pos)

        return positions

    def is_sunk(self):
        return self._hit_count is self.length


CARRIER_SHIP = Ship(5, 'c')
BATTLESHIP_SHIP = Ship(4, 'b')
DESTROYER_SHIP = Ship(3, 'd')
SUBMARINE_SHIP = Ship(3, 's')
PATROL_SHIP = Ship(2, 'p')
SHIPS = CARRIER_SHIP, BATTLESHIP_SHIP, DESTROYER_SHIP, SUBMARINE_SHIP, PATROL_SHIP


class BattleshipBoard:
    __ship_grid = []
    __ships = {}
    hit_grid = []

    def __init__(self):
        self.__ship_grid = [["" for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]
        self.hit_grid = [[HitStatus.NONE for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]

        for ship in SHIPS:
            self.__ships[ship.identifier] = ship

        self.__place_ships()

    def do_move(self, move_tile):
        col, row = move_tile
        col = ord(col.lower()) - ord('a')

        if not is_valid_grid_position((col, row)):
            raise ValueError(f"Invalid grid pos ({col},{row})")

        if self.hit_grid[row][col] is not HitStatus.NONE:
            return HitStatus.TRIED_ALREADY

        ship_id_at_pos = self.__ship_grid[row][col]

        if ship_id_at_pos is not "":
            ship_at_pos = self.__ships[ship_id_at_pos]
            ship_at_pos._hit_count += 1
            self.hit_grid[row][col] = HitStatus.SUNK if ship_at_pos.is_sunk() else HitStatus.HIT
        else:
            self.hit_grid[row][col] = HitStatus.MISS

        return self.hit_grid[row][col]

    def has_won(self):
        for ship in self.__ships.values():
            if not ship.is_sunk():
                return False

        return True

    def __place_ships(self):
        for ship in self.__ships.values():
            pos = (random.randrange(0, GRID_SIZE), random.randrange(0, GRID_SIZE))
            ori = random.choice(list(PlacementOrientation))

            while not self.__is_valid_ship_placement(ship, pos, ori):
                pos = (random.randrange(0, GRID_SIZE), random.randrange(0, GRID_SIZE))
                ori = random.choice(list(PlacementOrientation))

            ship_positions = ship.positions(pos, ori)

            for ship_position in ship_positions:
                self.__ship_grid[ship_position[0]][ship_position[1]] = ship.identifier

    def __is_valid_ship_placement(self, ship, pos, ori):
        pos_to_check = ship.positions(pos, ori)

        for p in pos_to_check:
            if not is_valid_grid_position(p):
                return False
            elif self.__ship_grid[p[0]][p[1]] is not "":
                return False

        return True
