#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


class TouchCommand: public AbstractCommand {
	private:
		AbstractFileSystem* afs;
		AbstractFileFactory* aff;
	public:
		TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff);
		void displayInfo() override;
		int execute(std::string) override;
};