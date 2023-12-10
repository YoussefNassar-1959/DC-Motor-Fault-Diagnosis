# DC Motor Fault Detection System 🛠️

## Overview ℹ️

This repository contains an Arduino program designed to monitor and analyze the performance of a DC motor using a current sensor module. The program measures the motor's current consumption and evaluates potential faults in the motor's geartrain based on peak current readings.

## Features ✨

- **Current Measurement:** Utilizes a current sensor module to measure the DC motor's current consumption.
- **RPM Calculation:** Uses an encoder to calculate the motor's RPM (Revolutions Per Minute).
- **Fault Detection:** Analyzes current readings to detect irregularities that may indicate geartrain faults.
- **Fitting Function:** Predicts expected healthy RPM based on a fitted function and compares it to measured RPM.

## How It Works 🔄

The program continuously reads current data from the sensor, calculates RPM, and compares the measured RPM with the expected healthy RPM derived from a fitted function. If the deviation exceeds a set threshold, it flags the motor as potentially faulty.

## Getting Started 🚀

To run this program:
1. Set up your Arduino board with the appropriate connections.
2. Upload the `main.ino` sketch to your Arduino IDE.
3. Ensure the current sensor and encoder are correctly wired.
4. Monitor the serial output to observe motor RPM and fault detection status.

## Calibration and Customization 🛠️

- **Sensor Calibration:** Adjust ADC readings to accurately represent current values for your sensor.
- **Fitting Function Parameters:** Tune parameters for the fitted function to match your motor's characteristics.

## Contributions and Issues 🤝

Feel free to contribute to this project by opening issues, suggesting enhancements, or submitting pull requests. Contributions of all kinds are welcome!

## License 📝

This project is licensed under the [MIT License](LICENSE) - see the [LICENSE](LICENSE) file for details.


Maintained with ❤️ by [Your GitHub Username](https://github.com/YourGitHubUsername)
