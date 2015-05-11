//
//  boy.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 11/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include "boy.h"
#include "functions.h"

Boy::Boy(){
    minPos = new Point();
    maxPos = new Point();
    position = new Point(maxPos->getX(), minPos->getY());
}
Boy::Boy(Parquet parquet, pthread_mutex_t *screenMutex, Girl ** list, int index){
    minPos = new Point(parquet.corner(0).getX()+2, parquet.corner(0).getY()+2);
    maxPos = new Point(parquet.corner(2).getX()-2, parquet.corner(2).getY()-2);
    position = new Point(minPos->getX(), minPos->getY() + index);
    girls = list;
    
    // initialize girl list
    for (int i = 0; i < GIRLS_COUNT; i++) {
        int girl_number = rand() % GIRLS_COUNT;
        girlIds.push_back(list[girl_number]->getId());
        
//        std::string s = std::to_string(list[girl_number]->getId());
//        char const *pchar = s.c_str();  //use char const* as target type

    }
    
    print(screenMutex, position->getX(), position->getY(), "B");
}


void Boy::drawNewPosition(pthread_mutex_t *screenMutex, Parquet parquet, Point current_position){
    print(screenMutex, current_position.getX(), current_position.getY(), "D");
    clearChar(screenMutex, position->getX(), position->getY(), " ");
}

void Boy::enjoy(){
    for( list<int>::iterator iter=girlIds.begin(); iter != girlIds.end(); iter++ ){
        girlIds.begin();
        printf("%d\n", *iter);
    }
}