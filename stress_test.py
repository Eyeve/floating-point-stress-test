from os import system
from sys import argv
from re import sub

N = 1000000
OPERATION = '*'

if (len(argv) > 1):
    OPERATION = argv[1]
    if (OPERATION != '*' and OPERATION != '/' and OPERATION != '+' and OPERATION != '-'):
        print(f"Invalid operation: {OPERATION}")
        exit(1)

system("clang main.c -o main.exe")
system("clang tester.c -o tester.exe")
open("out.txt", "w")

for testNumber in range(N):
    system(f"./tester.exe '{OPERATION}' > out.txt")

    with open("out.txt", "r") as f:
        test = f.readline().strip()
        expected = f.readline().strip()

    system(f"./main.exe {test} > out.txt")
    test = test.replace("'", "", 2)
    with open("out.txt", "r") as f:
        actual = f.readline().strip()
        
    if sub("0+p", "p", actual) != expected:
        print()
        print(f"=== test failed => | {testNumber}")
        print(f" \=== expected ==> | {expected}")
        print(f"  \== actual ====> | {actual}")
        input(f"   \= test case => | {test}\n")
    else:
        if (testNumber % 100 == 0):
            print(f"\n======= ONE HUNDRED MORE TESTS =======\n")
        elif (testNumber % 10 == 0):
            print("="*(testNumber%3) + f"===> test passed - {testNumber}")
    




    