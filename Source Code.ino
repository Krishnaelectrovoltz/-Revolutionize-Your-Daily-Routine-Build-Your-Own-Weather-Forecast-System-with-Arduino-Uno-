#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int SwitchPin1 = 10 ;
int SwitchPin2 = 9 ;
int SwitchPin3 = 8 ;
int SwitchPin4 = 7 ;
int alsens = A0 ;
int humidsens=A1;
int moistureval ;
int gassens = A2 ;
int TempSens = A3;
int tempsens1 ;
float humidperc ;

void setup() {
  lcd.begin(16, 2);
  lcd.print("BOOTING UP");
  delay(1000);
  lcd.clear();
  pinMode(SwitchPin1 , INPUT);
  pinMode(alsens , OUTPUT);
  Serial.begin(9600);
}

void loop() {
   int sens;
  sens = analogRead(A0);
  Serial.println(sens);
  delay(1000);
  
  int gas = analogRead(A2);
  Serial.print(gas);
  
  int TempSens = analogRead(A3);
  tempsens1 = ((-40 + 0.488155 * (analogRead(A3) - 20)));
  
  
  if (digitalRead(SwitchPin4)){
  digitalWrite(TempSens, HIGH);
  
  lcd.print("Temperature:");
  lcd.print(tempsens1);
    lcd.print("C");
  delay(1000);
  }  
    else { digitalWrite(TempSens, LOW) ;
       }

    
  if (digitalRead(SwitchPin3)){
  digitalWrite(humidsens, HIGH);
    int gasl=analogRead(gassens);
 if (gasl >= 123);
  
  lcd.print("GAS LEAK !!!");
  }
   else { digitalWrite(gassens, LOW) ;
       }

  
  
  moistureval=analogRead(A1);
  Serial.print("Moisture Sensor Value:");
  Serial.println(moistureval);
  
  
  moistureval = analogRead(A1);
  humidperc = ((moistureval/870.00)*100);
  
  
  if (digitalRead(SwitchPin1)){
  digitalWrite(alsens, HIGH);
  }
  
  else { digitalWrite(alsens, LOW) ;
       }


  if (digitalRead(SwitchPin2)){
  digitalWrite(humidsens, HIGH);
    int val=analogRead(humidsens);
 
  lcd.print("Humidity:");
  lcd.print(humidperc); 
  lcd.print("%");
  }
  
  else { digitalWrite(humidsens, LOW) ;
       }

 
  
  
  if (sens >= 935 && sens <= 940) {
    Serial.println("Cloudy Sky"); 
   lcd.print("Cloudy Sky");
  }
  
  delay(500);
  lcd.clear();  
  
  
	if (sens >= 940 && sens <= 950) 
    {
    Serial.println("Partially Cloudy");
      lcd.print("Partially Cloudy");
    }
  
  delay(500);
  lcd.clear();

  
	if (sens >= 950 ) {
    Serial.println("Clear sky");  
    lcd.print("Clear Sky");
    }
  
  
  
  
  }
 
  

  

