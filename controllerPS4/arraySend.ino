//created 25 October 2022

/*Include library*/
#include <PS4BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
#include <SoftwareSerial.h>

/*Define Class Library*/
USB Usb;
BTD Btd(&Usb);
PS4BT PS4(&Btd, PAIR);
SoftwareSerial mySerial(4, 5); //rx tx

/*Define Variable*/

bool bCommand;
bool printAngle, printTouch;
uint8_t oldL2Value, oldR2Value;
uint8_t lastSend[13];
uint8_t joy[13];
int left_xAxis, left_yAxis, right_xAxis, right_yAxis;
String sendJoyData;

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial)
    ;
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nUSB Host Shield not detected!"));
    while (1)
      ;
  }
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));
}

void loop() {
  Usb.Task();

  if (PS4.connected()) {
    if (PS4.getAnalogHat(LeftHatX)) {
      left_xAxis = PS4.getAnalogHat(LeftHatX);
      //      joy[8] = map (left_xAxis, 0, 255, -127, 127);
      joy[8] = left_xAxis;
    } if (PS4.getAnalogHat(LeftHatY)) {
      left_yAxis = PS4.getAnalogHat(LeftHatY);
//      joy[9] = map (left_yAxis, 0, 255, 127, -127);
      joy[9] = left_yAxis;
    } if (PS4.getAnalogHat(RightHatX)) {
//      if (128 >= PS4.getAnalogHat(RightHatX)) {
//        right_xAxis = PS4.getAnalogHat(RightHatX) - 128;
//      }
//      if (PS4.getAnalogHat(RightHatX) > 128) {
//        right_xAxis = PS4.getAnalogHat(RightHatX) - 128;
//      }
//      joy[10] = right_xAxis;
      joy[10] = PS4.getAnalogHat(RightHatX);
    } if (PS4.getAnalogHat(RightHatY)) {
//      if (128 >= PS4.getAnalogHat(RightHatY)) {
//        right_yAxis = -(PS4.getAnalogHat(RightHatY) - 128);
//      }
//      if (PS4.getAnalogHat(RightHatY) > 128) {
//        right_yAxis = 128 - PS4.getAnalogHat(RightHatY);
//      }
//      joy[11] = right_yAxis;
      joy[11] = PS4.getAnalogHat(RightHatY);
    }
    if (PS4.getButtonPress(UP)) {
      joy[0] = 1;
    } else if (PS4.getButtonPress(DOWN)) {
      joy[0] = -1;
    } else {
      joy[0] = 0;
    }
    if (PS4.getButtonPress(RIGHT)) {
      joy[1] = 1;
    } else if (PS4.getButtonPress(LEFT)) {
      joy[1] = -1;
    } else {
      joy[1] = 0;
    }
    if (PS4.getButtonPress(TRIANGLE)) {
      joy[2] = 1;
    } else if (PS4.getButtonPress(CROSS)) {
      joy[2] = -1;
    } else {
      joy[2] = 0;
    }
    if (PS4.getButtonPress(CIRCLE)) {
      joy[3] = 1;
    } else if (PS4.getButtonPress(SQUARE)) {
      joy[3] = -1;
    } else {
      joy[3] = 0;
    }
    if (PS4.getButtonPress(R1)) {
      joy[4] = 1;
    } else if (PS4.getButtonPress(L1)) {
      joy[4] = -1;
    } else {
      joy[4] = 0;
    }
    if (PS4.getButtonPress(OPTIONS)) {
      joy[5] = 1;
      PS4.disconnect();
    } else if (PS4.getButtonPress(SHARE)) {
      joy[5] = -1;
    } else {
      joy[5] = 0;
    }
    if (PS4.getButtonPress(TOUCHPAD)) {
      joy[6] = 1;
    } else if (PS4.getButtonPress(PS)) {
      joy[6] = -1;
    } else {
      joy[6] = 0;
    }
    if (PS4.getButtonPress(R2)) {
      joy[7] = 1;
    } else if (PS4.getButtonPress(L2)) {
      joy[7] = -1;
    } else {
      joy[7] = 0;
    }

    //    Serial.print  ("Data 1: " + (String)joy[0] +
    //                   " || Data 10: " + (String)joy[9] + " || Data 11: " + (String)joy[10] + " || Data 12: " + (String)joy[11] + " || Data 13: " + (String)joy[12]);
    //    Serial.println();
  } else {
    for (int i = 0; i < 10; i++) {
      joy[i] = 0;
    }
  }

  sendJoyData = ("#" + (String)joy[0] + "#" + (String)joy[1] + "#" + (String)joy[2] + "#" + (String)joy[3] + "#" + (String)joy[4] + "#" + (String)joy[5] +
                 "#" + (String)joy[6] + "#" + (String)joy[7] + "#" + (String)joy[8] + "#" + (String)joy[9] + "#" + (String)joy[10] + "#" + (String)joy[11]
                 + "#$");
  mySerial.write('#');
  mySerial.write(joy, 13);
  mySerial.write('$');
  //  delay(500);
}

//void sendSTM(uint8_t varSend, int sizet) {
//  if (varSend != lastSend) {
//    mySerial.write(varSend, sizet);
//    lastSend = varSend;
//    //    Serial.println();
//    Serial.write(lastSend, sizet);
//  }
//}
