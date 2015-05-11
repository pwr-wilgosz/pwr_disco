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
    pthread_mutex_init(&screenMutex,0);
    Point p( 30, 3);
    Parquet parquet(p, 130, 40);
    parquet.draw(&screenMutex);

    Girl* girls[GIRLS_COUNT];
    for (int i = 0; i < GIRLS_COUNT; i++) {
        girls[i] = new Girl(i+1, parquet, &screenMutex);
    }
    sleep(1);
    for (int i = 0; i < GIRLS_COUNT; i++) {
        Point current_pos(girls[i]->getPosition().getX()-1, girls[i]->getPosition().getY());
        girls[i]->drawNewPosition(&screenMutex, parquet, current_pos);
    }
    

    //    xy(current.getX(), current.getY()), vprintf(fmt, ap);
    //    xy(current.getX()+1, current.getY()), fflush(stdout);

    
//    pthread_t boys[BOYS_COUNT];
//    
//    for(int i = 0; i < BOYS_COUNT; i++){
//        sleep(1);
//     	pthread_create(&boys[i], NULL, enjoy, &i);
//    }
//    
//    for(int i = 0; i < BOYS_COUNT; i++)
//     	pthread_join(boys[i], NULL);
//    
//    printf ("Sorry, disco is ended. Goodnight!\n");
    return 0;
}
