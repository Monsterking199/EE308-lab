# EE308-lab

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const string table1[32] = {"auto", "break",	"case",	"char",	"const", "continue","default",	"do",
                            "double",	"else",	"enum",	"extern", "float", "for", "goto" , "if",
                            "int",	"long",	"register",	"return", "short", "signed", "sizeof", "static",
                            "struct",	"switch",	"typedef",	"union", "unsigned", "void", "volatile", "while"};

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const string table1[32] = {"auto", "break",	"case",	"char",	"const", "continue","default",	"do",
                            "double",	"else",	"enum",	"extern", "float", "for", "goto" , "if",
                            "int",	"long",	"register",	"return", "short", "signed", "sizeof", "static",
                            "struct",	"switch",	"typedef",	"union", "unsigned", "void", "volatile", "while"};

static int table2[32] = {0};

struct CaseNum{           
	bool switch_ready=false; 
	bool Da_kuo_hao_ready=false; 
};

CaseNum c[100];        
static int structNum =0; 
int caseArr[100] = {0}; 
static int casePos=0;

struct The_if{           
    bool hasIf = false;
	bool elseIf = false;
	bool hasElse= false;
};

The_if ifArr[100];
int ifArrPos = -1;
static int IE=0, IEE=0; 



int main(){
cout << "Please enter your address: " ;

char address[100];
cin >> address;
fstream cpp_file(address); 

int table3[32] = {0};
for(int i=0;i<32;i++){
	table3[i]=table1[i].length(); 
}

string line;

while(!cpp_file.eof()){
			getline(cpp_file, line); 
	

	for(int i=0;i<line.length();i++){
		if( ! (line[i]>='a'&&line[i]<='z' || line[i]>='A'&&line[i]<='Z' || line[i]>='0'&&line[i]<='9' || line[i]=='{' || line[i]=='}' || line[i]=='_' || line[i]=='/' || line[i]=='"') ){    //把没用的符号变成空格 
		    line[i]=' ';	
		}
	} 