template <class T>
class ResourceManager {
	private:
		class RecycledIndices {
			public:
				int upperBound, lowerBound;

				RecycledIndices* next;

				RecycledIndices(int start);

				/**
				 * Inserts the given value in this node if this value will fit contiguously in it.
				 */
				bool insert(int index);template <class T>
class ResourceManager {
	private:
		class RecycledIndices {
			public:
				int upperBound, lowerBound;

				RecycledIndices* next;

				RecycledIndices(int start);

				/**
				 * Inserts the given value in this node if this value will fit contiguously in it.
				 */
				bool insert(int index);

				int popLowestIndex();

				void setNext(RecycledIndices* next);

				void incrementUpperBound();

				void decrementLowerBound();
		};
		RecycledIndices *recycled;
		int elements;
		T* list;
	public:
		ResourceManager();

		/**
 		 * Adds the given element to the list.
 		 * @param element the element to be added
 		 * @return the index assigned to the element that it may be accessed by
 		 */
		int add(T element);
		
		/**
		 * Removes the item at the given location from the list.
		 * @param index the index of the element to be removed
		 * @return the removed element
		 */
		T remove(int index);
};

//implementation///////////////////////////////////////////////////////////////////////////

template <class T>
ResourceManager<T>::ResourceManager() {
	recycled = NULL;
	elements = 0;
	list = new T[500];
}

template <class T>
int ResourceManager<T>::add(T element) {
	int i;
	if (recycled != NULL) {
		i = recycled->popLowestIndex();
	} else {
		i = elements;
	}
	elements++;
	list[i] = element;
	return i;
}

template <class T>
T ResourceManager<T>::remove(int index) {
	if (recycled == NULL) {
		recycled = new RecycledIndices(index);
	} else {
		RecycledIndices* current = recycled;
		while (true) {
			if (current->insert(index)) {
				break;
			}
			if (current->next != NULL) {
				current = current->next;
			} else {
				current->setNext(new RecycledIndices(index));
				break;
			}
		}
	}
	return list[index];
}

//RecycledIndices implementation/////////////////////////////////////////////////
template <class T>
ResourceManager<T>::RecycledIndices::RecycledIndices(int start = 0) {
	lowerBound = upperBound = start;
	next = NULL;
}

template <class T>
void ResourceManager<T>::RecycledIndices::setNext(RecycledIndices* next) {
	this->next = next;
}

template <class T>
void ResourceManager<T>::RecycledIndices::incrementUpperBound() {
	upperBound++;
	if (upperBound == next->lowerBound) {
		upperBound = next->upperBound;
		RecycledIndices* tmp = next;
		next = next->next;
		delete tmp;
	}
}

template <class T>
int ResourceManager<T>::RecycledIndices::popLowestIndex() {
	int retval = lowerBound++;
	if (lowerBound > upperBound && next != NULL) {
		RecycledIndices* tmp = next;
		*this = *next;
		delete tmp;
	}
	return retval;
}

template <class T>
void ResourceManager<T>::RecycledIndices::decrementLowerBound() {
	lowerBound--;
}

template <class T>
bool ResourceManager<T>::RecycledIndices::insert(int index) {
	if (index == lowerBound - 1) {
		decrementLowerBound();
		return true;
	} else if (index == upperBound + 1) {
		incrementUpperBound();
		return true;template <class T>
class ResourceManager {
	private:
		class RecycledIndices {
			public:
				int upperBound, lowerBound;

				RecycledIndices* next;

				RecycledIndices(int start);

				/**
				 * Inserts the given value in this node if this value will fit contiguously in it.
				 */
				bool insert(int index);

				int popLowestIndex();

				void setNext(RecycledIndices* next);

				void incrementUpperBound();

				void decrementLowerBound();
		};
		RecycledIndices *recycled;
		int elements;
		T* list;
	public:
		ResourceManager();

		/**
 		 * Adds the given element to the list.
 		 * @param element the element to be added
 		 * @return the index assigned to the element that it may be accessed by
 		 */
		int add(T element);
		
		/**
		 * Removes the item at the given location from the list.
		 * @param index the index of the element to be removed
		 * @return the removed element
		 */
		T remove(int index);
};

//implementation///////////////////////////////////////////////////////////////////////////

template <class T>
ResourceManager<T>::ResourceManager() {
	recycled = NULL;
	elements = 0;
	list = new T[500];
}

template <class T>
int ResourceManager<T>::add(T element) {
	int i;
	if (recycled != NULL) {
		i = recycled->popLowestIndex();
	} else {
		i = elements;
	}
	elements++;
	list[i] = element;
	return i;
}

template <class T>
T ResourceManager<T>::remove(int index) {
	if (recycled == NULL) {
		recycled = new RecycledIndices(index);
	} else {
		RecycledIndices* current = recycled;
		while (true) {
			if (current->insert(index)) {
				break;
			}
			if (current->next != NULL) {
				current = current->next;
			} else {
				current->setNext(new RecycledIndices(index));
				break;
			}
		}
	}
	return list[index];
}

//RecycledIndices implementation/////////////////////////////////////////////////
template <class T>
ResourceManager<T>::RecycledIndices::RecycledIndices(int start = 0) {
	lowerBound = upperBound = start;
	next = NULL;
}

template <class T>
void ResourceManager<T>::RecycledIndices::setNext(RecycledIndices* next) {
	this->next = next;
}

template <class T>
void ResourceManager<T>::RecycledIndices::incrementUpperBound() {
	upperBound++;
	if (upperBound == next->lowerBound) {
		upperBound = next->upperBound;
		RecycledIndices* tmp = next;
		next = next->next;
		delete tmp;
	}
}

template <class T>
int ResourceManager<T>::RecycledIndices::popLowestIndex() {
	int retval = lowerBound++;
	if (lowerBound > upperBound && next != NULL) {
		RecycledIndices* tmp = next;
		*this = *next;
		delete tmp;
	}
	return retval;
}

template <class T>
void ResourceManager<T>::RecycledIndices::decrementLowerBound() {
	lowerBound--;
}

template <class T>
bool ResourceManager<T>::RecycledIndices::insert(int index) {
	if (index == lowerBound - 1) {
		decrementLowerBound();
		return true;
	} else if (index == upperBound + 1) {
		incrementUpperBound();
		return true;template <class T>
class ResourceManager {
	private:
		class RecycledIndices {
			public:
				int upperBound, lowerBound;

				RecycledIndices* next;

				RecycledIndices(int start);

				/**
				 * Inserts the given value in this node if this value will fit contiguously in it.
				 */
				bool insert(int index);

				int popLowestIndex();

				void setNext(RecycledIndices* next);

				void incrementUpperBound();

				void decrementLowerBound();
		};
		RecycledIndices *recycled;
		int elements;
		T* list;
	public:
		ResourceManager();

		/**
 		 * Adds the given element to the list.
 		 * @param element the element to be added
 		 * @return the index assigned to the element that it may be accessed by
 		 */
		int add(T element);
		
		/**
		 * Removes the item at the given location from the list.
		 * @param index the index of the element to be removed
		 * @return the removed element
		 */
		T remove(int index);
};

//implementation///////////////////////////////////////////////////////////////////////////

template <class T>
ResourceManager<T>::ResourceManager() {
	recycled = NULL;
	elements = 0;
	list = new T[500];
}

template <class T>
int ResourceManager<T>::add(T element) {
	int i;
	if (recycled != NULL) {
		i = recycled->popLowestIndex();
	} else {
		i = elements;
	}
	elements++;
	list[i] = element;
	return i;
}

template <class T>
T ResourceManager<T>::remove(int index) {
	if (recycled == NULL) {
		recycled = new RecycledIndices(index);
	} else {
		RecycledIndices* current = recycled;
		while (true) {
			if (current->insert(index)) {
				break;
			}
			if (current->next != NULL) {
				current = current->next;
			} else {
				current->setNext(new RecycledIndices(index));
				break;
			}
		}
	}
	return list[index];
}

//RecycledIndices implementation/////////////////////////////////////////////////
template <class T>
ResourceManager<T>::RecycledIndices::RecycledIndices(int start = 0) {
	lowerBound = upperBound = start;
	next = NULL;
}

template <class T>
void ResourceManager<T>::RecycledIndices::setNext(RecycledIndices* next) {
	this->next = next;
}

template <class T>
void ResourceManager<T>::RecycledIndices::incrementUpperBound() {
	upperBound++;
	if (upperBound == next->lowerBound) {
		upperBound = next->upperBound;
		RecycledIndices* tmp = next;
		next = next->next;
		delete tmp;
	}
}

template <class T>
int ResourceManager<T>::RecycledIndices::popLowestIndex() {
	int retval = lowerBound++;
	if (lowerBound > upperBound && next != NULL) {
		RecycledIndices* tmp = next;
		*this = *next;
		delete tmp;
	}
	return retval;
}

template <class T>
void ResourceManager<T>::RecycledIndices::decrementLowerBound() {
	lowerBound--;
}

template <class T>
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


	}
	return false;
}


	}
	return false;
}



				int popLowestIndex();

				void setNext(RecycledIndices* next);

				void incrementUpperBound();

				void decrementLowerBound();
		};
		RecycledIndices *recycled;
		int elements;
		T* list;
	public:
		ResourceManager();

		/**
 		 * Adds the given element to the list.
 		 * @param element the element to be added
 		 * @return the index assigned to the element that it may be accessed by
 		 */
		int add(T element);
		
		/**
		 * Removes the item at the given location from the list.
		 * @param index the index of the element to be removed
		 * @return the removed element
		 */
		T remove(int index);
};

//implementation///////////////////////////////////////////////////////////////////////////

template <class T>
ResourceManager<T>::ResourceManager() {
	recycled = NULL;
	elements = 0;
	list = new T[500];
}

template <class T>
int ResourceManager<T>::add(T element) {
	int i;
	if (recycled != NULL) {
		i = recycled->popLowestIndex();
	} else {
		i = elements;
	}
	elements++;
	list[i] = element;
	return i;
}

template <class T>
T ResourceManager<T>::remove(int index) {
	if (recycled == NULL) {
		recycled = new RecycledIndices(index);
	} else {
		RecycledIndices* current = recycled;
		while (true) {
			if (current->insert(index)) {
				break;
			}
			if (current->next != NULL) {
				current = current->next;
			} else {
				current->setNext(new RecycledIndices(index));
				break;
			}
		}
	}
	return list[index];
}

//RecycledIndices implementation/////////////////////////////////////////////////
template <class T>
ResourceManager<T>::RecycledIndices::RecycledIndices(int start = 0) {
	lowerBound = upperBound = start;
	next = NULL;
}

template <class T>
void ResourceManager<T>::RecycledIndices::setNext(RecycledIndices* next) {
	this->next = next;
}

template <class T>
void ResourceManager<T>::RecycledIndices::incrementUpperBound() {
	upperBound++;
	if (upperBound == next->lowerBound) {
		upperBound = next->upperBound;
		RecycledIndices* tmp = next;
		next = next->next;
		delete tmp;
	}
}

template <class T>
int ResourceManager<T>::RecycledIndices::popLowestIndex() {
	int retval = lowerBound++;
	if (lowerBound > upperBound && next != NULL) {
		RecycledIndices* tmp = next;
		*this = *next;
		delete tmp;
	}
	return retval;
}

template <class T>
void ResourceManager<T>::RecycledIndices::decrementLowerBound() {
	lowerBound--;
}

template <class T>
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


