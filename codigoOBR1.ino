#define GPIO34 2 

#define GPIO35 3 

#define GPIO36 4 

#define GPIO39 5 

#define GPIO32 6 

 

#define LedRed    25 

#define LedGreen  26 

#define LedBlue   27 

 

int R,G,B     = 0; 

 

void setup() { 

  pinMode(34, OUTPUT); 

  pinMode(35, OUTPUT); 

  pinMode(36, OUTPUT); 

  pinMode(39, OUTPUT); 

  pinMode(32, INPUT); 

 

  pinMode(LedRed, OUTPUT); 

  pinMode(LedGreen, OUTPUT); 

  pinMode(LedBlue, OUTPUT); 

   

  // Frequencia 

  digitalWrite(34, HIGH); 

  digitalWrite(35, LOW); 

   

  Serial.begin(9600); 

 

  for (int i=0; i<=5; i++){ 

    digitalWrite(LedRed, !digitalRead(LedRed)); 

    digitalWrite(LedGreen, !digitalRead(LedGreen)); 

    digitalWrite(LedBlue, !digitalRead(LedBlue)); 

    delay(250); 

  } 

} 

void loop() { 

  // Vermelho 

  digitalWrite(36, LOW); 

  digitalWrite(39,LOW); 

  R = pulseIn(32, LOW);  // Frequencia saida vermelho 

  delay(100);  

  // Verde 

  digitalWrite(36, HIGH); 

  digitalWrite(39, HIGH); 

  G = pulseIn(32, LOW);  // Frequencia saida Verde 

  delay(100); 

  // Azul 

  digitalWrite(36,LOW); 

  digitalWrite(39,HIGH); 

  B = pulseIn(32, LOW);  Frequencia saida vermelho 

  delay(100); 

   

  //---------------------------------------------------------- 

Cor vo mudar 

  if (R>20 && R<35 && G>80 && G<105 && B>70 && B<90){       // detectar vermelho 

    digitalWrite(LedRed, HIGH); 

  } 

  else if (R>75 && R<100 && G>60 && G<85 && B>75 && B<95){  // detectar verde 

    digitalWrite(LedGreen, HIGH); 

  } 

  else if (R>95 && R<115 && G>70 && G<95 && B>30 && B<55){  // detectar azul 

    digitalWrite(LedBlue, HIGH); 

  } 

  else{ 

    digitalWrite(LedRed, LOW); 

    digitalWrite(LedGreen, LOW); 

    digitalWrite(LedBlue, LOW); 

  } 

  //---------------------------------------------------------- 

 

  // Printa Rgb 

  Serial.print("R= "); 

  Serial.print(R); 

  Serial.print(" | "); 

  Serial.print("G= "); 

  Serial.print(G); 

  Serial.print(" | "); 

  Serial.print("B= "); 

  Serial.print(B); 

  Serial.println(); 

  delay(200); 

} 