#include <Arduino.h>
#define LED_BUILTIN 6
#define LIGHT_SENSOR A2

int light_value = 0;
bool led_flag = false;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LIGHT_SENSOR, INPUT);
}

void loop()
{
  light_value = analogRead(LIGHT_SENSOR);
  Serial.print("Light value: ");
  Serial.println(light_value);
  bool temp_led_flag;

  if (light_value <= 300)
  {
    temp_led_flag = true;
    if (temp_led_flag != led_flag)
    {
      Serial.println("Light below threshold detected, activating LED");
    }
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    temp_led_flag = false;
    if (temp_led_flag != led_flag)
    {
      Serial.println("Light above threshold detected, de-activating LED");
    }
    digitalWrite(LED_BUILTIN, LOW);
  };
  led_flag = temp_led_flag;
  delay(500);
}