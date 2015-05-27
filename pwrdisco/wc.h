//
//  wc.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 12/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef __pwrdisco__wc__
#define __pwrdisco__wc__

#include <stdio.h>
#include "parquet.h"
#include <mutex>

using namespace std;
class Wc{
    Point *position;
    bool busy;
    mutex* wcMutex;
public:
    Wc();
    bool tryUse(bool action);
    Point getPosition(){ return *position; }
    void draw(pthread_mutex_t *screenMutex);

};


#endif /* defined(__pwrdisco__wc__) */
