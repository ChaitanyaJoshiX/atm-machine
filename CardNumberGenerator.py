# WAP to output a random 12 digit card number to a txt file
import random
import os


number = ""

for i in range(1,20):
    if i % 5 == 0: # Using a if statement to put space after 4 digits
        number += " "
    else:
        randnum = random.randint(0,9)
        number += str(randnum)

cardnumber = open("cardnumber.txt", "w") # Creating a file to write the generated number
cardnumber.write(number) # Writing the generated card number to the file
cardnumber.close()
