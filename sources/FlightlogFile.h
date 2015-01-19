#ifndef FLIGHTLOGFILE_H_INCLUDED
#define FLIGHTLOGFILE_H_INCLUDED

#include <fstream>
#include <string>
#include <sstream>
#include <memory>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include "Utilities/Log.h"
#include "Utilities/Erreur.h"

#include "MVC/Model.h"

const std::string DEFAULT_PATH = "./flightlog/flightlog.txt";
const std::string LAST_SAVE_PATH = "./flightlog/flightlog.old";
const std::string DEFAULT_FLIGHTLOG_DIRECTORY = "./flightlog/";

class FlightlogFile : public Model
{
public:
    FlightlogFile();                                    //OK
    virtual ~FlightlogFile();                           //OK

    void notifyObservers();                             //OK
    void notifyObservers(std::string&);

    int calculateKEY() const;
    int getKEY() const;

private:
    boost::filesystem::path path;                       //OK
    std::unique_ptr<boost::filesystem::fstream> file;   //OK

    void open();
    void close();
    void save();
    void read(std::vector<std::string>&);
    void write(std::vector<std::string>&);

    int getLineNbr(const std::string& line) const {}

    void searchSection(std::string&, boost::filesystem::fstream&) const;
};

#endif // FLIGHTLOGFILE_H_INCLUDED
