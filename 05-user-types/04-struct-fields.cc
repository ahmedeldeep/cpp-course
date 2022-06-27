
// Structures

struct Status {
  unsigned int TXE : 1;   // Transmit data register empty
  unsigned int TC : 1;    // Transmission complete
  unsigned int RXNE : 1;  // Read data register not empty
  unsigned int ERR : 3;   // Error
  unsigned int : 26;      // Reserved
};

struct Data {
  unsigned int DATA : 8;  // Data
  unsigned int : 24;      // Reserved
};

struct Uart {
  Status SR;  // Status register
  Data DR;    // Data register
};

int main() {}