int start_time = 0;
unsigned int current_time = 0;
int buzzer = 3;
int relay_pin = 2;
int RPI = 0;
int motor = 0;
int safety_led = 4;



void setup()
{
  Serial.begin(9600);
  pinMode(A7, INPUT);
  pinMode(buzzer, OUTPUT); 
  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, HIGH);
  pinMode(5, INPUT);
  digitalWrite(buzzer, LOW);
  while (digitalRead(5) == LOW)
  {
    Serial.println("initializing");
    digitalWrite(buzzer, HIGH);
    delay(20);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
  digitalWrite(buzzer, LOW);
}

void loop()
{

  digitalWrite(buzzer, LOW);
  RPI = digitalRead(5);
 // motor = analogRead(A7);
  //Serial.println(motor);
  // Serial.println(RPI);
  Serial.println(RPI);
  if (RPI = HIGH)
  {
    start_time = millis();
    while (RPI == HIGH)
    {
      RPI = digitalRead(5);
      //motor = analogRead(A7);
      current_time = millis() - start_time;
      Serial.println(RPI);
      if (current_time > 4000)
      {
        Serial.println("Time Exceeded");
        digitalWrite(relay_pin, LOW);
        delay(2000);
        digitalWrite(relay_pin, HIGH);
        delay(2000);
        Serial.println("Relay OFF");
        while (digitalRead(5) == LOW)
        {
          digitalWrite(buzzer, HIGH);
           delay(200);
          digitalWrite(buzzer, LOW);
          delay(100);
          start_time = millis();
        }
        digitalWrite(buzzer, HIGH);
      }
    }
    if (current_time <= 500)
    {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
  }



  if (RPI == LOW)
  {
    start_time = millis();
    while (RPI == LOW)
    {
      RPI = digitalRead(5);
      //motor = analogRead(A7);
      current_time = millis() - start_time;
      Serial.println(current_time);
      if (current_time > 8000)

      {
        Serial.println("Time Exceeded");
        digitalWrite(relay_pin, LOW);
        delay(2000);
        digitalWrite(relay_pin, HIGH);
        delay(2000);
        Serial.println("Relay OFF");

        while (digitalRead(5) == LOW)
        {

          digitalWrite(buzzer, HIGH);
          delay(200);
          digitalWrite(buzzer, LOW);
          delay(100);
          start_time = millis();
        }
        digitalWrite(buzzer, HIGH);
      }
    }
    if (current_time <= 300)
    {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
  }
}
