
// Program to print a fraction in Egyptian Form using Greedy Algorithm
/*
 Example:Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
         Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156
 */
#include <iostream>
using namespace std;
  
void printEgyptian(int num, int dnum)
{
    if (dnum == 0 || num == 0)
        return;
  
    if (dnum%num == 0)
    {
        cout << "1/" << dnum/num;
        return;
    }

    if (num%dnum == 0)
    {
        cout << num/dnum;
        return;
    }

    if (num > dnum)
    {
        cout << num/dnum << " + ";
        printEgyptian(num%dnum, dnum);
        return;
    }
  
    int n = dnum/num + 1;
    cout << "1/" << n << " + ";
  
    printEgyptian(num*n-dnum, dnum*n);
 }
  
int main()
{
    int num = 12, dnum= 13;
    cout << "Egyptian Fraction Representation of "
         << num << "/" << dnum << " is\n ";
    printEgyptian(num, dnum);
    return 0;
}
