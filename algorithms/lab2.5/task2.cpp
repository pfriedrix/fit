#include <iostream>
#include <sstream>
#include <valarray>

using namespace std;

int swaps = 0, comparisons = 0;

bool isEqual(int arr[], int temp[], int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] != temp[i]) return false;
    }
    return true;
}

void mergeFiles(char *outputFile, int size, int arr[]) {
    FILE *out = fopen(outputFile, "a");
    for (int i = 0; i < size; i++) {
        fprintf(out, "%d ", arr[i]);
    }
    fprintf(out, "\n");
    fclose(out);
}

void display(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void split(char *inputFile, int size, int starts[], int length_starts) {
    FILE *in = fopen(inputFile, "r");
    FILE *out[2];
    for (int i = 0; i < 2; i++) {
        stringstream fileName;
        fileName << "/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/lab2.5/" << i << ".txt";


        out[i] = fopen(fileName.str().c_str(), "w");
    }

    bool more_input = true;
    int next_output_file = 0;

    int *arr = (int *) malloc(
            size * sizeof(int));

    while (more_input) {
        for (int i = 0; i < size; i++) {
            if (fscanf(in, "%d ", &arr[i]) != 1) {
                more_input = false;
                break;
            }
        }

        for (int i = 0; i < length_starts - 1; i++) {
            if ((i + 1) % 2 == 0) {
                for (int j = starts[i]; j < starts[i + 1]; j++) {
                    fprintf(out[0], "%d ", arr[j]);
                }
            } else {
                for (int j = starts[i]; j < starts[i + 1]; j++) {
                    fprintf(out[1], "%d ", arr[j]);
                }
            }
        }
    }

    for (int i = 0; i < 2; i++)
        fclose(out[i]);

    fclose(in);
}

void merge(int source[], int target[], int startLeft, int startRight, int endRight) {
    int leftPos = startLeft;
    int rightPos = startRight;
    int targetPos = startLeft;
    while (leftPos < startRight && rightPos < endRight) {
        int leftValue = source[leftPos];
        int rightValue = source[rightPos];
        comparisons++;
        if (leftValue <= rightValue) {
            target[targetPos++] = leftValue;
            swaps++;
            leftPos++;
        } else {
            target[targetPos++] = rightValue;
            swaps++;
            rightPos++;
        }
    }
    while (leftPos < startRight) {
        target[targetPos++] = source[leftPos++];
        swaps++;
    }
    while (rightPos < endRight) {
        target[targetPos++] = source[rightPos++];
        swaps++;
    }
}

void mergeSort(int arr[], int length) {
    int temp[length];
    int starts[length];

    int j = 0;
    starts[0] = 0;
    for (int i = 1; i <= length; i++) {
        if (i == length || arr[i] < arr[i - 1]) {
            starts[++j] = i;
        }
    }
    char inputFile[] = "/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/lab2.5/input.txt";

    split(inputFile, length, starts, j);

    int *from = arr;
    int *to = temp;

    while (j > 1) {
        int newRunCount = 0;
        for (int i = 0; i < j - 1; i += 2) {
            merge(from, to, starts[i], starts[i + 1], starts[i + 2]);
            starts[newRunCount++] = starts[i];
            split(inputFile, length, starts, j);
            mergeFiles(inputFile, length, to);
        }

        if (j % 2 == 1) {
            int lastStart = starts[j - 1];
            for (int i = lastStart; i < length - lastStart; i++) to[i] = from[i];
            starts[newRunCount++] = lastStart;
        }
        starts[newRunCount] = length;
        j = newRunCount;
        int *help = from;
        from = to;
        to = help;

        display(help, 0, length);
    }

    if (!isEqual(from, arr, length)) {
        for (int i = 0; i < length; i++) arr[i] = from[i];
    }
}


int main() {
    char input_file[] = "/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/lab2.5/input.txt";

    FILE *in = fopen(input_file, "w");
    cout << "input length: ";
    int length;
    cin >> length;
    int arr[length];
    srand(time(nullptr));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100 - 50;
        fprintf(in, "%d ", arr[i]);
    }
    fclose(in);
    display(arr, 0, length);
    mergeSort(arr, length);
    for (int i = 0; i < length; i++) cout << arr[i] << " ";
    cout << endl;
}