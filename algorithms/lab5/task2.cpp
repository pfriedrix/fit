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
        const int n = length;
        const double a = 0.6180339887;
        return n * fmod(key * a, 1);
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


int main() {
    Trapezoid *instance = new Trapezoid(point(4, 5), point(1, 0), point(-8, 10), point(4,
                                                                                       0));
    Trapezoid *instance2 = new Trapezoid(point(4, 8), point(1, 1), point(-8, 10), point(4,
                                                                                        0));
    Hash hashtable;
    hashtable.insert(instance);
    hashtable.insert(instance2);
    hashtable.insert(instance);


    hashtable.display();
}
