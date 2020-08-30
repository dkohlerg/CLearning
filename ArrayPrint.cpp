#include <iostream>
#include <cmath>
#include <numeric>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>


/*
Print array {10,8,2} like:
-------------------
|  0  |  1  |  2  |
-------------------
| 10  |  8  |  2  |
-------------------   

*/

void PrintHorizontalVector(std::vector<int>& vec);

int main(){
    std::vector<int> vec = {0,1,2,10,8,2};
    PrintHorizontalVector(vec);
    return 0;
}

void PrintHorizontalVector(std::vector<int>& vec){
    int dashes = std::ceil((vec.size())*6);
    for (int  n = 0; n < dashes; n ++ )
        std::cout << "-";
    std::cout << "-\n";

    for (int  n = 0; n < vec.size(); n ++ )
        printf("| %2d  ",n);
    std::cout << "|\n";

    for (int  n = 0; n < dashes; n ++ )
        std::cout << "-";
    std::cout << "-\n";

    for (int  n = 0; n < vec.size(); n ++ )
        printf("| %2d  ",vec[n]);
    std::cout << "|\n";

     for (int  n = 0; n < dashes; n ++ )
        std::cout << "-";
    std::cout << "-\n";
}

