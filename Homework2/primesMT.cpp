// Copyright 2024 <Max Dupler>
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

bool isPrime(int n) {
  // 2 is the smallest prime number
  if (n < 2) return false;
  if (n == 2) return true;

  for (int j = 2; j < n; j++) {
    if ( (n % j) == 0)
      return false;
  }
  return true;
}

bool isInteger(const std::string &s) {
    try {
        std::stoi(s);
        return true;
    } catch (...) {
        return false;
    }
}

// Checks CLA and returns based on correct or incorrect usage
bool checkArguments(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Usage:  primesMT maxToCheck mode" << endl;
    return false;
  } else if (!(isInteger(argv[1]) && isInteger(argv[2]))) {
    cout << "Error: arguments must be integers" << endl;
    return false;
  } else {
    return true;
  }
}

void serialPrimes(int maxCheck, int* numPrimes) {
  for (int i = 0; i < maxCheck; i++) {
    if (isPrime(i)) {
      (*numPrimes)++;
    }
  }
}

void checkPairPrimes(int num1, int num2, int* numPrimes) {
  if (isPrime(num1)) (*numPrimes)++;
  if (isPrime(num2)) (*numPrimes)++;
}

void inefficientPrimes(int maxCheck, int* numPrimes) {
  cout << "starting inefficient prime check" << endl;
  for (int i = 0; i < maxCheck; i += 4) {
    int numPrimes2 = 0;
    thread pair1(checkPairPrimes, i, i + 1, numPrimes);
    thread pair2(checkPairPrimes, i + 2, i + 3, &numPrimes2);
    pair1.join();
    pair2.join();
    (*numPrimes) += numPrimes2;
  }
}
void checkEfficientPrimes(int maxCheck, int num1, int num2, int* numPrimes) {
  while (num1 < maxCheck && num2 <= maxCheck) {
    if (isPrime(num1)) (*numPrimes)++;
    if (isPrime(num2)) (*numPrimes)++;
    num1 += 4;
    num2 += 4;
  }
}

void efficientPrimes(int maxCheck, int* numPrimes) {
  int numPrimes2 = 0;
  thread pair1(checkEfficientPrimes, maxCheck, 0, 1, numPrimes);
  thread pair2(checkEfficientPrimes, maxCheck, 2, 3, &numPrimes2);
  pair1.join();
  pair2.join();
  *numPrimes += numPrimes2;
}

int main(int argc, char *argv[]) {
  // check CLA
  if (!checkArguments(argc, argv)) {
    return 0;
  }

  int numPrimes = 0;

  switch (std::stoi(argv[2])) {
    case 0:
      serialPrimes(std::stoi(argv[1]), &numPrimes);
      break;
    case 1:
      inefficientPrimes(std::stoi(argv[1]), &numPrimes);
      break;
    case 2:
      efficientPrimes(std::stoi(argv[1]), &numPrimes);
      break;
  }


  cout << "Found " << numPrimes << " prime numbers < "
    << std::stoi(argv[1]) << endl;

  exit(0);
}
