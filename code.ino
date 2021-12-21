int LED1 = 2, LED2 = 3, LED3 = 4, LED4 = 5, LED5 = 6, LED6 = 7, LED7 = 8, LED8 = 9, LED9 = 10;
int BUT1 = 12;
bool LED[9] = { };

int COUNTER = 0;

bool buttonState = 0, lastButtonState = 0;

bool FOREVER = 1;

void setup() {
  for (int LED = 2; LED <= 10; LED++)
    pinMode(LED, OUTPUT);

  pinMode(BUT1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  for (int a = 2; a <= 11; a++){
 	digitalWrite(a, 1);
 
    if (LED[a - 1] == 0){
      buttonState = !digitalRead(BUT1);
      if (buttonState != lastButtonState){
        if (buttonState == 1){
          LED[a - 1] = 1;
          COUNTER++;
        }
        delay(150);
      }
      else{
       delay(150);
       digitalWrite(a, 0);
       delay(150);
      }

      lastButtonState = buttonState;
    }
    else{
      buttonState = !digitalRead(BUT1);
      if (buttonState != lastButtonState && buttonState == 1)
          COUNTER++;

      delay(300);
      lastButtonState = buttonState;
    }
  }
 
  if (LED[1] && LED[2] && LED[3] && LED[4] && LED[5] && LED[6] && LED[7] && LED[8] && LED[9]){
    Serial.print("Congratulations, you did it! Number of clicks: ");
    Serial.println(COUNTER);
    while (FOREVER = 1){
      for (int i = 2; i <= 10; i++)
        digitalWrite(i, 0);
 
      delay(500);
 
      for (int i = 2; i <= 10; i++)
        digitalWrite(i, 1);
 
      delay(500);
    }
  }
}