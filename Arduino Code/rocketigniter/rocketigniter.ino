
#define BUTTON 3
#define BUZZER 13
#define RELAY 4
#define CHECKPIN A0
#define BURNTIME 2000
int E = 5;
int D = 6;
int C = 7;
int P = 8;
int B = 9;
int A = 10;
int F = 11;
int G = 12;
int notalar[] = {800, 400, 400, 400, 100, 100, 100, 100, 100, 100};
int circle[] = {A, B, C, D, E, F};

void setup() {
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(P, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RELAY, OUTPUT);
  pinMode(CHECKPIN, INPUT_PULLUP);
  digitalWrite(P, HIGH);

}

unsigned long timer = millis();
int i = 10;
int circleCount = 0;
bool start = false;
void loop() {
  if (digitalRead(CHECKPIN)) {
    noTone(BUZZER);
    RakamYaz(-2);
    digitalWrite(P, LOW);
    while (digitalRead(CHECKPIN)) {
      digitalWrite(circle[circleCount], HIGH);
      delay(50);
      digitalWrite(circle[circleCount], LOW);
      circleCount = circleCount == 5 ? 0 : circleCount + 1;

    }
    RakamYaz(-2);
    digitalWrite(P, HIGH);
    circleCount = 0;
    i = 10;
    start = false;
  } else {
    if (!digitalRead(BUTTON)) {
      while (!digitalRead(BUTTON)) {}
      start = !start;
      i = 10;
    } else if (start) {

      if (millis() - timer > 1000) {
        
        if (i == 0) {
          tone(BUZZER, notalar[0]);
          digitalWrite(RELAY, HIGH);
          delay(BURNTIME);
          digitalWrite(RELAY, LOW);
          noTone(BUZZER);
          start = false;
          delay(20);
        }
        i--;
        RakamYaz(i);
        if (i <= 2 && i>=0) {
          tone(BUZZER, notalar[i + 1]);
        }
        timer = millis();

      }
      if (millis() - timer > 200 && millis() - timer < 800) {
        digitalWrite(P, HIGH);
      }

      if (millis() - timer > 800) {
        noTone(BUZZER);
        digitalWrite(P, LOW);
      }
    }
  }
}


void RakamYaz(int rakam)
{
  switch (rakam)
  {
    case 0 :
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    case 1:
      digitalWrite(E, LOW);
      digitalWrite(D, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(A, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case 2:
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(A, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    case 3:
      digitalWrite(E, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(A, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    case 4:
      digitalWrite(E, LOW);
      digitalWrite(D, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(A, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 5:
      digitalWrite(E, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 6:
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 7:
      digitalWrite(E, LOW);
      digitalWrite(D, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(A, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case 8:
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 9:
      digitalWrite(E, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case -1:
      digitalWrite(E, LOW);
      digitalWrite(D, LOW);
      digitalWrite(C, LOW);
      digitalWrite(B, LOW);
      digitalWrite(A, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    default:
      digitalWrite(E, LOW);
      digitalWrite(D, LOW);
      digitalWrite(C, LOW);
      digitalWrite(B, LOW);
      digitalWrite(A, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
  }
}
