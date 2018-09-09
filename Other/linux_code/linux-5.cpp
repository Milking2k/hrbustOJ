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

int a[N+1],readNum,nowLen,writeNum;
sem_t hasR[N+1], mdReadNum[N+1], mdque;
pthread_t rid, wid,scan,run;

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

    cout << "写线程" << pthread_self() << " is reading...\n";
    usleep(nowLen);
    cout << "reading thread:" << pthread_self() << " used " << nowLen << " to runing, it's ending" << endl;

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
    cout << "thread:读进程" << pthread_self() << " is writting...\n";
    usleep(nowLen);
    cout << "writting thread:" << pthread_self() << " used " << nowLen << " to runing, it's ending" << endl;
    sem_post(&hasR[writePos]);

    return NULL;
}

void *Scan(void *arg)
{
    PII cnt;
    int type;
    while (1)
    {
        scanf("%d %d %d",&type, &cnt.first, &cnt.second);
        if(type==1){
            sem_wait(&mdque);
            readque.push(cnt);
            sem_post(&mdque);
        }
        else {
            sem_wait(&mdque);
            writeque.push(cnt);
            sem_post(&mdque);
        }
        sleep(4);
    }
}

void *Running(void *arg)
{
    while (1)
    {
        sem_wait(&mdque);
        while (readque.size())
        {
            nowThread = readque.front();
            readque.pop();
            pthread_create(&rid, NULL, Reader, &nowThread);
        }
        while (writeque.size())
        {
            nowThread = writeque.front();
            writeque.pop();
            pthread_create(&wid, NULL, Writer, &nowThread);
        }
        sem_post(&mdque);
        usleep(1);
    }
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

void createMessage(queue<PII> &r, queue<PII> &w)// 传入包装好的队列
{
    sem_wait(&mdque);
    while(r.size()){
        readque.push(r.front());
        r.pop();
    }
    while(w.size()){
        writeque.push(w.front());
        w.pop();
    }
    sem_post(&mdque);
}

int main()
{
    init();

    //create window  2 1 1
    //running window

    for (int i = 1; i <= 10;i++){
        PII cnt = make_pair(rand() % 8, 10*1000*400);//i*100 ms
        writeque.push(cnt);
    }
    for (int i = 1; i <= 10;i++){
        PII cnt = make_pair(rand() % 8, 1*1000*400);//i*100 ms
        readque.push(cnt);
    }
    
    pthread_create(&scan, NULL, Scan, NULL);
    // sleep(1);
    // pthread_join(scan, NULL);

    pthread_create(&run, NULL, Running, NULL);
    pthread_join(run, NULL);
}

/*
1 2 1111111
1 2 1222222
1 2 1333333
*/

/*
工作完成情况：大部分逻辑已经清楚。
需要决定在何处打印线程运行和结束信息。
需要重新想办法在QT中打印信息。
*/