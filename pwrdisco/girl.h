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
#include <pthread.h>
#include "parquet.h"

class Girl{
    int id;
    Point *position;
    Point *minPos;
    Point *maxPos;
public:
    Girl();
    Girl(int girl_id, Parquet parquet, pthread_mutex_t *screenMutex);
    int getId(){ return id; }
    Point getPosition(){ return *position; }
    void drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position);

};

#endif /* defined(__pwrdisco__girl__) */
