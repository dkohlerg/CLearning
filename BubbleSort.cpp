#include <iostream>
#include <cmath>
#include <numeric>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>

std::vector<int> GenerateRndVec(int nOfn, int min, int max);
void BubbleSort(std::vector<int>& vNum); // with & we got the reference to the vector in order to modify it from the finction

int main(){
    
    std::vector<int> vVals = GenerateRndVec(5, 1, 50);
    for(auto x: vVals){
        std::cout << x << "\n";
    }
    BubbleSort(vVals);
    return 0;
}


std::vector<int> GenerateRndVec(int nOfn, int min, int max){
    std::vector<int> vValues;
    srand(time(NULL));
    int randVal = 0;
    for (int i = 0;  i < nOfn; i++){
        randVal = min + std::rand() % ((max + 1) - min);
        vValues.push_back(randVal);
    }
    return vValues;
}

void BubbleSort(std::vector<int>& vNum){
    int i = vNum.size() -1;
    std::cout << i;
    while(i >= 1){
        int j = 0;
        while(j < i){
            printf("\nIs %d > %d\n",vNum[j], vNum[j+1]);
            if(vNum[j] > vNum[j +1]){
                std::cout << "Switch\n";
                int temp = vNum[j];
                vNum[j] = vNum[j+1];
                vNum[j+1] = temp;
            } else std::cout << "Don't Switch\n";
            j++;
            for (int k: vNum){
                std::cout << k << ",";
            }
        }
        std::cout << "\nEnd of round\n";
        i--;
    }
}