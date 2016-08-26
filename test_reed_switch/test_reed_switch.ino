#define rs1 2
//#define rs2 3
#define rs3 3
//#define motor1 10
//#define motor2 11
//#define motor_en 9
int num = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(rs1, INPUT);
//  pinMode(rs2, INPUT);
  pinMode(rs3, INPUT);

//  pinMode(motor1, OUTPUT);
// pinMode(motor2, OUTPUT);
//  pinMode(motor_en, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
//  do { 
  Serial.print(digitalRead(rs1));
//  Serial.print(digitalRead(rs2));
  Serial.print(digitalRead(rs3));
  Serial.println();
//    } while (digitalRead(rs1) != HIGH);
//    num = num+1;
//  delay(100);

//  if (digitalRead(rs1) == HIGH) {
//    num = 1; 
//    digitalWrite(motor_en, HIGH);
//    digitalWrite(motor1, LOW); 
//    digitalWrite(motor2, HIGH);
//    }
//  else if (digitalRead(rs2) == HIGH) {
//    num = 2; 
//    digitalWrite(motor_en, HIGH);
//    digitalWrite(motor1, HIGH); 
//    digitalWrite(motor2, LOW);  
//    }
//  else if (digitalRead(rs3) == HIGH) {
//  	digitalWrite(motor_en, HIGH);
//  	digitalWrite(motor1, LOW); 
// 	digitalWrite(motor2, LOW);
//    num = 3; }
//  switch (num) {
//    case 1:
//      Serial.println("RS1");
//      break;
//    case 2:
//      Serial.println("RS2");
//      break;
//    case 3:
//      Serial.println("RS3");
//      break;
//  }
//  num = 0;
  delay(100);
}
