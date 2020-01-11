#define moteur1_IN1  2
#define moteur1_IN2  3
#define moteur1_IN3  4
#define moteur1_IN4  5

#define moteur2_IN1 8
#define moteur2_IN2 9
#define moteur2_IN3 10
#define moteur2_IN4 11

#define moteur3_IN1 14
#define moteur3_IN2 15
#define moteur3_IN3 16
#define moteur3_IN4 17

int temps =10; 
int i=0;

void setup(){
Serial.begin(115200);

pinMode(moteur1_IN1, OUTPUT); 
pinMode(moteur1_IN2, OUTPUT);
pinMode(moteur1_IN3, OUTPUT); 
pinMode(moteur1_IN4, OUTPUT);

pinMode(moteur2_IN1, OUTPUT); 
pinMode(moteur2_IN2, OUTPUT);
pinMode(moteur2_IN3, OUTPUT); 
pinMode(moteur2_IN4, OUTPUT);

pinMode(moteur3_IN1, OUTPUT); 
pinMode(moteur3_IN2, OUTPUT);
pinMode(moteur3_IN3, OUTPUT); 
pinMode(moteur3_IN4, OUTPUT);
}

void loop{
for(i=0; i <= 10; i++){
Serial.println(i); 

digitalWrite(moteur1_IN1, LOW);
digitalWrite(moteur1_IN2, LOW);
digitalWrite(moteur1_IN3, LOW);
digitalWrite(moteur1_IN4, HIGH);
delay(temps);
digitalWrite(moteur1_IN1, LOW);
digitalWrite(moteur1_IN2, LOW);
digitalWrite(moteur1_IN3, HIGH);
digitalWrite(moteur1_IN4, LOW);
delay(temps);
digitalWrite(moteur1_IN1, LOW); 
digitalWrite(moteur1_IN2, HIGH);
digitalWrite(moteur1_IN3, LOW);
digitalWrite(moteur1_IN4, LOW);
delay(temps);
digitalWrite(moteur1_IN1, HIGH); 
digitalWrite(moteur1_IN2, LOW);
digitalWrite(moteur1_IN3, LOW);
digitalWrite(moteur1_IN4, LOW);
delay(temps);

digitalWrite(moteur2_IN1, LOW);
digitalWrite(moteur2_IN2, LOW);
digitalWrite(moteur2_IN3, LOW);
digitalWrite(moteur2_IN4, HIGH);
delay(temps);
digitalWrite(moteur2_IN1, LOW);
digitalWrite(moteur2_IN2, LOW);
digitalWrite(moteur2_IN3, HIGH);
digitalWrite(moteur2_IN4, LOW);
delay(temps);
digitalWrite(moteur2_IN1, LOW); 
digitalWrite(moteur2_IN2, HIGH);
digitalWrite(moteur2_IN3, LOW);
digitalWrite(moteur2_IN4, LOW);
delay(temps);
digitalWrite(moteur2_IN1, HIGH); 
digitalWrite(moteur2_IN2, LOW);
digitalWrite(moteur2_IN3, LOW);
digitalWrite(moteur2_IN4, LOW);
delay(temps);
/*
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
delay(temps);
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
delay(temps);
digitalWrite(IN1, LOW); 
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
delay(temps);
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
delay(temps);*/
}
}
