#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor: public AbstractFileVisitor {
	void visit_ImageFile(ImageFile* file);
	void visit_TextFile(TextFile* file);
};
