#include <iostream>
#include <string>
using namespace std;

class Strategy {
public:
    Strategy(){
        // Constructor
    }
    Strategy(string fname);
    ~Strategy(){
        // Destructor
    }
    virtual void solve();
};
