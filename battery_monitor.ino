#define BATTERY A0
#define RELAY 2
#define LED0 3  // LOWEST
#define LED1 4
#define LED2 5
#define LED3 6  // HIGHEST

float value = 0.0;
float voltage;
float perc;

void setup(){
  Serial.begin(9600);
  
  pinMode(BATTERY, INPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  digitalWrite(RELAY, LOW);
}

void loop(){
  value = analogRead(A0);
  voltage = value * 5.0/1023.0;
  perc = (voltage - 3.27) / (4.2 - 3.27) * 100.0; 
  
  Serial.print("Voltage= ");
  Serial.println(voltage*3.0f+0.1f);  // 0.1V drop in UNO
  Serial.print("Battery level= ");
  Serial.print(perc);
  Serial.println(" %");

  if(perc > 0.0 && perc <= 100.0) {
    digitalWrite(RELAY, HIGH);

    if(perc >= 80.0) {
      digitalWrite(LED0, HIGH);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
    } else if(perc >= 60.0) {
      digitalWrite(LED0, HIGH);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
    } else if(perc >= 40.0) {
      digitalWrite(LED0, HIGH);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    } else if(perc >= 20.0) {
      digitalWrite(LED0, HIGH);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }
  } else {
    digitalWrite(RELAY, LOW);

    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }


  
  delay(1);
}
