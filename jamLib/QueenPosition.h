#ifndef QUEENPOSITION_H
#define QUEENPOSITION_H
#include<cstring>
#include "LinkList.h"
using namespace std;

namespace jamLib {
template <int size>
class QueenPosition : public Object
{
protected:
    enum { N = size + 2};
    struct Pos : public Object
    {
        int x;
        int y;
        Pos(int px=0, int py=0):x(px), y(py){}
    };

    int m_checkerboard[N][N];
    Pos m_direction[3];
    int m_count;

    LinkList<Pos> m_point;

    void init()
    {
        m_count = 0;
        for (int i=0; i<N; i+=(N-1))
        {
            for(int j=0; j<N; j++)
            {
                m_checkerboard[i][j] = 2;
                m_checkerboard[j][i] = 2;
            }
        }
        for(int i=1; i<=size; i++)
        {
            for (int j=1; j<=size; j++) {
                m_checkerboard[i][j] = 0;
            }

        }

        m_direction[0].x = -1;
        m_direction[0].y = -1;
        m_direction[1].x = 0;
        m_direction[1].y = -1;
        m_direction[2].x = 1;
        m_direction[2].y = -1;

    }

    void print()
    {
        for ( m_point.move(0); !m_point.end(); m_point.next())
        {
             cout << "("<< m_point.current().x << "," << m_point.current().y << ")" ;
        }
        cout << endl;

        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                switch (m_checkerboard[i][j])
                {
                    case 0 :
                        cout << " ." ; break;
                    case 1 :
                        cout << " #"; break;
                    case 2 :
                        cout << " +"; break;
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    bool check(int i, int j, int d)
    {
        bool falg = true;
        do
        {
            i +=  m_direction[d].x;
            j +=  m_direction[d].y ;
            falg = falg && (m_checkerboard[i][j] == 0) ;

        }while(falg);

        return( m_checkerboard[i][j] == 2 ) ;
    }

    void run(int j)
    {
        if(j<=size)
        {
            for (int i=1; i<=size; i++)
            {

               if( check(i, j, 0) && check(i, j, 1) && check(i, j, 2) )
               {

                    m_checkerboard[i][j] = 1;

                    m_point.insert(Pos(i, j));

                    run( j + 1);

                    m_checkerboard[i][j] = 0;

                    m_point.remove(m_point.length() - 1);
               }

            }
        }
        else
        {
            m_count++;
            print();
        }
    }




public:
   QueenPosition()
   {
       init();
   }

   void run()
   {
       run(1);
       cout << m_count << endl;
   }

};

//---------------数据结构---43,44,45
struct Node
{
    int m_value;
    Node* next;
};

Node* create_list(int v, int len)
{
    Node* ret = NULL;
    Node* slider =NULL;

    for(int i=0; i<len; i++)
    {
        Node* n = new Node();
        n->m_value = v++;
        n->next = NULL;

        if( slider == NULL)
        {
            slider = n;
            ret = n;
        }
        else
        {
            slider->next = n;
            slider = n;
        }
    }
    return ret;
}

void print_list(Node* list)
{
    while(list)
    {
        cout << list->m_value << " -> ";

        list = list->next;
    }
    cout << "NULL" << endl;
}

void r_print_enent(Node* list)
{
    if(list != NULL)
    {
        r_print_enent(list->next);

        if(list->m_value % 2 == 0)
            cout<< list->m_value << endl;
    }

}

void delete_list(Node* list)
{
    while(list)
    {
        Node* temp = list;
        list = list->next;
        delete temp;
    }
}

Node* reverse(Node* list)
{
    if( list == NULL || list->next == NULL )
    {
        return list;
    }
    else
    {
        Node* guard = list->next;
        Node* ret = reverse(list->next);

        guard->next = list;

        list->next = NULL;
        return ret;
    }
}

int sum(int num)
{

    if( num == 1)
    {
       num = 1;
    }else
    {
       num += sum(num - 1);
    }
    return num;
}

Node* merge(Node* list1, Node* list2)
{
    if( list1 == NULL)
    {
        return list2;
    }
    else if(list2 == NULL)
    {
        return list1;
    }
    else if( list1->m_value < list2->m_value)
    {
//        Node* list1_ = list1->next;
//        Node* list = merge(list1_, list2);

//        list1->next = list;
//        return list1;
        return (list1->next = merge(list1->next, list2), list1);
    }
    else
    {
        Node* list2_ = list2->next;
        Node* list = merge(list1, list2_);

        list2->next = list;
        return list2;
    }
}

void hannoTower(int n, char a,char b, char c)
{
    if(n==1)
    {
        cout<< a << "=>" << c << endl;
    }else
    {
        hannoTower(n-1, a, c, b);
        hannoTower(1, a, b, c);
        hannoTower(n-1, b, a, c);
    }

}

void permutation(char* s, char* e)
{
    if(*s == '\0')
    {
        cout << e << endl;
    }
    else
    {
        for (int i = 0; i<static_cast<int>(strlen(s)); i++)
        {
            swap(s[0], s[i]);
            permutation(s+1, e);
            swap(s[0], s[i]);
        }
    }
}

}

#endif // QUEENPOSITION_H
