//#--------------------------------------------------------------------------------------#
//| Thanks to Digikey for providing the kits and helping us make this an amazing CodeDay!|
//#--------------------------------------------------------------------------------------#

char led = 4;
char button = 6;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (digitalRead(button) == HIGH) {
      digitalWrite(led, HIGH);
    }
    else {
      digitalWrite(led, LOW);
    }
}
