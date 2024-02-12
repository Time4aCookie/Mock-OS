#include "AbstractFile.h"
#include <string>

class PasswordProxy: public AbstractFile {
	private: 
		AbstractFile * afPointer;
		std::string password;
	public:
		PasswordProxy(AbstractFile * afPointer, std::string password);
		~PasswordProxy();
		virtual std::vector<char> read() override;
		virtual int write(std::vector<char> bytes) override;
		virtual int append(std::vector<char> bytes) override;
		virtual unsigned int getSize() override;
		virtual std::string getName() override;
		virtual void accept(AbstractFileVisitor* visitor) override;
		virtual AbstractFile *clone(std::string name) override;


		protected:
		std::string passwordPrompt();
};
