#include <Arduino.h>

#define LED D1
#define IRA D2
#define IRB D3

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(IRA,INPUT);
  pinMode(IRB,INPUT);
    // put your setup code here, to run once:
}

bool statusA = false;
bool statusB = true;
bool modeEntry = false;
bool modeExit = false;

int count = 0, entryCount = 0, exitCount =0;

void print() {
  Serial.print("Entry: ");
  Serial.print(entryCount);
  Serial.print(" / Exit:  ");
  Serial.print(exitCount);
  Serial.print(" [Room Occupancy: ");
  Serial.print(entryCount - exitCount);
  Serial.println("]");
}

void loop() {
  if(digitalRead(IRA)) {
    if(statusA == false) {
      statusA = true;
      if(modeExit == true) {
        exitCount++;
        modeExit = false;
        print();
      } else {
        modeEntry = true;
      }
    }
  } else {
    statusA = false;
  }

    if(digitalRead(IRB)) {
      if(statusB == false) {
        statusB = true;
        if(modeEntry == true) {
           entryCount++;
           modeEntry = false;
           print();
        } else {
          modeExit = true;
        }
      }
    } else {
      statusB = false;
    }
    // put your main code here, to run repeatedly:
}
