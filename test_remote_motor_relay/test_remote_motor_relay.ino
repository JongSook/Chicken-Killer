#define remote1  13
#define remote2  12
#define remote3  8
//#define remote4  5
#define motor_en 9
#define motor1 10
#define motor2 11
#define RELAY1  6                        
#define RELAY4  7  
int num = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(remote1, INPUT);
  pinMode(remote2, INPUT);
  pinMode(remote3, INPUT);
//  pinMode(remote4, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor_en, OUTPUT);
  pinMode(RELAY1, OUTPUT);       
  pinMode(RELAY4, OUTPUT);
  Serial.begin(9600);
  digitalWrite(RELAY1, HIGH); 
  digitalWrite(RELAY4, HIGH); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // fast stop
  digitalWrite(motor_en, HIGH);
  digitalWrite(motor1, LOW); 
  digitalWrite(motor2, LOW);

//  digitalWrite(RELAY1, HIGH); 
//  digitalWrite(RELAY4, HIGH); 

  Serial.print(digitalRead(remote1));
  Serial.print(digitalRead(remote2));
//  Serial.print(digitalRead(remote3));
//  Serial.print(digitalRead(remote4));
  Serial.println();

//  if (digitalRead(remote1) == HIGH) {
//    num = 1; 
//    // forward
//    digitalWrite(motor_en, HIGH);
//    digitalWrite(motor1, LOW); 
//    digitalWrite(motor2, HIGH);
//    digitalWrite(RELAY1, HIGH);
//    digitalWrite(RELAY4, HIGH);
//    delay(5000);
//    }
//  else if (digitalRead(remote2) == HIGH) {
//    num = 2; 
//    // backward
//    digitalWrite(motor_en, HIGH);
//    digitalWrite(motor1, HIGH); 
//    digitalWrite(motor2, LOW);  
//    digitalWrite(RELAY1, HIGH);
//    digitalWrite(RELAY4, HIGH);
//    delay(5000);
//    }
//  else if (digitalRead(remote3) == HIGH) {
//    num = 3; }
//
//  switch (num) {
//  	case 0:
//    	break;
//  	case 1:
//    	Serial.println("P1");
//    	break;
//  	case 2:
//    	Serial.println("P2");
//    	break;
//  	case 3:
//    	Serial.println("P3");
//    	break;
//  		}

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
//  }
  else {
  	num = 0;
  }

  switch (num) {
  	case 0:
      digitalWrite(RELAY1, HIGH); 
      digitalWrite(RELAY4, HIGH); 
    	break;
  	case 1:
    	// forward
    	digitalWrite(motor_en, HIGH);
    	digitalWrite(motor1, LOW); 
    	analogWrite(motor2, 63);
    	digitalWrite(RELAY1, LOW);
    	digitalWrite(RELAY4, LOW);
    	delay(5000);
      digitalWrite(RELAY1, HIGH); 
      digitalWrite(RELAY4, HIGH); 
    	break;
  	case 2:
    	// backward
    	digitalWrite(motor_en, HIGH);
    	analogWrite(motor1, 127); 
   		digitalWrite(motor2, LOW);  
    	digitalWrite(RELAY1, LOW);
    	digitalWrite(RELAY4, LOW);
    	delay(5000);
    	digitalWrite(RELAY1, HIGH); 
      digitalWrite(RELAY4, HIGH); 
    	break;
//  	case 3:
//  		// forward
//    	digitalWrite(motor_en, HIGH);
//    	digitalWrite(motor1, LOW); 
//    	analogWrite(motor2, 63);
//  		digitalWrite(RELAY1, HIGH); 
//  		digitalWrite(RELAY4, HIGH); 
//  		delay(5000);
//  		// backward
//    	digitalWrite(motor_en, HIGH);
//    	analogWrite(motor1, 127); 
//   		digitalWrite(motor2, LOW);  
//    	digitalWrite(RELAY1, HIGH);
//    	digitalWrite(RELAY4, HIGH);
//    	delay(5000);
//    	break;
  		}

  num = 0;
}
