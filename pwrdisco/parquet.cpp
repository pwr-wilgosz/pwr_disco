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
    top_left = Point(point.getX(), point.getY());
    width = base_width;
    height = base_height;

    corners[0] = &top_left;
    corners[1] = new Point(top_left.getX()+width, top_left.getY());
    corners[2] = new Point(top_left.getX()+width, top_left.getY()+height);
    corners[3] = new Point(top_left.getX(), top_left.getY()+height);
}

void Parquet::draw(pthread_mutex_t *screenMutex){
    for(int i = top_left.getX(); i < top_left.getX()+width; i++){
        print(screenMutex, i, top_left.getY(), "-");
        print(screenMutex, i, top_left.getY()+height, "-");
    }
    
    for(int i = top_left.getY()+1; i < top_left.getY()+height; i++){
        print(screenMutex, top_left.getX(), i, "|");
        print(screenMutex, top_left.getX()+width, i, "|");
    }
    
    print(screenMutex, top_left.getX(), top_left.getY()+5, " ");
    print(screenMutex, top_left.getX(), top_left.getY()+6, " ");
    

}
