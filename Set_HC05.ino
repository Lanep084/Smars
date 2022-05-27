void setup() {

Serial.begin(38400);
delay(500);
Serial.println(" AT+NAME=Bluino#00" );
delay(500); 
Serial.println(" AT+UART=115200,0,0" ); // Use this baudrate if using for Arduino Uno, Bluino and Mega2560 //
delay(500); 
Serial.println(" AT+POLAR=1,0" );
delay(500); 
}

void loop() { }
