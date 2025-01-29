#include <iostream>
#include <stdlib.h>
#include <stdexcept>

const size_t SORTEDLIST_MAX_SIZE= 20;

class SortedList{
    private:
        size_t currentSize;
        float Array[SORTEDLIST_MAX_SIZE];
    public:
        SortedList();
        void copy(const SortedList& other);
        float index(size_t ind);
        size_t insert(float number);
        float remove(size_t index);
        size_t find(float number);
        void print(void);
        size_t RecursiveBinary(float Array[], int low, int high, float key) {
            if (low > high) {
                std::cout<<"notfound"<<std::endl;
                return -1;  // Return -1 to indicate "not found"
            }

            int mid = (low + high) / 2;
            float midvalue = Array[mid];

            if (midvalue == key) {
                std::cout<<"found!!!! : " << midvalue<< "in index:"<< mid <<std::endl; 
                return mid;
            } else if (midvalue > key) {
                return RecursiveBinary(Array, low, mid - 1, key);
            } else {
                return RecursiveBinary(Array, mid + 1, high, key);
            }
        }

};

SortedList::SortedList():currentSize(0){}

void SortedList::copy(const SortedList& other){
    if(other.currentSize > SORTEDLIST_MAX_SIZE){
        throw std::overflow_error("Cannot copy since it exceed the capability of array.");
    }
    for(int i = 0; i < other.currentSize ; i++){
        Array[i] = other.Array[i];   
    }
    currentSize = other.currentSize;
}

float SortedList::index(size_t ind){
    if(ind > SORTEDLIST_MAX_SIZE - 1 || ind >= currentSize){
        throw std::out_of_range("out of range");
        return 0;
    }
    else{
        std::cout<<"index is given:"<<Array[ind]<<std::endl;
        return Array[ind];
    }
}


size_t SortedList::insert(float number) {
    if (currentSize  >= SORTEDLIST_MAX_SIZE) {
        throw std::length_error("List is full, cannot insert.");
    }

    int i = 0;
    while (i < currentSize && Array[i] < number) {
        i++;
    }

    for (int j = currentSize; j > i; j--) {
        Array[j] = Array[j - 1];
    }

    Array[i] = number;
    currentSize++;

    std::cout<<"filled index : " << i << std::endl;
    std::cout <<"filled with:" << Array[i]<<std::endl;
    return i;
}


float SortedList::remove(size_t index){
    if(index > currentSize -1){
        throw std::domain_error("domain error");
    }
    int temp = Array[index];
    for(int i = index; i <= currentSize + 1 ; i++){
        Array[i] = Array[i+1];
    }
    currentSize --;
    Array[currentSize] = 0;
    return temp;
}


size_t SortedList::find(float number){
    float key = number;
    int low = 0;
    int high = currentSize - 1;
    size_t result = RecursiveBinary(Array, low, high, key);
    return result;
}

void SortedList::print(void){
    if(currentSize == 0){
        std::cout<<"empty list."<<std::endl;
    }
    else{
        for(int i=0; i<currentSize;i++){
            std::cout<<"Array"<<"["<<i<<"]:  "<<Array[i]<<"  "<<std::endl;
        }
    }
}



int main(){
    float denemenum = 2.5;
    float ax=3.7;
    float k1=1.5;
    float k2=5.7;
    float k3=10.43;
    float k4= 7.77;
    SortedList object1;
    object1.insert(denemenum);
    object1.insert(ax);
    //object1.print();
    //object1.print();
    SortedList object2;
    object2.copy(object1);
    //object2.print();
    int indexd = 1;
    //object2.index(0);
    object2.insert(k1);
    object2.insert(k2);
    object2.insert(k3);
    std::cout<<"k3 inserted before k4"<<std::endl;
    object2.insert(k4);
    //object2.print();
    object2.remove(2);
    std::cout<<"removed....." << std::endl;
    //object2.print();
    //object2.find(5.7);
    object2.insert(6.4);
    object2.insert(8.9);
    object2.insert(9.1);
    object2.insert(3.2);
    object2.insert(0.9);
    object2.insert(100.2);
    object2.insert(0.01);
    object2.insert(35.3);
    object2.insert(87.3);
    object2.insert(89.7);
    object2.insert(78.1);
    object2.insert(98.4);
    object2.insert(2.4);
    object2.insert(45.5);
    object2.insert(4.5);
    //object2.insert(1.5);
    /*object2.insert(9.2);*/
    //object2.print();
    object2.find(523);
    object2.find(87.3);
    SortedList object3;
    object3.copy(object2);
    object3.print();
    object3.remove(15);
    std::cout<<"removed!!"<<std::endl;
    object3.print();
    object3.remove(19);
    return 0;
    
}