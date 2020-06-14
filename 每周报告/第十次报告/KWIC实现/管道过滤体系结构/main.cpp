#include <iostream>
#include "filter.h"
using namespace std;
int main()
{
    inputFilter filter1;
    filter1.read();
    filter1.trans();
    transFilter filter2;
    transport(&filter1.output,&filter2.input);
    filter2.exchange();
    sortFilter filter3;
    transport(&filter2.output,&filter3.input);
    filter3.sortthis();
    outputFilter filter4;
    transport(&filter3.output,&filter4.input);
    filter4.trans();
    filter4.put();
    return 0;
}