
// Selection Sort C++
// Worst case: O(n^2), Best case O(n^2)

template<typename T>
void selectionSort (T (&numbers)[]) {
    for (int i = 0; i < sizeof(numbers) - 1; ++i) {
        int indexSmallest = i;
        for (int j = i + 1; j < sizeof(numbers); ++j) {
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}
