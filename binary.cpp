#ifndef BOOLEAN_H
#define BOOLEAN_H

#include <iostream>

class boolean {
    private:
        char* array;
        int size;

    public:
        boolean(int size) {
          this->size = (size-1)/8+1;
          this->array = new char[this->size];
          for (size_t i = 0; i < this->size; i++) {
            this->array[i] = 0;
          }
        }

        void bitOn(int position) {
          this->array[position / 8] |= 1<<(7-position%8);
        }

        void bitOff(int position) {
          this->array[position / 8] &= ~(1<<(7-position%8));
        }

        bool operator[](int position) {
          char sector = this->array[position/8];
          sector &= 1 << (7-position%8);
          if (sector == 0) {
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
            for (size_t j = 0; j < 8; j++) {
              std::cout << (*this)[i*8+j];
            }
            std::cout << ' ';
          }
          std::cout << '\n';
        }

        ~boolean() {
          delete[] this->array;
        }
};

#endif
