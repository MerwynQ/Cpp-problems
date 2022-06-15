#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.reserve(50);

  for (int i = 0; i < 50; ++i) {
    v.push_back(i);
  }

  for (int i = v.size() - 1; i >= 0; --i) {
    std::cout << i << ": " << v[i] << std::endl;
  }
  return 0;
}

/*in the initial program, the auto keyword sets the loop iterators to be unsigned longs, hence there's no output.
After changing it to an int, the desired behaviour of obtaining numbers 50 to 1 for positions 50 to 1 in the vector
is observed. This is because unsigned variables can only have positive values, and after reaching zero, it won't stop
 at a negative value being less than zero, at which point it should stop, because what comes after zero is again
 positive values and therefore it will go on indefinitely, away from zero and never fulfilling that condition.*/