#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

#define FIREBASE_HOST "androidstatus-8ebf1.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyAdD0OqUE8lO2JBjaHVE4OUdPZu9n2kO-s"
#define WIFI_SSID "Yarana"
#define WIFI_PASSWORD "12112001"

int led = 2;
int led2 = 15;// isko chhor ke baki sab ko relay se connect karna hai 
int led3 = 4;
int led4 = 13;
int led5 = 21;
int led6 = 19;
int led7 = 18;
int led8 = 5;

void setup() {
  Serial.begin(9600);
  delay(1000);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);

  delay(1000);


  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);

  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  // for (int i = 1; i <= 8; i++) {
  //   Firebase.setString("LED_STATUS" + String(i), "OFF");
  // }
}

void loop() {
  String fireStatus = Firebase.getString("LED_STATUS");
  // String fireStatus2 = Firebase.getString("LED_STATUS2");
  // String fireStatus3 = Firebase.getString("LED_STATUS3");
  // String fireStatus4 = Firebase.getString("LED_STATUS4");
  // String fireStatus5 = Firebase.getString("LED_STATUS5");
  // String fireStatus6 = Firebase.getString("LED_STATUS6");
  // String fireStatus7 = Firebase.getString("LED_STATUS7");
  // String fireStatus8 = Firebase.getString("LED_STATUS8");

  Serial.print("Firebase Value ");
  Serial.println(fireStatus);

  if (fireStatus == "1") {
    Serial.println("Led Turned ON");
    digitalWrite(led, HIGH);
  } else if (fireStatus == "0") {
    Serial.println("Led Turned OFF");
    digitalWrite(led, LOW);
  }

  if (fireStatus == "4") {
    Serial.println("Led 2 Turned ON");
    digitalWrite(led2, HIGH);
  } else if (fireStatus == "3") {
    Serial.println("Led 2 Turned OFF");
    digitalWrite(led2, LOW);
  }

  if (fireStatus == "6") {
    Serial.println("Led 3 Turned ON");
    digitalWrite(led3, HIGH);
  } else if (fireStatus == "5") {
    Serial.println("Led 3 Turned OFF");
    digitalWrite(led3, LOW);
  }

  if (fireStatus == "8") {
    Serial.println("Led 4 Turned ON");
    digitalWrite(led4, HIGH);
  } else if (fireStatus == "7") {
    Serial.println("Led 4 Turned OFF");
    digitalWrite(led4, LOW);
  }

  if (fireStatus == "10") {
    Serial.println("Led 5 Turned ON");
    digitalWrite(led5, HIGH);
  } else if (fireStatus == "9") {
    Serial.println("Led 5 Turned OFF");
    digitalWrite(led5, LOW);
  }

  if (fireStatus == "12") {
    Serial.println("Led 6 Turned ON");
    digitalWrite(led6, HIGH);
  } else if (fireStatus == "11") {
    Serial.println("Led 6 Turned OFF");
    digitalWrite(led6, LOW);
  }

  if (fireStatus == "14") {
    Serial.println("Led 7 Turned ON");
    digitalWrite(led7, HIGH);
  } else if (fireStatus == "13") {
    Serial.println("Led 7 Turned OFF");
    digitalWrite(led7, LOW);
  }

  if (fireStatus == "16") {
    Serial.println("Led 8 Turned ON");
    digitalWrite(led8, HIGH);
  } else if (fireStatus == "15") {
    Serial.println("Led 8 Turned OFF");
    digitalWrite(led8, LOW);
  }

  delay(100);
}
