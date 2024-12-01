#define IN1 7
#define IN2 8
#define lenhet 2 //nút nhấn lên kính khi nhấn dừng khi ngừng nhấn
#define xuonghet 3 //Nút nhấn lên hết
#define len1 4
#define xuong1 5
#define mua 6
int dong = A0;
int i =0,j=0;
float setdong = 3; //Set dòng tải max bảo vệ chống kẹt từ 0.0 -> 20.0 đối với module ACS20A

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(len1, INPUT_PULLUP);
pinMode(xuong1, INPUT_PULLUP);
pinMode(lenhet, INPUT_PULLUP);
pinMode(xuonghet, INPUT_PULLUP);

pinMode(mua, INPUT_PULLUP);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);

}
void len(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void xuong(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
void dung(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void loop() {
 float I = analogRead(dong)/1023.0 * 40.0;  //sử dụng module dòng 20A
 I = I - 18.9;
 if(I<=0)I=0;
  // put your main code here, to run repeatedly:
  Serial.println(I);
 while(I >= setdong){
  float I = analogRead(dong)/1023.0 * 40.0;  //sử dụng module dòng 20A
 I = I - 18.9;
 if(I<=0)I=0;
  if(I<=0)I=0;
  i=0;
  j=0;
    xuong();
  }
if(digitalRead(lenhet) ==0){
i=1;
j=0;
}

if(digitalRead(xuonghet) ==0 ){
i=0;
j=1;
}
if(digitalRead(mua) ==0 && digitalRead(xuong1) == 1){
  i=1;
  j=0;
}

if (digitalRead(xuong1) == 0){
  xuong();
  i=0;
  j=0;
}
if (digitalRead(len1) == 0){
  len();
  i=0;
  j=0;
}
if(i==1){
  len();
}
else if(j == 1){
  xuong();
}
else if(digitalRead(len1) == 1 && digitalRead(xuong1) == 1 && i==0 && j==0)
{dung();}
}
