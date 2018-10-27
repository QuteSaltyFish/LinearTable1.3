#include <iostream>
#include "seqStack.hpp"
#include "linkQueue.hpp"
using namespace std;

void arrive(int x, int n,seqStack<int>& in, linkQueue<int> &out)
{
    if (!in.isFull())
        in.push(x,n);
    else
        out.enQueue(n);
}
void leaveOutPark(int n, linkQueue<int> &out)
{
    int size=out.size();
    int carnum;
    for (int i=0; i<size; ++i)
    {
        carnum = out.dequeue();
        if (carnum == n)
        {
            cout<<"Car "<<carnum<<" outside has left!\n";
            return;
        }
        else
            out.enQueue(carnum);
    }
    cout<<"There is no such car!\n";
}
    
int getout(int n, int time, seqStack<int> &in, seqStack<int> &tmp,linkQueue<int>& out)
{
    int a,b, result=-1;
    while (!in.isEmpty() && in.top()!=n )
    {   //如果不是要的那一辆车就放到tmp里面
        b=in.top();
        a=in.pop();
        tmp.push(a, b);
    }
    if (!in.isEmpty())
        result = in.pop();
    else
        leaveOutPark(n, out);
    
    while (!tmp.isEmpty())
    {
        b=tmp.top();
        a=tmp.pop();
        in.push(a,b);
    }
    while (!in.isFull() && !out.isEmpty())
    {
        b=out.dequeue();
        in.push(time,b);
    }
    return result;
}
int main() {
    seqStack<int> inPark(2), tmpPark(2);
    linkQueue<int> outPark;
    char flag;
    int currenttime;
    int data, num;
    cout<<"PLS input type:";
    cin.get(flag);
    while (flag=='A' || flag=='D')
    {
        cout<<"PLS input Car number and Time:";
        cin>>num>>data;
        if (flag == 'A')
        {
            arrive(data, num, inPark, outPark);
            currenttime = data;
        }
        else if (flag == 'D' && !inPark.isEmpty())
        {
            int intime=getout(num, data, inPark, tmpPark, outPark);
            currenttime = data;
            if (intime!=-1)
                cout<<"Duration time is:"<<(currenttime-intime)<<endl;
        }
        else if (flag == 'D' && inPark.isEmpty())
        {
            cout<<"There isn't enough Car!\n";
        }
        cin.get();
        cout<<"PLS input type:";
        cin.get(flag);
    }
    
    /*int **elem;
    int initsize = 10;
    elem = new int*[initsize];
    for (int i=0; i<initsize; ++i)
        elem[i] = new int[2];
    for (int i=0; i<10; ++i)
    {
        for (int j=0; j<2; ++j)
        {
            elem[i][j] = i*j;
            cout<<elem[i][j];
        }
    }*/
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
