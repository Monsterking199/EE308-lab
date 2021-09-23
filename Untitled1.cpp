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
};

CaseNum c[100];         //���ɼ��100��switch����� 
static int structNum =0; 
int caseArr[100] = {0}; //case��ǰ��׼�� 
static int casePos=0;

struct The_if{           // һ�� if��Ҫ����Ϣ 
    bool hasIf = false;
	bool elseIf = false;
	bool hasElse= false;
};

The_if ifArr[100];
int ifArrPos = -1;
static int IE=0, IEE=0; //������������� 

int main(){
	
	cout << "Please enter your address: " ;
	
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
    		if( ! (line[i]>='a'&&line[i]<='z' || line[i]>='A'&&line[i]<='Z' || line[i]>='0'&&line[i]<='9' || line[i]=='{' || line[i]=='}' || line[i]=='_' || line[i]=='/' || line[i]=='"') ){    //��û�õķ��ű�ɿո� 
			    line[i]=' ';	
			}
		} 
		
		string s;
		istringstream is(line);       //��ȡ�ַ������ַ� 
		
		while(is>>s){
			
			if(s[0]=='"' || s[0]=='/')   continue;
			
			for(int i=0;i<32;i++){
				if( s.length()==table3[i] ){
					if( s.compare(table1[i])==0 ){	table2[i]++; }   //���ؼ��� 
				}
				
				//�����Ǹ�Switch�Ĳ��� 
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
		
		//�����Ǹ�if-else�Ĳ���  ������ȼ���elseif if else
		if( line.find("else if")>=0 && line.find("else if")<line.length()){
			ifArr[ifArrPos].elseIf = true;
		} else if( line.find("if")>=0 && line.find("if")<line.length()){
		
		    ifArrPos++;
			while(ifArr[ifArrPos].hasElse && ifArrPos<100){     //�ҵ�û���´�����if
				ifArrPos++;
			} 
			ifArr[ifArrPos].hasIf = true;
					
		} else if ( line.find("else")>=0 && line.find("else")<line.length()) {
			ifArr[ifArrPos].hasElse = true;
			ifArrPos--;
			while(ifArr[ifArrPos].hasElse==true && ifArrPos>=0){ //�ҵ�û���´�����if
				ifArrPos--;
			}
		}
	}
	
	int total;
	for(int j=0;j<32;j++){
		total+=table2[j];   // �������йؼ��֣���ʵ�ּ���35�� 
	} 
	cout << "total num: " << total << endl;
	
	cout << "switch num: " << table2[25] << endl;
	cout << "case num: ";             //�г�����Case��  (��ʵ��) 
	for(int i=0;i<100;i++){
		if(caseArr[i]!=0){
			cout <<caseArr[i] << " ";  
		}
	}
	cout << endl; 

	//���ڸ�if
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
