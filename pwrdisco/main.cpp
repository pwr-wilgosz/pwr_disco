//
//  main.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include "headers.h"
#include "girl.h"

pthread_mutex_t screenMutex;

int main(int argc, const char * argv[]) {
    /* initialize random seed: */
    srand ((int)time(NULL));
    
    /* generate secret number between 1 and 10: */
    pthread_mutex_init(&screenMutex,0);
    Point p( 30, 3);
    Parquet parquet(p, 130, 40);
    parquet.draw(&screenMutex);
    Wc *wc = new Wc();
    wc->draw(&screenMutex);
    Bar *bar = new Bar();
    bar->draw(&screenMutex);

    Girl* girls[GIRLS_COUNT];
    for (int i = 0; i < GIRLS_COUNT; i++)
        girls[i] = new Girl(i, parquet, &screenMutex);

    for (int i = 0; i < GIRLS_COUNT; i++){
        Point current_pos(girls[i]->getPosition().getX()-1, girls[i]->getPosition().getY());
//        girls[i]->drawNewPosition(&screenMutex, parquet, current_pos);
    }

    Boy *boys[BOYS_COUNT];
    for(int i = 0; i < BOYS_COUNT; i++){
        // creating new threads in constructor
        boys[i] = new Boy(parquet, &screenMutex, girls, i, wc, bar);
    }

    for(int i = 0; i < BOYS_COUNT; i++){
        // creating new threads in constructor
        usleep(rand() % 100000 + 10000);
        boys[i]->startThread();
    }

    for(int i = 0; i < BOYS_COUNT; i++)
        boys[i]->joinThread();

    
//    printf ("Sorry, disco is ended. Goodnight!\n");
    
    return 0;
}
