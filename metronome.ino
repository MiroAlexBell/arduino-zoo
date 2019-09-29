//---------------------------------------------------------------
#define PIN_LED  10      // buzzer pin
#define BUTTON_PIN 7    //calibration button pin
#define MIN_BPM 100      // minimum bpm value
#define MAX_BPM 130     // maximum bpm value
#define POT A0          // pot analog pin
//---------------------------------------------------------------


//---------------------------------------------------------------
int bpm;                // bpm value
int button_state = 0;   //calibration button state
//---------------------------------------------------------------

void setup() {
  Serial.begin(4800);
  pinMode(PIN_LED, OUTPUT);  // LED pin as output
  pinMode(BUTTON_PIN, INPUT); //Button pin as input
  delay(2000);
}
//---------------------------------------------------------------

void loop() {
    if(digitalRead(BUTTON_PIN) == 0){
        bpm = map(analogRead(POT), 0, 1023, MIN_BPM, MAX_BPM);  //maps pot value into BPM
        Serial.print(bpm);
        Serial.print("\n");
        
        digitalWrite(PIN_LED, HIGH);        // does a "tick" for...
        delay(6000 / bpm);        // 10% of T (where T is the time between two BPSs)
        digitalWrite(PIN_LED, LOW);           // silence for...
        delay(54000 / bpm);       // 90% of T
      
    }
}
