# Automatic Nerf Target Game

The **Automatic Nerf Target Game** is an interactive target shooting system designed for use with Nerf guns. It keeps score automatically and resets the targets for continued play, providing a fun and challenging experience for players of all ages. Whether you want to practice your accuracy or compete with friends, this system offers two engaging game modes and real-time scoring displayed on an LCD screen.

## What is it made of?

The system is composed of the following components:

- **Wooden Base**:  
  The foundation of the game is a sturdy wooden board that holds all the components in place, ensuring stability during intense Nerf battles.

- **LCD Display**:  
  Mounted on a 3D-printed stand, the LCD screen displays the game mode, time remaining, and score in real-time. Players can easily track their performance and switch between game modes using the joystick.

- **Joystick for Game Mode Selection**:  
  A joystick is used to navigate through and select the game mode. It provides an intuitive control system for users to choose between Arcade Mode or Training Mode before starting the game.

- **Three Targets**:  
  The game features three targets, each attached to the base with a steel hinge and an M4 bolt and nut. When a target is hit and knocked down, a proximity sensor behind it detects the fall and adds a point to the score. The system then signals a servo motor to raise another target for the next shot.

- **Servo Motors**:  
  Each target is reset to its upright position by a servo motor. The servos quickly raise the targets back into place, making the game fast-paced and continuous.

- **Presence Sensors**:  
  Each target has a presence sensor mounted behind it to detect when it has been knocked over. These sensors trigger the scoring system and reset the targets as needed.

- **Arduino Uno**:  
  The entire system is controlled by an Arduino Uno, which manages the target reset mechanism, score tracking, and game mode logic.

## Game Modes

### Arcade Mode
In this mode, players have one minute to hit as many targets as possible. The LCD keeps track of the time and displays the score in real-time as targets are knocked down and reset.

### Training Mode
This mode is designed for practice sessions. Targets continuously rise as they are hit, allowing players to train for as long as they want. The LCD displays the training time and score, allowing players to track their progress and performance.

## How does it work?

### Hit Detection and Target Reset
When a Nerf dart knocks down a target, the sensor detects its fall, adds a point to the score, and instructs the corresponding servo motor to raise another target back into position. The continuous target reset ensures the game stays fast-paced and challenging.

### Game Controls and Scoring
The joystick allows players to select between Arcade and Training modes. During gameplay, the LCD shows the current score, remaining time (in Arcade mode), or the duration of training (in Training mode). This real-time feedback keeps players engaged and focused on improving their performance.

## Additional Features

### Customizable Design
The LCD screen is securely mounted on a 3D-printed support, making it easy to assemble and modify. The entire system can be customized to accommodate different target sizes or game configurations.

### Printable Parts
You can find the printable parts for this project on my Thingiverse account: [Thingiverse - Automatic Nerf Target Game](https://www.thingiverse.com/thing:6806833).

### GitHub Code Access
All the necessary code and wiring diagrams for this project can be found in this repository. Follow the provided instructions to set up and program the system.

## Conclusion

The Automatic Nerf Target Game offers a dynamic and engaging shooting experience that keeps track of your hits and automatically resets targets. Perfect for casual fun or focused training, this Arduino-powered project brings a new level of interactivity to your Nerf sessions. Whether you’re playing alone or with friends, the two game modes—Arcade and Training—ensure endless entertainment. With all the components easily assembled and controlled via Arduino, this project is perfect for Nerf enthusiasts, tinkerers, and makers alike!
