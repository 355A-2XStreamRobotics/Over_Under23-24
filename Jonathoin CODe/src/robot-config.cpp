#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor L1 = motor(PORT1, ratio6_1, true);
motor L2 = motor(PORT3, ratio6_1, true);
motor L3 = motor(PORT5, ratio6_1, true);
motor R1 = motor(PORT2, ratio6_1, false);
motor R2 = motor(PORT4, ratio6_1, false);
motor R3 = motor(PORT6, ratio6_1, false);
inertial Gyro1 = inertial(PORT10);
controller Controller1 = controller(primary);
motor I1 = motor(PORT8, ratio6_1, false);
motor LA1 = motor(PORT7, ratio36_1, true);
motor F1 = motor(PORT7, ratio6_1, true);
motor W1 = motor(PORT9, ratio36_1,true);
digital_out W2 =digital_out(Brain.ThreeWirePort.B);
digital_out LIFT = digital_out(Brain.ThreeWirePort.B);
distance ID1 = distance(PORT10);
digital_out WANGR =digital_out(Brain.ThreeWirePort.A);
digital_out WANGL =digital_out(Brain.ThreeWirePort.C);



// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}