#include<karel.h>
void turnRight();
void vroh();
void trasa();
void gohome();

int main(){
    setStepDelay(100);
	turnOn("task_2.kw");

    vroh();
    trasa();
    gohome();


	turnOff();
	return 0;
}

void vroh(){
    while(notFacingNorth()){
		turnLeft();
	}
	while(frontIsClear()){
		movek();
	}
    while(notFacingWest()){
        turnLeft();
    }
	while(frontIsClear()){
		movek();
	}
}

void trasa(){

while(leftIsClear()){

    while(notFacingEast()){
    turnLeft();
    }
    while(frontIsClear()){
        movek();


        if(beepersPresent()){
           pickBeeper();
           turnLeft();
           turnLeft();
           while(frontIsClear()){
                movek();
           }
           turnLeft();
           turnLeft();
           while(beepersPresent()){
                movek();
           }
           putBeeper();
           }


        }

    turnLeft();
    turnLeft();
    while(frontIsClear()){
            movek();
    }
    if(leftIsClear()){
    turnLeft();
    movek();
    turnLeft();
    }
    else{
    break;
    }
   }
}

void gohome(){
    turnLeft();
    turnLeft();
    while(frontIsClear()){
        movek();
    }
    turnLeft();
    while(frontIsClear()){
            movek();
    }
}

void turnRight(){
	turnLeft();
	turnLeft();
	turnLeft();
}
