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
  chassis.set_drive_constants(3, 3.0, 0, 10, 0);
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

chassis.drive_distance(-6);
WANGR.set(true);
wait(50,msec);
WANGR.set(false);
chassis.turn_to_angle(-45);
chassis.drive_distance(4);

/*
WA.set(true);
wait(150,msec);
chassis.drive_distance(-4);
chassis.turn_to_angle(325);
wait(150,msec);
WA.set(false);
chassis.drive_distance(-18);
chassis.turn_to_angle(140);
chassis.drive_distance(27);
I1.spin(reverse, 10,volt);
wait(2000,msec);
I1.stop();
*/

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
chassis.turn_to_angle(45);
I1.spin(reverse);
wait(500,msec);
chassis.drive_with_voltage(12,12);
wait(300,msec);
chassis.drive_distance(-15);

}
/*
if(AutonomousMode == RedGrayMode){

  //chassis.turn_to_angle(179);
  //fast_default_constants();
  //chassis.set_drive_exit_conditions(1.2, 300, 2000);
  default_constants();
  I1.setVelocity(80,percent);
  I1.spin(reverse);
task DeployWangLeft;
DeployWangLeft = task(DeployWingLeft);
task SetHheadingTask;
SetHheadingTask = task(SetHeading);
chassis.drive_distance(44);
I1.stop();
chassis.drive_distance(-4);
WA.set(false);
chassis.turn_to_angle(-20);
chassis.drive_distance(-15);
chassis.turn_to_angle(-70);
chassis.drive_distance(-37);


}

if(AutonomousMode == BlueGrayMode){
Slow_Turn_Constant();
chassis.drive_max_voltage = 7;
WA.set(true);
wait(100,msec);
WA.set(false);
I1.setVelocity(90,percent);
I1.spin(forward);
chassis.drive_distance(54.5);
wait(250,msec);
I1.stop();
chassis.turn_to_angle(120);
WA.set(true);
I1.spin(reverse);
wait(700,msec);
chassis.drive_with_voltage(12,12);
wait(470,msec);
WA.set(false);
I1.stop();
chassis.turn_to_angle(-88);
I1.setVelocity(50,percent);
I1.spin(forward);
chassis.drive_distance(33);
wait(200,msec);
chassis.drive_distance(-10);
I1.stop();
chassis.turn_to_angle(75);
chassis.drive_distance(18);
I1.spin(reverse);
ESlow_Turn_Constant();
chassis.turn_to_angle(120);
WA.set(true);
chassis.drive_with_voltage(12,12);
wait(200,msec);
I1.stop();
chassis.drive_distance(-10);


}

if(AutonomousMode == SkillsMode){



}
*/
}