//
//  point.h
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#ifndef __pwrdisco__point__
#define __pwrdisco__point__

#include <stdio.h>

class Point{
    int x, y;
public:
    Point(){ x=0;y=0; }
    Point(int xpos, int ypos);
    int getX(){ return x; }
    int getY(){ return y; }
};

#endif /* defined(__pwrdisco__point__) */
