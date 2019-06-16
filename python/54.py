# stdlib
from time import time
from collections import Counter


def preprocess_hand(line):
    line = line.replace("T", "10").replace("J", "11").replace("Q", "12").replace("K", "13").replace("A", "14")
    cards = [(int(card[:-1]), card[-1]) for card in line.split()]
    return cards[:5], cards[5:]

#################
# Hand Rankings #
#################


def get_rank(cards):
    sorted_values = sorted([x[0] for x in cards])
    counter = Counter([x[0] for x in cards])
    if len(set([x[1] for x in cards])) == 1 and not {"10", "11", "12", "13", "14"} - set([x[0] for x in cards]):
        # royal flush
        return 10, sorted_values[-1], sorted_values
    elif len(set([x[1] for x in cards])) == 1 and sorted_values == list(range(sorted_values[0], sorted_values[-1] + 1)):
        # straight_flush
        return 9, sorted_values[-1], sorted_values
    elif counter.most_common(1)[0][1] == 4:
        # four of a kind
        return 8, counter.most_common(1)[0][0], sorted_values
    elif counter.most_common(1)[0][1] == 3 and any([x[1] == 2 for x in counter.most_common(2)]):
        # full house
        return 7, counter.most_common(1)[0][0], sorted_values
    elif len(set([x[1] for x in cards])) == 1:
        # flush
        return 6, sorted_values[-1], sorted_values
    elif sorted_values == list(range(sorted_values[0], sorted_values[-1] + 1)):
        # straight
        return 5, sorted_values[-1], sorted_values
    elif counter.most_common(1)[0][1] == 3:
        # three of a kind
        return 4, counter.most_common(1)[0][0], sorted_values
    elif all([x[1] == 2 for x in counter.most_common(2)]):
        # two pairs
        return 3, max([x[0] for x in counter.most_common(2)]), sorted_values
    elif any([x[1] == 2 for x in counter.most_common(2)]):
        # one pair
        return 2, counter.most_common(1)[0][0], sorted_values
    else:
        # high card
        return 1, max([x[0] for x in cards]), sorted_values

###################
# ranking players #
###################


def is_player_1_winning(game):
    player1, player2 = game
    rank1, max_rank1, sorted_values1 = get_rank(player1)
    rank2, max_rank2, sorted_values2 = get_rank(player2)
    if rank1 != rank2:
        return rank1 > rank2
    elif max_rank1 != max_rank2:
        return max_rank1 > max_rank2
    for i in range(5):
        if sorted_values1[-1 - i] != sorted_values2[-1 - i]:
            return sorted_values1[-1 - i] > sorted_values2[-1 - i]
    return True


if __name__ == "__main__":
    since = time()
    games = [preprocess_hand(l.strip()) for l in open("p054_poker.txt").readlines()]

    count = sum([is_player_1_winning(game) for game in games])
    print(f"Player 1 won {count} times!")
    print(f"Took {round(time() - since, 2)} s")
