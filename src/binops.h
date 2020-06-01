#ifndef BIN_OPERATIONS_H
#define BIN_OPERATIONS_H


#include <bin.h>
#include <executable.h>

#include <string>
#include <vector>
#include <memory>
#include <stdint.h>


/*
 * Procedure to check for file format, architecture, and system of a given file
 * Return binary content of file
 */
std::vector<uint8_t> CheckABI(const std::string&, int*, int*, int*);

/*
 * Procedure to create a derived class from the given abi
 * Return a Bin pointer to the object
 */
template<typename FF, typename ARCH, typename SYS>
std::unique_ptr<Bin> CreateExecutable(const std::vector<uint8_t>& content){
	return std::make_unique<Executable<FF, ARCH, SYS>>(content);
}


#endif
