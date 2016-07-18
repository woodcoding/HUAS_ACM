#include <iostream>
#include <algorithm>
using namespace std;

const __int64 maxn=500;         //不用__int64鬼知道他数据有多大
const __int64 maxm=1000;
__int64 ldata[maxn], ndata[maxn], mdata[maxn], xdata[maxm], lndata[maxn*maxn];
__int64 l,n,m,s,x, lnlen;
bool ans;

void Init()
{
    ///初始化输出数据
    lnlen=0;
    for(__int64 i=0;i<l;i++)cin>>ldata[i];
    for(__int64 i=0;i<n;i++)cin>>ndata[i];
    for(__int64 i=0;i<m;i++)cin>>mdata[i];
    cin>>s;
    for(__int64 i=0;i<l;i++)for(__int64 j=0;j<n;j++)lndata[lnlen++]=ldata[i]+ndata[j];
    sort(mdata, mdata+m);       //排序，后面二分会用得到
    sort(lndata, lndata+lnlen);
    lnlen = unique(lndata,lndata+lnlen)-lndata;     //去重，新技能get
}

bool lnFind(__int64 fm)
{
    ///二分查找
    __int64 fBegin=0;
    __int64 fEnd=lnlen-1;
    while(fBegin<=fEnd)
    {
        __int64 mid=(fBegin+fEnd)>>1;       //不会溢出的平均计算，新技能get
        if(lndata[mid]==fm)return true;
        if(lndata[mid]<fm)fBegin=mid+1;
        if(lndata[mid]>fm)fEnd=mid-1;
    }
    return false;
}

void Print()
{
    while(s--)
    {
        cin>>x;
        if(x>lndata[lnlen-1]+mdata[m-1]||x<lndata[0]+mdata[0])
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(__int64 mi=0;mi<m;mi++)
        {
            __int64 fx=x-mdata[mi];
            if(ans=lnFind(fx))break;
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main()
{
    __int64 icase=0;
    while(cin>>l>>n>>m)
    {
        Init();
        cout<<"Case "<<++icase<<":"<<endl;
        Print();
    }
    return 0;
}
