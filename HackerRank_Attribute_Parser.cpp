#include <iomanip>
#include <iostream>
#include <sstream>
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
    string closingTag;
    map<string,string> AttVal;
    Tag* parent;
  public:
    void setName(string n){ name = n; }
    void setClosingTag(string t){ closingTag = t; }
    void setAttVal( string a, string v ){
      AttVal[a] = v;
    }
    void setParent(Tag* p){ 
      parent = p; 
    }
    string getName(){ return name; }
    string getClosingTag(){ return closingTag; }
    map<string,string> getAttVal(){ return AttVal; }
    Tag* getParent(){ return parent; }
};
class Query{
  private:
    vector<string> hierarchy;
    string attribute;
  public:
    void import(string input){
      // Output: name
      int j = 0;
      stringstream tagStream;
      stringstream tagAtt;
      stringstream tagVal;
      
      while(j < input.length()){
        while(input[j] != '.' && input[j]!='~' && j < input.length()){
          tagStream << input[j];
          j++;
        }
        hierarchy.push_back(tagStream.str());
        tagStream.str("");
        tagStream.clear();
        j++;
      }
    }
    vector<string> getHierarchy(){
      return hierarchy;
    }
};

// extract tag NAMES, ATTRIBUTES and VALUES
Tag* extractLine(string input){

  // Declare string streams
  stringstream tagStream;
  stringstream tagAtt;
  stringstream tagVal;
  //Declare string vectors
  Tag* output = new Tag;
  int j = 0;
  int tg = 0;

  // Extract all names, attributes and values in each line
  if(input[j] == '<'){
    j++;  
    if(input[j] != '/'){
      // Output: name
      while(input[j] != ' ' && input[j]!='>'){
        tagStream << input[j];
        j++;
      }
      if(tagStream.str() != " ") {
        output->setName(tagStream.str());
      }
      // Output: Values and Attributes,  Loop for many "values = attributes"
      while(input[j] != '>'){
        while(input[j] != '='){ // Acquire attribute
          if(input[j] != ' ' && input[j] != '='){
            tagAtt << input[j];
          }
          j++;
        }
        while(input[j] != '"'){
          j++;
        }
        do{ // Acquire value
          if(input[j] != ' ' && input[j] != '=' && input[j] != '"'){
            tagVal << input[j];
          }
          j++;
        } while(input[j] != '"');
        j++;
            
        output->setAttVal(tagAtt.str(),tagVal.str());
        tagVal.str("");
        tagVal.clear();
        tagAtt.str("");
        tagAtt.clear();
      }
      
    } else {
      while(input[j] != '>'){
        if(input[j] != '<' && input[j] != '/' && input[j] != '>') {
          tagStream << input[j];
        }
        j++;
      }
      output->setClosingTag(tagStream.str());
    }
  }
  return output;
}

// Writes tag hierarchy into str which points vector<string> n1D in main()
void checkStructure(Tag* ptr, vector<string>* str){
  if(ptr->getParent() != 0 && ptr->getParent()->getName() != ptr->getName()){
    str->insert(str->begin(),ptr->getName());
    checkStructure(ptr->getParent(),str);
  } else {
    str->insert(str->begin(),ptr->getName());
  }
}

int main(){
  int nInputs, nQueries;
  cin >> nInputs >> nQueries;
  cin.ignore();
  
  vector<Tag*> vec;
  vector<Tag*> openTags;
  Tag* v;
  string input;
  int ctr = 0;
  bool firstIter = true;
  Tag* currentlyOpen;
  string nametag;
  // nInputs
  for (int i = 0; i < nInputs; i++){
    // after space read tagname, save as tagname
    // look for " read until ", save as tagvalue
    getline(cin,input);
    vec.push_back(extractLine(input));  
    
    if ( vec[i]->getName() != "" ) {
      if( ctr > 0 ){
        vec[i]->setParent(currentlyOpen); 
      } else {
        vec[i]->setParent(vec[i]);  
      }
      openTags.push_back(vec[i]);
      ctr++;
      currentlyOpen = vec[i];
    }
    if ( vec[i]->getClosingTag() != "" ){
      ctr--;
      if( vec[i]->getClosingTag() == currentlyOpen->getName() ) currentlyOpen = currentlyOpen->getParent();
    }
  }

  // READ BACK TAG STRUCTURE
    vector<string> hrchy;
    for( int i = 0; i < vec.size(); i++ ){
      if(vec[i]->getName() != "") {
        string tmp_hrchy;
        vector<string> n1D;
        vector<string>* nPtr = &n1D;
        checkStructure(vec[i],nPtr);
        for ( auto hc : n1D ){
          tmp_hrchy += hc;
        }
        hrchy.push_back(tmp_hrchy);
      }
    }
  // MAP HIERARCHY TO TAG
  map<string,Tag*> htMap;
  int cc = 0;
    for (int i = 0; i < openTags.size(); i++){
      htMap[hrchy[i]] = openTags[i];
    }
  // PARSE QUERIES 
  string qqs;
  vector<vector<string>> queries;
  vector<string> hrchy2;
  // Read queriesi
  for (int i = 0; i < nQueries; i++){
    string tmp_hrchy2;
    Query inp;
    getline(cin,qqs);
    inp.import(qqs);
    vector<string> a =  inp.getHierarchy();
    queries.push_back(a);
    for ( int j = 0; j < a.size()-1; j++ ){
      tmp_hrchy2 += a[j];
    }
    hrchy2.push_back(tmp_hrchy2);
  }
  
  // INSERT QUERY IN MAP
  int ccc = 0;
  for ( auto &qv : hrchy2 ){
    try{
      if(htMap[qv] == 0) throw invalid_argument("Map to 0");
      map<string,string> adf =  htMap[qv]->getAttVal();
      string aft = adf[queries[ccc][queries[ccc].size()-1]];
      if ( aft == "" ) cout << "Not Found!" << endl;
      else cout << aft << endl; 
    } catch(exception & e) {
      cout << "Not Found!" << endl;
    }
    ccc++;
  }
}
