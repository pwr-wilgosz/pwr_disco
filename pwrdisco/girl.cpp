//
//  girl.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include "headers.h"
#include "parquet.h"
#include "girl.h"
#include "functions.h"

using namespace std;
Girl::Girl(){
    busy = false;
    minPos = new Point();
    maxPos = new Point();
    position = new Point(maxPos->getX(), minPos->getY()+id);
}
Girl::Girl(int girl_id, Parquet parquet, pthread_mutex_t *screenMutex){
    busy = false;
    id = girl_id;
    minPos = new Point(parquet.corner(0).getX()+6, parquet.corner(0).getY()+2);
    maxPos = new Point(parquet.corner(2).getX()-4, parquet.corner(2).getY()-2);
    int row = (id/(parquet.getHeight()-4))*spacebetweengirls;
    position = new Point(maxPos->getX()-40-row, minPos->getY() + 7 + id%(parquet.getHeight()-15));
    girlMutex = new mutex;

    print(screenMutex, position->getX(), position->getY(), "G");
}

void Girl::drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position){
    print(screenMutex, current_position.getX(), current_position.getY(), "G");
    clearChar(screenMutex, position->getX(), position->getY(), " ");
}

bool Girl::ask(bool action){
    lock_guard<mutex> guard(*girlMutex);
    if (action == true){
        //want to ask her to dance
        if (busy == false){
            //if she is free, ask her
            busy = true;
            return true;
        }else{
            //cannot busy if she already dance
            return false;
        }
    }else{
        //want to free her
        if (busy == true){
            //if she dance, free her
            busy = false;
            return true;
        }else{
            //if she doesn't dance, connot free ger
            return false;
        }
        
    }
}