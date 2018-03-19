#include <Servo.h>

#define SERVO 10
#define BUTTON 8
#define RED 3
#define GREEN 2
#define BLUE 4
#define SPEAKER 9

#define NOTE_E3  2637
#define NOTE_F3  2794
#define NOTE_FS3 2960
#define NOTE_G3  3136
#define NOTE_GS3 3322
#define NOTE_A3  3520
#define NOTE_AS3 3729
#define NOTE_B3  3951
#define NOTE_C4  4186
#define NOTE_CS4 4435
#define NOTE_D4  4699

Servo arm;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  Serial.begin(9600);
  arm.attach(SERVO);
  arm.write(0);
  
  // put your setup code here, to run once:

}
int ran = 0;
void loop() {

  //Generate a random number when the button is pressed to randomize which sequence the arm goes to
  if(digitalRead(BUTTON)){
    Serial.println("Pressed");

    //Generate random number in the interval [0, 5]
    ran = random(0, 6);
    Serial.print(ran);

    //Run sequence given random number
    switch (ran){
      case 0:
        push();
        break;
      case 1:
        wave();
        break;
      case 2:
        hesistate();
        break;
      case 3:
        quick();
        break;
      case 4:
        quick();
        break;
      case 5:
        quick();
        break;  
      default:
        quick();  
        break;
    }
  }

  //Reset after the sequence is complete
  noTone(SPEAKER);
  arm.write(0);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(500);
}

//SEQUENCES

void push(){
//Lift up hood, then turn the siwtch off
  //Lift up
  Serial.println("Push");
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  arm.write(70);
  Serial.println("Pause");
  delay(3000);
  //Push
  arm.write(100);
  Serial.println("Hit");
  delay(1500);
  //Go back
  arm.write(0);
  Serial.println("Return");
  delay(500);
}

void hesistate(){
//Pushes the button close, but then pop back up again
  Serial.println("Hesistate");
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  //Push button
  arm.write(100);
  delay(1500);
  //Go back
  arm.write(0);
  delay(1000);
  //Lift up the hood
  arm.write(70);
  delay(2000);
  //Screech and push switch again
  tone(SPEAKER, NOTE_E3);
  arm.write(100);
  delay(1500);
  //Go back
  arm.write(0);
  delay(500);
  noTone(SPEAKER);
}

void quick(){
//Turns off button very quickly
  arm.write(100);
  delay(500);
  arm.write(0);
  delay(500);
}

void wave(){
//Popup and play the funkytown song while waving with hand
  
  Serial.write("Wave");
  arm.write(85);
  tone(SPEAKER,NOTE_A3); 
  delay(50);
  noTone(SPEAKER);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  
  delay(250);
  
  arm.write(65);
  tone(SPEAKER,NOTE_A3);
  delay(50);
  noTone(SPEAKER);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  
  delay(250);
  
  arm.write(85);
  tone(SPEAKER,NOTE_G3);
  delay(50);
  noTone(SPEAKER);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  
  delay(250);
  
  arm.write(65);
  tone(SPEAKER,NOTE_A3);
  delay(50);
  noTone(SPEAKER);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  
  delay(500);
  
  arm.write(100);
  tone(SPEAKER,NOTE_E3);
  delay(50);
  noTone(SPEAKER);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  delay(500);
  
  arm.write(85);
  tone(SPEAKER,NOTE_E3);
  delay(50);
  noTone(SPEAKER);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  
  delay(250);
  
  arm.write(65);
  tone(SPEAKER,NOTE_A3);
  delay(50);
  noTone(SPEAKER);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  
  delay(250);
  
  arm.write(85);
  tone(SPEAKER,NOTE_D4);
  delay(50);
  noTone(SPEAKER);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  
  delay(250);
  
  arm.write(65);
  tone(SPEAKER,NOTE_CS4);
  delay(50);
  noTone(SPEAKER);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  
  delay(250);
  tone(SPEAKER,NOTE_A3);
  delay(50);
  noTone(SPEAKER);
  arm.write(85);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  
  delay(250);
  
  
  arm.write(65);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  
  delay(250);
  
  arm.write(0);
}

