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
#include "wc.h"
#include "parquet.h"
#include "bar.h"
using namespace std;

class Boy{
    Point *position;
    Point *minPos;
    Point *maxPos;
    list<int> girlIds;
    thread _th;
    Girl **girls;
    string actions[3] = {"dance", "wc", "bar"};
    int activeAction;
    pthread_mutex_t* screenMutex;
    Wc *wc;
    Parquet *parquetCopy;
    Bar *bar;
public:
    Boy();
    Boy(Parquet parquet, pthread_mutex_t *screenMutex, Girl **, int index, Wc* wwc, Bar* myBar);
    ~Boy() { if (_th.joinable()) _th.join(); }
    
    Point getPosition(){ return *position; }
    void drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position);
    void startThread() { _th = thread(&Boy::enjoy, this); }
    void joinThread() { _th.join(); }
    void enjoy();
    void chooseAction() { activeAction = rand() % 3; }
    string currentAction(){ return actions[activeAction];}
    void move(Point target);
    void gotoWC();
    void gotoBar();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    bool isInParquet();
    void dance(Girl *girl);
};

#endif /* defined(__pwrdisco__boy__) */