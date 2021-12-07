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
    trasa();
	pickBeeper();
    turnLeft();
    turnLeft();
    gohome();
	pickBeeper();
	onWest();
	turnOff();
    return 0;
}

void firstStep(){
	if (frontIsBlocked() && leftIsClear()){
		turnLeft();
		movek();
//		turnRight();
	}
	if (frontIsClear() && rightIsBlocked()){
		movek();
	}
}

void trasa(){
    while (noBeepersPresent()){
        if (frontIsBlocked() && rightIsBlocked()){
            turnLeft();
        }
        if(rightIsClear()){
            turnRight();
            movek();
        }
         if(rightIsBlocked() && frontIsClear()){
            movek();
        }
    }
}
void gohome(){
	while (noBeepersPresent()){
	    if (frontIsBlocked() && leftIsBlocked()){
            turnRight();
        }
        if(leftIsClear()){
           turnLeft();
           movek();
        }
        if(leftIsBlocked() && frontIsClear()){
            movek();
        }
    }
}

void onWest(){
	while(notFacingWest()){
		turnLeft();
	}
}

void turnRight(){
    setStepDelay(0);
	turnLeft();
	turnLeft();
	turnLeft();
	setStepDelay(100);
}

 






