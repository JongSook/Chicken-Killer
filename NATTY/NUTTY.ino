#define remote1     13      //  downward
#define remote2     12      //  upward
#define RELAY1      6       //  positive voltage
#define RELAY4      7       //  negative voltage
#define motor1      10      //  clockwise
#define motor2      11      //  counter clockwise
#define motor_en    9       //  motor main energy
#define rs1         2       //  above reed switch
#define rs3         3       //  below reed switch
int num           = 0;      //
int reedNum       = 0;      //

// relay function
void relayControl(int relayS1, int relayS2){
  digitalWrite(RELAY1, relayS1);
  digitalWrite(RELAY4, relayS2);  
}

// motor function
void motorControl(int enMotor, int motorS1, int motorS2){
  analogWrite(motor_en, enMotor);
  digitalWrite(motor1, motorS1); 
  digitalWrite(motor2, motorS2);  
}

// TIME pause function 
void triggerRELAY(int trigTime){   
  motorControl(255, HIGH, HIGH); 
  delay(trigTime);
  relayControl(HIGH, HIGH);
  Serial.println(trigTime);
}

void setup() {
  // serial
  Serial.begin(9600);

  // remote input
  pinMode(remote1, INPUT);
  pinMode(remote2, INPUT);
  //  pinMode(remote3, INPUT);
  //  pinMode(remote4, INPUT);

  // reelay control
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  // motor control
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor_en, OUTPUT);

  // reed switch input
  pinMode(rs1, INPUT);
  pinMode(rs3, INPUT);

  // relay openning
  relayControl(HIGH, HIGH);
}

void loop() {
  // start motor
  motorControl(255, HIGH, HIGH); 

  // set to zero point
  if(digitalRead(rs1) == LOW){
    reedNum = 1;
    Serial.println("WaitRemote1");
  }
  else{
    reedNum = 0;
    Serial.println("FIND ZERO POINT");
  }

  switch(reedNum){
  case 1:{
    do{
      Serial.print(digitalRead(remote1));
      Serial.print(digitalRead(remote2));
      Serial.println();

      if(digitalRead(remote1) == HIGH){
        num = 1;
        Serial.println("P1");
      }
      else if(digitalRead(remote2) == HIGH){
        num = 2;
        Serial.println("P2");
      }
      else{
        num = 0;
        Serial.println("NOTHING TO DO");
        }
    }while(num == 0);

    if(num == 1){
      relayControl(LOW, LOW); 
      for(int i=0; i<=256; i=i+63){
        motorControl(i, HIGH, LOW); 
        delay(50);
      }
      do{
        motorControl(255, HIGH, LOW); 
        Serial.println(digitalRead(rs3));
      }while(digitalRead(rs3) == HIGH);

      triggerRELAY(10000);

      for(int i=0; i<=256; i=i+63){
        motorControl(i, LOW, HIGH); 
        delay(50);
      }
      do{
        motorControl(255, LOW, HIGH);
        Serial.println(digitalRead(rs1));
      }while(digitalRead(rs1) == HIGH);
      
      motorControl(255, HIGH, HIGH);     
    }

    else if(num == 2){
      relayControl(LOW, LOW); 
      for(int i=0; i<=256; i=i+63){
        motorControl(i, HIGH, LOW); 
        delay(50);
      }
      do{
        motorControl(255, HIGH, LOW); 
        Serial.println(digitalRead(rs3));
      }while(digitalRead(rs3) == HIGH);

      triggerRELAY(6000);

      for(int i=0; i<=256; i=i+63){
        motorControl(i, LOW, HIGH); 
        delay(50);
      }
      do{
        motorControl(255, LOW, HIGH);
        Serial.println(digitalRead(rs1));
      }while(digitalRead(rs1) == HIGH);
      
      motorControl(255, HIGH, HIGH);  
    }
      
    num     = 0;
    reedNum = 0;
    Serial.println("DONE");
    break;
  }

  case 0:{
    delay(3000);

    do{
      for(int i=0; i<=256; i=i+63){
        motorControl(i, LOW, HIGH); 
        delay(50);
      }
    }while(digitalRead(rs1) == HIGH);
    
    while(digitalRead(rs1) == HIGH) {
        motorControl(255, LOW, HIGH);
        Serial.println(digitalRead(rs1));
      } 
    motorControl(255, HIGH, HIGH);

    num     = 0;
    reedNum = 0;
    Serial.println("Bye Bye");
    break;
  }  

  }
}

