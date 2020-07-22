
class Node{
public:
    char data;
    int count;
    unordered_map<char, Node*> children;
    bool terminal;
    Node(char d){
        data=d;
        terminal =false;
        count=1;
    }
};

class Trie{

    Node* root;
    //int cnt;
    
public:
    Trie(){
        root=new Node('\0');
        //cnt=0;
    }
    void insert(string s){
        Node* temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->children.count(s[i])){
                temp=temp->children[s[i]];
                temp->count+=1;
            }else{
                Node* n= new Node(s[i]);
                temp->children[s[i]]=n;
                temp=n;
            }
        }
        temp->terminal=true;
    }
    
    bool find(string s){
        Node * temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->children.count(s[i])==0){
                return false;
            }
            else{
                temp=temp->children[s[i]];
            }
        }
        return temp->terminal;
    }
    void pref(string s){
        string t;
        Node* temp=root;
        for(int i=0;i<s.size();i++){
            temp=temp->children[s[i]];
                t.push_back(s[i]);
            if(temp->count==1){
                break;
            }
        }
        cout<<t<<endl;
    }
    
};
