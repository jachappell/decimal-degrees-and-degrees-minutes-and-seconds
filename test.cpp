#include <iostream>
#include "dms.h"

using namespace std;
using namespace DMS;

int main()
{
    double ang ;
    
    cout << "Enter angle (decimal degrees): " ;
    cin >> ang ;
    
    string dms ;

    dms = DegreesMinutesSeconds(ang) ;

    cout << dms << endl ;

    ang = DecimalDegrees(dms) ;

    cout << ang << endl ;

    return 0 ;
}
