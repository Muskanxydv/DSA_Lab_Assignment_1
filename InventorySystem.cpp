#include <bits/stdc++.h>
using namespace std;

struct Item {
    int id;
    string name;
    int qty;
    float price;
};

class Inventory {
public:
    Item arr[100];
    int n;
    vector<vector<int>> sparse;

    Inventory(){ n=0; }

    void insertItem(int id,string name,int qty,float price){
        arr[n++]={id,name,qty,price};
    }

    void deleteItem(int id){
        for(int i=0;i<n;i++){
            if(arr[i].id==id){
                for(int j=i;j<n-1;j++)arr[j]=arr[j+1];
                n--;
                break;
            }
        }
    }

    Item* searchItem(int id){
        for(int i=0;i<n;i++)if(arr[i].id==id)return &arr[i];
        return NULL;
    }

    Item* searchItem(string name){
        for(int i=0;i<n;i++)if(arr[i].name==name)return &arr[i];
        return NULL;
    }

    void rowMajor(int q[][2],int r,int c){
        for(int i=0;i+r;){}
    }

    void priceQuantityTable(vector<vector<float>>& t){
        for(int i=0;i<t.size();i++)
            for(int j=0;j<t[i].size();j++)
                t[i][j]=arr[i].price+arr[i].qty;
    }

    void buildSparse(){
        sparse.clear();
        for(int i=0;i<n;i++){
            if(arr[i].qty<=2)sparse.push_back({arr[i].id,arr[i].qty});
        }
    }
};

int main(){
    cout<<"2401840002 Muskan\n";

    Inventory inv;
    inv.insertItem(1,"Milk",10,30.5);
    inv.insertItem(2,"Rice",1,55.0);
    inv.insertItem(3,"Sugar",15,45.0);
    inv.insertItem(4,"Oil",2,120.0);

    Item* f=inv.searchItem(1);
    if(f)cout<<f->name<<"\n";

    inv.deleteItem(3);

    inv.buildSparse();
    for(auto &x:inv.sparse)cout<<x[0]<<" "<<x[1]<<"\n";

    vector<vector<float>> table(3,vector<float>(2));
    inv.priceQuantityTable(table);
    for(auto &r:table){
        for(auto &v:r)cout<<v<<" ";
        cout<<"\n";
    }
}
