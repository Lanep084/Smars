/*Programma per Robot Smars, realizzato da Aspari Lorenzo in data: 20.05.2022 
*/

#include <AFMotor.h>                    // includere la libreria per comandare la shield L293

AF_DCMotor MotorL(1);                   // definire il motore sinistro come Motore 1 
AF_DCMotor MotorR(2);                   // definire il motore destro come Motore 2
                                       

const int buzPin = 7;                   // settare il pin digitale 7 come buzPin (attiva il buzzer)

String readString, action, Lspeed, Rspeed, actionDelay, stopDelay; // dichiarare le stringhe multiple

void setup(){ 
  Serial.begin(115200);                 // settare la velocità della Seriale a 115200 bps                                        
  Serial.println("*SMARS Remote Control Mod*"); 
  
  pinMode(buzPin, OUTPUT);              // settare il pin del buzzer come Output 
  
  //settare la velocià di partenza, da 0 (off) a 255 (massima velocità) 
  MotorL.setSpeed(255); 
  MotorR.setSpeed(255); 
  // turn off motor 
  MotorL.run(RELEASE); 
  MotorR.run(RELEASE);
   
  } 

  //String line = "";
void loop() { 
  while (Serial.available() > 0) {
    char c = Serial.read();            // ottiene un byte dal buffer seriale 
    readString += c; 
    
    if (c == '\n') { 
       Serial.println("---------------"); 
       Serial.print(readString);       // stampa la stringa sulla porta seriale in uscita  
    
       
    
    // avanti 
    if(action.equals("F")){ 
      MotorL.setSpeed(255); 
      MotorR.setSpeed(255); 
      MotorL.run(FORWARD); 
      MotorR.run(FORWARD); 
      
      // in dietro 
      } else if(action.equals("B")){
        MotorL.setSpeed(255); 
        MotorR.setSpeed(255); 
        MotorL.run(BACKWARD); 
        MotorR.run(BACKWARD); 
        
      // sinistra 
      } else if(action.equals("L")){ 
        MotorL.setSpeed(255); 
        MotorR.setSpeed(255); 
        MotorL.run(BACKWARD); 
        MotorR.run(FORWARD); 
        
      // destra 
      } else if(action.equals("R")){ 
        MotorL.setSpeed(255); 
        MotorR.setSpeed(255); 
        MotorL.run(FORWARD); 
        MotorR.run(BACKWARD); 
        
       // stop 
       } else if(action.equals("S")){ 
          MotorL.run(RELEASE);
          MotorR.run(RELEASE); 
          
        // bizzer on  
       } else if(action.equals("H")){ 
        digitalWrite(7, HIGH); 
        delay(150); 
        digitalWrite(7, LOW); 
        delay(100); 
        digitalWrite(7, HIGH); 
        delay(250); 
        digitalWrite(7, LOW);
       }
      
      } 
     } 
    }
