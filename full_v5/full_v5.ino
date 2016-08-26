#define remote1 13  // downward
#define remote2 12  // upward
//#define remote3 8
//#define remote4 5
#define RELAY1 6
#define RELAY4 7
#define motor1 10
#define motor2 11
#define motor_en 9
#define rs1 3  // top
//#define rs2 2  // middle
#define rs3 4  // below
int num = 0;
int reedNum = 0;
int H = 1;
int L = 0;

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
  pinMode(rs3, INPUT);
  Serial.begin(9600);

  // relay openning function
  digitalWrite(RELAY1, HIGH); 
  digitalWrite(RELAY4, HIGH); 

}

void loop() {
  // put your main code here, to run repeatedly:
  // motor pausing function
  analogWrite(motor_en, 255);
  digitalWrite(motor1, HIGH); 
  digitalWrite(motor2, HIGH);

  if (digitalRead(rs1) == H) {
    reedNum = 1;
    Serial.println("WaitRemote1");
  }
  else if (digitalRead(rs3) == H) {
    reedNum = 2;
    Serial.println("WaitRemote2");
  }
//  else if (digitalRead(rs2) == H) {
//    reedNum = 3;
//    Serial.println("WaitInitial");
//  }
  else {
    reedNum = 0;
    Serial.println("NOTHING TO WAIT");
  }

  switch (reedNum) {
  case 1:
  {
  	do {
  		Serial.print(digitalRead(remote1));
  		Serial.print(digitalRead(remote2));
  		Serial.println();

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
    		Serial.println("NOTHING TO DO 1");
    		}
  	} while (num != 1);

  	if (num == 1) {
      do {
        analogWrite(motor_en, 255);
        digitalWrite(motor1, LOW); 
        digitalWrite(motor2, HIGH);
        Serial.println(digitalRead(rs3));
      } while (digitalRead(rs3) != H);

      digitalWrite(RELAY1, LOW);
      digitalWrite(RELAY4, LOW);
      
      analogWrite(motor_en, 255);
      digitalWrite(motor1, HIGH); 
      digitalWrite(motor2, HIGH);   
    }
      
  	

    num = 0;
    reedNum = 0;
    break;
  }

  case 2:
  {	
      while (num != 2) {
  		Serial.print(digitalRead(remote1));
  		Serial.print(digitalRead(remote2));
  		Serial.println();

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
    		Serial.println("NOTHING TO DO 2");
    		}
  	}

  	digitalWrite(RELAY1, HIGH); 
    digitalWrite(RELAY4, HIGH); 
    
  	if (num == 2) {
  		do {
  			analogWrite(motor_en, 255);
        digitalWrite(motor1, HIGH); 
        digitalWrite(motor2, LOW);
  			Serial.println(digitalRead(rs1));
  		} while (digitalRead(rs1) != H);
  		analogWrite(motor_en, 255);
  		digitalWrite(motor1, HIGH); 
  		digitalWrite(motor2, HIGH);   
  	}

    num = 0;
    reedNum = 0;
    break;
  }

//  case 3:
//  {
//  	while (digitalRead(rs1) != HIGH) {
//  		digitalWrite(motor_en, HIGH);
//  		digitalWrite(motor1, HIGH); 
//  		digitalWrite(motor2, LOW);
//  	}
//
//    Serial.println("Bye Bye");
//    reedNum = 0;
//    break;
//  }

  case 0:
  {
    do {
        analogWrite(motor_en, 255);
        digitalWrite(motor1, HIGH); 
        digitalWrite(motor2, LOW);
        Serial.println(digitalRead(rs1));
      } while (digitalRead(rs1) != H);
    analogWrite(motor_en, 255);
    digitalWrite(motor1, HIGH); 
    digitalWrite(motor2, HIGH); 
    
    Serial.println("Bye");
    break;
  }  

  }

}
