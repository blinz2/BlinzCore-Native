#ifndef IMAGE_H
#define IMAGE_H

template <typename T>
class ResourceManager {
	private:
		class RecycledIndices {
			private:
				int upperBound, lowerBound;
				RecycledIndices* next;
			public:
				RecycledIndices(int start);

				/**
				 * Inserts the given value in this node if this value will fit contiguously in it.
				 */
				bool insert(int index);

				int popLowestIndex();
				
			private:
				void setNext(RecycledIndices* next);

				RecycledIndices* getNext();
 
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


#endif // IMAGE_H
