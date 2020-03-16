#define moteur1_IN1  2
#define moteur1_IN2  3
#define moteur1_IN3  4
#define moteur1_IN4  5
#define moteur2_IN1  6
#define moteur2_IN2  7
#define moteur2_IN3  8
#define moteur2_IN4  9
#define moteur3_IN1  14
#define moteur3_IN2  15
#define moteur3_IN3  16
#define moteur3_IN4  17
#define moteur4_IN1  18
#define moteur4_IN2  19
#define moteur4_IN3  20
#define moteur4_IN4  21
int temps =10;

#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
int sortieAnal=0;
int anal;

#include <SoftwareSerial.h>;
#define RX 12
#define TX 13
SoftwareSerial mySerial(RX,TX);
static int8_t Send_buf[8] = {0} ;
#define NEXT_SONG 0X01  
#define PREV_SONG 0X02  
#define CMD_PLAY_W_INDEX 0X03 //DATA IS REQUIRED (number of song) 
#define VOLUME_UP_ONE 0X04 
#define VOLUME_DOWN_ONE 0X05 
#define CMD_SET_VOLUME 0X06//DATA IS REQUIRED (number of volume from 0 up to 30(0x1E)) 
#define SET_DAC 0X17 
#define CMD_PLAY_WITHVOLUME 0X22 //data is needed  0x7E 06 22 00 xx yy EF;(xx volume)(yy number of song) 
#define CMD_SEL_DEV 0X09 //SELECT STORAGE DEVICE, DATA IS REQUIRED 
#define DEV_TF 0X02 //HELLO,IM THE DATA REQUIRED 
#define SLEEP_MODE_START 0X0A 
#define SLEEP_MODE_WAKEUP 0X0B 
#define CMD_RESET 0X0C//CHIP RESET 
#define CMD_PLAY 0X0D //RESUME PLAYBACK 
#define CMD_PAUSE 0X0E //PLAYBACK IS PAUSED 
#define CMD_PLAY_WITHFOLDER 0X0F//DATA IS NEEDED, 0x7E 06 0F 00 01 02 EF;(play the song with the directory \01\002xxxxxx.mp3 
#define STOP_PLAY 0X16 
#define PLAY_FOLDER 0X17// data is needed 0x7E 06 17 00 01 XX EF;(play the 01 folder)(value xx we dont care) 
#define SET_CYCLEPLAY 0X19//data is needed 00 start; 01 close 
#define SET_DAC 0X17//data is needed 00 start DAC OUTPUT;01 DAC no output 

#include <Adafruit_NeoPixel.h> // Charge la librairie Neo Pixel d'Adafruit utilisé pour piloter le ruban de LED
#define PIXEL_PIN A1// On définit le pin où est connecté la patte DATA du bandeau
#define PIXEL_COUNT 66 // On définit le nombre de LED compris sur le Ruban de LED 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800); // Paramètre l'objet strip qui correspond à toute les LED du ruban

char Var;

////////////////////////////////////////////////////////////////////////////////////  

void sendCommand(int8_t command, int16_t dat) { 
  delay(20); 
  Send_buf[0] = 0x7e; //starting byte 
  Send_buf[1] = 0xff; //version 
  Send_buf[2] = 0x06; //the number of bytes of the command without starting byte and ending byte 
  Send_buf[3] = command; // 
  Send_buf[4] = 0x00;//0x00 = no feedback, 0x01 = feedback 
  Send_buf[5] = (int8_t)(dat >> 8);//datah 
  Send_buf[6] = (int8_t)(dat); //datal 
  Send_buf[7] = 0xef; //ending byte 
  for(uint8_t i=0; i<8; i++){ 
    mySerial.write(Send_buf[i]) ; 
  } 
} 
//////////////////////////////////////////////////////////////////////////////////
void pas_1(){
  for(int i=0; i <= 550; i++){
  /*ON DESCEND L'OBJET*/
  digitalWrite(moteur1_IN1, LOW);
  digitalWrite(moteur1_IN2, LOW);
  digitalWrite(moteur1_IN3, LOW);
  digitalWrite(moteur1_IN4, HIGH);

  digitalWrite(moteur2_IN1, LOW);
  digitalWrite(moteur2_IN2, LOW);
  digitalWrite(moteur2_IN3, LOW);
  digitalWrite(moteur2_IN4, HIGH);

  digitalWrite(moteur3_IN1, LOW);
  digitalWrite(moteur3_IN2, LOW);
  digitalWrite(moteur3_IN3, LOW);
  digitalWrite(moteur3_IN4, HIGH);

  digitalWrite(moteur4_IN1, LOW);
  digitalWrite(moteur4_IN2, LOW);
  digitalWrite(moteur4_IN3, LOW);
  digitalWrite(moteur4_IN4, HIGH);


  delay(temps);

  digitalWrite(moteur1_IN1, LOW);
  digitalWrite(moteur1_IN2, LOW);
  digitalWrite(moteur1_IN3, HIGH);
  digitalWrite(moteur1_IN4, LOW);

  digitalWrite(moteur2_IN1, LOW);
  digitalWrite(moteur2_IN2, LOW);
  digitalWrite(moteur2_IN3, HIGH);
  digitalWrite(moteur2_IN4, LOW);

  digitalWrite(moteur3_IN1, LOW);
  digitalWrite(moteur3_IN2, LOW);
  digitalWrite(moteur3_IN3, HIGH);
  digitalWrite(moteur3_IN4, LOW);

  digitalWrite(moteur4_IN1, LOW);
  digitalWrite(moteur4_IN2, LOW);
  digitalWrite(moteur4_IN3, HIGH);
  digitalWrite(moteur4_IN4, LOW);


  delay(temps);

  digitalWrite(moteur1_IN1, LOW); 
  digitalWrite(moteur1_IN2, HIGH);
  digitalWrite(moteur1_IN3, LOW);
  digitalWrite(moteur1_IN4, LOW);

  digitalWrite(moteur2_IN1, LOW); 
  digitalWrite(moteur2_IN2, HIGH);
  digitalWrite(moteur2_IN3, LOW);
  digitalWrite(moteur2_IN4, LOW);

  digitalWrite(moteur3_IN1, LOW); 
  digitalWrite(moteur3_IN2, HIGH);
  digitalWrite(moteur3_IN3, LOW);
  digitalWrite(moteur3_IN4, LOW);

  digitalWrite(moteur4_IN1, LOW);
  digitalWrite(moteur4_IN2, HIGH);
  digitalWrite(moteur4_IN3, LOW);
  digitalWrite(moteur4_IN4, LOW);


  delay(temps);

  digitalWrite(moteur1_IN1, HIGH); 
  digitalWrite(moteur1_IN2, LOW);
  digitalWrite(moteur1_IN3, LOW);
  digitalWrite(moteur1_IN4, LOW);

  digitalWrite(moteur2_IN1, HIGH); 
  digitalWrite(moteur2_IN2, LOW);
  digitalWrite(moteur2_IN3, LOW);
  digitalWrite(moteur2_IN4, LOW);

  digitalWrite(moteur3_IN1, HIGH); 
  digitalWrite(moteur3_IN2, LOW);
  digitalWrite(moteur3_IN3, LOW);
  digitalWrite(moteur3_IN4, LOW);

  digitalWrite(moteur4_IN1, HIGH);
  digitalWrite(moteur4_IN2, LOW);
  digitalWrite(moteur4_IN3, LOW);
  digitalWrite(moteur4_IN4, LOW);


  delay(temps);
  }
}

//////////////////////////////////////////////////////////////////////////////////
void pas_2(){
   for(int j=0; j<= 550 ; j++){
  /*ON MONTE L'OBJET*/
  digitalWrite(moteur1_IN1, HIGH); 
  digitalWrite(moteur1_IN2, LOW);
  digitalWrite(moteur1_IN3, LOW);
  digitalWrite(moteur1_IN4, LOW);

  digitalWrite(moteur2_IN1, HIGH); 
  digitalWrite(moteur2_IN2, LOW);
  digitalWrite(moteur2_IN3, LOW);
  digitalWrite(moteur2_IN4, LOW);


  digitalWrite(moteur3_IN1, HIGH); 
  digitalWrite(moteur3_IN2, LOW);
  digitalWrite(moteur3_IN3, LOW);
  digitalWrite(moteur3_IN4, LOW);

  digitalWrite(moteur4_IN1, HIGH); 
  digitalWrite(moteur4_IN2, LOW);
  digitalWrite(moteur4_IN3, LOW);
  digitalWrite(moteur4_IN4, LOW);

  delay(temps);

  digitalWrite(moteur1_IN1, LOW); 
  digitalWrite(moteur1_IN2, HIGH);
  digitalWrite(moteur1_IN3, LOW);
  digitalWrite(moteur1_IN4, LOW);

  digitalWrite(moteur2_IN1, LOW); 
  digitalWrite(moteur2_IN2, HIGH);
  digitalWrite(moteur2_IN3, LOW);
  digitalWrite(moteur2_IN4, LOW);

  digitalWrite(moteur3_IN1, LOW); 
  digitalWrite(moteur3_IN2, HIGH);
  digitalWrite(moteur3_IN3, LOW);
  digitalWrite(moteur3_IN4, LOW);

  digitalWrite(moteur4_IN1, LOW); 
  digitalWrite(moteur4_IN2, HIGH);
  digitalWrite(moteur4_IN3, LOW);
  digitalWrite(moteur4_IN4, LOW);

  delay(temps);

  digitalWrite(moteur1_IN1, LOW);
  digitalWrite(moteur1_IN2, LOW);
  digitalWrite(moteur1_IN3, HIGH);
  digitalWrite(moteur1_IN4, LOW);

  digitalWrite(moteur2_IN1, LOW);
  digitalWrite(moteur2_IN2, LOW);
  digitalWrite(moteur2_IN3, HIGH);
  digitalWrite(moteur2_IN4, LOW);

  digitalWrite(moteur3_IN1, LOW);
  digitalWrite(moteur3_IN2, LOW);
  digitalWrite(moteur3_IN3, HIGH);
  digitalWrite(moteur3_IN4, LOW);

  digitalWrite(moteur4_IN1, LOW); 
  digitalWrite(moteur4_IN2, LOW);
  digitalWrite(moteur4_IN3, HIGH);
  digitalWrite(moteur4_IN4, LOW);

  delay(temps);

  digitalWrite(moteur1_IN1, LOW);
  digitalWrite(moteur1_IN2, LOW);
  digitalWrite(moteur1_IN3, LOW);
  digitalWrite(moteur1_IN4, HIGH);

  digitalWrite(moteur2_IN1, LOW);
  digitalWrite(moteur2_IN2, LOW);
  digitalWrite(moteur2_IN3, LOW);
  digitalWrite(moteur2_IN4, HIGH);

  digitalWrite(moteur3_IN1, LOW);
  digitalWrite(moteur3_IN2, LOW);
  digitalWrite(moteur3_IN3, LOW);
  digitalWrite(moteur3_IN4, HIGH);

  digitalWrite(moteur4_IN1, LOW); 
  digitalWrite(moteur4_IN2, LOW);
  digitalWrite(moteur4_IN3, LOW);
  digitalWrite(moteur4_IN4, HIGH);

  delay(temps);
  }
}

///////////////////////////////////////////////////////////////////////////
void all(int temps, int r, int v, int b){
   for(int i = 0 ; i < 76 ; i++){
     strip.setPixelColor(i, r, v, b);
   }
   strip.show();
   delay(temps); 
}

///////////////////////////////////////////////////////////////////////////////////
void lumiere_flash(){
      all(1000, 120, 20, 60);
      all(500,0,0,0);
      all(1000, 253, 108, 158);
      all(500,0,0,0);
      all(1000, 255, 255, 255);
      all(500,0,0,0);
      all(1000, 247, 255, 60);
      all(500,0,0,0);
      all(1000, 144, 238, 144);
      all(500,0,0,0);
      all(1000, 135, 206, 235);
      all(500,0,0,0);
      all(1000, 204, 204, 255);
      all(500,0,0,0);
}
////////////////////////////////////////////////////////////////////////////////////
void lumiere_prog(){
      progressiveUp(20,204,85,0);
      deprogressiveUp(20,204,85,0);
      progressiveUp(20,204,85,0);
      deprogressiveUp(20,204,85,0);
      all(500,0,0,0);
}
//////////////////////////////////////////////////////////////////////////
void lumiere_def(){
      strip.setBrightness(100); // Règle la luminosité à 100 % de la luminosité maximale
      chenillardUp(100, 25, 25, 112);
      all(500,0,0,0); 
}
///////////////////////////////////////////////////////////////////////////
void chenillardUp(int temps, int r, int v, int b){
  for(int i = 0 ; i < 76 ; i++){
     strip.setPixelColor(i, r, v, b);
     strip.show();
     strip.setPixelColor(i, 0, 0, 0);
     strip.show();
     delay(temps);
  }  
}
////////////////////////////////////////////////////////////////////////////////
void progressiveUp(int temps, int r, int v, int b){
  for(int lumi = 0 ; lumi < 100 ; lumi++){
     for(int i = 0 ; i < 76 ; i++){
       strip.setPixelColor(i, r, v, b);
      }
     strip.setBrightness(lumi); 
     strip.show();
     delay(temps);
     }
  }
/////////////////////////////////////////////////////////////////////////////// 
void deprogressiveUp(int temps, int r, int v, int b){
  for(int lumi = 100 ; lumi > 0 ; lumi--){
     for(int i = 0 ; i < 76 ; i++){
       strip.setPixelColor(i, r, v, b);
      }
     strip.setBrightness(lumi); 
     strip.show();
     delay(temps);
     }
  }
///////////////////////////////////////////////////////////////////////////////


void setup() {

mySerial.begin(9600);//Start our Serial coms for our serial monitor! 
BlueT.begin(9600);
delay(500);//Wait chip initialization is complete 
sendCommand(CMD_SEL_DEV, DEV_TF);//select the TF card   
delay(200);

Serial.begin(9600);
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

strip.begin(); // Lance la connection
strip.show(); // Initialise toute les led à 'off'
}


void loop() {

 anal = analogRead(sortieAnal);
 Serial.println(anal);
 
 if((anal)>=800 || (anal)<=700){
    Serial.print(anal);
    Serial.print("     ");
    Serial.println("bebe pleure");
    BlueT.write("*S");
    delay(1000);
    while (! BlueT.available()) {
      Serial.println("EN ATTENTE");
    }
    
    Var = BlueT.read();
    
    if (Var=='a'){
      Serial.println("AAAAA");
      sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00101);//play the first song with volume 15 class 
      pas_1();
      lumiere_flash();
      pas_2();
      lumiere_flash();
    }
    else if (Var=='e'){
      Serial.println("EEEEEE");
       sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00103);
       pas_1();
       lumiere_prog();
       pas_2(); 
       lumiere_prog(); 
       
      }

    else if (Var=='d'){
       Serial.println("");
        sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00102);
        pas_1();
        lumiere_def();
        pas_2();
        lumiere_def();
      }
  }
  else{
    Serial.println(anal); 
  } 
}
