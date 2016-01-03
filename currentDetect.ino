const int MVA_LENGTH = 30;
int values[MVA_LENGTH] = {0}; 
int pointIndex = 0; 
int sum = 0; 

int ACTIVATION_THRESHOLD =  350; 



void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);

  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //  size (400, 400);
  //  background(0);

  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  // float reading = sensorValue * (5.0 / 1023.0);


  int finalReading = mvaValue(sensorValue);
  
  Serial.println(  finalReading  );

  if (finalReading >= ACTIVATION_THRESHOLD) {
    digitalWrite(13, HIGH);
  } else { 
    digitalWrite(13, LOW); 
  }
  
  delay(100);

  
  
 }


int mvaValue(int newValue){

  sum -= values[pointIndex]; 
  values[pointIndex] = newValue; 
  sum += newValue; 
  (pointIndex >= MVA_LENGTH -1) ? pointIndex = 0 : pointIndex++; 

  return sum / MVA_LENGTH; 
}




