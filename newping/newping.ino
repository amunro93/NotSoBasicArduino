#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 9
#define MAX_DISTANCE 200
int cm = 0;
Servo myservo; // create servo object to control a servo
NewPing myHCSR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup()
{
	Serial.begin(9600);
	myservo.attach(7);
}

void loop()
{
	cm = myHCSR04.ping_cm();
	Serial.print("cm: ");
	Serial.println(cm);
	if (cm != 0)
	{
		if (cm > 10)
			myservo.write(180);
		else
			myservo.write(90);
	}
	delay(50);
}