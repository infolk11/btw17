#ifndef VWAHLEXCEPTION_H
#define VWAHLEXCEPTION_H

#include <exception>
#include <string>

#include <QString>

class VWahlException : std::exception
{
public:
    VWahlException();
    VWahlException(QString error) :errorMsg(error) {}
    VWahlException(std::string error) : errorMsg(QString::fromStdString(error)) {}
    const char* what();

private:
    QString errorMsg;
};

class CandidateNotFoundException : std::exception
{
public:
    CandidateNotFoundException();
    CandidateNotFoundException(QString error) :errorMsg(error) {}
    CandidateNotFoundException(std::string error) : errorMsg(QString::fromStdString(error)) {}
    const char* what();

private:
    QString errorMsg;
};


#endif // VWAHLEXCEPTION_H
