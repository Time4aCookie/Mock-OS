#include <iostream>
#include "../../include/mockos/BasicDisplayVisitor.h"
#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/ImageFile.h"

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
	for(int i = 0; i < file->getImageDimensions(); ++i) {
		for(int j = 0; j < file->getImageDimensions(); ++j) {
			cout << file->read()[file->coordsToIndex(j,i)];
		}
		cout << endl;
	}
}

void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
	for (int i = 0; i < file->getSize(); ++i) {
		cout << file->read()[i];
	}	
	cout << endl;
}
