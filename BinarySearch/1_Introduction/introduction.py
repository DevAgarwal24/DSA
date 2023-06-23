def BinarySearchIterative(searchSpace, number):
    if not isinstance(searchSpace, list):
        print("Incorrect type for the search space")
        return -1

    low = 0
    high = len(searchSpace) - 1

    while (low <= high):
        mid = int(low + (high - low)/2)

        if (searchSpace[mid] == number):
            return mid
        elif (searchSpace[mid] > number):
            high = mid - 1
        else:
            low = mid + 1

    return -1

def BinarySearchRecursive(searchSpace, low, high, number):

    if (low > high):
        return -1

    mid = int(low + (high - low)/2)

    if (searchSpace[mid] == number):
        return mid
    elif (searchSpace[mid] > number):
        return BinarySearchRecursive(searchSpace, low, mid-1, number)
    else:
        return BinarySearchRecursive(searchSpace, mid+1, high, number)

def main():
    searchSpace = [3, 4, 6, 7, 9, 12, 16, 17]

    for i in range(len(searchSpace)):
        print(f"{BinarySearchIterative(searchSpace, searchSpace[i])} {BinarySearchRecursive(searchSpace, 0, len(searchSpace)-1, searchSpace[i])}")

    print(f"{BinarySearchIterative(searchSpace, 32)} {BinarySearchRecursive(searchSpace, 0, len(searchSpace)-1, 32)}")

if __name__ == '__main__':
    main()