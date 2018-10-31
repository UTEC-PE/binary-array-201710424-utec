#ifndef BOOLEAN_H
#define BOOLEAN_H

#include <iostream>

class boolean {
    private:
        char* array;
        int size;

    public:
        boolean(int size) {
          this-> size = size;
          array = new char[size/8+1];
          for (size_t i = 0; i < size/8+1; i++) {
            array[i] = 0;
          }
        }

        void bitOn(int position) {
          array[position / 8] |= 1<<(position%8);
        }

        void bitOff(int position) {
          array[position / 8] &= ~(1<<(position%8));
        }

        bool operator[](int position) {
          array[position/8] &= 1 << (position%8);
          if (array[position/8] == 0) {
            return false;
          } else return true;
        }

        void clear() {
          for (size_t i = 0; i < this->size/8+1; i++) {
            array[i] = 0;
          }
        }

        void print() {
          for (size_t i = 0; i < this->size; i++) {
            //std::cout << this->[i] << ' ';
          }
          std::cout << '\n';
        }

        ~boolean() {
          delete[] array;
        }
};

#endif
