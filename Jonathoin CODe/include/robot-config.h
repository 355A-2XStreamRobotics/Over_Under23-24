using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor L1;
extern motor L2;
extern motor L3;
extern motor R1;
extern motor R2;
extern motor R3;
extern motor LA;
extern inertial Gyro1;
extern controller Controller1;
extern motor I1;
extern motor F1;
extern digital_out IL;
extern distance ID1;
extern motor S1;
extern digital_out WANGR;
extern digital_out WANGL;
extern motor W1;
extern digital_out W2;
extern digital_out LIFT;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );