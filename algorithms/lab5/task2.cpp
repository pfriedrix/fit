#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::get; using std::vector;

typedef std::tuple<int, int> point;

class Trapezoid {
private:
    int ab, ad, bc, dc, h;

    static int getLength(point a, point b) {
        return sqrt(pow((get<0>(b) - get<0>(a)), 2) + pow(get<1>(b) - get<1>(a), 2));
    }

public:
    Trapezoid(point a, point b, point c, point d) {
        ab = getLength(a, b);
        ad = getLength(a, d);
        bc = getLength(b, c);
        dc = getLength(d, c);
        h = fabs(get<1>(a) - get<1>(d));
    }

    Trapezoid() {
        srand((unsigned) (time(NULL)));
        auto a = point((rand() % 10 - 5), (rand() % 10 - 5));
        auto b = point((rand() % 10 - 5), (rand() % 10 - 5));
        auto c = point((rand() % 10 - 5), (rand() % 10 - 5));
        auto d = point((rand() % 10 - 5), (rand() % 10 - 5));
        ab = getLength(a, b);
        ad = getLength(a, d);
        bc = getLength(b, c);
        dc = getLength(d, c);
        h = fabs(get<1>(a) - get<1>(d));
    }


    double getSquare() const {
        return (double) (ab + dc) / 2 * h;
    }

    int getPerimeter() {
        return ab + ad + bc + dc;
    }

    void display() const {
        printf("%d %d %d %d", ab, ab, bc, dc);
    }
};

class Hash {
private:

    static const int length = 1000;
    double arr[length]{};

    static int getHash(int key) {
        const int m = 7;
        const double a = 0.5;
        return m * fmod(key * a, 1);
    }

public:
    void insert(Trapezoid *instance) {
        double square = instance->getSquare();
        int key = getHash(square);
        if (arr[key] == 0) {
            arr[key] = square;
        } else {
            double value = arr[key];
            int counter = 0;
            while (value != 0) {
                counter++;
                value = arr[key + counter];
            }
            arr[key + counter] = square;
        }
    }

    void display() {
        for (int i = 0; i < 1000; i++) {
            if (arr[i] != 0) {
                cout << "#" << i << " " << arr[i] << " ";
                cout << endl;
            }
        }
    }
};

int *countMatrix(int size, int *ptr) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> *(ptr + i * size + j);
        }

    }
    cout << "Your matrix is" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << *(ptr + i * size + j) << " ";
        }
        cout << endl;

    }
    int m[]{0, 1};
    return m;
}


int main() {
//    Trapezoid *instance = new Trapezoid(point(0, 0), point(0, 1), point(1, 0), point(7,
//                                                                                     8));
//    Trapezoid *instance2 = new Trapezoid(point(0, -2), point(0, 0), point(-2, 4), point(5,
//                                                                                        6));
//    Trapezoid *instance3 = new Trapezoid(point(1, 1), point(2, 2), point(-3, 3), point(6,
//                                                                                       7));
//    Trapezoid *instance4 = new Trapezoid(point(-1, 1), point(-2, 2), point(3, 1), point(4,
//                                                                                        5));
//    Hash hashtable;
//    hashtable.insert(instance);
//    hashtable.insert(instance2);
//    hashtable.insert(instance3);
//    hashtable.insert(instance4);
//
//
//    hashtable.display();s
    cout << "input your point" << endl;
    int x;
    std::cin >> x;
    if (x < 2 || x > 50) {
        cout << "try again" << endl;
        main();
    }
    int arr[x][x];
    int *ptr = countMatrix(x, *arr);
    cout << *ptr;
    cout << endl;
    cout << *(ptr + 1);
}



