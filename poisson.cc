#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
  return (pow(mu, k) * exp(-mu)) / tgamma(k + 1);
}

int main() {
    using namespace std;

    vector<int> zaehler(11);

    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    ofstream fout1("histpoi.txt");

    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;
    }
    for ( unsigned int k = 0 ; k < zaehler.size(); ++k) {
      fout << k << " " << zaehler[k] << endl;
    }

    for ( unsigned int k = 0 ; k < zaehler.size(); ++k) {
      double poi = 234 * poisson(3.11538, k);
      fout1 << k << " " << zaehler[k] << " " << poi << endl;
    }

    fin.close();
    fout.close();
    fout1.close();

}