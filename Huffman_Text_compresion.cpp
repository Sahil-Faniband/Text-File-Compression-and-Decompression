/**
 * This program compresses and decompresses a text file using Huffman coding.
 * 
 * @param s The input string that needs to be compressed and decompressed using Huffman coding.
 * 
 * @return The program returns 0, which indicates successful execution of the program.
 */
#include<bits/stdc++.h>
#include<unordered_map>
#include<fstream>
using namespace std;


/* The class represents a node in a Huffman tree with a character, a value, and pointers to its left
and right children. */
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
/**
 * The function takes a string as input and returns a vector of pairs, where each pair contains a
 * character and its frequency in the input string.
 * 
 * @param s The input string for which we want to find the frequency of each character.
 * 
 * @return The function `Freq` returns a vector of pairs, where each pair contains a character and its
 * frequency in the input string `s`.
 */
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
/* The above class defines a comparison operator for HuffmanTree objects based on their values. */
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
/**
 * The function prints the values and letters of a priority queue of HuffmanTree objects in descending
 * order based on their values.
 * 
 * @param q q is a priority queue of pointers to HuffmanTree objects. The priority queue is sorted
 * based on the Compare function, which compares the values of the HuffmanTree objects. The function is
 * passed by reference, so any changes made to the priority queue inside the function will affect the
 * original priority queue passed to the
 */
void print(priority_queue<HuffmanTree*, vector<HuffmanTree*>, Compare> &q){
    while(q.size()){
        cout<<q.top()->letter<<" "<<q.top()->val<<endl;
        q.pop();
    }
}
/**
 * The function takes a vector of character frequencies and constructs a Huffman tree using a priority
 * queue.
 * 
 * @param freq freq is a vector of pairs, where each pair contains a character and its frequency of
 * occurrence in a given text or message. This function takes this frequency vector as input and
 * constructs a Huffman tree based on the frequencies of the characters.
 * 
 * @return The function `makeTree` returns a pointer to the root node of a Huffman tree.
 */
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
/**
 * This function recursively generates Huffman codes for each character in a Huffman tree and stores
 * them in an unordered map.
 * 
 * @param root A pointer to the root of a Huffman tree.
 * @param code The parameter "code" is a string that represents the Huffman code for a particular
 * character in the Huffman tree. It is initially an empty string and is recursively built up as the
 * function traverses the tree.
 * @param codeTable `codeTable` is an unordered map that stores the Huffman codes for each character in
 * the input string. The keys of the map are the characters and the values are the corresponding
 * Huffman codes. The function `getHuffmanCode` recursively generates the Huffman codes for each
 * character by traversing the Huffman tree
 * 
 * @return Nothing is being returned explicitly in this function. However, the function is recursively
 * calling itself to traverse the Huffman tree and populate the `codeTable` unordered map with the
 * Huffman codes for each character in the tree.
 */
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
/**
 * This function takes in a compressed text and a Huffman tree, and returns the decompressed text using
 * the tree to traverse the binary code.
 * 
 * @param compressedText The compressed text is a string of binary digits that represents the
 * compressed version of some original text using Huffman coding.
 * @param root The root parameter is a pointer to the root node of a Huffman tree.
 * 
 * @return a string that represents the decompressed version of the input compressedText using the
 * HuffmanTree provided as root.
 */
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

/**
 * This function compresses and decompresses a text file using Huffman coding.
 * 
 * @return The main function is returning an integer value of 0.
 */
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
    compressedFile.write(compressedText.c_str(), compressedText.size());
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


