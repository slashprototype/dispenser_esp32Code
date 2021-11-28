# 1 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino"
# 2 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino" 2
# 3 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino" 2
# 4 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino" 2

// define two tasks for Blink & AnalogRead
void TaskBlink( void *pvParameters );
void TaskAnalogReadA3( void *pvParameters );
void TaskBlinkingLED2( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");

  // Now set up two tasks to run independently.
  xTaskCreatePinnedToCore(
    TaskBlink
    , "TaskBlink" // A name just for humans
    , 1024 // This stack size can be checked & adjusted by reading the Stack Highwater
    , 
# 26 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino" 3 4
      __null
    
# 27 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino"
   , 1 // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    , 
# 28 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino" 3 4
      __null
    
# 29 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino"
   , 1);

  xTaskCreatePinnedToCore(
    TaskAnalogReadA3
    , "AnalogReadA3"
    , 1024 // Stack size
    , 
# 35 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino" 3 4
      __null
    
# 36 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino"
   , 2 // Priority
    , 
# 37 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino" 3 4
      __null
    
# 38 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino"
   , 1);

  xTaskCreatePinnedToCore(
    TaskBlinkingLED2
    , "BlinkingLED2"
    , 1024 // Stack size
    , 
# 44 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino" 3 4
      __null
    
# 45 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino"
   , 2 // Priority
    , 
# 46 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino" 3 4
      __null
    
# 47 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino"
   , 1);

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/
void TaskBlinkingLED2(void *pvParameters) // This is a task.
{
  (void) pvParameters;
  pinMode(32, 0x02);
  for (;;) // A Task shall never return or exit.
  {
    blink_led(32);
  }
}

void TaskBlink(void *pvParameters) // This is a task.
{
  (void) pvParameters;

/*

  Blink

  Turns on an LED on for one second, then off for one second, repeatedly.

    

  If you want to know what pin the on-board LED is connected to on your ESP32 model, check

  the Technical Specs of your board.

*/
# 82 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino"
  // initialize digital LED_BUILTIN on pin 13 as an output.
  pinMode(13, 0x02);


  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(13, 0x1); // turn the LED on (HIGH is the voltage level)
    vTaskDelay(100); // one tick delay (15ms) in between reads for stability
    digitalWrite(13, 0x0); // turn the LED off by making the voltage LOW
    vTaskDelay(100); // one tick delay (15ms) in between reads for stability
    funcion();
  }
}

void TaskAnalogReadA3(void *pvParameters) // This is a task.
{
  (void) pvParameters;

/*

  AnalogReadSerial

  Reads an analog input on pin A3, prints the result to the serial monitor.

  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)

  Attach the center pin of a potentiometer to pin A3, and the outside pins to +5V and ground.



  This example code is in the public domain.

*/
# 109 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\FreeRTOS.ino"
  for (;;)
  {
  Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            vTaskDelay(10); // one tick delay (15ms) in between reads for stability
        }
    }
    Serial.println("");

    // Wait a bit before scanning again
    vTaskDelay(5000); // one tick delay (15ms) in between reads for stability
  }
}
