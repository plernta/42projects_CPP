#include <string>
#include <iostream>
#include <fstream>

std::string replace_word(std::string& line, const std::string& old_word, const std::string& new_word)
{
    std::string result = line;
    size_t pos = 0;
    size_t old_word_length = old_word.length();
    size_t new_word_length = new_word.length();

    while ((pos = result.find(old_word, pos)) != std::string::npos)
    {
        // result.replace(pos, old_word_length, new_word);
        // (part before the found word at pos from 0) + (replacement word) + (part after the found word)
        result = result.substr(0, pos) + new_word + result.substr(pos + old_word_length);
        pos += new_word_length;
    }
    return result;
}

void transfer_if_to_of(std::ifstream &infile, std::ofstream &outfile, const std::string &s1, const std::string &s2)
{
    std::string temp_line;

    while(std::getline(infile, temp_line))
    {
        temp_line = replace_word(temp_line, s1, s2);
        outfile << temp_line << std::endl;
    }
}

int main(int ac, char **av)
{
    if (ac == 4)
    {  
        std::ifstream infile;
        std::ofstream outfile;
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string filename_out = filename + ".replace";

        infile.open(filename.c_str());
        if (!infile)
        {
            std::cout << "Error: Could not open file " << filename << std::endl;
            return 1;
        }

        outfile.open(filename_out.c_str());
        if (!outfile)
        {
            std::cout << "Error: Could not open file " << filename_out << std::endl;
            return 1;
        }

        transfer_if_to_of(infile, outfile, s1, s2);
        infile.close();
        outfile.close();

    }
    else
    {
        std::cout << "Error: Wrong number of arguments" << std::endl;
        return 1;
    }
}