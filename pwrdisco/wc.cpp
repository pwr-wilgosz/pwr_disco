//
//  wc.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 12/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include "wc.h"
#include "functions.h"
#include <iostream>
using namespace std;

Wc::Wc(){
    position = new Point(0, 2);
    wcMutex = new mutex;
}

void Wc::draw(pthread_mutex_t* screenMutex){
    clearChar(screenMutex, 0, 0, "                                        ");
    print(screenMutex, position->getX(), position->getY()+1, "\\  /\\  /");
    print(screenMutex, position->getX(), position->getY()+2, " \\/  \\/");
    
    print(screenMutex, position->getX()+11, position->getY()-1, "___");
    print(screenMutex, position->getX()+10, position->getY(), "|   \\");
    print(screenMutex, position->getX()+10, position->getY()+1, "|");
    print(screenMutex, position->getX()+10, position->getY()+2, "|");
    print(screenMutex, position->getX()+11, position->getY()+3, "___/");
    
}

bool Wc::tryUse(bool action){
    lock_guard<mutex> guard(*wcMutex);
    if (action == true){
        //want to busy it
        if (busy == false){
            //if wc is free, busy it
            busy = true;
            return true;
        }else{
            //cannot busy locked toilette
            return false;
        }
    }else{
        //want to free it
        if (busy == true){
            //if wc is free, busy it
            busy = false;
            return true;
        }else{
            //cannot free empty toilette
            return false;
        }
        
    }
}