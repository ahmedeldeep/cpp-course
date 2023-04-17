
#ifndef __INTERFACE_V3_H_
#define __INTERFACE_V3_H_

// interface-v3.h
namespace Interface_V3 {
void print_new(void) {
  std::cout << "print new v3"
            << "\n";
}
#include "interface-v2.h"
using Interface_V2::print;
}  // namespace Interface_V3

#endif