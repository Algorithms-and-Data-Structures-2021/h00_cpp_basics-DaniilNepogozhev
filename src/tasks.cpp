#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;
using std::endl;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs&&rhs){
        int c = *lhs;
        *lhs = *rhs;
        *rhs = c;
    }


}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_cols>0&&num_rows>0){
        int **arr = new int *[num_rows];
        for (int row = 0;   row < num_rows; ++row){
            arr[row] = new int[num_cols];
        }
        for (int row = 0; row < num_rows; row++) {
            for (int column = 0; column < num_cols; column++){
                arr[row][column] = init_value;
            }
        }
        return arr;
    } else return nullptr;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (num_cols>0 && num_rows>0 && arr_2d_source && arr_2d_target) {
        for (int row = 0; row < num_rows; row++) {
            int *pointer_source = arr_2d_source[row];
            int *pointer_target = arr_2d_target[row];
            copy(pointer_source, pointer_source + num_cols, pointer_target);
        }
        return true;
    }
    return false;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    int len = arr.size();
    if (len) {
        for (int i = 0; i < len / 2; i++) {
            int mem = arr[i];
            arr[i] = arr[len - i - 1];
            arr[len - i - 1] = mem;
        }
    } else return;
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin && arr_end) {
        int len = arr_end - arr_begin +1;
        for (int i = 0; i < len / 2; i++) {
            int mem = *arr_begin;
            int mem_2 = *arr_end;
            *arr_begin = mem_2;
            *arr_end = mem;
            arr_begin += 1;
            arr_end -= 1;
        }
    } else return;
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if (size > 0 && arr){
        int *max_pointer = arr;
        int *elem_pointer = arr;
        for (int i = 0; i<size; i++){
            if (*max_pointer < *elem_pointer){
                max_pointer = elem_pointer;
            }
            elem_pointer += 1;
        }
        return max_pointer;
    } else return nullptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    int len = arr.size();
    vector<int> odd_array;
    if (len) {
        for (int i = 0; i < len; i++) {
            if (arr[i] % 2 != 0) {
                odd_array.push_back(arr[i]);
            }
        }
    }
    return odd_array;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    int len_1 = arr_a.size();
    int len_2 = arr_b.size();
    vector<int> common;
    if (len_1 && len_2){
        for (int i = 0; i<len_1; i++){
            for (int j = 0; j<len_2; j++){
                if(arr_a[i]==arr_b[j]){
                    common.push_back(arr_a[i]);
                    break;
                }
            }
        }
    }return common;
}
