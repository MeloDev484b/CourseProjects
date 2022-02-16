import random
from typing import Set
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

password = []

def GenerateLetter():
    randomLetter = random.randint(0, len(letters)-1)
    return letters[randomLetter]
def GenerateNumber():
    randomNumber = random.randint(0, len(numbers)-1)
    return numbers[randomNumber]
def GenerateSymbol():
    randomSymbol = random.randint(0, len(symbols)-1)
    return symbols[randomSymbol]
def AddLetters(limit):
    letter = int(input("How many letters would you like to use in your password?\n"))
    if letter > limit:
        letter = limit
    for letter in range(0, letter):
        if len(password) < limit:
            password.append(GenerateLetter())
def AddNumbers(limit):
    if len(password) < limit:
        number = int(input("How many numbers would you like to use in your password?\n"))
        for number in range(0, number):
            if len(password) < limit:
                password.append(GenerateNumber())
def AddSymbols(limit):
    if len(password) < limit:
        symbol = int(limit - len(password))
        for symbol in range(0, symbol):
            password.append(GenerateSymbol())
def GeneratePassword(limit):
    AddLetters(limit)
    AddNumbers(limit)
    AddSymbols(limit)

limit = int(input("How many characters would you like your password to contain?\n"))
GeneratePassword(limit)
random.shuffle(password)
passwordString = ''.join(password)
print(f"Your password is:\n\n{passwordString}\n")

input("Press enter to exit.\n")