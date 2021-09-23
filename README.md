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