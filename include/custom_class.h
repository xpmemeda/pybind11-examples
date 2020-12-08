#include <string>


struct Pet {
    Pet(const std::string& name);
    void setName(const std::string& name);
    const std::string& getName() const;
    std::string public_name;
  private:
    std::string _name;
};