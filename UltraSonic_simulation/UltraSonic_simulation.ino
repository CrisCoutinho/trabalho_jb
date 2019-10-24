#include <LiquidCrystal.h>;

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

const int trigPin=3;  // defines the pin numbers
const int echoPin=2;

int PinoledVerm = 8;  //Pino led1 - Vermelho  
int PinoledVerde = 9; //Pino led1 - Verde   
  
long duration;                // defines variables
int distanceCm, distanceInch;

void setup() {
  Serial.begin (9600);
  lcd.begin (16,2);     // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode(PinoledVerm, OUTPUT);  //Define o Pino vermelho do led como saida  
  pinMode(PinoledVerde, OUTPUT); //Define o Pino verde do led como saida  
    
  }

void loop() {
digitalWrite(3,LOW);  // Clears the trigPin
delayMicroseconds(2);
digitalWrite(3,HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10); // Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(3,LOW);

duration = pulseIn(2, HIGH);   //To receive the reflected signal.

distanceCm= duration*0.0340/2;  // Calculating the distance
distanceInch = duration*0.0133/2;

if(distanceCm >= 40){

  digitalWrite(PinoledVerde,0);
  digitalWrite(PinoledVerm,1);
  lcd.setCursor(0,0);      
  lcd.print("Limite do Sensor"); 
  lcd.setCursor(0,1);
  lcd.print("   Estourado !  ");
  delay(100);
  digitalWrite(PinoledVerde,0);
  digitalWrite(PinoledVerm,0);
  lcd.setCursor(0,0);     
  lcd.print("                "); 
  lcd.setCursor(0,1);
  lcd.print("                ");
  delay(100);

  }

if(distanceCm <= 25){

  digitalWrite(PinoledVerde,0);
  digitalWrite(PinoledVerm,1);
  
  lcd.setCursor(0,0);      // Sets the location where text written to the LCD will be displayed
  lcd.print("Distance= "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm);   // Prints the distance value from the sensor
  lcd.print(" cm    ");
  delay(20);
  lcd.setCursor(0,1);
  lcd.print("Distance= ");
  lcd.print(distanceInch);
  lcd.print(" inch    ");
  delay(20);

}else if((distanceCm > 25) && (distanceCm <= 40)){

  digitalWrite(PinoledVerm,0);
  digitalWrite(PinoledVerde,1);
  
  lcd.setCursor(0,0);      
  lcd.print("Distance= ");
  lcd.print(distanceCm);   
  lcd.print(" cm    ");
  delay(20);
  lcd.setCursor(0,1);
  lcd.print("Distance= ");
  lcd.print(distanceInch);
  lcd.print(" inch    ");
  delay(20);
    
  }
    
}
