
#define remote1  13
#define remote2  12
#define remote3  8
#define motor1 10
#define motor2 11
#define motor_en 9
//#define remote4  5
int num = 0;

void setup()
{
  pinMode(remote1, INPUT);
  pinMode(remote2, INPUT);
  pinMode(remote3, INPUT);
//  pinMode(remote4, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor_en, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, LOW); 
//  digitalWrite(motor2, LOW);

  Serial.print(digitalRead(remote1));
  Serial.print(digitalRead(remote2));
  Serial.print(digitalRead(remote3));
//  Serial.print(digitalRead(remote4));
  Serial.println();
//  delay(100);

//  if (digitalRead(remote1) == HIGH) {
//    num = 1; 
//    digitalWrite(motor_en, HIGH);
//    digitalWrite(motor1, LOW); 
//    digitalWrite(motor2, HIGH);
//    }
//  else if (digitalRead(remote2) == HIGH) {
//    num = 2; 
//    digitalWrite(motor_en, HIGH);
//    digitalWrite(motor1, HIGH); 
//    digitalWrite(motor2, LOW);  
//    }
//  else if (digitalRead(remote3) == HIGH) {
//    num = 3; }
    
  switch (num) {
    case 0:
      break;
    case 1:
      Serial.println("P1");
      break;
    case 2:
      Serial.println("P2"); 
      break;
    case 3:
      Serial.println("P3");
      break;
  }
  num = 0;
//  delay(1000);
}
