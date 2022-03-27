// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) { 
        if (arr[i] + arr[j] == value)
            count++;
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int i = len,
  j = len - 1; 
    for (int i = len - 1; arr[i] > value; i--)
      j--;
    for (int num = 0; num <= len; num++) {
      if(arr[num] > value / 2) {
        break;
      }
          for (int right = j; right > num; right--) {
            if (arr[num] + arr[right] == value) {
              count++;
              }
            if (arr[num] + arr[right] < value) {
              break;
            }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int pr = len - 1;
  for (int i = 0; i < len - 1; i++) {
    int check = 0;
    int le = i + 1;
    int mid = (le + pr) / 2;
    while (le <= pr) {
      if (arr[i] + arr[mid] == value) {
        count++;
        check = 1;
        break;
      } else if (arr[mid] + arr[i] > value) {
        pr = mid - 1;
      } else if (arr[mid] + arr[i] < value) {
        le = mid + 1;
      }
      mid = (le + pr) / 2;
    }
    int mid1 = mid;
    int mid2 = mid;
    if (check == 1) {
      while (arr[mid1 - 1] == arr[mid] && mid1 - 1 != i) {
        count++;
        mid1--;
      }
      while (arr[mid2 + 1] == arr[mid]) {
        count++;
        mid2++;
      }
    }
  }
  return count;
}
