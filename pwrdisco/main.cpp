//
//  main.cpp
//  pwrdisco
//
//  Created by Sebastian Wilgosz on 10/05/15.
//  Copyright (c) 2015 Sebastian Wilgosz. All rights reserved.
//

#include "headers.h"

 int girls[GIRLS_COUNT];
 pthread_mutex_t screenMutex;

int main(int argc, const char * argv[]) {
    pthread_mutex_init(&screenMutex,0);
    initialize_girls(girls);
    Point p( 30, 3);
    Parquet parquet(p, 130, 40);
    parquet.draw(&screenMutex);
    
    pthread_t boys[BOYS_COUNT];
    
    for(int i = 0; i < BOYS_COUNT; i++){
        sleep(1);
     	pthread_create(&boys[i], NULL, enjoy, &i);
    }
    
    for(int i = 0; i < BOYS_COUNT; i++)
     	pthread_join(boys[i], NULL);
    
    printf ("Sorry, disco is ended. Goodnight!\n");
    return 0;
}
