
import random

def create_arr(length, mode='r'):
    arr = list()
    if mode == 'r':
        arr = [random.randint(-30, 30) for i in range(length)]
        print([i for i in arr])
    elif mode == 'i':
        arr = map(int, input('Input array: ').split(''))[:length]
    else: 
        return 
    return arr

def search_max_element(arr):
    max_el = int()
    for i in range(1, len(arr), 2): 
        if arr[i] > max_el: max_el = arr[i]
    return max_el, arr.index(max_el)

def search_min_element(arr):
    min_el = int()
    for i in range(2, len(arr), 2):
        if arr[i] < min_el: min_el = arr[i]
    return min_el, arr.index(min_el)
    

def main():
    length = int(input('Input length of array: '))
    option = input('Input option for creating array (i/r): ')
    arr = create_arr(length, option)
    max_el = search_max_element(arr)
    min_el = search_min_element(arr)

    print('max index: {}, max value: {}'.format(max_el[1], max_el[0]))
    print('min index: {}, min value: {}'.format(min_el[1], min_el[0]))
    arr[max_el[1]], arr[min_el[1]] = arr[min_el[1]], arr[max_el[1]]
    print(arr)

if __name__ == '__main__':
    main()
