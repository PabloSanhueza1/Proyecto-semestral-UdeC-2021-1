#include <Servo.h>
#include <LiquidCrystal.h>

Servo s1; // se le declara un nombre
LiquidCrystal lcd(4, 5, 8, 9, 10, 11);

int h=0,m=0,s=59; // hora, minuto, segundo
int auxs=10; // variable auxiliar de los segundos
int aux1=h; // variable auxiliar "1" de temporizador en función de las horas
void setup()
{
  lcd.begin(16, 2);
  
  s1.attach(3);
  
  pinMode(6, OUTPUT);
  
  s1.write(0); //Servo en posición inicial, 0 grados
  
  lcd.setCursor(0,0);
  lcd.print(".*~ Feedoggy ~*.");
  
  lcd.setCursor(4,1);
  lcd.print("0");
  lcd.setCursor(5,1); // se imprime la hora de inicio (0:0:59) por primera vez
  lcd.print("0");
  lcd.setCursor(6,1);
  lcd.print(":");
  lcd.setCursor(7,1);
  lcd.print("00");
  lcd.setCursor(9,1);
  lcd.print(":");
  lcd.setCursor(10,1);
  lcd.print(s);
}
void loop()
{
  
  lcd.setCursor(5,1); // se imprime la hora de inicio (dentro del loop)
  lcd.print(h);
  lcd.setCursor(6,1);
  lcd.print(":");
  lcd.setCursor(7,1);
  lcd.print(m);
  lcd.setCursor(9,1);
  lcd.print(":");
  lcd.setCursor(10,1);
  lcd.print(s);
  
  while(aux1>=0){
    
  	for(int i=0;i<=49;i++){ //avanzan los segundos
  		lcd.setCursor(10,1);
  		lcd.print(s-i);
  		delay(1000);
  		}
  		lcd.setCursor(10,1);
  		lcd.print("0");
  	for(int i=0;i<=9;i++){ //avanzan segundos debajo del 10 para dar uniformidad al temporizador
  		lcd.setCursor(11,1);
  		lcd.print(auxs-1-i);
  		delay(1000);
  		}
   		if(m==0){
            if(h>0){
            m=59;
      		lcd.setCursor(7,1);
      		lcd.print(m);
      		h=h-1;
            aux1=h;
            lcd.setCursor(5,1);
            lcd.print(h);
            	}else{
              	aux1=aux1-1;
              	lcd.setCursor(5,1);
              	lcd.print(0);
            	}
    		}else{
          		if(m<=10){
    			lcd.setCursor(7,1);
  				lcd.print("0");
          		m=m-1;
          		lcd.setCursor(8,1);
  				lcd.print(m);
    			}
        if(m>10){
      		m=m-1;
      		lcd.setCursor(7,1);
      		lcd.print(m);
    		}
        }
    s=59; //los segundos vuelven a 59
  }
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Llenando Platito");
  lcd.setCursor(2,1);
  lcd.print(".~- ^w^ ~-°");
  
  tone(6,262,300);
  
  s1.write(90); //servo se mueve 90 grados
  delay(1000);
  
  digitalWrite(3,LOW); //servo se queda quieto (se apaga)
  delay(5000);
  
  s1.write(0); //servo vuelve a su posicion inicial
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print(".*~ Feedoggy ~*.");
  
  lcd.setCursor(4,1);
  lcd.print("0");
  
  h=7; //todas las variables vuelven a mostrar 8 horas restantes
  m=59;
  s=59;
  aux1=h;
}