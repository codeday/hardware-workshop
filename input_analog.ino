//#--------------------------------------------------------------------------------------#
//| Thanks to Digikey for providing the kits and helping us make this an amazing CodeDay!|
//#--------------------------------------------------------------------------------------#

char rotary = A0;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(rotary);
  Serial.println(value);
}
