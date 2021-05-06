#include <Arduino.h>
#include <Scheduler.h>
#ifndef TRAIN
#define TRAIN

#define MIN_SPEED 150
#define MAX_SPEED 600 //max 1023


class Train:public Task{
  String id;
  int speed;
  int target_speed;
  bool engine;
  int outA;
  int outB;
  bool forward;
  bool target_dir;
  
  bool gyorsulas;
  int gyorsulas_merteke;
  unsigned long acc_time;
  
  
  public:
  Train(String name, int oA, int oB):id(name), speed(0), engine(false),forward(false), outA(oA), outB(oB),target_dir(false), gyorsulas(false), gyorsulas_merteke(20){
    pinMode(outA,OUTPUT);
    pinMode(outB, OUTPUT);
    analogWrite(outB,0);
    analogWrite(outA,0);
  }
  void setForward(const bool fw){
    target_dir=fw;
    if(!gyorsulas){
      forward=target_dir;
      controlEngine();
    }
  }
  void setSpeed(int sebesseg){    
    if(sebesseg>=0 && sebesseg<=255){
      int uj_sebesseg=map(sebesseg,0,255,MIN_SPEED, MAX_SPEED);
      if(gyorsulas){
        target_speed=uj_sebesseg;
        acc_time=millis();
      }
      else
        speed=uj_sebesseg;
    }
    controlEngine();    
  }
  
  void engineON(){
    engine=true;
    controlEngine();
  }
  
  void engineOFF(){
    engine=false;
    controlEngine();
  }
  void setEngine(bool mode){
    engine=mode;
    controlEngine();
  }
  
  int getSpeed(){
    return speed;
  }
  String getName(){
    return id;
  }
  String toString(){
    return id+String("\tEngine: ")+String(engine)+ String("\tSpeed:")+String(speed)+String("\tTarget Speed:")+String(target_speed)
    +String("\tDirection:")+String(forward?"true":"false")+String("\tTarget direction:")+String(target_dir?"true":"false");
  }
  void setAcceleration(bool v){
    gyorsulas=v;
  }

  void loop(){
    if(gyorsulas){
      if(acc_time+gyorsulas_merteke < millis()){
        if(forward != target_dir && speed<=MIN_SPEED+20){
          forward=target_dir;
        }
        int szorzo=forward != target_dir ? -1 : 1;
        
        if(speed > (szorzo * target_speed)){
          speed-=1;
        }else if(speed <(szorzo * target_speed)){
          speed+=1;
        }
        controlEngine();
        acc_time=millis();
      }
    }
  }
  
  private:
  void controlEngine(){
    if(engine && speed > MIN_SPEED){
      analogWrite(outA,(forward)? speed:0);
      analogWrite(outB,(forward)? 0:speed);
    }else{
      analogWrite(outA,0);
      analogWrite(outB,0);
    }
    Serial.println(this->toString());
  }
};

#endif
