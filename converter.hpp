#ifndef CONVERTER_HPP_
#define CONVERTER_HPP_
#include <vector>

namespace stat {
  // Converter from COO format to CSR
  auto converter_COO_to_CSR();
  // Converter from CSR format to COO
  auto converter_CSR_to_COO();
  }

#endif
