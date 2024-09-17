import tkinter
import pyautogui
import os
from time import *
import threading
import beepy
import sys
import winsound
isTurnedOn = False
isNotifierStarted = False


def get_image_path(imageName):
    # Get the directory where the executable is located
    if getattr(sys, 'frozen', False):
        # If the application is frozen (i.e., converted to an .exe by PyInstaller)
        executable_dir = os.path.dirname(sys.executable)
    else:
        # If running in a normal Python environment
        executable_dir = os.path.dirname(os.path.abspath(__file__))

    # Image path in the same directory as the executable
    image_path = os.path.join(executable_dir, imageName)

    return image_path
def Notifier(imageName):
    global isNotifierStarted
    # Get the directory path
    dir_path = os.path.dirname(os.path.realpath(__file__))

    # Use os.path.join to handle the file path correctly

    image_path = get_image_path(imageName)
    print(image_path)
    # Start the loop
    while True:
        try:
            print(image_path)
            # Locate the image on the screen with a confidence level
            location = pyautogui.locateOnScreen(image_path, confidence=0.80)

            if location is not None:
                # Beep if the image is found
                if isTurnedOn:
                    stateLabel.config(text="Found the Image")
                    #beepy.beep(sound=1)
                    winsound.Beep(1000, 400)
            else:
                if isTurnedOn:
                    print("Image not found.")

            if not isTurnedOn:
                break
        except OSError as oe:
            print("File Not found")
            stateLabel.config(text="No Image named image.png found",fg="red")
            break
        except pyautogui.ImageNotFoundException as e:
            if isTurnedOn:
                print(f"An error occurred: {e}")
                print(type(e))
                stateLabel.config(text="Cannot find the image")
        # Pause for a second before the next iteration
        sleep(0.1)

    isNotifierStarted = False


def turnOn():
    global isTurnedOn
    global stateLabel
    isTurnedOn = True
    stateLabel.config(text="Turned ON", fg="green")
    try:
        # Start autoClick in a new thread
        global isNotifierStarted
        if not isNotifierStarted:
            isNotifierStarted = True
            imageName = "image.png"
            threading.Thread(target=Notifier, args=(imageName,), daemon=True).start()
    except:
        stateLabel.config(text="Please Enter numbers",fg="red")

def turnOff():
    global isTurnedOn
    isTurnedOn = False
    stateLabel.config(text="Turned OFF", fg="red")

# Window
window = tkinter.Tk()
window.title("Image notifier")
window.geometry("410x130+100+100")
window.resizable(False,False)

# Objects


turnOnButton = tkinter.Button(window, text="Turn ON", command=turnOn)
turnOffButton = tkinter.Button(window, text="Turn OFF", command=turnOff)
stateLabel = tkinter.Label(window, text="Turned OFF", fg="red")
mycopyright = tkinter.Label(window, text="This Application is programmed by Ahmed Emad")

# Positions and placing
turnOnButton.place(x=50, y=50)
turnOffButton.place(x=200, y=50)
stateLabel.place(x=125, y=20)
mycopyright.place(x=0,y=100)
window.mainloop()
