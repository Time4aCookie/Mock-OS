#include "AbstractFileVisitor.h"

class BasicDisplayVisitor: public AbstractFileVisitor {
	void visit_ImageFile(ImageFile* file);
	void visit_TextFile(TextFile* file);
};
