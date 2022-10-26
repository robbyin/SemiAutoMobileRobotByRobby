////created 25 October 2022
//
///*Include library*/
//#include <PS4BT.h>
//#include <usbhub.h>
//#ifdef dobogusinclude
//#include <spi4teensy3.h>
//#endif
//#include <SPI.h>
//#include <SoftwareSerial.h>
//
///*Define Class Library*/
//USB Usb;
//BTD Btd(&Usb);
//PS4BT PS4(&Btd, PAIR);
//SoftwareSerial mySerial(4, 5); //rx tx
//
///*Define Variable*/
////Sent Char
//#define cFW 'A' //Forward
//#define cBW 'B' //Backward
//#define cR 'C' //Right
//#define cL 'D' //Left
//#define cTR 'E' //Turn Right
//#define cTL 'F' //Turn Left
//#define cFOR 'G' //Forward Oblique Right
//#define cFOL 'H' //Forward Oblique Left
//#define cBOR 'I' //Backward Oblique Right
//#define cBOL 'J' //Backward Oblique Left
//#define cSHR 'K' //Stepper Horizontal Right
//#define cSHL 'L' //Stepper Horizontal Left
//#define cSVR 'M' //Stepper Vertikal UP
//#define cSVL 'N' //Stepper Vertikal Down
//#define cSRR 'O' //Stepper Rotasi Right
//#define cSRL 'P' //Stepper Rotasi Left
//#define cSH1 'Q' //Shooter 1 Up
//#define cSH2 'R' //Shooter 2 Up
//#define cTR1 'S' //Throwing 1
//#define cTR2 'T' //Throwing 2
//#define cS '0' //Stop
//#define cC1 '1' //Command 1
//#define cC2 '2' //Command 2
//#define cDC 'Z'
//
//bool bCommand;
//bool printAngle, printTouch;
//uint8_t oldL2Value, oldR2Value;
//char lastSend;
//int joy[10];
//
///*{0, up 1 down -1
//   0, right 1 left -1
//   0, triangle 1 cross -1
//   0, circle 1 square -1
//   0, R1 1 L1 -1
//   0, option 1 share -1
//   0, touchpad 1 ps -1
//   0, R2 + L2 -
//   0, leftHatX + leftHatY - 
//   0 RightHatX + RightHatY}*/
//void setup() {
//  Serial.begin(115200);
//#if !defined(__MIPSEL__)
//  while (!Serial)
//    ;
//#endif
//  if (Usb.Init() == -1) {
//    Serial.print(F("\r\nUSB Host Shield not detected!"));
//    while (1)
//      ;
//  }
//  Serial.print(F("\r\nPS4 Bluetooth Library Started"));
//}
//
//void loop() {
//  Usb.Task();
//
//  if (PS4.connected()) {
//    if (PS4.getAnalogHat(LeftHatX) > 137
//        || PS4.getAnalogHat(LeftHatX) < 117
//        || PS4.getAnalogHat(LeftHatY) > 137
//        || PS4.getAnalogHat(LeftHatY) < 117
//        || PS4.getAnalogHat(RightHatX) > 137
//        || PS4.getAnalogHat(RightHatX) < 117
//        || PS4.getAnalogHat(RightHatY) > 137
//        || PS4.getAnalogHat(RightHatY) < 117) {
//      Serial.print(F("\r\nLeftHatX: "));
//      Serial.print(PS4.getAnalogHat(LeftHatX));
//      Serial.print(F("\tLeftHatY: "));
//      Serial.print(PS4.getAnalogHat(LeftHatY));
//      Serial.print(F("\tRightHatX: "));
//      Serial.print(PS4.getAnalogHat(RightHatX));
//      Serial.print(F("\tRightHatY: "));
//      Serial.print(PS4.getAnalogHat(RightHatY));
//      if (65 > PS4.getAnalogHat(LeftHatX) < 191 && PS4.getAnalogHat(LeftHatY) == 0) {
//        sendSTM(cFW);  //Forward
//      } else if (65 > PS4.getAnalogHat(LeftHatX) < 191 && PS4.getAnalogHat(LeftHatY) == 255) {
//        sendSTM(cBW);  //Backward
//      } else if (PS4.getAnalogHat(LeftHatX) == 255 && 65 > PS4.getAnalogHat(LeftHatY) < 191) {
//        sendSTM(cR);  //Backward
//      } else if (PS4.getAnalogHat(LeftHatX) == 0 && 65 > PS4.getAnalogHat(LeftHatY) < 191) {
//        sendSTM(cL);  //Backward
//      } else if (PS4.getAnalogHat(RightHatX) > 128 && PS4.getAnalogHat(RightHatY) < 128) {
//        sendSTM(cFOR);  //Forward Oblique Right
//      } else if (PS4.getAnalogHat(RightHatX) < 128 && PS4.getAnalogHat(RightHatY) < 128) {
//        sendSTM(cFOL);  //Forward Oblique Left
//      } else if (PS4.getAnalogHat(RightHatX) > 128 && PS4.getAnalogHat(RightHatY) > 128) {
//        sendSTM(cBOR);  //Backward oblique Right
//      } else if (PS4.getAnalogHat(RightHatX) < 128 && PS4.getAnalogHat(RightHatY) > 128) {
//        sendSTM(cBOL);  //Backward Oblique Left
//      }
//    }
//
//    else if (PS4.getAnalogButton(L2) || PS4.getAnalogButton(R2)) {  // These are the only analog buttons on the PS4 controller
//      Serial.print(F("\r\nL2: "));
//      Serial.print(PS4.getAnalogButton(L2));
//      Serial.print(F("\tR2: "));
//      Serial.print(PS4.getAnalogButton(R2));
//      if (PS4.getAnalogButton(L2) != oldL2Value || PS4.getAnalogButton(R2) != oldR2Value)  // Only write value if it's different
//                                                                                           //        PS4.setRumbleOn(PS4.getAnalogButton(L2), PS4.getAnalogButton(R2));
//        oldL2Value = PS4.getAnalogButton(L2);
//      oldR2Value = PS4.getAnalogButton(R2);
//      if (PS4.getAnalogButton(L2) == 0 && PS4.getAnalogButton(R2) != 0) {
//        sendSTM(cTR);
//      } else if (PS4.getAnalogButton(L2) != 0 && PS4.getAnalogButton(R2) == 0) {
//        sendSTM(cTL);
//      }
//      //      sendSTM(cFW);
//    }
//
//
//    else if (PS4.getButtonClick(PS)) {
//      Serial.print(F("\r\nPS"));
//
//    }
//    //    else {
//    else if (PS4.getButtonClick(TRIANGLE)) {
//      Serial.print(F("\r\nTriangle"));
//      //      PS4.setRumbleOn(RumbleLow);
//      PS4.setLed(Red);
//      PS4.getBatteryLevel();
//    } else if (PS4.getButtonClick(CIRCLE)) {
//      Serial.print(F("\r\nCircle"));
//      PS4.setLed(Blue);
//      sendSTM(cTR2);
//    } else if (PS4.getButtonClick(CROSS)) {
//      Serial.print(F("\r\nCross"));
//      PS4.setLed(Green);
//      sendSTM(cS);
//    } else if (PS4.getButtonClick(SQUARE)) {
//      Serial.print(F("\r\nSquare"));
//      PS4.setLed(Yellow);
//      sendSTM(cTR1);
//    }
//
//    else if (PS4.getButtonPress(UP)) {
//      Serial.print(F("\r\nUp"));
//      sendSTM(cFW);
//    } else if (PS4.getButtonPress(RIGHT)) {
//      Serial.print(F("\r\nRight"));
//      sendSTM(cR);
//    } else if (PS4.getButtonPress(DOWN)) {
//      Serial.print(F("\r\nDown"));
//      sendSTM(cBW);
//    } else if (PS4.getButtonPress(LEFT)) {
//      Serial.print(F("\r\nLeft"));
//      sendSTM(cL);
//    } else if (PS4.getButtonPress(L1))
//      Serial.print(F("\r\nL1"));
//    else if (PS4.getButtonClick(L3))
//      Serial.print(F("\r\nL3"));
//    else if (PS4.getButtonPress(R1))
//      Serial.print(F("\r\nR1"));
//    else if (PS4.getButtonClick(R3))
//      Serial.print(F("\r\nR3"));
//
//    else if (PS4.getButtonClick(SHARE))
//      Serial.print(F("\r\nShare"));
//    else if (PS4.getButtonClick(OPTIONS)) {
//      Serial.print(F("\r\nOptions"));
//      PS4.disconnect();
//      printAngle = !printAngle;
//    } else sendSTM(cS);
//  } else {
//    sendSTM(cDC); 
//  }
//}
//
//void sendSTM(char cVal) {
// if (cVal != lastSend) {
//   mySerial.print(cVal);
//   lastSend = cVal;
//   Serial.println();
//   Serial.print(lastSend);
// }
//}
