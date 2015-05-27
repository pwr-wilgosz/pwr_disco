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

bool Bar::tryUse(bool action, int i){
    lock_guard<mutex> guard(*barMutex[i]);
    if (action == true){
        //want to busy it
        if (busy[i] == false){
            //if wc is free, busy it
            busy[i] = true;
            return true;
        }else{
            //cannot busy locked toilette
            return false;
        }
    }else{
        //want to free it
        if (busy[i] == true){
            //if wc is free, busy it
            busy[i] = false;
            return true;
        }else{
            //cannot free empty toilette
            return false;
        }
        
    }
}