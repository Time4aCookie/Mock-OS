#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class LSCommand : public AbstractCommand {
	private:
		AbstractFileSystem* afs;
	public:
		LSCommand(AbstractFileSystem* afs);
		void displayInfo() override;
		int execute(std::string) override;
};