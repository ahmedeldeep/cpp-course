
// Enumerations
// Reference: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>

enum class StatusFlags {
  data_received = 0x1,
  rx_buffer_full = 0x2,
  rx_error = 0x4,
  data_transmitted = 0x8,
  tx_buffer_empty = 0x10,
  tx_error = 0x20,
};

constexpr StatusFlags operator|(StatusFlags a, StatusFlags b) {
  return static_cast<StatusFlags>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr StatusFlags operator&(StatusFlags a, StatusFlags b) {
  return static_cast<StatusFlags>(static_cast<int>(a) & static_cast<int>(b));
}

void check_status_flags(StatusFlags status) {
  StatusFlags ready_to_read{StatusFlags::data_received |
                            StatusFlags::rx_buffer_full};
  if ((status & ready_to_read) == ready_to_read) {
    std::cout << "Read Data" << std::endl;
  }

  StatusFlags ready_to_write{StatusFlags::data_transmitted |
                             StatusFlags::tx_buffer_empty};
  if ((status & ready_to_write) == ready_to_write) {
    std::cout << "Write Data" << std::endl;
  }

  StatusFlags any_error{StatusFlags::rx_error | StatusFlags::tx_error};
  StatusFlags no_error{static_cast<StatusFlags>(0)};
  if ((status & any_error) != no_error) {
    std::cout << "RX and/or TX Error" << std::endl;
  }
}

int main() {
  //
  StatusFlags status{static_cast<StatusFlags>(0x3F)};
  check_status_flags(status);

  std::cout << (StatusFlags::rx_error < StatusFlags::tx_error) << std::endl;
}