#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5

int a, b, c, d, e, f, g;
int Speed = 80;

char auth[] = "QCQtCp4AHG2Hswy1no3JTqt19cvtkWX4"; //Token apk blynk
char ssid[] = "PLN33"; //SSID WiFi
char pass[] = "00000000"; //password WiFi


void setup() {
  Serial.begin(115200);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.jpnet.co.th", 8080);
  Serial.println("DDDD");
}

BLYNK_WRITE(V0) {
  a = param[0].asInt();
  Serial.print("A : "); Serial.println(a);
}
BLYNK_WRITE(V1) {
  b = param[0].asInt();
  Serial.print("B : "); Serial.println(b);
}
BLYNK_WRITE(V2) {
  c = param.asInt();
  Serial.print("C : "); Serial.println(c);
}
BLYNK_WRITE(V3) {
  d = param.asInt();
  Serial.print("D : "); Serial.println(d);
}
BLYNK_WRITE(V4) {
  e = param.asInt();
  Serial.print("E : "); Serial.println(d);
}
BLYNK_WRITE(V5) {
  f = param.asInt();
  Serial.print("F : "); Serial.println(d);
}
BLYNK_WRITE(V6) {
  g = param.asInt();
  Serial.print("G : "); Serial.println(d);
}

void smartcar() {
  if (a == 1) {
    jalanMaju();
    Serial.println("Maju");
  } else if (b == 1) {
    jalanMundur();
    Serial.println("Mundur");
  } else if (c == 1) {
    belokKiri();
    Serial.println("Belok Kiri");
  } else if (d == 1) {
    belokKanan();
    Serial.println("Belok Kanan");
  } else if (e == 1) {
    Speed = 80;
    Serial.println("Speed 1");
  } else if (f == 1) {
    Speed = 120;
    Serial.println("Speed 2");
  } else if (g == 1) {
    Speed = 160;
    Serial.println("Full Power");
  } else {
    berhenti();
    Serial.println("carstop");
  }
}
void loop() {
  Blynk.run();
  smartcar();
}

void belokKiri() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void belokKanan() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void jalanMaju() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void jalanMundur() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void berhenti() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
