//
//  headers.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef pwrdisco_headers_h
#define pwrdisco_headers_h

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <iostream>
#include <sys/sem.h>
#include <thread>
#include <unistd.h>
#include <stdarg.h>

#include "functions.h"
#include "classes.h"

#define GIRLS_COUNT 100
#define BOYS_COUNT 300
#define movespeed rand() % 100000 + 50000
#define dancespeed rand() % 1000000 + 100000
#define barservicetime rand()% 10000000 +100000
#define shittingtime rand()% 10000000 +100000
#define spacebetweengirls 15
#define xy(x, y) printf("\033[%d;%dH", x, y)

using namespace std;

#endif
