# MindControl: An EEG-Based Video Game Controller


## What it does 

MindControl is an Arduino Script that reads the brain wave data from a MindFlex Duel EEG Headset and outputs a keystroke in response to certain brain wave patterns. 
It uses the Arduino brain library to get the Theta, Low Alpha, High Alpha, Low Beta, and High Beta brain wave bands to calculate a user's emotion depending on the two-dimensional valence-arousal model typically used in modern neuropsychology.
In addition, it calculates the user's engagement level, which is useful to detect if a user wants to actually output a given keystroke at a given moment.

## Installation

In order to create the EEG headset used for this project, follow [this](https://frontiernerds.com/brain-hack) tutorial created by Frontier Nerds, the creators of the Arduino Brain Library. 

# Make sure to use the ARDUINO LEONARDO in order to send keyboard input back to the system connected.

## Problems in Implementation


## Project Status / Future Goals


