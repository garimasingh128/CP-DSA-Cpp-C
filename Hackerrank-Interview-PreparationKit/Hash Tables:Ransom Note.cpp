// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string,int>themap;
    int m;
    int n;
    m=magazine.size();
    n=note.size();

    for(int i=0;i<m;i++){
        themap[magazine[i]]=themap[magazine[i]]+1;
    }
    for(int i=0;i<n;i++){
        if(themap[note[i]]>0){
            themap[note[i]]=themap[note[i]]-1;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
    return;


}
