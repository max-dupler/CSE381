// Copyright 2024 <Max Dupler>
#include <iostream>

using std::cout;
using std::endl;

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

int main(int argc, char *argv[]) {
  if (!checkArguments(argc, argv)) {
    return 0;
  }
  exit(0);
}
