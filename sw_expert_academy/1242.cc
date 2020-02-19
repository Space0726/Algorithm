#include <iostream>
#include <string>
  
using namespace std;
  
int pw[8];
int check[128];
bool code[2000];
  
bool isTrue()
{
    if (((pw[0] + pw[2] + pw[4] + pw[6]) * 3 + pw[1] + pw[3] + pw[5] + pw[7]) % 10 == 0)
        return true;
    return false;
}
  
int sum()
{
    int ret = 0;
    for (int i = 0;i < 8;i++)
        ret += pw[i];
    return ret;
}
  
bool change[16][4] = {
    {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},
    {0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
    {1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},
    {1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}
};
  
void init()
{
    for (int i = 0; i < 128; i++)
    {
        check[i] = -1;
    }
  
    check[13] = 0;
    check[25] = 1;
    check[19] = 2;
    check[61] = 3;
    check[35] = 4;
    check[49] = 5;
    check[47] = 6;
    check[59] = 7;
    check[55] = 8;
    check[11] = 9;
}
  
  
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int tc = 1;tc <= T;tc++)
    {
        init();
        int N, M;
        cin >> N >> M;
        int res = 0;
        string bef="", inp;
        for (int i = 0;i < N;i++)
        {
            cin >> inp;
            if (bef != inp)
            {
                int num;
                for (int j = 0;j < M;j++)
                {
  
                    //2진수 변환
                    switch (inp[j])
                    {
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                        num = inp[j] - 'A' + 10;
                        break;
                    default:
                        num = inp[j] - '0';
                        break;
                    }
                    for (int k = 0;k < 4;k++)
                    {
                        code[j * 4 + k] = change[num][k];
                    }                   
                }
  
                int changed = 0;
                int len = 0;
                int mul;
                for (int j = 1;j < M*4;j++)
                {
                    if (code[j] != code[j - 1])
                    {
                        changed++;
                    }
              
                    if (changed == 32)
                    {
                        mul = len / 49;
                        int idx = 0;
                        int l = 0;
                        for(int k=0;k<56;k++)
                        {
                            idx = (idx << 1) + code[j - (56 - k)*mul];
                            if (k % 7 == 6)
                            {
                                pw[l++]=check[idx];
                                idx = 0;
                            }
                        }
  
                        bool tf = true;
                        for (int test = (j - 56*mul)/4;test <= j/4;test++)
                        {
                            if (bef[test] != inp[test])
                            {
                                tf = false;
                                break;
                            }
                        }
                        if (isTrue() && !tf)
                        {
                            res += sum();
                        }
                        len=0;
                        changed = 0;
                    }
  
                    if (changed >= 4)
                        len++;
                }
            }
  
            bef = inp;
        }
  
        cout << "#" << tc << " " << res << endl;
    }
  
    return 0;
}