#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
{
    // privated
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShubberyCreationForm", 145, 137), target(target)
{
    std::cout << "📜🫐 ShrubberyCreationForm constructed: " << this->target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target(other.target)
{
    std::cout << "📜🫐 ShrubberyCreationForm copy constructed: " << this->target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << "📜🫐 ShrubberyCreationForm copy assignment called: " << this->target << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "📜🫐 ShrubberyCreationForm destructor called: " << this->target << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream outfile;
    outfile.open((this->target + "_shrubbery").c_str());
    if (!outfile)
        throw FileOpenException();

    outfile << "        🎉42🎉\n";
    outfile << "         /\\\n";
    outfile << "        /🌟\\\n";
    outfile << "       /🎁🎄\\\n";
    outfile << "      /❄️🎅🎉\\\n";
    outfile << "     /🎄✨🎁🎀\\\n";
    outfile << "    /🎁☃️⭐❄️🎄\\\n";
    outfile << "   /🎅🎁🌟🎉🎄🎀\\\n";
    outfile << "         |||\n";
    outfile << "         |||\n";
    outfile << "        /___\\\n";

    outfile.close();

    std::cout << "📜🫐 ShrubberyCreationForm executed: " << this->target << "_shrubbery" << std::endl;
}



const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "⛔ FileOpenException: Failed to open file for writing.";
}