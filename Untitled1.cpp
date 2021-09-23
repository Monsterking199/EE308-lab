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
};

CaseNum c[100];         //最多可检测100个switch的情况 
static int structNum =0; 
int caseArr[100] = {0}; //case的前期准备 
static int casePos=0;

struct The_if{           // 一个 if需要的信息 
    bool hasIf = false;
	bool elseIf = false;
	bool hasElse= false;
};

The_if ifArr[100];
int ifArrPos = -1;
static int IE=0, IEE=0; //两种情况的数量 

int main(){
	
	cout << "Please enter your address: " ;
	
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
    		if( ! (line[i]>='a'&&line[i]<='z' || line[i]>='A'&&line[i]<='Z' || line[i]>='0'&&line[i]<='9' || line[i]=='{' || line[i]=='}' || line[i]=='_' || line[i]=='/' || line[i]=='"') ){    //把没用的符号变成空格 
			    line[i]=' ';	
			}
		} 
		
		string s;
		istringstream is(line);       //提取字符串中字符 
		
		while(is>>s){
			
			if(s[0]=='"' || s[0]=='/')   continue;
			
			for(int i=0;i<32;i++){
				if( s.length()==table3[i] ){
					if( s.compare(table1[i])==0 ){	table2[i]++; }   //检测关键字 
				}
				
				//现在是搞Switch的部分 
				if( s.compare(table1[i])==0 && i==25){
					c[structNum].switch_ready=true;
				}
				if( s.compare("{")==0 && c[structNum].switch_ready==true){
					c[structNum].Da_kuo_hao_ready=true;
				}
				
				if(c[structNum].switch_ready && c[structNum].Da_kuo_hao_ready ){
					if( s.compare(table1[i])==0 && i==2){
						caseArr[casePos]++;
					}
				}
				
				if(c[structNum].switch_ready && c[structNum].Da_kuo_hao_ready && s.compare("}")==0){
					structNum++;
					casePos++;	
				}	
			} 
		}		
		
		//现在是搞if-else的部分  检测优先级：elseif if else
		if( line.find("else if")>=0 && line.find("else if")<line.length()){
			ifArr[ifArrPos].elseIf = true;
		} else if( line.find("if")>=0 && line.find("if")<line.length()){
		
		    ifArrPos++;
			while(ifArr[ifArrPos].hasElse && ifArrPos<100){     //找到没有新创建的if
				ifArrPos++;
			} 
			ifArr[ifArrPos].hasIf = true;
					
		} else if ( line.find("else")>=0 && line.find("else")<line.length()) {
			ifArr[ifArrPos].hasElse = true;
			ifArrPos--;
			while(ifArr[ifArrPos].hasElse==true && ifArrPos>=0){ //找到没有新创建的if
				ifArrPos--;
			}
		}
	}
	
	int total;
	for(int j=0;j<32;j++){
		total+=table2[j];   // 计算所有关键字（已实现检测出35） 
	} 
	cout << "total num: " << total << endl;
	
	cout << "switch num: " << table2[25] << endl;
	cout << "case num: ";             //列出所有Case数  (已实现) 
	for(int i=0;i<100;i++){
		if(caseArr[i]!=0){
			cout <<caseArr[i] << " ";  
		}
	}
	cout << endl; 

	//现在搞if
	for(int i=0;i<100;i++){
		if(ifArr[i].hasIf){
			if(ifArr[i].elseIf) IEE++;
			else{   IE++;
		    }
		}
	} 
	
	cout << "if-else num: " << IE <<endl;
	cout << "if-elseif-else num: " << IEE << endl;
	
	return 0;
}
