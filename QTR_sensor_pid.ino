float Kp=2.5,Ki=1,Kd=8;
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_P=0;

int initial_motor_speed=80;


 int sensor1=7;
 int sensor2=6;
 int sensor3=5;
 int sensor4=4;
 int sensor5=3;
 int sensor6=2;
 int sensor7=14;
 int sensor8=15;
 
const int motor_right_input=8;
const int motor_right_output=9;
const int motor_left_input=12;
const int motor_left_output=13;
const int enable_pin_1=10; //left
const int enable_pin_2=11; //right

const int detect_black=1;
const int detect_white=0;

 int qtr_sensor_1,qtr_sensor_2,qtr_sensor_3,qtr_sensor_4,qtr_sensor_5,qtr_sensor_6,qtr_sensor_7,qtr_sensor_8;
int qtr_sensor_last_data=0;
void setup() {                
  
  pinMode(motor_left_input,OUTPUT);
  pinMode(motor_left_output,OUTPUT);
  pinMode(motor_right_input,OUTPUT);
  pinMode(motor_right_output,OUTPUT);
  
  pinMode(enable_pin_1,OUTPUT);
  pinMode(enable_pin_2,OUTPUT);
  
  
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  pinMode(sensor5,INPUT);
  pinMode(sensor6,INPUT);
  pinMode(sensor7,INPUT);
  pinMode(sensor8,INPUT);
  
  delay(2000);
  Serial.begin(9600);
  
}

void loop()
{
    qtr_sensor();
    calculate_pid();
    motor_control();
}

void qtr_sensor()
{
   
qtr_sensor_1=digitalRead(sensor1);
qtr_sensor_2=digitalRead(sensor2);
qtr_sensor_3=digitalRead(sensor3);
qtr_sensor_4=digitalRead(sensor4);
qtr_sensor_5=digitalRead(sensor5);
qtr_sensor_6=digitalRead(sensor6);
qtr_sensor_7=digitalRead(sensor7);
qtr_sensor_8=digitalRead(sensor8);
  
  
//  Serial.print(qtr_sensor_1);
//  Serial.print("   ");
//  Serial.print(qtr_sensor_2);
//  Serial.print("   ");
//  Serial.print(qtr_sensor_3);
//  Serial.print("   ");
//  Serial.print(qtr_sensor_4);
//  Serial.print("   ");
//  Serial.print(qtr_sensor_5);
//  Serial.print("   ");
//  Serial.print(qtr_sensor_6);
//  Serial.print("   ");
//  Serial.print(qtr_sensor_7);
//  Serial.print("   ");
//  Serial.println(qtr_sensor_8);
//  delay(100);//
  

   if(qtr_sensor_1==1 && qtr_sensor_2==0 && qtr_sensor_3==0 &&  qtr_sensor_4==0 && qtr_sensor_5==0 &&  qtr_sensor_6==0 && qtr_sensor_7==0 && qtr_sensor_8==0  )
  {
    error=7;
 
  }
  
  if(qtr_sensor_1==1 && qtr_sensor_2==1 && qtr_sensor_3==0 &&  qtr_sensor_4==0 && qtr_sensor_5==0 &&  qtr_sensor_6==0 && qtr_sensor_7==0 && qtr_sensor_8==0  )
  {
    error=6;
  }
  
  if(qtr_sensor_1==1 && qtr_sensor_2==1 && qtr_sensor_3==1 &&  qtr_sensor_4==0 && qtr_sensor_5==0 &&  qtr_sensor_6==0 && qtr_sensor_7==0 && qtr_sensor_8==0)
  {
    error=5;
    
  }
  
  
  if(qtr_sensor_1==0 && qtr_sensor_2==1 && qtr_sensor_3==1 &&  qtr_sensor_4==0 && qtr_sensor_5==0 &&  qtr_sensor_6==0 && qtr_sensor_7==0 && qtr_sensor_8==0)
  {
    error=4;
  }
  
  if(qtr_sensor_1==0 && qtr_sensor_2==1 && qtr_sensor_3==1 && qtr_sensor_4==1 && qtr_sensor_5==0 &&  qtr_sensor_6==0 && qtr_sensor_7==0 && qtr_sensor_8==0  )
  {
    error=3;
  
  }
  
  if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==1 && qtr_sensor_4==1 && qtr_sensor_5==0 &&  qtr_sensor_6==0 && qtr_sensor_7==0 && qtr_sensor_8==0)
  {
     error=2;
  
  }
  
    if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==1 && qtr_sensor_4==1 && qtr_sensor_5==1 &&  qtr_sensor_6==0 && qtr_sensor_7==0 && qtr_sensor_8==0)
  {
     error=1;
  
  }
  
 
 //-----------------------------------
 
    if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==0 && qtr_sensor_4==1 && qtr_sensor_5==1 &&  qtr_sensor_6==0 && qtr_sensor_7==0 && qtr_sensor_8==0)
  {
    
   error=0;
    
  }
  
  //----------------------------------
 
 
  
   if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==0 && qtr_sensor_4==1 && qtr_sensor_5==1 &&  qtr_sensor_6==1 && qtr_sensor_7==0 && qtr_sensor_8==0)
  {
    error=-1;
  }
  
  if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==0 && qtr_sensor_4==0 && qtr_sensor_5==1 &&  qtr_sensor_6==1 && qtr_sensor_7==0 && qtr_sensor_8==0)
  {
   error=-2;
   
  }
  
  if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==0 && qtr_sensor_4==0 && qtr_sensor_5==1 &&  qtr_sensor_6==1 && qtr_sensor_7==1 && qtr_sensor_8==0)
  {
    error=-3;
   
  }
  
 if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==0 && qtr_sensor_4==0 && qtr_sensor_5==0 &&  qtr_sensor_6==1 && qtr_sensor_7==1 && qtr_sensor_8==0)
  {
   error=-4;
    
  }
  
  if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==0 && qtr_sensor_4==0 && qtr_sensor_5==0 &&  qtr_sensor_6==1 && qtr_sensor_7==1 && qtr_sensor_8==1)
  {
    error=-5;
    
  }
  
    if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==0 && qtr_sensor_4==0 && qtr_sensor_5==0 &&  qtr_sensor_6==0 && qtr_sensor_7==1 && qtr_sensor_8==1)
  {
    error=-6;
  
  }
  
 if(qtr_sensor_1==0 && qtr_sensor_2==0 && qtr_sensor_3==0 && qtr_sensor_4==0 && qtr_sensor_5==0 &&  qtr_sensor_6==0 && qtr_sensor_7==0 && qtr_sensor_8==1)
  {
    error=-7;
  }
  
     
     
}


void calculate_pid()
{
    P = error;
    I = error + previous_P;
    D = P-previous_P;
    
    PID_value = (Kp*P) + (Ki*I) + (Kd*D);
    previous_P=P;
    //previous_error=error;
//    Serial.print("Kp*P:");
//    Serial.print(Kp*P);
//    Serial.print("   Ki*I:");
//    Serial.print(Ki*I);
//    Serial.print("   Kd*D:");
//    Serial.print(Kd*D);
//    
//    Serial.print("   PID value: ");
//    Serial.print(PID_value);
//    delay(200);
}



void motor_control()
{
   
    int left_motor_speed = initial_motor_speed-PID_value;
    int right_motor_speed = initial_motor_speed+PID_value;
    
    
    constrain(left_motor_speed,0,255);
    constrain(right_motor_speed,0,255);
    
    analogWrite(10,left_motor_speed);   //Left Motor Speed
    Serial.print("     Sol motor:");
    Serial.print(left_motor_speed);
    analogWrite(11,right_motor_speed);
    Serial.print(" Sag motor:");
    Serial.println(right_motor_speed);
      
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
}
