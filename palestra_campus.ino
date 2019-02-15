#define pino_sinal_analogico A0
int rele = 7;
 
int valor_analogico;
 
void setup()
{
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
}
 
void loop()
{
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);
 
  //Solo umido
  if (valor_analogico > 0 && valor_analogico < 400)
  {
    Serial.println(" Status: Solo umido");
  
  }
 
  //Solo com umidade moderada
  if (valor_analogico > 400 && valor_analogico < 800)
  {
    Serial.println(" Status: Umidade moderada");
    digitalWrite(rele, LOW);
    delay(3000);
    digitalWrite(rele, HIGH);
    delay(3000);
  }
 
  //Solo seco
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    Serial.println(" Status: Solo seco");
    digitalWrite(rele, LOW);
    delay(6000);
    digitalWrite(rele, HIGH);
    delay(6000);
  }
  delay(100);
}
