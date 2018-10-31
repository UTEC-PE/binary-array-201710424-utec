#ifndef BOOLEAN_H
#define BOOLEAN_H

#include <iostream>

class boolean {
    private:
        char* array;
        int size;

    public:
        boolean(int size) {
          this-> size = size/8+1;
          this->array = new char[size];
          for (size_t i = 0; i < size; i++) {
            this->array[i] = 0;
          }
        }

        void bitOn(int position) {
          this->array[position / 8] |= 1<<(position%8);
        }

        void bitOff(int position) {
          this->array[position / 8] &= ~(1<<(position%8));
        }

        bool operator[](int position) {
          this->array[position/8] &= 1 << (position%8);
          if (this->array[position/8] == 0) {
            return false;
          } else return true;
        }

        void clear() {
          for (size_t i = 0; i < this->size/8+1; i++) {
            this->array[i] = 0;
          }
        }

        void print() {
          for (size_t i = 0; i < this->size; i++) {
            std::cout << (int) this->array[i] << ' ';
          }
          std::cout << '\n';
        }

        ~boolean() {
          delete[] this->array;
        }
};

#endif
