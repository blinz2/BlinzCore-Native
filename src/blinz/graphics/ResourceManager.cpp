#define NULL 0
#include "ResourceManager.hpp"

template <typename T>
ResourceManager<T>::ResourceManager() {
	recycled = NULL;
	elements = 0;
	list = new T[500];
}

template <typename T>
int ResourceManager<T>::add(T element) {
	int i;
	if (recycled != NULL) {
		i = recycled->popLowestIncex();
	} else {
		i = elements;
	}
	elements++;
	list[i] = element;
	return i;
}

template <typename T>
T ResourceManager<T>::remove(int index) {
	if (recycled == NULL) {
		recycled = new RecycledIndices(index);
	} else {
		RecycledIndices* current = recycled;
		while (!current->insert(index) && current->getNext() != NULL) {
			if (current->insert(index)) break;
			if (current->getNext() != NULL) current = current->getNext();
			else {
				current.setNext(new RecycledIndices(index));
			}
		}
	}
	return list[index];
}

//RecycledIndices implementation/////////////////////////////////////////////////
template <typename T>
ResourceManager<T>::RecycledIndices::RecycledIndices(int start = 0) {
	lowerBound = upperBound = start;
	next = NULL;
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

template <typename T>
int ResourceManager<T>::RecycledIndices::popLowestIndex() {
	int retval = lowerBound++;
	if (lowerBound > upperBound) {
		RecycledIndices* tmp = next;
		*this = *next;
		delete tmp;
	}
	return retval;
}

template <typename T>
void ResourceManager<T>::RecycledIndices::decrementLowerBound() {
	lowerBound--;
}

template <typename T>
bool ResourceManager<T>::RecycledIndices::insert(int index) {
	if (index == lowerBound - 1) {
		decrementLowerBound();
		return true;
	} else if (index == upperBound + 1) {
		incrementUpperBound();
		return true;
	}
	return false;
}
