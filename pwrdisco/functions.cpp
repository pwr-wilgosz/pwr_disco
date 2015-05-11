//
//  functions.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//
#include "headers.h"
#include "functions.h"

void print(pthread_mutex_t *screenMutex, int y, int x, const char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    
    pthread_mutex_lock(screenMutex);
    xy(x, y), vprintf(fmt, ap);
    xy(x + 1, y), fflush(stdout);
    pthread_mutex_unlock(screenMutex);
    
}

void clearChar(pthread_mutex_t *screenMutex, int y, int x, const char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    
    pthread_mutex_lock(screenMutex);
    xy(x, y), vprintf(fmt, ap);
    xy(45, 0), fflush(stdout);
    pthread_mutex_unlock(screenMutex);


}