#ifndef BITS_H
#define BITS_H

template<typename T>
T ToIntegral(const std::vector<uint8_t>& content, int first, int last){
	size_t size = last-first+1;
	if(size > sizeof(T)){
		Log::Error("Specified region must not be greater than size of type");
		return 0;
	}
	T integral = 0;
	for(size_t i=0; i<size; ++i){
		integral |= content[first+i] << i*8;
	}
	return integral;
}

#endif
