#include "Strategy.h"
#include "Read.h"

Strategy::Strategy(string fname){
    // Constructor
    Read reader(fname);
    reader.readFile();
    cout << "Grafo leído correctamente a continuació." << endl;


}