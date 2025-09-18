#ifndef UNORDEREDARRAYLISTTYPE_H
#define UNORDEREDARRAYLISTTYPE_H

#include "arrayListType.h"

class unorderedArrayListType: public arrayListType
{
public:
	void insertAt(int location, int insertItem);
	void insertEnd(int insertItem);
	void replaceAt(int location, int repItem);
	int seqSearch(int searchItem) const;
	void remove(int removeItem);
	
	//Constructor.
	unorderedArrayListType(int size = 100);
	
};

#endif