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

struct CaseNum{           // 一个switch需要的信息 
	bool switch_ready=false; 
	bool Da_kuo_hao_ready=false; 
	int caseNumber=0;
};

CaseNum c[100];         //最多可检测100个switch的情况 
static int structNum =0; 
int caseArr[100] = {0}; //switch的准备 
static int casePos=0;

int main(){
	char address[100];
    cin >> address;
	fstream cpp_file(address);  //导入文件 
	
	
	
	int table3[32] = {0};
	for(int i=0;i<32;i++){
		table3[i]=table1[i].length();    //关键字长度的参考表 
	}
	
	string line;
	while(!cpp_file.eof()){
		
    	getline(cpp_file, line); 
    	
    	for(int i=0;i<line.length();i++){
    		if( ! (line[i]>='a'&&line[i]<='z' || line[i]>='A'&&line[i]<='Z' || line[i]>='0'&&line[i]<='9' || line[i]=='{' || line[i]=='}' || line[i]=='_' ) ){    //把没用的符号变成空格 
			    line[i]=' ';	
			}
		} 
		
		string s;
		istringstream is(line);       //提取字符串中字符 
		
		
		while(is>>s){
			for(int i=0;i<32;i++){
				if( s.length()==table3[i] ){
					if( s.compare(table1[i])==0 ){	table2[i]++; }   //检测关键字 
				}
				
				if( s.compare("switch")==0 ){
					
					
				}
				
			} 
		}
		
	}
	
	int total;
	for(int i=0;i<32;i++){
		total+=table2[i];   // 计算所有关键字（已实现检测出35） 
	} 
	cout << "total: " << total;
	
	return 0;
}
