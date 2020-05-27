#include <iostream>
#include <queue>
#include <pthread.h>
#define NITERS 5
void *producer(void *arg);
void *consumer(void *arg);
using namespace std;

queue <int> q;
int n=4; // queue size
int pcnt=0, ccnt=0;

struct {
    int buf[10]; /* shared var */
} shared;

/*
void *producer(void *arg) {
    while(1){
        while(pcnt - ccnt == n){
            // queue full, no space to produce
        }
        q.push(produce()); //produce and push into queue
        pcnt++;
    }
}
void *consumer(void *arg) {
    while(1){
        while(pcnt - ccnt == 0){
            // queue empty, nothing to consume
        }
       consume(q.front()) //consume element
       q.pop();
       ccnt++;
    }
}
*/

void *producer(void *arg) {
    int i, item;
    for (i=0; i<NITERS; i++) {
        item = i;
        while(pcnt - ccnt == n){
            // queue full, no space to produce
        }
        shared.buf[pcnt] = item;
        printf("produced %d\n",item);
        pcnt++;
    }
    return NULL;
}

void *consumer(void *arg) {
    int i, item;
    for (i=0; i<NITERS; i++) {
        while(pcnt - ccnt == 0){
            // queue empty, nothing to consume
        }
        item = shared.buf[ccnt];
        printf("consumed %d\n",item);
        ccnt++;
    }
    return NULL;
}


int main()
{
    pthread_t tid_producer;
    pthread_t tid_consumer;

    pthread_create(&tid_producer, NULL, producer, NULL);
    pthread_create(&tid_consumer, NULL, consumer, NULL);
    pthread_join(tid_producer, NULL);
    pthread_join(tid_consumer, NULL);
    exit(0);
}
/*
int pcnt = 0, ccnt=0;

void sbuf_insert(sbuf_t *sp, int item)
{
    while(pcnt - ccnt == sp->n); // space full
    sp->buf[(++sp->rear)%(sp->n)] = item; // Insert the item
    pcnt++;
}

int sbuf_remove(sbuf_t *sp) {
    int item;
    while(pcnt - ccnt == 0); // space empty, nothing to consume
    item = sp->buf[(++sp->front)%(sp->n)]; // Remove the item
    ccnt++;
    return item;
}


int readcnt, writecnt;                   // initially both 0
sem_t rmutex, wmutex, r, w;              // initially all 1

void reader(void)
{
  P(&r);
  P(&rmutex);
  readcnt++;
  if (readcount == 1) P(&w);
  V(&rmutex);
  V(&r);
  // Reading happens here
  P(&rmutex);
  readcnt--;
  if (readcnt == 0) V(&w);
  V(&rmutex);
}

void writer(void)
{
    P(&wmutex);
    writecnt++;
    if(writecnt == 1) P(&r);
    V(&wmutex);
    P(&w);
    // writing happens here
    V(&w);
    P(&wmutex);
    writecnt--;
    if (writecnt == 0) V(&r);
    V(&wmutex);
}
*/





