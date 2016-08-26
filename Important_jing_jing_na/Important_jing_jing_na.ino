#define remote1 13
#define remote2 12
//#define remote3 8
//#define remote4  5
#define RELAY1 6
#define RELAY4 7
#define motor1 10
#define motor2 11
#define motor_en 9
#define rs1 3
//#define rs2 3
//#define rs3 4
int num = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(remote1, INPUT);
  pinMode(remote2, INPUT);
//  pinMode(remote3, INPUT);
//  pinMode(remote4, INPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor_en, OUTPUT);
  pinMode(rs1, INPUT);
//  pinMode(rs2, INPUT);
//  pinMode(rs3, INPUT);
  Serial.begin(9600);

  // open relay
  digitalWrite(RELAY1, HIGH); 
  digitalWrite(RELAY4, HIGH); 

}

void loop() {
  // put your main code here, to run repeatedly:
  // pause motor
  digitalWrite(motor_en, HIGH);
  digitalWrite(motor1, LOW); 
  digitalWrite(motor2, LOW);

//  // open relay
//  digitalWrite(RELAY1, HIGH); 
//  digitalWrite(RELAY4, HIGH); 
  
  // check remote number
  Serial.print(digitalRead(remote1));
  Serial.print(digitalRead(remote2));
//  Serial.print(digitalRead(remote3));
//  Serial.print(digitalRead(remote4));
  Serial.println();

  // loop for remote number checking 
  if (digitalRead(remote1) == HIGH) {
    num = 1; 
    Serial.println("P1");
    }
  else if (digitalRead(remote2) == HIGH) {
    num = 2; 
    Serial.println("P2");
    }
//  else if (digitalRead(remote3) == HIGH) {
//    num = 3; 
//    Serial.println("P3");
//    }
  else {
    num = 0;
    Serial.println("NOTHING TO DO");
    }

  // command loop
  switch (num) {
    case 0:
      digitalWrite(motor_en, HIGH);
      digitalWrite(motor1, LOW); 
      digitalWrite(motor2, LOW);
      digitalWrite(RELAY1, HIGH); 
      digitalWrite(RELAY4, HIGH); 
      break;

    case 1:
      do {
        digitalWrite(motor_en, HIGH);
        digitalWrite(motor1, LOW); 
        digitalWrite(motor2, HIGH);
        Serial.println(rs1);
        } while (digitalRead(rs1) == HIGH);
      do {
        digitalWrite(motor_en, HIGH);
        digitalWrite(motor1, LOW); 
        analogWrite(motor2, 63);
        Serial.println(rs1);
        if (digitalRead(rs1) == HIGH) {
          digitalWrite(RELAY1, LOW);
          digitalWrite(RELAY4, LOW);
          }
        else if (digitalRead(rs1) == LOW) {
          digitalWrite(RELAY1, HIGH);
          digitalWrite(RELAY4, HIGH);
          }
        } while (digitalRead(rs1) == HIGH);
      delay(5000);  
      digitalWrite(motor_en, HIGH);
      digitalWrite(motor1, LOW); 
      digitalWrite(motor2, LOW);  
      digitalWrite(RELAY1, HIGH); 
      digitalWrite(RELAY4, HIGH); 
      break;

    case 2:
      do {
        digitalWrite(motor_en, HIGH);
        digitalWrite(motor1, HIGH); 
        digitalWrite(motor2, LOW);
        Serial.println(rs1);
        } while (digitalRead(rs1) == HIGH);
      do {
        digitalWrite(motor_en, HIGH);
        analogWrite(motor1, 63); 
        digitalWrite(motor2, LOW);
        Serial.println(rs1);
        } while (digitalRead(rs1) == HIGH);
      delay(5000);
      digitalWrite(motor_en, HIGH);
      digitalWrite(motor1, LOW); 
      digitalWrite(motor2, LOW);
      digitalWrite(RELAY1, HIGH); 
      digitalWrite(RELAY4, HIGH); 
      break;

//    case 3:
//      digitalWrite(motor_en, HIGH);
//      digitalWrite(motor1, LOW); 
//      digitalWrite(motor2, LOW);
//      digitalWrite(RELAY1, HIGH); 
//      digitalWrite(RELAY4, HIGH); 
//      break;
      }

  // reset num value
  num = 0;

  // old algorithm
//  Serial.print(digitalRead(remote1));
//  Serial.print(digitalRead(remote2));
//  Serial.print(digitalRead(remote3));
//  Serial.println();
//  
//  if (digitalRead(remote1) == HIGH) {
//    num = 1; }
//  else if (digitalRead(remote2) == HIGH) {
//    num = 2; }
//  else if (digitalRead(remote3) == HIGH) {
//    num = 3; }
//  
//  switch (num) {
//    case 1:
//      do {
//        digitalWrite(motor_en, HIGH);
//        digitalWrite(motor1, LOW); 
//        digitalWrite(motor2, HIGH);
//        } while (digitalRead(rs2) == LOW);
//      do {
//        digitalWrite(motor_en, HIGH);
//        digitalWrite(motor1, LOW); 
//        analogWrite(motor2, 128);
//        } while (digitalRead(rs3) == LOW);
//      digitalWrite(motor_en, HIGH);
//      digitalWrite(motor1, LOW); 
//      digitalWrite(motor2, LOW);  
//      break;
//  
//    case 2:
//      do {
//        digitalWrite(motor_en, HIGH);
//        digitalWrite(motor1, HIGH); 
//        digitalWrite(motor2, LOW);
//        } while (digitalRead(rs2) == LOW);
//      do {
//        digitalWrite(motor_en, HIGH);
//        analogWrite(motor1, 128); 
//        digitalWrite(motor2, LOW);
//        } while (digitalRead(rs1) == LOW);
//      digitalWrite(motor_en, HIGH);
//      digitalWrite(motor1, LOW); 
//      digitalWrite(motor2, LOW);
//      break;
//      
//    case 3:
//      break;
//  }
//  
//  num = 0;  

}
