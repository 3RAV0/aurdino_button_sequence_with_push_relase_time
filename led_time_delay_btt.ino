#define btt A1//pin location for first button and it's name
int val;//analog read value for buttons
int arr[400][1];//array to keep push order, pushing time, delay time

//led's pins and names in order
int l1 = 8;
int l2 = 9;
int l3 = 10;

//led's time keeper values for arr[i][1]
int l1t = 0;
int l2t = 0;
int l3t = 0;


//delay time keeper for arr[i][1]
int delt = 0;

//arr's first line for button keeping
int i = 0;


void setup() {
  Serial.begin(9600);//for trakcing the values from serial monitor
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
}

void loop() {
  val = analogRead(btt);
  Serial.println(val);//for printing different values of different buttons
  delay(100);


  //if first button being pushed value of it being between 1023 and 1000
  if (1000 < val && val <= 1023) {
    arr[i][0] = 1;//we will use this value for opening the 1st led with 1st button
    l1t++;//it's for pushing time we will store it in arr[i][1] for 1st led's lighting time
    arr[i][1] = l1t;
    i += 1;
    l1t = 0;
  }
  //if second button being pushed value of it being between 500 and 520
  else if (500 < val && val <= 520) {
    arr[i][0] = 2;//we will use this value for opening the 2nd led with 2nd button
    l2t++;//it's for pushing time we will store it in arr[i][1] for 2nd led's lighting time
    arr[i][1] = l2t;
    i += 1;
    l2t = 0;
  }
  //if third button being pushed value of it being between 300 and 350
  else if (300 < val && val <= 350) {
    arr[i][0] = 3;//we will use this value for opening the 3rd led with 3rd button
    l3t++;//it's for pushing time we will store it in arr[i][1] for 3rd led's lighting time
    arr[i][1] = l3t;
    i += 1;
    l3t = 0;
  }
  //after the first push it will store the times between 2 push in arr[x][0] = 4
  else if(i != 0 && val == 0){
    arr[i][0] = 4;//we will use this value for resetting all sequence
    delt++;
    arr[i][1] = delt;
    i += 1;
    delt = 0;
  }
  //if 4th button being pushed value of it being between 140 and 170 this code for resetting it

  else if (140 < val && val <= 170) {
    for(int j = 0; j < 400; j++){
      for(int z = 0; z < 2; z++){
        arr[j][z] = 0;
      }
    }
  }
  //if 5th button being pushed balue of it being between 130 and 140 this code for starting the sequence of lighting
  else if(130 < val && val <= 140){
    for(int k = 0; k < 400; k++){//this line for searching the arr 
      if(arr[k][0] == 1){
        while(arr[k][1] != 0){
          digitalWrite(l1, HIGH);
          arr[k][1]--;
          delay(120);
        }
        if(arr[k][1] == 0){
          digitalWrite(l1, LOW);
          //delay(arr[k][2]);
        }
      }  
      else if(arr[k][0] == 2){
        while(arr[k][1] != 0){
          digitalWrite(l2, HIGH);
          arr[k][1]--;
          delay(100);
        }
          if(arr[k][1] == 0)
            digitalWrite(l2, LOW);
      }
      else if(arr[k][0] == 3){
        while(arr[k][1] != 0){
          digitalWrite(l3, HIGH);
          arr[k][1]--;
          delay(100);
          }
          if(arr[k][1] == 0)
            digitalWrite(l3, LOW);
        }
      else if(arr[k][0] == 4){
        while(arr[k][1] != 0){
          digitalWrite(l1, LOW);
          digitalWrite(l2, LOW);
          digitalWrite(l3, LOW);
          delay((arr[k][1]));
          arr[k][1]--;
          delay(50); 
        }
      }
      else if(arr[k][0] == 0){
        digitalWrite(l1, LOW);
        digitalWrite(l2, LOW);
        digitalWrite(l3, LOW);
      }
    }
    i = 0;
    
  }
  
}
