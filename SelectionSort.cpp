
// Selection Sort Function
// Worst case: O(n^2), Best case O(n^2)

template<typename T>
void selectionSort (T (&numbers)[]) {
    for (i = 0; i < sizeof(numbers) - 1; ++i) {
        indexSmallest = i;
        for (j = i + 1; j < numbersSize; ++j) {
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }
        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}
