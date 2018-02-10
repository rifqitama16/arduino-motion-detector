#define SSID "Masih Wifi Tetangga"
#define PASS "1103130000"
#define HOST "aldebaran.esy.es"
boolean stat;
int motion;

void setup() {
  pinMode(3, INPUT); //pin motion sensor
  Serial.begin(115200);
  delay(8000);
  connectWifi();
}

void loop() {  
  if (digitalRead(3) == HIGH){
    if (stat == LOW){
      Serial.println("Motion detected!");
      stat = HIGH; motion = 1;
      sendData(String(motion));
    }
  }
  else {
    if (stat == HIGH){
      Serial.println("Negative");
      stat = LOW; motion = 0;
      sendData(String(motion));
    }
  }
}

void sendData(String motion){
  Serial.println("AT");
  delay(500);
  if(Serial.find("OK")){
    String cmd = "AT+CIPSTART=\"TCP\",\"";
    cmd += HOST;
    cmd += "\",80";
    Serial.println(cmd);
    delay(500);
    cmd = "GET /project/1/addData.php?motionornot="+motion+" HTTP/1.1\r\nHost: "+HOST+"\r\n\r\n";
    Serial.print("AT+CIPSEND=");
    Serial.println(cmd.length());
    if(Serial.find(">")){
      Serial.println(cmd);
      delay(5000);
    }
    else{
      Serial.println("ERROR CONNECTION #2");
    }
  }
  else{
    Serial.println("ERROR CONNECTION #1");
  }
}

void connectWifi(){
  Serial.println("AT+CWQAP");
  String cmd = "AT+CWJAP=\"";
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  Serial.println(cmd);
  delay(4000);
}

