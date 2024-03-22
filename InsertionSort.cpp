
// Insertion Sort Function
// Worst case: O(n^2), Best case O(n)

template <typename T>
T cityInsertionSort(T (&numbers)[]) {
    for (i = 1; i < sizeof(numbers); ++i) {
        j = i;
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}
  
