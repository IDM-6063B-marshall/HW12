//Turn potentiometer all the way to the left
//Press button 
//Turn potentiometer all the way to the right
//Press button 

//Success: green LED
//Failure & default: red LED

int green = A0;   // Green LED pin
int red = A2;     // Red LED pin
int button = D8;  // Button pin
int pot = A6;     // Potentiometer pin

int potVal;
int buttonVal;
int lastButtonVal;
int nClicks;
bool success; //bool is true/false
bool passwordComplete;

void setup() {
  pinMode(green, OUTPUT);  
  pinMode(red, OUTPUT);  
  pinMode(button, INPUT);
  pinMode(pot, INPUT);

  lastButtonVal = 0;
  nClicks = 0;
  success = false;
  passwordComplete = false;

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(pot);  // Read potentiometer value 
  buttonVal = digitalRead(button);  // Read button state

  // Detect button press via transition from value 0 to value 1
  if (lastButtonVal == 0 && buttonVal == 1) {
    nClicks++;  // Increment the click counter

    // Turn potentiometer to left (0) and press button
    if (nClicks == 1) {
      if (potVal == 0) {
        Serial.println("Potentiometer is all the way to the left.");
        success = true;  
      } else {
        success = false;
        Serial.println("Error.");
      }
    }

    // Turn potentiometer to right and press button
    if (nClicks == 2) {
      if (potVal > 4000) {
        Serial.println("Potentiometer is all the way to the right.");
      } else {
        success = false;
        Serial.println("Error.");
      }
    }

    if (nClicks == 2) {
      passwordComplete = true;
      if (success) {
        digitalWrite(green, HIGH);  // Turn on green LED for success
        digitalWrite(red, LOW);     // Turn off red LED
        Serial.println("Success!");
      } else {
        digitalWrite(green, LOW);   // Turn off green LED
        digitalWrite(red, HIGH);    // Turn on red LED
        Serial.println("Failure.");
      }

      delay(5000);  // Wait 5 seconds before resetting for the next cycle
      nClicks = 0;
      success = false;
      passwordComplete = false;
    }
  }

  lastButtonVal = buttonVal;

  delay(50);
}
