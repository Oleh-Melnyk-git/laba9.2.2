#include <iostream>
#include <vector>
using namespace std;
#define SWAP(a, b) do { auto _t = (a); (a) = (b); (b) = _t; } while(0)
#define LESS(a, b) ((a) < (b))
#define PRINT_ARRAY(vec) do { \
    for (size_t _i = 0; _i < (vec).size(); ++_i) cout << (vec)[_i] << " "; \
    cout << endl; \
} while(0)

#define PUSH_ALL(vec, ...) do { \
    int _tmp[] = { __VA_ARGS__ }; \
    for (size_t _i = 0; _i < sizeof(_tmp)/sizeof(_tmp[0]); ++_i) (vec).push_back(_tmp[_i]); \
} while(0)


void quickSort(vector<int>& v, int low, int high) {
    if (low < high) {
        int pivot = v[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (LESS(v[j], pivot)) {
                ++i;
                SWAP(v[i], v[j]);
            }
        }
        SWAP(v[i + 1], v[high]);
        int pi = i + 1;
        quickSort(v, low,     pi - 1);
        quickSort(v, pi + 1,  high);
    }
}

int main() {
    vector<int> v;


    int n;
    cout << "Введіть кількість чисел: ";
    cin >> n;
    v.resize(n);
    cout << "Введіть числа: ";
    for (int i = 0; i < n; ++i) cin >> v[i];

   

    if (!v.empty())
        quickSort(v, 0, (int)v.size() - 1);

    cout << "Відсортовані числа: ";
    PRINT_ARRAY(v);
    return 0;
}
