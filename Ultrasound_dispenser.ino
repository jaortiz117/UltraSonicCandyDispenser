int blue = 5;
int green = 0;
int red = 4;

void setup() {
  // put your setup code here, to run once:
 pinMode(blue, OUTPUT);
 pinMode(green, OUTPUT);
 pinMode(red, OUTPUT);
 usSetup();
 servoSetup();
 
}

void loop() {

  //float distance;
  bool numpad;

  //numpad = keyStatus();//saves keypad status
  
  while(numpad != true){
    digitalWrite(red, HIGH);
    numpad = keyStatus();//saves keypad status
  }
  digitalWrite(red, LOW);
  
  if(numpad == true){
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
    numpad = false;
    
  } else{
    digitalWrite(red, HIGH);
    delay(1000);
    digitalWrite(red, LOW);;
  }
  
  //distance = usDistance();//saves ultrasonic distance
  
  /***************
  // put your main code here, to run repeatedly:
  digitalWrite(blue, HIGH);
  delay(1000);
  digitalWrite(blue, LOW);
  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW); 
  
 ****/

 
}
