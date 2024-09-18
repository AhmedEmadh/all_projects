
import time
import pyautogui
import random
import pyperclip
from pynput.keyboard import Controller as KeyboardController, Key
from pynput.mouse import Controller as MouseController, Button
keyboard = KeyboardController()
mouse = MouseController()
import ctypes
import subprocess
from ctypes import windll
# Configurations
generalDelay = 10 + random.uniform(0.1,3)
F4Delay = 0.2 + random.uniform(0.1,0.3)
typingDelay = 0.3 + random.uniform(0.1,0.3)
numberOfIterations = 35
FChar = 'F4'
PC = True
# functions
def read_file(file_path):
    try:
        with open(file_path, 'r') as file:
            content = file.read()
        return content
    except FileNotFoundError:
        return f"Error: The file '{file_path}' does not exist."
    except IOError:
        return "Error: An IOError occurred."


def contains_non_ascii(text):
    return any(ord(char) > 127 for char in text)


def type_char(c):
    pressing_delay = 0.08 + random.uniform(0.0,0.09)
    if PC == True:
        pyautogui.typewrite(c)
    else:
        keyboard.press(c)
        time.sleep(pressing_delay)
        keyboard.release(c)


def type_word(choice):
    for c in choice:
        type_char(c)
        time.sleep(0.1+random.uniform(0.0,0.1))


def typing():
    choice = random.choice(myList)
    if contains_non_ascii(choice):
        pyperclip.copy(choice)
        pyautogui.hotkey('ctrl','v')
    else:
        type_word(choice)


# code
#['zoro', 'luffy', 'mihawk', 'dracule Mihawk', 'Hankock', 'steve', 'alex', 'tomato', 'apple']
#['ميهوك', 'سمنة', 'زورو', 'نامي', 'سمنة', 'يسوب', 'سمنة', 'طبخ', 'تفاحة', 'برتقالة', 'عصير', 'عنب', 'خوخ', 'قصب', 'عناب', 'نامي روبين', 'نيكو روبين', 'جوي بوي جارب', 'مونكي دي زورو', 'رورونوا نامي', 'دراكول بروك', 'مونكي دي لاو', 'دراكول جارب', 'بوا لوفي', 'بوا زورو', 'دونكيهوتي ميهوك', 'دراكول جينبي', 'ناروتو', 'شانكس هاكي ملكي', 'شانكس هيبة', 'فول', 'عتس']
#initialize lists
englishList = read_file("english.txt").split(',')
# Open the file and read its contents
with open('arabic.txt', 'r', encoding='utf-8') as file:
    arabic_text = file.read()


# Open the file and read its contents
with open('arabic.txt', 'r', encoding='utf-8') as file:
    arabic_text = file.read()

# Convert the string to a list
arabic_list = [item.strip() for item in arabic_text.split(',')]

englishList = [w.strip() for w in englishList]
#arabicList = [w.strip() for w in arabicList]

myList = englishList
if PC == True:
    myList += arabic_list

def press():
    if PC == True:
        pyautogui.press(FChar)
    else:
        mouse.click(Button.left,1)
        time.sleep(0.05+random.uniform(0.0,0.1))
        mouse.click(Button.left,1)
        time.sleep(0.05 + random.uniform(0.0, 0.1))
        mouse.click(Button.left,1)
        time.sleep(0.05 + random.uniform(0.0, 0.1))

for i in range(numberOfIterations):
    time.sleep(generalDelay)
    press()
    time.sleep(F4Delay)
    typing()
    time.sleep(typingDelay)
    pyautogui.press('Enter')


