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
#define rs2 2  // middle
#define rs3 4  // below
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

  // relay openning function
  digitalWrite(RELAY1, HIGH); 
  digitalWrite(RELAY4, HIGH); 

}

void loop() {
  // put your main code here, to run repeatedly:
  // motor pausing function
  digitalWrite(motor_en, HIGH);
  digitalWrite(motor1, LOW); 
  digitalWrite(motor2, LOW);

  if (digitalRead(rs1) == HIGH) {
  	while (num == 1) {
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
  	}

  	if (num == 1) {
  		while (digitalRead(rs2) == HIGH) {
  			digitalWrite(motor_en, HIGH);
       		digitalWrite(motor1, LOW); 
        	digitalWrite(motor2, HIGH);
        	Serial.println(rs2);
  		}
  		do {
  			digitalWrite(motor_en, HIGH);
  			digitalWrite(motor1, LOW);
  			digitalWrite(motor2, 127);
  			Serial.println(rs3);
  			if (digitalRead(rs3) == HIGH) {
  				digitalWrite(RELAY1, LOW);
          		digitalWrite(RELAY4, LOW);
  			}
  			else if (digitalRead(rs3) == LOW) {
  				digitalWrite(RELAY1, HIGH);
          		digitalWrite(RELAY4, HIGH);
  			}
  		} while (digitalRead(rs3) == HIGH);
  		digitalWrite(motor_en, HIGH);
  		digitalWrite(motor1, LOW); 
  		digitalWrite(motor2, LOW);
  	}
  }

  if (digitalRead(rs3) == HIGH) {
  	while (num == 2) {
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
  		while (digitalRead(rs2) == HIGH) {
  			digitalWrite(motor_en, HIGH);
       		digitalWrite(motor1, HIGH); 
        	digitalWrite(motor2, LOW);
        	Serial.println(rs2);
  		}
  		digitalWrite(motor_en, HIGH);
  		digitalWrite(motor1, LOW); 
  		digitalWrite(motor2, LOW);
  	}
  }

  num = 0;

}
