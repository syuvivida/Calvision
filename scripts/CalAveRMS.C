#include <iostream>
#include <vector>
using namespace std;

void CalAveRMS()
{
  cout << "All numbers must be greater than 0" << endl;

  float sum=0;
  vector<float> inputNs;
  float in;
  unsigned int nNumbers=0;
  cin >> in;
  while(in>0){
    sum += in;
    inputNs.push_back(in);
    nNumbers++;
    cin >> in;
    
  }

  float average = nNumbers>0? sum/nNumbers: -9999;
  float sum2=0;
  for(unsigned int i=0; i < inputNs.size(); i++)
    {
      sum2 += pow(inputNs[i]-average,2);
    }
  float average_sq = nNumbers>1? sum2/(nNumbers-1): -9999;
  float std = nNumbers>0? sqrt(average_sq): -9999;
  cout << "There are " << nNumbers << " numbers " << endl;
  cout << "Average = " << average << endl;
  cout << "Std. = " << std << endl;

}
