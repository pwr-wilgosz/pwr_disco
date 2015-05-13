//
//  parquet.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef __pwrdisco__parquet__
#define __pwrdisco__parquet__

#include <pthread.h>
#include "point.h"

class Parquet {
    Point top_left;
    int width, height;
public:
    Point *corners[4];
    Parquet();
    Parquet (Point top_left, int base_width, int base_height);
    void draw(pthread_mutex_t *screenMutex);
    Point corner(int i){ return *corners[i]; }
    int getWidth(){ return width; }
    int getHeight(){ return height; }
};

#endif /* defined(__pwrdisco__parquet__) */
