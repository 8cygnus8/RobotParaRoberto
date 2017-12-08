// DECLARACION DE VARIABLES PARA PINES
const int pinecho = 11;
const int pintrigger = 12;
const int pinled = 10;
const int pinled2 = 8;
// VARIABLES PARA CALCULOS
unsigned int tiempo, distancia;

//SENSOR PIR
const int sPIR = 2;
int mov = 0;
 
void setup() {
  // PREPARAR LA COMUNICACION SERIAL
  Serial.begin(9600);
  // CONFIGURAR PINES DE ENTRADA Y SALIDA
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  pinMode(pinled, OUTPUT);
 pinMode(pinled2, OUTPUT);
 pinMode(sPIR,INPUT);
  Serial.println("PIR Motion | Sensor de Movimiento IR");
  Serial.println(" ");
}
 
void loop() {
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);
 
  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);
 
  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = tiempo / 58;
 
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print(distancia);
  Serial.println(" cm");
  delay(200);
 
  // ENCENDER EL LED CUANDO SE CUMPLA CON CIERTA DISTANCIA
  if (distancia <= 15) {
    digitalWrite(pinled, HIGH);
    delay(500);
  } else {
    digitalWrite(pinled, LOW);
  }
  mov = digitalRead(sPIR);
  
  if (mov == HIGH) {
    digitalWrite(pinled2,HIGH);
  Serial.print("*P"+String(mov)+"*");
    Serial.print(mov); Serial.print(" : "); Serial.println("Movimiento detectado"); 
    delay(2000);
     mov = 0;
    
  }
 else {
    digitalWrite(pinled2,LOW);
    Serial.print(mov); Serial.print(" : "); Serial.println("No se detecta movimiento");
    
    delay(200);
    }
}
