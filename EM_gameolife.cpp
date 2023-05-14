#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Life {
private:
  uint8_t* life;  
  uint32_t rows;
  uint32_t cols;
  
public:
    Life(uint32_t rows, uint32_t cols)
   : rows(rows), cols(cols), life(new uint8_t[rows* cols] ) {
    for (uint32_t i = 0; i < rows * cols; i++)
      life[i] = 0;
  }

  Life(ifstream& f) {
    f >> rows;
    f >> cols;
    life = new uint8_t[rows * cols];
    for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++){
                int value;
                f >> value;
                life[i * cols + j] = (uint8_t)value;
            }
    }
  }

  Life(const Life& orig) : rows(orig.rows), cols(orig.cols),
     life(new uint8_t[orig.rows * orig.cols]) {
    memcpy(life, orig.life, sizeof(uint8_t) * rows * cols);
  }

    Life& operator =(Life copy) {
     rows = copy.rows;
     cols = copy.cols;
     std::swap(life, copy.life);
     return *this;
  }

    void next() {
        Life old = Life(*this);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbor = 0;
                if (i != 0 && j != 0 && old(i - 1,j - 1))
                    neighbor++;
                if (i != 0 && old(i - 1,j))
                    neighbor++;
                if (i != 0 && j != cols - 1 && old(i - 1, j + 1))
                    neighbor++;
                if (j != 0 && old(i, j - 1))
                    neighbor++;
                if (j != cols - 1 && old(i,j + 1))
                    neighbor++;
                if (i != rows - 1 && j != 0 && old(i + 1, j - 1))
                    neighbor++;
                if (i != rows - 1 && old(i + 1, j))
                    neighbor++;
                if (i != rows - 1 && j != cols - 1 && old(i + 1, j + 1))
                    neighbor++;
                if (life[cols * i + j] == 1 && !(neighbor == 2 || neighbor == 3))
                    life[cols * i + j] = 0;
                else if (life[cols * i + j] == 0 && neighbor == 3)
                    life[cols * i + j] = 1;
            }
        }
    }
    uint8_t operator ()(uint32_t r, uint32_t c) const {
     return life[r * cols + c];
  }
    uint8_t& operator () (uint32_t r, uint32_t c){
     return life[r * cols + c];
    }
    friend std::ostream& operator <<(std::ostream& s, const Life& life) {
    for (int i = 0; i < life.rows; i++) {
        for (int j = 0; j < life.cols; j++)
          s << (int)life(i,j) << '\t';
        s << '\n';
    }
    return s;
  }
};


int main() {
    ifstream f("my.life.txt");
    Life life(f);
    // Life life(10,10);
  //  life(5,4) = 1;
  //  life(5,5) = 1;
  //  life(5,6) = 1;
    for (int i = 0; i< 10; i++) {
        cout << life << endl;
        life.next();
    }
}