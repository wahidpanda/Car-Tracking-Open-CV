#include 'SoftwareSerial.h' //Replace (' ') with (< >)

SoftwareSerial BLU(0,1);

String voice;

int Green = 4; //Connect To Pin #4

int Yellow = 2; //Connect To Pin #2

int Red = 3; //Connect To Pin #3

void allon()
{

digitalWrite(Red, HIGH);

digitalWrite(Yellow, HIGH);

digitalWrite(Green, HIGH);

}

void alloff()
{

digitalWrite(Red, LOW);

digitalWrite(Yellow, LOW);

digitalWrite(Green, LOW);

}

void setup()
{

Serial.begin(9600);

BLU.begin(9600);

pinMode(Red, OUTPUT);

pinMode(Yellow, OUTPUT);

pinMode(Green, OUTPUT);

}

void loop()
{

while (Serial.available()) //Check if there is an available byte to read

{ delay(10); //Delay added to make thing stable

char c = Serial.read(); //Conduct a serial read

if (c == '#')

{

break; //Exit the loop when the # is detected after the word

}

voice += c;

}

if (voice.length() > 0)

{

if(voice == "*turn on all LED")

{

allon();

}

else if(voice == "*turn off all LED")

{

alloff();

}

else if(voice == "*switch on red")

{

digitalWrite(Red,HIGH);

}

else if(voice == "*switch on yellow")

{

digitalWrite(Yellow,HIGH);

}

else if(voice == "*switch on green")

{

digitalWrite(Green,HIGH);

}

else if(voice == "*switch off red")

{

digitalWrite(Red,LOW);

}

else if(voice == "*switch off yellow")

{

digitalWrite(Yellow,LOW);

}

else if(voice == "*switch off green")

{

digitalWrite(Green,LOW);

}

voice=""; //Reset variable

}

}