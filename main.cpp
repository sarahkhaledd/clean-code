#include <iostream>
#include <cassert>

using namespace std;

/*
    You need to refactor the following function using clean code guidelines
        - Meaningful names
        - Functions
        - Comments
        - Formatting
        - Error Handling
    After finishing, you are requested to write unite tests below in the main code for the function.
*/
bool checkOnArrayValue(const int array[]) {
    return(array == nullptr );
}

bool isInvalidIndices(int startIndex, int endIndex, int arraySize) {
    return (startIndex < 0 || endIndex < 0 || startIndex >= arraySize || endIndex > arraySize || startIndex >= endIndex);
}

int calculateArraySumInRange(int* array, int startIndexOfElement, int endIndexOfElement, int arraySize) {

     if(checkOnArrayValue(array) || isInvalidIndices(startIndexOfElement,endIndexOfElement,arraySize)) {
        return 0;  //Return 0 to indicate an error
    }

    int resultOfSummation = 0;

    for (int index = startIndexOfElement; index < endIndexOfElement; index++) {
        resultOfSummation+=array[index];
    }
    return resultOfSummation;
}

int main () {
    int resultOfSum;
    int myArray[] = {1, 2, 3, 0, 5};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    //Test with valid ranges (happy scenario)
    resultOfSum = calculateArraySumInRange(myArray, 0, 4, arraySize);
    assert( resultOfSum == 6);

    //Test with valid ranges (happy scenario)
    resultOfSum = calculateArraySumInRange(myArray, 1, 3, arraySize);
    assert(resultOfSum == 5);

    //Test with Invalid ranges
    resultOfSum = calculateArraySumInRange(myArray, -1, 5, arraySize);
    assert(resultOfSum == 0);

    //Test with empty range values of start and end Indices
    resultOfSum = calculateArraySumInRange(myArray, 2, 2, arraySize);
    assert(resultOfSum == 0);

    //Test with Invalid startIndex (negative value) and Valid value of endIndex
    resultOfSum = calculateArraySumInRange(myArray, -1, 4, arraySize);
    assert(resultOfSum == 0);

    //Test with Valid startIndex and Invalid value of endIndex (negative value)
    resultOfSum = calculateArraySumInRange(myArray, 0, -3, arraySize);
    assert(resultOfSum == 0);

    //Test with Valid startIndex and Invalid value of endIndex (out of boundary array)
    resultOfSum = calculateArraySumInRange(myArray, 3, 8, arraySize);
    assert(resultOfSum == 0);

    //Test with Invalid startIndex (out of boundary array) and valid value of endIndex
    resultOfSum = calculateArraySumInRange(myArray, 8, 3, arraySize);
    assert(resultOfSum == 0);

    //Test with valid ranges but pass null pointer array
    resultOfSum = calculateArraySumInRange(nullptr, 0, 3, arraySize);
    assert( resultOfSum == 0);

    std::cout << "All tests passed!" << std::endl;

    return 1;
}
