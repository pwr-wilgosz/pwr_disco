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

Girl::Girl(int girl_id, Parquet parquet){
    
    id = girl_id;
//    printf("corner0: %d %d\n", parquet.corner(0).getX(), parquet.corner(0).getY());
//    printf("corner1: %d %d\n", parquet.corner(1).getX(), parquet.corner(1).getY());
//    printf("corner2: %d %d\n", parquet.corner(2).getX(), parquet.corner(2).getY());
//    printf("corner2: %d %d\n", parquet.corner(3).getX(), parquet.corner(3).getY());
    minPos = new Point(parquet.corner(0).getX()+1, parquet.corner(0).getY()+1);
    maxPos = new Point(parquet.corner(2).getX()-1, parquet.corner(2).getY()-1);
    position = new Point(maxPos->getX(), minPos->getY()+id);
}

void Girl::drawPosition(pthread_mutex_t *screenMutex, Parquet parquet){
    print(screenMutex, position->getX(), position->getY(), "D");
}

