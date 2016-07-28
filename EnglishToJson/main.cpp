#include<iostream>
#include<string>
#include<fstream>
#include<cctype> 
#include<algorithm>
using namespace std;

#define SIZE 100
#define VOC_SIZE 200

char Line[SIZE];
string FileName;

class Voc{
public:
	int id;
	string Chinese;
	string English;
	string Speech;
	string Sentence;
	string Ch_Sentence;

	void Print() {
		if (id != 0) {
			cout << ",\n\t{\n";
			cout << "\t\t\"id\":" << id << ",\n";
			cout << "\t\t\"Chinese\":\"" << Chinese << "\",\n";
			cout << "\t\t\"English\":\"" << English << "\",\n";
			cout << "\t\t\"Speech\":\"" << Speech << "\",\n";
			cout << "\t\t\"Sentence\":\"" << Sentence << "\",\n";
			cout << "\t\t\"Ch_Sentnece\":\"" << Ch_Sentence << "\n";
			cout << "\t}";
		}
		else {
			cout << "\t{\n";
			cout << "\t\t\"id\":" << id << ",\n";
			cout << "\t\t\"Chinese\":" << Chinese << "\",\n";
			cout << "\t\t\"English\":" << English << "\",\n";
			cout << "\t\t\"Speech\":" << Speech << "\",\n";
			cout << "\t\t\"Sentence\":" << Sentence << "\",\n";
			cout << "\t\t\"Ch_Sentnece\":" << Ch_Sentence << "\n";
			cout << "\t}";
		}
	}
	void SetID(int _id) {
		id = _id;
	}
	void SetSpeech(string _Speech) {
		Speech = _Speech;
	}
	void SetChinese(string _Chinese) {
		Chinese = _Chinese;
	}
	void SetEnglish(string _English) {
		transform(_English.begin(), _English.end(), _English.begin(), tolower);
		English = _English;
	}
	void SetSentence(string _Sentence) {
		Sentence = _Sentence;
	}
	void SetCh_Sentence(string _Ch_Sentence) {
		Ch_Sentence = _Ch_Sentence;
	}
	
};

string IfSpeech(string str) {
	
	if (str == "名") {
		str = "N.";
	}
	if (str == "形") {
		str = "adj.";
	}
	if (str == "動") {
		str = "v.";
	}
	if (str == "副") {
		str = "adv.";
	}
	if (str == "介") {
		str = "prep.";
	}
	if (str == "連") {
		str = "conj.";
	}

	return str;
}

int main() {
	
	int id = 0;
	Voc Vocs[VOC_SIZE];

	cout << "檔案名稱：";
	cin >> FileName;

	fstream fin;
	fin.open(FileName + ".txt", ios::in);
	while(!fin.eof()){
		Vocs[id].SetID(id);
		fin.getline(Line, sizeof(Line), '<');
		Vocs[id].SetEnglish(Line);
		fin.getline(Line, sizeof(Line), '>');
		Vocs[id].SetSpeech(Line);
		fin.getline(Line, sizeof(Line), '\n');
		Vocs[id].SetChinese(Line);
		fin.getline(Line, sizeof(Line), '\n');
		Vocs[id].SetSentence(Line);
		fin.getline(Line, sizeof(Line), '\n');
		Vocs[id].SetCh_Sentence(Line);
		fin.getline(Line, sizeof(Line), '\n');
		id++;
	}

	fstream fp;
	fp.open(FileName + ".json", ios::out);
	if (!fp) {
		cout << "Fail to open file: " << FileName << endl;
	}


	fp << "[\n";
	for (int i = 0; i < id-1; i++) {
		if (i != 0) {
			fp << ",\n\t{\n";
			fp << "\t\t\"id\":" << i << ",\n";
			fp << "\t\t\"Chinese\":\"" << Vocs[i].Chinese << "\",\n";
			fp << "\t\t\"English\":\"" << Vocs[i].English << "\",\n";
			fp << "\t\t\"Speech\":\"" << Vocs[i].Speech << "\",\n";
			fp << "\t\t\"Sentence\":\"" << Vocs[i].Sentence << "\",\n";
			fp << "\t\t\"Ch_Sentnece\":\"" << Vocs[i].Ch_Sentence << "\"\n";
			fp << "\t}";
		}
		else {
			fp << "\t{\n";
			fp << "\t\t\"id\":" << i << ",\n";
			fp << "\t\t\"Chinese\":" << Vocs[i].Chinese << "\",\n";
			fp << "\t\t\"English\":" << Vocs[i].English << "\",\n";
			fp << "\t\t\"Speech\":" << Vocs[i].Speech << "\",\n";
			fp << "\t\t\"Sentence\":" << Vocs[i].Sentence << "\",\n";
			fp << "\t\t\"Ch_Sentnece\":" << Vocs[i].Ch_Sentence << "\"\n";
			fp << "\t}";
		}
	}
	fp << "\n]";

	

	fp.close();//關閉檔案

	system("pause");


	return 0;
}