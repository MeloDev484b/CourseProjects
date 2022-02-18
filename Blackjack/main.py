import art
import random


def reset_game(hand1, hand2):
    hand1.clear()
    hand2.clear()
    print("The dealer shuffles and deals.")


def first_hand():
    deal(2, player_hand)
    deal(2, computer_hand)

    print("You are holding: ")
    print_hand(player_hand)
    print(f"The computer is showing {computer_hand[0]}.")


def deal(times, hand):
    for i in range(0, times):
        new_card = select_card()
        hand.append(new_card)


def select_card():
    card = random.randrange(0, 12)
    return cards_list[card]


def print_hand(hand):
    string = ", ".join(str(card) for card in hand)
    print(string)


def dealer():
    player_turn = True
    while player_turn:
        choice = input("Would you like to hit or stand?\nH/S")
        if choice == "H" or choice == "h":
            deal(1, player_hand)
            print_hand(player_hand)
            if bust(player_hand):
                print("BUST!")
                break
        elif bust(player_hand):
            print("BUST!")
        else:
            print("You choose to stand.")
            player_turn = False


def bust(hand):
    if calculate_hand(hand) > 21:
        return True


def calculate_hand(hand):
    hand_value = 0
    for i in hand:
        hand_value += cards[i]
    return hand_value


def check_for_win(hand1, hand2, turn_number):
    player = calculate_hand(hand1)
    cpu = calculate_hand(hand2)
    if player > 21:
        print("Computer wins!")
        return "Computer"
    elif cpu > 21:
        print("Player wins!")
        return "Player"
    elif player == cpu:
        print("Push! No winner.")
        return "None"
    elif turn_number == 2:
        if player > cpu:
            print("Player wins!")
            return "Player"
        else:
            print("Computer wins!")
            return "Computer"
    else:
        return ""


def computer_controller(hand):
    """Logic for the computer"""
    if not bust(player_hand):
        computer_turn = True
        while computer_turn:
            if calculate_hand(hand) <= 17:
                deal(1, hand)
                print("The computer hits.")
                print(hand[-1])
            elif bust(computer_hand):
                print("BUST!")
                computer_turn = False
            else:
                print("The computer stands.\nThe computer holds the following cards:")
                print_hand(computer_hand)
                computer_turn = False


def play_again():
    play = input("Would you like to play again?\nY/N")
    if play == "Y" or play == "y":
        return True
    else:
        return False


print(art.logo)

# Dictionary to hold the values of each card
cards = {
    "[A]": 1,
    "[2]": 2,
    "[3]": 3,
    "[4]": 4,
    "[5]": 5,
    "[6]": 6,
    "[7]": 7,
    "[8]": 8,
    "[9]": 9,
    "[10]": 10,
    "[J]": 10,
    "[Q]": 10,
    "[K]": 10,
}

# A list of keys to be used to access values held in the cards dictionary
cards_list = list(cards)

player_hand = []
computer_hand = []
playing = True
winner = ""
turn = 1

while playing:
    turn = 1
    reset_game(player_hand, computer_hand)
    first_hand()
    dealer()
    if not check_for_win(player_hand, computer_hand, turn):
        turn = 2
        computer_controller(computer_hand)
        check_for_win(player_hand, computer_hand, turn)
    playing = play_again()

# Path forward:
# 1. Show both hands when a winner is declared
# 2. Make the Ace card count as either 1 or 11, depending on the hand value.

