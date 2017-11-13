#include <iostream>
#include <sstream>

using namespace std;

bool input(float * &elements, int num)
{
    string str;
    int excess_el;

    getline(cin, str);

    float *tmp_elements = new float [num];

    for (string str; getline(cin, str); ) {
        istringstream stream(str);
        for (unsigned int j = 0; j < num; ++j) {
            if(!(stream >> tmp_elements[j])) {
                return false;
            }
        }
        if(stream >> excess_el) return false;
        break;
    }
    elements = tmp_elements;
    return true;
}

void qsort(float *elements, int left, int right)
{
    int x, i = left, j = right;
    x = elements[(left+right)/2];

    do {
        while((elements[i] < x) && (i < right)) i++;
        while((x < elements[j]) && (j > left)) j--;

        if(i <= j) {
            swap(elements[i],elements[j]);
            i++; j--;
        }

    } while (i <= j);

    if(left < j) qsort(elements, left, j);
    if(i < right) qsort(elements, i, right);
}

int main() {
    float *elements;
    int num;

    if (!(cin >> num)|| (num <= 0))
    {
        cout << "An error has occured while reading input data.\n";
        return 0;
    }

    if (!(input(elements, num)))
    {
        cout << "An error has occured while reading input data.\n";
        return 0;
    }

    qsort(elements, 0, num-1);

    for (unsigned int i = 0; i < num; i++) cout << elements[i] << ' ';

    delete[] elements;
    return 0;
}
