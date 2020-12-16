#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double mu1 = 3.11538;

ofstream fout2("nll.txt");
ofstream fout3("deltanll.txt");
ofstream fout4("deltanll2.txt");

double poisson(double mu, int k) {
  return (pow(mu, k) * exp(-mu)) / tgamma(k + 1);
}

double prob(vector<int> daten, double mu) {
  double product = 1;
  for(int i = 0 ; i < daten.size() ; ++i) {
        product = product * poisson(mu, daten[i]);
    }
  return product;
}

double prob2(vector<int> daten) {
  double product = 1;
  for(int i = 0 ; i < daten.size() ; ++i) {
        product = product * poisson(daten[i], daten[i]);
    }
  return product;
}


int main() {
    using namespace std;

    vector<int> daten;
    ofstream fout("likelihood.txt");
    ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }

    double likelihood = prob(daten, mu1);
    
    cout << likelihood << endl; 
    
    vector<double> daten1;
    
    for(double i=0; i<=600; i++) { 
      double x = i/100;
      fout << x << " " << prob(daten, x) << endl;

      fout2 << x << " " << -2*log(prob(daten, x)) << endl;

      double x1;

      
      fout3 << x << " " << -2*log(prob(daten, x))+2*log(prob(daten, mu1)) << endl;

      x1 = -2*log(prob(daten, x)/prob(daten, 3.12));

      if (x1<1.0) {
        daten1.push_back(x);
        fout4 << x <<" " << x1 << endl;
      }
    }
    cout << "uncertainty: " << (daten1[daten1.size()-1]-daten1[0])/2<< endl;

    double lambda = likelihood / prob2(daten);

    cout << "Lambda: " << -2*log(lambda) << endl;
    
    int n = 233;
    double z = (-2*log(lambda)-n)/(sqrt(2*n));

    cout << "Deviation z: " << z << endl;

    fin.close();
    fout.close();
    fout2.close();
    fout3.close();
    fout4.close();

}