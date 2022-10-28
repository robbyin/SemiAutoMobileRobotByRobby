//int joy[10]={
//  0, 0, 0, 0,
//  0, 0, 0, 0,
//  0, 0
//};
//bool parsing = false;
//String sData, data[11];
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(115200);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  // #1#0#1#0#1#0#128#-255#255#-128#$
//  while (Serial.available()) {
//    char inChar = Serial.read();
//    sData += inChar;
//    if (inChar == '$') {
//      parsing = true;
//    }
//    if (parsing) {
//      int q = 0;
//      for (int i = 0; i < sData.length(); i++) {
//        if (sData[i] == '#') {
//          q++;
//          data[q] = "";
//        } else {
//          data[q] += sData[i];
//        }
//      }
//      Serial.println("Data 1: " + data[1]);
//      Serial.println("Data 2: " + data[2]);
//      Serial.println("Data 3: " + data[3]);
//      Serial.println("Data 4: " + data[4]);
//      Serial.println("Data 5: " + data[5]);
//      Serial.println("Data 6: " + data[6]);
//      Serial.println("Data 7: " + data[7]);
//      Serial.println("Data 8: " + data[8]);
//      Serial.println("Data 9: " + data[9]);
//      Serial.println("Data 10: " + data[10]);
//      Serial.println();
//    }
//  }
//
//
//    joy[0] = 1;
//    joy[1] = 0;
//    joy[2] = 1;
//    joy[3] = 0;
//    joy[4] = 1;
//    joy[5] = 0;
//    joy[6] = 128;
//    joy[7] = -255;
//    joy[8] = 255;
//    joy[9] = -128;
//  //  for(int i=0; i<10; i++){
//  //    mySerial(joy[i]);
//  //  }
//  Serial.println("#"+(String)joy[0]+"#"+(String)joy[1]+"#"+(String)joy[2]+"#"+(String)joy[3]+"#"+(String)joy[4]+"#"+(String)joy[5]+
//                    "#"+(String)joy[6]+"#"+(String)joy[7]+"#"+(String)joy[8]+"#"+(String)joy[9]+"#$");
//  delay(1000);
//}
//
//void mySerial(int sendInt) {
//  Serial.println(sendInt);
//}
