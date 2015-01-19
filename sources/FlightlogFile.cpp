#include "FlightlogFile.h"

FlightlogFile::FlightlogFile()
{
    Log("FlightlogFile constructor");



    notifyObservers();
}

FlightlogFile::~FlightlogFile()
{
    Log("FlightlogFile destructor");
}

void
FlightlogFile::notifyObservers()
{
    Log("Observers notification...");
    for (size_t i = 0; i < observers.size(); ++i)
    {
        observers[i]->update();
    }
}

void
FlightlogFile::notifyObservers(std::string& message)
{
    Log("Observers notification with message...");
    for (size_t i = 0; i < observers.size(); ++i)
    {
        observers[i]->update(message);
    }
}

int
FlightlogFile::calculateKEY() const
{
    using namespace boost::filesystem;
    fstream file(path, std::ios_base::in);

    std::string sectionName ("KEY");
    searchSection(sectionName, file);
    std::streampos calculusEnd = file.tellg();
    file.seekg(std::ios::beg);

    int ret = 0;

    char c;
    while(file.get(c) && file.tellg() != calculusEnd)
    {
        ret += (int)c;
    }

    std::string sret;
    std::stringstream ssret;
    ssret << ret;
    sret = ssret.str();

    Log("calculateKEY:" + sret);

    return ret;
}

int
FlightlogFile::getKEY() const
{
    using namespace boost::filesystem;
    fstream file(path, std::ios_base::in);

    int key = 0;
    std::string sectionName = "KEY";
    searchSection(sectionName, file);
    file >> key;

    if (key != 0)
        return key;

    throw Erreur("Error reading key", MEDIUM, FILE_ERROR);
}

//_________________PRIVATE_____________________________________________________

void
FlightlogFile::open()
{
    using namespace boost::filesystem;
    path = DEFAULT_PATH;
    if (!exists(path))
    {
        throw Erreur("Flightlog file not found", LOW, FILE_NOT_FOUND);
    }

    std::unique_ptr<fstream> filestream (new fstream (path, std::ios_base::in | std::ios_base::out));

    if (!(filestream->good()))
        throw Erreur("Problem while opening/creating flightlog.txt", HIGH, FILE_ERROR);

    file = std::move(filestream);
}

void
FlightlogFile::searchSection(std::string& sectionName, boost::filesystem::fstream& file) const
{
    file.seekg(std::ios::beg);
    std::string s;

    while(std::getline(file, s))
    {
        //std::cout << s << std::endl;
        if (s == "[" + sectionName + "]")
        {
            break;
        }
    }

    if (!file)
        throw Erreur("SECTION not found", MEDIUM, FILE_ERROR);
}
