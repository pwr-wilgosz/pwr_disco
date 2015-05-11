//
//  headers.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef pwrdisco_headers_h
#define pwrdisco_headers_h

#include <iostream>
#include <sys/sem.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include "functions.h"
#include "classes.h"

#define GIRLS_COUNT 10
#define BOYS_COUNT 2
#define xy(x, y) printf("\033[%d;%dH", x, y)
#define clear_eol(x) print(x, 14, "\033[K")

//class Boy {
//    int *girl_list;
//public:
//};


#endif
