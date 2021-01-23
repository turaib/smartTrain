/**
 * Author: Turai Botond
 */
#include <Arduino.h>
#include <Scheduler.h>
#ifndef TRAIN
#define TRAIN

#define MIN_SPEED 150
#define MAX_SPEED 500 //max 1023

/**
 * The Train object is responsible for controlling the locomotive
 */
class Train:public Task{
  String id;  //Train name
  int speed;  //Train speed
  bool engine;  //Engine status (on/off)
  int outA;     //Output pin (GPIO 0)
  
  bool gyorsulas;       //acceleration
  int gyorsulas_merteke;  //degree of acceleration
  unsigned long acc_time;
  int target_speed;     
  
  public:
  /**
   * The variables are initialized in the constructor and the locomotive is ready for operation
   */
  Train(String name, int oA):id(name), speed(0), engine(false),outA(oA), gyorsulas(false), gyorsulas_merteke(20){
    speed=MIN_SPEED;
    pinMode(outA,OUTPUT);
    analogWrite(outA,0);
  }

  /**
   * The locomotive must proceed at a new speed.
   */
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
  /**
   * Turns the engine on (If the speed is not 0, the locomotive starts)
   */
  void engineON(){
    engine=true;
    controlEngine();
  }

  /**
   * The locomotive stops immediately (emergency brake)
   */
  void engineOFF(){
    engine=false;
    controlEngine();
  }

  /**
   * Set engine status
   */
  void setEngine(bool mode){
    engine=mode;
    controlEngine();
  }

  /**
   * It can be used to query the speed of the locomotive
   */
  int getSpeed(){
    return speed;
  }

  /**
   * It can be used to query the name of the locomotive
   */
  String getName(){
    return id;
  }

  /**
   * standard toString which returns the locomotive name and speed
   */
  String toString(){
    return id+String(" engine: ")+String(engine)+ String(" speed:")+String(speed);
  }

  /**
   * A method for turning the gradual acceleration function on and off
   */
  void setAcceleration(bool v){
    gyorsulas=v;
  }
  /**
   * Only required if the gradual acceleration of the locomotive is switched on
   */
  void loop(){
    if(gyorsulas){
      if(acc_time+gyorsulas_merteke < millis()){
        if(speed>target_speed){
          speed-=1;
        }else if(speed<target_speed){
          speed+=1;
        }
        controlEngine();
        acc_time=millis();
      }
    }
  }
  
  private:

  /**
   * A private method that controls the motor directly
   */
  void controlEngine(){
    if(engine==true && speed > MIN_SPEED){
      analogWrite(outA,speed);
    }else{
      analogWrite(outA,0);
    }
  }
};

#endif
