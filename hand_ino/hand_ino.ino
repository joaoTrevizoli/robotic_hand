#include <Arduino.h>
#include <Servo.h>

void movimentaDedo(Servo &servo);
int fechaMao();

const int dedo1 = 5;
const int dedo2 = 6;
const int dedo3 = 9;
const int dedo4 = 10;
const int dedo5 = 11;

int input;
int pos = 0;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup()
{
  Serial.begin(9600);
  servo1.attach(dedo1);
  servo1.write(0);
  servo2.attach(dedo2);
  servo2.write(0);
  servo3.attach(dedo3);
  servo3.write(0);
  servo4.attach(dedo4);
  servo4.write(0);
  servo5.attach(dedo5);
  servo5.write(0);

  delay(100);
}

void loop()
{

  if (Serial.available()>0)
  {
    int input = Serial.read();
    Serial.println(input);
    switch (input)
    {
      case 'q':
        Serial.println(input);
        movimentaDedo(servo1);
        break;
      case 'w':
        Serial.println(input);
        movimentaDedo(servo2);
        break;
      case 'e':
        Serial.println(input);
        movimentaDedo(servo3);
        break;
      case 'r':
        Serial.println(input);
        movimentaDedo(servo4);
        break;
      case 't':
        Serial.println(input);
        movimentaDedo(servo5);
        break;
      default:
        Serial.println(input);
        fechaMao();
        break;
    }

    Serial.println();
  }
}


void movimentaDedo(Servo &servo)
{
  for (pos = 0; pos <= 180; pos++)
  {
  servo.write(pos);
  delay(3);
  }
  for (pos = 180; pos >= 0; pos--)
  {

  servo.write(pos);
    delay(3);
  }
}

int fechaMao()
{

  for (pos = 0; pos <= 180; pos++)
  {
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    servo5.write(pos);

    delay(5);
  }
  for (pos = 180; pos >= 0; pos--)
  {
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    servo5.write(pos);
    delay(5);
  }
  return 1;
}

