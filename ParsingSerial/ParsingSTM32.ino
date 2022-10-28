char ReceiveData[40];
uint8_t data[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //  Serial.print(data.toInt());
  Serial.write('#');
  Serial.write(data, 12);
  Serial.write('$');
}

void loop() {
  // put your main code here, to run repeatedly:
  // #1#0#1#0#1#0#128#-255#255#-128#$

}
