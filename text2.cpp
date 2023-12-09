////
//// Created by huangruidong on 2023/2/28.
////
//#include <stdio.h>
//
//void swap(int* a, int* b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//int partition(int arr[], int sm, int la)
//{
//    int i = sm - 1, j = sm;
//    int temp = arr[la];
//    for (; j <= la - 1; j++) {
//        if (arr[j] < temp) {
//            i++;
//            swap(&arr[i], &arr[j]);
//        }
//    }
//    swap(&arr[i + 1], &arr[la]);
//    return i + 1;
//}
//
//void quickSort(int arr[], int l, int r)
//{
//    int pi = -1;
//    if (l < r) {
//        pi = partition(arr, l, r);
//        quickSort(arr, l, pi - 1);
//        quickSort(arr, pi + 1, r);
//    }
//}
//
//int binarySearch(int arr[], int key, int low, int high)
//{
//    if(low > high) {
//        return 0;
//    }
//    int mid = (low + high) / 2;
//    if (key > arr[mid])
//        return binarySearch(arr, key, mid + 1, high);
//    else if (key < arr[mid])
//        return binarySearch(arr, key, low, mid - 1);
//    else
//        return 1;
//}
//
//int binarySearchChkPair(int arr[], int n, int key)
//{
//    //quickSort(arr, 0, n - 1);
//    for (int i = 0; i < n - 1; i++)
//        if (binarySearch(arr, key - arr[i], i + 1, n - 1))
//            return 1;
//    return 0;
//}
//
//int main()
//{
//    int arr[] = { 1, 4, 45, 6, 10, -8 };
//    int key = 14;
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    quickSort(arr, 0, n - 1);
//
//    if (binarySearchChkPair(arr, n, key))
//        printf("Yes");
//    else
//        printf("No");
//
//    return 0;
//}