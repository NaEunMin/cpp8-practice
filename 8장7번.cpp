/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class BaseMemory{
    char *mem;
    protected:
    BaseMemory(int size){ mem = new char [size]; }
    char getData(int index){ return mem[index]; }
    void setData(int index, char ch){ mem[index] = ch; }
};

class ROM : public BaseMemory{
    public:
    ROM(int size, char x[], int length) : BaseMemory(size){
        for(int i=0; i<length; i++) setData(i, x[i]);
    }
    char read(int index){ return getData(index); } 
};

class RAM : public BaseMemory{
    public:
    RAM(int size) : BaseMemory(size){}
    void write(int index, char ch){ setData(index, ch); }
    char read(int index){ return getData(index); }
};

int main()
{
    char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
    return 0;
}
