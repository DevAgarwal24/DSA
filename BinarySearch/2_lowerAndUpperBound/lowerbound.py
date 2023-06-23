def lowerBoundIterative(searchSpace, number):
    if not isinstance(searchSpace, list):
        print("Incorrect type for search space")
        return -1

    low = 0
    high = len(searchSpace) - 1
    lb = len(searchSpace)

    while (low <= high):
        mid = int(low + (high - low)/2)

        if searchSpace[mid] >= number:
            high = mid - 1
            lb = mid
        else:
            low = mid + 1

    return lb

def main():
    searchSpace = [1, 2, 3, 3, 5, 8, 8, 10, 10, 11]

    print(f"{lowerBoundIterative(searchSpace, 0)}")
    print(f"{lowerBoundIterative(searchSpace, 9)}")
    print(f"{lowerBoundIterative(searchSpace, 12)}")
    print(f"{lowerBoundIterative(searchSpace, 8)}")

if __name__ == '__main__':
    main()