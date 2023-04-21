#include<M5Core2.h>
//#include<M5Stack.h>

#define sampleMicroSec  50
#define sample_num     40

#define pulse_A        19    //core2
#define TP4            27    //core2

//#define pulse_A        2    //Gray
//#define TP4            5    //Gray

volatile boolean debug = 0;

volatile boolean  segA[sample_num] ;
volatile boolean  segB[sample_num] ;
volatile boolean  segC[sample_num] ;
volatile boolean  segD[sample_num] ;
volatile boolean  segE[sample_num] ;
volatile boolean  segF[sample_num] ;
volatile boolean  segG[sample_num] ;
volatile boolean  segdP[sample_num] ;

volatile int      judgeA [2] = {0, 0};   // count 1 and 0
volatile int      judgeB [2] = {0, 0};
volatile int      judgeC [2] = {0, 0};
volatile int      judgeD [2] = {0, 0};
volatile int      judgeE [2] = {0, 0};
volatile int      judgeF [2] = {0, 0};
volatile int      judgeG [2] = {0, 0};
volatile int      judgedP[2] = {0, 0};

volatile boolean  segAok;  // True or False 
volatile boolean  segBok;
volatile boolean  segCok;
volatile boolean  segDok;
volatile boolean  segEok;
volatile boolean  segFok;
volatile boolean  segGok;
volatile boolean  segdPok;

volatile boolean  flag = 0;

volatile int  i;  // loop index

String lcdV;// = "START";
void  Shitugaiki_pulse_capture() {
  flag =  1;  
}

void setup() {
 
  //M5.begin(true, true, true, true);
  M5.begin();
  M5.Lcd.setTextSize(20);
  M5.Lcd.setTextFont(2);
  M5.Lcd.setCursor(10, 10); 
  M5.Lcd.println(lcdV);
  
  lcdV = "START";
  M5.Lcd.println(lcdV);
  delay (480 * 2);

  pinMode (pulse_A, INPUT_PULLDOWN);
  pinMode (TP4,     INPUT_PULLUP);
 
  attachInterrupt(digitalPinToInterrupt(pulse_A), Shitugaiki_pulse_capture, RISING); 
}

void loop() {

  while(!flag){
    delay(16);
  }
  detachInterrupt(digitalPinToInterrupt(pulse_A));
  flag = 0;

    //delayMicroseconds(5);

    for(i=0; i<sample_num; i++) {
      segA[i] = digitalRead(TP4);
      delayMicroseconds(sampleMicroSec);
      if (segA[i] == 0) {
        judgeA[0] = judgeA[0] + 1;
      }
      else if (segA[i] == 1){
        judgeA[1] = judgeA[1] + 1; 
      }
    } 

   for(i=0; i<sample_num; i++) {
      segB[i] = digitalRead(TP4);
      delayMicroseconds(sampleMicroSec);
      if (segB[i] == 0) {
        judgeB[0] = judgeB[0] + 1;
      }
      else if (segB[i] == 1){
        judgeB[1] = judgeB[1] + 1; 
      }
    } 
    
   for(i=0; i<sample_num; i++) {
      segC[i] = digitalRead(TP4); 
      delayMicroseconds(sampleMicroSec);
      if (segC[i] == 0) {
        judgeC[0] = judgeC[0] + 1;
      }
      else if (segC[i] == 1){
        judgeC[1] = judgeC[1] + 1; 
      }
    }
    
   for(i=0; i<sample_num; i++) {
      segD[i] = digitalRead(TP4); 
      delayMicroseconds(sampleMicroSec);
      if (segD[i] == 0) {
        judgeD[0] = judgeD[0] + 1;
      }
      else if (segD[i] == 1){
        judgeD[1] = judgeD[1] + 1; 
      }
    }

   for(i=0; i<sample_num; i++) {
      segE[i] = digitalRead(TP4); 
      delayMicroseconds(sampleMicroSec);
      if (segE[i] == 0) {
        judgeE[0] = judgeE[0] + 1;
      }
      else if (segE[i] == 1){
        judgeE[1] = judgeE[1] + 1; 
      }
    }

    for(i=0; i<sample_num; i++) {
      segF[i] = digitalRead(TP4); 
      delayMicroseconds(sampleMicroSec);
      if (segF[i] == 0) {
        judgeF[0] = judgeF[0] + 1;
      }
      else if (segF[i] == 1){
        judgeF[1] = judgeF[1] + 1; 
      }
    }   
  
   for(i=0; i<sample_num; i++) {
      segG[i] = digitalRead(TP4); 
      delayMicroseconds(sampleMicroSec);
      if (segG[i] == 0) {
        judgeG[0] = judgeG[0] + 1;
      }
      else if (segG[i] == 1){
        judgeG[1] = judgeG[1] + 1; 
      }
    }    

   for(i=0; i<sample_num; i++) {
      segdP[i] = digitalRead(TP4); 
      delayMicroseconds(sampleMicroSec);
      if (segdP[i] == 0) {
        judgedP[0] = judgedP[0] + 1;
      }
      else if (segdP[i] == 1){
        judgedP[1] = judgedP[1] + 1; 
      }
    } 
    
 //   count number of "0" and "1" from sample points
     if (judgeA[0] > judgeA[1]) {
        segAok = 0;
     }else {
        segAok = 1;
     }
     if (judgeB[0] > judgeB[1]) {
        segBok = 0;
     }else {
        segBok = 1;
     }
     
     if (judgeC[0] > judgeC[1]) {
        segCok = 0;
     } else {
        segCok = 1;
     }
     if (judgeD[0] > judgeD[1]) {
        segDok = 0;
     } else {
        segDok = 1;
     }

     if (judgeE[0] > judgeE[1]) {
        segEok = 0;
     } else {
        segEok = 1;
     }
     if (judgeF[0] > judgeF[1]) {
        segFok = 0;
     } else {
        segFok = 1;
     }

     if (judgeG[0] > judgeG[1]) {
        segGok = 0;
     } else {
        segGok = 1;
     }
     
     if (judgedP[0] > judgedP[1]) {
        segdPok = 0;
     } else {
        segdPok = 1;
     }

   if (debug == 1) {
          Serial.print(segAok);
          Serial.print(segBok);
          Serial.print(segCok);
          Serial.print(segDok);
          Serial.print(segEok);
          Serial.print(segFok);
          Serial.print(segGok);
          Serial.print(segdPok);
          Serial.print("   :  ");
          Serial.print(lcdV);
          Serial.println(); 
     }    
    
   // judgeX num is cleared.  
    judgeA[0] = 0;
    judgeA[1] = 0;
    judgeB[0] = 0;
    judgeB[1] = 0;
    judgeC[0] = 0;
    judgeC[1] = 0;
    judgeD[0] = 0;
    judgeD[1] = 0;
    judgeE[0] = 0;
    judgeE[1] = 0;
    judgeF[0] = 0;
    judgeF[1] = 0;
    judgeG[0] = 0;
    judgeG[1] = 0;
    judgedP[0] = 0;
    judgedP[1] = 0;
    
    if      (segAok == 1 && segBok ==0 && segCok ==0 && segDok ==1 && segEok == 1 && segFok ==1 && segGok ==1){
      lcdV = "1" ;
    }
    else if (segAok == 0 && segBok ==0 && segCok ==1 && segDok ==0 && segEok == 0 && segFok ==1 && segGok ==0 ){
      lcdV = "2" ;
    }
    else if (segAok == 0 && segBok ==0 && segCok ==0 && segDok ==0 && segEok == 1 && segFok ==1 && segGok ==0 ){
      lcdV = "3" ;
    }
    else if (segAok == 1 && segBok ==0 && segCok ==0 && segDok ==1 && segEok == 1 && segFok ==0 && segGok ==0 ){
      lcdV = "4" ;
    }
    else if (segAok == 0 && segBok ==1 && segCok ==0 && segDok ==0 && segEok == 1 && segFok ==0 && segGok ==0 ){
      lcdV = "5" ;
    }
    else if (segAok == 0 && segBok ==1 && segCok ==0 && segDok ==0 && segEok == 0 && segFok ==0 && segGok ==0 ){
      lcdV = "6" ;
    }
    else if (segAok == 0 && segBok ==0 && segCok ==0 && segDok ==1 && segEok == 1 && segFok ==1 && segGok ==1 ){
      lcdV = "7" ;
    }
    else if (segAok == 0 && segBok ==0 && segCok ==0 && segDok ==0 && segEok == 0 && segFok ==0 && segGok ==0 ){
      lcdV = "8" ;
    } 
    else if (segAok == 0 && segBok ==0 && segCok ==0 && segDok ==0 && segEok== 1 && segFok ==0 && segGok ==0 ){
      lcdV = "9" ;
    } 
    else if (segAok == 0 && segBok ==0 && segCok ==0 && segDok ==0 && segEok == 0 && segFok ==0 && segGok ==1 ){
      lcdV = "0" ;
    } 
    else if (segAok == 1 && segBok ==1 && segCok ==1 && segDok ==1 && segEok == 1 && segFok ==1 && segGok ==1 ){
      lcdV = " " ;
    } 
    
    M5.Lcd.setCursor(10, 10); 
    M5.Lcd.print(lcdV);
    //delay(480);
    delay(480 / 3 );
    M5.Lcd.clear();
    attachInterrupt(digitalPinToInterrupt(pulse_A), Shitugaiki_pulse_capture, RISING); 
}
