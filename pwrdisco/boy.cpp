//
//  boy.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 11/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include <pthread.h>
#include "boy.h"
#include "parquet.h"
#include "functions.h"

Boy::Boy(){
    minPos = new Point();
    maxPos = new Point();
    position = new Point(maxPos->getX(), minPos->getY());
}
Boy::Boy(Parquet parquet, pthread_mutex_t *screenMutex, Girl ** list, int index){
    minPos = new Point(parquet.corner(0).getX()+2, parquet.corner(0).getY()+2);
    maxPos = new Point(parquet.corner(2).getX()-2, parquet.corner(2).getY()-2);
    position = new Point(minPos->getX(), minPos->getY() + index);
  
    
    // initialize girl list
    int size = (sizeof(list)/sizeof(*list));
    for (int i = 0; i < size; i++) {
        int girl_number = rand() % size;
        girl_list.push_back(list[girl_number]);
    }
    
    print(screenMutex, position->getX(), position->getY(), "B");
}


void* Boy::enjoy(void *param){
//    int *i = (int*)param;

    for (int j = 0; j < 100; j++)
        printf("\n%d\n", j);

    return NULL;
}

void Boy::createThread(int index){
    pthread_create(&thread_handler, NULL, &Boy::enjoy, &index);
}


void Boy::drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position){
    print(screenMutex, current_position.getX(), current_position.getY(), "D");
    clearChar(screenMutex, position->getX(), position->getY(), " ");
}
