# Auto Clicker Project

<p align="center">
    <img src="https://img.shields.io/github/license/ahmedemadh/all_projects" alt="License Badge">
    <img src="https://img.shields.io/badge/version-1.0-blue" alt="Version Badge">
    <img src="https://img.shields.io/badge/contributions-welcome-brightgreen" alt="Contributions Badge">
</p>

<p align="center"><strong>An automatic clicker program with adjustable time intervals, built with Python and Tkinter for GUI.</strong></p>

---

## Table of Contents

- [About the Project](#about-the-project)
- [Screenshots](#screenshots)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Installation](#installation)
- [Usage](#usage)

---

## About the Project

The Auto Clicker Project is a Python-based automation tool that simulates mouse clicks at regular intervals. It includes a simple GUI (Graphical User Interface) built with Tkinter, allowing users to easily set the delay between clicks in hours, minutes, and seconds.

Key Highlights:

- Allows users to set custom click intervals (hours, minutes, and seconds).
- Monitors mouse inactivity to trigger clicks.
- Turn the auto-clicker on and off with simple button clicks in the GUI.

---

## Screenshots

<p align="center">
    <img src="https://github.com/AhmedEmadh/all_projects/blob/master/Python%20Projects/Auto%20Clicker/Screenshot-1.png" alt="Project Screenshot" style="max-width: 100%;">
</p>
<p align="center">
    <img src="https://github.com/AhmedEmadh/all_projects/blob/master/Python%20Projects/Auto%20Clicker/Screenshot-2.png" alt="Project Screenshot" style="max-width: 100%;">
</p>

---

## Features

<ul>
    <li><strong>Adjustable Click Interval:</strong> Set custom intervals for automatic clicks in hours, minutes, and seconds.</li>
    <li><strong>Mouse Inactivity Detection:</strong> Starts counting down after the mouse stops moving.</li>
    <li><strong>Simple GUI:</strong> Provides an easy-to-use interface to control the auto clicker.</li>
    <li><strong>Start/Stop Control:</strong> Start or stop the clicking process with simple button clicks.</li>
</ul>

---

## Tech Stack

<p><strong>Languages & Tools:</strong></p>
<ul>
    <li><a href="https://www.python.org/">Python</a></li>
    <li><a href="https://docs.python.org/3/library/tkinter.html">Tkinter</a> for GUI</li>
    <li><a href="https://pyautogui.readthedocs.io/">PyAutoGUI</a> for simulating mouse clicks</li>
    <li><a href="https://pypi.org/project/pyperclip/">pyperclip</a> for clipboard operations (if used in the future)</li>
</ul>

---

## Installation

### Prerequisites

- Python 3.x installed on your system.
- Required Python libraries: `tkinter`, `pyautogui`.

### Steps

1. Clone the repository:
   
   ```bash
   git clone https://github.com/yourusername/autoclicker.git
   ```

2. Install the required libraries:
   
   ```bash
   pip install pyautogui
   ```

## Usage

- Open the `AutoClicker.py` file to launch the program.
- In the GUI, input the number of hours, minutes, and seconds for the auto-clicker interval.
- Click on "Turn ON" to start the auto-clicking process.
- If you want to stop the auto-clicker, simply click "Turn OFF".
- The auto-clicker will trigger clicks whenever there is no mouse movement detected.
