#define pino_sinal_analogico A0 //define o pino que o sensor de solo vai estar alocado
int rele = 7; //define o pino que o modulo rele vai estar alocado 
 
int valor_analogico; 
 
void setup()
{
  Serial.begin(9600);//inicia o serial print do arduino 
  pinMode(pino_sinal_analogico, INPUT); //inicia o sensor de umidade 
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
    Serial.println(" Status: Solo umido"); //mostra no serial print o estado do solo
  
  }
 
  //Solo com umidade moderada
  if (valor_analogico > 400 && valor_analogico < 800)
  {
    Serial.println(" Status: Umidade moderada"); //mostra no serial print o estado do solo
    digitalWrite(rele, LOW); 
    delay(3000);
    digitalWrite(rele, HIGH);
    delay(3000);
  }
 
  //Solo seco
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    Serial.println(" Status: Solo seco"); //mostra no serial print o estado do solo
    digitalWrite(rele, LOW);
    delay(6000);
    digitalWrite(rele, HIGH);
    delay(6000);
  }
  delay(100);
}
