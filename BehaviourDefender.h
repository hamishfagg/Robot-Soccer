#ifndef BDEFENDER_INCLUDED_
#define BDEFENDER_INCLUDED_


#include "controlalgo.h"
#include "commondata.h"
#include "RFComm.h"
#include "map.h"
#include "math.h"
#include "BehaviourRobot.h"

class CDefenderAction : public RobotBehaviour //----- To defend the goal from attack by opponent
{

private:
	float MIDDLE;
	float NEARPOS;
	float XHYSTERESIS;
	float YHYSTERESIS;
	float HALF_GOALSIZE;
	float CLEARYOFFSET;
	int *pstate;
	int which; //---- which robot we're referring to
	floatPOINT BallPos;
	float Ballspeed;
	floatPOINT finalPos;
	floatPOINT GPos;
	float GAngle;
	float GOALIESTANDX;

	
public:
	CDefenderAction(int w, int *ps);
	~CDefenderAction(){}

//  Switching Conditions/ State Transitions
//  Possible state transitions
//	S0S1, S0S2, S0S3, S0S4
//	S1S2, S1S3, S1S4
//	S2S3, S2S1, S2S4
//	S3S2, S3S1, S3S4


	BOOL S0S1();
	BOOL S0S2();
	BOOL S0S3();
	BOOL S0S4();
	BOOL S1S2();
	BOOL S1S3();
	BOOL S1S4();
	BOOL S2S1();
	BOOL S2S3();
	BOOL S2S4();
	BOOL S3S1();
	BOOL S3S2();
	BOOL S3S4();
	BOOL S4S1();
	BOOL S4S2();
	BOOL S4S3();

	// Action States
	// S0 initialisation
	//void S0() {}; // No Action for Initialisation State

	void S1(); //---- Track like goalie
	void S2(); //---- Tackle
	void S3(); //---- Clear
	void S4(); //---- Assist

	//-- Run function
	void runAction();
};	//-- CDefenderAction class definition ends here

#endif