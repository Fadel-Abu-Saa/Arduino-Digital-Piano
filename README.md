# 🎹 Arduino Digital Piano Synthesizer

<div align="center">
  <img width="700" alt="Arduino Piano Circuit" src="https://github.com/user-attachments/assets/1e0d1a7f-5740-4e36-8837-42eacf8bceae" />
</div>
<br/>

This project is a fully programmable electronic synthesizer built with Arduino. It utilizes 8 pushbuttons as piano keys to generate tones through a piezo buzzer. Designed with a focus on playability, it features advanced real-time controls, allowing the user to shift octaves dynamically and toggle between different musical scales using software-debounced inputs for a seamless, glitch-free playing experience.

## ✨ Key Features

* **8-Key Interface:** Responsive pushbuttons mapped to accurate musical frequencies.
* **Dynamic Octave Shifting:** Instantly pitch the notes up or down in real-time.
* **Multiple Musical Scales:** Switch between Major, Minor, and Blues scales on the fly.
* **Software Debouncing:** Custom logic to ensure clean, accurate note triggers without hardware noise or double-press glitches.
* **Piezo Audio Output:** Direct tone generation utilizing microcontroller timers.

## 🚀 Live Interactive Simulation

You can test the circuit, read the code, and play the synthesizer directly in your browser without needing any physical hardware! 

👉 **[Launch Wokwi Simulation](https://wokwi.com/projects/463450510342318081)**

## 🧰 Hardware Components

* Arduino Uno (or compatible microcontroller)
* 1x Piezo Buzzer
* Pushbuttons (8 for piano keys + additional for control switches)
* Resistors (for hardware pull-downs, if not using internal pull-ups)
* Breadboard & Jumper Wires

## 🛠️ How It Works

The system continuously polls the state of the buttons. To ensure a smooth musical experience, the code implements a **debounce algorithm** that filters out mechanical switch noise. Depending on the active scale mode and octave offset, the input from the 8 main keys is mathematically mapped to specific frequencies and sent to the Piezo buzzer using the `tone()` function.
