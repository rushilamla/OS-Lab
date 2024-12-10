#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_MAX 32

int BUFFER[BUFFER_MAX];
int BUFFER_SIZE = 0;

int empty = BUFFER_MAX, full = 0, mutex = 1;

void wait_sem(int *s) {
    while (*s <= 0); // Busy-wait
    *s -= 1;
}

void signal_sem(int *s) {
    *s += 1;
}

void *producer(void *arg) {
    int id = *(int *)arg;
    for (int count = 0; count < 10; count++) { // Produce 10 items and exit
        wait_sem(&empty);
        wait_sem(&mutex);

        printf("Producer %d obtained mutex\n", id);

        if (BUFFER_SIZE < BUFFER_MAX) {
            int item = rand() % 100;
            BUFFER[BUFFER_SIZE++] = item;
            printf("Producer %d produced item %d\n", id, item);
        }

        signal_sem(&mutex);
        signal_sem(&full);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int id = *(int *)arg;
    for (int count = 0; count < 10; count++) { // Consume 10 items and exit
        wait_sem(&full);
        wait_sem(&mutex);

        if (BUFFER_SIZE > 0) {
            int item = BUFFER[--BUFFER_SIZE];
            printf("Consumer %d consumed item %d\n", id, item);
        }

        signal_sem(&mutex);
        signal_sem(&empty);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <producers> <consumers>\n", argv[0]);
        return 1;
    }

    int producers = atoi(argv[1]);
    int consumers = atoi(argv[2]);

    pthread_t producer_threads[producers];
    pthread_t consumer_threads[consumers];

    int producer_ids[producers];
    int consumer_ids[consumers];

    // Create producer threads
    for (int i = 0; i < producers; i++) {
        producer_ids[i] = i + 1; // Unique IDs
        printf("Creating producer with id: %d\n", producer_ids[i]);
        pthread_create(&producer_threads[i], NULL, producer, &producer_ids[i]);
    }

    // Create consumer threads
    for (int i = 0; i < consumers; i++) {
        consumer_ids[i] = i + 1; // Unique IDs
        printf("Creating consumer with id: %d\n", consumer_ids[i]);
        pthread_create(&consumer_threads[i], NULL, consumer, &consumer_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < producers; i++) {
        pthread_join(producer_threads[i], NULL);
    }
    for (int i = 0; i < consumers; i++) {
        pthread_join(consumer_threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}
