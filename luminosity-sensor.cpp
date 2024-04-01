int green = 2;
int yellow = 3;
int red = 4;
int buzzer = 13;

void setup(){
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int LDR = analogRead(A0);
  Serial.println(LDR);
  
  if(LDR > 100 && LDR < 500){
    digitalWrite(green, HIGH);
    delay(3000);
    digitalWrite(green, LOW);
  }
  else if(LDR > 500 && LDR < 1000){
    digitalWrite(yellow, HIGH);
    tone(buzzer, 2000, 3000);
    delay(3000);
    digitalWrite(yellow, LOW); 
    noTone(buzzer);
  }else if(LDR < 100 || LDR > 1000){
    digitalWrite(red, HIGH);
    tone(buzzer, 1000, 10000);
    delay(10000);
    digitalWrite(red, LOW);
    noTone(buzzer);
  }
  
  delay(1000);
}
