#include <Servo.h>
#include <LiquidCrystal.h>

// Pin Definitions
#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define TARGET1_PIN 2 // Proximity sensor for target 1
#define TARGET2_PIN 3 // Proximity sensor for target 2
#define TARGET3_PIN 4 // Proximity sensor for target 3
#define SERVO1_PIN 5 // Servo for target 1
#define SERVO2_PIN 6 // Servo for target 2
#define SERVO3_PIN 7 // Servo for target 3
#define LCD_RS 8
#define LCD_E 9
#define LCD_D4 10
#define LCD_D5 11
#define LCD_D6 12
#define LCD_D7 13

// Game Modes
enum GameMode { Arcade, Training };
GameMode currentMode = Arcade;

// Servo objects
Servo target1Servo;
Servo target2Servo;
Servo target3Servo;

// LCD object
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// Game variables
int score = 0;
unsigned long startTime;
unsigned long elapsedTime = 0;
const unsigned long arcadeDuration = 60000; // 1 minute for Arcade mode
bool target1Hit = false;
bool target2Hit = false;
bool target3Hit = false;

void setup() {
    Serial.begin(9600);
    
    // Initialize servos
    target1Servo.attach(SERVO1_PIN);
    target2Servo.attach(SERVO2_PIN);
    target3Servo.attach(SERVO3_PIN);

    // Initialize LCD
    lcd.begin(16, 2);
    lcd.print("Nerf Target Game");
    delay(2000);
    
    // Start in Arcade Mode
    selectGameMode();
}

void loop() {
    // Read the joystick position
    int joystickX = analogRead(JOYSTICK_X);
    int joystickY = analogRead(JOYSTICK_Y);

    // Game mode selection
    if (joystickX < 400) {
        currentMode = Arcade;
        lcd.setCursor(0, 1);
        lcd.print("Mode: Arcade    ");
    } else if (joystickX > 600) {
        currentMode = Training;
        lcd.setCursor(0, 1);
        lcd.print("Mode: Training  ");
    }

    // Run the selected game mode
    if (currentMode == Arcade) {
        runArcadeMode();
    } else {
        runTrainingMode();
    }

    // Check targets
    checkTargets();
}

void selectGameMode() {
    // Wait for joystick to settle
    delay(200);
    while (true) {
        int joystickX = analogRead(JOYSTICK_X);
        if (joystickX < 400) {
            currentMode = Arcade;
            lcd.setCursor(0, 1);
            lcd.print("Mode: Arcade    ");
            break;
        } else if (joystickX > 600) {
            currentMode = Training;
            lcd.setCursor(0, 1);
            lcd.print("Mode: Training  ");
            break;
        }
    }
    delay(1000);
}

void runArcadeMode() {
    // Start timer
    if (score == 0) {
        startTime = millis();
    }

    // Calculate elapsed time
    elapsedTime = millis() - startTime;

    // Check if time is up
    if (elapsedTime >= arcadeDuration) {
        lcd.clear();
        lcd.print("Time's Up!");
        lcd.setCursor(0, 1);
        lcd.print("Score: ");
        lcd.print(score);
        delay(3000);
        resetGame();
    } else {
        // Display score and remaining time
        lcd.setCursor(0, 1);
        lcd.print("Score: ");
        lcd.print(score);
        lcd.print(" Time: ");
        lcd.print((arcadeDuration - elapsedTime) / 1000);
    }
}

void runTrainingMode() {
    lcd.setCursor(0, 1);
    lcd.print("Score: ");
    lcd.print(score);
}

void checkTargets() {
    if (digitalRead(TARGET1_PIN) == HIGH && !target1Hit) {
        target1Hit = true;
        score++;
        target1Servo.write(0); // Lower target 1
        delay(500);
        target1Servo.write(90); // Reset target 1
        lcd.setCursor(0, 1);
        lcd.print("Score: ");
        lcd.print(score);
    }
    
    if (digitalRead(TARGET2_PIN) == HIGH && !target2Hit) {
        target2Hit = true;
        score++;
        target2Servo.write(0); // Lower target 2
        delay(500);
        target2Servo.write(90); // Reset target 2
        lcd.setCursor(0, 1);
        lcd.print("Score: ");
        lcd.print(score);
    }
    
    if (digitalRead(TARGET3_PIN) == HIGH && !target3Hit) {
        target3Hit = true;
        score++;
        target3Servo.write(0); // Lower target 3
        delay(500);
        target3Servo.write(90); // Reset target 3
        lcd.setCursor(0, 1);
        lcd.print("Score: ");
        lcd.print(score);
    }

    // Reset hits after a brief delay
    if (millis() % 1000 == 0) {
        target1Hit = false;
        target2Hit = false;
        target3Hit = false;
    }
}

void resetGame() {
    score = 0;
    target1Hit = false;
    target2Hit = false;
    target3Hit = false;
    lcd.clear();
    lcd.print("Nerf Target Game");
    delay(2000);
}
