#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1073741824;
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e7+7;
int n,t,m;
uint32_t a[N];
uint32_t b[100007];
uint32_t x,y,z,w;

uint32_t rng()
{
    x ^= (x << 11);
    x ^= (x >> 4);
    x ^= (x << 5);
    x ^= (x >> 14);
    w = x ^ (y ^ z);
    x = y;
    y = z;
    z = w;
    return z;
}

const int INFINITE = INT_MAX;
const int MAXNUM = 1e5+7;
struct SegTreeNode
{
    int val;
    int addMark;//�ӳٱ��
}segTree[MAXNUM];//�����߶���

/*
���ܣ������߶���
root����ǰ�߶����ĸ��ڵ��±�
arr: ���������߶���������
istart���������ʼλ��
iend������Ľ���λ��
*/
void build(int root, uint32_t arr[], int istart, int iend)
{
    segTree[root].addMark = 0;//----���ñ��ӳټ���
    if(istart == iend)//Ҷ�ӽڵ�
        segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2+1, arr, istart, mid);//�ݹ鹹��������
        build(root*2+2, arr, mid+1, iend);//�ݹ鹹��������
        //���������������ڵ��ֵ�����µ�ǰ���ڵ��ֵ
//        segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
    }
}

/*
���ܣ���ǰ�ڵ�ı�־�����ӽڵ㴫��
root: ��ǰ�߶����ĸ��ڵ��±�
*/
void pushDown(int root)
{
    if(segTree[root].addMark != 0)
    {
        //�������Һ��ӽڵ�ı�־����Ϊ���ӽڵ���ܱ�����ӳٱ����û�����´���
        //������ ��+=��
        segTree[root*2+1].addMark = max(segTree[root*2+1].addMark, segTree[root].addMark);
        segTree[root*2+2].addMark = max(segTree[root*2+2].addMark, segTree[root].addMark);
        //���ݱ�־�����ú��ӽڵ��ֵ����Ϊ��������������Сֵ����˵�������ÿ��Ԫ
        //�ؼ���һ��ֵʱ���������СֵҲ�������ֵ
//        segTree[root*2+1].val = segTree[root].addMark;
//        segTree[root*2+2].val = segTree[root].addMark;
        //���ݺ󣬵�ǰ�ڵ��������
        segTree[root].addMark = 0;
    }
}

/*
���ܣ��߶����������ѯ
root����ǰ�߶����ĸ��ڵ��±�
[nstart, nend]: ��ǰ�ڵ�����ʾ������
[qstart, qend]: �˴β�ѯ������
*/
int query(int root, int nstart, int nend, int qstart, int qend)
{
    //��ѯ����͵�ǰ�ڵ�����û�н���
    if(qstart > nend || qend < nstart)
        return INFINITE;
    //��ǰ�ڵ���������ڲ�ѯ������
    if(qstart <= nstart && qend >= nend)
        return segTree[root].val;
    //�ֱ������������ѯ���������߲�ѯ����Ľ�Сֵ
    pushDown(root); //----�ӳٱ�־�����´���
    int mid = (nstart + nend) / 2;
    return min(query(root*2+1, nstart, mid, qstart, qend),
               query(root*2+2, mid + 1, nend, qstart, qend));

}

/*
���ܣ������߶�����ĳ��������Ҷ�ӽڵ��ֵ
root����ǰ�߶����ĸ��ڵ��±�
[nstart, nend]: ��ǰ�ڵ�����ʾ������
[ustart, uend]: �����µ�����
addVal: ���µ�ֵ��ԭ����ֵ����addVal��
*/
void update(int root, int nstart, int nend, int ustart, int uend, int addVal)
{
    // ����Ҷ�ӽڵ�
    if(nstart == nend) {
        if(segTree[nstart].val < addVal)
            segTree[nstart].val = addVal;
        return ;
    }
    //��������͵�ǰ�ڵ�����û�н���
    if(ustart > nend || uend < nstart)
        return ;
    //��ǰ�ڵ���������ڸ���������
    if(ustart <= nstart && uend >= nend)
    {
        segTree[root].addMark = addVal;
//        segTree[root].val = addVal;
        return ;
    }
    pushDown(root); //�ӳٱ�����´���
    //�������Һ��ӽڵ�
    int mid = (nstart + nend) / 2;
    update(root*2+1, nstart, mid, ustart, uend, addVal);
    update(root*2+2, mid+1, nend, ustart, uend, addVal);
    //��������������ֵ���ݸ��µ�ǰ�ڵ��ֵ
//    segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> x >> y >> z;
        rep(i,1,3*m+1){
            a[i] = rng();
        }

        build(1,b,1,n);

        uint32_t cnt=0,l,r,v;
        rep(i,1,m+1) {
            l = a[3*i-2] % n;
            r = a[3*i-1] % n;
            v = a[3*i] % mod;
            l++,r++;
            if(l>r)swap(l,r);
            update(1,1,n,l,r,v);
        }

        uint64_t ans=0;
        rep(i,1,n+1){
            b[i] = query(1,i,i,1,n);
            ans ^= i*b[i];
        }

        cout << ans << endl;
    }
    return 0;
}


/*

100
1 10 100 1000 10000
10 100 1000 10000 100000
100 1000 10000 100000 1000000
1000 10000 100000 1000000 10000000

*/
