/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\adams                                            */
/*    Created:      Tue Feb 08 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, 3, 4      
// Controller1          controller                    
// MotorGroup5          motor_group   5, 6            
// Motor9               motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <stdio.h>
#include <string>
#include <cmath>
#include "methods.h"
using namespace vex;
//Declare variables

//Declare variables
bool done;

int multitask() {
  multiTaskRunning = true;
  println("Multitask is running");
  Motor9.setRotation(90, degrees);
  while (multiTaskRunning) {
    if(done){
      Motor9.setRotation(40, degrees);
    }
    else if (done = false){
      Motor9.setRotation(90, degrees);
    }
    task::sleep(20); // Sleeps for 20 Milliseconds.....
  }
  return 1;
}

void Autonomous(void) {
  autonomousRunning = true;
  MotorGroup5.setVelocity(83.14159265359, percent);
  Drivetrain.driveFor(f, twelveFeet - (foot * 2), i, 100);//Moves mobile goal across field
  for(int x = 0; x < 2; x++){
    Drivetrain.turnFor(185, degrees);
    Drivetrain.driveFor(f, foot * 4.2, i, 100);//drives forward to move other mobile goal(middle goal)  
  }
  Drivetrain.turnFor(138, degrees);
  task myTask(multitask);
  Drivetrain.driveFor(r, foot * 3, i, 100);//reverse to get blue goal
  done = true;
  Drivetrain.turnFor(180, degrees);
  
  Drivetrain.driveFor(f, twelveFeet, i, 100);//drives forward to move other mobile goal(middle goal)  
  done = false;
}

int main() {
  vexcodeInit();
  Drivetrain.setDriveVelocity(100, percent);
  Competition.autonomous(Autonomous);
}

