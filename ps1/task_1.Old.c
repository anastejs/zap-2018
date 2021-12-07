#include<karel.h>

void trasa();
void gohome();
void onWest();
void turnRight();
void firstStep();

int main() {

	setStepDelay(100);
	turnOn("task_1.kw");

    putBeeper();

	firstStep();

	while(noBeepersPresent()){
	trasa();
	}

	pickBeeper();

	while(notFacingNorth()){
		turnLeft();
	}

	while(noBeepersPresent()){
		gohome();
	}

	onWest();

	turnOff();
        return 0;
}

void firstStep(){
	if (frontIsBlocked() && leftIsClear()){
		turnLeft();
		movek();
	}

	if (frontIsClear() && rightIsBlocked()){
		movek();
	}
}

void trasa(){

	while(rightIsBlocked() && noBeepersPresent()){
		movek();
	}

	if(rightIsClear()){
		turnRight();
	        movek();
	}

	while(rightIsBlocked()){
		movek();
	}

	turnRight();

	while(frontIsClear()){
		movek();	}

	turnLeft();

	while(frontIsClear()){
		movek();
	}

	turnLeft();
}

void gohome(){

	while(leftIsBlocked() &&  noBeepersPresent()){
		movek();
	}

	turnLeft();
	movek();

	while(leftIsBlocked() && noBeepersPresent()){
		movek();
	}

	turnLeft();

	while(frontIsClear() && noBeepersPresent()){
		movek();
	}

	turnRight();

	while(frontIsClear() && noBeepersPresent()){
		movek();
	}

	turnRight();
}

void onWest(){
	while(notFacingWest()){
		turnLeft();
	}
}

void turnRight(){
	turnLeft();
	turnLeft();
	turnLeft();
}








