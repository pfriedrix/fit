#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int swaps = 0, comparisons = 0;

struct MinHeapNode {
    int element;

    int i;
};


void swap(MinHeapNode *x, MinHeapNode *y);


class MinHeap {

    MinHeapNode *harr;


    int heap_size;

public:

    MinHeap(MinHeapNode a[], int size);


    void MinHeapify(int);

    int left(int i) { return (2 * i + 1); }


    int right(int i) { return (2 * i + 2); }


    MinHeapNode getMin() { return harr[0]; }

    void replaceMin(MinHeapNode x) {
        harr[0] = x;
        MinHeapify(0);
    }
};


MinHeap::MinHeap(MinHeapNode a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(MinHeapNode *x, MinHeapNode *y) {
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}


void display(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void merge(int *arr, int low, int high, int mid, const int length) {
    int c[length];
    memset(c, 0, length * sizeof(int));
    int i = low;
    int k = low;
    int j = mid + 1;
    while (i <= mid && j <= high) {
        comparisons++;
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        } else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    bool merged = false;
    display(c, 0, k);
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
        merged = true;
    }
//    display(c, 0, high);
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
        merged = true;
    }
    if (merged)
        if (low > 1 || k > length) display(c, 0, high);
        else display(c, 0, high);

    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}


void merge_sort(int *arr, int low, int high, int length) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid, length);
        merge_sort(arr, mid + 1, high, length);
        merge(arr, low, high, mid, length);
    }

}

void mergeFiles(char *outputFile, int size) {
    FILE *in[2];
    for (int i = 0; i < 2; i++) {
        stringstream fileName;
        fileName << "/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/lab2.5/" << i << ".txt";


        in[i] = fopen(fileName.str().c_str(), "r");
    }

    FILE *out = fopen(outputFile, "a");
    fprintf(out, "\n");
    MinHeapNode *harr = new MinHeapNode[2];
    int i;
    for (i = 0; i < 2; i++) {
        if (fscanf(in[i], "%d ", &harr[i].element) != 1) {
            break;
        }
        harr[i].i = i;
    }

    MinHeap hp(harr, i);

    int count = 0;

    while (count != i) {
        MinHeapNode root = hp.getMin();
        fprintf(out, "%d ", root.element);
        if (fscanf(in[root.i], "%d ",
                   &root.element)
            != 1) {
            root.element = INT_MAX;
            count++;
        }

        hp.replaceMin(root);
    }


    for (i = 0; i < 2; i++)
        fclose(in[i]);

    fclose(out);
}

void createInitialRuns(char *inputFile, int size) {
    FILE *in = fopen(inputFile, "r");
    FILE *out[2];
    for (int i = 0; i < 2; i++) {
        stringstream fileName;
        fileName << "/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/lab2.5/" << i << ".txt";


        out[i] = fopen(fileName.str().c_str(), "w");
    }


    int *arr = (int *) malloc(
            size * sizeof(int));

    bool more_input = true;
    int next_output_file = 0;

    int i;
    while (more_input) {
        for (i = 0; i < size; i++) {
            if (fscanf(in, "%d ", &arr[i]) != 1) {
                more_input = false;
                break;
            }
        }

        merge_sort(arr, 0, i - 1, size);

        for (int j = 0; j < i; j++)
            fprintf(out[next_output_file],
                    "%d ", arr[j]);

        next_output_file++;
    }

    for (i = 0; i < 2; i++)
        fclose(out[i]);

    fclose(in);
}

void externalSort(char *inputFile, int size) {
    createInitialRuns(inputFile, size);
    mergeFiles(inputFile, size);
}


int main() {
    cout << "input length: ";
    int length;
    cin >> length;

    char input_file[] = "/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/lab2.5/input.txt";

    FILE *in = fopen(input_file, "w");

    srand(time(NULL));

    // generate input
    for (int i = 0; i < length; i++)
        fprintf(in, "%d ", rand() % 100 - 50);

    fclose(in);

    externalSort(input_file, length);

    return 0;
}

