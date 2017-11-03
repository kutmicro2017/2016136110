#define UpDown_R 4 //상하 신호등
#define UpDown_Y 5
#define UpDown_G 6
#define LeftRight_R 7 // 좌우 신호등
#define LeftRight_Y 8
#define LeftRight_G 9
#define Button_A 2 // 스위치
int delaytime = 40000; //40초
volatile bool state = true; //스위치 변수, 누를 시 false

void setup() {  // OUTPUT 세팅
  pinMode(UpDown_R, OUTPUT);
  pinMode(UpDown_G, OUTPUT);
  pinMode(UpDown_Y, OUTPUT);
  pinMode(LeftRight_R, OUTPUT);
  pinMode(LeftRight_G, OUTPUT);
  pinMode(LeftRight_Y, OUTPUT);
  pinMode(Button_A, INPUT_PULLUP); //기본값 HIGH input과는 다르게 프로세서 내부 저항을 사용
  attachInterrupt(0,Botton, FALLING); // 인터럽트 0 은 핀 2에 상호작용 따라서 스위치를 2번에 달것
}

void loop() {
// -----------------------------------------------------
//순서는 상-하-좌-우
// -----------------------------------------------------


//------------맨처음, 상 하 신호등만 초록색 ----------------  
digitalWrite(LeftRight_R, HIGH);
digitalWrite(UpDown_R, LOW);
digitalWrite(UpDown_G, HIGH);
for(int count=0;count<40;count++){ //40초간 초록불 유지
  if(state == false){ //스위치가 눌리면
    delay(1000); //1초 후
    digitalWrite(UpDown_G, LOW);
    Yellow(UpDown_Y);
    digitalWrite(UpDown_R, HIGH);
    digitalWrite(LeftRight_R, LOW);
    digitalWrite(LeftRight_G, HIGH);
    delay(5000);
    digitalWrite(LeftRight_G, LOW);
    Yellow(LeftRight_Y);
    state = true;
    if(count>=25){ //25초 이상이 지난 후 누르면 for문 빠져나옴
      break; 
    }
    else{ //25초 이하라면 다시 상하 켜줌
      digitalWrite(UpDown_R, LOW);
      digitalWrite(UpDown_G, HIGH);
      digitalWrite(LeftRight_G, LOW);
      digitalWrite(LeftRight_R, HIGH);
      count = count + 15; //15초가 지난만큼 추가
    }
  }
  delay(1000);
}
digitalWrite(UpDown_R, LOW);
digitalWrite(UpDown_G, LOW);
Yellow(UpDown_Y);
digitalWrite(UpDown_R, HIGH);
digitalWrite(LeftRight_R, LOW);
digitalWrite(LeftRight_G, HIGH);
delay(delaytime); //40초간 좌우 초록불 온
digitalWrite(LeftRight_G, LOW);
Yellow(LeftRight_Y);
}











//----------------------------------함수들--------------------------------
void Botton(){ //스위치가 눌렸을 때 실행되는 함수
 if(digitalRead(UpDown_G) == HIGH) state = false; //스위치가 눌리면 state의 값을 바꿔준다
}




void Yellow(const int LED) {  //yellow신호 점멸
   for(int i =0; i < 5; i++) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
   }
}

//----------------------------------------------------------------------------
