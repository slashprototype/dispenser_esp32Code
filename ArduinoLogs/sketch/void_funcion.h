#line 1 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\void_funcion.h"
void funcion(){
  if (Serial.available()){
  Serial.write(Serial.read());   
  }
}
void blink_led(const int pin){
  digitalWrite(pin,HIGH);
  vTaskDelay(100);
  digitalWrite(pin,LOW);
  vTaskDelay(100);
}
