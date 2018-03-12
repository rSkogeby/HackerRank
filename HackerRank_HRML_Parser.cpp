//#include <cmath>
//#include <iomanip>
//#include <iostream>
//#include <vector>
//#include <set>
//#include <map>
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <algorithm>
//#include <cassert>
//#include <bitset>

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
using namespace std;

class Tag{
	private:
		string name;
		map<string,string> AttVal;
		Tag* parent;
	public:
		void setName(string n){ name = n; }
		string getName(){ return name; }
		Tag* getParent(){ return parent; }
		void mapTagInput( string a, string v ){
			if(AttVal.find(a) != AttVal.end() ){
				AttVal.emplace(a,v);
			} else {
				AttVal[a] = v;
			}
		}
		void setParent(Tag* p){ 
			parent = p;	
		}
};


int main(){
	int nInputs, nQueries;
	
	cin >> nInputs >> nQueries;
	cin.ignore();
	
	stringstream tagStream;
	stringstream tagNameStream;
	stringstream tagValueStream;
	string input;
	int j;
	vector<string> tags;
	vector<string> tagNames;
	vector<string> tagValues;
	vector<string> commands;
	vector<vector<string> > entries;
	vector<string> closingTags;
	vector<Tag> tagVec;
	Tag* previousTag;
	Tag tag_tmp;
	int ctr = 0;
	bool firstIter = true;
	// nInputs
	for (int i = 0; i < nInputs; i++){
		// after space read tagname, save as tagname
		// look for " read until ", save as tagvalue
		getline(cin,input);
				
		// Look for <, read until space, save as tag
		j = 0;
		int tg = 0;
		if(input[j] == '<'){
			j++;	
			if(input[j] != '/'){
				while(input[j] != ' ' && input[j]!='>'){
					tagStream << input[j];
					j++;
				}
				if(tagStream.str() != " ") {
					tag_tmp.setName(tagStream.str());
					tagVec.push_back(tag_tmp); 
					if(firstIter){
						firstIter=false;
						tagVec[ctr].setParent(NULL);
					} else if(/*previous tag not closed before another one opens*/ !firstIter){
					previousTag = &tagVec[ctr];
					ctr++;
						tagVec[ctr].setParent(previousTag);
					}
				}
				commands.push_back(tagStream.str());
				tagStream.str("");
				tagStream.clear();
				// loop many values = attributes
				while(input[j] != '>'){
					while(input[j] != '='){ // Acquire value
						if(input[j] != ' ' && input[j] != '=' && input[j] != '"') tagNameStream << input[j];
						j++;
					}
					while(input[j] != '"'){
						j++;
					}
					do{ // Acquire attribute
						if(input[j] != ' ' && input[j] != '=' && input[j] != '"') tagValueStream << input[j];
						j++;
					} while(input[j] != '"');
					j++;
				//tags.push_back(tagStream.str());
				//tagNames.push_back(tagNameStream.str());
				//tagValues.push_back(tagValueStream.str());
					commands.push_back(tagNameStream.str());
					commands.push_back(tagValueStream.str());
					tagNameStream.str("");
					tagNameStream.clear();
					tagValueStream.str("");
					tagValueStream.clear();
				}
					entries.push_back(commands);
					commands.erase(commands.begin(),commands.end());
				
			} else {
				while(input[j] != '>'){
					if(input[j] != '<' && input[j] != '/' && input[j] != '>') tagStream << input[j];
					j++;
				}
				closingTags.push_back(tagStream.str());
				tagStream.str("");
				tagStream.clear();
			}
		}
		// look for </ read tag
		// if another < tag comes before </, nestle expression
	}
	for (int k=0; k< entries.size();k++){
		for (int j=0; j < entries[k].size();j++){
			cout << entries[k][j] << endl;
		}
	}
		for (int j=0; j < closingTags.size();j++){
			cout << closingTags[j] << endl;
		}
		for (int j=0; j < tagVec.size();j++){
			cout <<"Name: "<< tagVec[j].getName() << " Parent: " << tagVec[j].getParent()->getName() << endl;
		}
}
