import java.util.*;

class dsa_9_heapsort {
    static void heapify(int arr[], int n, int ind) {
        int largest = ind;
        int l = 2 * ind + 1; // index of the left child
        int r = 2 * ind + 2; // index of the right child

        // Check if the left child is larger than the current largest
        if (l < n && arr[largest] < arr[l]) { // Fix: Change > to <
            largest = l;
        }

        // Check if the right child is larger than the current largest
        if (r < n && arr[largest] < arr[r]) { // Fix: Change > to <
            largest = r;
        }

        // If the largest value is not the current node, swap them and heapify the affected subtree
        if (ind != largest) {
            int temp = arr[ind];
            arr[ind] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();
        System.out.println();

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        // Build a max heap from the input array
        for (int i = (n / 2); i >= 0; i--) {
            heapify(arr, n, i);
        }

        int ct = 1;
        for (int i = n - 1; i >= 0; i--) {
            // Swap the root (max element) with the last element
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Heapify the reduced heap
            heapify(arr, i, 0);

            System.out.print("Pass " + ct++ + ": ");
            for (int j = 0; j < n; j++) {
                System.out.print(arr[j] + " ");
            }
            System.out.println();
        }

        System.out.println("Sorted array:");
        for (int j = 0; j < n; j++) {
            System.out.print(arr[j] + " ");
        }
        System.out.println();
    }
}

/*First convert the array into heap data structure using heapify, then one by one delete the root node of the Max-heap and replace it with the last node in the heap and then heapify the root of the heap. Repeat this process until size of heap is greater than 1.

Build a heap from the given input array.
Repeat the following steps until the heap contains only one element:
Swap the root element of the heap (which is the largest element) with the last element of the heap.
Remove the last element of the heap (which is now in the correct position).
Heapify the remaining elements of the heap.
The sorted array is obtained by reversing the order of the elements in the input array.*/
