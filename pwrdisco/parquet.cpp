//
//  parquet.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include "parquet.h"
#include "functions.h"


Parquet::Parquet(Point point, int base_width, int base_height){
    top_left = new Point(point.x, point.y);
    width = base_width;
    height = base_height;
}

void Parquet::draw(pthread_mutex_t *screenMutex){
    for(int i = top_left->x; i < top_left->x+width; i++){
        print(screenMutex, i, top_left->y, "-");
        print(screenMutex, i, top_left->y+height, "-");
    }
    
    for(int i = top_left->y+1; i < top_left->y+height; i++){
        print(screenMutex, top_left->x, i, "|");
        print(screenMutex, top_left->x+width, i, "|");
    }

}
