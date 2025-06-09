#define M1 9 
#define M2 11 
#define dir1 4 // Pino de direção do 1º motor
#define dir2 2 // Pino de direção do 2º motor
#define pin_S1 A0
#define pin_S2 A1
#define pin_Potenciometro A2
int velocidade = 150; 

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);
  digitalWrite(dir1, LOW); 
  digitalWrite(dir2, LOW);  
  Serial.begin(9600); 
}

void loop() {
  // Leitura do sensor de linha e do potenciômetro
  int Sensor1 = analogRead(pin_S1); 
  int Sensor2 = analogRead(pin_S2);
  int valorPotenciometro = analogRead(pin_Potenciometro);
  int limiar = 600; 
  Serial.print("Sensor1: ");   
  Serial.print(Sensor1);
  Serial.print(" Sensor2: ");
  Serial.println(Sensor2);

  // Controle dos motores com base nos valores dos sensores
  if (Sensor1 > limiar) { 
    digitalWrite(dir1, LOW); 
    analogWrite(M1, velocidade);
  } 
  else {
    digitalWrite(dir1, HIGH); 
    analogWrite(M1, velocidade);
  }

  if (Sensor2 > limiar) { 
    digitalWrite(dir2, LOW); 
    analogWrite(M2, velocidade);
  } 
  else {
    digitalWrite(dir2, HIGH); 
    analogWrite(M2, velocidade);
  }
   delay(100);
}
             