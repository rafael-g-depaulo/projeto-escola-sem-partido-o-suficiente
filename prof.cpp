#include <vector>

using namespace std;

class Prof {
  public:
    int hab;
    vector<int> escolas;
    
  Prof(int _hab, int esc1, int esc2, int esc3, int esc4, int esc5) {
    hab = _hab;
    escolas.push_back(esc1);
    escolas.push_back(esc2);
    escolas.push_back(esc3);
    escolas.push_back(esc4);
    escolas.push_back(esc5);
  }
};