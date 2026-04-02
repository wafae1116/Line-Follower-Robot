// ===== Sensors =====

int leftSensor = A3;

int centerSensor = A4;

int rightSensor = A5;


// ===== Motor driver L298N =====

int ENA = 5;

int IN1 = 10;

int IN2 = 7;

int ENB = 6;

int IN3 = 8;

int IN4 = 9;

// ===== loss dtction =====

int ld =0;

void setup() {

  pinMode(leftSensor, INPUT);

  pinMode(centerSensor, INPUT);

  pinMode(rightSensor, INPUT);

  pinMode(ENA, OUTPUT);

  pinMode(IN1, OUTPUT);

  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);

  pinMode(IN3, OUTPUT);

  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  Serial.begin(9600); //setting serial monitor at a default baund rate of 9600
}

void loop()
{
  int l = digitalRead(leftSensor);

  int c = digitalRead(centerSensor);

  int r = digitalRead(rightSensor);

  // ===== FOLLOW THE LINE =====

  if (l==LOW && c==HIGH && r==LOW)
  {
    forward();
    ld =0;
  }

  // ===== TURN LEFT TO LINE =====

  else if( l==HIGH && r==LOW)
  {
    leftTurn();
    ld =1;
  }

  // ===== TURN RIGHT TO LINE =====

  else if(l==LOW && r==HIGH)
  {
    rightTurn();
    ld =2;
  }

  // ===== INTRSCTION =====

  else if(l==HIGH && c==HIGH && r==HIGH)
  {
    forward();
    ld =0;
  }

  // ===== LINE LOSS =====

  else if(l==LOW && c==LOW && r==LOW)
  {
    analogWrite(ENA, 100);
    analogWrite(ENB, 100);

    // if(ld ==0)
    // {
    //   backward();
    // }
    if(ld ==1)
    {
      leftTurn();
    }
    else if(ld ==2)
    {
      rightTurn();
    }
  }

  else
  {
    forward();
  }
}

// ===== Motor Functions =====

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rightTurn()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void leftTurn()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void rotate360()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(1000); // adjust time until robot rotates 360°
}

void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
