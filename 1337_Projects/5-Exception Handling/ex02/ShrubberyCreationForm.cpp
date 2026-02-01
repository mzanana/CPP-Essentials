#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shruberry", 145, 137){
	target = "Default Target";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shruberry", 145, 137), target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :  AForm(other), target(other.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& right)
{
	if (this != &right)
	{
		AForm::operator=(right);
		this->target = right.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (target);
}

void ShrubberyCreationForm::action() const
{
    std::ofstream output((target + "_shrubbery").c_str());

    output << "                                                         ." << std::endl;
    output << "                                              .         ;  " << std::endl;
    output << "                 .              .              ;%     ;;   " << std::endl;
    output << "                   ,           ,                :;%  %;   " << std::endl;
    output << "                    :         ;                   :;%;'     .,   " << std::endl;
    output << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    output << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    output << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    output << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    output << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    output << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    output << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    output << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
    output << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
    output << "                          `@%%. `@%%    ;@@%;        " << std::endl;
    output << "                            ;@%. :@%%  %@@%;       " << std::endl;
    output << "                              %@bd%%%bd%%:;     " << std::endl;
    output << "                                #@%%%%%:;;" << std::endl;
    output << "                                %@@%%%::;" << std::endl;
    output << "                                %@@@%(o);  . '         " << std::endl;
    output << "                                %@@@o%;:(.,'         " << std::endl;
    output << "                            `.. %@@@o%::;         " << std::endl;
    output << "                               `)@@@o%::;         " << std::endl;
    output << "                                %@@(o)::;        " << std::endl;
    output << "                               .%@@@@%::;         " << std::endl;
    output << "                               ;%@@@@%::;.          " << std::endl;
    output << "                              ;%@@@@%%:;;;. " << std::endl;
    output << "                          ...;%@@@@@%%:;;;;,.." << std::endl;

    output.close();
}

