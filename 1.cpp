#include <iostream>
#include <sstream>
#include <utility>
#include <stdlib.h>
using namespace std;

bool str(float *st,int n)
{
    char x;
    bool h=true;
    string t;
    getline(cin,t);
    istringstream stream(t);
    for(unsigned int i = 0; i<n; i++)
    {
        if(!(stream>>st[i]))
        {
            h = false;
            return false;
        }
    }
    if (stream>>x){
        cout<<"An error has occured while reading numbers from line";
        exit(0);
    }
    return true;
}

void reverse (float* st, int n)
{
  for(unsigned int i=0; i < (n/2); i++) {
          swap(st[i], st[n-i-1]);
      }
  }







void print_st(float * st,int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        cout << st[i] << " ";
    }
}

int main() {

        int n;
            if(!(cin >> n)||(n<0)) {
        cout << "An error has occured while reading numbers from line";
        return 0;
    }
        cin.get();
        float *st = new float[n];
        if (str(st, n)) {
            reverse(st, n);
            print_st(st, n);
        } else {
            cout << "An error has occured while reading numbers from line";
        }
        delete[] st;
        return 0;
    }
