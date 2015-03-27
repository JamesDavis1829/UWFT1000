#include <SabertoothSimplified.h>// sabertooth library down load from www.dimensionengineering.com/info/arduino

SabertoothSimplified ST; // We'll name the sabertooth object ST

void setup()
{ // start of void sett up
  SabertoothTXPinSerial.begin(9600);// this is the baud rate you chose with the DIP switches.

  /* Drive and turn are preprogramed commands that do what they say. Depending on how the power supply is connected
  to the motors, a positive power number will make you go forwads or backwords. If it's not to your liking just swap
  the motors plug in on the sabertooth.  */
  ST.drive(0);// 0 just sets drive value to zero same for turning
  ST.turn(0);
}// end of void set up

void loop()
{ // start of void loop

  /*this was a simple command used to make wheeles turn forwards
     Power was used to establish how fast the wheeles turned. Positive forwads, Negitive backwords and 0 was stopped
   int power = 81;
   ST.drive(power);*/
  smoothAccelerate(127);

  ST.drive(0);
  delay(5000);



  /* for(power = -127;power <=127; power++)
   {

     ST.turn(power);
     delay(50);
   }

   ST.turn(0);
   ST.drive(0);

   delay(5000);
  */
}// end of void loop

void smoothAccelerate(int value)
{
  int motorPower;
  int fin_velocity = value; // sets final velocity to a power
  float time_delay = 3 * fin_velocity; // sets initial time delay to 1 ms
  float fin_time_delay = .5 * time_delay;

  int step_counter = 1;
  int step_one_acceleration_final = fin_velocity / 3;
  int step_two_acceleration_final = step_one_acceleration_final * 2;

  for (motorPower = 1; motorPower <= fin_velocity; motorPower++) // for loop( set power to -127 (maxs backwards); run until power is less then or lessthen 127(maxs forward); add one to power value
  {

    if (step_counter <= step_one_acceleration_final)
    {
      ST.drive(motorPower);
      delay(time_delay);
      time_delay = time_delay - fin_time_delay / step_one_acceleration_final;
      step_counter++;
    }
    else if (step_counter <= step_two_acceleration_final)
    {
      ST.drive(motorPower);
      delay(time_delay);
      step_counter++;
    }
    else if (step_counter <= fin_velocity)
    {
      ST.drive(motorPower);
      delay(time_delay);
      time_delay = time_delay + fin_time_delay / step_one_acceleration_final;
      step_counter++;
    }
  }

}


