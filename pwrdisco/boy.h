//
//  boy.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 11/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef __pwrdisco__boy__
#define __pwrdisco__boy__

#include <pthread.h>
#include <list>
#include <iostream>
#include <cstddef>
#include "headers.h"
#include "parquet.h"
#include "girl.h"

using namespace std;

class Boy{
    Point *position;
    Point *minPos;
    Point *maxPos;
    list<Girl*> girl_list;
    
public:
    Boy();
    Boy(Parquet parquet, pthread_mutex_t *screenMutex, Girl **, int index);
    Point getPosition(){ return *position; }
    void drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position);
    void createThread(int i);
    pthread_t thread_handler;
    static void *enjoy(void*);
//    ask to dance
//    dance
};

#endif /* defined(__pwrdisco__boy__) */
