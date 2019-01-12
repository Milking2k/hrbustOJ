#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define mabs(x) ((x)>0?(x):(0-(x)))
#define N_max 100005

/*
*n层楼
*每层楼m个房间，按1~m编号，相同编号的水平位置相同
*把房间表示为(i, j)，意思是i层楼的j房间
*在走廊上走，走楼梯或坐电梯
*每个x的楼梯或电梯占有了所有(i, x)
*房间之间或层之间走动1花费1，坐电梯走动v花费1
*查询：从(x1, y1)到(x2, y2)
*/
int n, m, cl, ce, v, q;
int flr[100005], elv[100005];
//二分查找一次完成对左右电梯/楼梯的查找
void bins(int a[], int n, int x,int *_l,int *_r) {
    int l = -1, r = n, m;
    //二分求l，是左边最近的位置
    while (l + 1 < r) {
        m = (l + r) / 2;
        if (a[m] <= x)l = m;
        else r = m;
    }

    if (l == -1)//没有在x左边的电梯/楼梯，选一个最左边的来代替
        l = 0;

    //求r，是与l相邻的位置
    if (a[l] == x)//如果l是x的位置，那么使用该电梯/楼梯是最优的
        r = l;
    //没有在x右边的电梯/楼梯，选一个最右边的来代替
    else r = (l + 1 )>= n ? n - 1 : l + 1;
    //传递结果
    *_l=l;*_r=r;
}


int sol(int x1, int y1, int x2, int y2) {
    int l, r;
    int costf, coste;
    int cost1, cost2, cost3;
    //同一层楼特判
    if (x1 == x2)
        return mabs(y1 - y2);

    //走左右最近的楼梯
    bins(flr, cl, y1,&l,&r);
    costf = min(mabs(y1 - flr[l]) + mabs(x2 - x1) + mabs(y2 - flr[l]),
                mabs(y1 - flr[r]) + mabs(x2 - x1) + mabs(y2 - flr[r]));

    //左右最近的电梯
     bins(elv, ce, y1,&l,&r);
    coste = min(mabs(y1 - elv[l]) + mabs(x2 - x1) / v + (mabs(x2 - x1) % v != 0) + mabs(y2 - elv[l]),
                mabs(y1 - elv[r]) + mabs(x2 - x1) / v + (mabs(x2 - x1) % v != 0) + mabs(y2 - elv[r]));
    //该解法没有考虑电梯/楼梯没有的情况，在最后判断
    if (cl == 0)return coste;
    else if (ce == 0)return costf;
    return min(costf, coste);
}
int main() {

    int x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &n, &m, &cl, &ce, &v);
    for (int i = 0; i < cl; ++i)
        scanf("%d", &flr[i]);
    for (int i = 0; i < ce; ++i)
        scanf("%d", &elv[i]);
    scanf("%d", &q);
    int ans;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ans = sol(x1, y1, x2, y2);
        printf("%d\n", ans);

    }
}