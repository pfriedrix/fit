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

    int getPerimetеr() const {
        return ab + ad + bc + dc;
    }

    void display() const {
        printf("%d %d %d %d", ab, ab, bc, dc);
    }
};

class Hash {
private:

    int arr[1000]{};

    int getHash(int key) {
        const int n = 13;
        const double a = 0.6180339887;
        return n * fmod(key * a, 1);
    }

public:
    void insert(Trapezoid *instance) {
        int key = instance->getSquare();
        if (arr[key] == 0) {
            arr[key] = getHash(key);
        } else cout << "It's gonna be collision" << endl;
    }

    void display() {
        for (int value: arr) {
            if (value != 0) {
                cout << value << " ";
            }
        }
    }
};

int main() {
    Trapezoid *instance = new Trapezoid();
    Hash hashtable;
    hashtable.insert(instance);
    hashtable.insert(instance);

    hashtable.display();
}
