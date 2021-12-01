#include <BluetoothSerial.h>
BluetoothSerial BT;

int i = 0;
int k = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  BT.begin("doudouTestEsp32");//請改名
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);
    if(BTdata=="1"){
      i++;
      if( i == 1 ){
            digitalWrite(27,HIGH);
      }
      else if( i == 2 ){
            digitalWrite(14,HIGH);
            i = 0;
      }
    }
    if(BTdata=="2"){
      k++;
      if( k == 1 ){
            digitalWrite(12,HIGH);
      }
      else if( k == 2 ){
            digitalWrite(13,HIGH);
            k = 0;
      }
    }
    
    if(BTdata=="New Game"){
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      digitalWrite(14,LOW);
      digitalWrite(27,LOW);
      i = 0;
      k = 0;
      }    

        }

  delay(1);
}
//|| "disconnect"
