#pragma once

class Printer {
public:
	Printer();
	void setOutputFileName(const std::string& outputFileName);
	void print(int cmdType, std::string op1, prioirtyQ searchQ, bool &isFirst);
private:
	std::string outputFileName;
};