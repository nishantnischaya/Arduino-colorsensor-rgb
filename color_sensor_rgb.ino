/*     Arduino Color Sensing Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define redPin 11
#define greenPin 10
#define bluePin 9
#define sensorOut 2

int frequency = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}

int R,G,B;

void loop() {
  R=0,B=0,G=0;
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remap
  frequency = map(frequency,199, 33, 0 , 255);
  //Assigning Value
  R=frequency;
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remap
  frequency = map(frequency,260, 24, 0 , 255);
  //Assigning Value
  G=frequency;
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remap
  frequency = map(frequency,177, 25, 0 , 255);
  //Assigning Value
  B=frequency;
  delay(100);

  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(R);//printing RED color frequency
  Serial.print("  ");
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(G);//printing GREEN color frequency
  Serial.print("  ");
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(B);//printing BLUE color frequency
  Serial.println("  ");
  delay(100);
}
