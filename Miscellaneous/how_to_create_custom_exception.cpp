#include<exception>
#include<stdexcept>
#include<string>
using std::string, std::exception, std::runtime_error;

class CustomException : public exception {
public:
    const char* what() const noexcept override {
        return "custom error message";
    }
};
//using std::runtime_error if required
class MessageException : public runtime_error {
public:
    explicit MessageException(const string& msg)
        : std::runtime_error("MessageException: " + msg) {}
};

//or an exception with some data
class ErrorException : public exception{
private:
    string msg;
public:
    ErrorException(const string &s) : msg(s){}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};
