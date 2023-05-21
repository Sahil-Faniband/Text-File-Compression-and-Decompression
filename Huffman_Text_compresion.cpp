#include<bits/stdc++.h>
#include<unordered_map>
#include<fstream>
using namespace std;


class HuffmanTree{
   public:
        char letter;
        int val;
        
        HuffmanTree *left;
        HuffmanTree *right;

        HuffmanTree(char c,int val){
            this->letter = c;
            this->val = val;
            
            this->left= NULL;
            this->right= NULL;
        }
};
vector<pair<char,int> > Freq(string s){
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    vector<pair<char,int> > v;
    for(int i=0;i<s.size();i++){
        if(mp[s[i]]!=0){
            v.push_back(make_pair(s[i],mp[s[i]]));
             mp[s[i]]=0;
        }
    }
    
    return v;

}
class Compare{
    public:
    bool operator()(HuffmanTree* a,HuffmanTree* b){
        if(a->val > b->val){
            return true;
        }
        else{
            return false;
        }
    }
};
void print(priority_queue<HuffmanTree*, vector<HuffmanTree*>, Compare> &q){
    while(q.size()){
        cout<<q.top()->letter<<" "<<q.top()->val<<endl;
        q.pop();
    }
}
HuffmanTree *makeTree(vector<pair<char,int> > &freq){
    priority_queue<HuffmanTree*, vector<HuffmanTree*>, Compare>q;
    for(int i=0; i<freq.size();i++){
        q.push(new HuffmanTree(freq[i].first,freq[i].second));
    }
    //print(q);
    while(q.size()>1){
        HuffmanTree *left=q.top();
        q.pop();
        HuffmanTree *right=q.top();
        q.pop();
        HuffmanTree *nd=new HuffmanTree('~',left->val+right->val);
        nd->left=left;
        nd->right=right;
        q.push(nd);
    }
    return q.top();
}
void getHuffmanCode(HuffmanTree * root,string code,unordered_map<char,string> & codeTable){
    if(!root) {
        return;
    }
        
    if(root->letter!='~'){
        codeTable[root->letter] = code;
        
    }
    else{    
        getHuffmanCode(root->left,code+"0",codeTable);
        getHuffmanCode(root->right,code+"1",codeTable);
    }
}
string decompress(const string& compressedText, HuffmanTree* root) {
    string decompressedText = "";
   HuffmanTree* currentNode = root;

    for (char c : compressedText) {
        if (c == '0') {
            currentNode = currentNode->left;
        } else if (c == '1') {
            currentNode = currentNode->right;
        }

        if (!currentNode->left && !currentNode->right) {
            decompressedText += currentNode->letter;
            currentNode = root;
        }
    }

    return decompressedText;
}

int main(){
    
    cout<<"---------------******************************************---------------"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"----- Text File Compression and Decompression using Huffman Coding -----"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    char key;
    cout<<"Press any key to start Compression:"<<endl;
    cin>>key;
    cout<<"-------------------------------------------------------------------------"<<endl;
    string s;
    string line;
    cout<<"\nOpening Text_File.txt ..."<<endl;
   std::ifstream ReadFile("Text_File.txt");
    if(ReadFile){
        
        while(getline(ReadFile,line)){
            if(line=="end"){
                break;
            }
            s+=line+"\n";
        }
        ReadFile.close();
        cout<<"File Opened Successfuly..!"<<endl;
    }
    else{
        cout<<"\nFailed to open a file..!"<<endl;
        cout<<"---------------*************************************---------------"<<endl;
        return 0;
    }
    
    cout<<"\nCompressing..."<<endl;
    cout<<"\nProcessing.... Plz wait..!"<<endl;
    vector<pair<char,int> > freq=Freq(s);
    //Prints Frequencys of Characters:-
    // sort(freq.begin(),freq.end());
    //  for(int i=0;i<freq.size();i++){
    //      cout<<freq[i].first<<" "<<freq[i].second<<endl; 
    //  }
    
    HuffmanTree *tree=makeTree(freq);
    unordered_map<char,string> codeTable;
    getHuffmanCode(tree,"",codeTable);
    string compressedText="";
    cout<<"\nCharacter Table with Huffman codes \n";
	cout<<"\n\tCharacter\t\tHuffman Code\n";
    //Prints code assigned to each character
    for(auto i:  codeTable){
         cout<<"\t\t"<<i.first<<"\t:\t "<<i.second<<endl;   
    }
    
    for (char c : s) {
        compressedText += codeTable[c];
    }
    ofstream compressedFile("Compressed_File.bin",ios::binary);
    compressedFile.write((char *)&compressedText,sizeof(compressedText));
    compressedFile.close();
    cout<<"\nCompression Successful..!"<<endl;
    //cout<<"Compressed Text :"<<compressedText<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    char temp;
    cout<<"Press any key to Decompress the Text File:"<<endl;
    cin>>temp;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Processing.... Plz wait..!"<<endl;
    string decompressedText="";
    decompressedText=decompress(compressedText,tree);
    ofstream decompressedFile("Decompressed_File.txt");
    decompressedFile<<decompressedText;
    decompressedFile.close();
    
    cout<<"Decompression Successful..!"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"---------------*******************************************---------------"<<endl;

    return 0;
}


