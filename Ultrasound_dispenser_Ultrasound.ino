/*
 *UltrasonicDemo.pde - Ultrasonic sensor Ranging measure Demo
 *@Author:dragon
 *@DATA:2013-8-7
 *Company website:www.elecfreaks.com
 */
#include <Ultrasonic.h>//includes ultrasonic programming library

int trigpin = 3;//appoint trigger pin
int echopin = 2;//appoint echo pin

Ultrasonic ultrasonic(trigpin,echopin);//creates ultrasonic object

void usSetup()
{
	Serial.begin(9600);//opens serial communication
 
	Serial.println("Ultrasonic sensor starting!!!!!");//write into serial
  Serial.println("Now measuring Candies!!");
}

float usDistance()
{
	float cmdistance;//creates variable to save distance
	long microsec = ultrasonic.timing();//saves ultrasonic timing between beeps
  
	Serial.print("microsec: ");
	Serial.print(microsec);//print microsecs on screen
 
	cmdistance = ultrasonic.CalcDistance(microsec,Ultrasonic::CM);//finds distance in centimeters, 
	                                                             // and saves it to variable
	
	Serial.print(" cmdistance: ");
	Serial.println(cmdistance);//prints distance on screen
	
	delay(200);

 return cmdistance;//returns cmDistance
}
