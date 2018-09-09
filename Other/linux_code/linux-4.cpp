#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;
#define PII pair<int, int>
const int N = 10;// 临界区资源数量

int a[N+1],readNum,nowLen;
sem_t hasR[N+1], hasW, mdReadNum[N+1], mdque;
pthread_t rid, wid;

PII nowThread;
queue< PII > readque, writeque;

void *Reader(void*arg)
{
    PII nowPT = *((PII *)arg);
    int readPos = nowPT.first;
    int nowLen = nowPT.second;

    sem_wait(&mdReadNum[readPos]);
    readNum++;
    if(readNum==1) sem_wait(&hasR[readPos]);
    sem_post(&mdReadNum[readPos]);

    usleep(nowLen);

    sem_wait(&mdReadNum[readPos]);
    readNum--;
    if(readNum==0) sem_post(&hasR[readPos]);
    sem_post(&mdReadNum[readPos]);

    return NULL;
}
void *Writer(void *arg)
{
    PII nowPT = *((PII *)arg);
    int writePos = nowPT.first;
    int nowLen = nowPT.second;

    sem_wait(&hasR[writePos]);
    sleep(nowLen);
    sem_post(&hasR[writePos]);

    return NULL;
}

void init()
{
    for (int i = 0; i <= N;i++){
        a[i] = i;
        sem_init(&hasR[i], 0, 1);
        sem_init(&mdReadNum[i], 0, 1);
    }
    sem_init(&mdque, 0, 1);
}


int main()
{
    init();
    while(1){
        sleep(1);

        sem_wait(mdque);
        while(readque.size()){
            sem_post(mdque);

            nowThread = readque.front();readque.pop();
            pthread_create(rid, NULL, Reader, &nowThread);
            pthread_join(rid, NULL);
            sleep(nowThread.second);

            set_wait(mdque);
        }
        if(writeque.size()){
            sem_post(mdque);
            
            nowThread = writeque.front();
            writeque.pop();
            pthread_create(wid, NULL, Writer, &nowThread);
            pthread_join(wid, NULL);
            sleep(nowThread.second);

        }
    }



}

