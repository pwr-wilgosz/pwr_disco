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
public:
    int x, y;
    Point(){ x=0;y=0; }
    Point(int xpos, int ypos);
    int getX(){ return x; }
    int getY(){ return y; }
    void incX(){ x++; }
    void incY(){ y++; }
    void decX(){ x--; }
    void decY(){ y--; }
    void randX(int diff){ x += diff; } //diff is in -1,0,1
    void randY(int diff){ y += diff; } //diff is in -1,0,1
    void setX(int xx){ x = xx; }
    void setY(int yy){ y = yy; }

    
};

#endif /* defined(__pwrdisco__point__) */
