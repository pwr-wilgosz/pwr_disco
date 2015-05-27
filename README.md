# pwr_disco

The project is a multi-thread application made for getting the credit of Operation Systems at University of Technology.

The application simulates the disco at University of Technology. Threads are boys - same as at, university there are lot of them, and most rival for resources-girls.

There are three types of resources:

- WC - a toilette. Only one boy can be inside, and doors are locked to prevent others to see what is inside.
- The bar - this resouce allow to serve as many users at a time, as much barmans exists.
- Girl - there are lot of girls on the parquet, and boys tries to dance with them, one at a time.

##Algorithm

The speed of whole program and every type of action, including moving and shitting time can be managed from `headers.h` file.

1. Each boy random his own list of girls to dance with and save them into the queue. If there are 100 girls on the parquet, boy's list includes 100 records. The order is completely random, so boy can dance with the same girl few times, and with others no one.
2. Next each boy random the action to process from this set: [wc, dance, bar]
3. If 'WC' is choosen, he tries to go to toilete. If it is empty, he locks it and go inside. Otherwise he random the action type once again and walk to the proper resource. Locked toilette has exclamation mark above it.
4. If the boy chooses the 'Bar' he walk to the bar and random the barman to order the beer. It works almost the same as toilette, except the fact, that all barmans can be busy at the same time. When the barman serves the boy, exclamation marks appear on them.
5. If the boy wants to dance with girl, he goes to the first girl on his list, and if she is free, he asks her to dance. Then the equal sign appears between them, marking the pair as dancing. Dancing pair moves inside the parquet in random direction, and for random time. The delay between moves is also random.
6. After dancing with girl, the boy removes her from the list and random the next action from the set.
7. When the girl is busy, the boy simple goes to the next girl in the queue or random next action.
8. The process repeat until the thread dance with all girls in his list.

The program ends after all thread finish his disco plan.

The result you can see running `main` executable file.

**Here you can see some screenshots:**

- [The application just after starting it][1]
- [How the disco at University of Technology looks like after few minutes of running][2]

[1]: https://github.com/wilgoszpl/pwr_disco/blob/master/screenshot-start.png
[2]: https://github.com/wilgoszpl/pwr_disco/blob/master/screenshot-after-a-while.png
