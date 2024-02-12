#include "../../include/mockos/MetadataDisplayVisitor.h"
#include "../../include/mockos/ImageFile.h"
#include "../../include/mockos/TextFile.h"
#include <iomanip>

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
	int maxWidth = 20;
	int buffer = 1;
	cout << file->getName();
	for (int i = 0; i < (maxWidth + buffer) - file->getName().size(); i++) {
		cout << " ";
	}
	string text = "text";
	cout << text;
	for (int i = 0; i < (maxWidth + buffer) - text.size(); i++) {
		cout << " ";
	}
	cout << file->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	int maxWidth = 20;
	int buffer = 1;
	cout << file->getName();
	for (int i = 0; i < (maxWidth + buffer) - file->getName().size(); i++) {
		cout << " ";
	}
	string image = "image";
	cout << image;
	for (int i = 0; i < (maxWidth + buffer) - image.size(); i++) {
		cout << " ";
	}
	cout << file->getSize() << endl;
}
