
template <class T>
class ResourceManager {
	private:
		class AvailableIndices {
			public:
				int upperBound, lowerBound;

				AvailableIndices* next;

				AvailableIndices(int start, int end);

				/**
				 * Remvoes the given value in this node if this value will fit contiguously in it.
				 */
				bool add(int index);

				int popLowestIndex();

				void setNext(AvailableIndices* next);

				void incrementUpperBound();

				void decrementLowerBound();

				void decrementUpperBound();
		};
		AvailableIndices *avail;
		int elements;
		T* list;
	public:
		ResourceManager(int defaultSize);

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
ResourceManager<T>::ResourceManager(int defaultSize = 500) {
	avail = new AvailableIndices();
	elements = 0;
	list = new T[defaultSize];
}

template <class T>
int ResourceManager<T>::add(T element) {
	int i;
	if (avail != 0) {
		i = avail->popLowestIndex();
	} else {
		i = elements;
	}
	elements++;
	list[i] = element;
	return i;
}

template <class T>
T ResourceManager<T>::remove(int index) {
	if (avail == 0) {
		avail = new AvailableIndices(index, index);
	} else {
		AvailableIndices* current = avail;
		if (current->lowerBound > index) {
			avail = new AvailableIndices(index, index);
			avail->next = current;
		} else while (true) {
			if (current->add(index)) {
				break;
			}
			if (current->next == 0) {
				current->setNext(new AvailableIndices(index, index));
				break;
			} else if (current->next->lowerBound > index) {
				//insert new node
				AvailableIndices* i = new AvailableIndices(index, index);
				i->next = current->next;
				current->next = i;
				break;
			} else {
				current = current->next;
			}
		}
	}
	return list[index];
}

//RecycledIndices implementation/////////////////////////////////////////////////
template <class T>
ResourceManager<T>::AvailableIndices::AvailableIndices(int start = 0, int end = 32767) {
	lowerBound = start;
	upperBound = end;
	next = 0;
}

template <class T>
void ResourceManager<T>::AvailableIndices::setNext(AvailableIndices* next) {
	this->next = next;
}

template <class T>
void ResourceManager<T>::AvailableIndices::incrementUpperBound() {
	upperBound++;
	if (next != 0 && upperBound == next->lowerBound) {
		upperBound = next->upperBound;
		AvailableIndices* n = next;
		next = next->next;
		delete n;
	}
}

template <class T>
int ResourceManager<T>::AvailableIndices::popLowestIndex() {
	int retval = lowerBound++;
	if (lowerBound > upperBound && next != 0) {
		AvailableIndices* tmp = next;
		*this = *next;
		delete tmp;
	}
	return retval;
}

template <class T>
void ResourceManager<T>::AvailableIndices::decrementLowerBound() {
	lowerBound--;
}

template <class T>
bool ResourceManager<T>::AvailableIndices::add(int index) {
	if (index <= upperBound + 1) {
		if (index == upperBound + 1) {
			incrementUpperBound();
			return true;
		} else if (index == lowerBound - 1) {
			decrementLowerBound();
			return true;
		} 
	}
	return false;
}

