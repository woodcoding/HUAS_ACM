#include <iostream>

using namespace std;

double h, d, u, f;
int days=0;
bool flag=false;
double height=0, down=0;

void CampTheSBWall(double cd, double cu, double cf)
{
    days++;
    height+=cd;
    //cout<<"-*"<<cd<<endl;
    if(height>h){flag=true;return;}
    height-=cu;
    if(height<0){flag=false;return;}
    CampTheSBWall(cd-down, cu, cf);
}

int main()
{
    while(cin>>h>>d>>u>>f && (h+d+u+f))
    {
        down=d*0.01*f;
        CampTheSBWall(d, u, f);
        if(flag)cout<<"success on day "<<days<<endl;
        else cout<<"failure on day "<<days<<endl;
        days=0;
        flag=false;
        height=0;
        down=0;
    }
    return 0;
}
