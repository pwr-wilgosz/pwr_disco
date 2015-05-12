//
//  boy.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 11/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include "boy.h"
#include "functions.h"

Boy::Boy(){
    minPos = new Point();
    maxPos = new Point();
    position = new Point(maxPos->getX(), minPos->getY());
}
Boy::Boy(Parquet parquet, pthread_mutex_t *screenMtx, Girl ** list, int index){
    minPos = new Point(parquet.corner(0).getX()+2, parquet.corner(0).getY()+2);
    maxPos = new Point(parquet.corner(2).getX()-2, parquet.corner(2).getY()-2);
    position = new Point(minPos->getX(), minPos->getY() + index);
    girls = list;
    screenMutex = screenMtx;

    // initialize girl list
    for (int i = 0; i < GIRLS_COUNT; i++) {
        int girl_number = rand() % GIRLS_COUNT;
        girlIds.push_back(list[girl_number]->getId());
        
//        std::string s = std::to_string(list[girl_number]->getId());
//        char const *pchar = s.c_str();  //use char const* as target type

    }
    print(screenMutex, position->getX(), position->getY(), "B");
}


void Boy::drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position){
    print(screenMutex, current_position.getX(), current_position.getY(), "B");
    clearChar(screenMutex, position->getX(), position->getY(), " ");
}

void Boy::enjoy(){
    for( list<int>::iterator iter=girlIds.begin(); iter != girlIds.end(); iter++ ){
        chooseAction();
        girlIds.begin();
        Girl *girl;
        if (currentAction() == "dance"){
            girl = girls[*iter];
            move(*girl);
            if (!girl->isBusy()){
//                dance(&girl);
            }
        }
//        cout << currentAction() << endl;
    }
}

void Boy::move(Girl targetGirl){
    Point target = targetGirl.getPosition();
    if (target.getX()-2 > position->getX()){
        while(target.getX()-2 > position->getX()){
            usleep(rand() % 100000 + 1000);
            moveRight();
        }
    }else if (target.getX()-2 < position->getX()){
        while(target.getX()-2 < position->getX()){
            usleep(rand() % 100000 + 1000);
            moveLeft();
        }
    }

    if (target.getY() > position->getY()){
        while(target.getY() > position->getY()){
//            cout << "tY: " << target.getY() << " pY: " << position->getY() << endl;
            usleep(rand() % 100000 + 1000);
            moveDown();
        }
    }else if (target.getY() < position->getY()){
        while(target.getY() < position->getY()){
            usleep(rand() % 100000 + 1000);
            moveUp();
//            std::string s = std::to_string(targetGirl.getId());
//            char const *pchar = s.c_str();  //use char const* as target type
//            print(screenMutex, position->getX(), position->getY(), pchar);
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
