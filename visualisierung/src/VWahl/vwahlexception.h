#ifndef VWAHLEXCEPTION_H
#define VWAHLEXCEPTION_H

#include <exception>
#include <string>

#include <QString>

class VWahlException : public std::exception
{
public:
    VWahlException() = default;
    VWahlException(QString error) :errorMsg(error) {}
    VWahlException(std::string error) : errorMsg(QString::fromStdString(error)) {}
    const char* what();

private:
    QString errorMsg;
};

class CandidateNotFoundException : public VWahlException
{
public:
    CandidateNotFoundException() = default;
    CandidateNotFoundException(QString error) : VWahlException(error) {}
    CandidateNotFoundException(std::string error) : VWahlException(error) {}
};

class PlottingException : public VWahlException
{
public:
    PlottingException() = default;
    PlottingException(QString error) : VWahlException(error) {}
    PlottingException(std::string error) : VWahlException(error) {}
};


#endif // VWAHLEXCEPTION_H
