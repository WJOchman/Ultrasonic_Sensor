int Trigger = 8;
int Echo = 4; 
unsigned long startTime = 0;
unsigned long returnTime = 0;
int LED = 13;

void setup() {
  // put your setup code here, to run once:
pinMode (Trigger, OUTPUT);
pinMode (Echo, INPUT);
pinMode (LED, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Trigger, HIGH);
delayMicroseconds(15);
digitalWrite(Trigger, LOW);
int e = digitalRead(Echo);
while(e == LOW)
{
  e = digitalRead(Echo);
}
startTime = micros();
//Serial.print("sTime = ");
//Serial.println(startTime);
while(e == HIGH)
{
  e = digitalRead(Echo);
}
returnTime = micros();
//Serial.print("rTime = ");
//Serial.println(returnTime);

unsigned long totalTime = returnTime - startTime;
float distance = totalTime / 58;
if (distance < 10){
  digitalWrite(LED, HIGH);
}
else
{
  digitalWrite(LED, LOW);
}
Serial.println(distance);
delay(75);
}
