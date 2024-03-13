/*
  SIT210 - Task 1.1P
  Mubasher Fareed
  StudentID: 215426559
  
  Morse Code of my first name

  "--",     // M
  "..-",    // U
  "-...",   // B
  ".-",     // A
  "...",    // S
  "....",   // H
  ".",      // E
  ".-.",    // R  
*/

const int buttonPin = 3;  // Pushbutton connected to pin 3
const int ledPin = 8;     // LED connected to pin 8

const int dotDuration = 250;  // Duration of a dot in milliseconds
const int dashDuration = 3 * dotDuration;  // Duration of a dash (3 times longer than a dot)

const char* morseCode[] = {
  ".-",     // A
  "-...",   // B
  "-.-.",   // C
  "-..",    // D
  ".",      // E
  "..-.",   // F
  "--.",    // G
  "....",   // H
  "..",     // I
  ".---",   // J
  "-.-",    // K
  ".-..",   // L
  "--",     // M
  "-.",     // N
  "---",    // O
  ".--.",   // P
  "--.-",   // Q
  ".-.",    // R
  "...",    // S
  "-",      // T
  "..-",    // U  
  "...-",   // V
  ".--",    // W
  "-..-",   // X
  "-.--",   // Y
  "--.."    // Z
};

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) 
  {
    convert_string_to_morse_code();
  }
}

void convert_string_to_morse_code() {

  char name[9] = "MUBASHER";

  for (int i = 0; i < sizeof(name) - 1; i++) 
  {   
    char letter = name[i];
    int morseIndex = letter - 'A';  // get letter index with respect to `A`
    
    const char* code = morseCode[morseIndex];

    blink_code(code);  // Blink Morse code representation of the letter    

    delay(dotDuration * 4);  // 4 dots duration for inter-element space
  }
}

void blink_code(const char* code) {

  for (int i = 0; i < strlen(code); i++) {

    char signal = code[i];

    if (signal == '.') 
    {
      digitalWrite(ledPin, HIGH);  // Turn LED on for a dot
      delay(dotDuration);
    } 
    else if (signal == '-') 
    {
      digitalWrite(ledPin, HIGH);  // Turn LED on for a dash
      delay(dashDuration);
    }

    digitalWrite(ledPin, LOW);  // Turn LED off after dot or dash
    delay(dotDuration);          // Short delay between dots and dashes
  }
}
