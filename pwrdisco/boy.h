//
//  boy.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 11/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef __pwrdisco__boy__
#define __pwrdisco__boy__

#include <list>
#include <thread>
#include <cstddef>
#include "headers.h"
#include "parquet.h"
#include "girl.h"

using namespace std;

class Boy{
    Point *position;
    Point *minPos;
    Point *maxPos;
    list<int> girlIds;
    thread _th;
    Girl **girls;
    string actions[2] = {"dance", "wc"};
    int activeAction;
    pthread_mutex_t* screenMutex;

public:
    Boy();
    Boy(Parquet parquet, pthread_mutex_t *screenMutex, Girl **, int index);
    ~Boy() { if (_th.joinable()) _th.join(); }
    
    Point getPosition(){ return *position; }
    void drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position);
    void startThread() { _th = thread(&Boy::enjoy, this); }
    void joinThread() { _th.join(); }
    void enjoy();
    void chooseAction() { activeAction = rand() % 2; }
    string currentAction(){ return actions[activeAction];}
    void move(Girl target);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

//    ask to dance
//    dance
};

#endif /* defined(__pwrdisco__boy__) */