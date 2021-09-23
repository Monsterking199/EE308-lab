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

struct CaseNum{           // һ��switch��Ҫ����Ϣ 
	bool switch_ready=false; 
	bool Da_kuo_hao_ready=false; 
	int caseNumber=0;
};

CaseNum c[100];         //���ɼ��100��switch����� 
static int structNum =0; 
int caseArr[100] = {0}; //switch��׼�� 
static int casePos=0;

int main(){
	char address[100];
    cin >> address;
	fstream cpp_file(address);  //�����ļ� 
	
	
	
	int table3[32] = {0};
	for(int i=0;i<32;i++){
		table3[i]=table1[i].length();    //�ؼ��ֳ��ȵĲο��� 
	}
	
	string line;
	while(!cpp_file.eof()){
		
    	getline(cpp_file, line); 
    	
    	for(int i=0;i<line.length();i++){
    		if( ! (line[i]>='a'&&line[i]<='z' || line[i]>='A'&&line[i]<='Z' || line[i]>='0'&&line[i]<='9' || line[i]=='{' || line[i]=='}' || line[i]=='_' ) ){    //��û�õķ��ű�ɿո� 
			    line[i]=' ';	
			}
		} 
		
		string s;
		istringstream is(line);       //��ȡ�ַ������ַ� 
		
		
		while(is>>s){
			for(int i=0;i<32;i++){
				if( s.length()==table3[i] ){
					if( s.compare(table1[i])==0 ){	table2[i]++; }   //���ؼ��� 
				}
				
				if( s.compare("switch")==0 ){
					
					
				}
				
			} 
		}
		
	}
	
	int total;
	for(int i=0;i<32;i++){
		total+=table2[i];   // �������йؼ��֣���ʵ�ּ���35�� 
	} 
	cout << "total: " << total;
	
	return 0;
}
