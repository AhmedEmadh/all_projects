# Imports
import tkinter
import requests
from datetime import datetime

# Define global variables
prayerTimes = ""
labelText = "Today's prayer times for Cairo, Egypt:"
# Replace with your own values
now = datetime.now()
year = now.year
month = now.month
day = now.day - 1
city = "Cairo"  # Example city name
country = "Egypt"  # Example country name

# Construct the API endpoint URL
url = f"http://api.aladhan.com/v1/calendarByCity/{year}/{month}?city={city}&country={country}"


try:
    # Try to get requests
    res = requests.get(url)
    response = res.json()
    FajrTime = response['data'][day]['timings']['Fajr'].split()[0]
    DhuhrTime = response['data'][day]['timings']['Dhuhr'].split()[0]
    AsrTime = response['data'][day]['timings']['Asr'].split()[0]
    MaghribTime = response['data'][day]['timings']['Maghrib'].split()[0]
    IshaTime = response['data'][day]['timings']['Isha'].split()[0]

    # Split Hours from minutes
    FormatedFajrTime = FajrTime.split(":")
    FormatedDhuhrTime = DhuhrTime.split(":")
    FormatedAsrTime = AsrTime.split(":")
    FormatedMaghribTime = MaghribTime.split(":")
    FormatedIshaTime = IshaTime.split(":")

    # get hours as int from split
    HoursFajrTime = int(FormatedFajrTime[0])
    HoursDhuhrTime = int(FormatedDhuhrTime[0])
    HoursAsrTime = int(FormatedAsrTime[0])
    HoursMaghribTime = int(FormatedMaghribTime[0])
    HoursIshaTime = int(FormatedIshaTime[0])

    # define isPM booleans
    isPMFajr = False
    isPMDhuhr = False
    isPMAsr = False
    isPMMaghrib = False
    isPMIsha = False

    # Set Booleans
    if HoursFajrTime >= 12:
        isPMFajr = True
    if HoursDhuhrTime >= 12:
        isPMDhuhr = True
    if HoursAsrTime >= 12:
        isPMAsr = True
    if HoursMaghribTime >= 12:
        isPMMaghrib = True
    if HoursIshaTime >= 12:
        isPMIsha = True

    # Adjust hours
    if HoursFajrTime > 12:
        HoursFajrTime -= 12
    if HoursDhuhrTime > 12:
        HoursDhuhrTime -= 12
    if HoursAsrTime > 12:
        HoursAsrTime -= 12
    if HoursMaghribTime > 12:
        HoursMaghribTime -= 12
    if HoursIshaTime > 12:
        HoursIshaTime -= 12

    # Format The date
    FajrTime = str(HoursFajrTime) + ":" + FormatedFajrTime[1]
    DhuhrTime = str(HoursDhuhrTime) + ":" + FormatedDhuhrTime[1]
    AsrTime = str(HoursAsrTime) + ":" + FormatedAsrTime[1]
    MaghribTime = str(HoursMaghribTime) + ":" + FormatedMaghribTime[1]
    IshaTime = str(HoursIshaTime) + ":" + FormatedIshaTime[1]

    # Append AM/PM
    if isPMFajr:
        FajrTime += " PM"
    else:
        FajrTime += " AM"

    if isPMDhuhr:
        DhuhrTime += " PM"
    else:
        DhuhrTime += " AM"

    if isPMAsr:
        AsrTime += " PM"
    else:
        AsrTime += " AM"

    if isPMMaghrib:
        MaghribTime += " PM"
    else:
        MaghribTime += " AM"

    if isPMIsha:
        IshaTime += " PM"
    else:
        IshaTime += " AM"

    # Append times together
    prayerTimes += "Fajr: " + FajrTime + "\n"
    prayerTimes += "Dhuhr: " + DhuhrTime + "\n"
    prayerTimes += "Asr: " + AsrTime + "\n"
    prayerTimes += "Maghrib: " + MaghribTime + "\n"
    prayerTimes += "Isha: " + IshaTime + "\n"
except requests.exceptions.RequestException as e:
    # If request Failed
    prayerTimes = "Cannot Connect to the internet"
    labelText = ""


# Initialize Window
window = tkinter.Tk()
window.title("Prayer Times")
window.geometry("310x160+100+100")
window.resizable(False,False)

# Initialize Objects
label = tkinter.Label(window, text=labelText)
if not labelText == "":
    azanZones = tkinter.Label(window, text=prayerTimes,anchor="w",justify="left")
else:
    azanZones = tkinter.Label(window, text=prayerTimes, anchor="w", justify="left",fg="red")
mycopyright = tkinter.Label(window, text="This Application is programmed by Ahmed Emad")

# Positions and placing
label.place(x=0, y=0)
azanZones.place(x=0,y=30)
mycopyright.place(x=0,y=135)

#Start GUI
window.mainloop()
