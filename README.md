# MindControl: An EEG-Based Video Game Controller


## What it does 

MindControl is an Arduino Script that reads the brain wave data from a MindFlex Duel EEG Headset and outputs a keystroke in response to certain brain wave patterns. 
It uses the Arduino brain library to get the Theta, Low Alpha, High Alpha, Low Beta, and High Beta brain wave bands to calculate a user's emotion depending on the two-dimensional valence-arousal model typically used in modern neuropsychology.

In addition to valence and arousal, it also calculates the user's engagement level, which is useful to detect if a user wants to actually output a given keystroke at a given moment.
After calculating these values, the program will then calculate what emotion a user is feeling. There are four emotions that are recognized for now (Enthusiastic, Nervous, Calm, and Disappointed).

Now, there is a template function included in the program for the "Geometry Dash" video game. 
When a user is "Enthusiastic" the "up arrow" on a simulated keyboard is "pressed" which causes the character in game to also jump.

This program is meant to act as more of a template that can be applied to various games.
In order to change controls on a game by game basis you need to simply change what the "keyboard" outputs after a given emotion is detected.

## Installation

In order to create the EEG headset used for this project, follow [this](https://frontiernerds.com/brain-hack) tutorial created by Frontier Nerds, the creators of the Arduino Brain Library. 

### Make sure to use the ARDUINO LEONARDO in order to send keyboard input back to the system connected.

Afterward, simply install the Arduino IDE, and connect your Arduino to your PC. Load the MindControl.ino in the MindControl folder and run the program.

## Problems in Implementation

Due to the MindFlex Duel headset only being a single-channel headset, the data is NOT accurate. 

This is because based my formulas for Arousal, Valence, and Engagement on the formulas for these values made for the EMOTIV EPOC+, a multisensor headset.
The original formulas for EPOC+ were created by Dr. McMahan, Dr. Ian Parberry, and Dr. Thomas Parsons, in this research [paper](https://doi.org/10.1016/j.promfg.2015.07.376).

As a result, I have reason to believe that the conversions I made between the multisensor data outputs from the EPOC+ to the single sensor data outputs by the MindFlex Duel used in this project are what are causing inaccurate results.
Unfortunately, I do not have a strong enough background in Computational Neuropsychology to be able to fix these issues, and as such, they shall be left in their relatively inaccurate state.

## Project Status / Future Goals

This project is currently complete. I could add more functions and perhaps more templates for the keystroke output, but I do not think I will be able to fix the issues that occur due to the single sensor. 
If I ever purchase or receive a multisensor EEG, I have reason to believe that I will program a significantly more accurate version of this project.
