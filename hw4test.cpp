#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

pair< vector<int>, float  >  assign(int N, int E, int M, float **prob);
pair< vector<int>, float  >  assign2(int N, int E, int M, float **prob);

int main(int argc, char *argv[])
{
   ifstream ifile(argv[1]);

   if(!ifile.is_open()){
      std::cout << "File failed to open" << std::endl;
   }

   int N, E, M;
   ifile >> N >> E >> M;
   float *prob[N];

   
   for (int i = 0; i < N ; i++)
	{
            prob[i] = new float[M];
	    for (int j= 0; j < M; j++)
		{
		    float s;
		    ifile >> s;
		    prob[i][j] = s;
		}
	}

   pair< vector<int>,  float> res = assign(N,E,M,prob); 
 
   cout << "\nBase case : \n\n";
   cout << "Energy assignment : ";
   for (int i = 0; i < res.first.size(); i++)
	{
 	    cout <<  res.first[i] << " ";
	}
   cout << "   prob : " << res.second << endl;

   pair< vector<int>, float  >  res2 = assign2(N, E, M, prob);
 
   cout << "\nBase case : \n\n";
   cout << "Energy assignment : ";
   for (int i = 0; i < res2.first.size(); i++)
	{
 	    cout <<  res2.first[i] << " ";
	}
   cout << "   prob : " << res2.second << endl;

   return 0;
}
 
