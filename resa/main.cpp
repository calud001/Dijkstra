#include "Controller.h"
#include <fstream>


//#include <iomanip>
//#include <chrono> For taking time

using namespace std;


int main(int argc, char* argv[]) {
	//*
	if (argc != 3) {
		
		return -1;
	}
	//*/
	
	/* More Time-taking
	cout << "Start\n";
	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	*/

	Controller graph;

	ifstream read;
	string path = argv[1];//"C:/Users/administrator/Desktop/Resa/Nodes1.txt";//argv[1];

	read.open(path);
	string fileLineLoaded;
	getline(read, fileLineLoaded);

	if (fileLineLoaded == "DIRECTED") {
		
		//load nodes
		getline(read, fileLineLoaded);
		while (fileLineLoaded != ""){
			
			graph.insert(fileLineLoaded);

			getline(read, fileLineLoaded);
		}

		//load lines
		while (!read.eof())
		{
			getline(read, fileLineLoaded);

			
			string town1 = fileLineLoaded.substr(0, fileLineLoaded.find("\t"));
			fileLineLoaded = fileLineLoaded.substr(fileLineLoaded.find("\t")+1);//cut out town 1
			string town2 = fileLineLoaded.substr(0, fileLineLoaded.find("\t"));
			fileLineLoaded = fileLineLoaded.substr(fileLineLoaded.find("\t")+1);//cut out town 2
			int cost = stoi(fileLineLoaded.substr(0, fileLineLoaded.find("\t")));

			graph.insertLink(town1, town2, cost);

		}

	}
	else {
		//load nodes
		getline(read, fileLineLoaded);
		while (fileLineLoaded != "") {

			graph.insert(fileLineLoaded);

			getline(read, fileLineLoaded);
		}

		//load lines
		while (!read.eof())
		{
			getline(read, fileLineLoaded);


			string town1 = fileLineLoaded.substr(0, fileLineLoaded.find("\t"));
			fileLineLoaded = fileLineLoaded.substr(fileLineLoaded.find("\t") + 1);//cut out town 1
			string town2 = fileLineLoaded.substr(0, fileLineLoaded.find("\t"));
			fileLineLoaded = fileLineLoaded.substr(fileLineLoaded.find("\t") + 1);//cut out town 2
			int cost = stoi(fileLineLoaded.substr(0, fileLineLoaded.find("\t")));
			graph.insertLink(town1, town2, cost);
			graph.insertLink(town2, town1, cost);
		}
	}

	read.close();

	string pathNodes = argv[2];//"Second Town-Third Town";//argv[2]; //"F-D";

	graph.findPath(pathNodes.substr(0, pathNodes.find("-")), pathNodes.substr(pathNodes.find("-") + 1));
	
	/* Time taking
	auto end = chrono::high_resolution_clock::now();

	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cout << "Time taken by program is : " << fixed << setprecision(9)
		<< time_taken;
	cout << " sec" << endl;
	*/

	cout << endl << "done" << endl;

	getchar();

	return 0;
}