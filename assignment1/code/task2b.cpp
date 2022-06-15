#include <iostream>
#include <vector>

unsigned int get_max(unsigned int a, unsigned int b) {
  unsigned int c = a > b ? a : b; // if a is greater than b, c = a, otherwise b
  return c;
}

int main() {
  std::vector<unsigned int> v(10000, 0);
  v[9999] = 1000u;

      auto max = 0u;
  for(auto e : v){
    max = get_max(max, e);
  }
  std::cout << "Maximum: " << max << std::endl;
  return 0;
}

/* Debugging shows that a segmentation fault occurs at line 15 that results in EOP
    upon further examination we can understand it is a memory problem owing to the ampersand operator next to the
    get_max function return type. So basically as a reference, it dies after the function is called, returning
    nothing to the callee resulting in undesirable behaviour. Deleting that gives an output of 1000*/