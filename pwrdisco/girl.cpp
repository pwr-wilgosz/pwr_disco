//
//  girl.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include "parquet.h"
#include "girl.h"
#include "functions.h"

Girl::Girl(){
    busy = false;
    minPos = new Point();
    maxPos = new Point();
    position = new Point(maxPos->getX(), minPos->getY()+id);
}
Girl::Girl(int girl_id, Parquet parquet, pthread_mutex_t *screenMutex){
    busy = false;
    id = girl_id;
    minPos = new Point(parquet.corner(0).getX()+2, parquet.corner(0).getY()+1);
    maxPos = new Point(parquet.corner(2).getX()-2, parquet.corner(2).getY()-1);
    position = new Point(maxPos->getX(), minPos->getY()+id);
    
    print(screenMutex, position->getX(), position->getY(), "D");
}

void Girl::drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position){
    print(screenMutex, current_position.getX(), current_position.getY(), "D");
    clearChar(screenMutex, position->getX(), position->getY(), " ");
}
