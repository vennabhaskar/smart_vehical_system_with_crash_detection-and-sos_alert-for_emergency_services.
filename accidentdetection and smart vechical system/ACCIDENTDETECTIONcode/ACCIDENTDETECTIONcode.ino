#include <AltSoftSerial.h>
#include <TinyGPS++.h>
#include <Wire.h>
#include <math.h>
#include <SoftwareSerial.h>

// Crash detection system
const int buttonPin = 2; // Button connected to pin 2
const int ledPin = 13; // LED connected to pin 13
const int sosAlertDelay = 20000; // 20 seconds in milliseconds

int buttonState = 0; // Initialize button state to 0 (LOW)
bool sosAlertSent = false; // Initialize SOS alert flag to false
unsigned long startTime = 0; // Initialize start time to 0

// SOS alert system
const String EMERGENCY_PHONE = "+91xxxxxxxxxx";
#define rxPin 2
#define txPin 3

SoftwareSerial sim800(rxPin, txPin);
AltSoftSerial neogps;
TinyGPSPlus gps;
#define BUZZER 12
#define BUTTON 11
#define xPin A1
#define yPin A2
#define zPin A3

byte updateflag;

int xaxis = 0, yaxis = 0, zaxis = 0;
int deltx = 0, delty = 0, deltz = 0;
int vibration = 2;
int devibrate = 75;
int magnitude = 0;
int sensitivity = 20;

double angle;
bool impact_detected = false;
unsigned long time1;
unsigned long impact_time;
unsigned long alert_delay = 30000;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  sim800.begin(9600);
  neogps.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  sms_status = "";
  sender_number = "";
  received_date = "";
  msg = "";
  sim800.println("AT");
  delay(1000);
  sim800.println("ATE1");
  delay(1000);
  sim800.println("AT+CPIN?");
  delay(1000);
  sim800.println("AT+CMGF=1");
  delay(1000);
  sim800.println("AT+CNMI=1,1,0,0,0");
  delay(1000);
  time1 = micros();
  xaxis = analogRead(xPin);
  yaxis = analogRead(yPin);
  zaxis = analogRead(zPin);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (sosAlertSent == true) {
    Serial.println("SOS alert sent to emergency services.");
    // Code to send SOS alert to emergency services
    sendSms("SOS alert! Crash detected!");
  }

  if (micros() - time1 > 1999) Impact();
  if (updateflag > 0)
  {
    updateflag = 0;
    Serial.println("Impact detected!!");
    Serial.print("Magnitude:");
    Serial.println(magnitude);

    getGps();
    digitalWrite(BUZZER, HIGH);
    impact_detected =true;
    impact_time = millis();


  }
  if (buttonState == HIGH && sosAlertSent == false && (millis() - startTime) < sosAlertDelay) 
  {
    sosAlertSent = true; // Set the SOS alert flag to true
    digitalWrite(ledPin, LOW); // Turn off the LED
    Serial.println("SOS alert cancelled.");
  }
  if (impact_detected == true)
  {
    if (millis() - impact_time >= alert_delay) {
      digitalWrite(BUZZER, LOW);
      makeCall();
      delay(1000);
      sendAlert();
      impact_detected = false;
      impact_time = 0;
    }
  }

  while (sim800.available()) 
  {
    parseData(sim800.readString());
  }
  while (Serial.available())  
  {
    sim800.println(Serial.readString());
  }
}

  return impact_detected;
}

void Impact()
{
  time1 = micros();
  int oldx = xaxis;
  int oldy = yaxis;
  int oldz = zaxis;

  xaxis = analogRead(xPin);
  yaxis = analogRead(yPin);
  zaxis = analogRead(zPin);


  vibration--;
  Serial.print("Vibration = ");
  Serial.println(vibration);
  if (vibration < 0) vibration = 0;
  if (vibration > 0) return;
  deltx = xaxis - oldx;
  delty = yaxis - oldy;
  deltz = zaxis - oldz;


  magnitude = sqrt(sq(deltx) + sq(delty) + sq(deltz));
  if (magnitude >= sensitivity) //impact detected
  {
    updateflag = 1;
    vibration = devibrate;
  }
  else
  {
    magnitude = 0;
  }
}

void parseData(String buff) {
  Serial.println(buff);

  unsigned int len, index;
  index = buff.indexOf("\r");
  buff.remove(0, index + 2);
  buff.trim();
  if (buff != "OK"){
    index = buff.indexOf(":");
    String cmd = buff.substring(0, index);
    cmd.trim();

    buff.remove(0, index + 2);
    if (cmd == "+CMTI") {
      index = buff.indexOf(",");
      String temp = buff.substring(index + 1, buff.length());
      temp = "AT+CMGR=" + temp + "\r";
      sim800.println(temp);
    }
    else if (cmd == "+CMGR") {
      if (buff.indexOf(EMERGENCY_PHONE) > 1) {
        buff.toLowerCase();
        if (buff.indexOf("get gps") > 1) {
          getGps();
          String sms_data;
          sms_data = "GPS Location Data\r";
          sms_data += "http://maps.google.com/maps?q=loc:";
          sms_data += latitude + "," + longitude;

          sendSms(sms_data);
        }
      }
    }
  }
  else {
  }
}

void getGps()
{
  // Can take up to 60 seconds
  boolean newData = false;
  for (unsigned long start = millis(); millis() - start < 2000;) {
    while (neogps.available()) {
      if (gps.encode(neogps.read())) {
        newData = true;
        break;
      }
    }
  }

  if (newData)
  {
    latitude = String(gps.location.lat(), 6);
    longitude = String(gps.location.lng(), 6);
    newData = false;
  }
  else {
    Serial.println("No GPS data is available");
    latitude = "";
    longitude = "";
  }

  Serial.print("Latitude= "); Serial.println(latitude);
  Serial.print("Lngitude= "); Serial.println(longitude);
}

void sendAlert()
{
  String sms_data;
  sms_data = "Accident Alert!!\r";
  sms_data += "http://maps.google.com/maps?q=loc:";
  sms_data += latitude + "," + longitude;

  sendSms(sms_data);
}

void makeCall()
{
  Serial.println("calling....");
  sim800.println("ATD" + EMERGENCY_PHONE + ";");
  delay(20000); //20 sec delay
  sim800.println("ATH");
  delay(1000); //1 sec delay
}

void sendSms(String text)
{
  //return;
  sim800.print("AT+CMGF=1\r");
  delay(1000);
  sim800.print("AT+CMGS=\"" + EMERGENCY_PHONE + "\"\r");
  delay(1000);
  sim800.print(text);
  delay(100);
  sim800.write(0x1A);
  delay(1000);
  Serial.println("SMS Sent Successfully.");
}