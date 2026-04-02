# Line Follower Robot

## Overview
This project is a line-following robot built using Arduino.  
It uses 3 IR sensors to detect a path and controls two motors via an L298N motor driver to follow the line autonomously.

## Components
- Arduino board
- 3 IR sensors (left, center, right)
- L298N motor driver
- DC motors
- Battery pack
- Chassis

## Working Principle
- The robot reads values from the three IR sensors.
- Based on sensor inputs, it decides:
  - Move forward if centered on the line
  - Turn left or right to correct its path
  - Adjust behavior when the line is lost
- A simple state memory (`ld`) is used to remember the last direction when the line is lost.

## Features
- Line tracking using multiple sensors
- Basic decision logic for movement
- Line loss handling strategy
- Motor control using L298N driver

## Behavior Logic
- Center sensor detects line → move forward
- Left sensor detects line → turn left
- Right sensor detects line → turn right
- All sensors detect line → move forward (intersection)
- No sensors detect line → recover using last known direction

## What I Learned
- Interfacing IR sensors with Arduino
- Controlling DC motors using L298N
- Implementing decision-making logic in embedded systems
- Handling edge cases like line loss

## Future Improvements
- Implement PID control for smoother movement
- Improve sensor calibration
- Add speed adjustment based on error
