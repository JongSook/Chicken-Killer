 #define motor_en 9
#define motor1 10
#define motor2 11
int num = 0;
#define remote1 13  // downward
#define remote2 12  // upward
//#define remote3 8
//#define remote4 5
#define RELAY1  6                        
//#define RELAY2  7                        
//#define RELAY3  8                        
#define RELAY4  7
 
void setup() {
  // put your setup code here, to run once:
  pinMode(motor_en, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);

  pinMode(remote1, INPUT);
  pinMode(remote2, INPUT);

  pinMode(RELAY1, OUTPUT);       
  //pinMode(RELAY2, OUTPUT);
  //pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  digitalWrite(RELAY1, HIGH); 
  digitalWrite(RELAY4, HIGH); 

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(RELAY1, HIGH); 
  digitalWrite(RELAY4, HIGH); 

  // fast stop
//  delay(1000);
  digitalWrite(motor_en, HIGH);
  digitalWrite(motor1, HIGH); 
  digitalWrite(motor2, HIGH);

  if (digitalRead(remote1) == HIGH) {
        num = 1;
        Serial.println("P1");
      }
      else if (digitalRead(remote2) == HIGH) {
        num = 2;
        Serial.println("P2");
      }
      else {
        num = 0;
        Serial.println("NOTHING TO DO");
        }

  switch (num) {
  case 1: {
    // backward // down
    delay(2000);
    analogWrite(motor_en, 63);
    digitalWrite(motor1, 1); 
    digitalWrite(motor2, 0);

    delay(1000);
    analogWrite(motor_en, 127);
    digitalWrite(motor1, 1); 
    digitalWrite(motor2, 0);

    delay(1000);
    analogWrite(motor_en, 255);
    digitalWrite(motor1, 1); 
    digitalWrite(motor2, 0);

    digitalWrite(RELAY1,LOW);                                   // Wait 2 seconds
    digitalWrite(RELAY4,LOW);         
    
    Serial.println("Go First");

    delay(500);
    break;
    }

  case 2: {
    // forward // up
    delay(1000);
    for (int i=0; i <= 255; i = i+1){
    analogWrite(motor_en, i);
    digitalWrite(motor1, 0); 
    digitalWrite(motor2, 1);
    delay(2);
    }

    digitalWrite(RELAY1,LOW);                                   // Wait 2 seconds
    digitalWrite(RELAY4,LOW); 
    
    Serial.println("Go Second");
    
    delay(1000);
    break;
    }

  case 0:{
//    // backward // down
//    delay(1000);
//    digitalWrite(motor_en, HIGH);
//    digitalWrite(motor1, HIGH); 
//    digitalWrite(motor2, LOW);
//    delay(1000);
//
//    // forward // up
//    delay(1000);
//    digitalWrite(motor_en, HIGH);
//    digitalWrite(motor1, LOW); 
//    digitalWrite(motor2, HIGH);
//    analogWrite(motor2, 127);
//    delay(1000);

  }

  }

  num = 0;

//  // fast stop
//  delay(1000);
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, HIGH); 
//  digitalWrite(motor2, HIGH);
  
//  // backward // down
//  delay(1000);
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, HIGH); 
//  digitalWrite(motor2, LOW);

  // fast stop
//  delay(5000);
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, LOW); 
//  digitalWrite(motor2, LOW);

//    // fast stop
//  delay(1000);
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, LOW); 
//  digitalWrite(motor2, LOW);
  
//  // forward // up
//  delay(1000);
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, LOW); 
//  digitalWrite(motor2, HIGH);
//  analogWrite(motor2, 127);

  // fast stop
//  delay(2000);
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, LOW); 
//  digitalWrite(motor2, LOW);
  
  

//  // fast stop
//  delay(1000);
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, LOW); 
//  digitalWrite(motor2, LOW);

//  // forward
//  delay(1000);
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, LOW); 
//  //digitalWrite(motor2, HIGH);
//  analogWrite(motor2, 63);

//  // fast stop
//  delay(1000);
//  digitalWrite(motor_en, HIGH);
//  digitalWrite(motor1, HIGH); 
//  digitalWrite(motor2, HIGH);
    
}
