//
//  bar.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 13/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include "bar.h"

#include "functions.h"
#include <iostream>
using namespace std;

Bar::Bar(){
    position = new Point(180, 0);
    for (int i=0; i < 5; i++)
        barMutex[i] = new mutex;
}

void Bar::draw(pthread_mutex_t* screenMutex){
    print(screenMutex, position->getX(), position->getY()+1, "----           ----");
    print(screenMutex, position->getX(), position->getY()+2, "|    \\        |   \\");
    print(screenMutex, position->getX(), position->getY()+3, "|    |   /\\   |    |");
    print(screenMutex, position->getX(), position->getY()+4, " ----   /  \\  ----");
    print(screenMutex, position->getX(), position->getY()+5, "|    \\ /----\\ |\\");
    print(screenMutex, position->getX(), position->getY()+6, "|    |/      \\| \\");
    print(screenMutex, position->getX(), position->getY()+7, " ----         |  \\");

}
