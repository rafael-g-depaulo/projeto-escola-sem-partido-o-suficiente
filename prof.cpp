#include <vector>

using namespace std;

class Prof {
  public:
    int hab;
    int ind;
    vector<int> escolas;
    
  Prof(int _ind, int _hab, int esc1, int esc2, int esc3, int esc4, int esc5) {
    ind = _ind;
    hab = _hab;
    escolas.push_back(esc1);
    escolas.push_back(esc2);
    escolas.push_back(esc3);
    escolas.push_back(esc4);
    escolas.push_back(esc5);
  }
};