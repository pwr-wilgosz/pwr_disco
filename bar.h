//
//  bar.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 13/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef __pwrdisco__bar__
#define __pwrdisco__bar__

#include <stdio.h>
#include "parquet.h"
#include <mutex>

using namespace std;
class Bar{
    Point *position;
    bool busy[5] = { false, false, false, false };
    mutex* barMutex[5];
public:
    Bar();
    bool tryUse(bool action, int i);
    Point getPosition(){ return *position; }
    void draw(pthread_mutex_t *screenMutex);
    
};



#endif /* defined(__pwrdisco__bar__) */
