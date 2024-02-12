#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/CommandPrompt.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/LSCommand.h"
#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/RemoveCommand.h"
#include "../include/mockos/CatCommand.h"
#include "../include/mockos/MacroCommand.h"
#include "../include/mockos/EditDisplayParsingStrategy.h"
#include "../include/mockos/CopyCommand.h"
#include "../include/mockos/RenameParsingStrategy.h"

using namespace std;

int main(int argc, char* argv[]) {
	SimpleFileSystem* fs = new SimpleFileSystem();
	SimpleFileFactory* ff = new SimpleFileFactory();
 
	CommandPrompt* cmd = new CommandPrompt();
	cmd->setFileSystem(fs);
	cmd->setFileFactory(ff);

	TouchCommand* touch = new TouchCommand(fs, ff);
	cmd->addCommand("touch", touch);

	DisplayCommand* ds = new DisplayCommand(fs);
	cmd->addCommand("ds", ds);

	LSCommand* ls = new LSCommand(fs);
	cmd->addCommand("ls", ls);

	RemoveCommand* rm = new RemoveCommand(fs);
	cmd->addCommand("rm", rm);

	CatCommand* cat = new CatCommand(fs);
	cmd->addCommand("cat", cat);

	CopyCommand* cp = new CopyCommand(fs);
	cmd->addCommand("cp", cp);

	MacroCommand* rename = new MacroCommand(fs);
	rename->setDisplayInfo("rn - rename a file\nUsage:\n\trn <existing_file> <new_name_with_no_extension>");
	RenameParsingStrategy* renameStrat = new RenameParsingStrategy();
	rename->setParseStrategy(renameStrat);
	rename->addCommand(cp);
	rename->addCommand(rm);
	cmd->addCommand("rn", rename);

	MacroCommand* editDisplay = new MacroCommand(fs);
	editDisplay->setDisplayInfo("ed - edit and display a file with optional append\n\nUsage:\n\ted <file_name> [-a]");
	EditDisplayParsingStrategy* edDispStrat = new EditDisplayParsingStrategy();
	editDisplay->setParseStrategy(edDispStrat);
	editDisplay->addCommand(cat);
	editDisplay->addCommand(ds);
	cmd->addCommand("ed", editDisplay);

	return cmd->run();
}
