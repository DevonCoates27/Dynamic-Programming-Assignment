#include <vector>
#include <algorithm>

using namespace std;

pair< vector<int>, float >  assign(int N, int E, int M, float **prob)
{
    vector<vector<double> > matrix(N+1, vector<double>(E+1, 0));
    vector<vector<int> > choice(N+1, vector<int>(E+1, 0));
    vector<int> result(N, 0);

    for (int i = 1; i <= N; ++i) {
        for (int e = i; e <= E; ++e) {
            for (int m = 1; m <= min(e, M); ++m) {
                double temp = prob[i-1][m-1] * (i == 1 ? 1 : matrix[i-1][e-m]);
                if (temp > matrix[i][e]) {
                    matrix[i][e] = temp;
                    choice[i][e] = m;
                }
            }
        }
    }

    int e = E;
    for (int i = N; i >= 1; --i) {
        result[i-1] = choice[i][e];
        e -= choice[i][e];
    }

    return {result, matrix[N][E]};
}


pair< vector<int>, float >  assign2(int N, int E, int M, float **prob)
{
    vector<vector<double> > matrix(N+1, vector<double>(E+1, 0));
    vector<vector<int> > choice(N+1, vector<int>(E+1, 0));
    vector<int> result(N, 0);

    // Calculate the probabilities with the overload device applied
    vector<vector<float> > overloadProb(N, vector<float>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            overloadProb[i][j] = min(max(0.999f, prob[i][j]), prob[i][j] + 0.2f);
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int e = i; e <= E; ++e) {
            for (int m = 1; m <= min(e, M); ++m) {
                double temp = overloadProb[i-1][m-1] * (i == 1 ? 1 : matrix[i-1][e-m]);
                if (temp > matrix[i][e]) {
                    matrix[i][e] = temp;
                    choice[i][e] = m;
                }
            }
        }
    }

    int e = E;
    for (int i = N; i >= 1; --i) {
        result[i-1] = choice[i][e] > 0 ? choice[i][e] : 0-choice[i][e];
        e -= abs(choice[i][e]);
    }

    return {result, matrix[N][E]};

}


 
 
