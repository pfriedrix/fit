#include <iostream>
#include <string>
#include <vector>

using namespace std;

void make_table(int d[], string q) {
    int M = q.length();
    for (int i = 0; i < 256; i++) {
        d[i] = M;
    }
    for (int i = 0; i < M - 1; i++) {
        d[q[i]] = M - i - 1;
    }
}


void seek_substring_BM(string s, string q) {
    int d[256];
    int i = 0, j, k, N, M, count{};
    N = s.length();
    M = q.length();

    make_table(d, q);

    int id{};
    for (int j = 0; j < M - 1; j++) {
        if (j != i && q[i] == q[j]) {
            for (int f = 0; f < M; f++) {
                if (q[j] == q[f] && f > j) {
                    id = i;
                }
            }
            d[q[j]] = M - id - 1;
            cout << d[q[i]] << " ";
        } else {
            cout << d[q[i]] << " ";
            i++;
        }
    }
    cout << "0";
    i = M - 1;
    for (i = M - 1; i < N; i += d[(unsigned) s[i]]) {
        j = M - 1;
        k = i;
        cout << "\n" << q[j] << "\t" << s[k];
        while ((j >= 0) && (q[j] == s[k])) {
            cout << "\n" << q[j] << "\t" << s[k];
            k--;
            j--;
            count++;

        }
        if (j < 0) {
            cout << "\nPattern found on: " << k + 1 << endl;
        }
    }
    cout << "\nNumber of compares: " << count << "\n";


    cout << "Array d: ";
    for (int el : d) cout << el << " ";
}

int main() {
    cout << "input line:" << endl;
    string full;
    getline(cin, full);
    cout << "input pattern:" << endl;
    string part;
    getline(cin, part);
    seek_substring_BM(full, part);
}
