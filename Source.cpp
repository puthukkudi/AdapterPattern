/*
* Adapter will be used to analyse the xml data that client has.
* Since DataAnalysingTool accepts only json format Adapter will convert the xml format to json format and do the required processing.
*/


#include <iostream>
using namespace std;

class XMLData
{
private:
	string xmlData;
public:
	XMLData(string pXMLData):xmlData(pXMLData)
	{

	}

	string GetXMLData()
	{
		return xmlData;
	}
};

class DataAnalysingTool
{
protected:
	string jsonData;
public:
	DataAnalysingTool() {}
	DataAnalysingTool(string pJsonData):jsonData(pJsonData)
	{

	}

	virtual void AnalyseData()
	{
		cout << "Analysing Json Data.... " << jsonData<<endl;
	}

	string GetJsonData()
	{
		return jsonData;
	}
};


class Client
{
public:
	void ProcessData(DataAnalysingTool* tool)
	{
		tool->AnalyseData();
	}
};

class Adapter : public DataAnalysingTool
{
private:
	XMLData* xmlData;
	string ConvertedJsonData(string pXMLData)
	{
		return "converted json : " + pXMLData;
	}

public:
	Adapter(XMLData* pXMLData) :xmlData(pXMLData) {}


	void AnalyseData()
	{
		cout << "Converting xml data to json data..." << endl;
		jsonData = ConvertedJsonData(xmlData->GetXMLData());
		DataAnalysingTool::AnalyseData();
	}
};


int main()
{
	XMLData* m_xmlData = new XMLData("Sample Xml Data");	
	DataAnalysingTool* tool = new Adapter(m_xmlData); // Use upcasting and Adapter class to create a bridge to analyse xml string
	tool->AnalyseData();

	DataAnalysingTool* toolNew = new DataAnalysingTool("Sample Json Data");
	toolNew->AnalyseData();
}