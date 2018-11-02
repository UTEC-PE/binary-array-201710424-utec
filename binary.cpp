#ifndef BOOLEAN_H
#define BOOLEAN_H

#include <iostream>

template <class T>
class boolean {
    private:
        T* array;
        int numberContainers;
        int sizeContainer = sizeof(T) * 8;

    public:
        boolean(int boolsNeed) {
          this->numberContainers = (boolsNeed-1)/this->sizeContainer+1;
          this->array = new T[this->numberContainers];
          for (size_t i = 0; i < this->numberContainers; i++) {
            this->array[i] &= (T) 0<<(this->sizeContainer-1);
          }
        }

        void bitOn(int position) {
          this->array[position / this->sizeContainer] |= (T) 1 <<((this->sizeContainer-1)-position%this->sizeContainer);
        }

        void bitOff(int position) {
          this->array[position / this->sizeContainer] &= ~( (T) 1<<((this->sizeContainer-1)-position%this->sizeContainer));
        }

        bool operator[](int position) {
          bool bit = (this->array[position/this->sizeContainer] >> ((this->sizeContainer-1)-position%this->sizeContainer)) & 1U;
          return bit;
        }

        void clear() {
          for (size_t i = 0; i < this->numberContainers; i++) {
            this->array[i] &= (T) 0<<(this->sizeContainer-1);
          }
        }

        void print() {
          for (size_t i = 0; i < this->numberContainers; i++) {
            for (size_t j = 0; j < this->sizeContainer; j++) {
              std::cout << (*this)[i*this->sizeContainer+j];
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
