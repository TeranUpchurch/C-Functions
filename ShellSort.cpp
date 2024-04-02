
// Shell Sort C++
// Time Complexity: O(n^1.5)

void InsertionSortInterleaved(int (&numbers)[], int numbersSize, int startIndex, int gap) {
    int temp = 0;
    int j = 0;
    for (int i = startIndex + gap; i < numbersSize; i = i + gap) {
        j = i;
        while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
            temp = numbers[j];
            numbers[j] = numbers[j - gap];
            numbers[j - gap] = temp;
            j = j - gap;
        }
    }
}

void ShellSort(int (&numbers)[], int numbersSize, int gapValues[]) {
    int size = sizeof(gapValues);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            InsertionSortInterleaved(numbers, numbersSize, j, i);
        }
    }
}
