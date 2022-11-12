import sys

from Game import Game

if __name__ == '__main__':
    number_of_game = 1
    if len(sys.argv) == 2:
        number_of_game = int(sys.argv[1])

    total_turn = 0
    for i in range(number_of_game):
        game = Game()
        total_turn += game.start_game()

    print(f"Average: {total_turn/number_of_game} turns!")

    # TODO Go ahead and implement Bot.py
