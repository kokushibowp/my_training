#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Menu.h"

#define RANGE 100
#define ARRSIZE 100

int SELECTED;

bool menuproc(Menu* menu);
bool is_ascendingproc(Menu* isAscending);

void bubble_sorting(int* arr, int arrsize, bool isAscending);                    // Worst - O(n^2),     Average - O(n^2),     Best - O(n),       Space - O(1) 
void double_bubble_sorting(int* arr, int arrsize, bool isAscending);             // Worst - O(n^2),     Average - O(n^2),     Best - O(n),       Space - O(1) 
void selection_sorting(int* arr, int arrsize, bool isAscending);                 // Worst - O(n^2),     Average - O(n^2),     Best - O(n^2),     Space - O(1)
void insertion_sorting(int* arr, int arrsize, bool isAscending);                 // Worst - O(n^2),     Average - O(n^2),     Best - O(n),       Space - O(1) 
void counting_sorting(int* arr, int arrsize, bool isAscending);                  // Worst - O(n),       Average - O(n),       Best - O(n),       Space - O(RANGE)
void quick_sorting(int* arr, int start, int end, bool isAscending);              // Worst - O(n^2),     Average - O(n*log n), Best - O(n*log n), Space - O(1)
void merge_sorting(int* arr, int arrsize, int start, int end, bool isAscending); // Worst - O(n*log n), Average - O(n*log n), Best - O(n*log n), Space - O(n)      (not certified)
void shell_sorting(int* arr, int arrsize, bool isAscending);                     // Worst - O(n^2),     Average - O(n*log n), Best - O(n*log n), Space - O(1)
void heap_sorting(int* arr, int arrsize, bool isAscending);                      // Worst - O(n*log n), Average - O(n*log n), Best - O(n*log n), Space - O(1)

int* create_an_array(int range);

void print_arr(int* arr, int arrsize);
void write_arr(int* arr, int arrsize);
void clear_file(char* filename);

int main()
{
    system("chcp 1251 > 0");
    COORD xy = {2, 1};
    Menu menu(xy);

    menu.add_item((char*)"Сортировка пузырьком");
    menu.add_item((char*)"Шейкерная сортировка");
    menu.add_item((char*)"Сортировка выбором");
    menu.add_item((char*)"Сортировка вставками");
    menu.add_item((char*)"Сортировка методом подсчета");
    menu.add_item((char*)"Быстрая сортировка");
    menu.add_item((char*)"Сортировка слиянием");
    menu.add_item((char*)"Сортировка Шелла");
    menu.add_item((char*)"Сортировка кучей");
    
    menu.set_color(0x03, 0x2F);
    menu.draw_menu();
    
    menu.menu_processor(&menuproc);
 }

bool menuproc(Menu* menu) {
    menu->clear_screen();
    
    COORD xy = { 2, 1 };
    Menu isAscending(xy);
    isAscending.add_item((char*)"Сортировать по возрастанию");
    isAscending.add_item((char*)"Сортировать по убыванию");
    
    int* arr;
    switch (menu->get_cursor_pos()) {
    case 1:
        SELECTED = 1;
        break;
    case 2:
        SELECTED = 2;
        break;
    case 3:
        SELECTED = 3;
        break;
    case 4:
        SELECTED = 4;
        break;
    case 5:
        SELECTED = 5;
        break;
    case 6:
        SELECTED = 6;
        break;
    case 7:
        SELECTED = 7;
        break;
    case 8:
        SELECTED = 8;
        break;
    case 9:
        SELECTED = 9;
        break;
    }
    isAscending.draw_menu();
    Sleep(150);
    isAscending.menu_processor(&is_ascendingproc);
    menu->draw_menu();
    menu->set_cursor(menu->get_cursor_pos());
    return true;
}

bool is_ascendingproc(Menu* isAscending) {
    isAscending->clear_screen();

    int* arr;
    switch (isAscending->get_cursor_pos()) {
    case 1:
        switch (SELECTED) {
        case 1:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            bubble_sorting(arr, ARRSIZE, 1);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 2:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            double_bubble_sorting(arr, ARRSIZE, 1);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 3:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            selection_sorting(arr, ARRSIZE, 1);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 4:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            insertion_sorting(arr, ARRSIZE, 1);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 5:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            counting_sorting(arr, ARRSIZE, 1);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 6:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            quick_sorting(arr, 0, 99, 1);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 7:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            merge_sorting(arr, ARRSIZE, 0, 99, 1);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 8:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            shell_sorting(arr, ARRSIZE, 1);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 9:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            heap_sorting(arr, ARRSIZE, 1);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        }
        break;
    case 2:
        switch (SELECTED) {
        case 1:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            bubble_sorting(arr, ARRSIZE, 0);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 2:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            double_bubble_sorting(arr, ARRSIZE, 0);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 3:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            selection_sorting(arr, ARRSIZE, 0);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 4:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            insertion_sorting(arr, ARRSIZE, 0);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 5:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            counting_sorting(arr, ARRSIZE, 0);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 6:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            quick_sorting(arr, 0, 99, 0);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 7:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            merge_sorting(arr, ARRSIZE, 0, 99, 0);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 8:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            shell_sorting(arr, ARRSIZE, 0);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        case 9:
            arr = create_an_array(ARRSIZE);
            clear_file((char*)"random array.txt");
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            heap_sorting(arr, ARRSIZE, 0);
            print_arr(arr, ARRSIZE);
            write_arr(arr, ARRSIZE);
            break;
        }
        break;
    }
    system("PAUSE");
    system("CLS");
    return false;
}

void bubble_sorting(int* arr, int arrsize, bool isAscending) {
    bool was_swapped;
    if(isAscending){
        for (int i = 0; i < arrsize; ++i) {
            
            was_swapped = false;

            for (int j = 0; j < arrsize - i; ++j) {
                if (arr[j] > arr[j+1]) {

                    arr[j]     = arr[j] + arr[j + 1];
                    arr[j + 1] = arr[j] - arr[j + 1];
                    arr[j]     = arr[j] - arr[j + 1];
                    
                    was_swapped = true;
                }
            }
            
            if (was_swapped == false) break;

        }
    }
    else {
        for (int i = 0; i < arrsize; ++i) {

            was_swapped = false;

            for (int j = 0; j < arrsize - i; ++j) {
                if (arr[j] < arr[j + 1]) {

                    arr[j]     = arr[j] + arr[j + 1];
                    arr[j + 1] = arr[j] - arr[j + 1];
                    arr[j]     = arr[j] - arr[j + 1];

                    was_swapped = true;
                }
            }

            if (was_swapped == false) break;

        }
    }
}

void double_bubble_sorting(int* arr, int arrsize, bool isAscending) {
    bool was_swapped;
    if (isAscending) {
        for (int i = 0; i < arrsize; ++i) {

            was_swapped = false;
            int j;
            for (j = 0; j < arrsize - i; ++j) {
                if (arr[j] > arr[j + 1]) {

                    arr[j]     = arr[j] + arr[j + 1];
                    arr[j + 1] = arr[j] - arr[j + 1];
                    arr[j]     = arr[j] - arr[j + 1];

                    was_swapped = true;
                }
            }

            if (was_swapped == false) break;

            for (j = j - 1; j > i; --j) {
                if (arr[j] < arr[j - 1]) {

                    arr[j]     = arr[j] + arr[j - 1];
                    arr[j - 1] = arr[j] - arr[j - 1];
                    arr[j]     = arr[j] - arr[j - 1];

                    was_swapped = true;
                }
            }

            if (was_swapped == false) break;

        } 
    }
    else {
        for (int i = 0; i < arrsize; ++i) {

            was_swapped = false;
            int j;
            for (j = 0; j < arrsize - i; ++j) {
                if (arr[j] < arr[j + 1]) {

                    arr[j] = arr[j] + arr[j + 1];
                    arr[j + 1] = arr[j] - arr[j + 1];
                    arr[j] = arr[j] - arr[j + 1];

                    was_swapped = true;
                }
            }

            if (was_swapped == false) break;

            for (j = j - 1; j > i; --j) {
                if (arr[j] > arr[j - 1]) {

                    arr[j] = arr[j] + arr[j - 1];
                    arr[j - 1] = arr[j] - arr[j - 1];
                    arr[j] = arr[j] - arr[j - 1];

                    was_swapped = true;
                }
            }

            if (was_swapped == false) break;
        }
    }
}

void selection_sorting(int* arr, int arrsize, bool isAscending) {
    int minOrMaxItem;
    int itemIndex;
    int save;
    
    if (isAscending) {
        for (int i = 0; i < arrsize; ++i) {
            minOrMaxItem = arr[i];
            itemIndex = i;
            for (int j = i; j < arrsize; ++j) {
                if (minOrMaxItem > arr[j]) {
                    minOrMaxItem = arr[j];
                    itemIndex = j;
                }
            }
            save = arr[i];
            arr[i] = arr[itemIndex];
            arr[itemIndex] = save;
        }
    }
    else {
        for (int i = 0; i < arrsize; ++i) {
            minOrMaxItem = arr[i];
            itemIndex = i;
            for (int j = i; j < arrsize; ++j) {
                if (minOrMaxItem < arr[j]) {
                    minOrMaxItem = arr[j];
                    itemIndex = j;
                }
            }
            save = arr[i];
            arr[i] = arr[itemIndex];
            arr[itemIndex] = save;
        }
    }
}

void insertion_sorting(int* arr, int arrsize, bool isAscending) {
    if (isAscending) {
        for (int i = 1; i < arrsize; ++i) {
            for (int j = i; (arr[j] < arr[j - 1]) && (j > 0); --j) {

                arr[j]     = arr[j] + arr[j - 1];
                arr[j - 1] = arr[j] - arr[j - 1];
                arr[j]     = arr[j] - arr[j - 1];

            }
        }
    }
    else {
        for (int i = 1; i < arrsize; ++i) {
            for (int j = i; (arr[j] > arr[j - 1]) && (j > 0); --j) {

                arr[j]     = arr[j] + arr[j - 1];
                arr[j - 1] = arr[j] - arr[j - 1];
                arr[j]     = arr[j] - arr[j - 1];

            }
        }
    }
}

void counting_sorting(int* arr, int arrsize, bool isAscending) {
    int counter[RANGE] = { 0 };
    for (int i = 0; i < arrsize; ++i) {
        ++counter[arr[i]];
    }
    memset(arr, 0, arrsize*sizeof(int));
    int arrIterator = 0;
    if (isAscending) {
        for (int i = 0; i < arrsize; ++i) {
            for (int j = 0; j < counter[i]; ++j) {
                arr[arrIterator++] = i;
            }
        }
    }
    else {
        for (int i = arrsize; i > 0; --i) {
            for (int j = 0; j < counter[i]; ++j) {
                arr[arrIterator++] = i;
            }
        }
    }
}

void quick_sorting(int* arr, int start, int end, bool isAscending) {
    if (start >= end) return;
    int current = start;
    int save = 0;
    
    if (isAscending) {
        for (int i = start + 1; i <= end; ++i) {
            if (arr[i] < arr[start]) {
                ++current;
                save = arr[i];
                arr[i] = arr[current];
                arr[current] = save;
            }
        }
    }
    else {
        for (int i = start + 1; i <= end; ++i) {
            if (arr[i] > arr[start]) {
                ++current;
                save = arr[i];
                arr[i] = arr[current];
                arr[current] = save;
            }
        }
    }
    save = arr[start];
    arr[start] = arr[current];
    arr[current] = save;

    if (current > start) {
        quick_sorting(arr, start, current - 1, isAscending);
    }
    if (current + 1 < end) {
        quick_sorting(arr, current + 1, end, isAscending);
    }
}

void merge_sorting(int* arr, int arrsize, int start, int end, bool isAscending) {
    if (start >= end)return;
    int mid = (start + end) / 2;
    merge_sorting(arr, arrsize, start, mid, isAscending);
    merge_sorting(arr, arrsize, mid+1, end, isAscending);
    int i = start, j = mid + 1, k = start;
    int* mergedList = new int[arrsize];

    if (isAscending) {
        while (i <= mid && j <= end) {
            if (arr[i] < arr[j]) {
                mergedList[k] = arr[i];
                ++i;
                ++k;
            }
            else {
                mergedList[k] = arr[j];
                ++j;
                ++k;
            }
        }

        while (i <= mid) {
            mergedList[k] = arr[i];
            ++i;
            ++k;
        }

        while (j <= end) {
            mergedList[k] = arr[j];
            ++j;
            ++k;
        }

        for (i = start; i < k; ++i) {
            arr[i] = mergedList[i];
        }
    }
    else {
        while (i <= mid && j <= end) {
            if (arr[i] > arr[j]) {
                mergedList[k] = arr[i];
                ++i;
                ++k;
            }
            else {
                mergedList[k] = arr[j];
                ++j;
                ++k;
            }
        }

        while (i <= mid) {
            mergedList[k] = arr[i];
            ++i;
            ++k;
        }

        while (j <= end) {
            mergedList[k] = arr[j];
            ++j;
            ++k;
        }

        for (i = start; i < k; ++i) {
            arr[i] = mergedList[i];
        }
    }

    delete[] mergedList;
    mergedList = 0;
}

void shell_sorting(int* arr, int arrsize, bool isAscending) {
    if (isAscending) {
        for (int step = arrsize / 2; step > 0; step /= 2) {
            
            for (int i = step; i < arrsize; ++i) {
                
                int j = i;
                while (j >= step && arr[j - step] > arr[j]) {
                    
                    int save      = arr[j];
                    arr[j]        = arr[j - step];
                    arr[j - step] = save;
                    j -= step;

                }

            }

        }
    }
    else {
        for (int step = arrsize / 2; step > 0; step /= 2) {

            for (int i = step; i < arrsize; ++i) {

                int j = i;
                while (j >= step && arr[j - step] < arr[j]) {

                    int save = arr[j];
                    arr[j] = arr[j - step];
                    arr[j - step] = save;
                    j -= step;

                }

            }

        }
    }
}







void heapify(int* arr, int arrsize, int root, bool isAscending);

void heap_sorting(int* arr, int arrsize, bool isAscending) {
    for (int i = arrsize / 2 - 1; i >= 0; --i) {
        heapify(arr, arrsize, i, isAscending);
    }
    for (int i = arrsize - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, isAscending);
    }
}

void heapify(int* arr, int arrsize, int root, bool isAscending) {
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    
    if (isAscending) {
        if (l < arrsize && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < arrsize && arr[r] > arr[largest]) {
            largest = r;
        }
    }
    else {
        if (l < arrsize && arr[l] < arr[largest]) {
            largest = l;
        }
        if (r < arrsize && arr[r] < arr[largest]) {
            largest = r;
        }
    }

    if (largest != root) {
        int save = arr[root];
        arr[root] = arr[largest];
        arr[largest] = save;
        heapify(arr, arrsize, largest, isAscending);
    }
}






int* create_an_array(int range) {
    srand(time(0));
    static int a[100] = { 0 };
    for (int i = 0; i < 100; ++i) {
        a[i] = rand() % range;
    }
    return a;
}

void print_arr(int* arr, int arrsize) {
    for (int i = 0; i < arrsize; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n\n";
}

void write_arr(int* arr, int arrsize) {
    std::ofstream out("random array.txt", std::ios::app);
    for (int i = 0; i < arrsize; ++i) {
        if (out.is_open()) {
            out << arr[i] << ' ';
        }
    }
    out << "\n\n";
}

void clear_file(char* filename) {
    std::ofstream out;
    out.open(filename);
    out.close();
}