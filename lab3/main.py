import algos

def main():
    arr = [int(el) for el in input().split()]
    print(arr)
    arr = algos.quick(arr)
    print(arr)


if __name__ == "__main__":
    main()