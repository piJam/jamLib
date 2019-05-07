#include <iostream>
#include <cstring>
#include <cstdlib>

#include "DynamicArray.h"

using namespace std;
using namespace jamLib;

class Test : public Object
{
    int m_index;
public:
    Test(int i = 0)
    {
        m_index = i;
    }
bool operator ==(const Test& e)
{
    return m_index == e.m_index;
}

};

int main()
{
    DynamicArray<DynamicArray<int>> array;
    array.resize(10);

    for(int i = 0;i<array.length();i++)
    {
        array[i].resize(i);
        for(int j = 0; j < array[i].length(); j++)
        {
            array[i].set(j,j);
        }
    }

    for(int i = 0;i<array.length();i++)
    {

        for(int j = 0; j < array[i].length(); j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }

}


