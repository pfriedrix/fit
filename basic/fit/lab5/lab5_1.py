
def fibonacci(n):
    if n == 0 or n==1:
        return 1
    else:
        return fibonacci(n-1)+fibonacci(n-2)
        
        

def main():
    m, n = map(int, input().split())
    if m < n:
        print("m should be more than n")
        return
    print("Fibonacci row: ", end="")
    for i in range(m):
        print(fibonacci(i), end=" ")
    print("Fibonacci(N): {}".format(fibonacci(n-1)))
