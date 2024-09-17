import tkinter
import pyautogui
from time import *
import threading

isTurnedOn = False
isClickerStarted = False

def autoClick(ClickDelayHours, ClickDelayMin, ClickDelaySec):
    totalClickDelayInSeconds = (ClickDelaySec + ClickDelayMin * 60 + ClickDelayHours * 60 * 60)
    delayedSeconds = 0
    oldx, oldy = pyautogui.position()
    global isTurnedOn
    while isTurnedOn:
        while delayedSeconds < totalClickDelayInSeconds:
            sleep(1)
            newx, newy = pyautogui.position()
            if (newx, newy) == (oldx, oldy):
                delayedSeconds += 1
            else:
                oldx = newx
                oldy = newy
                delayedSeconds = 0
            if not isTurnedOn:
                break
        if not isTurnedOn:
            break
        pyautogui.click()
        delayedSeconds = 0
    global isClickerStarted
    isClickerStarted = False


def turnOn():
    global isTurnedOn
    global stateLabel
    isTurnedOn = True
    stateLabel.config(text="Turned ON", fg="green")
    try:
        hours = int(hoursIn.get("1.0", "end-1c"))
        mins = int(minIn.get("1.0", "end-1c"))
        secs = int(secIn.get("1.0", "end-1c"))
        temp = 1/(hours + mins + secs)
        # Start autoClick in a new thread
        global isClickerStarted
        if not isClickerStarted:
            isClickerStarted = True
            threading.Thread(target=autoClick, args=(hours, mins, secs), daemon=True).start()
    except:
        stateLabel.config(text="Please Enter numbers",fg="red")

def turnOff():
    global isTurnedOn
    isTurnedOn = False
    stateLabel.config(text="Turned OFF", fg="red")

# Window
window = tkinter.Tk()
window.title("Auto Clicker")
window.geometry("450x230+100+100")
window.resizable(False,False)

# Objects
label = tkinter.Label(window, text="Auto click every: ")
hoursIn = tkinter.Text(window, width=3, height=1)
minIn = tkinter.Text(window, width=3, height=1,)
secIn = tkinter.Text(window, width=3, height=1)
dot1 = tkinter.Label(window, text=":")
dot2 = tkinter.Label(window, text=":")
turnOnButton = tkinter.Button(window, text="Turn ON", command=turnOn)
turnOffButton = tkinter.Button(window, text="Turn OFF", command=turnOff)
stateLabel = tkinter.Label(window, text="Turned OFF", fg="red")
noteLabel = tkinter.Label(window, text="Note: it starts counting if no mouse movment happenes")
mycopyright = tkinter.Label(window, text="This Application is programmed by Ahmed Emad")

# Positions and placing
label.place(x=10, y=10)
hoursIn.place(x=150, y=11)
minIn.place(x=200, y=11)
secIn.place(x=250, y=11)
dot1.place(x=185, y=10)
dot2.place(x=235, y=10)
noteLabel.place(x=0,y=70)
turnOnButton.place(x=50, y=150)
turnOffButton.place(x=200, y=150)
stateLabel.place(x=125, y=120)
mycopyright.place(x=0,y=200)
window.mainloop()
