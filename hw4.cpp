#include <vector>

using namespace std;

pair< vector<int>, float >  assign(int N, int E, int M, float **prob)
{
    vector <int> res0;
    float p = prob[N-1][M-1];

    for (int i =0; i < N; i++)
        res0.push_back(0);	
    return make_pair(res0, p);

}


pair< vector<int>, float >  assign2(int N, int E, int M, float **prob)
{
    vector <int> res0;
    float p = prob[N-1][M-1];

    for (int i =0; i < N; i++)
        res0.push_back(0);	
    return make_pair(res0, p);

}


 
 
