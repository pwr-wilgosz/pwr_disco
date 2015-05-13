//            std::string s = std::to_string(targetGirl.getId());
//            char const *pchar = s.c_str();  //use char const* as target type
//            print(screenMutex, position->getX(), position->getY(), pchar);


//
//  boy.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 11/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//


#include "boy.h"
#include "functions.h"
#define movespeed rand() % 100000 + 50000
#define dancespeed rand() % 1000000 + 100000
Boy::Boy(){
    minPos = new Point();
    maxPos = new Point();
    position = new Point(maxPos->getX(), minPos->getY());
}
Boy::Boy(Parquet parquet, pthread_mutex_t *screenMtx, Girl ** list, int index, Wc* wwc, Bar* myBar){
    minPos = new Point(parquet.corner(0).getX()+4, parquet.corner(0).getY()+2);
    maxPos = new Point(parquet.corner(2).getX()-6, parquet.corner(2).getY()-2);
    parquetCopy = &parquet;
    position = new Point(minPos->getX()+10-(index/(parquet.getHeight()-4)), minPos->getY() + index%(parquet.getHeight()-4));
    girls = list;
    wc = wwc;
    bar = myBar;
    screenMutex = screenMtx;

    // initialize girl list
    for (int i = 0; i < GIRLS_COUNT; i++) {
        int girl_number = rand() % GIRLS_COUNT;
        girlIds.push_back(list[girl_number]->getId());
    }
    print(screenMutex, position->getX(), position->getY(), "B");
}


void Boy::drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position){
    print(screenMutex, current_position.getX(), current_position.getY(), "B");
    clearChar(screenMutex, position->getX(), position->getY(), " ");
}

void Boy::enjoy(){
    while (!girlIds.empty()){
        for( list<int>::iterator iter=girlIds.begin(); ((iter != girlIds.end()) && !girlIds.empty()); iter++ ){
            chooseAction();
            Girl *girl;
            if (currentAction() == "dance"){
                girl = girls[*iter];
                Point p(maxPos->getX(),minPos->getY()+4);
                //go to the gate
                if (!isInParquet()){
                    //go to the gate
                    if (position->getX() < minPos->getX()){
                        p.setX(wc->getPosition().getX());
                        p.setY(minPos->getY()+4);
                    }

                    if (position->getX() > maxPos->getX()){
                        p.setX(bar->getPosition().getX()-2);
                        p.setY(minPos->getY()+4);
                    }
                    move(p);
                }
                //and to the girl
                move(girl->getPosition());
                if (!girl->isBusy()){
                    dance(girl);
                    girlIds.erase(iter);
                }
            }else if (currentAction() == "wc"){
                gotoWC();
            }else if (currentAction() == "bar"){
                gotoBar();
            }
        }
        if (!girlIds.empty())
            sleep(rand() % 10 + 5);
    }
}

void Boy::dance(Girl *girl){
    Point p(position->getX(),position->getY());
    if (!isInParquet()){
        if (position->getX() < minPos->getX() || !isInParquet())
            Point p(minPos->getX(),minPos->getY()+4);
        else if (position->getX() > maxPos->getX() || !isInParquet())
            Point p(maxPos->getX(),minPos->getY()+4);
        move(p);
    }
    girl->busyHer();
    print(screenMutex, position->getX()+1, position->getY(), "=");
    

    int steps = rand() % 50 + 30;
    for (int i = 0; i<steps; i++) {
        short int changeX = rand() % 3-1;
        short int changeY = rand() % 3-1;
        //remember old position
        int oldX = position->getX();
        int oldY = position->getY();
        
        //random new position and check if after change pair is in parquet
        if (position->getX()+changeX >= maxPos->getX() || position->getX()+changeX <= minPos->getX()){
            changeX *= -1;
        }
        if (position->getY()+changeY >= maxPos->getY() || position->getY()+changeY <= minPos->getY()){
            changeY *= -1;
        }
        position->randX(changeX);
        position->randY(changeY);
        girl->setPosition(position->getX()+2, position->getY());
        clearChar(screenMutex, oldX, oldY, "   ");
        print(screenMutex, position->getX(), position->getY(), "B=G");
        usleep(dancespeed);
    }
    clearChar(screenMutex, position->getX(), position->getY(), "   ");
    print(screenMutex, girl->getPosition().getX(), girl->getPosition().getY(), "G");

    girl->freeHer();
    
}

bool Boy::isInParquet(){
    return (position->getX() >= minPos->getX()-5) && (position->getX() <= maxPos->getX()+7) && (position->getY() >= minPos->getY()-3) && (position->getY() <= maxPos->getY()+3);
}

void Boy::move(Point target){
    if (target.getX()-2 > position->getX()){
        while(target.getX()-2 > position->getX()){
            usleep(movespeed);
            moveRight();
        }
    }else if (target.getX()-2 < position->getX()){
        while(target.getX()-2 < position->getX()){
            usleep(movespeed);
            moveLeft();
        }
    }

    if (target.getY()-1 > position->getY()){
        while(target.getY()-1 > position->getY()){
            usleep(movespeed);
            moveDown();
        }
    }else if (target.getY()+1 < position->getY()){
        while(target.getY()+1 < position->getY()){
            usleep(movespeed);
            moveUp();
        }
    }

}


void Boy::moveRight(){
    clearChar(screenMutex, position->getX(), position->getY(), " ");
    position->incX();
    print(screenMutex, position->getX(), position->getY(), "B");
}

void Boy::moveLeft(){
    clearChar(screenMutex, position->getX(), position->getY(), " ");
    position->decX();
    print(screenMutex, position->getX(), position->getY(), "B");
}
void Boy::moveUp(){
    clearChar(screenMutex, position->getX(), position->getY(), " ");
    position->decY();
    print(screenMutex, position->getX(), position->getY(), "B");
}

void Boy::moveDown(){
    clearChar(screenMutex, position->getX(), position->getY(), " ");
    position->incY();
    print(screenMutex, position->getX(), position->getY(), "B");
}

void Boy::gotoWC(){
    Point p(minPos->getX(),minPos->getY()+4);
    //go to the gate
    if (isInParquet())
        move(p);
    else{
        //go to bottom of the screen
        if (position->getX() < minPos->getX())
            p.setX(wc->getPosition().getX());
        if (position->getX() > maxPos->getX())
            p.setX(bar->getPosition().getX()-2);

        p.setY(minPos->getY()+40);
        move(p);
    }
    // and to toilete
    p.setX(2);
    p.setY(wc->getPosition().getY()+6);
    move(p);
    
    if (!wc->isBusy()){
        wc->busyIt();
        //move in
        p.setY(wc->getPosition().getY()+2);
        move(p);
        print(screenMutex, wc->getPosition().getX(), wc->getPosition().getY(), "!");
        usleep(rand()% 10000000 +100000);
        print(screenMutex, wc->getPosition().getX(), wc->getPosition().getY(), " ");
        wc->freeIt();
        //move out
        p.setY(wc->getPosition().getY()+6);
        move(p);
    }
}


void Boy::gotoBar(){
    Point p(maxPos->getX(),minPos->getY()+4);
    int whichBar = rand() % 5;
    //go to the gate
    if (isInParquet())
        move(p);
    else{
        //go to bottom of the screen
        if (position->getX() < minPos->getX())
            p.setX(wc->getPosition().getX());
        if (position->getX() > maxPos->getX())
            p.setX(bar->getPosition().getX()-2);
        
        p.setY(minPos->getY()+40);
        move(p);
    }
    //and to the bar
    p.setX(bar->getPosition().getX()-2);
    p.setY(bar->getPosition().getY()+7+whichBar);
    move(p);
    

    if (!bar->isBusy(whichBar)){
        bar->busyIt(whichBar);
        p.setX(bar->getPosition().getX()+3);
        move(p);
        print(screenMutex, bar->getPosition().getX()+3, bar->getPosition().getY()+8+whichBar, "!");
        usleep(rand()% 10000000 +100000);
        print(screenMutex, bar->getPosition().getX()+3, bar->getPosition().getY()+8+whichBar, " ");
        bar->freeIt(whichBar);
        p.setX(bar->getPosition().getX()-3);
        move(p);
    }

    
}
