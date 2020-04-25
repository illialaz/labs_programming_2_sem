#include <iostream>
using namespace std;

class Imatrix {
  private:
    int n, m;
    int** mas;
  public:
    virtual void put(void) = 0;
    virtual void print(void) = 0;
    // void add(const Imatrix* tmp) {};
    virtual void remove() = 0;
};

class matrix_int: public Imatrix {
  private:
    int n, m;
    int** mas;
  public:
    matrix_int() { n = 0; m = 0; mas = NULL; }
    matrix_int(const matrix_int& tmp) {
      matrix_int res;
      res.n = this->n;
      res.m = this->m;
      res.mas = new int*[m];
      for(int i = 0; i < m; i++) {
        res.mas[i] = new int[n];
      }

      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          res.mas[i][j] = this->mas[i][j];
        }
      }
    }
    void put(void) {
      cout << "Enter n, m" << endl;
      cin >> n >> m;
      mas = new int*[m];
      for(int i = 0; i < m; i++) {
        mas[i] = new int[n];
      }
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          cin >> mas[i][j];
        }
      }
    }
    void remove() {
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          mas[i][j] = 0;
        }
      }
    }
    void print() {
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          cout << mas[i][j];
        }
        cout << endl;
      }
    }

    // void add(const Imatrix* tmp) override {
    //   if(this->n == tmp->n && this->m == tmp->m) {
    //     for(int i = 0; i < m; i++) {
    //       for(int j = 0; j < n; j++) {
    //       this->mas[i][j] += tmp->mas[i][j];
    //       }
    //     }
    //   }
    // }
    ~matrix_int() {
      if(mas != NULL) {
        for(int i = 0; i < m; i++) delete mas[i];
        delete mas;
      }
    }
};

class matrix_double : public Imatrix {
  private:
    int n, m;
    double** mas;
  public:
    matrix_double() { n = 0; m = 0; mas = NULL; }
    matrix_double(const matrix_double& tmp) {
      matrix_double res;
      res.n = this->n;
      res.m = this->m;
      res.mas = new double*[m];
      for(int i = 0; i < m; i++) {
        res.mas[i] = new double[n];
      }

      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          res.mas[i][j] = this->mas[i][j];
        }
      }
    }
    void put(void) {
      cout << "Enter n, m" << endl;
      cin >> n >> m;
      mas = new double*[m];
      for(int i = 0; i < m; i++) {
        mas[i] = new double[n];
      }
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          cin >> mas[i][j];
        }
      }
    }
    void remove() {
      if(mas != NULL) {
        for(int i = 0; i < m; i++) {
          for(int j = 0; j < n; j++) {
            mas[i][j] = 0;
          }
        }
      }
    }
    void print(){
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          cout << mas[i][j];
        }
        cout << endl;
      }
    }
    // void add(const matrix_double* tmp) {
    //   if(this->n == tmp->n && this->m == tmp->m) {
    //     for(int i = 0; i < m; i++) {
    //       for(int j = 0; j < n; j++) {
    //       this->mas[i][j] += tmp->mas[i][j];
    //       }
    //     }
    //   }
    // }
    ~matrix_double() {
      for(int i = 0; i < m; i++) delete mas[i];
      delete mas;
    }
};