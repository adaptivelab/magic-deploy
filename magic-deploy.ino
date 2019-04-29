#define RED_LED 12
#define GREEN_LED 11
#define FLIP_SWITCH 2
#define KEY_SWITCH 3
#define DEPLOY_BUTTON 4

void setup() {
  pinMode(FLIP_SWITCH, INPUT_PULLUP);
  pinMode(KEY_SWITCH, INPUT_PULLUP);
  pinMode(DEPLOY_BUTTON, INPUT_PULLUP);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(RED_LED, HIGH);
}

void loop() {
  int flipSwitchReading = digitalRead(FLIP_SWITCH);
  int keySwitchReading = digitalRead(KEY_SWITCH);
  int deployButtonReading = digitalRead(DEPLOY_BUTTON);

  if (flipSwitchReading == LOW && keySwitchReading == LOW) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    if (deployButtonReading == LOW) {
      Keyboard.press(KEY_ENTER);
      Keyboard.release(KEY_ENTER);

      for (int i = 0; i <= 5; i++) {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);
        delay(100);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
        delay(100);
      }
    }
  } else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
}
