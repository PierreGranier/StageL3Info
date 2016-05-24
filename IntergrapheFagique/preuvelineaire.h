#ifndef preuvelineaire_h
#define preuvelineaire_h

#include <string>

class PreuveLineaire : public std::string
{
	private:
	
	public:
		PreuveLineaire(std::string const &chaine) : std::string(chaine) {};
		~PreuveLineaire() {};
		
		bool commencePar(std::string const &chaine) const { return this->find(chaine+" ") == 0 || this->find(" "+chaine+" ") == 0; };
		std::string triplet() const { return this->substr(this->find('{'), this->find(':')) + this->substr(this->find('='), this->find('}')); };
		void tronquerRegle() { this->erase(0, this->find('{')); };
		void tronquerTriplet() { this->substr(this->find('{'), this->find(':')); this->substr(this->find('='), this->find('}')); };
};

#endif