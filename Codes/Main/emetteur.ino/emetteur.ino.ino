int pin = A0;
float tension;
void setup()
{
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop()
{
  tension = analogRead(pin);
  Serial.println(tension);
}

