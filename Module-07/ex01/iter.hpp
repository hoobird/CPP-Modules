#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename U>
void iter(T *arr, int len, U fn) {
    if (!arr || len <= 0 || !fn) 
        return;

    for (int i = 0; i < len; i++) {
        fn(arr[i]);
    }
}

#endif