#include "Replace.hpp"
#include <iostream>

Replace::Replace(const std::string& filename,
                 const std::string& s1,
                 const std::string& s2)
    : filename(filename), s1(s1), s2(s2)
{
}

bool Replace::process()
{
    if (s1.empty())
    {
        std::cerr << "Error: string to replace (s1) cannot be empty." << std::endl;
        return false;
    }

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: could not open input file '" << filename << "'." << std::endl;
        return false;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outfile(outFilename.c_str());
    if (!outfile)
    {
        std::cerr << "Error: could not create output file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line;
        if (!infile.eof())
            outfile << "\n";
    }

    return true;
}

