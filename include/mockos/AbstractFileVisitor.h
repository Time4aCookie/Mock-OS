#pragma once

// forward definition
class ImageFile;
class TextFile;

class AbstractFileVisitor {
	public:
		virtual void visit_ImageFile(ImageFile* file) = 0;
		virtual void visit_TextFile(TextFile* file) = 0;
};
