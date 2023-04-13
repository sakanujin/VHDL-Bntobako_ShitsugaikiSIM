#include<M5Stack.h>

#define pulse_A 2  // trigger pin
#define TP4     5  // data pin
#define smpuSec  400
#define sample_num     5

volatile bool flag  = false;
volatile bool debug = true;

volatile int segData[8][sample_num];

volatile int  judge [8][2] ;

volatile bool data_ok [8];
volatile int  i; // loop index

String lcdv; 
void getData();

void setup() {
  // put your setup code here, to run once:
  pinMode(TP4, INPUT);
  pinMode(pulse_A, INPUT_PULLUP);
  

  M5.begin();
  M5.Lcd.setTextSize(4);
  M5.Lcd.setTextFont(2);
  M5.Lcd.setCursor(10, 10); 
  
  lcdv = "start now..";
  M5.Lcd.println(lcdv);
  delay (1000);

  attachInterrupt(digitalPinToInterrupt(pulse_A), getData, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (!flag){
    delay(1);
  }
 
  detachInterrupt(digitalPinToInterrupt(pulse_A));
  flag = false;
  
  for (i=0; i< 8; i++){  // repeat 8 times (a, b, c, d, e, f, g, dp)
    segData[i][0] = digitalRead(TP4); 
    //delayMicroseconds(smpuSec);
    delay (2);
    
  } // end for

  if (segData[0][0]==1 && segData[1][0]==0 && segData[2][0]==0 && segData[3][0]==1 && segData[4][0]==1 && segData[5][0]==1 && segData[6][0]==1){
     lcdv = "1";
  }
  else if(segData[0][0]==0 && segData[1][0]==0 && segData[2][0]==1 && segData[3][0]==0 && segData[4][0]==0 && segData[5][0]==1 && segData[6][0]==0){
     lcdv = "2";
  }
  else if(segData[0][0]==0 && segData[1][0]==0 && segData[2][0]==0 && segData[3][0]==0 && segData[4][0]==1 && segData[5][0]==1 && segData[6][0]==0){
     lcdv = "3";
  }
  else if(segData[0][0]==1 && segData[1][0]==0 && segData[2][0]==0 && segData[3][0]==1 && segData[4][0]==1 && segData[5][0]==0 && segData[6][0]==0){
     lcdv = "4";
  }
  else if(segData[0][0]==0 && segData[1][0]==1 && segData[2][0]==0 && segData[3][0]==0 && segData[4][0]==1 && segData[5][0]==0 && segData[6][0]==0){
     lcdv = "5";
  } 
  else if(segData[0][0]==0 && segData[1][0]==1 && segData[2][0]==0 && segData[3][0]==0 && segData[4][0]==0 && segData[5][0]==0 && segData[6][0]==0){
      lcdv = "6" ;
  }
  else if(segData[0][0]==0 && segData[1][0]==0 && segData[2][0]==0 && segData[3][0]==1 && segData[4][0]==1 && segData[5][0]==1 && segData[6][0]==1){
      lcdv = "7" ;
  }
  else if(segData[0][0]==0 && segData[1][0]==0 && segData[2][0]==0 && segData[3][0]==0 && segData[4][0]==0 && segData[5][0]==0 && segData[6][0]==0){
      lcdv = "8" ;
  }
  else if(segData[0][0]==0 && segData[1][0]==0 && segData[2][0]==0 && segData[3][0]==0 && segData[4][0]==1 && segData[5][0]==0 && segData[6][0]==0){
      lcdv = "9" ;
  }  
  else if(segData[0][0]==0 && segData[1][0]==0 && segData[2][0]==0 && segData[3][0]==0 && segData[4][0]==1 && segData[5][0]==0 && segData[6][0]==1){
      lcdv = "0" ;
  } 
  else if(segData[0][0]==1 && segData[1][0]==1 && segData[2][0]==1 && segData[3][0]==1 && segData[4][0]==1 && segData[5][0]==1 && segData[6][0]==1){
      lcdv = " " ;
  }  
  //else {
  //  lcdv = "no data";
  //}

     if (debug == true) {
          Serial.print(segData[0][0]);
          Serial.print(segData[1][0]);
          Serial.print(segData[2][0]);
          Serial.print(segData[3][0]);
          Serial.print(segData[4][0]);
          Serial.print(segData[5][0]);
          Serial.print(segData[6][0]);
          Serial.print(segData[7][0]);
          Serial.print(" : ");
          Serial.print(lcdv);
          Serial.println();  
     }
  
 M5.Lcd.setCursor(10, 10); 
 M5.Lcd.print(lcdv);
 delay(200);
 M5.Lcd.clear();
 // interrupt set again
 attachInterrupt(digitalPinToInterrupt(pulse_A), getData, RISING);
 
}// end LOOP()

void getData(){
  flag = true;
}
