/*
Arrays.binarySearch()
Collections.binarySearch()
*/

private static int binarySearch(int[] arr, int target) {
    int start = 0;
    int end = arr.length;

    while (end > start) {
        it mid = (start + end) / 2;
        int value = arr[mid];

        if (value == target) {
            return mid;
        } else if (value > target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}