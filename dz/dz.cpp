#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

int findMinSumPosition(const std::vector<int>& arr, int currentIndex, int currentSum, int minSum, int& minPosition) 
{
   
    if (currentIndex + 10 > arr.size()) {
        return minSum;
    }


    currentSum = 0;
    for (int i = currentIndex; i < currentIndex + 10; ++i) {
        currentSum += arr[i];
    }

    if (currentSum < minSum) {
        minSum = currentSum;
        minPosition = currentIndex;
    }


    return findMinSumPosition(arr, currentIndex + 1, currentSum, minSum, minPosition);
}

int main() 
{
    setlocale(LC_ALL, "ru");
    std::srand(std::time(0));
    std::vector<int> arr(100);

  
    for (int& num : arr) {
        num = std::rand() % 101 - 50;
    }

    int minPosition = 0;
    int minSum = std::numeric_limits<int>::max(); 

  
    findMinSumPosition(arr, 0, 0, minSum, minPosition);

  
    std::cout << "Минимальная сумма начинается с позиции: " << minPosition << "\n";
    std::cout << "Минимальная сумма: " << minSum << "\n";

    return 0;
}
//*****************************************************************************************************************************//

int findMax(const std::vector<int>& arr) {
    int maxVal = std::numeric_limits<int>::min();
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}


int findMax(const std::vector<std::vector<int>>& arr) {
    int maxVal = std::numeric_limits<int>::min();
    for (const auto& row : arr) {
        for (int num : row) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
    }
    return maxVal;
}


int findMax(const std::vector<std::vector<std::vector<int>>>& arr) {
    int maxVal = std::numeric_limits<int>::min();
    for (const auto& plane : arr) {
        for (const auto& row : plane) {
            for (int num : row) {
                if (num > maxVal) {
                    maxVal = num;
                }
            }
        }
    }
    return maxVal;
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<int> arr1D = { 1, 2, 3, -5, 7, 8, 10, -2 };
    std::cout << "Максимальное значение в одномерном массиве: " << findMax(arr1D) << "\n";


    std::vector<std::vector<int>> arr2D = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << "Максимальное значение в двумерном массиве: " << findMax(arr2D) << "\n";


    std::vector<std::vector<std::vector<int>>> arr3D = {
        {
            {1, 2},
            {3, 4}
        },
        {
            {5, 6},
            {7, 8}
        }
    };
    std::cout << "Максимальное значение в трехмерном массиве: " << findMax(arr3D) << "\n";

    return 0;
}

