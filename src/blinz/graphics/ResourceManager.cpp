#include <vector>
#include "ResourceManager.hpp"

using std::vector;


template <typename T>
ResourceManager<T>::ResourceManager() {
	recycled = NULL;
}

template <typename T>
ResourceManager<T>:: RecycledIndices::RecycledIndices() {
	lowerBound = upperBound = 0;
	next = NULL;
}

template <typename T>
int ResourceManager<T>::RecycledIndices::getLowerBound() {
	return lowerBound;
}

template <typename T>
int ResourceManager<T>::RecycledIndices::getUpperBound() {
	return upperBound;
}

template <typename T>
void ResourceManager<T>::RecycledIndices::setNext(RecycledIndices* next) {
	this->next = next;
}

template <typename T>
void ResourceManager<T>::RecycledIndices::incrementUpperBound() {
	upperBound++;
	if (upperBound == next->lowerBound) {
		upperBound = next->upperBound;
		RecycledIndices* tmp = next;
		next = next->next;
		delete tmp;
	}
}

