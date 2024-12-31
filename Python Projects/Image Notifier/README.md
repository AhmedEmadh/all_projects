# Image Notifier

The **Image Notifier** is a Python application that monitors your screen for a specific image and notifies you when the image is found. It is ideal for scenarios like detecting pop-up messages or visual cues in applications or games.

## Table of Contents

1. [Features](#features)
2. [Requirements](#requirements)
3. [Screenshots](#screenshots)
4. [Usage](#usage)
5. [How It Works](#how-it-works)
6. [Example Use Cases](#example-use-cases)

## Features

- **Image Detection**: The app monitors the screen for a specific image (`image.png`).
- **Notifications**: Plays a sound when the image is detected.
- **Simple GUI**: Allows users to start and stop the monitoring with a simple interface.
- **Multi-threading**: Runs the image detection in the background to keep the GUI responsive.

## Requirements

Before running the app, make sure you have the following Python libraries installed:

- `pyautogui`: For screen image detection.
- `beepy` (optional): For sound notifications.
- `winsound`: For system beep notifications.
- `tkinter`: For creating the graphical user interface (GUI).

You can install the necessary libraries using `pip`:

```bash
pip install pyautogui beepy
```

## Screenshots

<img title="Screenshot 1" src="https://github.com/AhmedEmadh/all_projects/blob/master/Python%20Projects/Image%20Notifier/Screenshot-1.png" alt="Screenshot 1">
</br>
<img title="Screenshot 2" src="https://github.com/AhmedEmadh/all_projects/blob/master/Python%20Projects/Image%20Notifier/Screenshot-2.png" alt="Screenshot 2">
</br>
<img title="Screenshot 3" src="https://github.com/AhmedEmadh/all_projects/blob/master/Python%20Projects/Image%20Notifier/Screenshot-3.png" alt="Screenshot 3">

## Usage

1. Place the image you want to monitor as `image.png` in the same directory as this script, or modify the code to point to a different image path.
2. Run the script.
3. Use the **Turn ON** button to start monitoring for the image.
4. The app will beep and display a message when the image is detected on the screen.
5. Use the **Turn OFF** button to stop monitoring.

## How It Works

1. **Turn ON**: This will start the image detection. The program will check the screen for the specified image.
2. **Turn OFF**: This stops the image detection loop and prevents further notifications.
3. **Image Detection**: The app uses `pyautogui.locateOnScreen()` to find the specified image with a confidence level of 80%. If the image is found, a beep sound is played, and a message is displayed.

## Example Use Cases

- **Game Notifications**: Detect pop-up messages or UI changes in games.
- **Automated Monitoring**: Set the app to look for specific images on the screen and notify you when they appear.
- **Visual Alerts**: Use the app to monitor for important screen events, like updates, requests, or reminders.
