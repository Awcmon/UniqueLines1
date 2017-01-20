
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <fstream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::set;

vector<string> explode(string const & s, char delim)
{
	vector<std::string> result;
	std::istringstream iss(s);
	for (string token; std::getline(iss, token, delim); )
	{
		result.push_back(move(token));
	}
	return result;
}

void writeFile(string file, string content)
{
	std::ofstream ofs;
	ofs.open(file, std::ofstream::out | std::ofstream::trunc);

	ofs << content;

	ofs.close();
}

int main(int argc, char* argv[])
{

	std::ifstream ifs("input.txt");
	std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

	vector<string> exp = explode(content, '\n');
	vector<string> unique;

	for (int i = 0; i < (int)exp.size(); i++)
	{
		//if found exp[i], add to unique vec
		if (std::find(unique.begin(), unique.end(), exp[i]) == unique.end())
		{
			unique.push_back(exp[i]);
		}
	}

	string output = "";
	for (int i = 0; i < (int)unique.size(); i++)
	{
		output = output + unique[i] + "\n";
	}
	writeFile("output.txt", output);

	return 0;
}