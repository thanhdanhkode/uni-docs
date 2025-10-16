/**
 *
 * THIS FILE IS ONLY FOR ARDUINO IDE
 *
 */

// Khai báo chân pin kết nối với các cảm biến và động cơ
#define S1 0
#define S2 1
#define S3 2
#define S4 3
#define S5 4
#define ENA 5
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define ENB 10
#define TRIGGER 11
#define ECHO 12
#define LED0 LED_BUILTIN
#define BuzzerDigital 13

int currentDistance, safeDistance = 10, speed = 20, minSpeed = 60, minTurnSpeed = 40, turnSpeed1 = 50, turnSpeed2 = 80, stopSpeed = 0, S1Val, S2Val, S3Val, S4Val, S5Val; // Khai báo biến để lưu trữ giá trị cảm biến và khoảng cách (Giá trị là số nguyên)
unsigned long duration;                                                                                                                                                   // Khai báo biến không dấu để lưu trữ thời gian

// Khai báo hàm setup và loop
void setup();
void loop();

// Khai báo hàm Setup để khởi tạo các chân pin
void setup()
{
  Serial.begin(9600); // Khởi động Serial với tốc độ 9600 bps
  // Khai báo chế độ cho từng chân pin
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED0, OUTPUT);
  pinMode(BuzzerDigital, OUTPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  delay(1000); // Tạm dừng 1 giây
}

// Hàm vòng lặp chính
void loop()
{
  S1Val = digitalRead(S1); // Đọc giá trị từ cảm biến IR S1
  S2Val = digitalRead(S2); // Đọc giá trị từ cảm biến IR S2
  S3Val = digitalRead(S3); // Đọc giá trị từ cảm biến IR S3
  S4Val = digitalRead(S4); // Đọc giá trị từ cảm biến IR S4
  S5Val = digitalRead(S5); // Đọc giá trị từ cảm biến IR S5

  digitalWrite(TRIGGER, LOW);                   // Tắt chân TRIGGER cảm biến siêu âm
  delayMicroseconds(2);                         // Tạm dừng 2 micro giây
  digitalWrite(TRIGGER, HIGH);                  // Bật chân TRIGGER cảm biến siêu âm
  delayMicroseconds(3);                         // Tạm dừng 3 micro giây
  digitalWrite(TRIGGER, LOW);                   // Tắt chân TRIGGER cảm biến siêu âm
  duration = pulseIn(ECHO, HIGH);               // Đo thời gian phản hồi từ cảm biến siêu âm
  currentDistance = int(duration / 2 / 29.412); // Tính khoảng cách từ thời gian phản hồi (đơn vị cm)

  Serial.print("[DEBUG]");
  Serial.print(" S1: ");
  Serial.print(S1Val);
  Serial.print(" S2: ");
  Serial.print(S2Val);
  Serial.print(" S3: ");
  Serial.print(S3Val);
  Serial.print(" S4: ");
  Serial.print(S4Val);
  Serial.print(" S5: ");
  Serial.print(S5Val);
  Serial.println();

  // Nếu khoảng cách hiện tại <= 10 cm, dừng động cơ
  if (currentDistance <= safeDistance)
  {
    // Giá trị digital của các chân IN1, IN2, IN3, IN4 đều là LOW (hay là 0) ==> dừng động cơ
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, stopSpeed); // Tốc độ động cơ A
    analogWrite(ENB, stopSpeed); // Tốc độ động cơ B
    digitalWrite(LED0, HIGH);    // Bật đèn LED báo hiệu
    delay(200);                  // Tạm dừng 50ms
    digitalWrite(LED0, LOW);     // Tắt đèn LED báo hiệu
    delay(200);
    digitalWrite(LED0, HIGH);
    delay(200);
    digitalWrite(LED0, LOW);
  }
  else
  {
    // 0 luôn là FAlSE, 1 luôn là TRUE
    // Nếu giá trị của S1, S2, S4, S5 đều là TRUE (hay là 1) hoặc tất cả đều là FALSE (hay là 0) nghịch đảo lại tất cả thành TRUE (hay là 1) thì xe sẽ tiến với tốc độ ...
    if (S1Val && S2Val && S4Val && S5Val)
    {
      // Xe đi thẳng
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      // Tốc độ ban đầu để xe có thể di chuyển
      analogWrite(ENA, 100); // Tốc đọ động cơ A
      analogWrite(ENB, 100); // Tốc đọ động cơ B
      delay(50);
      // // Giảm/Tằng tốc độ xe theo mức cần thiết
      analogWrite(ENA, 20); // Tốc độ động cơ A
      analogWrite(ENB, 20); // Tốc độ động cơ B
      delay(100);
    }
    else if (!S1Val) // Giá trị nghịch đảo của S1 bằng 1 thì TRUE
    {
      // Xe quay trái
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 150); // Tốc độ động cơ A
      analogWrite(ENB, 150); // Tốc độ động cơ B
      delay(100);
      analogWrite(ENA, 30); // Tốc độ động cơ A
      analogWrite(ENB, 30); // Tốc độ động cơ B
      delay(75);
    }
    else if (!S2Val) // Giá trị nghịch đảo của S2 bằng 1 thì TRUE
    {
      // Xe quay trái
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 150); // Tốc độ động cơ A
      analogWrite(ENB, 150); // Tốc độ động cơ B
      delay(50);
      analogWrite(ENA, 30); // Tốc độ động cơ A
      analogWrite(ENB, 30); // Tốc độ động cơ B
      delay(75);
    }
    else if (!S1Val && !S2Val) // Giá trị nghịch đảo của S1 và S2 bằng 1 thì TRUE
    {
      // Xe quay trái
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 150); // Tốc độ động cơ A
      analogWrite(ENB, 150); // Tốc độ động cơ B
      delay(100);
      analogWrite(ENA, 30); // Tốc độ động cơ A
      analogWrite(ENB, 30); // Tốc độ động cơ B
      delay(75);
    }
    else if (!S4Val) // Giá trị nghịch đảo của S4 bằng 1 thì TRUE
    {
      // Xe quay phải
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 150); // Tốc độ động cơ A
      analogWrite(ENB, 150); // Tốc độ động cơ B
      delay(50);
      analogWrite(ENA, 0); // Tốc độ động cơ A
      analogWrite(ENB, 0); // Tốc độ động cơ B
      delay(50);
    }
    else if (!S5Val) // Giá trị nghịch đảo của S5 bằng 1 thì TRUE
    {
      // Xe quay trái
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 150); // Tốc độ động cơ A
      analogWrite(ENB, 150); // Tốc độ động cơ B
      delay(50);
      analogWrite(ENA, 30); // Tốc độ động cơ A
      analogWrite(ENB, 30); // Tốc độ động cơ B
      delay(75);
    }
    else if (!S4Val && !S5Val) // Giá trị nghịch đảo của S4 và S5 bằng 1 thì TRUE
    {
      // Xe quay phải
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 150); // Tốc độ động cơ A
      analogWrite(ENB, 150); // Tốc độ động cơ B
      delay(75);
      analogWrite(ENA, 30); // Tốc độ động cơ A
      analogWrite(ENB, 30); // Tốc độ động cơ B
      delay(75);
    }
    else // Khác (hay các trường hợp còn lại)
    {
      // Dừng động cơ
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, stopSpeed); // Tốc độ động cơ A
      analogWrite(ENB, stopSpeed); // Tốc độ động cơ B
      digitalWrite(LED0, HIGH);    // Bật đèn LED báo hiệu
      delay(200);                  // Tạm dừng 50ms
      digitalWrite(LED0, LOW);     // Tắt đèn LED báo hiệu
      delay(200);
      digitalWrite(LED0, HIGH);
      delay(200);
      digitalWrite(LED0, LOW);
    }
  }
}
