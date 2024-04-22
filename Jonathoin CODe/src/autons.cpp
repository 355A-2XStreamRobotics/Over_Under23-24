#include "vex.h"
/*
    enum IntakeSensor {
    Intake,
    Hold,
    Outake,
  
  };

void AUTOIN(IntakeSensor){
  switch (IntakeSensor()){
    case Intake:
     if(ID1.objectDistance(mm)<=70){
        I1.setVelocity(80,percent);
        I1.spin(forward);
        Brain.Screen.printAt(1, 30, "Intake");
      }
      if(ID1.objectDistance(mm)>=70){
        break;

      }
    case Hold:
      if(ID1.objectDistance(mm)>=70){
        I1.stop();
        Brain.Screen.clearLine(1,30);
        Brain.Screen.printAt(1, 30, "Hold");
     }
     if(ID1.objectDistance(mm)<=70){
       IntakeSensor() == Intake;
      }
    case Outake:
      if(ID1.objectDistance(mm)>= 100){
       I1.spin(reverse);
        Brain.Screen.clearLine(1,30);
        Brain.Screen.printAt(1, 30, "Outake");
     }
  }

}
*/

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(4, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 150, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void fast_default_constants(){
  chassis.set_drive_constants(10, 3.0, 0, 10, 0);
  chassis.set_heading_constants(6, .3, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}
void Slow_Turn_Constant(){
  chassis.set_turn_constants(6, .4, .03, 3, 15);
}
void Slow_Drive_Constant(){
  chassis.set_drive_constants(2, 3.0, 0, 10, 0);
}

void ESlow_Turn_Constant(){
  chassis.set_turn_constants(3, .4, .03, 3, 15);
}

int DeployWingLeft(){
  wait(400,msec);
  WANGL.set(true);
  return 0;
}
/*
void IntakeS(){
switch (IntakeSensor()){
  case Intake:
    if(ID1.objectDistance(mm)<=70){
      I1.setVelocity(80,percent);
      I1.spin(forward);
    }
    if(ID1.objectDistance(mm)>=70){
      break;
    }
  case Hold:
    if(ID1.objectDistance(mm)>=70){
      I1.stop();
    }
    if(ID1.objectDistance(mm)<=70){
      IntakeSensor() == Intake;
    }
  case Outake:
    if(ID1.objectDistance(mm)>= 100){
      I1.spin(reverse);
    }

}

}
*/

int SetHeading(){
  wait(105,msec);
  //chassis.turn_to_angle(-270);
  chassis.set_heading(-90);
  return 0;
}



void AutonTesting(void){
extern enum auton_modes AutonomousMode;
default_constants();
chassis.drive_max_voltage = 12;
chassis.drive_settle_error = 3;

if(AutonomousMode == RedMode){
//AWP Close
I1.setVelocity(100,percent);
chassis.drive_distance(-6);
WANGR.set(true);
wait(500,msec);
chassis.turn_to_angle(-55);
WANGR.set(false);
chassis.turn_to_angle(0);
chassis.drive_distance(14);
chassis.turn_to_angle(-45);
chassis.drive_distance(34);
I1.spin(reverse);

}

if(AutonomousMode == BlueMode){
//Far Side Aution
I1.setVelocity(80,percent);
chassis.drive_with_voltage(10,10);
wait(200,msec);
chassis.drive_distance(.01);
WANGR.set(true);
wait(100,msec);
Slow_Turn_Constant();
chassis.turn_to_angle(-20);
WANGR.set(false);
I1.spinFor(-950,degrees);
chassis.drive_distance(28.5);
chassis.drive_distance(-16.5);
chassis.turn_to_angle(-90);
chassis.drive_distance(35);
chassis.turn_to_angle(-45);
I1.spin(forward);
Slow_Drive_Constant();
chassis.drive_distance(12);
wait(50,msec);
chassis.turn_to_angle(45);
I1.spin(reverse);
wait(500,msec);
chassis.drive_with_voltage(12,12);
wait(300,msec);
chassis.drive_distance(-15);

}

if(AutonomousMode == PurpleMode){
  //Skills Auton
  chassis.turn_to_angle(-27);
  chassis.drive_distance(-5);
  F1.spin(forward,8,voltageUnits::volt);
  wait(4,sec);
  F1.stop();
  chassis.turn_to_angle(-50);
  chassis.drive_distance(30);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(35);
  chassis.turn_to_angle(0);
  WANGR.set(true);
  WANGL.set(true);
  chassis.drive_with_voltage(12,12);
  wait(2,sec);
  chassis.drive_distance(-5);
  

  
}


}

