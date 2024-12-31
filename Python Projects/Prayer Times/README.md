# Prayer Times Python Project

<p align="center"><strong>A Python application to display daily prayer times for a specific city using the Aladhan API.</strong></p>

---

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

---

## About the Project

This project provides daily prayer times for a specified city (defaulted to Cairo, Egypt) using the Aladhan API. The application fetches the prayer times, processes them, and displays them in a user-friendly GUI.

Key Highlights:

- Displays prayer times for Fajr, Dhuhr, Asr, Maghrib, and Isha.
- The program fetches real-time prayer times from the Aladhan API.
- Features a graphical user interface (GUI) to show the prayer times.
- Written in Python using the Tkinter library for the interface and requests for fetching the API data.

This project was built as part of a personal project to display prayer times dynamically.

<img src="https://github.com/AhmedEmadh/all_projects/blob/master/Python%20Projects/Prayer%20Times/Screenshot.png" alt="Screenshot" />

---

## Features

<ul>
    <li><strong>Real-Time Data:</strong> Fetches prayer times using the Aladhan API for a specific city.</li>
    <li><strong>Graphical User Interface (GUI):</strong> Displays prayer times in an easy-to-read format using Tkinter.</li>
    <li><strong>Time Formatting:</strong> Converts 24-hour times to 12-hour AM/PM format.</li>
    <li><strong>Error Handling:</strong> Displays an error message if there is no internet connection or if the request fails.</li>
</ul>

---

## Tech Stack

<p><strong>Languages & Tools:</strong></p>
<ul>
    <li><a href="https://www.python.org/">Python 3.x</a></li>
    <li><a href="https://docs.python.org/3/library/tkinter.html">Tkinter (for GUI)</a></li>
    <li><a href="https://requests.readthedocs.io/">Requests (for API calls)</a></li>
</ul>

---

## Installation

### Prerequisites

- Python 3.x installed on your machine.
- Required Python libraries: `tkinter` (usually pre-installed with Python) and `requests`.

# 

---

# Steps

### 1. Clone the repository:

```bash
git clone https://github.com/yourusername/prayer-times.git
```

### 2. Navigate to the project folder:

```bash
cd prayer-times
```

### 3. Install required dependencies (if not already installed):

```bash
pip install requests
```

### 4. Run the project:

```bash
python prayer_times.py
```

---

# Usage

Once the program is executed, a window will pop up showing the prayer times for the current day in the specified city (Cairo by default). The city and country can be modified in the script by changing the `city` and `country` variables.

You will see a GUI that shows the prayer times for:

- Fajr
- Dhuhr
- Asr
- Maghrib
- Isha

The times will be displayed in a 12-hour AM/PM format. If there is an error (e.g., no internet connection), the program will display an error message.
