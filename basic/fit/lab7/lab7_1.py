import random

def main():
    while (True):
        size = list(map(int, input('Enter rows and cols for matrix: ').split()))
        if size[0] >= 3 and size[1] >= 3:
            break

    option = input('Input option for creating matrix (i/r): ')
    matrix = []
    for i in range(size[0]):
        if option == 'i':
            matrix.append(int(input('')))
        elif option == 'r':
            rand = [random.randint(-50, 50) for i in range(size[1])]
            matrix.append(rand)
    print(matrix)
    

if __name__ == "__main__":
    main()