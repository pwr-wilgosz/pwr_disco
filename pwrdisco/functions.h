//
//  functions.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef __pwrdisco__functions__
#define __pwrdisco__functions__

#include <stdio.h>
#include <pthread.h>

void initialize_girls(int *);
void *enjoy(void *param);
void print(pthread_mutex_t *screenMutex, int y, int x, const char *fmt, ...);


#endif /* defined(__pwrdisco__functions__) */
