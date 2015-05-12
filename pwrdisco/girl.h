//
//  girl.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef __pwrdisco__girl__
#define __pwrdisco__girl__

#include <stdio.h>
#include "parquet.h"
#include "mutex"

using namespace std;

class Girl{
    int id;
    Point *position;
    Point *minPos;
    Point *maxPos;
    bool busy;

    mutex* girlMutex;
public:
    Girl();
    Girl(int girl_id, Parquet parquet, pthread_mutex_t *screenMutex);
    int getId(){ return id; }
    int isBusy(){ return busy; }
    void busyHer(){
        lock_guard<mutex> guard(*girlMutex);
        busy = true; }
    void freeHer() {
        lock_guard<mutex> guard(*girlMutex);
        busy = false;
    }
    Point getPosition(){ return *position; }
    void setPosition(int x, int y){ position->setX(x); position->setY(y); }
    void drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position);

};

#endif /* defined(__pwrdisco__girl__) */
