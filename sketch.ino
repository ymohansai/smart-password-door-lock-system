#include <Keypad.h>
const byte rows=4;
const byte cols=4;
char keys[rows][cols]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
byte rowpins[rows]={9,8,7,6};
byte colpins[cols]={5,4,3,2};
Keypad keypad=Keypad(makeKeymap(keys),rowpins,colpins,rows,cols);

#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include <Servo.h>
Servo motor;

const int led=10;

String password = "1234";
String enteredpassword = "";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

lcd.init();
lcd.backlight();

lcd.print("ENTER PASSWORD..");
lcd.setCursor(1,1);
lcd.print("DOOR LOCKED!..");
motor.write(0);
pinMode(led, OUTPUT);

motor.attach(11);

}
void loop() {
char Key=keypad.getKey();
if (Key){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PASSWORD ");
  lcd.print(enteredpassword+Key);
  enteredpassword+=Key;
  if (enteredpassword.length()==4){
    if (enteredpassword==password){
      lcd.setCursor(1,1);
      lcd.print("#DOOR UNLOCKED");
      motor.write(180);
      delay(3000);
      motor.write(0);
      digitalWrite(led, HIGH);
      delay(1000);
    }
    else{
      motor.write(10);
      delay(500);
      motor.write(0);
      lcd.setCursor(1,1);
      lcd.print("WRONG PASSWORD");
      digitalWrite(led, LOW);
      delay(1000);
    }
    enteredpassword="";
  }
  lcd.clear();
}
}