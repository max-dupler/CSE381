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
    cout << "Usage: primesMT maxToCheck mode" << endl;
    return false;
  } else if (!(isInteger(argv[1]) && isInteger(argv[2]))) {
    cout << "Error: arguments must be integers" << endl;
    return false;
  } else {
    return true;
  }
}

int serialPrimes(int maxCheck) {
  int primes = 0;
  for (int i = 0; i < maxCheck; i++) {
    if (isPrime(i)) {
      primes++;
    }
  }
  return primes;
}

int inefficientPrimes(int maxCheck) {
  
}

int main(int argc, char *argv[]) {
  // check CLA
  if (!checkArguments(argc, argv)) {
    return 0;
  }

  int numPrimes = serialPrimes(std::stoi(argv[1]));

  cout << numPrimes << endl;

  exit(0);
}
