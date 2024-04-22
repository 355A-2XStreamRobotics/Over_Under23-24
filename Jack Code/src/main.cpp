#include "vex.h"




extern void AutonTesting(void);
using namespace vex;
competition Competition;
auton_modes AutonomousMode = NoMode;
/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(L1,L2,L3),

//Right Motors:
motor_group(R1,R2,R3),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT10,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
2.75,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
1,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
355,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;
int AutonomousCompete = 0;

enum boxes { RED, WHITE, WHITE2, BLUE, GREEN, PURPLE, YELLOW, BOX_COUNT };



struct coordinates {
  int x;  // display x coordinate
  int y;
  color box_color;
  char text[20];  // Name that you want to display
  auton_modes mode;
};

void pre_auton(void) {
  digital_out(Brain.ThreeWirePort.A).set(false);
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  coordinates coords[BOX_COUNT] = {
      {10, 10, red, "CLOSE AWP", RedMode},                        // RED
      {10, 110, transparent, "CLOSE Over not Unde", RedGrayMode},      // WHITE
      {110, 110, transparent, "Ollieisahoe", BlueGrayMode},   // WHITE2
      {110, 10, blue, "FarSideHigh/AWP", BlueMode},                    // BLUE
      {220, 10, green, "#Sad no auton", auton_modes::GreenMode},         // GREEN
      {330, 10, purple, "NA", PurpleMode},    // PURPLE
      {330, 110, yellow, "NA", YellowMode}}; // YELLOW

  int width = 100;
  int height = 100;

  for (int i = 0; i < BOX_COUNT; i++) {
    coordinates box = coords[i];
    Brain.Screen.setFillColor(box.box_color);
    Brain.Screen.drawRectangle(box.x, box.y, width, height);
  }

  while (AutonomousMode == NoMode) {
    if (Brain.Screen.pressing()) {

      int X = Brain.Screen.xPosition(); // X pos of press
      int Y = Brain.Screen.yPosition(); // Y pos of press

      for (int i = 0; i < BOX_COUNT; i++) {
        coordinates box = coords[i];

        if (((X >= box.x) && (X <= (box.x + width))) &&
            ((Y >= box.y) && (Y <= (box.y + height)))) {
          // Do something
          Brain.Screen.printAt(1, 180, box.text);
          // Set to Red Autonomous Mode
          AutonomousMode = box.mode;
          break;
        }
      }
    }
  }
}





bool pneumaticStateY = false;
void pneumaticButtonToggleY(void) {

   pneumaticStateY = ! pneumaticStateY; 
   WANGR.set(pneumaticStateY); 
}

bool pneumaticStateR = false;
void pneumaticButtonToggleR(void) {

   pneumaticStateR = ! pneumaticStateR;
   WANGL.set(pneumaticStateR); 
}

void autonomous(void) {
 auto_started = true;
  AutonomousCompete = 1;
  // Call the Autonomous Function
  AutonTesting();
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {

  while (1) {

    chassis.control_exponential();
    


   if(ID1.objectDistance(mm)>= 50){
      if(Controller1.ButtonR1.pressing()){
        I1.setVelocity(80,percent);
        I1.spin(forward);
      }

      else if(Controller1.ButtonR2.pressing()){
        I1.setVelocity(80,percent);
        I1.spin(reverse);      
      }else{
        I1.stop();
      }
    

    }
    else if(ID1.objectDistance(mm)<50){
      if(Controller1.ButtonR2.pressing()){
        I1.setVelocity(80,percent);
        I1.spin(reverse);      
      }else{
        I1.stop();
      }
    }
    printf("Intake Distance: %f %f\n", ID1.objectDistance(mm));
    



    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.

W1.setVelocity(100,percent);

   if(Controller1.ButtonL1.pressing()){
  W1.spin(forward);

   }

  else if(Controller1.ButtonUp.pressing()){

  W1.spin(reverse);
}
  else{
    W1.setBrake(hold);
    W1.stop();
  }

if(Controller1.ButtonL2.pressing()){
  W2.set(false);
}

  }



}



//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  Controller1.ButtonY.pressed(pneumaticButtonToggleY);
  Controller1.ButtonRight.pressed(pneumaticButtonToggleR);
  


  if(Gyro1.installed()) {
    Gyro1.calibrate();
    while(Gyro1.isCalibrating()) {
      wait(20,msec);
    }
  }
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
