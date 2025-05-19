// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the 
// median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums3Size = nums1Size + nums2Size;
    int nums3[nums3Size];

    int idx1 = 0, idx2 = 0;
    int mid = (nums1Size + nums2Size) / 2;
    int cont = 0;

    while (idx1 < nums1Size && idx2 < nums2Size) {

        if (nums1[idx1] < nums2[idx2]) {
            nums3[cont] = nums1[idx1];
            idx1++;
        }
        else {
            nums3[cont] = nums2[idx2];
            idx2++;
        }

        cont++;
    }

    if (idx2 < nums2Size) {
        for (int i = idx2; i < nums2Size; i++) {
            nums3[cont] = nums2[i];
            cont++;
        }
    }

    else if (idx1 < nums1Size) {
        for (int i = idx1; i < nums1Size; i++) {
            nums3[cont] = nums1[i];
            cont++;
        }
    }

    if ((nums1Size + nums2Size) % 2 == 0) {
        return (double) (nums3[mid] + nums3[mid - 1]) / 2;
    }

    else {
        return (double) nums3[mid];
    }

}