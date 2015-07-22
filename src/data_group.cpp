#include <data_group.h>

DataGroup::DataGroup(uint n, dVec d)
{
	size = n;
	data = d;
	sum = calculateSum(data);
	mean = calculateMean(size, sum);
	median = calculateMedian(size, data);
	variance = calculateVariance(size, data, mean);
	sd = calculateSD(variance);
}

DataGroup::~DataGroup()
{}

void DataGroup::showData()
{
	if( size <= 10)
	{
		std::cout << "The data are: [";
		for(uint i = 0; i < size - 1; i++)
			std::cout << data[i] << ", ";
		std::cout << data[size - 1] << "]" << std::endl;
	}
	else
	{
		std::cout << "The data are: [";
		for(uint i = 0; i < 5; i++)
			std::cout << data[i] << ", ";
		std::cout << " ... , "; 
		for(uint i = size - 5; i < size -1; i++)
			std::cout << data[i] << ", ";
		std::cout << data[size - 1] << "]" << std::endl;
	}
	std::cout << "The sum of data = " << sum << std::endl;
	std::cout << "The mean of data = " << mean << std::endl;
	std::cout << "The median of data = " << median << std::endl;
	std::cout << "The variance of data = " << variance << std::endl;
	std::cout << "The standard deviation of data = " << sd << std::endl;
}

void DataGroup::saveData()
{
	std::fstream dataFile("data.dat",std::fstream::in | std::fstream::out | std::fstream::trunc); 
	//for(uint i = 0; i < size; i++)
	uint i = 0;
	for(dVecIt it = data.begin(); it != data.end(); ++it)
	{
		dataFile << i << " " << *it << std::endl;
		i++;
	}
	dataFile.close();
}

void DataGroup::deleteData()
{
	if( remove("data.dat") != 0)
		perror("Error deleting file");
}

void DataGroup::plotData()
{
	saveData();

	plotGNU();

	deleteData();
}

void DataGroup::saveDataSQL() {	SQLite();}

void DataGroup::sortData() { StatisticalMethods::sortData(data);}
