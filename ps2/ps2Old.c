#include<karel.h>
void turnRight();
void setNorth();
void goToWall();
void firstStep();
void trasa();
void turnAround();
void miesto();
//int chek();

//bool beeperNotAtWall();

int main(){
	 setStepDelay(100);
	 turnOn("ps2.kw");
		
	setNorth();
    goToWall();
	firstStep();
	miesto();

	turnOff();
	return 0;
}

void setNorth(){
	while(notFacingNorth()){
		turnLeft();
	}
}

void goToWall(){
	while(frontIsClear() && noBeepersPresent()){
		movek();
	}
}

void firstStep(){
	if(noBeepersPresent()){
		turnRight();
		while(leftIsBlocked()){
		    movek();
		}
        turnLeft();
        movek();
    }
    turnLeft();
    while(frontIsClear()){
    movek();
    }
    turnAround();
}

//void trasa(){
//
//	while(frontIsClear()){
//	 if(beepersPresent() && rightIsBlocked() && leftIsBlocked()){
//       break;
//       }
//    while(beepersPresent()){
//        pickBeeper();
//        turnAround();
//        movek();
//        if(leftIsClear()){
//            turnAround();
//            movek();
//            putBeeper();
//            while(beepersPresent()){
//                pickBeeper();
//                movek();
//                putBeeper();
//                turnAround();
//                movek();
//                turnAround();
//            }
//            movek();
//            movek();
//            break;
//        }
//        else{
//            putBeeper();
//            turnAround();
//            movek();
//        }
//
//    }
//    movek();
//    if(frontIsBlocked()){
//    turnRight();
//    }
//    }
//
//}

void miesto(){

    while(leftIsBlocked()){
        if(frontIsBlocked()){
            turnRight();
        }
        movek();
        if(beepersPresent()){
            movek();
            while(noBeepersPresent()){
            if(frontIsBlocked()){
            turnRight();
            }
            movek();
                if(frontIsBlocked() && leftIsBlocked() && facingNorth()){    //if end
                    turnAround();
                    while(noBeepersPresent()){
                    movek();
                        if(frontIsBlocked()){
                        turnRight();
                        }
                    if(beepersPresent()){
                    turnLeft();
                    movek();
                    turnAround();
                    return;
                    }
                    if(frontIsBlocked()){
                    turnLeft();
                    }
                    }

                }

                if(beepersPresent()){                          //if looked for beeper
                    turnAround();
                    while(frontIsClear()){
                        movek();
                    if(frontIsBlocked() && rightIsBlocked() && facingWest()){
                        turnAround();
                        break;
                    }
                    if(frontIsBlocked()){
                        turnLeft();
                    }
                    }

                    while(frontIsClear()){
                        movek();
                        if(beepersPresent()){
                        pickBeeper();
                        }
                        if(frontIsBlocked() && leftIsBlocked() && facingNorth()){
                            turnRight();
                            break;
                            }
                        if(frontIsBlocked()){
                            turnRight();
                        }
                    }
                    break;
                }
            }
        }
    }

}



void turnRight(){
	turnLeft();
	turnLeft();
	turnLeft();
}

void turnAround(){
turnLeft();
turnLeft();
}
			



